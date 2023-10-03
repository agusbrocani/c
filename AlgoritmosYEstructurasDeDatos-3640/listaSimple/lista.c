#include"lista.h"


void crearLista(tLista *pl)
{
    *pl = NULL;
}


int insertarAlFinal(tLista* pl, const void*d,unsigned tam)
{
    tNodo* ultNodo = (tNodo*)malloc(sizeof(tNodo));
    ultNodo->d = malloc(tam);
    if(!ultNodo || !(ultNodo->d))
    {
        free(ultNodo);
        return 0;
    }
    //cargo el Nuevo tNodo y hago que sig apunte a NULL ya que sera el ultimo
    memcpy(ultNodo->d,d,tam);
    ultNodo->tam = tam;
    ultNodo->sig = NULL;

    while(*pl)
    {
        pl = &((*pl)->sig);
    }
    *pl = ultNodo; // Recordamos que *pl es tNodo* entonces esta asignacion es valida
    return 1;
}


int insertarAlComienzo(tLista* pl,const void *d,unsigned tam)
{
    tNodo* priNodo = (tNodo*)malloc(sizeof(tNodo));
    priNodo->d = malloc(tam);
    if(!priNodo || !(priNodo->d))
    {
        free(priNodo);
        return 0;
    }
    //cargo el Nuevo tNodo y hago que sig apunte a *pl ya que sera el ultimo
    memcpy(priNodo->d,d,tam);
    priNodo->tam = tam;
    priNodo->sig = *pl;

    *pl = priNodo;
    return 1;

}

int insertarOrdenado (tLista* pl, const void* dato, unsigned tamDato,int (*comparar)(void* dato1, void* dato2)) //ascendente
{
    tNodo* aux;
    while((*pl) != NULL && comparar((void*)dato,(*pl)->d)> 0)    ///Corregido
        pl = &(*pl)->sig;

    //pl se acabo o el dato es menor o igual al de la lista

    aux = (tNodo*)malloc(sizeof(tNodo));
    aux->d = malloc(tamDato);

    if(!aux || !(aux->d))
    {
        free(aux);
        return 0;

    }

    memcpy(aux->d,dato,tamDato);
    aux->tam = tamDato;
    aux->sig = *pl;

    *pl = aux;

    return 1;
} //1 3 6 8 quiero insertar 7 en modo ascendente
// recorro la lista hasta el 8, creo el nodo aux, le asigno al siguiente de aux el 8, y donde estaba el 8 meto el aux
//13678

int cargarListaVector(tLista* pl, const void* d, unsigned tamE, unsigned cantE, int(*insertar)(tLista* pl, const void* d, unsigned tam))
{
    unsigned i;


    for( i = 0; i<cantE; i++)
    {
        if(!insertar(pl,d,tamE))
            return 0;
        d = ((char*)d) + tamE;
    }
    return 1;
}

void mostrarListaGen(const tLista* pl, void mostrarElemento(const void *d))
{
    while(*pl)
    {
        mostrarElemento((*pl)->d);//muestro elemento
        pl =&((*pl)->sig); //avanzo
    }
}
void mostrarProducto(const void* a)
{
    printf("\n %d %d %lf",((tProducto*)a)->idProducto,((tProducto*)a)->cantidad,((tProducto*)a)->precio);
}
void mostrarNumero(const void *d)
{
    printf("%d ",*((int*)d));
}

void vaciarLista(tLista *pl)
{
    tNodo* elim;
    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;

        free(elim->d);
        free(elim);
    }
}

int listaVacia(const tLista *pl)
{
    return *pl ==NULL;
}

int listaLlena(const tLista* pl,unsigned tam)
{
    tNodo* aux = (tNodo*)malloc(sizeof(tNodo));
    void * info = malloc(tam);
    free(info);
    free(aux);

    return !(info && aux);
}

int sacarUltimo(tLista * pl, void* d, unsigned tam)
{
    if(*pl == NULL)
    {
        return 0;
    }

    while((*pl)->sig)//esto te deja en el ultimo, sig == NULL;
    {
        pl = &((*pl)->sig);
    }
    memcpy(d,(*pl)->d,minimo(tam,(*pl)->tam));
    free((*pl)->d);
    free(*pl);
    *pl = NULL;
    return 1;
}


int sacarPrimero(tLista *pl, void*d, unsigned tam)
{
    if(*pl == NULL)
    {
        return 0;
    }
    tNodo *aux = *pl;
    *pl = (*pl)->sig;
    memcpy(d,aux->d,minimo(tam,aux->tam));
    free(aux->d);
    free(aux);
    return 1;
}

tNodo* buscarPrimerAparicion(const tLista* pl, void *d,int (*busqueda)(const void*d, const void*a))
{
    while(*pl && !busqueda(d,(*pl)->d))
    {
        pl = &(*pl)->sig;
    }
    return *pl;
}

int actualizarEnLista(tLista* pl, const void* d,unsigned tam,void (*actualizar)(void* a, const void*b),int(*comparacion)(const void* a, const void* b))
{
    //ESTA ES SI LA LISTA ESTA ORDENADA
    tNodo* aux;

    //comp mayor a cero Si d< (*pl)->d
    //comp 0 si d == (*pl)->d
    //comp menor a cero si d> (*pl)->d

    while((*pl) && (comparacion((*pl)->d,d)<0))
    {
        pl = &((*pl)->sig);
    }

    if(comparacion((*pl)->d,d) == 0)
    {
        actualizar((*pl)->d,d); // actualizado recibe un void* que representa el contenido del nodo *pl y d que tendra los cambios
    }

    if(!(*pl) || comparacion((*pl)->d,d)>0)//dio negativo el elemento no existe, lo inserto
    {
        aux = (tNodo*)malloc(sizeof(tNodo));
        aux->d = malloc(tam);
        if(!aux || !(aux->d))
        {
            free(aux);
            return 0;
        }
        memcpy(aux->d,d,tam);
        aux->tam = tam;
        aux->sig = *pl;
        *pl = aux;
    }
    else
    {
        actualizar((*pl)->d,d); // actualizado recibe un void* que representa el contenido del nodo *pl y d que tendra los cambios
    }


    return 1;

}

void actualizarProductos(void* a, const void* b)
{
    ((tProducto*)a)->cantidad +=  ((tProducto*)b)->cantidad;
}

int compararProductos(const void* a, const void* b)
{
    return ((tProducto*)a)->idProducto -((tProducto*)b)->idProducto;
}


void eliminarApariciones(tLista* pl,int (*comparacion)(const void* a, const void * b))
{
    tNodo* elim;

    while((*pl))
    {
        while((*pl)->sig && (comparacion((*pl)->d,(*pl)->sig->d) == 0))
        {
            elim = *pl;
            *pl = (*pl)->sig;
            free(elim->d);
            free(elim);
        }
        pl = &((*pl)->sig);
    }
}

void acumularApariciones(tLista* pl,int (*comparacion)(const void* a, const void * b),void (*acumular)(void *a, const void *b))
{
    tNodo* elim;

    while((*pl))
    {
        while((*pl)->sig && (comparacion((*pl)->d,(*pl)->sig->d) == 0)) //   3 4
        {
            elim = *pl;
            *pl = (*pl)->sig;

            acumular((*pl)->d,elim->d);

            free(elim->d);
            free(elim);
        }
        pl = &((*pl)->sig);
    }
}

void acumularProductos(void *a, const void *b)
{
    ((tProducto*)a)->cantidad +=  ((tProducto*)b)->cantidad;
}

void ordenarLista(tLista* pl,int (*comparar)(const void* a, const void* b))
{
    tNodo** menor; //&(tNodo*) --> &(&tNodo)
    tNodo* mov;
    if(*pl) //lista no vacia
    {
        while((*pl)->sig) //si el sig apunta a null sale del ciclo o directamente no entra
        {
            menor = buscarMenor(pl,comparar); //devuele tNodo**
            if(menor != pl) //equivaldria a un swap, enganche y desenganche
            {
                mov =*menor;
                *menor = mov->sig;
                mov->sig = *pl;
                *pl = mov;
            }

            pl =&((*pl)->sig);
        }
    }
}

tNodo** buscarMenor(tLista* pl, int(*comparar)(const void* a, const void* b))
{
    tNodo** menor = pl;
    pl =&((*pl)->sig);
    while(*pl)
    {
        if(comparar((*pl)->d,(*menor)->d)<0)
        {
            menor = pl;
        }
        pl =&((*pl)->sig);
    }

    return menor;

}

int insertarOrdenadoAcumulado(tLista* pl, const void*d, unsigned tam, int(*comparar)(const void* a, const void* b), void (*acumular)(void* a, const void* b))
{
    tNodo* elem; //si el elemento no existe, elem va a crear un nuevo nodo y lo va a insertar ordenado

    while(*pl && comparar((*pl)->d,d)<0)
    {
        pl = &((*pl)->sig);
    }
    if((*pl) == NULL || comparar((*pl)->d,d)>0)
    {
        elem = (tNodo*)malloc(sizeof(tNodo));
        if(!elem)
        {
            return 0;
        }
        elem->d = malloc(tam);

        if(!(elem->d))
        {
            return 0;
        }
        memcpy(elem->d,d,tam);
        elem->tam = tam;
        elem->sig = *pl;
        *pl = elem;
    }
    else
    {
        acumular((*pl)->d,d);
    }
    return 1;
}

void acumularNumeros(void* a, const void *b)
{
    return;
}


void mapMio(tLista* pl, void (*accion)(void* d))///RECORRER LA LISTA Y HACER ALGO COMO CALCULAR PROMEDIO
{
    while(*pl)
    {
        accion((*pl)->d);
        pl =&((*pl)->sig);
    }
}

void rMapMio(tLista* pl, void (*accion)(void* d))///recursiva
{
    if(*pl)
    {
        accion((*pl)->d);
        rMapMio(&((*pl)->sig),accion);
    }
}


int filtrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro)///FILTRAR
{
    tNodo* elim;
    int elemDel = 0;
    while(*pl)
    {
        if(fFiltro((*pl)->d,filtro))
        {
            elim =*pl;
            *pl = (*pl)->sig;
            free(elim->d);
            free(elim);
            elemDel++;
        }
        else
        {
           pl= &((*pl)->sig);
        }
    }
    return elemDel;
}



int rFiltrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro)
{
    int elemDel = 0;

    _rFiltrar(pl,fFiltro,filtro,&elemDel);

    return elemDel;
}

void _rFiltrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro, int* cant)
{
    tNodo* elim;
    if(*pl)
    {
        if(fFiltro((*pl)->d,filtro))
        {
            elim = (*pl);
            (*pl) = (*pl)->sig;
            free(elim->d);
            free(elim);
            *cant +=1;
            _rFiltrar(pl,fFiltro,filtro,cant);
        }

        _rFiltrar(&((*pl)->sig),fFiltro,filtro,cant);
    }
}


int reduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum)
{
    int cantElem = 0;

    while(*pl)
    {
        fReduccion((*pl)->d,acum);
        pl = &((*pl)->sig);
        cantElem++;
    }

    return cantElem;
}



int rReduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum)
{
    int cantElem;
    _rReduce(pl,fReduccion,acum,&cantElem);
    return cantElem;
}

void _rReduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum, int* cant)
{
    if(*pl)
    {
        fReduccion((*pl)->d,acum);
        *cant +=1;
        _rReduce(&((*pl)->sig),fReduccion,acum,cant);
    }
}

void mostrarListaAlRevesRecursiva(tLista* pl, void(*mostrar)(const void* d))
{
    if(*pl)
    {
        mostrarListaAlRevesRecursiva(&((*pl)->sig),mostrar);
        mostrar((*pl)->d);
    }
}

void mostrarListaRecursiva(tLista* pl, void(*mostrar)(const void* d))
{
    if(*pl)
    {
        mostrar((*pl)->d);
        mostrarListaRecursiva(&((*pl)->sig),mostrar);
    }
}




/*void mostrarListaAlReves(tLista* pl, void(*mostrar)(const void* d))
{
    tPila elemAlreves;
    crearPila(&elemAlreves);
    unsigned tamElem = (*pl)?(*pl)->tam:0;
    void* aux = malloc(tamElem);

    while(*pl)
    {
        apilar(&elemAlreves,(*pl)->d,(*pl)->tam);

        pl= &((*pl)->sig);
    }

    while(desapilar(&elemAlreves,aux,tamElem))
    {
        mostrar(aux);
    }
}*/
