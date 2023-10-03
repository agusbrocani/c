#include "pila.h"

void crearPila(tPila *p)
{
    p->tope = TAM_PILA; // EN ESTA IMPLEMENTACION TOPE REPRESENTA LA CANT DE BYTES DISPONIBLES EN LA PILA
}
int pilaLlena(const tPila *p,unsigned tam)
{
    return p->tope<tam + sizeof(unsigned);
}
int apilar(tPila* p, const void* d, unsigned tam)
{
    if(p->tope<tam + sizeof(unsigned))
       return 0;
    //se guarda primero la info y despues el tam
    p->tope -= tam;
    memcpy(p->pila + p->tope,d,tam);
    p->tope-=sizeof(unsigned);
    memcpy(p->pila +p->tope,&tam,sizeof(unsigned));
    return 1;
}
int verTope(const tPila *p, void* d, unsigned tam)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo,p->pila + p->tope,sizeof(unsigned));
    memcpy(d,p->pila + p->tope +sizeof(unsigned),minimo(tamInfo,tam));
    return 1;

}
int pilaVacia(const tPila *p)
{
    return p->tope == TAM_PILA;
}
int desapilar(tPila*p, void*d, unsigned tam)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo,p->pila + p->tope,sizeof(unsigned));
    memcpy(d,p->pila+p->tope + sizeof(unsigned),minimo(tam,tamInfo);
    p->tope += tamInfo + sizeof(unsigned);
    return 1;
}
void vaciarPila(tPila* p)
{
    p->tope = TAM_PILA;
}
