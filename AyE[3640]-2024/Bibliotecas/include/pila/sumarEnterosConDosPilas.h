#ifndef SUMARENTEROSCONDOSPILAS_H_INCLUDED
#define SUMARENTEROSCONDOSPILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "./Estatica/pila.h"
#include "./Dinamica/pila.h"
#include "../generico.h"

void sumarEnterosConDosPilas( tPila* pilaResultado, tPila* pila1, tPila* pila2, FILE* aResultado, void* grabarSegunEstrategia );

#endif // SUMARENTEROSCONDOSPILAS_H_INCLUDED
