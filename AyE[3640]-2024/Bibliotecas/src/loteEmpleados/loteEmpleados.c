#include "../../include/loteEmpleados/loteEmpleados.h"

void cargaEmpleadosAVector(tEmpleado* dondeCopioLote)
{
    tEmpleado empleados[CE_EMPLEADOS] =
    {
        {14, "Gabriela Ortega", 'F', 1550000},
        {5, "Carla Fernandez", 'F', 900000},
        {7, "Daniela Herrera", 'F', 980000},
        {19, "Luis Silva", 'M', 1800000},
        {30, "Valeria Barrera", 'F', 2900000},
        {4, "Carlos Delgado", 'M', 850000},
        {12, "Esteban Moreno", 'M', 1400000},
        {22, "Natalia Vargas", 'F', 1950000},
        {25, "Pablo Ximenez", 'M', 2100000},
        {1, "Agustin Brocani", 'M', 650000},
        {15, "Gabriel Perez", 'M', 1600000},
        {16, "Juliana Quiroga", 'F', 1650000},
        {11, "Emilia Martinez", 'F', 1300000},
        {8, "David Ibarra", 'M', 1100000},
        {21, "Martin Uribe", 'M', 1900000},
        {20, "Marta Torres", 'F', 1850000},
        {6, "Claudia Gomez", 'F', 920000},
        {27, "Rodrigo Zambrano", 'M', 2250000},
        {9, "Diana Juarez", 'F', 1150000},
        {2, "Ana Benitez", 'F', 720000},
        {3, "Ariel Castro", 'M', 780000},
        {13, "Federico Martucci", 'M', 1500000},
        {17, "Julian Rodriguez", 'M', 1700000},
        {24, "Patricia Wallace", 'F', 2050000},
        {28, "Silvia Zuniga", 'F', 2300000},
        {29, "Santiago Araujo", 'M', 2500000},
        {18, "Laura Sanchez", 'F', 1750000},
        {10, "Eduardo Lopez", 'M', 1200000},
        {23, "Nicolas Villegas", 'M', 2000000},
        {26, "Rosa Yanez", 'F', 2200000}
    };

    memcpy(dondeCopioLote, empleados, CE_EMPLEADOS * sizeof(tEmpleado));
}


void mostrarEmpleado(const void* dato)
{
    printf("ID: %d\nNya: %s\nSexo: %c\nSalario: %.2f\n\n",
            ((tEmpleado*)dato)->id,
            ((tEmpleado*)dato)->nya,
            ((tEmpleado*)dato)->sexo,
            ((tEmpleado*)dato)->salario
            );
}

int comparaEmpleadosPorID(const void* a, const void* b)
{
    return ((tEmpleado*)a)->id - ((tEmpleado*)b)->id;
}
