#include "unidad4.h"

/**
 Los archivos deben resultar ordenados por fecha de vencimiento,
 y a igualdad del mismo por proveedor y clave.

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
*/

void accionParaDuplicados(void* dato, void* datoAAcumular)
{
    ///NO HAGO NADA
}

int compararPorFechaDeVentaProveedorClave(const void* a, const void* b)
{
    int cmp;

    cmp = ((tProducto*)a)->fechaDeVenta.anio - ((tProducto*)b)->fechaDeVenta.anio;
    if(!cmp)
    {
        cmp = ((tProducto*)a)->fechaDeVenta.mes - ((tProducto*)b)->fechaDeVenta.mes;
        if(!cmp)
        {
            cmp = ((tProducto*)a)->fechaDeVenta.dia - ((tProducto*)b)->fechaDeVenta.dia;
            if(!cmp)
            {
                cmp = strcmpi(((tProducto*)a)->proveedor, ((tProducto*)b)->proveedor);
                if(!cmp)
                {
                    cmp = strcmpi(((tProducto*)a)->codProd, ((tProducto*)b)->codProd);
                }
            }
        }
    }

    return cmp;
}






