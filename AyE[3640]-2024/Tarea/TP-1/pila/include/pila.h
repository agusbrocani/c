#ifndef PILA_H_
#define PILA_H_

#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TODO_OK 1
#define PILA_LLENA 0
#define HAY_LUGAR 0
#define PILA_VACIA 0

#define MINIMO(X, Y) ((X) > (Y) ? Y : X)

typedef struct s_nodo
{
    void* dato;
    unsigned tamElem;
    struct s_nodo* sigNodo;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila (t_pila* p);
int apilar (t_pila* p, const void* elem, unsigned tam);
int desapilar (t_pila* p, void* dato, unsigned tam);
void vaciarPila (t_pila* p);
int verTope (const t_pila* p, void* dato, unsigned tam);

#endif // PILA_H_
