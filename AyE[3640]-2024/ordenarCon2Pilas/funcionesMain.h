#ifndef FUNCIONESMAIN_H_INCLUDED
#define FUNCIONESMAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Bibliotecas/include/menu/menu.h"
#include "./Bibliotecas/include/generico.h"
#include "./Bibliotecas/include/loteEmpleados/archivoEmpleados.h"
#include "./Bibliotecas/include/loteEmpleados/loteEmpleados.h"
#include "./Bibliotecas/include/pila/ordenarCon2Pilas.h"


#define LOTE_TEXTO_LF 1
#define LOTE_TEXTO_LV 2
#define LOTE_BINARIO 3


#define NOMBRE_ARCHIVO_LOTE_TEXTO_LV "empleadoslv.txt"
#define NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO "empleadoslv-ordenado.txt"

#define NOMBRE_ARCHIVO_LOTE_TEXTO_LF "empleadoslf.txt"
#define NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO "empleadoslf-ordenado.txt"

#define NOMBRE_ARCHIVO_LOTE_BINARIO "empleados.bin"
#define NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO "empleados-ordenado.bin"

void fSwitchMenu(int opcion);
void loteTextoLF(const void* coleccion, unsigned tam, unsigned ce);
void loteTextoLV(const void* coleccion, unsigned tam, unsigned ce);
void loteBinario(const void* coleccion, unsigned tam, unsigned ce);

#endif // FUNCIONESMAIN_H_INCLUDED
