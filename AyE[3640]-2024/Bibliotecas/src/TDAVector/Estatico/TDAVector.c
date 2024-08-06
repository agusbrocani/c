#include "../../../include/TDAVector/Estatico/TDAVector.h"

void crearVector( tVector* v, unsigned tam )
{
    v->tamDisponible = TAM_VECTOR;
    v->tamDato = tam;
}

int vectorVacio( const tVector* v )
{
    return v->tamDisponible == TAM_VECTOR;
}

int vectorLleno( const tVector* v )
{
    return v->tamDato > v->tamDisponible;
}

int verElementoEnPosicionDada( const tVector* v, void* dato, unsigned posicion )
{
    if(         v->tamDisponible == TAM_VECTOR          )
    {
        return VECTOR_VACIO;
    }

    memcpy( dato, v->vec + (posicion * v->tamDato), v->tamDato );

    return OK;
}

int eliminarElementoEnPosicion( tVector* v, void* dato, unsigned posicion, unsigned* ce )
{
    void* ini = v->vec + posicion * v->tamDato;
    void* fin = v->vec + (*ce) * v->tamDato;

    if(         !*ce || !( posicion < *ce )          )
    {
        return NO_PUEDO_ELIMINAR;
    }

    if(         ini < fin           )
    {
        v->tamDisponible += v->tamDato;
        (*ce) --;
    }

    memcpy( dato, v->vec + posicion * v->tamDato, v->tamDato );

    while(          ini < fin           )
    {
        memcpy( ini, ini + v->tamDato, v->tamDato );
        ini += v->tamDato;
    }

    return OK;
}

void destruirVector( tVector* v )
{
    v->tamDato = 0;
    v->tamDisponible = TAM_VECTOR;
}


int insertarOrdenado( tVector* v, const void* dato, unsigned* ce, int (*comparar)( const void* a, const void* b ) )
{
    void* ini = v->vec;
    void* fin = v->vec + (*ce) * v->tamDato;

    if(         v->tamDato > v->tamDisponible           )
    {
        return NO_HAY_LUGAR;
    }

    while(          ini < fin && comparar( fin - v->tamDato, dato ) > 0            )
    {
        memcpy( fin, fin - v->tamDato, v->tamDato );
        fin -= v->tamDato;
    }

    memcpy( fin, dato, v->tamDato );
    v->tamDisponible -= v->tamDato;
    (*ce) ++;

    return OK;
}

