#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define MINIMO(X,Y) ( ( (X) < (Y) ) ? (X) : (Y) )

#define NO_PUDE_APILAR 0
#define NO_PUDE_DESAPILAR 0
#define NO_PUDE_VER_TOPE 0
#define PILA_LLENA 1
#define HAY_LUGAR 0

typedef struct sNodo
{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;

void crearPila( tPila* p );
int apilar( tPila* p, const void* dato, unsigned tam );
int desapilar( tPila* p, void* dato, unsigned tam );
void vaciarPila( tPila* p );
int pilaVacia( const tPila* p );
int pilaLlena( const tPila* p, unsigned tam );
int verTope( const tPila* p, void* dato, unsigned tam );

#endif // PILA_H_INCLUDED
