#include "../../../include/TDAVector/Dinamico/TDAVector.h"

void crearVector( tVector* v, unsigned tam )
{
    v->vec = NULL;
    v->tamDato = tam;
    v->tamDisponible = 0;
    v->tamReservado = 0;
}

int vectorVacio( const tVector* v )
{
    return NULL == v->vec || ( v->vec && !( v->tamDisponible - v->tamReservado ) );
}

int vectorLleno( const tVector* v )
{
    return v->tamDisponible < v->tamDato;
}

int verElementoEnPosicionDada( const tVector* v, void* dato, unsigned posicion )
{
    if(         !v->vec         )
    {
        return NO_PUEDO_VER_ELEMENTO;
    }

    memcpy( dato, v->vec + posicion * v->tamDato, v->tamDato );

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
    free( v->vec );
    v->vec = NULL;
    v->tamDato = 0;
    v->tamDisponible = 0;
    v->tamReservado = 0;
}

int insertarOrdenado( tVector* v, const void* dato, unsigned* ce, int (*comparar)( const void* a, const void* b ) )
{
    void* ini;
    void* fin;
    char* amplioVector;

    if(         !v->vec         )   //NO HAY VECTOR
    {
        v->vec = malloc( CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato );

        if(         !v->vec         )
        {
            printf("No habia lugar para crear el vector\n");
            return NO_HAY_LUGAR;
        }

        v->tamDisponible = CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato;
        v->tamReservado = CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato;
    }

    if(         v->tamDisponible < v->tamDato           )   //NO HAY LUGAR SUFICIENTE, REALLOC
    {
        amplioVector = realloc( v->vec, v->tamReservado + CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato );   //Tenia v->tamReservado y le sume 10 elementos mas
        if(         !amplioVector           )
        {
            printf("No habia lugar para ampliar el vector\n");
            return NO_HAY_LUGAR;
        }

        v->vec = amplioVector;
        v->tamDisponible += CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato;
        v->tamReservado += CE_ELEMENTOS_RESERVADOS_POR_DEFECTO * v->tamDato;
    }

    ini = v->vec;
    fin = v->vec + (*ce) * v->tamDato;  //esta asegurado que voy a tener lugar

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
