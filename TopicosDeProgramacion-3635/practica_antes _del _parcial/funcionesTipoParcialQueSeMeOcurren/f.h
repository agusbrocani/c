#ifndef F_H_INCLUDED
#define F_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define BUFFER_SIZE 1000
#define CE_MAX 6

typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;


typedef struct
{
    int id;
    char nya[TAM];
    char sexo;
    tFecha fNac;
    float salario;
}tEmpleado;

int comparaEmpleadosPorNYA( const void* a, const void* b);
int comparaEmpleadosPorID( const void* a, const void* b);
int comparaEmpleadosIDMayor( const void* a, const void* b );

void mostrarEmpleado( const void* data );
void mostrar( const void* data, size_t tam, int ce, void (*mostrar)( const void* data ) );

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );
void crearLoteEmpleados();

void* buscarMenor( void* data, size_t tam, int ce, int (*comparar)( const void* a, const void* b ) );
void* buscarMayor( void* data, size_t tam, int ce, int (*comparar)( const void* a, const void* b ) );
void fSwap( void* a, void* b, size_t tam );
void ordenarPorSeleccion( void* data, size_t tam, int ce, int (*comparar)( const void* a, const void* b ));
void insertarOrdenado( void* data, const void* aInsertar, size_t tam, int* ce, int (*comparar)( const void* a, const void* b ));

void trozar( tEmpleado* empleado, char* buffer );

#endif // F_H_INCLUDED
