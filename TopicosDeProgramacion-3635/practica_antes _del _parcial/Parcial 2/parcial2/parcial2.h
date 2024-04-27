#ifndef PARCIAL2_H_INCLUDED
#define PARCIAL2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLUMNAS 5
#define MAX_FILAS 5

int comparaInt( const void* a, const void* b );
void mostrarInt( const void* data );
void mostrarVector( const void* data, size_t tam, int ce, void (*mostrar) ( const void* data ) );
void mostrarMatriz( const void* data, size_t tam, int cf, int cc, void (*mostrar)( const void* data ) );


void* buscarMenor( void* data, size_t tam, size_t ce, int (*comparar)( const void* a, const void* b ) );
void fSwap( void* a, void* b, size_t tam );
void _ordenarSeleccion( void* data, size_t ce, size_t tam, int (*comparar)( const void* a, const void* b ) );

int miStrlen( const char* cadena );
int miStrncmp( const char* cadena1, const char* cadena2, int cantidad );
char* miStrstr( const char *cadena1, const char *cadena2 );

int _contarCelulasVivasEnVecindario( int mat[][MAX_COLUMNAS], int cf, int cc, int posF, int posC, int (*comparar)( const void* a, const void* b ) );

#endif // PARCIAL2_H_INCLUDED
