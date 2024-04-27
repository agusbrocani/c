#include "model.h"

int main()
{
    int vec[] = {1,2,3,4,5,6,7,8,9,10};
    int x = 9;
    printf("%p - ", &vec[8]);
    printf("%p", _bbinaria(&x, vec, sizeof(vec)/sizeof(int), sizeof(int), compareInt));
//    FILE* file;
//    char longestWord[MAX_LINE];
//    char* line = longestWord;
//    int occurrences;
//
//    if(openFile(&file, "test.txt", "rt"))
//        return FILE_ERR;
//
//    occurrences = _contarPalabras(file, line);
//    printf("Longest word: %s - Occurrences: %d", line, occurrences);
//    fclose(file);
//
//
//    int mat[][MAX_COLUMNS] =
//    {
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//        {1,   2,  3,  4,  5,  6,  7, 8, 9, 1, 2, 3, 4, 5, 6},
//    };
//    int mat[][MAX_COLUMNS] =
//    {
//        {1,   2,  3,  4, 5},
//        {6,   7,  8,  9, 10},
//        {11, 12, 13, 14, 15},
//        {16, 17, 18, 19, 20},
//        {21, 22, 23, 24, 25}
//    };
//    int mat[][MAX_COLUMNS] =
//    {
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {1,   2,  3,  4,  5,  6},
//        {6,   7,  8,  9, 10, 11},
//        {11, 12, 13, 14, 15, 16},
//        {16, 17, 18, 19, 20, 21},
//        {21, 22, 23, 24, 25, 26},
//        {27, 28, 29, 30, 31, 32}
//    };
//    int numberOfRows = sizeof(mat)/(MAX_COLUMNS * sizeof(int));
//    int numberOfColumns = sizeof(mat)/(MAX_ROWS * sizeof(int));
//    recorrerTrianSupEInf(mat, numberOfRows, numberOfColumns);
//    printf("\nExpected: 109 - Obtained: %d\n", sumTrianDerEntreDiag(mat, numberOfRows, numberOfColumns));
//    printf("Expected: 165 - Obtained: %d\n", sumTrianInfEntreDiag(mat, numberOfRows, numberOfColumns));
//    printf("Expected: 83 - Obtained: %d\n", sumTrianIzqEntreDiag(mat, numberOfRows, numberOfColumns));
//    printf("Expected: 31 - Obtained: %d", sumTrianSupEntreDiag(mat, numberOfRows, numberOfColumns));


    return 0;
}
