#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENOR(X, Y) (((X) < (Y)) ? (X) : (Y))

#define OK 1
#define NO_PUDE_INSERTAR 0
#define NO_HAY_ELEMENTOS 0

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* pl);
int insertarAlFinal(t_lista* pl, const void* dato, unsigned tam);
int sacarUltimo(t_lista* pl, void* dato, unsigned tam);
void vaciarLista(t_lista* pl);
int insertarOrdenadoSinDuplicados(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b));
int insertarOrdenado(t_lista *pl, const void *dato, unsigned tam, int (*cmp)(const void *, const void *));

void mostrarListaEnOrden(const t_lista* pl, void (*mostrar)(const void* dato));

t_nodo** buscarMenor(t_lista* pl, int (*comparar)(const void* a, const void* b));
void ordenarLista(t_lista* pl, int (*comparar)(const void* a, const void* b));

#endif // LISTASIMPLE_H_INCLUDED
