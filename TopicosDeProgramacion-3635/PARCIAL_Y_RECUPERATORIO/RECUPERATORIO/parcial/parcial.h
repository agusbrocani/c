#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 50
#define MAX_COLUMNA 50

void mostrarMatriz( int mat[][MAX_COLUMNA], int cf, int cc );
void trasponerMatriz( int mat[][MAX_COLUMNA], int cf, int cc );

void mostrarEntero( const void* data );
void mostrarVector( const void* data, int tam, int ce, void (*mostrar)(const void* data) );

int comparaEnteros( const void* a, const void* b );
void* miBsearch( const void* clave, const void* data, size_t ce, size_t tam, int (*comparar)(const void *, const void *));

#endif // PARCIAL_H_INCLUDED
