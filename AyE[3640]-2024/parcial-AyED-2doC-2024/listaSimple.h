#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NO_PUDE_RESERVAR_MEMORIA 0
#define OK 1
#define DATO_DUPLICADO 2
#define LISTA_VACIA 0
#define MENOR(X,Y) (((X) < (Y)) ? (X) : (Y))

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* pl);
int insertarOrdenadoConAccion(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, const void* datoAInsertar));
void mapEnListaSimple(const t_lista* pl, void* recursos, void (*accion)(void* dato, void* recursos));
void vaciarLista(t_lista* pl);
int sacarPrimero(t_lista* pl, void* dato, unsigned tam);

#endif // LISTASIMPLE_H_INCLUDED
