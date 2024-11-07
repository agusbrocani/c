#include "listaSimple.h"

void crearLista(t_lista* pl)
{
    *pl = NULL;
}

int insertarOrdenadoConAccion(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, const void* datoAInsertar))
{
    t_nodo* nuevoNodo;

    while(*pl && comparar(dato, (*pl)->dato) > 0)
    {
        pl = &((*pl)->sig);
    }

    if(!*pl || comparar(dato, (*pl)->dato) < 0)
    {
        nuevoNodo = malloc(sizeof(t_nodo));
        if(!nuevoNodo)
        {
            fprintf(stderr, "No pude reservar memoria.\n");
            return NO_PUDE_RESERVAR_MEMORIA;
        }
        nuevoNodo->dato = malloc(tam);
        if(!nuevoNodo->dato)
        {
            fprintf(stderr, "No pude reservar memoria.\n");
            free(nuevoNodo);
            return NO_PUDE_RESERVAR_MEMORIA;
        }
        memcpy(nuevoNodo->dato, dato, tam);
        nuevoNodo->tam = tam;
        nuevoNodo->sig = *pl;
        *pl = nuevoNodo;
    }
    else
    {
        ///DUPLICADO
        accion((*pl)->dato, dato);
        return DATO_DUPLICADO;
    }

    return OK;
}

void mapEnListaSimple(const t_lista* pl, void* recursos, void (*accion)(void* dato, void* recursos))
{
    while(*pl)
    {
        accion((*pl)->dato, recursos);
        pl = &((*pl)->sig);
    }
}

void vaciarLista(t_lista* pl)
{
    t_nodo* nodoAEliminar;

    while(*pl)
    {
        nodoAEliminar = *pl;
        *pl = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
}

int sacarPrimero(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(!*pl)
    {
        return LISTA_VACIA;
    }
    nodoAEliminar = *pl;
    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));
    *pl = nodoAEliminar->sig;

    free(nodoAEliminar->dato);
    free(nodoAEliminar);
    return OK;
}
