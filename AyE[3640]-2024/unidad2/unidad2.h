#ifndef UNIDAD2_H_INCLUDED
#define UNIDAD2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include "../Bibliotecas/include/pila/Dinamica/pila.h"
//#include "../Bibliotecas/include/pila/Estatica/pila.h"
#include "../Bibliotecas/include/lote.h"
#include "../Bibliotecas/include/generico.h"
#include "../Bibliotecas/include/menu/menu.h"

#define NOMBRE_ARCHIVO_BINARIO "datos.bin"

#define OPCION_1 1
#define OPCION_2 2
#define OPCION_3 3
#define OPCION_4 4
#define OPCION_5 5
#define OPCION_6 6
#define OPCION_7 7

void cargarProductosAArchivoBinario();
void switchMenu4y5(int opcion, void* parametro);
void opcion4y5();
void ordenarDatosArchivoConDosPilas();
void sumarEnterosDesde2Archivos();

void switchMenu(int opcion, void* parametro);


#endif // UNIDAD2_H_INCLUDED
