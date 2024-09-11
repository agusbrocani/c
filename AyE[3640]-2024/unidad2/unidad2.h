#ifndef UNIDAD2_H_INCLUDED
#define UNIDAD2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Bibliotecas/include/pila/Dinamica/pila.h"
//#include "../Bibliotecas/include/pila/Estatica/pila.h"
#include "../Bibliotecas/include/generico.h"
#include "../Bibliotecas/include/lote.h"
#include "../Bibliotecas/include/menu/menu.h"
#include "../Bibliotecas/include/loteEmpleados/loteEmpleados.h"
#include "../Bibliotecas/include/loteEmpleados/archivoEmpleados.h"
#include "../Bibliotecas/include/pila/ordenarConDosPilas.h"
#include "../Bibliotecas/include/pila/SumarEnterosConDosPilas.h"

#define NOMBRE_ARCHIVO_BINARIO "datos.bin"

///MENU PRINCIPAL
#define OPCION_1 1
#define OPCION_2 2
#define OPCION_3 3
#define OPCION_4 4
#define OPCION_5 5
#define OPCION_6 6
#define OPCION_7 7

///SUBMENU PUNTO 4 Y 5
#define APILAR_4_Y_5 1
#define VER_TOPE_4_Y_5 2
#define DESAPILAR_4_Y_5 3


///SUBMENU ORDENAR CON 2 PILAS GENERICO
#define VER_ARCHIVO_DESORDENADO 1
#define LOTE_TEXTO_LF 2
#define LOTE_TEXTO_LV 3
#define LOTE_BINARIO 4

#define NOMBRE_ARCHIVO_LOTE_TEXTO_LV "empleadoslv.txt"
#define NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO "empleadoslv-ordenado.txt"

#define NOMBRE_ARCHIVO_LOTE_TEXTO_LF "empleadoslf.txt"
#define NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO "empleadoslf-ordenado.txt"

#define NOMBRE_ARCHIVO_LOTE_BINARIO "empleados.bin"
#define NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO "empleados-ordenado.bin"

#define NOMBRE_ARCHIVO_NUMERO1 "numero1.txt"
#define NOMBRE_ARCHIVO_NUMERO2 "numero2.txt"
#define NOMBRE_ARCHIVO_RESULTADO "resultado.txt"

#define A_NUMERO( X ) ( ( X ) - '0' )

typedef struct
{
    tPila* p;
    tProducto producto;
    unsigned tam;
    tProducto productos[CE_PRODUCTOS];
}tPilaCargada;

void cargarProductosAArchivoBinario();
void switchMenu4y5(int opcion, void* parametro);
void opcion4y5();

void switchMenuOrdenarArchivoConDosPilas(int opcion, void* parametro);
void loteTextoLF(const void* coleccion, unsigned tam, unsigned ce);
void loteTextoLV(const void* coleccion, unsigned tam, unsigned ce);
void loteBinario(const void* coleccion, unsigned tam, unsigned ce);
void ordenarDatosArchivoConDosPilas();

void crearLoteNumero(const char* nombreArchivo, const char* numero);
void grabarEntero(FILE* pf, const void* dato);
void sumarEnterosDesdeDosArchivos();

void switchMenu(int opcion, void* parametro);


#endif // UNIDAD2_H_INCLUDED
