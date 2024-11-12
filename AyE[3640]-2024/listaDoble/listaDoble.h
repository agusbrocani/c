#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_HAY_ELEMENTOS 0
#define NO_HAY_LUGAR 0
#define NO_PUDE_RESERVAR_MEMORIA 0
#define OK 1

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
    struct s_nodo* ant;
}t_nodo;

typedef t_nodo* t_listaDoble;

void crearListaDoble(t_listaDoble* pl);
int insertarOrdenadoConAccionEnRepetidosEnListaDoble(t_listaDoble* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* datoNodo, const void* dato));
void vaciarListaDoble(t_listaDoble* pl);
void mostrarListaDobleIzqDer(const t_listaDoble* pl, void (*mostrar)(const void* dato));
void mostrarListaDobleDerIzq(const t_listaDoble* pl, void (*mostrar)(const void* dato));

int eliminarDeListaDoble(t_listaDoble *p, unsigned cantBytes, const void *dato, int (*cmp)(const void*, const void*));

#endif // LISTADOBLE_H_INCLUDED
