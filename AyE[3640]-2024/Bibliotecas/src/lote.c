#include "../include/lote.h"

void crearLoteProductosBinario()
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

    if(         !abrirArchivo( &pf, NOMBRE_ARCHIVO_PRODUCTOS, "wb" )         )
    {
        return;
    }

    fwrite( coleccion, sizeof( coleccion ), 1, pf );

    fclose(pf);
}

int comparaProductosPorCodProd( const void* a, const void* b )
{
//    return strcmp( ((tProducto*)a)->codProd, ((tProducto*)b)->codProd );
    return atoi( ((tProducto*)a)->codProd ) - atoi( ((tProducto*)b)->codProd );
}

void grabarProductos( FILE* archivo, const void* dato )
{
    fprintf( archivo ,"CodProd: %s\nDescripcion: %s\nProveedor: %s\nFecha de compra: %d/%d/%d\nFecha de venta: %d/%d/%d\nPrecio de compra: %0.2f\nPrecio de venta: %0.2f\n",
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

    if(         stdout == archivo           )
    {
        printf("\n");
    }
}

void mostrarProducto( const void* dato )
{
    grabarProductos( stdout, dato );
}

void cargarProductos( tProducto* productos, unsigned ce )
{
    tProducto lote[CE_PRODUCTOS] =
    {
        {"5","Coca-Cola 2L","Coca-Cola Company",{1,1,2024},{26,7,2024},50.0,100.0},
        {"9","Pan Bimbo Integral","Bimbo",{2,2,2024},{27,7,2024},60.0,110.0},
        {"3","Detergente Ariel 1kg","Procter & Gamble",{3,3,2024},{28,7,2024},70.0,120.0},
        {"1","Leche La Serenisima 1L","La Serenisima",{4,4,2024},{29,7,2024},80.0,130.0},
        {"3","Detergente Ariel 1kg","Procter & Gamble",{3,3,2024},{28,7,2024},70.0,120.0},
        {"4","Aceite Natura 900ml","Natura",{5,5,2024},{30,7,2024},90.0,140.0},
        {"2","Galletas Oreo 150g","Mondelez",{6,6,2024},{31,7,2024},100.0,150.0},
        {"5","Coca-Cola 2L","Coca-Cola Company",{1,1,2024},{26,7,2024},50.0,100.0},
        {"6","Arroz Gallo 1kg","Molinos Rio de la Plata",{7,7,2024},{1,8,2024},110.0,160.0},
        {"4","Aceite Natura 900ml","Natura",{5,5,2024},{30,7,2024},90.0,140.0},
        {"8","Papel Higienico Elite 4 Rollos","Elite",{8,8,2024},{2,8,2024},120.0,170.0},
        {"7","Jugo Tang Naranja 20g","Mondelez",{9,9,2024},{3,8,2024},130.0,180.0},
        {"10","Cereal Kellogg's Corn Flakes 500g","Kellogg's",{10,10,2024},{4,8,2024},140.0,190.0},
        {"2","Galletas Oreo 150g","Mondelez",{6,6,2024},{31,7,2024},100.0,150.0},
        {"11","Cafe Nescafe Dolca 170g","Nestle",{11,11,2024},{5,8,2024},150.0,200.0}
    };

    memcpy( productos, lote, sizeof( tProducto ) * ce );
}
