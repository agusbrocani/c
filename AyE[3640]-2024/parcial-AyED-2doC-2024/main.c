#include "funciones.h"

int main()
{
    FILE* archivoLote;
    FILE* archivoLoteOrdenado;

    crearLote();
    if(!abrirArchivo(&archivoLote, NOMBRE_ARCHIVO_LOTE, "rb"))
    {
        return NO_PUDE_ABRIR_ARCHIVO_LOTE;
    }

    if(!abrirArchivo(&archivoLoteOrdenado, NOMBRE_ARCHIVO_LOTE_ORDENADO, "wt"))
    {
        fclose(archivoLote);
        return NO_PUDE_CREAR_ARCHIVO_LOTE_ORDENADO;
    }

    menu(archivoLote, archivoLoteOrdenado);
    printf("Saliendo...\n");

    fclose(archivoLote);
    fclose(archivoLoteOrdenado);

    return 0;
}
