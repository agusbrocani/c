#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define FILE_ERR -1
#define MEM_ERR -2
#define OK 0

typedef struct
{
    int dni;
    char surname[SIZE];
    char name[SIZE];
    float salary;
}tEmployee;

typedef struct
{
    tEmployee employee;
    char noveltyType;
}tNovelty;

int compareDNI(const void* a, const void* b);
void updateEmp(void* a, void* b);
void showEmployee(const void* data);
void showNovelty(const void* data);

int createEmployeeBatch(const char* fileName, const char* fileMode);
int createNoveltiesBatch(const char* fileName, const char* fileMode);
int createBatch(const char* fileName, const char* fileMode, int(*createTypeBatch)(const char*, const char*));
int openFile(FILE** filePointer, const char* fileName, const char* mode);

void updateFile(FILE* pfMaster,FILE* pfNovelties,FILE* pfTemp, int (*compare) (const void* a, const void* b), void (*update)(void* a ,void* b));


#endif // ABM_H_INCLUDED
