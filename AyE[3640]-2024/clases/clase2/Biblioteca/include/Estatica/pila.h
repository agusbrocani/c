#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENOR( X, Y ) ( ( X < Y ) ? ( X ) : ( Y ) )

#define NO_HAY_LUGAR 0
#define OK 1

#define PILA_LLENA 1
#define HAY_LUGAR 0

#define PILA_VACIA 0

#define TAM_PILA 1000

typedef struct
{
    char pila[TAM_PILA];
    unsigned tamDisponible;
}tPila;

void crearPila( tPila* p );
int apilar( tPila* p, const void* dato, unsigned tam );
int desapilar( tPila* p, void* dato, unsigned tam );
int verTope( const tPila* p, void* dato, unsigned tam );
int pilaVacia( const tPila* p );
int pilaLlena( const tPila* p, unsigned tam );
void vaciarPila( tPila* p );


#endif // PILA_H_INCLUDED
