#include "funciones.h"

void crearArbol(t_arbol* a)
{
    *a = NULL;
}

void recorrerEnPreOrden(const t_arbol* a, void (*accion)(void* dato))
{
    if(!*a)
    {
        return;
    }

    accion((*a)->dato);
    recorrerEnPreOrden(&((*a)->izq), accion);
    recorrerEnPreOrden(&((*a)->der), accion);
}

void recorrerEnOrden(const t_arbol* a, void (*accion)(void* dato))
{
    if(!*a)
    {
        return;
    }

    recorrerEnOrden(&((*a)->izq), accion);
    accion((*a)->dato);
    recorrerEnOrden(&((*a)->der), accion);
}

void recorrerEnPosOrden(const t_arbol* a, void (*accion)(void* dato))
{
    if(!*a)
    {
        return;
    }

    recorrerEnPosOrden(&((*a)->izq), accion);
    recorrerEnPosOrden(&((*a)->der), accion);
    accion((*a)->dato);
}

int insertarEnArbol(t_arbol* a, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*acumular)(void* datoArbol, const void* dato))
{
    t_nodo* nuevoNodo;
    int cmp;

    if(!*a)
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
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        *a = nuevoNodo;
        return OK;
    }

    cmp = comparar(dato, (*a)->dato);
    if(cmp < 0)
    {
        return insertarEnArbol(&((*a)->izq), dato, tam, comparar, acumular);
    }
    else if(cmp > 0)
    {
        return insertarEnArbol(&((*a)->der), dato, tam, comparar, acumular);
    }
    acumular((*a)->dato, dato);
    return DATO_DUPLICADO;
}

int insertarEnArbolIterativo(t_arbol* a, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*acumular)(void* datoArbol, const void* dato))
{
        t_nodo* nuevoNodo;

        while(*a)
        {
                if(comparar(dato, (*a)->dato) < 0)
                {
                       a = &((*a)->izq);
                }else if(comparar(dato, (*a)->dato) > 0)
                        {
                                a = &((*a)->der);
                        }
                        else
                        {
                                acumular((*a)->dato, dato);
                                return DATO_DUPLICADO;
                        }
        }

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
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        *a = nuevoNodo;

        return OK;
}


int contarNodos(const t_arbol* a)
{
        if(!*a)
        {
                return 0;
        }

        return 1 + contarNodos(&((*a)->izq)) + contarNodos(&((*a)->der))  ;
}

int contarHojas(const t_arbol* a)
{
        if(!*a)
        {
                return 0;
        }

        if(!((*a)->izq) && !((*a)->der))
        {
                return 1;
        }

        return contarHojas(&((*a)->izq)) + contarHojas(&((*a)->der));
}


//vaciarArbol
//podar todas las hojas


int podarHojas(t_arbol* a)
{
    if(!*a)
    {
        return 0;
    }

    if(!(*a)->izq && !(*a)->der)
    {
        free((*a)->dato);
        free(*a);
        *a = NULL;
        return 1;
    }
    else
    {
        return podarHojas(&((*a)->izq)) + podarHojas(&((*a)->der));
    }
}

void vaciarArbol(t_arbol* a)
{
    if(!*a)
    {
        return;
    }

    vaciarArbol(&((*a)->izq));
    vaciarArbol(&((*a)->der));
    free((*a)->dato);
    free(*a);
    *a = NULL;
}



