#ifndef UNIDAD3_H_INCLUDED
#define UNIDAD3_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Bibliotecas/include/cola/Dinamica/cola.h"
//#include "../Bibliotecas/include/cola/Estatica/cola.h"
#include "../clases/clase3/clase3.h"

#include "../Bibliotecas/include/generico.h"
#include "../Bibliotecas/include/lote.h"
#include "../Bibliotecas/include/menu/menu.h"
#include "../Bibliotecas/include/loteEmpleados/loteEmpleados.h"
#include "../Bibliotecas/include/loteEmpleados/archivoEmpleados.h"

#define NOMBRE_ARCHIVO_BINARIO "datos.bin"
#define NOMBRE_ARCHIVO_BINARIO_D1 "datos1.bin"
#define NOMBRE_ARCHIVO_BINARIO_D2 "datos2.bin"


///MENU PRINCIPAL
#define OPCION_1 1
#define OPCION_2 2
#define OPCION_3 3
#define OPCION_4 4
#define OPCION_5 5
#define OPCION_6 6
#define OPCION_7 7

///SUBMENU PUNTO 4 Y 5
#define ACOLAR_4_Y_5 1
#define VER_PRIMERO_4_Y_5 2
#define DESACOLAR_4_Y_5 3

typedef struct
{
    tCola* c;
    tProducto producto;
    unsigned tam;
    tProducto productos[CE_PRODUCTOS];
}tColaCargada;

void cargarProductosAArchivoBinario();
void switchMenu(int opcion, void* parametro);
void switchMenu4y5(int opcion, void* parametro);
void opcion4y5();
void grabarDosArchivos();

#endif // UNIDAD3_H_INCLUDED
