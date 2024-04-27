#ifndef PARCIALMARTES_H_INCLUDED
#define PARCIALMARTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ES_LETRA(X) ( (X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z') )
#define TAM 1000
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

typedef struct
{
    char palabra[TAM];
    int cantidadDeOcurrencias;
}tRetorno;

int cmpInt( const void* a, const void* b);
void mostrarInt( const void* data );
void mostrarMatriz( const void* data, int tam, int cf, int cc, void (*mostrar)( const void* data ) );

void crearLote();
int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );

void* _bbinaria( const void* clave, const void* base, size_t ce, size_t tam, int (*comparar)(const void * a, const void * b ) );
int proximaPalabra( char** cadena, char** palabra );
int _contarPalabras( FILE* pf, tRetorno* retorno );
int sumTrianInfEntreDiag( int mat[][MAX_COLUMNAS], int cf, int cc );
int sumTrianDerEntreDiag( int mat[][MAX_COLUMNAS], int cf, int cc );
void inicializarMatriz( int mat[][MAX_COLUMNAS] );
void elRelojCucu( int mat[][MAX_COLUMNAS],int cf, int cc );

int miStrlen( const char* cadena );
void miStrncpy( char* destino, const char* origen, int cantACopiar );
int miStrncmp( const char* cadena1, const char* cadena2, int cantidadAComparar );

#endif // PARCIALMARTES_H_INCLUDED
