#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>
#include "../lista.h"

void crearListaSimple(t_lista* pl);
int insertarAlFinalEnListaSimple(t_lista* pl, const void* dato, unsigned tam);
int sacarPrimeroEnListaSimple(t_lista* pl, void* dato, unsigned tam);
void mostrarListaSimpleEnOrden(const t_lista* pl, void (*mostrar)(const void* dato));
void vaciarListaSimple(t_lista *pl);
int listaSimpleVacia(const t_lista* pl);
int insertarOrdenadoSinDuplicados(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b));

void insertarArchivoBinarioEnListaSimple(FILE* pf, t_lista* pl, void* dato, unsigned tam, int (*comparar)(const void* a, const void* b));

void swapDeNodos(t_nodo** nodo1, t_nodo** nodo2);
t_nodo** direccionDeSigNodoAnteriorAlAzar(t_nodo** base, unsigned cantidadDeElementos);
void mezclarListaSimpleAleatoriamente(t_lista* pl, unsigned cantidadDeElementos);


#endif // LISTASIMPLE_H_INCLUDED
