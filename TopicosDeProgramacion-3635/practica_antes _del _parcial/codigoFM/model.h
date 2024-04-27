#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define FILE_ERR -1

#define MAX_LINE 1024
#define MAX_ROWS 50
#define MAX_COLUMNS 50

#define IS_LETTER(X) ((X >= 'A' && X <= 'Z')||(X >= 'a' && X <= 'z')? 1 : 0)

void* _bbinaria(const void* key, const void *arr, size_t numberOfElements, size_t sizeOfElement,
               int (*cmp)(const void* , const void* ));
int compareInt(const void* key, const void* arrayElement);
int _contarPalabras(FILE* fileToRead, char* longestWord);
void miStrncpy(char* longestWord, char* word, size_t wordLength);
int isOccurence(char* longestWord, size_t longestWordLength, char* word, size_t wordLength);
int openFile(FILE** file, const char* fileName, const char* fileMode);
int nextWord(char** line, char** word);
int sumTrianInfEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
int sumTrianDerEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
int sumTrianIzqEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
int sumTrianSupEntreDiag(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
void recorrerTrianSupEInf(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
void recorrerTrianInf(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
void recorrerTrianSup(int matrix[][MAX_COLUMNS], int totalRows, int totalColumns);
#endif // MODEL_H_INCLUDED
