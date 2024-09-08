/// Luca Arce, Agustin Brocani, Ezequiel Muñoz y Lautaro Vega
#include "funciones.h"

int main()
{
    FILE* archEmpleados;
    FILE* archEmpleadosOrdenado;
    unsigned tamDato = sizeof(tEmpleado);

    crearLoteEmpleado();

    if(!abrirArchivo(&archEmpleados, NOMBRE_ARCHIVO_BINARIO_DESORDENADO, "rb"))
    {
        return ERR_APERTURA_ARCHIVO;
    }

    if(!abrirArchivo(&archEmpleadosOrdenado, NOMBRE_ARCHIVO_BINARIO_ORDENADO, "wb"))
    {
        fclose(archEmpleados);
        return ERR_APERTURA_ARCHIVO;
    }

    ordenarArchivoConDosPilas(archEmpleados, archEmpleadosOrdenado, tamDato, comparaEmpleadosPorID);

    fclose(archEmpleados);
    fclose(archEmpleadosOrdenado);

    remove(NOMBRE_ARCHIVO_BINARIO_DESORDENADO);
    rename(NOMBRE_ARCHIVO_BINARIO_ORDENADO, NUEVO_NOMBRE_ARCHIVO);

    if(!abrirArchivo(&archEmpleados, NUEVO_NOMBRE_ARCHIVO, "rb"))
    {
        return ERR_APERTURA_ARCHIVO;
    }
    mostrarArchivoBinario(archEmpleados, tamDato, mostrarEmpleado);

    fclose(archEmpleados);
    return 0;
}
