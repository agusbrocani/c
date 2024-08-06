#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VECTOR 400000
#define OK 1
#define VECTOR_VACIO 0
#define NO_PUEDO_ELIMINAR 0
#define NO_HAY_LUGAR 0

typedef struct
{
    char vec[TAM_VECTOR];   //VEC + TAM_VECTOR - 1  => ULTIMA POSICION VALIDA PARA INSERTAR ALGO
    unsigned tamDato;
    unsigned tamDisponible;
}tVector;

void crearVector( tVector* v, unsigned tam );
int vectorVacio( const tVector* v );
int vectorLleno( const tVector* v );
int verElementoEnPosicionDada( const tVector* v, void* dato, unsigned posicion );
int eliminarElementoEnPosicion( tVector* v, void* dato, unsigned posicion, unsigned* ce );
void destruirVector( tVector* v );
int insertarOrdenado( tVector* v, const void* dato, unsigned* ce, int (*comparar)( const void* a, const void* b ) );


#endif // TDAVECTOR_H_INCLUDED
