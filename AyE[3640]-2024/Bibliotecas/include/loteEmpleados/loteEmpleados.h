#ifndef LOTEEMPLEADOS_H_INCLUDED
#define LOTEEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CE_EMPLEADOS 30
#define TAM_NYA 100
typedef struct
{
    int id;
    char nya[TAM_NYA];
    char sexo;
    float salario;
}tEmpleado;


void cargaEmpleadosAVector(tEmpleado* dondeCopioLote);
void mostrarEmpleado(const void* dato);
int comparaEmpleadosPorID(const void* a, const void* b);

#endif // LOTEEMPLEADOS_H_INCLUDED
