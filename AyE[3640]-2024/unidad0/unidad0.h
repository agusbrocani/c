#ifndef UNIDAD0_H_INCLUDED
#define UNIDAD0_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../Bibliotecas/include/TDAVector/Estatico/TDAVector.h"
#include "../Bibliotecas/include/TDAVector/Dinamico/TDAVector.h"
#include "../Bibliotecas/include/generico.h"

#define NO_PUEDO_DIVIDIR_POR_CERO 0
#define TAM_BUFFER 1000
#define TAM_NYA 100

#define NO_PUEDO_CALCULAR_EL_FACTORIAL_DE_NEGATIVOS 0

#define OK 1

typedef struct
{
    int id;
    char nya[TAM_NYA];
    char sexo;
    float salario;
}tPersona;

double sumar( double operando1, double operando2 );
double restar( double operando1, double operando2 );
double multiplicar( double operando1, double operando2 );
double dividir( double operando1, double operando2 );
double calcular( double operando1, double operando2, double (*operacion)( double operando1, double operando2 ) );
void ejercicio2();

void grabarEntero( FILE* pf, const void* dato );
void grabarPersona( FILE* pf, const void* dato );
void crearLoteTxtGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) );

void crearLoteNumerosEnArchivoDeTexto( const char* nombreArchivo );

int comparaEnteros( const void* a, const void* b );
void ejercicio3();

int comparaPersonasPorID( const void* a, const void* b );
void trozar( char* buffer, tPersona* dato );
void ejercicio4();

void ejercicio5( const void* nombreArchivo, void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) );

void crearLoteBinGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) );
void ejercicio6( const void* nombreArchivo, void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) );

void ejercicio7();



#endif // UNIDAD0_H_INCLUDED
