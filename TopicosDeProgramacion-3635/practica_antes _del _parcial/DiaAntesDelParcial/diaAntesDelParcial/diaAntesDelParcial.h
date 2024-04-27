#ifndef DIAANTESDELPARCIAL_H_INCLUDED
#define DIAANTESDELPARCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarInt( const void* data );
void mostrarVector( const void* data, size_t tam, int ce, void (*mostrar)( const void* data ) );
int comparaIntAB( const void* a, const void* b );
int comparaIntBA( const void* a, const void* b );
int insertarOrdenado( void* data, const void* aInsertar, size_t tam, int* ce, int maxCe, int (*comparar)( const void* a, const void* b) );


#endif // DIAANTESDELPARCIAL_H_INCLUDED
