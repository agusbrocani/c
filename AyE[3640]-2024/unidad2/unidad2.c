#include "./unidad2.h"

void switchMenu(int opcion, void* parametro)
{
    switch(opcion)
    {
        case OPCION_1:  //ejecuto 2 opciones en 1
        case OPCION_2:
            printf("Biblioteca de Pila %s implementada.\n", OPCION_1 == opcion ? "Estatica" : "Dinamica");
        break;
        case OPCION_3:
            printf("Cargar Productos a datos.bin.\n");
            cargarProductosAArchivoBinario();
        break;
        case OPCION_4:
        case OPCION_5:
            printf("Cargar Empleados desde archivo a Pila %s.\n", OPCION_4 == opcion ? "Estatica" : "Dinamica");
            opcion4y5();
        break;
        case OPCION_6:
            printf("Ordenar datos.bin con 2 pilas.\n");
            ordenarDatosArchivoConDosPilas();
        break;
        case OPCION_7:
            printf("Sumar 2 enteros muy grandes desde archivos.\n");
            sumarEnterosDesde2Archivos();
        break;
    }
}

void cargarProductosAArchivoBinario()
{
    FILE* pf;
    tProducto productos[CE_PRODUCTOS];
    unsigned tam = sizeof(productos[0]);
    cargarProductos(productos, CE_PRODUCTOS);

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_BINARIO, "wb"))
    {
        return;
    }

    fwrite(productos, CE_PRODUCTOS * tam, 1, pf);

    fclose(pf);
}

void switchMenu4y5(int opcion, void* parametro)
{
    switch(opcion)
    {
        default:
        break;
    }
}

void opcion4y5()
{
    FILE* datosBin;
    tPila pilaLectura;
    tProducto producto;
    unsigned tam = sizeof(tProducto);

    char textoMenu[][MAX_TAM_TEXTO] =
    {
      "Menu:\n",
      "[0]Salir de SubMenu.\n"
    };
    unsigned cantidadDeRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    crearPila(&pilaLectura);

    fread(&producto, tam, 1, datosBin);

    while(!feof(datosBin))
    {
        apilar(&pilaLectura, &producto, tam);
        fread(&producto, tam, 1, datosBin);
    }
//    vaciarPila(&pilaLectura);
    fclose(datosBin);

    //cambiar null por pila
    menu(textoMenu, cantidadDeRegistros, switchMenu4y5, NULL, DESACTIVAR_AYUDA_AL_USUARIO);
}

void ordenarDatosArchivoConDosPilas()
{
//  ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion, grabarDatoArchivoBinario);
}

void sumarEnterosDesde2Archivos()
{
//    sumarEnterosConDosPilas( &resultado, &pNumero1, &pNumero2, aResultado, grabarEntero );
}

