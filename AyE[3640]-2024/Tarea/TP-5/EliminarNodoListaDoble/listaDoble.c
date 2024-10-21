#include "listaDoble.h"

void crearLista (t_listaDoble *pl)
{
    *pl = NULL;
}

int insertarEnListaDoble (t_listaDoble *pl, void *dato, unsigned tamBytes, int cmp (void*, void*))
{
    t_nodoDoble *actual = *pl, *aAnt, *aSig;
    t_nodoDoble *nuevoNodo;

    if (!*pl)
    {
        aAnt = NULL;
        aSig = NULL;
    }
    else
    {
        while ((actual->ant != NULL) && (cmp (actual->dato, dato) > 0))
            actual = actual->ant;
        while ((actual->sig != NULL) && (cmp (actual->dato, dato) < 0))
            actual = actual->sig;
        if (cmp (actual->dato, dato) > 0)
        {
            aAnt = actual->ant;
            aSig = actual;
        }
        else if (cmp (actual->dato, dato) < 0)
            {
                aAnt = actual;
                aSig = actual->sig;
            }
            else
            {
                //duplicado
                return DUPLICADO;
            }
    }
    nuevoNodo = (t_nodoDoble*) malloc (sizeof (t_nodoDoble));
    if (!nuevoNodo)
        return SIN_MEMORIA;
    nuevoNodo->dato = malloc (tamBytes);
    if (!nuevoNodo->dato)
    {
        free (nuevoNodo);
        return SIN_MEMORIA;
    }
    memcpy (nuevoNodo->dato, dato, tamBytes);
    nuevoNodo->tam = tamBytes;
    nuevoNodo->sig = aSig;
    nuevoNodo->ant = aAnt;
    if (aAnt != NULL)
        aAnt->sig = nuevoNodo;
    if (aSig != NULL)
        aSig->ant = nuevoNodo;
    *pl = nuevoNodo;

    return OK;
}

int eliminarEnListaDobleSinDuplicados (t_listaDoble *pl, void *key, void *dato, unsigned tamBytes, int cmp (void*, void*))
{
    t_nodoDoble *actual, *aAnt, *aSig;

    if (!*pl)
        return LISTA_VACIA;
    actual = *pl;
    while ((actual->ant != NULL) && (cmp (actual->dato, key) > 0))
        actual = actual->ant;
    while ((actual->sig != NULL) && (cmp (actual->dato, key) < 0))
        actual = actual->sig;
    if (cmp (actual->dato, key) != 0)
        return NO_SE_ENCONTRO;
    memcpy (dato, actual->dato, MINIMO (tamBytes, actual->tam));
    aAnt = actual->ant;
    aSig = actual->sig;
    if (aAnt != NULL)
        aAnt->sig = aSig;
    if (aSig != NULL)
        aSig->ant = aAnt;
    free (actual->dato);
    free (actual);
    if (aAnt == NULL)
        *pl = aSig;
    else
        *pl = aAnt;
    return OK;
}

void vaciarListaDoble (t_listaDoble *pl)
{
    t_nodoDoble *actual, *nodoElim;

    if (!*pl)
        return;
    actual = *pl;
    while (actual->ant != NULL)
        actual = actual->ant;
    while (actual != NULL)
    {
        nodoElim = actual;
        actual = actual->sig;
        free (nodoElim->dato);
        free (nodoElim);
    }
    *pl = NULL;
}

int recorrerListaDobleMenorAMayor (t_listaDoble *pl, void accion (void*))
{
    t_nodoDoble *actual;

    if (!*pl)
        return LISTA_VACIA;
    actual = *pl;
    while (actual->ant != NULL)
        actual = actual->ant;
    while (actual != NULL)
    {
        accion (actual->dato);
        actual = actual->sig;
    }

    return OK;
}

