#include "examen.h"
/*
int comparePhrases( const void* a, const void* b )
{
    return strlen(a) > strlen(b);
}

void insertOrdered( void* data , const void* toInsert, size_t dataSize, int* numberOfElements, int maxLength, int (*compare)( const void* a, const void* b ) )
{
    void* lastElement = data + dataSize * ((*numberOfElements) - 2 );
    int indexToInsert = 0;
    int i;

//    if(         *numberOfElements < 0 || (*numberOfElements) + 1 > maxLength         )
//    {
//        return;
//    }

    while(          indexToInsert < *numberOfElements && compare( data, toInsert ) > 0        )
    {
        data += dataSize;
        indexToInsert++;
    }

    if(         !*numberOfElements || compare( data, toInsert ) < 0          )
    {
        for( i = (*numberOfElements) - 1; i > indexToInsert; i-- )
        {
            memcpy( lastElement + dataSize, lastElement, dataSize );
            lastElement -= dataSize;
        }

        memcpy( data, toInsert, dataSize );
        if(         *numberOfElements < maxLength         )
        {
            (*numberOfElements)++;
        }//else queda como esta
    }
}
*/
