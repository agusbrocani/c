#include "clase6.h"

void mostrarProducto(const void* dato)
{
    printf("Codigo: %d\nCantidad: %d\nPrecio: %.2f\n\n",
           ((tProducto*)dato)->codigo,
           ((tProducto*)dato)->cantidad,
           ((tProducto*)dato)->precio
          );
}

int comparaProductos(const void* a, const void* b)
{
    return ((tProducto*)a)->codigo - ((tProducto*)b)->codigo;
}

int eliminarPorClaveOrd(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b))
{
    t_nodo* nodoAEliminar;

    if(*pl == NULL)
        return NO_HAY_ELEMENTOS;

    while(*pl && comparar(clave,(*pl)->dato) > 0) // mientras no sea clave, sigo avanzando
    {
        pl = &((*pl)->sig); // queda apuntando a la direccion donde se guarda nodo->sig. *pl va a tener la dirección del próximo nodo
    }

    if(*pl && !comparar(clave, (*pl)->dato)) // Si *pl != NULL y encuentra la clave (!comparar es = a !0 -> verdadero)
    {
        nodoAEliminar = *pl; //

        memcpy(clave, (*pl)->dato, (*pl)->tam); //guardo la dato para devolverla

        *pl = nodoAEliminar->sig; // para no perder al siguiente de mi nodo a eliminar

        // libero el nodo a eliminar
        free(nodoAEliminar->dato);
        free(nodoAEliminar);

        return OK;
    }
    else
    {
        return CLAVE_INEXISTENTE;
    }
}

// lista simple con claves duplicadas, pero elimino todas las ocurrencias pero hago una acción...
// por ejemplo: devuelvo el que tiene el precio más barato :)

//void aplicarDescuentoDe20(void* dato)
//{
//    tProducto* prod = (tProducto*)dato;
//    prod->precio *= 0.8;
//}

void sumarStock(void* dato, void* clave)
{
    tProducto* prod = (tProducto*)dato;
    ((tProducto*)clave)->cantidad += prod->cantidad;
    ((tProducto*)clave)->codigo = prod->codigo;
    ((tProducto*)clave)->precio = prod->precio;
}

void sumarStockV2(void* aAcumular, const void* dato)
{
    ((tProducto*)aAcumular)->cantidad += ((tProducto*)dato)->cantidad;
    ((tProducto*)aAcumular)->codigo = ((tProducto*)dato)->codigo;
    ((tProducto*)aAcumular)->precio = ((tProducto*)dato)->precio;
}

void eliminarPorClaveDupConAccion(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b), void (*accion)(void* aAcumular, void* clave))
{
    t_nodo* nodoAEliminar;

    while(*pl && comparar(clave,(*pl)->dato) > 0) // mientras no sea clave, sigo avanzando
    {
        pl = &((*pl)->sig); // queda apuntando a la direccion donde se guarda nodo->sig. *pl va a tener la dirección del próximo nodo
    }

    while(*pl && !comparar(clave, (*pl)->dato)) // Si *pl != NULL y encuentra la clave (!comparar es = a !0 -> verdadero)
    {
        nodoAEliminar = *pl;

        /// la acción es la que guarda el dato, ya no necesito el memcpy
        accion(nodoAEliminar->dato, clave);
        //memcpy(clave, (*pl)->dato, (*pl)->tam); //guardo la dato para devolverla
        *pl = nodoAEliminar->sig; // para no perder al siguiente de mi nodo a eliminar

        // libero el nodo a eliminar
        free(nodoAEliminar->dato);
        free(nodoAEliminar);

    }
}

int eliminarPorClaveDesord(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b))
{
    t_nodo* nodoAEliminar;

    if(*pl == NULL)
        return NO_HAY_ELEMENTOS;

    /// cambia solo la comparación
    while(*pl && comparar(clave,(*pl)->dato) != 0) // mientras no sea clave, sigo avanzando
    {
        pl = &((*pl)->sig); // queda apuntando a la direccion donde se guarda nodo->sig. *pl va a tener la dirección del próximo nodo
    }

    if(*pl && !comparar(clave, (*pl)->dato)) // Si *pl != NULL y encuentra la clave (!comparar es = a !0 -> verdadero)
    {
        nodoAEliminar = *pl; //

        memcpy(clave, (*pl)->dato, (*pl)->tam); //guardo la dato para devolverla

        *pl = nodoAEliminar->sig; // para no perder al siguiente de mi nodo a eliminar

        // libero el nodo a eliminar
        free(nodoAEliminar->dato);
        free(nodoAEliminar);

        return OK;
    }
    else
    {
        return CLAVE_INEXISTENTE;
    }
}

void eliminarAparicionesDeClave(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* clave))
{
    t_nodo* nodoAEliminar;
    while(*pl)
    {
        while(*pl && comparar(clave,(*pl)->dato) != 0) // mientras no sea clave, sigo avanzando
        {
            pl = &((*pl)->sig); // queda apuntando a la direccion donde se guarda nodo->sig. *pl va a tener la dirección del próximo nodo
        }

        while(*pl && !comparar(clave, (*pl)->dato)) // Si *pl != NULL y encuentra la clave (!comparar es = a !0 -> verdadero)
        {
            nodoAEliminar = *pl;

            /// la acción es la que guarda el dato, ya no necesito el memcpy
            accion(nodoAEliminar->dato, clave);
            //memcpy(clave, (*pl)->dato, (*pl)->tam); //guardo la dato para devolverla
            *pl = nodoAEliminar->sig; // para no perder al siguiente de mi nodo a eliminar

            // libero el nodo a eliminar
            free(nodoAEliminar->dato);
            free(nodoAEliminar);

        }
    }
}

void eliminarAparicionesEnListaOrdenadaConDuplicados(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo* siguiente;
    t_nodo* nodoAEliminar;

    while(*pl)
    {
        nodoAEliminar = NULL;
        siguiente = (*pl)->sig;

        while(siguiente && !comparar((*pl)->dato, siguiente->dato))
        {
            nodoAEliminar = siguiente;

            (*pl)->sig = siguiente->sig;
            siguiente = siguiente->sig;

            free(nodoAEliminar->dato);
            free(nodoAEliminar);
            nodoAEliminar = (*pl);
        }
        (*pl) = (*pl)->sig;
        if(NULL != nodoAEliminar)
        {
            *pl = nodoAEliminar->sig;
            free(nodoAEliminar->dato);
            free(nodoAEliminar);
        }
        else
        {
            pl = &((*pl)->sig);
        }
    }
}

void eliminarAparicionesEnListaDesordenadaConDuplicados(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo* siguiente;
    t_nodo* nodoAEliminar;
    t_nodo** antSiguiente;

    while(*pl)
    {
        nodoAEliminar = NULL;
        siguiente = (*pl)->sig;
        antSiguiente = &((*pl)->sig);

        while(siguiente)
        {
            if(!comparar((*pl)->dato, siguiente->dato))
            {
                nodoAEliminar = siguiente;
                *antSiguiente = siguiente->sig;
                siguiente = siguiente->sig;

                free(nodoAEliminar->dato);
                free(nodoAEliminar);
                nodoAEliminar = *pl;
            }
            else
            {
                antSiguiente = &(siguiente->sig);
                siguiente = siguiente->sig;
            }
        }

        if(NULL != nodoAEliminar)
        {
            nodoAEliminar = *pl;
            *pl = (*pl)->sig;
            free(nodoAEliminar->dato);
            free(nodoAEliminar);
        }
        else
        {
            pl = &((*pl)->sig);
        }
    }
}

void eliminarRegistrosSinDuplicarAcumulandoRegistrosDuplicados(t_lista* pl,
                                                               int (*comparar)(const void* a, const void* b),
                                                               void (*accion)(void* aAcumular, const void* dato)
                                                               )
{
    t_nodo* siguiente;
    t_nodo* nodoAEliminar;
    t_nodo** antSiguiente;
    int esDuplicado;

    while(*pl)
    {
        nodoAEliminar = NULL;
        siguiente = (*pl)->sig;
        antSiguiente = &((*pl)->sig);
        esDuplicado = 0;

        while(siguiente)
        {
            if(!comparar((*pl)->dato, siguiente->dato))
            {
                accion((*pl)->dato, siguiente->dato);

                nodoAEliminar = siguiente;
                *antSiguiente = siguiente->sig;
                siguiente = siguiente->sig;

                free(nodoAEliminar->dato);
                free(nodoAEliminar);
                esDuplicado = 1;
            }
            else
            {
                antSiguiente = &(siguiente->sig);
                siguiente = siguiente->sig;
            }
        }

        if(!esDuplicado)
        {
            nodoAEliminar = *pl;
            *pl = (*pl)->sig;
            free(nodoAEliminar->dato);
            free(nodoAEliminar);
        }
        else
        {
            pl = &((*pl)->sig);
        }
    }
}





