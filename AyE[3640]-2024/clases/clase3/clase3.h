#ifndef CLASE3_H_INCLUDED
#define CLASE3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 1000

#define PILA_LLENA 1
#define HAY_LUGAR 0

#define NO_HAY_LUGAR 0

#define OK 1

#define PILA_VACIA 0

#define MINIMO(X,Y) (((X) < (Y)) ? (X) : (Y))

//Estatica
//typedef struct
//{
//    char pila[TAM_PILA];
//    unsigned tope;
//}t_pila;

//Dinamica
typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila* p);
int apilar(t_pila* p, const void* dato, unsigned tam);
int desapilar(t_pila* p, void* dato, unsigned tam);
void vaciarPila(t_pila* p);
int verTope(const t_pila* p, void* dato, unsigned tam);
int pilaLlena(const t_pila* p, unsigned tam);
int pilaVacia(const t_pila* p);



#endif // CLASE3_H_INCLUDED
