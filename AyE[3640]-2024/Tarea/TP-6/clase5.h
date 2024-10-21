#ifndef CLASE5_H_INCLUDED
#define CLASE5_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clase3.h"

#define OK 1
#define NO_HAY_LUGAR 0
#define LISTA_VACIA 0

#define NO_SON_IGUALES 0
#define LISTAS_VACIAS -1


typedef t_nodo* t_lista;

void crearLista(t_lista* pl);
int insertarAlFinal(t_lista* pl, const void* dato, unsigned tam);
int sacarFinal(t_lista* pl, void* dato, unsigned tam);
void vaciarLista(t_lista* pl);

void mostrarListaEnOrdenInversoR(const t_lista* pl, void (*mostrar)(const void* dato));
void mostrarListaEnOrdenInverso(const t_lista* pl, void (*mostrar)(const void* dato));

#endif // CLASE5_H_INCLUDED
