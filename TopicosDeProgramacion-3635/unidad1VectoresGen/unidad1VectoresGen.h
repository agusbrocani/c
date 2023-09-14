#ifndef UNIDAD1VECTORESGEN_H_INCLUDED
#define UNIDAD1VECTORESGEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_MAYUS(X) (            ( X >= 'a' && X <= 'z' ) ? ( X - ('a'-'A') ) : (X)          )
#define ABS(X) ( (X < 0) ? ( (X) * (-1) ) : (X) )

#define CEInt 10
#define CEChar 100


char validaOpcion(char opcion);

size_t miStrlen(const char* cadena);

void mostrarDatoEntero(void* vec);
void mostrarDatoChar(void* vec);
void mostrarVector(void* vec,unsigned tam,unsigned ce,void (*mostrar) (void* vec) );
int comparaEnteros(const void* a, const void* b);
void insertarEnPosicion(void* vec, const void* dato,unsigned tam,unsigned ce, unsigned pos);
void insertarOrdenado(void* vec, const void* dato, unsigned tam, unsigned ce, unsigned pos);
int eliminarPosicion(void* vec,void* dato, unsigned tam, unsigned* ce, unsigned pos);
int eliminarPrimerAparicion(void* vec,const void* dato, unsigned tam, unsigned* ce,int (*comparar) (const void* a, const void* b) );
int eliminarApariciones(void* vec,const void* dato, unsigned tam, unsigned* ce,int (*comparar) (const void* a, const void* b) );

#endif // UNIDAD1VECTORESGEN_H_INCLUDED
