#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Bibliotecas/include/lote.h"
#include "../Bibliotecas/include/generico.h"

#define HAY_LUGAR 1
#define OK 1
#define NO_PUDE_RESERVAR_MEMORIA 0
#define LISTA_VACIA 0
#define MENOR(X,Y) ((X) < (Y) ? (X) : (Y))

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearListaSimple(t_lista* pl);
void vaciarListaSimple(t_lista* pl);
int listaSimpleVacia(const t_lista* pl);
int listaSimpleLlena(const t_lista* pl);

int insertarPrimeroEnListaSimple(t_lista* pl, const void* dato, unsigned tam);
int insertarAlFinalEnListaSimple(t_lista* pl, const void* dato, unsigned tam);
int sacarPrimeroEnListaSimple(t_lista* pl, void* dato, unsigned tam);
int sacarUltimoEnListaSimple(t_lista* pl, void* dato, unsigned tam);

void mostrarListaSimpleEnOrden(const t_lista* pl, void (*mostrar)(const void* dato));
void mostrarListaSimpleEnOrdenInversoRecursivo(const t_lista* pl, void (*mostrar)(const void* dato));
void mapEnListaSimple(const t_lista* pl, void* recursos, void (*accion)(void* dato, void* recursos));
void filter(const t_lista* pl, const void* clave, void* recursos, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* recursos));
int insertarOrdenadoEnListaSimpleSinDuplicados(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* datoDuplicado));
t_nodo** buscarMenor(t_lista* pl, int (*comparar)(const void* a, const void* b));
void ordenarListaSimple(t_lista* pl, int (*comparar)(const void* a, const void* b));

void eliminarDuplicadosEnListaSimpleConAccion(t_lista* pl, void* recursos, int (*comparar)(const void* a, const void* b),void (*accion)(void* dato, void* recursos));

#endif // LISTASIMPLE_H_INCLUDED
