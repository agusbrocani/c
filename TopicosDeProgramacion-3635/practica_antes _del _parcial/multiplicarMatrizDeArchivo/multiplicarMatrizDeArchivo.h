#ifndef MULTIPLICARMATRIZDEARCHIVO_H_INCLUDED
#define MULTIPLICARMATRIZDEARCHIVO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILAS 50
#define MAX_COLUMNAS 50
#define TAM 100

void crearLote();
int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );
void mostrarMatriz( int mat[][MAX_COLUMNAS], int cantFilas, int cantColumnas );
void productoDeMatriz( int matriz1[][MAX_COLUMNAS], int matriz2[][MAX_COLUMNAS], int matResultados[][MAX_COLUMNAS], int cantFilas, int cantColumnas, int cantFilas2, int cantColumnas2 );

#endif // MULTIPLICARMATRIZDEARCHIVO_H_INCLUDED
