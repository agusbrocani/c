#include "cola.h"
#define minimo(X,Y) (((X)>(Y))? (Y) : (X) )

void crearCola(tCola *c)
{
    c->pri = 0;
    c->ult = 0;
    c->tamDis = TAM_COLA;
}

int colaLlena(const tCola *c,size_t tam)
{
    return c->tamDis<tam+sizeof(unsigned);
}

int colaVacia(const tCola *c)
{
    return c->tamDis == TAM_COLA;
}

void vaciarCola(tCola* c)
{
    c->ult = c->pri;
    c->tamDis = TAM_COLA;
}

int acolar(tCola* c, const void *d, unsigned tam)
{
    unsigned ini, fin;
    if(c->tamDis<sizeof(unsigned)+tam)
    {
        return 0;
    }
    //procesamos tam
    c->tamDis -=sizeof(unsigned)+tam;
    //ini = minimo(sizeof(unsigend), TAM_COLA - c->ult)); siendo c->ult el indice que selecciona donde termina el ultimo elemento
    if((ini = minimo(sizeof(unsigned), TAM_COLA - c->ult)) != 0)
        memcpy(c->cola +c->ult,&tam,ini); //TAM_COLA -c->ult es igual a cero solo cuando c->ult = TAM_COLA, eso quiere decir que esta parado en el final
    //fin = sizeof(tam)-ini;
    if((fin = sizeof(tam)-ini)!=0)
        memcpy(c->cola, ((char*)&tam)+ini,fin);
    c->ult = fin? fin: c->ult +ini;
    //procesamos la informacion
    //ini = minimo(tam,TAM_COLA - c->ult);
    if((ini = minimo(tam,TAM_COLA-c->ult))!=0)
        memcpy(c->cola + c->ult,d,ini);
        //fin = tam-ini;
    if((fin = tam-ini)!=0)
        memcpy(c->cola, ((char*)d)+ini,fin);
    c->ult = fin? fin: c->ult+ini; //esta pregunta siempre es necesaria cuando termino de procesar algo
    return 1;
}

int desacolar(tCola*c,void* d,unsigned tam)
{
    unsigned tamInfo,ini,fin;

    if(c->tamDis == TAM_COLA) //me fijo que no este vacio
    {
        return 0;
    }

    //proceso tamInfo
    ini = minimo(sizeof(unsigned),TAM_COLA-c->pri); //la diferencia con acolar es que aca hago TAM_COLA -c->pri
    if(ini)
    {
        memcpy(&tamInfo,c->cola + c->pri,ini);
    }
    fin = sizeof(unsigned) - ini;
    if(fin)
    {
        memcpy(((char*)&tamInfo)+ini,c->cola,fin);
    }
    c->pri = fin? fin: c->pri + ini;

    c->tamDis+=sizeof(unsigned) + tamInfo;
    tamInfo = minimo(tam,tamInfo);

    //proceso la informacion

    ini = minimo(tamInfo,TAM_COLA-c->pri);
    if(ini)
    {
        memcpy(d, c->cola+c->pri,ini);
    }
    fin = tamInfo -ini;
    if(fin)
    {
        memcpy(((char*)d)+ini,c->cola,fin);
    }
    //c->pri = fin? fin: c->pri+ini;
    c->pri=(c->pri+tamInfo)%TAM_COLA;
    return 1;
}

int verPrimero(const tCola*c, void *d,size_t tam)
{
    unsigned tamPrimero,ini,fin,primero = c->pri;

    if(c->tamDis == TAM_COLA) // la cola esta vacia
    {
        return 0;
    }

    //proceso la tamaño
    ini = minimo(sizeof(unsigned),TAM_COLA - c->pri);

    if(ini)
    {
        memcpy(&tamPrimero, c->cola+c->pri,ini);
    }
    fin = sizeof(tamPrimero)-ini;

    if(fin)
    {
         memcpy(((char*)&tamPrimero)+ini,c->cola,fin);
    }
    primero = fin? fin: primero + ini;
    tamPrimero = minimo(tam,tamPrimero);
    //proceso la info

    ini = minimo(tamPrimero,TAM_COLA - primero);
    if(ini)
    {
        memcpy(d,c->cola+primero,ini);
    }
    fin = tamPrimero -ini;

    if(fin)
    {
        memcpy(((char*)d)+ini,c->cola,fin);
    }
    //NO HACE FALTA PREGUNTAR primero = fin? fin: primero+ini por que ya leimos lo que queriamos
    return 1;
}
