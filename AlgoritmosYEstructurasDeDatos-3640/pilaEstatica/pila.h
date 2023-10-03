#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <string.h>

#define minimo(X,Y) (((X)<(Y))? (X) : (Y))
#define TAM_PILA 350

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope; //tam disponible
}tPila;

void crearPila(tPila* p);
int apilar(tPila* p, const void* d, unsigned tam);
int desapilar(tPila*p, void*d, unsigned tam);
int pilaVacia(const tPila* p);
void vaciarPila(tPila *p);
int verTope(const tPila *p, void* d, unsigned tam);
int pilaLlena(const tPila*p,unsigned tam);



#endif // PILA_H_INCLUDED
