#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lista.h"

void crearListaCircular(t_lista* pl);
int insertarSegundoEnListaCircular(t_lista* pl, const void* dato, unsigned tam);
int sacarSiguienteDelPrimeroListaCircular(t_lista* pl, void* dato, unsigned tam);
void vaciarListaCircular(t_lista *pl);
int listaCircularVacia(const t_lista *pl);
void mostrarListaCircular(const t_lista* pl, void (*mostrar)(const void* dato));
void cambiarNodosDeLugarEnListaCircular(t_lista* pl);

#endif // LISTACIRCULAR_H_INCLUDED
