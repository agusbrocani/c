#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_COLA 350

#define MENOR(X,Y) ( ( (X) < (Y) ) ? (X) : (Y) )

#define OK 1
#define NO_HAY_LUGAR 0
#define HAY_LUGAR 0
#define COLA_LLENA 1
#define COLA_VACIA 0

typedef struct
{
    unsigned pri;
    unsigned ult;
    unsigned tamDisponible;
    char cola[TAM_COLA];
}tCola;

void crearCola( tCola* c );
int acolar( tCola* c, const void* dato, unsigned tam );
int desacolar( tCola* c, void* dato, unsigned tam );
int colaVacia( const tCola* c );
int colaLlena( const tCola* c, unsigned tam );
void vaciarCola( tCola* c );
int verPrimero( const tCola* c, void* dato, unsigned tam );

#endif // COLA_H_INCLUDED
