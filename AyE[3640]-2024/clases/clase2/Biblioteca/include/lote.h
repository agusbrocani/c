#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED
#include <stdio.h>

#define TAM_NYA 100
#define T_ENTERO 1
#define T_EMPLEADO 2

typedef struct
{
    int id;
    char nya[TAM_NYA];
    char sexo;
    float salario;
}tEmpleado;

void grabarEmpleado( FILE* pf,const void* dato );
void grabarEntero( FILE* pf, const void* dato );
void grabar( FILE* pf, const void* dato, int opcion );
void mostrarColeccion( const void* dato, unsigned tam, unsigned ce, void (*mostrar)( const void* dato ) );

#endif // LOTE_H_INCLUDED
