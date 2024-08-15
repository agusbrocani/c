#ifndef LISTASIMPLEMENTEENLAZADA_H_INCLUDED
#define LISTASIMPLEMENTEENLAZADA_H_INCLUDED

#include "../lote.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENOR( X, Y ) ( ( X < Y ) ? ( X ) : ( Y ) )
#define CE_PRODUCTOS_A_INSERTAR 15


#define OK 1
#define NO_PUEDO_INSERTAR 0
#define NO_HAY_ELEMENTOS 0
#define HAY_LUGAR 0
#define LISTA_LLENA 1


typedef struct sNodo
{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

void crearLista( tLista* pl );
int insertarAlFinal( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) );
int insertarAlInicio( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) );
void mostrarLista( const tLista* pl, void ( *mostrar )( const void* dato ) );
void vaciarLista( tLista* pl );
int verPrimero( const tLista* pl, void* dato, unsigned tam );
int verUltimo( tLista* pl, void* dato, unsigned tam );
int insertarColeccionEnListaAlInicio( tLista* pl, const void* coleccion, unsigned tam, unsigned ce );
int insertarColeccionEnListaAlFinal( tLista* pl, const void* coleccion, unsigned tam, unsigned ce );
int insertarOrdenadoSinDuplicados( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) );
int insertarOrdenadoAcumuladoDuplicados( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ), void ( *acumular )( void* dato, const void* aAcumular) );
int insertarOrdenado( tLista* pl, const void* dato, unsigned tam, int ( *comparar )( const void* a, const void* b ) );
int insertarEnPosicion( tLista* pl, const void* dato, unsigned tam, unsigned posicion );
int listaLlena( const tLista* pl, unsigned tam );
int listaVacia( const tLista* pl );
int sacarPrimero( tLista* pl, void* dato, unsigned tam );
int sacarUltimo( tLista* pl, void* dato, unsigned tam );

tNodo** buscarMenor( tLista* pl, int (*comparar)( const void* a, const void* b ) );
void ordenarLista( tLista* pl, int (*comparar)( const void* a, const void* b ) );

tNodo** buscarPrimeraAparicion( tLista* pl, const void* clave, int (*comparar)( const void* a, const void* b ) );
tNodo** buscarInfoPorClaveListaOrdenada( tLista* pl, const void* clave, int (*comparar)( const void* a, const void* b ) );
tNodo** buscarInfoPorClaveListaDesordenada( tLista* pl, const void* clave, int (*comparar)( const void* a, const void* b ) );
void mostrarYEliminarDuplicados( tLista* pl, int (*comparar)( const void* a, const void* b ),void (*mostrar)( const void* dato ) );
void actualizarEnLista( tLista* pl, const void* clave, int (*comparar)( const void* a, const void* b ),void (*accion)( void* dato) );

#endif // LISTASIMPLEMENTEENLAZADA_H_INCLUDED
