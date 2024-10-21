#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaDoble.h"

typedef struct
{
    int legajo;
    char nombre [21];
    char apellido [21];
    char sector;
    float sueldo;
} t_empleado;

int cmpLegajoEmpleado (void*, void*);
void mostrarEmpleado (void*);

#endif // MAIN_H_INCLUDED
