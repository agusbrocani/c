///AGUSTIN BROCANI-EZEQUIEL MUÑOZ-LAUTARO VEGA-LUCA ARCE
#include "empleadosReestructurados.h"

int main()
{
    FILE* aEmpleados;
    FILE* aReestructurado;
    FILE* aDptosAReestructurar;
    FILE* aDptosNoReestructurados;

    crearEmpleadosBin();
    crearReestructuradoBin();

    if(!abrirArchivo(&aEmpleados, NOMBRE_ARCHIVO_EMPLEADOS, "rb"))
    {
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(!abrirArchivo(&aReestructurado, NOMBRE_ARCHIVO_REESTRUCTURADO, "rb"))
    {
        fclose(aEmpleados);
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(!abrirArchivo(&aDptosAReestructurar, NOMBRE_ARCHIVO_DPTOS_A_REESTRUCTURAR, "wb+"))
    {
        fclose(aEmpleados);
        fclose(aReestructurado);
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(!abrirArchivo(&aDptosNoReestructurados, NOMBRE_ARCHIVO_DPTOS_NO_REESTRUCTURADOS, "wb+"))
    {
        fclose(aEmpleados);
        fclose(aReestructurado);
        fclose(aDptosAReestructurar);
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    generarReporte(aEmpleados, aReestructurado, aDptosAReestructurar, aDptosNoReestructurados, compararPorSector);

    rewind(aDptosAReestructurar);
    rewind(aDptosNoReestructurados);
    fseek(aDptosAReestructurar, 0L, SEEK_CUR);
    fseek(aDptosNoReestructurados, 0L, SEEK_CUR);

    mostrarArchivosResultantes(aDptosAReestructurar, aDptosNoReestructurados);

    fclose(aEmpleados);
    fclose(aReestructurado);
    fclose(aDptosAReestructurar);
    fclose(aDptosNoReestructurados);
    remove(NOMBRE_ARCHIVO_EMPLEADOS);
    remove(NOMBRE_ARCHIVO_REESTRUCTURADO);

    return 0;
}
