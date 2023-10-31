#ifndef UNIDAD3PASAJEPARAMETROS_H_INCLUDED
#define UNIDAD3PASAJEPARAMETROS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LI 1
#define LS 4

int comparaEnteros(const void* a,const void* b);
void* buscarMenor(const void* vec,void* menor,unsigned tam, unsigned ce, int (*comparar)(const void* a, const void* b));

int opcionValida(int opcion);
void ingresaOpcion(int* opcion);


void opcionUno(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b));
void opcionDos(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b));
void opcionTres(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b));
int menu(const void* vec);

#endif // UNIDAD3PASAJEPARAMETROS_H_INCLUDED
