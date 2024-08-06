#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );
void mostrarColeccion( const void* dato, int tam, int ce, void (*mostrar)( const void* dato ) );
#endif // GENERICO_H_INCLUDED
