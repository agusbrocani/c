#ifndef UNIDAD1VECTORESGEN_H_INCLUDED
#define UNIDAD1VECTORESGEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_MAYUS(X) (            ( X >= 'a' && X <= 'z' ) ? ( X - ('a'-'A') ) : (X)          )

#define CEInt 10
#define CEChar 100


char validaOpcion(char opcion);

size_t miStrlen(const char* cadena);

void mostrarDatoEntero(void* vec);
void mostrarDatoChar(void* vec);
void mostrarVector(void* vec,unsigned tam,unsigned ce,void (*mostrar) (void* vec) );
void insertarEnPosicion(void* vec, void* dato,unsigned tam,unsigned ce, unsigned pos);


#endif // UNIDAD1VECTORESGEN_H_INCLUDED
