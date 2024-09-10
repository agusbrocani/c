#ifndef ORDENARCONDOSPILAS_H_INCLUDED
#define ORDENARCONDOSPILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "./Estatica/pila.h"
#include "./Dinamica/pila.h"

void ordenarConDosPilas( FILE* archivo, tPila* pilaEntrada, int tam, int(*comparar)( const void* a, const void* b ), void (*grabarArchivo)( FILE* archivo, const void* dato ) );

#endif // ORDENARCONDOSPILAS_H_INCLUDED
