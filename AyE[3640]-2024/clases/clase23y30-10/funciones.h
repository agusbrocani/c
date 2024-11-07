#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NO_PUDE_RESERVAR_MEMORIA 0
#define DATO_DUPLICADO -1

typedef struct s_nodo
{
        void* dato;
        unsigned tam;
        struct s_nodo* izq;
        struct s_nodo* der;
}t_nodo;

typedef t_nodo* t_arbol;

void crearArbol(t_arbol* a);
void recorrerEnPreOrden(const t_arbol* a, void (*accion)(void* dato));
void recorrerEnOrden(const t_arbol* a, void (*accion)(void* dato));
void recorrerEnPosOrden(const t_arbol* a, void (*accion)(void* dato));

int insertarEnArbol(t_arbol* a, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*acumular)(void* datoArbol, const void* dato));
int insertarEnArbolIterativo(t_arbol* a, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*acumular)(void* datoArbol, const void* dato));
int contarNodos(const t_arbol* a);
int contarHojas(const t_arbol* a);

int podarHojas(t_arbol* a);
void vaciarArbol(t_arbol* a);

#endif // FUNCIONES_H_INCLUDED
