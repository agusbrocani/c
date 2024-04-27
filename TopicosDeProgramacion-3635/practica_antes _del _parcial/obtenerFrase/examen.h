#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLUMN 1025
#define MAX_ROWS 5

char* obtenerFrase(char* frase);

int comparePhrases( const void* a, const void* b );
void insertOrdered( void* data , const void* toInsert, size_t dataSize, int* numberOfElements, int maxLength, int (*compare)( const void* a, const void* b ) );

#endif // EXAMEN_H_INCLUDED
