#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaSimple.h"

#define SALIR 0
#define ORDEN_ASC 1
#define ORDEN_DESC 2

#define LI SALIR
#define LS ORDEN_DESC

#define NO_PUDE_ABRIR_CREAR_ARCHIVO 0
#define NOMBRE_ARCHIVO_LOTE "lote.dat"
#define NOMBRE_ARCHIVO_LOTE_ORDENADO "loteOrdenado.txt"

#define NO_PUDE_ABRIR_ARCHIVO_LOTE 1
#define NO_PUDE_CREAR_ARCHIVO_LOTE_ORDENADO 1

#define TAM_LOCALIDAD 51

typedef struct
{
    int provincia;
    char localidad[TAM_LOCALIDAD];
    float superficie;
    int poblacion;
}tLote;

typedef struct
{
    int provincia;
    float superficieTotal;
    int cantidadTotalDeHabilitantes;
    float densidadDePoblacion;
}tLoteOrdenado;

int abrirArchivo(FILE** pf, const char* nombreArchivo, const char* modo);

void crearLote();
void grabarLote(FILE* pf, const void* dato);
void grabarLoteOrdenado(FILE* pf, const void* dato);
int compararEnteros(const void* a, const void* b);
int compararProvinciasASC(const void* a, const void* b);
int compararProvinciasDESC(const void* a, const void* b);

void acumularSuperficieYPoblacion(void* dato, const void* datoAInsertar);
void generarInformeTxtOrdenado(FILE* archivoLoteOrdenado, t_lista* lista);

void textoMenu();
int ingresoOpcion();
void mostrarLote(void* dato, void* recursos);
void cargarListaDesdeLoteBinario(FILE* archivoLote, t_lista* lista, int (*comparar)(const void* a, const void* b));
void menu(FILE* archivoLote, FILE* archivoLoteOrdenado);

#endif // FUNCIONES_H_INCLUDED
