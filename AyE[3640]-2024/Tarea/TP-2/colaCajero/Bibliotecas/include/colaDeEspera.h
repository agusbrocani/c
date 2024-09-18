#ifndef COLADEESPERA_H_INCLUDED
#define COLADEESPERA_H_INCLUDED
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD_INTERVALOS_ALEATORIOS 3
#define MAX_CANTIDAD_DE_SIMULACIONES 5

void simulacroColaDeEspera(const int* intervalosDeAcolado, const int* intervalosDeDesacolado);

#endif // COLADEESPERA_H_INCLUDED
