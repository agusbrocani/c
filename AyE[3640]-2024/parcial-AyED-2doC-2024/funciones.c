#include "funciones.h"

int abrirArchivo(FILE** pf, const char* nombreArchivo, const char* modo)
{
    *pf = fopen(nombreArchivo, modo);
    if(!*pf)
    {
        fprintf(stderr, "No pude abrir/crear el archivo: %s.\n", nombreArchivo);
        return NO_PUDE_ABRIR_CREAR_ARCHIVO;
    }

    return OK;
}

void crearLote()
{
    FILE* pf;
    tLote lote[] =
    {
        {2, "Gonzalez Catan", 100, 500},
        {2, "San Justo", 100, 500},
        {2, "Laferrere", 100, 500},
        {1, "La Madrid", 200, 500},
        {3, "Ciudad inventada 3", 50, 50},
        {1, "Ciudad inventada 1", 200, 500},
        {2, "I. Casanova", 100, 500},
    };

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_LOTE, "wb"))
    {
        return;
    }

    fwrite(lote, sizeof(lote), 1, pf);

    fclose(pf);
}

void grabarLote(FILE* pf, const void* dato)
{
    fprintf(pf, "Provincia: %d\nLocalidad: %s\nSuperficie: %.2f\nPoblacion: %d\n\n",
            ((tLote*)dato)->provincia,
            ((tLote*)dato)->localidad,
            ((tLote*)dato)->superficie,
            ((tLote*)dato)->poblacion
            );
}

void grabarLoteOrdenado(FILE* pf, const void* dato)
{
    fprintf(pf, "Provincia: %d\nSuperficie total: %.2f\nCantidad total de habitantes: %d\nDensidad de poblacion: %.2f\n\n",
            ((tLoteOrdenado*)dato)->provincia,
            ((tLoteOrdenado*)dato)->superficieTotal,
            ((tLoteOrdenado*)dato)->cantidadTotalDeHabilitantes,
            ((tLoteOrdenado*)dato)->densidadDePoblacion
            );
}

int compararEnteros(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int compararProvinciasASC(const void* a, const void* b)
{
    return ((tLote*)a)->provincia - ((tLote*)b)->provincia;
}

int compararProvinciasDESC(const void* a, const void* b)
{
    return ((tLote*)b)->provincia - ((tLote*)a)->provincia;
}

void acumularSuperficieYPoblacion(void* dato, const void* datoAInsertar)
{
    ((tLote*)dato)->superficie += ((tLote*)datoAInsertar)->superficie;
    ((tLote*)dato)->poblacion += ((tLote*)datoAInsertar)->poblacion;
}

void textoMenu()
{
    printf("Menu:\n");
    printf("[0]SALIR.\n");
    printf("[1]Insertar ordenado ASCENDENTE en lista simple generando informe.\n");
    printf("[2]Insertar ordenado DESCENDENTE en lista simple generando informe.\n");
}

int ingresoOpcion()
{
    int opcion;

    textoMenu();
    do
    {
        fflush(stdin);
        printf("\nIngrese opcion:\t");
        scanf("%d", &opcion);
        printf("\n");

        if(!(opcion >= LI && opcion <= LS))
        {
            printf("Ingreso invalido, intente nuevamente.\n");
        }

    }while(!(opcion >= LI && opcion <= LS));

    return opcion;
}

void mostrarLote(void* dato, void* recursos)
{
    grabarLote(stdout, dato);
}

///NO ES UNA PRIMITIVA, POR LO TANTO, NO HACE FALTA DECLARARLO EN EL .h y .c de listaSimple
void cargarListaDesdeLoteBinario(FILE* archivoLote, t_lista* lista, int (*comparar)(const void* a, const void* b))
{
    tLote lote;
    unsigned tamLote = sizeof(tLote);

    fread(&lote, tamLote, 1, archivoLote);
    while(!feof(archivoLote))
    {
        insertarOrdenadoConAccion(lista, &lote, tamLote, comparar, acumularSuperficieYPoblacion);
        fread(&lote, tamLote, 1, archivoLote);
    }
    mapEnListaSimple(lista, NULL, mostrarLote);
}

///NO ES UNA PRIMITIVA, POR LO TANTO, NO HACE FALTA DECLARARLO EN EL .h y .c de listaSimple
void generarInformeTxtOrdenado(FILE* archivoLoteOrdenado, t_lista* lista)
{
    tLote lote;
    tLoteOrdenado loteOrdenado;

    while(sacarPrimero(lista, &lote, sizeof(tLote)))
    {
        loteOrdenado.provincia = lote.provincia;
        loteOrdenado.superficieTotal = lote.superficie;
        loteOrdenado.cantidadTotalDeHabilitantes = lote.poblacion;
        loteOrdenado.densidadDePoblacion = (float) lote.poblacion / (float)lote.superficie; ///cantidadTotalDeHabitantes / superficieTotal => Cuanta gente vive en un determinado espacio
        grabarLoteOrdenado(archivoLoteOrdenado, &loteOrdenado);
        grabarLoteOrdenado(stdout, &loteOrdenado);
    }
}

void menu(FILE* archivoLote, FILE* archivoLoteOrdenado)
{
    t_lista lista;
    int opcion;

    crearLista(&lista);

    while(SALIR != (opcion = ingresoOpcion()))
    {
        switch(opcion)
        {
            case ORDEN_ASC:
                printf("Cargando lista desde lote binario ASC y generando informe txt ordenado.\n\n");
                cargarListaDesdeLoteBinario(archivoLote, &lista, compararProvinciasASC);
                printf("\nInforme generado:\n\n");
                generarInformeTxtOrdenado(archivoLoteOrdenado, &lista);
            break;
            case ORDEN_DESC:
                printf("Cargando lista desde lote binario DESC y generando informe txt ordenado.\n\n");
                cargarListaDesdeLoteBinario(archivoLote, &lista, compararProvinciasDESC);
                printf("\nInforme generado:\n\n");
                generarInformeTxtOrdenado(archivoLoteOrdenado, &lista);
            break;
        }
        system("pause");
        system("cls");
        vaciarLista(&lista);    //La lista ya esta vacia, pero porque utilizo programacion defensiva, coloco la primitiva
        rewind(archivoLote);
        rewind(archivoLoteOrdenado);
    }
}
