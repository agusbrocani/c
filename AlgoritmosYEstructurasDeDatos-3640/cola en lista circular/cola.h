#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include<stdlib.h>
#include<string.h>

#define minimo(X,Y) (((X)>(Y))? (Y) : (X))

typedef struct sNodo{
    void* d;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tCola;

void crearCola(tCola* c);
int acolar(tCola* c, const void* d, unsigned tam);
int desacolar(tCola* c, void* d, unsigned tam);
int colaLlena(const tCola* c,unsigned tam);
int colaVacia(const tCola* c);
int verPrimero(const tCola* c, void* d, unsigned tam);
void vaciarCola(tCola* c);
void vaciarColaRecursivo(tCola* c);
#endif // COLA_H_INCLUDED
