/// Luca Arce, Agustin Brocani, Ezequiel Muñoz y Lautaro Vega
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "./pila/include/pila.h"

#define NOMBRE_ARCHIVO_BINARIO_DESORDENADO "datos.bin"
#define NOMBRE_ARCHIVO_BINARIO_ORDENADO "datosOrdenados.bin"
#define NUEVO_NOMBRE_ARCHIVO "datos.bin"

#define TODO_OK 1
#define ERR_APERTURA_ARCHIVO -1
#define NO_SE_ABRIO_ARCH 0

#define TAM_NYA 100
typedef struct
{
    int id;
    char nya[TAM_NYA];
    char sexo;
    float salario;
}tEmpleado;

int comparaEmpleadosPorID(const void* a, const void* b);
void mostrarEmpleado(const void* dato);
void mostrarArchivoBinario (FILE* fp, unsigned tamDato, void (*mostrarEmpleado)(const void* dato));

int abrirArchivo (FILE** fp, const char* nombreArch, const char* modo);
void crearLoteEmpleado ();
void ordenarArchivoConDosPilas (FILE* desordenado, FILE* ordenado, unsigned tamDato, int (*comparar)(const void* a, const void* b));
#endif // FUNCIONES_H_INCLUDED
