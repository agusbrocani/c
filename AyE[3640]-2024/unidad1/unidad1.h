#ifndef UNIDAD1_H_INCLUDED
#define UNIDAD1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotecas/include/menu/menu.h"

#define TAM_MAX 1000

void mostrarCadena(const void* dato);
void mostrarVectorDeCadenas(char mat[][TAM_MAX], unsigned cantidadDeRegistros, void(*mostrar)(const void* dato));
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();

#endif // UNIDAD1_H_INCLUDED
