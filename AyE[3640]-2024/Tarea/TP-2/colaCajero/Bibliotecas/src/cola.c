#include "../include/cola.h"

void crearCola(t_cola* c)
{
    c->pri = NULL;
    c->ult = NULL;
}
int acolar(t_cola* c, const void* dato, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
    {
        return NO_HAY_LUGAR;
    }

    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        return NO_HAY_LUGAR;
    }
    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = NULL;

    if(NULL == c->pri)
    {
        c->pri = nuevoNodo;
    }
    else
    {
        c->ult->sig = nuevoNodo;
    }
    c->ult = nuevoNodo;

    return OK;
}
int desacolar(t_cola* c, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar = c->pri;

    if(NULL == nodoAEliminar)
    {
        return COLA_VACIA;
    }

    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));

    c->pri = nodoAEliminar->sig;
    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}


void vaciarCola(t_cola* c)
{
    t_nodo* nodoAEliminar = c->pri;

    while(c->pri)
    {
        nodoAEliminar = c->pri;
        c->pri = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
}

int colaVacia(const t_cola* c)
{
    return NULL == c->pri;
}

int colaLlena(const t_cola* c)
{
    return HAY_LUGAR;
}

int verPrimero(const t_cola* c, void*dato, unsigned tam)
{
    if(NULL == c->pri)
    {
        return COLA_VACIA;
    }
    memcpy(dato, c->pri->dato, MENOR(c->pri->tam, tam));

    return OK;
}
