#include "model.h"

void* _bbinaria(const void* key, const void *arr, size_t numberOfElements, size_t sizeOfElement,
               int (*cmp)(const void* , const void*))
{
    int i = 0;

    while(i < numberOfElements){
        if(!cmp(key, arr))
            return (void*)arr;
        arr += sizeOfElement;
        i++;
    }

    return NULL;
}

int compareInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int _contarPalabras(FILE* fileToRead, char* longestWord)
{
    int occurrences = 0;
    int longestWordLength = 0;
    int wordLength;
    char buffer[MAX_LINE];
    char* line;
    char* word;

    while(fgets(buffer, sizeof(buffer), fileToRead)){
        line = buffer;
        while((wordLength = nextWord(&line, &word))){
            if(wordLength > longestWordLength){
                occurrences = 0;
                miStrncpy(longestWord, word, wordLength);
                *(longestWord + longestWordLength + 1) = '\0';
                longestWordLength = wordLength;
            }
            occurrences += isOccurence(longestWord, longestWordLength, word, wordLength);
        }
    }

    return occurrences;
}


int nextWord(char** line, char** word)
{
    int wordLength = 0;

    while(**line && !IS_LETTER(**line))
        (*line)++;

    *word = *line;

    while(IS_LETTER(**line)){
        wordLength++;
        (*line)++;
    }

    return wordLength;
}
void miStrncpy(char* longestWord, char* word, size_t wordLength)
{
    while(wordLength > 0){
        *longestWord = *word;
        longestWord++;
        word++;
        wordLength--;
    }
}
int isOccurence(char* longestWord, size_t longestWordLength, char* word, size_t wordLength)
{
    if(longestWordLength != wordLength)
        return 0;
    while(longestWordLength > 0){
        if(*longestWord != *word)
            return 0;
        longestWord++;
        word++;
        longestWordLength --;
    }
    return 1;
}

int openFile(FILE** file, const char* fileName, const char* fileMode)
{
    *file = fopen(fileName, fileMode);
    if(!*file){
        perror("Oops! Something wrong occurred");
        return FILE_ERR;
    }

    return OK;
}

int sumTrianInfEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns){
    int sum = 0;
    int row;
    int col;

    for(row = totalRows - 1; row > totalRows / 2; row --)
        for(col = totalColumns - row; col < row; col ++)
            sum += matrix[row][col];

    return sum;
}

int sumTrianDerEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns){
    int sum = 0;
    int row;
    int col;

    for(col = totalColumns - 1; col > totalColumns / 2; col --)
        for(row = totalRows - col; row < col; row ++)
            sum += matrix[row][col];

    return sum;
}
int sumTrianIzqEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns){
    int sum = 0;
    int row;
    int col;

    for(col = 0; col < (totalColumns / 2); col ++)
        for(row = col + 1; row < totalRows - col - 1; row ++)
            sum += matrix[row][col];

    return sum;
}
int sumTrianSupEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns){
    int sum = 0;
    int row;
    int col;

    for(row = 0; row < (totalRows / 2); row ++)
        for(col = row + 1; col < totalColumns - row - 1; col ++)
            sum += matrix[row][col];

    return sum;
}

void recorrerTrianSupEInf(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns)
{
    recorrerTrianSup(matrix, totalRows, totalColumns);
    recorrerTrianInf(matrix, totalRows, totalColumns);
}

void recorrerTrianInf(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns)
{
    int row;
    int col;
    int spaces;
    int aux = 0;

    for(row = totalRows / 2; row < totalRows; row ++){
        for(col = totalColumns - row - 1; col <= row; col ++)
            printf("%d ", matrix[row][col]);
        printf("\n");
        for(spaces = 0 ; spaces < 2 * (row - aux - 1) ; spaces ++)
            printf(" ");
        aux += 2;
    }
}
void recorrerTrianSup(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns)
{
    int row;
    int col;
    int spaces;

    for(row = 0; row < totalRows / 2; row ++){
        for(col = row; col < totalColumns - row; col ++)
            printf("%d ", matrix[row][col]);
        printf("\n");
        for(spaces = 0; spaces <= 2 * row + 1; spaces ++)
            printf(" ");
    }
}
