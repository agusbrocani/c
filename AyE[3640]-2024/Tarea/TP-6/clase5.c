#include "clase5.h"

void crearLista(t_lista* pl)
{
    *pl = NULL;
}

int insertarAlFinal(t_lista* pl, const void* dato, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(!nuevoNodo)
    {
        fprintf(stderr,"No pude reservar memoria.\n");
        return NO_HAY_LUGAR;
    }

    nuevoNodo->dato = malloc(tam);
    if(!nuevoNodo->dato)
    {
        free(nuevoNodo);
        fprintf(stderr,"No pude reservar memoria.\n");
        return NO_HAY_LUGAR;
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;

    while(*pl)
    {
        pl = &((*pl)->sig);
    }

    nuevoNodo->sig = *pl;
    *pl = nuevoNodo;

    return OK;
}

int sacarFinal(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(NULL == *pl)
    {
        return LISTA_VACIA;
    }

    while((*pl)->sig)
    {
        pl = &((*pl)->sig);
    }
    nodoAEliminar = *pl;
    *pl = nodoAEliminar->sig;

    memcpy(dato, nodoAEliminar->dato, MINIMO(nodoAEliminar->tam, tam));
    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

void vaciarLista(t_lista* pl)
{
    t_nodo* nodoAEliminar;

    while(*pl)
    {
        nodoAEliminar = *pl;
        *pl = (*pl)->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
}

void mostrarListaEnOrdenInversoR(const t_lista* pl, void (*mostrar)(const void* dato))
{
    if(*pl)
    {
        mostrarListaEnOrdenInversoR(&((*pl)->sig), mostrar);
        mostrar((*pl)->dato);
    }
}

void mostrarListaEnOrdenInverso(const t_lista* pl, void (*mostrar)(const void* dato))
{
    t_pila pila;
    void* buffer;
    unsigned tam;

    if(!*pl)    ///ESTO ES NECESARIO, para asignar el tamaño a tam
    {
        return;
    }

    tam = (*pl)->tam;

    buffer = malloc(tam);
    if(!buffer)
    {
        fprintf(stderr, "No pude reservar memoria.\n");
        return;
    }

    crearPila(&pila);

    while(*pl)
    {
        apilar(&pila, (*pl)->dato, tam);
        pl = &((*pl)->sig);
    }

    while(desapilar(&pila, buffer, tam))
    {
        mostrar(buffer);
    }

    vaciarPila(&pila);
    free(buffer);
}
