#include "../../include/Dinamica/pila.h"

void crearPila( tPila* p )
{
    *p = NULL;
}

int apilar( tPila* p, const void* dato, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if( !nuevoNodo )
    {
        return NO_HAY_LUGAR;
    }

    nuevoNodo->dato = malloc( tam );

    if( !nuevoNodo->dato )
    {
        free( nuevoNodo );
        return NO_HAY_LUGAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *p;
    *p = nuevoNodo;

    return OK;
}

int desapilar( tPila* p, void* dato, unsigned tam )
{
    tNodo* nodoAEliminar = *p;

    if( !nodoAEliminar )
    {
        return PILA_VACIA;
    }

    memcpy( dato, nodoAEliminar->dato, MENOR( nodoAEliminar->tam, tam ) );

    *p = nodoAEliminar->sig;

    free( nodoAEliminar->dato );
    free( nodoAEliminar );

    return OK;
}

int verTope( const tPila* p, void* dato, unsigned tam )
{
    if( !*p )
    {
        return PILA_VACIA;
    }
    memcpy( dato, (*p)->dato, MENOR( (*p)->tam, tam ) );

    return OK;
}

int pilaVacia( const tPila* p )
{
    return NULL == *p;
}

int pilaLlena( const tPila* p, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if( !nuevoNodo )
    {
        return PILA_LLENA;
    }

    nuevoNodo->dato = malloc( tam );

    if( !nuevoNodo->dato )
    {
        free( nuevoNodo );
        return PILA_LLENA;
    }
    free( nuevoNodo->dato );
    free( nuevoNodo );

    return HAY_LUGAR;
}

void vaciarPila( tPila* p )
{
    tNodo* nodoAEliminar;

    while( *p )
    {
        nodoAEliminar = *p;
        *p = nodoAEliminar->sig;
        free( nodoAEliminar->dato );
        free( nodoAEliminar );
    }
}




