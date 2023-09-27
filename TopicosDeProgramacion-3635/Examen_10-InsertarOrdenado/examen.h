#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_F 5
#define MAX_C 1025

#define MAYOR(X,Y) (((X) > (Y)) ? (X) : (Y))
#define MENOR(X,Y) (((X) < (Y)) ? (X) : (Y))


char* obtenerFrase(char* frase);

int comparaCadenas(const void* cadena1, const void* cadena2);
void top5Frases(char mat[][MAX_C],unsigned* cantFrases, int (*comparar)(const void* a,const void* b));
void miInsertarOrdenado(char mat[][MAX_C],unsigned* cantFrases,const char* frase, int (*comparar)(const void* a, const void* b));
void mostrarFrases(char mat[][MAX_C],unsigned cantFrases);

#endif // EXAMEN_H_INCLUDED
