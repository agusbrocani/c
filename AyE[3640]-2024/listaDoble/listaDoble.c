#include "listaDoble.h"

void crearListaDoble(t_listaDoble* pl)
{
    *pl = NULL;
}

//int insertarOrdenadoConAccionEnRepetidosEnListaDoble(t_listaDoble* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* datoNodo, const void* dato))
//{
//    t_nodo* nuevoNodo;
//    t_nodo* siguiente;
//    t_nodo* anterior;
//    t_nodo* actual = *pl;
//    int comparar;
//
//    if(NULL == actual)
//    {
//        siguiente = NULL;
//        anterior = NULL;
//    }
//    else
//    {
//        while(actual->sig && comparar(dato, actual->dato) > 0)
//        {
//            actual = actual->sig;
//        }
//        while(actual->ant && comparar(dato, actual->dato) < 0)
//        {
//            actual = actual->ant;
//        }
//        anterior = actual->ant;
//        siguiente = actual->sig;
//
//        if(0 == (comparar = comparar(dato, actual->dato)))
//        {
//            accion(actual->dato, dato);
//            return OK;
//        }
//    }
//
//    nuevoNodo = malloc(sizeof(t_nodo));
//    if(NULL == nuevoNodo)
//    {
//        fprintf(stderr, "No pude reservar memoria para el nodo.\n");
//        return NO_PUDE_RESERVAR_MEMORIA;
//    }
//    nuevoNodo->dato = malloc(tam);
//    if(NULL == nuevoNodo->dato)
//    {
//        fprintf(stderr, "No pude reservar memoria para el dato.\n");
//        free(nuevoNodo);
//        return NO_PUDE_RESERVAR_MEMORIA;
//    }
//
//    if(actual && comparar > 0)
//    {
//        nuevoNodo->ant = actual;
//        nuevoNodo->sig = siguiente;
//        siguiente = nuevoNodo;
//    }
//
//    if(actual && comparar < 0)
//    {
//        nuevoNodo->ant = anterior;
//        nuevoNodo->sig = actual;
//        anterior = nuevoNodo;
//    }
//
//    if(siguiente)
//    {
//        siguiente->ant = nuevoNodo;
//    }
//    if(anterior)
//    {
//        anterior->sig = nuevoNodo;
//    }
//
//
//    memcpy(nuevoNodo->dato, dato, tam);
//    nuevoNodo->tam = tam;
//
//    *pl = nuevoNodo;
//
//    return OK;
//}

int insertarOrdenadoConAccionEnRepetidosEnListaDoble(t_listaDoble* p, const void* dato, unsigned cantBytes, int (*comparar)(const void* a, const void* b), void (*accion)(void* datoNodo, const void* dato))
{
    t_nodo *act = *p, *aSig = NULL, *aAnt = NULL, *nue;

    if(!act)
    {
        aAnt = NULL;
        aSig = NULL;
    }
    else // si la lista no está vacía, la recorro
    {
        while(act->ant && comparar(act->dato, dato)>0)//mientras haya un nodo anterior y el elemento a insertar sea menor
        {
            act = act->ant; //avanzo
        }

        while(act->sig && comparar(act->dato, dato)<0)//mientras no sea fin de la lista y el elemento a insertar sea mayor
        {
            act = act->sig; //avanzo
        }

        if(comparar(act->dato, dato)==0)
        {
            accion(act->dato,dato);
            return -1;
        }
        if(comparar(act->dato, dato)>0)
        {
            aAnt = act->ant;
            aSig = act;
        }
        if(comparar(act->dato, dato)<0)
        {
            aAnt = act;
            aSig = act->sig;
        }
    }

    ///una vez que encuentro la posición, reservo memoria y completo mi nodo:
    nue = malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->dato = malloc(cantBytes);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;
    nue->sig = aSig;
    nue->ant = aAnt;

    ///hago el enchanche
    if(aSig) // si es null no hace falta
    {
        aSig->ant = nue;
    }
    if(aAnt)
    {
        aAnt->sig = nue;
    }

    *p = nue; // main apuntando al nuevo nodo
    return OK;
}

void vaciarListaDoble(t_listaDoble* pl)
{
//    t_nodo* nodoAEliminar;
//    t_nodo* actual = *pl;

}

void mostrarListaDobleIzqDer(const t_listaDoble* pl, void (*mostrar)(const void* dato))
{
    t_nodo* actual = *pl;

    if(actual)
    {
        while(actual->ant)
        {
            actual = actual->ant;
        }

        while(actual)
        {
            mostrar(actual->dato);
            printf("\n");
            actual = actual->sig;
        }
    }
}

void mostrarListaDobleDerIzq(const t_listaDoble* pl, void (*mostrar)(const void* dato))
{
    t_nodo* actual = *pl;

    if(actual)
    {
        while(actual->sig)
        {
            actual = actual->sig;
        }

        while(actual)
        {
            mostrar(actual->dato);
            printf("\n");
            actual = actual->ant;
        }
    }
}

int eliminarDeListaDoble(t_listaDoble *p, unsigned cantBytes, const void *dato, int (*cmp)(const void*, const void*))
{
    t_nodo *act = *p, *aSig = NULL, *aAnt = NULL, *elim;

    if(!act)
    {
        return 0;
    }

    ///caso para un único nodo
    if(!act->ant && !act->sig && !cmp(act->dato, dato))
    {
        elim=act;
        memcpy(elim->dato,dato,cantBytes);
        free(elim->dato);
        free(elim);
        *p = NULL;
        return OK;
    }

    if(act) // si la lista no está vacía, la recorro
    {
        while(act->ant && cmp(act->dato, dato)>0)//mientras haya un nodo anterior y el elemento a insertar sea menor
        {
            act = act->ant; //avanzo
        }

        while(act->sig && cmp(act->dato, dato)<0)//mientras no sea fin de la lista y el elemento a insertar sea mayor
        {
            act = act->sig; //avanzo
        }
        if(cmp(act->dato, dato)>0)
        {
            return 0;
        }
        if(cmp(act->dato, dato)<0)
        {
            return 0;
        }

        ///encontré el nodo a eliminar
        if(cmp(act->dato, dato)==0)
        {
            aSig = act->sig;
            aAnt = act->ant;

            elim = act;

            ///hago el enchanche con los nodos vecinos
            if(aSig) // si es null no hace falta
            {
                aSig->ant = elim->ant;
            }
            if(aAnt)
            {
                aAnt->sig = elim->sig;
            }

            memcpy(elim->dato,dato,cantBytes);
            free(elim->dato);
            free(elim);

            if(aSig)
            {
                *p = aSig;
            }
            else if (aAnt)
            {
                *p = aAnt;
            }
        }
    }

    return OK;
}
