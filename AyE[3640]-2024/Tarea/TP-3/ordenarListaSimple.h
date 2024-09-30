#ifndef ORDENARLISTASIMPLE_H_INCLUDED
#define ORDENARLISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listaSimple.h"

typedef struct
{
    int codigo;
    int cantidad;
    float precio;
}tProducto;

void mostrarProducto(const void* dato);
int comparaProductos(const void* a, const void* b);

t_nodo** buscarMenor (t_lista *pl, int (*comparar)(const void* a, const void* b));
void ordenarLista (t_lista *pl, int (*comparar)(const void* a, const void* b));

#endif // ORDENARLISTASIMPLE_H_INCLUDED
