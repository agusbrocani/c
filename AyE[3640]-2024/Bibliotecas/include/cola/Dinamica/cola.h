#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NO_PUDE_ACOLAR 0
#define HAY_LUGAR 0
#define COLA_LLENA 1
#define COLA_VACIA 0

#define MENOR(X,Y) ( ( X < Y ) ? (X) : (Y) )

typedef struct sNodo
{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef struct
{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearCola( tCola* c );
int acolar( tCola* c, const void* dato, unsigned tam );
int desacolar( tCola* c, void* dato, unsigned tam );
int colaLlena( const tCola* c, unsigned tam );
int colaVacia( const tCola* c );
int verPrimero( const tCola* c, void* dato, unsigned tam );
void vaciarCola( tCola* c );


#endif // COLA_H_INCLUDED
