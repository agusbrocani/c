#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ES_LETRA(X) ( ( X >= 'A' && X <= 'Z' ) || ( X >= 'a' && X <= 'z' ) )

size_t quieroUnaLineaDeTextoOfuscadaV1(char* linea);

int buscarIndice( const char* grupo, char letra );
void validoYCambioLetra( char* letra, int offset );
char* desofuscar( char* linea );

int miProximaPalabra( char** cadena, char** comienzoPalabra );

#endif // OFUSCADO_INCLUDED
