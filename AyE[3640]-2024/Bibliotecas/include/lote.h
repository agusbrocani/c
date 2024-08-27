#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "../include/generico.h"

#define TAM_COD_PROD 800
#define TAM_DESC_Y_PROV 1600

#define NOMBRE_ARCHIVO_PRODUCTOS "loteProductos.bin"

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

void crearLoteProductos();
int comparaProductosPorCodProd( const void* a, const void* b );
void mostrarProducto( const void* dato );
void grabarProductos( FILE* archivo, const void* dato );
void cargarProductos( tProducto* productos, unsigned ce );


#endif // LOTE_H_INCLUDED
