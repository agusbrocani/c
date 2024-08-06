#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "../include/generico.h"

#define TAM_COD_PROD 8
#define TAM_DESC_Y_PROV 16

typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct
{
    char codProd[TAM_COD_PROD];
    char descripcion[TAM_DESC_Y_PROV];
    char proveedor[TAM_DESC_Y_PROV];
    tFecha fechaDeCompra;
    tFecha fechaDeVenta;
    float precioDeCompra;
    float precioDeVenta;
}tProducto;

void crearLote();
int comparaProductosPorCodProd( const void* a, const void* b );
void grabarProductos( FILE* archivo, const void* dato );

#endif // LOTE_H_INCLUDED
