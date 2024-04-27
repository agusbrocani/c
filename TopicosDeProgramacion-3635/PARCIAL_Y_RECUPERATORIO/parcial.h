#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define ES_LETRA(X) ( ( ( X >= 'A' ) && ( X <= 'Z' ) ) || ( ( X >= 'a' ) && ( X <= 'z' ) ) )
#define TAM 1025

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );
int proximaPalabra( char** cadena, char** palabra );
size_t miStrlen( const char *cadena );
void cambiaLetra( char* letra );
void darVueltaPalabra( char* palabra, int tamPalabra );
void desofuscarRegistro( char* buffer );

#endif // PARCIAL_H_INCLUDED
