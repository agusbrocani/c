#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM_BUFFER_CARGA_CONFIGURACIONES 11///cantidad maxima de caracteres posibles contando \0
#define MIN_CANT_VIDAS 0
#define MAX_CANT_VIDAS 5
#define MIN_TIEMPO_JUEGO_POR_RONDA 0
#define MAX_TIEMPO_JUEGO_POR_RONDA 20

#define OK 1

void mostrarConfiguracionElegida(tConfiguracion* configuracion, unsigned indiceDeNivelDeConfiguracionElegida);
int cargarConfiguraciones(FILE* aConfiguracion, tConfiguracion* configuraciones);

#endif // CONFIGURACIONES_H_INCLUDED
