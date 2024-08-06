#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CE_ELEMENTOS_RESERVADOS_POR_DEFECTO 10

#define OK 1
#define NO_PUEDO_VER_ELEMENTO 0
#define NO_HAY_LUGAR 0
#define NO_PUEDO_ELIMINAR 0

typedef struct
{
    void* vec;
    unsigned tamDato;           ///Si NO es de 1 solo tipo de dato, no es un vector en C, es otra cosa
    unsigned tamDisponible;     ///COMO RESERVAR MEMORIA Y REALOCAR ES COSTOSO, VOY A PEDIR MEMORIA PARA 10 ELEMENTOS  POR CADA VEZ
    unsigned tamReservado;
}tVector;

void crearVector( tVector* v, unsigned tam );
int vectorVacio( const tVector* v );
int vectorLleno( const tVector* v );
int verElementoEnPosicionDada( const tVector* v, void* dato, unsigned posicion );
int eliminarElementoEnPosicion( tVector* v, void* dato, unsigned posicion, unsigned* ce );
void destruirVector( tVector* v );
int insertarOrdenado( tVector* v, const void* dato, unsigned* ce, int (*comparar)( const void* a, const void* b ) );


#endif // TDAVECTOR_H_INCLUDED
