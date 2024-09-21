#include "clase6.h"

int main()
{
//    tProducto productos[] =
//    {
//        {1,10,9999},
//        {2,20,8888},
//        {3,30,1000},
//        {3,30,2000},
//        {3,30,3000},
//        {3,30,4000},
//        {4,40,6666},
//        {5,50,515.20},
//        {5,50,515.20},
//        {5,50,515.20},
//        {5,50,515.20},
//        {5,50,1}
//    };

    tProducto productos[] =
    {
        {1,10,10},
        {1,10,9999},
        {1,10,9999},
        {2,20,8888},
        {3,30,1000},
        {3,30,2000},
        {3,30,3000},
        {3,30,4000},
        {4,40,6666},
        {1,10,9999},
        {5,50,515.20},
        {3,30,4000},
        {3,30,4000},
        {1,10,9999},        {1,10,9999},        {1,10,9999},        {1,10,9999},        {1,10,9999},        {1,10,9999},        {1,10,9999},        {1,10,90}
    };

//    tProducto productos[] =
//    {
//        {1,10,9999},
//        {2,20,8888},
//        {3,30,7777},
//        {4,40,6666},
//        {5,50,515.20}
//    };
//    tProducto productos[] =
//    {
//        {1,10,9999}
//    };
//    tProducto productos[] =
//    {
//        {3,30,7777}
//    };
//    tProducto productos[] = {};

//    tProducto clave = {3,0,0};

    t_lista listaDeProductos;
    int ce = sizeof(productos) / sizeof(productos[0]);
    int tam = sizeof(tProducto);
    int i;

    crearLista(&listaDeProductos);

    for(i = 0; i < ce; i++)
    {
        insertarAlFinal(&listaDeProductos, &productos[i], tam);
//        insertarOrdenado(&listaDeProductos, &productos[i], tam, comparaProductos);
    }

//    eliminarAparicionesEnListaDesordenadaConDuplicados(&listaDeProductos, comparaProductos);
    eliminarRegistrosSinDuplicarAcumulandoRegistrosDuplicados(&listaDeProductos, comparaProductos, sumarStockV2);

    printf("Mostrando productos:\n");
    mostrarListaEnOrden(&listaDeProductos, mostrarProducto);

    vaciarLista(&listaDeProductos);

//    printf("Mostrar retorno:\n");
//    mostrarProducto(&clave);

    return 0;
}
