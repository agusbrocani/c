#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define SIN_MEMORIA 1
#define LISTA_VACIA 1
#define NO_SE_ENCONTRO 2
#define DUPLICADO 2
#define MINIMO(x,y) ((x < y) ? x : y)

typedef struct s_nodoDoble
{
    struct s_nodoDoble *ant;
    unsigned tam;
    void *dato;
    struct s_nodoDoble *sig;
} t_nodoDoble;

typedef t_nodoDoble *t_listaDoble;

void crearLista (t_listaDoble*);
int insertarEnListaDoble (t_listaDoble*, void*, unsigned, int (void*, void*));
int eliminarEnListaDobleSinDuplicados (t_listaDoble*, void*, void*, unsigned, int (void*, void*));
int recorrerListaDobleMenorAMayor (t_listaDoble*, void (void*));
void vaciarListaDoble (t_listaDoble*);

#endif // LISTADOBLE_H_INCLUDED
