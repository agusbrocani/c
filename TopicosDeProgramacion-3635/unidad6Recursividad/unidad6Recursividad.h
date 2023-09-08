#ifndef UNIDAD6RECURSIVIDAD_H_INCLUDED
#define UNIDAD6RECURSIVIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define ES_NUMERO(X) (X >= '0' && X <= '9')
#define A_NUMERO(X) ((X >= '0' && X <= '9')? (X - '0') : X)
#define ES_PAR(X) (X % 2 == 0)
#define ES_LETRA(X) (   (           (X>='A') && (X<='Z')            ) || (          (X>='a')&& (X<='z')         )         )
#define A_MAYUS(X)  (   ( (X >= 'a') && (X <= 'z') )     ? (X -('a' - 'A'))  : (X)          )
#define TAM 5

size_t rFactorial(int);
void mostrarContenidoArray(const char*);
void mostrarContenidoArrayInverso(const char*);
void mostrarContenidoArrayInversoYSumaNumeros(const char*, int*);
void contenidoArrayYSuma(const int*, int*, int);
void contenidoArrayYSumaPares(const int*, int*, int);
void contenidoArrayYSumaPosPares(const int*, int*, int);
size_t rStrlen(const char*);
char* rStrchr(char*, int);
char* rStrrchr(char*, int);
char* rStrcpy(char*, const char*);
int esPalindromo(const char*);
int rEsPalindromo(const char*, const char*, const char*);
unsigned short rCalcularCoeficienteTrianguloTartaglia(int n, int k);

#endif // UNIDAD6RECURSIVIDAD_H_INCLUDED
