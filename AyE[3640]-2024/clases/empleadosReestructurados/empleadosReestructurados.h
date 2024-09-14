#ifndef EMPLEADOSREESTRUCTURADOS_H_INCLUDED
#define EMPLEADOSREESTRUCTURADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../clase4/clase4.h"
#include "generico.h"

#define NOMBRE_ARCHIVO_EMPLEADOS "empleados.bin"
#define NOMBRE_ARCHIVO_REESTRUCTURADO "reestructurado.bin"
#define NOMBRE_ARCHIVO_DPTOS_A_REESTRUCTURAR "dptos-a-reestructurar.bin"
#define NOMBRE_ARCHIVO_DPTOS_NO_REESTRUCTURADOS "dptos-no-reestructurados.bin"
#define CATEGORIA_INEXISTENTE -1

#define NO_PUDE_ABRIR_ARCHIVO -1

#define TAM_NYA 100

typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct
{
    char sector;
    int categoria;
    int dni;
    char nya[TAM_NYA];
    tFecha fNac;
}tEmpleado;

typedef struct
{
    char sector;
    int categoriaNecesariaEnSector;
    int cantidadMaximaEmpleadosPorSector;
}tReestructurado;

int compararPorSector(const void* a, const void* b);
void mostrarEmpleado(const tEmpleado* bufferEmpleado);

void crearEmpleadosBin();
void crearReestructuradoBin();
void generarReporte(FILE* aEmpleados, FILE* aReestructurado, FILE* aDptosAReestructurar, FILE* aDptosNoReestructurados, int (*comparar)(const void* a, const void* b));

void mostrarArchivosResultantes(FILE* aDptosAReestructurar, FILE* aDptosNoReestructurados);
#endif // EMPLEADOSREESTRUCTURADOS_H_INCLUDED
