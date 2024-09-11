#include "unidad3.h"

void switchMenu(int opcion, void* parametro)
{
    switch(opcion)
    {
        case OPCION_1:  //ejecuto 2 opciones en 1
        case OPCION_2:
            printf("Biblioteca de Cola %s implementada.\n", OPCION_1 == opcion ? "Estatica" : "Dinamica");
        break;
        case OPCION_3:
            printf("Cargar Productos a datos.bin.\n");
            cargarProductosAArchivoBinario();
        break;
        case OPCION_4:
        case OPCION_5:
            printf("Cargar Empleados desde archivo a Cola %s.\n", OPCION_4 == opcion ? "Estatica" : "Dinamica");
            opcion4y5();
        break;
        case OPCION_6:
            printf("Cola de espera en cajero.\n");
        break;
        case OPCION_7:
            printf("Copiar archivo datos.bin en orden y orden inverso.\n");
            grabarDosArchivos();
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
    tColaCargada* dato = (tColaCargada*)parametro;
    srand(time(NULL));

    switch(opcion)
    {
        case ACOLAR_4_Y_5:
            printf("Acolando:\n");
            (dato->producto) = ((dato->productos)[rand() % CE_PRODUCTOS]);
            mostrarProducto(&(dato->producto));
            acolar(dato->c, &(dato->producto), dato->tam);
        break;
        case VER_PRIMERO_4_Y_5:
            if(!verPrimero(dato->c, &(dato->producto), dato->tam))
            {
                printf("Cola vacia.\n");
            }
            else
            {
                printf("Viendo primero:\n");
                mostrarProducto(&(dato->producto));
            }
        break;
        case DESACOLAR_4_Y_5:
            if(!desacolar(dato->c, &(dato->producto), dato->tam))
            {
                printf("Cola Vacia.\n");
            }
            else
            {
                printf("Desacolando:\n");
                mostrarProducto(&(dato->producto));
            }
        break;
    }
}

void opcion4y5()
{
    FILE* datosBin;
    tCola colaCargada;
    tProducto producto;
    unsigned tam = sizeof(tProducto);
    unsigned cantBytesArchivo;
    tColaCargada sColaCargada;

    char textoMenu[][MAX_TAM_TEXTO] =
    {
      "Submenu cola con datos.bin:",
      "[0]SALIR del submenu.",
      "[1]Acolar.",
      "[2]Ver Primero.",
      "[3]Desacolar."
    };
    unsigned cantidadDeRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    crearCola(&colaCargada);

    fread(&producto, tam, 1, datosBin);
    while(!feof(datosBin))
    {
        acolar(&colaCargada, &producto, tam);
        fread(&producto, tam, 1, datosBin);
    }
    fclose(datosBin);

    sColaCargada.c = &colaCargada;
    sColaCargada.tam = tam;
    cargarProductos(sColaCargada.productos, CE_PRODUCTOS);

    menu(textoMenu, cantidadDeRegistros, switchMenu4y5, &sColaCargada, DESACTIVAR_AYUDA_AL_USUARIO);

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "wb"))
    {
        return;
    }

    while(desacolar(&colaCargada, &producto, tam))
    {
        fwrite(&producto, tam, 1, datosBin);
    }

    fseek(datosBin, 0L, SEEK_END);
    cantBytesArchivo = ftell(datosBin);//cuenta cant bytes desde el inicio

    vaciarCola(&colaCargada);
    fclose(datosBin);

    if(!cantBytesArchivo)
    {
        printf("\nBorrando archivo...\n");
        remove(NOMBRE_ARCHIVO_BINARIO);
        system("pause");
        system("cls");
        return;
    }

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    printf("Mostrando archivo grabado:\n\n");
    fread(&producto, tam, 1, datosBin);
    while(!feof(datosBin))
    {
        mostrarProducto(&producto);
        fread(&producto, tam, 1, datosBin);
    }

    fclose(datosBin);
}

void grabarDosArchivos()
{
    FILE* datosBin;
    FILE* datos1Bin;
    FILE* datos2Bin;
    tProducto producto;
    unsigned tam = sizeof(tProducto);
    t_pila pila;
    tCola cola;

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    if(!abrirArchivo(&datos1Bin, NOMBRE_ARCHIVO_BINARIO_D1, "wb"))
    {
        fclose(datosBin);
        return;
    }

    if(!abrirArchivo(&datos2Bin, NOMBRE_ARCHIVO_BINARIO_D2, "wb"))
    {
        fclose(datosBin);
        fclose(datos1Bin);
        return;
    }

    crearPila(&pila);
    crearCola(&cola);

    fread(&producto, tam, 1, datosBin);
    while(!feof(datosBin))
    {
        apilar(&pila, &producto, tam);
        acolar(&cola, &producto, tam);
        fread(&producto, tam, 1, datosBin);
    }
    system("pause");
    system("cls");

    printf("Productos en orden inverso:\n");
    while(desapilar(&pila, &producto, tam))
    {
        mostrarProducto(&producto);
        fwrite(&producto, tam, 1, datos2Bin);
    }

    system("pause");
    system("cls");

    printf("Productos en orden:\n");
    while(desacolar(&cola, &producto, tam))
    {
        mostrarProducto(&producto);
        fwrite(&producto, tam, 1, datos2Bin);
    }
    system("pause");
    system("cls");

    fclose(datosBin);
    fclose(datos1Bin);
    fclose(datos2Bin);
}

