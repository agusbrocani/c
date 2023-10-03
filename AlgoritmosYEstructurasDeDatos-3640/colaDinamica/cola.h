#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#define minimo(X,Y) (((X)<(Y))? (X) : (Y))


typedef struct sNodo
{
    void* info;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef struct
{
    tNodo* pri;
    tNodo* ult;

}tCola;

void crearCola(tCola *c);
int acolar(tCola* c,const void* d, size_t tam);
int desacolar(tCola* c, void* d, size_t tam);
int colaVacia(const tCola* c);
int colaLlena(const tCola* c, size_t tam);
void vaciarCola(tCola* c);
int verPrimero(const tCola *c, void*d ,size_t tam );



#endif // COLA_H_INCLUDED
