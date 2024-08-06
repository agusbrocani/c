#include "../../include/pila/Estatica/pila.h"

void crearPila( tPila* p )
{
    p->tamDisponible = TAM_PILA;
}
int apilar( tPila* p, const void* dato, unsigned tam )
{
    unsigned offset = TAM_PILA - p->tamDisponible;//tam ocupado
    unsigned tamAInsertar = tam + sizeof( unsigned );

    if(         p->tamDisponible < tamAInsertar          )
    {
        return NO_HAY_LUGAR;
    }

    memcpy( (p->pila)+ offset, dato, tam );
    memcpy( (p->pila)+ offset + tam, &tam, sizeof( unsigned ) );

    (p->tamDisponible) -= tamAInsertar;

    return OK;
}

int desapilar( tPila* p, void* dato, unsigned tam )
{
    unsigned offset = TAM_PILA - p->tamDisponible;
    unsigned tamADesapilar;

    if(         TAM_PILA == p->tamDisponible            )
    {
        return PILA_VACIA;
    }

    memcpy( &tamADesapilar, (p->pila) + offset - sizeof(unsigned), sizeof(unsigned) );

    memcpy( dato, p->pila + offset - tamADesapilar - sizeof(unsigned), MINIMO( tam, tamADesapilar ) );

    p->tamDisponible += tamADesapilar + sizeof(unsigned);

    return OK;
}
void vaciarPila( tPila* p )
{
    p->tamDisponible = TAM_PILA;
}
int pilaVacia( const tPila* p )
{
    return TAM_PILA == p->tamDisponible;
}
int pilaLlena( const tPila* p, unsigned tam )
{
    unsigned tamAInsertar = tam + sizeof( unsigned );

    if(         p->tamDisponible < tamAInsertar          )
    {
        return PILA_LLENA;
    }

    return HAY_LUGAR;
}

int verTope( const tPila* p, void* dato, unsigned tam )
{
    unsigned offset = TAM_PILA - p->tamDisponible;  //lo que esta ocupado
    unsigned tamDato;

    if(         TAM_PILA == p->tamDisponible            )
    {
        return PILA_VACIA;
    }

    memcpy( &tamDato, ( p->pila ) + offset - sizeof( unsigned ), sizeof( unsigned ) );
    memcpy( dato, p->pila + offset - tamDato - sizeof(unsigned), MINIMO( tamDato, tam ) );

    return OK;
}

