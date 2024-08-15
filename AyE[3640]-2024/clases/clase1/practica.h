#ifndef PRACTICA_H_INCLUDED
#define PRACTICA_H_INCLUDED
#include <stdio.h>
#include <string.h>

#define TAM_NOMBRE 50
#define TAM_CARRERA 50

#define NO_PUDE_CREAR_ABRIR_ARCHIVO 0
#define OK 1

#define TAM_BUFFER 1000

//struct fecha
//{
//    unsigned dia;
//    unsigned mes;
//    unsigned anio;
//};

typedef struct
{
    unsigned dia;
    unsigned mes;
    unsigned anio;
}tFecha;

typedef struct
{
    char nombre[TAM_NOMBRE];
    unsigned edad;
    char carrera[TAM_CARRERA];
}tAlumno;

void mostrarAlumno( const void* dato );
void mostrarEntero( const void* dato );
void mostrarLetra( const void* dato );
void mostrarColeccion( const void* coleccion, unsigned tam, unsigned ce, void (*mostrar)( const void* dato ) );

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();

#endif // PRACTICA_H_INCLUDED
