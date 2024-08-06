#include "../../include/cola/Dinamica/cola.h"

void crearCola( tCola* c )
{
    c->pri = NULL;
    c->ult = NULL;
}

int acolar( tCola* c, const void* dato, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof(tNodo) );

    if(         !nuevoNodo          )
    {
        return NO_PUDE_ACOLAR;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato            )
    {
        free( nuevoNodo );
        return NO_PUDE_ACOLAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->tam = tam;

    if(         !c->pri          )
    {
        c->pri = nuevoNodo;
    }
    else
    {
        c->ult->sig = nuevoNodo;
    }

    c->ult = nuevoNodo;
    nuevoNodo->sig = NULL;

    return OK;
}

//debo asignar valor a ult si nunca lo uso?, solamente se usa para enganchar en acolar

int desacolar( tCola* c, void* dato, unsigned tam )
{
    tNodo* nodoAEliminar = c->pri;

    if(         !nodoAEliminar          )
    {
        return COLA_VACIA;
    }

    c->pri = nodoAEliminar->sig;

    memcpy( dato, nodoAEliminar->dato, MENOR( nodoAEliminar->tam, tam ) );
    free( nodoAEliminar->dato );
    free( nodoAEliminar );

    return OK;
}

int colaLlena( const tCola* c, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if(         !nuevoNodo          )
    {
        return COLA_LLENA;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato            )
    {
        free( nuevoNodo );
        return COLA_LLENA;
    }

    return HAY_LUGAR;
}

int colaVacia( const tCola* c )
{
    return NULL == c->pri;
}

int verPrimero( const tCola* c, void* dato, unsigned tam )
{
    if(         !c->pri         )
    {
        return COLA_VACIA;
    }

    memcpy( dato, c->pri->dato, MENOR( c->pri->tam, tam ) );

    return OK;
}

void vaciarCola( tCola* c )
{
    tNodo* nodoAEliminar;

    while(          c->pri          )
    {
        nodoAEliminar = c->pri;
        c->pri = nodoAEliminar->sig;
        free( nodoAEliminar->dato );
        free( nodoAEliminar );
    }
}
