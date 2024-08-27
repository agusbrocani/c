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

#define ES_NUMERO( X ) ( ( ( X ) >= '0' ) && ( ( X ) <= '9' ) )
#define A_NUMERO( X ) ( ( X ) - '0' )

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
void ejercicio2( double operando1, double operando2 );

void grabarEntero( FILE* pf, const void* dato );
void grabarPersona( FILE* pf, const void* dato );
void crearLoteTxtGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) );

void crearLoteNumerosEnArchivoDeTexto( const char* nombreArchivo );

int comparaEnteros( const void* a, const void* b );
void ejercicio3();

int comparaPersonasPorID( const void* a, const void* b );
void trozar( char* buffer, tPersona* dato );
void ejercicio4();

void ejercicio5( void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) );

void crearLoteBinGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) );
void ejercicio6( void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) );

size_t mStrlenR( const char* cadena );
char* mStrchrR( char* s, int c );
char* mStrrchrRC( char* ini, char* fin, int c );
char* mStrrchrR( char* s, int c );
int factorial( int n );
void mostrarEnOrdenR( const char* cadena );
void mostrarEnOrdenInversoR( const char* cadena );
void mostrarConFormatoEspecialMueveInicioR( const char* cadena );
void mostrarConFormatoEspecialMueveInicioOrdenInversoR( const char* cadena );
void mostrarConFormatoEspecialMueveFinRC2( const char* ini, const char* fin );
void mostrarConFormatoEspecialMueveFinRC( const char* ini, const char* fin,unsigned cantidadDeCaracteresExtraAMostrar );
void mostrarConFormatoEspecialMueveFinR( const char* cadena );
void mostrarConFormatoEspecialMueveFinOrdenInversoRC2( const char* ini, const char* fin );
void mostrarConFormatoEspecialMueveFinOrdenInversoRC( const char* ini, const char* fin,unsigned cantidadDeCaracteresExtraAMostrar );
void mostrarConFormatoEspecialMueveFinOrdenInversoR( const char* cadena );
void mostrarEnteroDescompuestoR( int entero );
void mostrarEnteroDescompuestoOrdenInversoR( int entero );
void mostrarEnteroDisminuyendoR( int entero );
void mostrarEnteroDisminuyendoOrdenInversoR( int entero );
void mostrarEnteroCreciendoRC( int entero, int divisor );
void mostrarEnteroCreciendoR( int entero );
void mostrarEnteroCreciendoOrdenInversoRC( int entero, int divisor );
void mostrarEnteroCreciendoOrdenInversoR( int entero );
void mostrandoSumaDigitosEnteroRC( int entero, int divisor, int* suma );
void mostrandoSumaDigitosEnteroR( int entero );
void mostrandoSumaCaracteresDigitosEnteroRC( const char* cadena, int* suma );
void mostrandoSumaCaracteresDigitosEnteroR( const char* cadena );
void mostrarArrayEnterosYSuSumaIRC( int* vectorDeEnteros, unsigned ce, int* suma );
void mostrarArrayEnterosYSuSumaIR( int* vectorDeEnteros, unsigned ce );
void mostrarArrayEnterosYSuSumaDigitosParesIRC( int* vectorDeEnteros, unsigned ce, int* suma );
void mostrarArrayEnterosYSuSumaDigitosParesIR( int* vectorDeEnteros, unsigned ce );
void mostrarArrayEnterosYSuSumaDigitosEnPosParesIRC( int* vectorDeEnteros, unsigned ce, int* suma, unsigned pos );
void mostrarArrayEnterosYSuSumaDigitosEnPosParesIR( int* vectorDeEnteros, unsigned ce );

void ejercicio7();



#endif // UNIDAD0_H_INCLUDED
