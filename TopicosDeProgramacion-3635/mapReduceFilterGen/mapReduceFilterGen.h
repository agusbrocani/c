#ifndef MAPREDUCEFILTERGEN_H_INCLUDED
#define MAPREDUCEFILTERGEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarEntero(const void* dato);
void mostrarFloat(const void* dato);

void recorrerVector(const void* vec, size_t tam, size_t ce, void (*mostrar) (const void* dato));
int comparaEntero(const void* a, const void* b);
void* buscarMenor(const void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b));
void* buscarMayor(const void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b));
void intercambio(void* a, void* b, size_t tam);
void ordenarSeleccionAscendente(void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b));
void ordenarSeleccionDescendente(void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b));

void acc(void* resultado,const void* dato);
void promedio(void* a,const void* b);

void fMap(const void* vec, size_t tam, size_t ce, void (*accion) (void* resultado,const void* dato),void (*mostrar)(const void* resultado));
void filter(const void* vec,const void* filtro, size_t tam, size_t ce, int (*comparar) (const void* a,const void* b),void (*mostrar)(const void* resultado));
void reduce(const void* vec, size_t tam, size_t ce, void (*accion) (void* a,const void* b),void (*mostrar)(const void* resultado));

#endif // MAPREDUCEFILTERGEN_H_INCLUDED
