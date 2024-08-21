#include "../../include/Estatica/pila.h"

void crearPila( tPila* p )
{
    p->tamDisponible = TAM_PILA;
}
//primero pone el dato
int apilar( tPila* p, const void* dato, unsigned tam )
{
    if( p->tamDisponible < tam + sizeof( unsigned ) )
    {
        return NO_HAY_LUGAR;
    }
    p->tamDisponible -= tam;
    memcpy( p->pila + p->tamDisponible, dato, tam );

    p->tamDisponible -= sizeof( unsigned );
    memcpy( p->pila + p->tamDisponible, &tam, sizeof( unsigned ) );

    return OK;
}
int desapilar( tPila* p, void* dato, unsigned tam )
{
    unsigned tamDesapilado;

    if( TAM_PILA == p->tamDisponible )
    {
        return PILA_VACIA;
    }

    memcpy( &tamDesapilado, p->pila + p->tamDisponible, sizeof(unsigned) );
    p->tamDisponible += sizeof( unsigned );

    memcpy( dato, p->pila + p->tamDisponible, MENOR( tamDesapilado, tam ) );
    p->tamDisponible += tamDesapilado;

    return OK;
}
int verTope( const tPila* p, void* dato, unsigned tam )
{
    unsigned tope = p->tamDisponible;
    unsigned tamDesapilado;

    if( TAM_PILA == p->tamDisponible )
    {
        return PILA_VACIA;
    }

    memcpy( &tamDesapilado, p->pila + tope, sizeof(unsigned) );
    tope += sizeof( unsigned );

    memcpy( dato, p->pila + tope, MENOR( tamDesapilado, tam ) );

    return OK;
}
int pilaVacia( const tPila* p )
{
    return TAM_PILA == p->tamDisponible;
}
int pilaLlena( const tPila* p, unsigned tam )
{
    return p->tamDisponible < tam + sizeof( unsigned );
}
void vaciarPila( tPila* p )
{
    p->tamDisponible = TAM_PILA;
}
