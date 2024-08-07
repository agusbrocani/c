#include "../../include/listaSimplementeEnlazada/listaSimplementeEnlazada.h"

void crearLista( tLista* pl )
{
    *pl = NULL;
}

int insertarAlFinal( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if(         !nuevoNodo          )
    {
        return NO_PUEDO_INSERTAR;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato           )
    {
        free( nuevoNodo );
        return NO_PUEDO_INSERTAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->tam = tam;

    while(          *pl         )
    {
        pl = &( (*pl)->sig );
    }
    nuevoNodo->sig = *pl;
    *pl = nuevoNodo;

    return OK;
}

int insertarAlInicio( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if(         !nuevoNodo          )
    {
        return NO_PUEDO_INSERTAR;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato         )
    {
        free( nuevoNodo );
        return NO_PUEDO_INSERTAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *pl;
    *pl = nuevoNodo;

    return OK;
}

void mostrarLista( const tLista* pl, void ( *mostrar )( const void* dato ) )
{
    while(          *pl         )
    {
        mostrar( (*pl)->dato );
        pl = &( (*pl)->sig );
    }
}

void vaciarLista( tLista* pl )
{
    tNodo* nodoAEliminar;

    while(          *pl         )
    {
        nodoAEliminar = *pl;
        *pl = nodoAEliminar->sig;
        free( nodoAEliminar->dato );
        free( nodoAEliminar );
    }
}

int verPrimero( const tLista* pl, void* dato, unsigned tam )
{
    if(         !*pl         )
    {
        return NO_HAY_ELEMENTOS;
    }

    memcpy( dato, (*pl)->dato, MENOR( (*pl)->tam, tam ) );

    return OK;
}
int verUltimo( tLista* pl, void* dato, unsigned tam )
{
    if(         !*pl         )
    {
        return NO_HAY_ELEMENTOS;
    }

    while(          (*pl)->sig            )
    {
        pl = &( (*pl)->sig );
    }

    memcpy( dato, (*pl)->dato, MENOR( (*pl)->tam, tam ) );

    return OK;
}

int insertarColeccionEnListaAlInicio( tLista* pl, const void* coleccion, unsigned tam, unsigned ce )
{
    tNodo* nuevoNodo;
    int i;

    for( i = 0; i < ce; i++ )
    {
        nuevoNodo = malloc( sizeof( tNodo ) );

        if(         !nuevoNodo           )
        {
            return NO_PUEDO_INSERTAR;
        }

        nuevoNodo->dato = malloc( tam );

        if(         !nuevoNodo->dato            )
        {
            free( nuevoNodo );
            return NO_PUEDO_INSERTAR;
        }

        memcpy( nuevoNodo->dato, coleccion, tam );
        nuevoNodo->tam = tam;
        nuevoNodo->sig = *pl;
        *pl = nuevoNodo;

        coleccion += tam;
    }

    return OK;
}

int insertarColeccionEnListaAlFinal( tLista* pl, const void* coleccion, unsigned tam, unsigned ce )
{
    tNodo* nuevoNodo;
    int i;

    for( i = 0; i < ce; i++ )
    {
        nuevoNodo = malloc( sizeof( tNodo ) );

        if(         !nuevoNodo           )
        {
            return NO_PUEDO_INSERTAR;
        }

        nuevoNodo->dato = malloc( tam );

        if(         !nuevoNodo->dato            )
        {
            free( nuevoNodo );
            return NO_PUEDO_INSERTAR;
        }

        memcpy( nuevoNodo->dato, coleccion, tam );
        nuevoNodo->tam = tam;

        while(          *pl         )
        {
            pl = &( (*pl)->sig );
        }

        nuevoNodo->sig = *pl;
        *pl = nuevoNodo;

        coleccion += tam;
    }

    return OK;
}

int insertarOrdenadoSinDuplicados( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) )
{
    tNodo* nuevoNodo;

    while(          *pl && comparar( (*pl)->dato, dato ) < 0         )
    {
        pl = &( (*pl)->sig );
    }

    if(         !*pl || comparar( (*pl)->dato, dato ) >  0          )
    {
        nuevoNodo = malloc( sizeof( tNodo ) );

        if(         !nuevoNodo          )
        {
            return NO_PUEDO_INSERTAR;
        }

        nuevoNodo->dato = malloc( tam );

        if(         !nuevoNodo->dato         )
        {
            free( nuevoNodo );
            return NO_PUEDO_INSERTAR;
        }

        memcpy( nuevoNodo->dato, dato, tam );
        nuevoNodo->tam = tam;
        nuevoNodo->sig = *pl;

        *pl = nuevoNodo;
    }

    return OK;
}

int insertarOrdenadoAcumuladoDuplicados( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ), void ( *acumular )( void* dato, const void* aAcumular) )
{
    tNodo* nuevoNodo;

    while(          *pl && comparar( (*pl)->dato, dato ) > 0         )
    {
        pl = &( (*pl)->sig );
    }

    if(         !*pl || comparar( (*pl)->dato, dato ) <  0          )
    {
        nuevoNodo = malloc( sizeof( tNodo ) );

        if(         !nuevoNodo          )
        {
            return NO_PUEDO_INSERTAR;
        }

        nuevoNodo->dato = malloc( tam );

        if(         !nuevoNodo->dato         )
        {
            free( nuevoNodo );
            return NO_PUEDO_INSERTAR;
        }

        memcpy( nuevoNodo->dato, dato, tam );
        nuevoNodo->tam = tam;
        nuevoNodo->sig = *pl;

        *pl = nuevoNodo;
    }
    else
    {
        acumular( (*pl)->dato, dato );
    }

    return OK;
}

int insertarOrdenado( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) )
{
    tNodo* nuevoNodo;

    while(          *pl && comparar( (*pl)->dato, dato ) < 0         )
    {
        pl = &( (*pl)->sig );
    }

    nuevoNodo = malloc( sizeof( tProducto ) );

    if(         !nuevoNodo           )
    {
        return NO_PUEDO_INSERTAR;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato            )
    {
        free( nuevoNodo );
        return NO_PUEDO_INSERTAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *pl;
    *pl = nuevoNodo;

    return OK;
}

int insertarEnPosicion( tLista* pl, const void* dato, unsigned tam, unsigned posicion )
{
    tNodo* nuevoNodo;
    int posicionRecorrida = 0;

    while(          *pl && posicionRecorrida < posicion         )
    {
        posicionRecorrida++;
        pl = &( (*pl)->sig );
    }

    if(         posicion > posicionRecorrida            )
    {
        return NO_PUEDO_INSERTAR;
    }

    nuevoNodo = malloc( sizeof( tNodo ) );

    if(         !nuevoNodo           )
    {
        return NO_PUEDO_INSERTAR;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato           )
    {
        free( nuevoNodo );
        return NO_PUEDO_INSERTAR;
    }

    memcpy( nuevoNodo->dato, dato, tam );
    nuevoNodo->sig = *pl;
    nuevoNodo->tam = tam;
    *pl = nuevoNodo;

    return OK;
}

int listaLlena( const tLista* pl, unsigned tam )
{
    tNodo* nuevoNodo;

    nuevoNodo = malloc( sizeof( tNodo ) );

    if(         !nuevoNodo          )
    {
        return LISTA_LLENA;
    }

    nuevoNodo->dato = malloc( tam );

    if(         !nuevoNodo->dato            )
    {
        free( nuevoNodo );
        return LISTA_LLENA;
    }

    free( nuevoNodo->dato );
    free( nuevoNodo );
    return HAY_LUGAR;
}

int listaVacia( const tLista* pl )
{
    return NULL == *pl;
}

int sacarPrimero( tLista* pl, void* dato, unsigned tam )
{
    tNodo* nodoAEliminar = *pl;

    if(         !nodoAEliminar          )
    {
        return NO_HAY_ELEMENTOS;
    }

    memcpy( dato, nodoAEliminar->dato, MENOR( nodoAEliminar->tam, tam ) );

    *pl = nodoAEliminar->sig;

    free( nodoAEliminar->dato );
    free( nodoAEliminar );

    return OK;
}

int sacarUltimo( tLista* pl, void* dato, unsigned tam )
{
    tNodo* nodoAEliminar;

    if(         !*pl          )
    {
        return NO_HAY_ELEMENTOS;
    }

    while(          (*pl)->sig         )
    {
        pl = &((*pl)->sig);
    }

    nodoAEliminar = *pl;
    memcpy( dato, nodoAEliminar->dato, MENOR( nodoAEliminar->tam, tam ) );

    *pl = nodoAEliminar->sig;

    free( nodoAEliminar->dato );
    free( nodoAEliminar );

    return OK;
}
