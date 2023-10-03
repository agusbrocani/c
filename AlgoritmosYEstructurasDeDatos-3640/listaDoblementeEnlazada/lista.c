#include"lista.h"

void crearLista(tListad *pl)
{
    *pl =NULL;
}

int insertar(tListad* pl, const void* d, unsigned tam)
{
    tNodod* ant= NULL;
    tNodod* sig = NULL;

    tNodod* nue = (tNodod*)malloc(sizeof(tNodod));
    if(!nue)
    {
        return 0;
    }

    nue->d = malloc(tam);

    if(!(nue->d))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->d,d,tam);
    nue->tam = tam;

    if(*pl != NULL)
    {
        sig = *pl; /// sig = (*pl)->sig
        ant = (*pl)->ant; ///ant = *pl
    }

    nue->sig = sig;
    nue->ant = ant;

    if(sig)
    {
        sig->ant = nue;
    }
    if(ant)
    {
        ant->sig = nue;
    }
    *pl = nue;
    return 1;

}

void mostrarIzqDer(const tListad* pl, void (*mostrar)(const void* d))
{
    if(*pl)
    {
        while((*pl)->ant)
        {
            pl = &((*pl)->ant);
        }
    }

    while(*pl)
    {
        mostrar((*pl)->d);
        pl = &((*pl)->sig);
    }
}

void mostrarDerIzq(const tListad* pl, void (*mostrar)(const void* d))
{
    if(*pl)
    {
        while((*pl)->sig)
        {
            pl = &((*pl)->sig);
        }
    }
    while(*pl)
    {
        mostrar((*pl)->d);
        pl = &((*pl)->ant);
    }
}
int insertarEnOrden(tListad* pl, const void* d, unsigned tam, int (*comparacion)(const void* a, const void* b))
{
    tNodod *ant=NULL, *sig=NULL, *actual = *pl;
    tNodod* nue = (tNodod*)malloc(sizeof(tNodod));
    if(!nue)
    {
        return 0;
    }
    nue->d = malloc(tam);

    if(!(nue->d))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->d,d,tam);
    nue->tam = tam;

    if(actual)
    {
        while(actual->sig && comparacion(actual->d,d)<0)
        {
            actual = actual->sig;
        }

        while(actual->ant && comparacion(actual->d,d)>0)
        {
            actual = actual->ant;
        }

        if(comparacion(actual->d,d)>0)
        {
            sig= actual;
            ant = actual->ant;
        }
        else // menor o igual a cero
        {
            sig = actual->sig;
            ant = actual;
        }

    }
    nue->sig = sig;
    nue->ant = ant;

    if(sig)
    {
        sig->ant = nue;
    }

    if(ant)
    {
        ant->sig = nue;
    }

    *pl = nue;
    return 1;
}

int eliminarElemento(tListad* pl, void* d, unsigned tam)
{
    tNodod *elim =*pl,*ant,*sig;
    if(!elim)
    {
        return 0;
    }
    elim = *pl;
    sig = (*pl)->sig;
    ant = (*pl)->ant;

    if(sig)
    {
        sig->ant = ant;
    }
    if(ant)
    {
        ant->sig = sig;
    }


    memcpy(d,elim->d,minimo(elim->tam,tam));
    free(elim->d);
    free(elim);

    if(sig)
    {
        *pl = sig;
    }
    else
    {
        *pl = ant;
    }

    return 1;
}
void vaciarLista(tListad* pl)
{
    tNodod* elim,*sig,*ant;
    while(*pl)
    {
        elim = *pl;
        sig = elim->sig;
        ant = elim->ant;
        if(sig)
        {
            sig->ant = ant;
        }
        if(ant)
        {
            ant->sig = sig;
        }

        free(elim->d);
        free(elim);

        *pl = sig?sig:ant;
    }
}

int listaLlena(const tListad* pl,unsigned tam)
{
    tNodod* nue = (tNodod*)malloc(sizeof(tNodod));
    void* d = malloc(tam);
    free(nue);
    free(d);
    return !nue || !d;
}

int listaVacia(const tListad* pl)
{
    return *pl ==NULL;
}

int insertarPrimero(tListad* pl,const void* d,unsigned tam)
{
    tNodod* nue = (tNodod*)malloc(sizeof(tNodod));
    if(!nue)
    {
        return 0;
    }
    nue->d = malloc(tam);
    if(!(nue->d))
    {
        return 0;
    }
    memcpy(nue->d,d,tam);
    nue->tam = tam;
    nue->ant = NULL;

    if(*pl)
    {
        while((*pl)->ant)
        {
            *pl = (*pl)->ant;
        }
        (*pl)->ant = nue;

    }
    nue->sig = *pl;

    *pl = nue;
    return 1;
}

int elimDuplicadosDesordenados(tListad* pl,const void* d, int(*busqueda)(const void* a, const void* b))
{
    tNodod *act= *pl,*primerAparicion;
    int bandera = 0;

    if(act)
    {
        while(act) //RECORRE POR LA DERECHA DE *PL
        {
            if(busqueda(act->d,d))
            {
                if(!bandera)
                {
                    primerAparicion = act;
                    act =act->sig;
                    bandera++;
                }
                else if(act == primerAparicion)
                {
                    act = act->sig;
                }
                else{
                    borrarNodo(&act);
                    bandera++;
                }
            }
            else
            {
                act = act->sig;
            }
        }
        act = (*pl)->ant;
        while(act)
        {

            if(busqueda(act->d,d))
            {
                if(!bandera)
                {
                    primerAparicion = act;
                    act = act->ant;
                    bandera++;
                }
                else if(act == primerAparicion)
                {
                    act = act->ant;
                }
                else{
                    bandera++;
                    borrarNodo(&act);
                }
            }
            else
            {
                act = act->ant;
            }
        }

        if(bandera>1)
        {
            borrarNodo(&primerAparicion);
            *pl = primerAparicion;
        }
    }
    return bandera>1? bandera:0;
}

int borrarNodo(tListad* pl)
{
    tNodod *elim = *pl, *ant = NULL, *sig = NULL;
    if(!elim)
    {
        return 0;
    }
    ant = elim->ant;
    sig = elim->sig;
    if(sig)
    {
        sig->ant = ant;
    }
    if(ant)
    {
        ant->sig = sig;
    }
    /*else{
        *pl = sig;
    }*/
    free(elim->d);
    free(elim);
    *pl = sig? sig:ant;
    return 1;
}

void eliminarDuplicadosDesordenadosTodosValores(tListad *pl, int(*busqueda)(const void*a, const void* b))
{
    tNodod *act = *pl,*primerAparicion;
    int esRepetido;

    if(act)
    {
        while(act->ant) // me para al comienzo
        {
            act = act->ant;
        }

        while(act && act->sig)
        {
            primerAparicion = act;
            esRepetido = 0;
            act = act->sig;
            while(act)
            {
                if(busqueda(act->d,primerAparicion->d))
                {
                    esRepetido = 1;
                    borrarNodoSig(&act);
                }
                else{
                    act = act->sig;
                }
            }


            act = primerAparicion->sig;

            if(esRepetido)
            {
                borrarNodo(&primerAparicion);
            }


    }

    *pl=primerAparicion;

    }
}

int borrarNodoSig(tListad* pl)
{
    tNodod* elim = *pl, *sig, *ant;

    if(!elim)
        return 0;

    sig = elim->sig;
    ant = elim->ant;
    if(sig)
    {
        sig->ant = ant;
    }
    if(ant)
    {
        ant->sig =sig;
    }
    free(elim->d);
    free(elim);
    *pl = sig;
    return 1;
}

int borrarNodoAnt(tListad* pl)
{
    tNodod* elim = *pl, *sig, *ant;

    if(!elim)
        return 0;

    sig = elim->sig;
    ant = elim->ant;
    if(sig)
    {
        sig->ant = ant;
    }
    if(ant)
    {
        ant->sig =sig;
    }
    free(elim->d);
    free(elim);
    *pl = ant;
    return 1;
}


void acumDesordenado(tListad * pl, void(*acumular)(void * a, const void*b), int(*comparacion)(const void* a, const void* b))
{
    tNodod* act, *primerAparicion = *pl;
    int bandera = 0;

    while(primerAparicion)
    {
        act = primerAparicion->sig;

        while(act)
        {
            if(!comparacion(act->d,primerAparicion->d))
            {
                acumular(primerAparicion->d,act->d);
                borrarNodoSig(&act);
            }
            else
            {
                act = act->sig;
            }
        }
        act = primerAparicion->ant;

        while(act)
        {
            if(!comparacion(act->d,primerAparicion->d))
            {
                acumular(primerAparicion->d,act->d);
                borrarNodoAnt(&act);
            }
            else
            {
                act = act->ant;
            }

        }

        if(!(primerAparicion->sig))
        {
            bandera = 1;
            primerAparicion = *pl;
        }

        primerAparicion = (!bandera)? primerAparicion->sig : primerAparicion->ant;
    }
}


