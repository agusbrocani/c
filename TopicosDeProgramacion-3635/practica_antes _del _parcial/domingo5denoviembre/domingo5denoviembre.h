#ifndef DOMINGO5DENOVIEMBRE_H_INCLUDED
#define DOMINGO5DENOVIEMBRE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNAS 10
#define MAX_FILAS 10

void mostrarInt( const void* data );
void mostrarMatriz( const void* data, size_t tam, int cf, int cc, void (*mostrar)( const void* data ) );

void cargarMatriz( int mat[][MAX_COLUMNAS], size_t tam, int cf, int cc );

#endif // DOMINGO5DENOVIEMBRE_H_INCLUDED
