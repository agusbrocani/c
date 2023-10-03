#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define SIZE 1024

#define CORRECTION_RAW(RAW)  (RAW*0.01873128+(-38.682956))


typedef struct
{
    int anio;
    int mes;
    int dia;
}tFecha;

typedef struct
{
    char patente[TAM];
    int nroCuota;
    char nya[TAM];
    int dni;
    tFecha fVencimiento;
    float importe;

}tPatente;


typedef struct
{
    int index;
    char name[TAM];
    char description[TAM];
    int sizeInBytes;

}tTabla1;

typedef struct
{
    char id[SIZE];
    int off;
    char TSLId_VARroot[SIZE];
    char description[SIZE];
    int byte;
    char type[SIZE];
    char rangeOrExpectedValue[SIZE];
    char alarms[SIZE];
}tTabla2;

typedef struct
{
    char name[SIZE];
    char description[SIZE];
    int sizeBytes[SIZE];
    char label[SIZE];
    char mnrFrame[SIZE];
    long double flightModelPendent;
    long double flightModelOffset;
    char typeOfTemp[SIZE];

}tTabla3;

typedef struct
{
    int id;
    int off;
    char tslVar[SIZE];
    char description[SIZE];
    int byte;
    char type[SIZE];
    char rangeOrExpectedValue[SIZE];
}tFigura3;

int checkEndianness();
int abrirArchivo(FILE** pf,const char* nombreArchivo,const char* modo);
void mostrarArchivoBinario(FILE* pf,void* dato,unsigned tam, void (*mostrar)(const void* dato));


#endif // TP_H_INCLUDED
