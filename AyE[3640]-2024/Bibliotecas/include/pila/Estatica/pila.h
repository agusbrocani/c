#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 10000
#define MINIMO(X,Y) ( ( (X) < (Y) ) ? (X) : (Y) )

#define OK 1
#define NO_HAY_LUGAR 0
#define PILA_VACIA 0
#define PILA_LLENA 1
#define HAY_LUGAR 1

typedef struct
{
    char pila[TAM_PILA];
    unsigned tamDisponible;
}tPila;

void crearPila( tPila* p );
int apilar( tPila* p, const void* dato, unsigned tam );
int desapilar( tPila* p, void* dato, unsigned tam );
void vaciarPila( tPila* p );
int pilaLlena( const tPila* p, unsigned tam );
int pilaVacia( const tPila* p );
int verTope( const tPila* p, void* dato, unsigned tam );



#endif // PILA_H_INCLUDED
