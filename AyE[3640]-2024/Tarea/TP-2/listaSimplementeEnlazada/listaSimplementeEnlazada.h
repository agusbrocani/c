///AGUSTIN BROCANI-EZEQUIEL MUÑOZ-LAUTARO VEGA-LUCA ARCE
#ifndef CLASE5_H_INCLUDED
#define CLASE5_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NO_HAY_LUGAR 0
#define LISTA_VACIA 0

#define MENOR(X,Y) (((X) < (Y)) ? (X) : (Y))

#define TAM_NYA 50

typedef struct
{
    int id;
    char nya[TAM_NYA];
    char sexo;
    float salario;
}tEmpleado;

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* pl);
//int insertarAlInicio(t_lista* pl, const void* dato, unsigned tam);
int insertarAlFinal(t_lista* pl, const void* dato, unsigned tam);
//int sacarInicio(t_lista* pl, void* dato, unsigned tam);
int sacarFinal(t_lista* pl, void* dato, unsigned tam);
void mostrarListaEnOrden(const t_lista* pl, void (*mostrar)(const void* dato));
void mostrarListaEnOrdenInverso(const t_lista* pl, void (*mostrar)(const void* dato));
void vaciarLista(t_lista* pl);

void* mapEnListaSimple(const t_lista* pl, void (*accion)(void* dato));

#endif // CLASE5_H_INCLUDED
