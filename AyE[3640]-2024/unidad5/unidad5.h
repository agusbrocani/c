#ifndef UNIDAD5_H_INCLUDED
#define UNIDAD5_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../clases/clase5/clase5.h"

#define ES_LETRA(X) (((X) >= 'A' && (X) <= 'Z') || ((X) >= 'a' && (X) <= 'z'))
#define A_MAYUS(X) (((X) >= 'a' && (X) <= 'z') ? ((X) - ('a' - 'A')) : (X))

#define ERROR_MATEMATICO -2147483648

#define ES_PALINDROMO 1
#define NO_ES_PALINDROMO 0

float calculaPotenciaR(float base, float exponente);

int calculaProductoDeDosEnterosRC(int numero1, int numero2);
int calculaProductoDeDosEnterosR(int numero1, int numero2);

int fibonacciRC(int primerTermino, int segundoTermino, int numeroDeTermino);
int fibonacciR(int numeroDeTermino);

void decimalABinarioR(unsigned numeroAConvertir);

int funcionAckermannR(int m, int n);

void* mBsearch(const void* clave, const void* base, size_t ce, size_t tam, int (*comparar)(const void* a, const void* b));

int esPalindromoRC(const char* ini, const char* fin);
size_t mStrlenR(const char* cadena);
int esPalindromoR(const char* cadena);

#endif // UNIDAD5_H_INCLUDED
