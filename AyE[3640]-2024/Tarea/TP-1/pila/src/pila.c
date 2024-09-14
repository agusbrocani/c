#include "../include/pila.h"

void crearPila (t_pila* p)
{
    *p = NULL;
}

int apilar (t_pila* p, const void* elem, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
        return PILA_LLENA;

    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
        return PILA_LLENA;

    memcpy(nuevoNodo->dato, elem, tam);
    nuevoNodo->tamElem = tam;
    nuevoNodo->sigNodo = *p;
    *p = nuevoNodo;

    return TODO_OK;
}

int desapilar (t_pila* p, void* elem, unsigned tam)
{
    t_nodo* elim = *p;
    if(NULL == *p)
        return PILA_VACIA;

    memcpy(elem, elim->dato, MINIMO(tam, elim->tamElem));
    *p = elim->sigNodo;

    free(elim->dato);
    free(elim);
    return TODO_OK;
}

int verTope (const t_pila* p, void* dato, unsigned tam)
{
    if(NULL == *p)
        return PILA_VACIA;

    memcpy(dato, (*p)->dato, MINIMO(tam, (*p)->tamElem));
    return TODO_OK;
}

void vaciarPila (t_pila* p)
{
    t_nodo* elim = *p;
    while(*p)
    {
        *p = elim->sigNodo;
        free(elim->dato);
        free(elim);
        elim = *p;
    }
}
