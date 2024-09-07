#include "./funcionesMain.h"

void fSwitchMenu(int opcion)
{
    tEmpleado empleados[CE_EMPLEADOS];
    unsigned ce = CE_EMPLEADOS;
    unsigned tam = sizeof(tEmpleado);

    cargaEmpleadosAVector(empleados);

    switch(opcion)
    {
        case LOTE_TEXTO_LF:
            printf("\n***************LOTE TextoLF***************\n");
            loteTextoLF(empleados, tam, ce);
            printf("\n***************FIN LOTE TextoLF***************\n");
        break;
        case LOTE_TEXTO_LV:
            printf("\n***************LOTE TextoLV***************\n");
            loteTextoLV(empleados, tam, ce);
            printf("\n***************FIN LOTE TextoLV***************\n");
        break;
        case LOTE_BINARIO:
            printf("\n***************LOTE BINARIO***************\n");
            loteBinario(empleados, tam, ce);
            printf("\n***************FIN LOTE BINARIO***************\n");
        break;
    }
}

void loteTextoLF(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_TEXTO_LF, "wt+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO, "wt+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoTxtLF(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion, grabarDatoArchivoTxtLF);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}

void loteTextoLV(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_TEXTO_LV, "wt+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO, "wt+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoTxtLV(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion, grabarDatoArchivoTxtLV);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}

void loteBinario(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_BINARIO, "wb+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO, "wb+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoBinario(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion, grabarDatoArchivoBinario);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}


