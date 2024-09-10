#include "../../include/menu/arbol.h"

void crearArbol(tArbol* a)
{
    *a =NULL;
}

int insertarEnArbol(tArbol* a, const void* d,unsigned tam, int (*comparar)(const void*a,const void* b))
{
    tNodoa* nuevo;
    int cmp;

    if(*a == NULL)
    {
        nuevo = (tNodoa*)malloc(sizeof(tNodoa));
        if(!nuevo)
        {
            return 0;
        }
        nuevo->d = malloc(tam);
        if(!(nuevo->d))
        {
            free(nuevo);
            return 0;
        }
        nuevo->tam = tam;
        nuevo->der=NULL;
        nuevo->izq =NULL;
        memcpy(nuevo->d,d,tam);
        *a = nuevo;
        return 1;
    }
    cmp = comparar((*a)->d,d);

    if(cmp>0)
    {
        return insertarEnArbol(&((*a)->izq),d,tam,comparar);
    }
    if(cmp<0)
    {
        return insertarEnArbol(&((*a)->der),d,tam,comparar);
    }

    if(!cmp)
    {
        return 1;//hubo duplicados pero no me interesa, sigo insertando
    }

    return 0;
}

void recorrerPreOrden( const tArbol* a, void (*accion)(const void*a))
{
    if(*a)
    {
        accion((*a)->d); //raiz
        recorrerPreOrden(&((*a)->izq),accion);
        recorrerPreOrden(&((*a)->der),accion);
    }
}

void recorrerOrden( const tArbol* a, void (*accion)(const void*a))
{
    if(*a)
    {
        recorrerOrden(&((*a)->izq),accion);
        accion((*a)->d);//raiz
        recorrerOrden(&((*a)->der),accion);
    }
}

void recorrerPostOrden( const tArbol* a, void (*accion)(const void*a))
{
    if(*a)
    {
        recorrerPostOrden(&((*a)->izq),accion);
        recorrerPostOrden(&((*a)->der),accion);
        accion((*a)->d);//raiz
    }

}

void mostrarArbol(const tArbol* a, void(*mostrarDato)(const void* d))
{
    int contador = 0;
    mostrarArbolR(a,contador,mostrarDato);
}

void mostrarArbolR(const tArbol* a,int contador,void(*mostrarDato)(const void* d))
{
    //int i;
    if(*a == NULL)
    {
        return;
    }

    mostrarArbolR(&((*a)->der),contador+1,mostrarDato);

    printf("%*c",contador*5,' ');
    /*for(i=0; i<contador;i++)
    {
        printf("\t");
    }*/
    mostrarDato((*a)->d);
    printf("\n");
    mostrarArbolR(&((*a)->izq),contador+1,mostrarDato);
}

int contadorNodos(const tArbol* a)
{
    return *a? contadorNodos(&((*a)->izq)) +  contadorNodos(&((*a)->der))+1: 0;
}

int alturaArbol(const tArbol* a)
{
    return *a? MAYOR(alturaArbol(&((*a)->izq)),alturaArbol(&((*a)->der)))+1:0;
}

int esCompletoANivel(const tArbol* a, int n)
{
    if(!(*a))
    {
        return 0;
    }
    if(n== 0)
    {
        return 1;
    }
    return esCompletoANivel(&((*a)->izq),n-1) && esCompletoANivel(&((*a)->der),n-1);
}

int esCompleto(const tArbol *a)
{
    return esCompletoANivel(a,alturaArbol(a)-1);
}

int esBalanceado(const tArbol *a)
{
    return esCompletoANivel(a,alturaArbol(a)-2);
}

void vaciarArbol(tArbol* a)///03-09-2024
{
    while(NULL != *a)
    {
        eliminarRaiz(a);
    }
}

int eliminarRaiz(tArbol* a)
{
    tNodoa **remp;
    tNodoa *elim;

    if(!(*a)) //arbol vacio no puedo eliminar nada, devuelvo 0
    {
        return 0;
    }
    free((*a)->d);

    if(!((*a)->izq) && !((*a)->der)) //arbol con solo un elemento, lo elimino, devuelvo 1
    {
        free(*a);
        *a = NULL;
        return 1;
    }

    remp = alturaArbol(&(*a)->izq)>alturaArbol(&(*a)->der)? mayorNodo(&(*a)->izq) : menorNodo(&(*a)->der);
    elim = *remp;

    (*a)->d = elim->d;
    (*a)->tam = elim->tam;
    *remp = elim->izq? elim->izq : elim->der;

    free(elim);
    return 1;
}

tNodoa** mayorNodo(const tArbol* a)
{

    while((*a) && (*a)->der)
    {
        a = &((*a)->der);
    }
    return (tNodoa**)a;
}

tNodoa** menorNodo(const tArbol* a)
{

    while((*a) && (*a)->izq)
    {
        a = &((*a)->izq);
    }
    return (tNodoa**)a;
}

int eliminarNodoPorClave(tArbol *a, void* dato, int(*comparar)(const void* a, const void* b))
{
    if(!(*a))
    {
        return 0;
    }
    if(comparar(dato,(*a)->d) == 0)
    {
        eliminarRaiz(a);
        return 1;
    }
    if(comparar(dato,(*a)->d)<0)
    {
        return eliminarNodoPorClave(&(*a)->izq,dato,comparar);
    }

    return eliminarNodoPorClave(&(*a)->der,dato,comparar);
}

tNodoa* buscarPorClave(tArbol *a, void* dato, int(*comparar)(const void* a,const void* b))
{
    if(!(*a) || comparar(dato,(*a)->d) == 0)
    {
        return *a;
    }
    if(comparar(dato,(*a)->d)<0)
    {
        return buscarPorClave(&(*a)->izq,dato,comparar);
    }

    return buscarPorClave(&(*a)->der,dato,comparar);
}

unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params)
{
    unsigned tam = *((int*)params);
    *d = malloc(tam);
    if(!*d)
        return 0;
    fseek((FILE*)pf, pos*tam, SEEK_SET);
    return fread(*d, tam, 1, (FILE*)pf);
}

int cargarDesdeDatosOrdenadosRec(tArbol * p, void * ds,unsigned (*leer)(void **, void *, unsigned, void *params),int li, int ls, void * params)
{
    int m = (li+ls)/2, r;
    if (li>ls)
        return 1;

    (*p) = (tNodoa*) malloc(sizeof(tNodoa));
    if (!*p || !((*p)->tam= leer(&(*p)->d, ds, m, params)))
    {
        free(*p);
        return 0;
    }

    (*p)->izq = (*p)->der = NULL;

    if((r=cargarDesdeDatosOrdenadosRec(&(*p)->izq, ds, leer, li, m-1, params))!=
            1)
        return r;
    return cargarDesdeDatosOrdenadosRec(&(*p)->der, ds, leer, m+1, ls, params);
}


int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbol * p, FILE * pf,unsigned tamd)
{
    int cantReg;
    if(*p || !pf)
        return 0;
    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tamd;
    return cargarDesdeDatosOrdenadosRec(p, pf, leerDesdeArchivoBin, 0, cantReg-1, & tamd);
}

int cargarArchivoBinOrdenadoArbolBinBusq(tArbol * p, const char * path,unsigned tamd)
{
    int cantReg,
        r;
    FILE * pf;
    if(*p)
        return 0;
    if(!(pf= fopen(path, "rb")))
        return 0;
    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tamd;
    r = cargarDesdeDatosOrdenadosRec(p, pf, leerDesdeArchivoBin, 0, cantReg-1, &
                                     tamd);
    fclose(pf);
    return r;
}

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbol * p, void * ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params)
{
    if(*p || !ds)
        return 0;
    return cargarDesdeDatosOrdenadosRec(p, ds, leer, 0, cantReg-1, params);
}

/*

void insertarEnPreOrder(t_arbol * a, FILE*archIndices, int li, int ls, int comparar(void*d1,void*d2)){
    tidx dato;
    if(li==ls){
        fseek(archIndices, 1L*sizeof(tidx)*ls, SEEK_SET);
        fread(&dato, sizeof(tidx),1, archIndices);
        insertarArbol(a, &dato, sizeof(dato), comparar);
        return;
    }
    fseek(archIndices, 1L*sizeof(tidx)*((ls-li)/2)+li), SEEK_SET);
    fread(&dato, sizeof(tidx),1, archIndices);
    insertarArbol(a, &dato, sizeof(dato), comparar);
    insertarEnPreOrder(a, archIndices, li, ((ls-li)/2)+li, comparar);
    insertarEnPreOrder(a, archIndices, ((ls-li)/2)+li+1, ls, comparar);
}*/


int insertarArchOrdenado(tArbol* a, FILE* pf, int li, int ls,unsigned tamReg)
{
    int m = (li+ls)/2, r;
    if(li>ls)
    {
        return 1;
    }
    *a = (tNodoa*)malloc(sizeof(tNodoa));

    if(!(*a))
    {
        return 0;
    }
    (*a)->d = malloc(tamReg);

    if((*a)->d == NULL)
    {
        free(*a);
        return 0;
    }

    fseek(pf,(long)m*tamReg,SEEK_SET); //me posiciona en el archivo
    fread((*a)->d,tamReg,1,pf);
    (*a)->tam = tamReg;
    (*a)->izq = (*a)->der =NULL;

    r=insertarArchOrdenado(&(*a)->izq,pf,li,m-1,tamReg);
    if(!r)
    {
        return r;
    }
    return insertarArchOrdenado(&(*a)->der,pf,m+1,ls,tamReg);
}

//LI EN UN COMIENZO ES SIEMPRE 0 Y LS EN ARCHIVOS ES CANTREG -1 SIENDO LA CANTREG
// fseek(pf,0L,SEEK_END); cantReg = ftell(pf)/tamReg
