#ifndef UNIDAD4_H_INCLUDED
#define UNIDAD4_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listaSimple.h"

#define NO_PUDE_ABRIR_DATOS1 1
#define NO_PUDE_ABRIR_DATOS2 2
#define NO_PUDE_ABRIR_ERRORES2 3

void accionParaDuplicados(void* dato, void* datoAAcumular);
int compararPorFechaDeVentaProveedorClave(const void* a, const void* b);


#endif // UNIDAD4_H_INCLUDED
