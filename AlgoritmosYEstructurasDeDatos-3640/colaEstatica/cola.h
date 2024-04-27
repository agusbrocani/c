#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include<stdlib.h>
#include<string.h>
#define TAM_COLA 17
typedef struct
{
    unsigned pri,ult,tamDis;
    char cola[TAM_COLA];
}tCola;

void crearCola(tCola *c);
int acolar(tCola* c,const void* d, unsigned tam);
int desacolar(tCola* c, void* d, unsigned tam);
int colaVacia(const tCola* c);
int colaLlena(const tCola* c, size_t tam);
void vaciarCola(tCola* c);
int verPrimero(const tCola *c, void*d ,size_t tam );


#endif // COLA_H_INCLUDED
