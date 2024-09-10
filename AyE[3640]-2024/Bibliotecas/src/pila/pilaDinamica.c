#include "../../include/pila/Dinamica/pila.h"


void crearPila( tPila* p )
{
    *p = NULL;
}

//RESERVO MEMORIA NODO
//RESERVO MEMORIA DATO
//INICIALIZO NODO
//ENGANCHO NODO A PILA
//APUNTO p AL NUEVO TOPE

int apilar( tPila* p, const void* dato, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(tNodo));
    if(NULL == nuevoNodo)
    {
        return NO_PUDE_APILAR;
    }
    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        return NO_PUDE_APILAR;
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *p;
    *p = nuevoNodo;

    return OK;
}

int desapilar( tPila* p, void* dato, unsigned tam )
{
    tNodo* nodoAEliminar = *p;

    if(         !nodoAEliminar         )
    {
        return NO_PUDE_DESAPILAR;
    }

    memcpy( dato, nodoAEliminar->dato, MINIMO( nodoAEliminar->tam, tam ) );
    *p = nodoAEliminar->sig;

    free( nodoAEliminar->dato );
    free( nodoAEliminar );

    return OK;
}

void vaciarPila( tPila* p )
{
    tNodo* nodoAEliminar = *p;

    while(NULL != nodoAEliminar)
    {
        *p = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
        nodoAEliminar = *p;
    }
}

int pilaVacia( const tPila* p )
{
    return NULL == *p;
}

int pilaLlena( const tPila* p, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof(tNodo) );

    if(         !nuevoNodo           )
    {
        return PILA_LLENA;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato            )
    {
        free( nuevoNodo );
        return PILA_LLENA;
    }

    free( nuevoNodo->dato );
    free( nuevoNodo );

    return HAY_LUGAR;
}

int verTope( const tPila* p, void* dato, unsigned tam )
{
    if(         !*p         )
    {
        return NO_PUDE_VER_TOPE;
    }

    memcpy( dato, (*p)->dato, MINIMO(tam, (*p)->tam) );

    return OK;
}
