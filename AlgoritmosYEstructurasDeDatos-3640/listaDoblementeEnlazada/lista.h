#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define minimo(X,Y) (((X)>(Y)) ? (Y) : (X))

typedef struct sNodod
{
    void* d;
    unsigned tam;
    struct sNodod *sig;
    struct sNodod *ant;
}tNodod;

typedef tNodod* tListad;

void crearLista(tListad* pl);
void vaciarLista(tListad* pl);
int insertar(tListad* pl, const void* d, unsigned tam);
int listaLlena(const tListad* pl,unsigned tam);
int listaVacia(const tListad* pl);
int insertarUltimo(tListad* pl, const void* d, unsigned tam);
int insertarPrimero(tListad* pl, const void* d, unsigned tam);
void mostrarIzqDer(const tListad* pl,void(*mostrar)(const void*d));
void mostrarDerIzq(const tListad* pl,void(*mostrar)(const void*d));
int insertarEnOrden(tListad* pl, const void* d, unsigned tam, int (*comparacion)(const void* a, const void* b));
int eliminarElemento(tListad* pl, void* d, unsigned tam);
int elimDuplicadosDesordenados(tListad* pl,const void* d, int(*busqueda)(const void* a, const void* b));
int borrarNodo(tListad* pl);
int borrarNodoSig(tListad* pl);
void eliminarDuplicadosDesordenadosTodosValores(tListad *pl, int(*busqueda)(const void*a, const void* b));
int borrarNodoAnt(tListad* pl);
void acumDesordenado(tListad * pl, void(*acumular)(void * a, const void*b), int(*comparacion)(const void* a, const void* b));
#endif // LISTA_H_INCLUDED
