#ifndef UNIDAD4TDA_H_INCLUDED
#define UNIDAD4TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESES_DEL_ANIO 12

typedef struct
{
int dia;
int mes;
int anio;
} tFecha;

int esBisiesto(unsigned anio);
int esFechaValida(tFecha* f);


#endif // UNIDAD4TDA_H_INCLUDED
