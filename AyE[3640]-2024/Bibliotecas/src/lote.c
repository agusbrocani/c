#include "../include/lote.h"

void crearLote()
{
    FILE* pf;
    tProducto coleccion[] =
    {
      {"5","9","3",{1,1,2000},{26,7,2024},50,100},
      {"4","9","3",{1,1,2000},{26,7,2024},50,100},
      {"1","9","3",{1,1,2000},{26,7,2024},50,100},
      {"3","9","3",{1,1,2000},{26,7,2024},50,100},
      {"2","9","3",{1,1,2000},{26,7,2024},50,100}
    };

    if(         !abrirArchivo( &pf, "datos.bin", "wb" )         )
    {
        return;
    }

    fwrite( coleccion, sizeof( coleccion ), 1, pf );

    fclose(pf);
}

int comparaProductosPorCodProd( const void* a, const void* b )
{
    return strcmp( ((tProducto*)a)->codProd, ((tProducto*)b)->codProd );
}

void grabarProductos( FILE* archivo, const void* dato )
{
    fprintf( archivo ,"\nCodProd: %s\nDescripcion: %s\nProveedor: %s\nFecha de compra: %d/%d/%d\nFecha de venta: %d/%d/%d\nPrecio de compra: %0.2f\nPrecio de venta: %0.2f\n\n",
           ((tProducto*)dato)->codProd,
           ((tProducto*)dato)->descripcion,
           ((tProducto*)dato)->proveedor,
           ((tProducto*)dato)->fechaDeCompra.dia,
           ((tProducto*)dato)->fechaDeCompra.mes,
           ((tProducto*)dato)->fechaDeCompra.anio,
           ((tProducto*)dato)->fechaDeVenta.dia,
           ((tProducto*)dato)->fechaDeVenta.mes,
           ((tProducto*)dato)->fechaDeVenta.anio,
           ((tProducto*)dato)->precioDeCompra,
           ((tProducto*)dato)->precioDeVenta
           );
}
