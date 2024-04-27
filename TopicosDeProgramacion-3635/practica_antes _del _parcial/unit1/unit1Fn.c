#include "unit1Header.h"

void showInt( const void* data )
{
    printf("%d\t",*(int*)data);
}

void showData( const void* data, size_t dataSize, int numberOfElements, void (*show)(const void* data))
{
    size_t pos;

    if(         numberOfElements < 1            )
    {
        return;
    }

    for( pos = 0; pos < numberOfElements; pos++ )
    {
        show(data);
        data += dataSize;
    }
    printf("\n");
}

int cmpInt( const void* data1, const void* data2 )
{
    return *(int*) data1 - *(int*) data2;
}

void shiftDataToRight(void* data, size_t indexSource, size_t dataSize, int numberOfElements)  //numberOfElements es la cantidad de elementos actuales del array, pero el array va a tener 1 pos más para poder hacer el shifteo
{
    void* actualDataTraverse = data + numberOfElements * dataSize - dataSize;
    int i;

    if(         indexSource < 0          )    ///indexSource >= numberOfElements esa condicion se verifica igualmente en el for, pero lo dejo para que sea explicito
    {
        return;
    }

    for( i = indexSource; i < numberOfElements; i++ )
    {
        memcpy( actualDataTraverse + dataSize, actualDataTraverse, dataSize );
        actualDataTraverse -= dataSize;
    }
}
void shiftDataToLeft( void* data, size_t sourceIndex, size_t dataSize, size_t* numberOfElements )
{
    int i;

    if(         *numberOfElements <= 1 || sourceIndex < 0            )
    {
        printf("Do not shift that\n");
        return;
    }

    for( i = sourceIndex; i < *numberOfElements - 1; i++ )
    {
        memcpy( data + sourceIndex * dataSize, data + sourceIndex * dataSize + dataSize, dataSize );
        data += dataSize;
    }
    (*numberOfElements)--;  ///SI MANDE EL INDEX DEL ULTIMO ELEMENTO, DIRECTAMENTE LO ELIMINO DECREMENTANDO LA CANTIDAD DE ELEMENTOS
}

int insertIntoPosition( void* data, const void* dataToInsert, size_t insertPositionIndex, size_t dataSize, int* numberOfElements )
{
    if(         insertPositionIndex < 0 || insertPositionIndex > (*numberOfElements)           )   //Solo permito ingresos hasta numberOfElements, porque si me pide añadirlo en ese indice, que en teoria se pasa, lo permito
    {
        return 0;
    }

    shiftDataToRight( data, insertPositionIndex, dataSize, *numberOfElements );
    (*numberOfElements) ++;
    memcpy( data + insertPositionIndex * dataSize, dataToInsert, dataSize );

    return 1;
}

void sortedInsert( void* data, const void* dataToInsert, size_t dataSize, int* numberOfElements, int (*compare)(const void* data1, const void* data2) )
{
    void* startOfData = data;
    size_t indexToInsert = 0;
    size_t lastElementIndex = (*numberOfElements) - 1;

    while(          indexToInsert <= lastElementIndex && compare( data, dataToInsert) < 0          )
    {
        indexToInsert++;
        data += dataSize;
    }

    shiftDataToRight( startOfData, indexToInsert, dataSize, *numberOfElements );
    (*numberOfElements) ++;
    memcpy( data, dataToInsert, dataSize);
}

int deleteElementInPosition( void* data, void* deleatedData, size_t indexToDelete, size_t dataSize, size_t* numberOfElements )
{
    if(         indexToDelete < 0 || *numberOfElements < 1 || indexToDelete >= *numberOfElements            )
    {
        return 0;
    }

    memcpy( deleatedData, (data+indexToDelete*dataSize), dataSize );
    shiftDataToLeft(data,indexToDelete,dataSize,numberOfElements);

    return 1;
}

void deleteFirstOccurrence( void* data, const void* ocurrenceToDelete, size_t dataSize, size_t* numberOfElements, int (*compare)(const void* data1, const void* data2) )
{
    void* origin = data;
    int index;

    for( index = 0; index < *numberOfElements; index++ )
    {
        if(         !compare( data, ocurrenceToDelete )          )
        {
            shiftDataToLeft( origin, index, dataSize, numberOfElements );
            break;
        }
        data += dataSize;
    }

}

void deleteAllOccurrences( void* data, const void* toDelete, size_t dataSize, size_t* numberOfElements, int (*compare)( const void* data1, const void* data2 ) )
{
    void* read = data;
    void* write = data;
    size_t remainingElementsToBeTraversed = *numberOfElements;
    size_t numberOfElementsToDelete;

    while(          remainingElementsToBeTraversed          )
    {
        numberOfElementsToDelete = 0;
        while(          remainingElementsToBeTraversed && !compare( read, toDelete )           )
        {
            read += dataSize;
            numberOfElementsToDelete++;
            remainingElementsToBeTraversed--;
        }

        while(          remainingElementsToBeTraversed && compare( read, toDelete )            )
        {
            memcpy( write, read, dataSize );
            write += dataSize;
            read += dataSize;
            remainingElementsToBeTraversed--;
        }
        *numberOfElements -= numberOfElementsToDelete;
    }
}
