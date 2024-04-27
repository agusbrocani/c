#include "unit1Header.h"

int main()
{
    ///EJERCICIO 1:
//    int vec[MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9};
//    //int vec[MAX_SIZE] = {};
//    //int vec[MAX_SIZE] = {0};
//    int dataToInsert = -1;
//    size_t numberOfElements = 0;
//    int indexToInsert = 0;
//    if(         !insertIntoPosition(vec,&dataToInsert,indexToInsert,sizeof(int),&numberOfElements)         )
//    {
//        printf("Do not allow data insertion into the selected position.\n");
//    }
//
//    showData(vec,sizeof(int),numberOfElements,showInt);
    ///EJERCICIO 2:
//    int vec[MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9};
//    //int vec[MAX_SIZE] = {};
//    //int vec[MAX_SIZE] = {0};
//    int dataToInsert = -1;
//    size_t numberOfElements = 0;
//    sortedInsert(vec,&dataToInsert,sizeof(int),&numberOfElements,cmpInt);
//    showData(vec,sizeof(int),numberOfElements,showInt);

      ///EJERCICIO 3
//    int vec[MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9};
//    //int vec[MAX_SIZE] = {};
//    //int vec[MAX_SIZE] = {0};
//    size_t numberOfElements numberOfElements = 10;
//    int indexToDelete = 9;
//    int deleatedData;
//    if(         !deleteElementInPosition(vec,&deleatedData,indexToDelete,sizeof(int),&numberOfElements)          )
//    {
//        printf("Index to delete not found");
//    }
//    else
//    {
//        printf("Deleated Data: %d\n",deleatedData);
//        showData(vec,sizeof(int),numberOfElements,showInt);
//    }
    ///EJERCICIO 4
//    int vec[MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9};
    int vec[MAX_SIZE] = {1,1,2,3,1,5,1,7,1,1};
//    //int vec[MAX_SIZE] = {};
//    //int vec[MAX_SIZE] = {0};
    size_t numberOfElements = 10;
    int elementToDelete = 1;

    //deleteFirstOccurrence( vec, &elementToDelete, sizeof(int), &numberOfElements, cmpInt );
    deleteAllOccurrences( vec, &elementToDelete, sizeof(int), &numberOfElements, cmpInt );
    showData( vec, sizeof(int), numberOfElements, showInt );

    return 0;
}

/*
    int vec[] = { 1, 1, 2, 3, 1, 5, 1, 7, 1, 1 };   size_t numberOfElements = sizeof(vec)/sizeof(int);  size_t dataSize = sizeof(int);
//    int vec[] = { 1, 1, 2, 3, 1, 1, 5, 1, 7};   size_t numberOfElements = sizeof(vec)/sizeof(int);  size_t dataSize = sizeof(int);
//    int vec[] = { 2, 3, 1, 5, 1, 1, 7, 1, 1 };   size_t numberOfElements = sizeof(vec)/sizeof(int);  size_t dataSize = sizeof(int);
//    int vec[] = {1}; size_t numberOfElements = sizeof(vec)/sizeof(int);  size_t dataSize = sizeof(int);
//    int vec[] = {}; size_t numberOfElements = sizeof(vec)/sizeof(int);  size_t dataSize = sizeof(int);
    int toDelete = 1;

    showData( vec, dataSize, numberOfElements, showInt );

    deleteAllOccurrences( vec, &toDelete, dataSize, &numberOfElements, compareInt );

    showData( vec, dataSize, numberOfElements, showInt );
*/
