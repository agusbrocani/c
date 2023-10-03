#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#define minimo(X,Y) (((X)>(Y))? (Y):(X))

typedef struct sNodo
{
    struct sNodo* sig;
    void* d;
    unsigned tam;
}tNodo;

typedef tNodo* tLista;

typedef struct
{
    int idProducto;
    int cantidad;
    double precio;
}tProducto;

void crearLista(tLista *pl);
int insertarAlFinal(tLista* pl, const void*d,unsigned tam);
int insertarAlComienzo(tLista* pl,const void *d,unsigned tam);
int insertarOrdenado (tLista* pl, const void* dato, unsigned tamDato,int (*comparar)(void* dato1, void* dato2));
int cargarListaVector(tLista* pl, const void* d, unsigned tamE, unsigned cantE, int(*insertar)(tLista* pl, const void* d, unsigned tam));
void mostrarListaGen(const tLista* pl, void mostrarElemento(const void *d));
void mostrarNumero(const void *d);
void vaciarLista(tLista *pl);
int listaVacia(const tLista *pl);
int listaLlena(const tLista* pl,unsigned tam);
int sacarUltimo(tLista * pl, void* d, unsigned tam);
int sacarPrimero(tLista *pl, void*d, unsigned tam);
tNodo* buscarPrimerAparicion(const tLista *pl, void *d,int (*busqueda)(const void*d, const void*a));
int actualizarEnLista(tLista* pl, const void* d,unsigned tam,void (*actualizar)(void* a, const void*b),int(*comparacion)(const void* a, const void* b));
void actualizarProductos(void* a, const void* b);
int compararProductos(const void* a, const void* b);
void mostrarProducto(const void* a);
void eliminarApariciones(tLista* pl,int (*comparacion)(const void* a, const void * b));
void acumularProductos(void *a, const void *b);
void acumularApariciones(tLista* pl,int (*comparacion)(const void* a, const void * b),void (*acumular)(void *a, const void *b));

int insertarOrdenadoAcumulado(tLista* pl, const void*d, unsigned tam, int(*comparar)(const void* a, const void* b), void (*acumular)(void* a, const void* b));

void acumularNumeros(void* a, const void *b);
void ordenarLista(tLista* pl,int (*comparar)(const void* a, const void* b));
tNodo** buscarMenor(tLista* pl, int(*comparar)(const void* a, const void* b));

void mapMio(tLista* pl, void (*accion)(void* d));
int filtrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro);
int reduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum);


void rMapMio(tLista* pl, void (*accion)(void* d));
int rFiltrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro);
void _rFiltrar(tLista *pl, int (*fFiltro)(const void*a, const void* b), void* filtro, int* cant);
int rReduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum);
void _rReduce(tLista* pl, void (*fReduccion)(const void* info,void* ac),void* acum, int* cant);



void mostrarListaAlRevesRecursiva(tLista* pl, void(*mostrar)(const void* d));
void mostrarListaRecursiva(tLista* pl, void(*mostrar)(const void* d));
#endif // LISTA_H_INCLUDED
