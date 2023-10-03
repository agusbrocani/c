#ifndef ARCHIVOSBINARIOS_H_INCLUDED
#define ARCHIVOSBINARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

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

void mostrarTPatente(const void* dato);

void crearLote(); //crear un archivo cargado completo, luego con abrir y mostrar deberiamos ver lo mismo que cargamos
int abrirArchivo(FILE** pf,const char* nombreArchivo,const char* modo);
void mostrarArchivoBinario(FILE* pf,void* dato,unsigned tam, void (*mostrar)(const void* dato));


#endif // ARCHIVOSBINARIOS_H_INCLUDED
