#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAYOR(X,Y) ((X)>(Y))? (X):(Y)

typedef struct sNodoa
{
    void* d;
    unsigned tam;
    struct sNodoa* der;
    struct sNodoa* izq;
}tNodoa;

typedef tNodoa* tArbol;

void crearArbol(tArbol* a);
int insertarEnArbol(tArbol* a, const void* d,unsigned tam, int (*comparar)(const void*a,const void* b));
void recorrerPreOrden(const tArbol* a, void (*accion)(const void*a));
void recorrerOrden(const tArbol* a, void (*accion)(const void*a));
void recorrerPostOrden( const tArbol* a, void (*accion)(const void*a));
void mostrarArbol(const tArbol* a,void(*mostrarDato)(const void* d));
void mostrarArbolR(const tArbol* a, int contador, void(*mostrarDato)(const void* d));
int contarNodos(const tArbol*a);
int esCompletoANivel(const tArbol* a, int n);
int esCompleto(const tArbol* a);
int esBalanceado(const tArbol* a);
int eliminarRaiz(tArbol* a);
tNodoa** menorNodo(const tArbol* a);
tNodoa** mayorNodo(const tArbol* a);
int eliminarNodoPorClave(tArbol *a, void* dato, int(*comparar)(const void* a, const void* b));
tNodoa* buscarPorClave(tArbol *a, void* dato, int(*comparar)(const void* a,const void* b));

unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params);
int cargarDesdeDatosOrdenadosRec(tArbol * p, void * ds,unsigned (*leer)(void **, void *, unsigned, void *params),int li, int ls, void * params);
int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbol * p, FILE * pf,unsigned tamd);
int cargarArchivoBinOrdenadoArbolBinBusq(tArbol * p, const char * path,unsigned tamd);
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbol * p, void * ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params);

//mostrarnivel buscar y esALV
#endif // ARBOL_H_INCLUDED
