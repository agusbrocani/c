#ifndef UNIT1HEADER_H_INCLUDED
#define UNIT1HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 20

void showInt( const void* data );
void showData( const void* data, size_t dataSize, int numberOfElements, void (*show)(const void* data) );
int cmpInt( const void* data1, const void* data2 );

/**
shiftData functions must recibe:
*   data                : origin of data when is call
*   indexSource         : index source since where do the shift
*   dataSize
*   numberOfElements
*/

void  shiftDataToRight( void* data, size_t indexSource, size_t dataSize, int numberOfElements );  //DEBE RECIBIR: vector, posicion desde donde debe shiftear, numero de elementos actuales
void shiftDataToLeft( void* data, size_t sourceIndex, size_t dataSize, size_t* numberOfElements );


int insertIntoPosition( void* data, const void* dataToInsert,size_t insertPositionIndex, size_t dataSize, int* numberOfElements );
void sortedInsert( void* data, const void* dataToInsert, size_t dataSize, int* numberOfElements, int (*compare)(const void* data1, const void* data2) );
int deleteElementInPosition( void* data, void* deleatedData, size_t indexToDelete, size_t dataSize, size_t* numberOfElements );
void deleteFirstOccurrence( void* data, const void* ocurrenceToDelete, size_t dataSize, size_t* numberOfElements, int (*compare)(const void* data1, const void* data2) );
void deleteAllOccurrences( void* data, const void* toDelete, size_t dataSize, size_t* numberOfElements, int (*compare)( const void* data1, const void* data2 ) );

#endif // UNIT1HEADER_H_INCLUDED
