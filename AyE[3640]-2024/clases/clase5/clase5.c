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

    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));
    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

//int insertarAlInicio(t_lista* pl, const void* dato, unsigned tam);
//int sacarInicio(t_lista* pl, void* dato, unsigned tam);

void mostrarListaEnOrden(const t_lista* pl, void (*mostrar)(const void* dato))
{
    while(*pl)
    {
        mostrar((*pl)->dato);
        printf("\n");
        pl = &((*pl)->sig);
    }
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
    if(*pl && (*pl)->sig)
    {
        mostrarListaEnOrdenInversoR(&((*pl)->sig), mostrar);
    }
    mostrar((*pl)->dato);
}

int insertarAlFinalR(t_lista* pl, const void* dato, unsigned tam)
{
    if(*pl)
    {
        return insertarAlFinalR(&((*pl)->sig), dato, tam);
    }
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
    {
        fprintf(stderr, "No pude reservar memoria.");
        return NO_HAY_LUGAR;
    }

    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        fprintf(stderr, "No pude reservar memoria.");
        return NO_HAY_LUGAR;
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *pl;
    *pl = nuevoNodo;

    return OK;
}

void* mapEnListaSimple(const t_lista* pl, void (*accion)(void* dato))
{
    t_nodo* inicioLista = *pl;

    while(*pl)
    {
        accion((*pl)->dato);
        pl = &((*pl)->sig);
    }

    return inicioLista;
}
