#ifndef CLASE6_H_INCLUDED
#define CLASE6_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../../unidad4/listaSimple.h"

#define CLAVE_INEXISTENTE -1

typedef struct
{
    int codigo;
    int cantidad;
    float precio;
}tProducto;

void mostrarProducto(const void* dato);
int comparaProductos(const void* a, const void* b);
void sumarStock(void* dato, void* clave);
void sumarStockV2(void* dato, const void* clave);

int eliminarPorClaveOrd(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b));
void eliminarPorClaveDupConAccion(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* clave));
int eliminarPorClaveDesord(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b));
void eliminarAparicionesDeClave(t_lista* pl, void* clave, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* clave));
void eliminarAparicionesEnListaOrdenadaConDuplicados(t_lista* pl, int (*comparar)(const void* a, const void* b));
void eliminarAparicionesEnListaDesordenadaConDuplicados(t_lista* pl, int (*comparar)(const void* a, const void* b));
void eliminarRegistrosSinDuplicarAcumulandoRegistrosDuplicados(t_lista* pl, int (*comparar)(const void* a, const void* b),void (*accion)(void* aAcumular, const void* dato));

#endif // CLASE6_H_INCLUDED
