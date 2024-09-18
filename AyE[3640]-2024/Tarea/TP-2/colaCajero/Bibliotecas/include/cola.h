#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENOR(X,Y) (((X) < (Y)) ? (X) : (Y))

#define OK 1
#define NO_HAY_LUGAR 0
#define COLA_VACIA 0
#define HAY_LUGAR 0

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef struct
{
    t_nodo* pri;
    t_nodo* ult;
}t_cola;

void crearCola(t_cola* c);
int acolar(t_cola* c, const void* dato, unsigned tam);
int desacolar(t_cola* c, void* dato, unsigned tam);
void vaciarCola(t_cola* c);
int colaVacia(const t_cola* c);
int colaLlena(const t_cola* c);
int verPrimero(const t_cola* c, void* dato, unsigned tam);

#endif // COLA_H_INCLUDED
