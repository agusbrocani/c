///AGUSTIN BROCANI-EZEQUIEL MUÑOZ-LAUTARO VEGA-LUCA ARCE
#include "empleadosReestructurados.h"

int compararPorSector(const void* a, const void* b)
{
    return ((tEmpleado*)a)->sector - ((tReestructurado*)b)->sector;
}

void mostrarEmpleado(const tEmpleado* bufferEmpleado)
{
    fprintf(stdout, "Sector: %c\nCategoria: %d\nDNI: %d\nNyA: %s\nFNac: %02d/%02d/%04d\n\n",
            bufferEmpleado->sector,
            bufferEmpleado->categoria,
            bufferEmpleado->dni,
            bufferEmpleado->nya,
            bufferEmpleado->fNac.dia,
            bufferEmpleado->fNac.mes,
            bufferEmpleado->fNac.anio);
}


void crearEmpleadosBin()
{
    FILE* pf;
    tEmpleado empleados[] =
    {
        //Empleados del sector 'a' - TODO OK
        {'a', 1, 12345678, "Juan Perez", {15, 4, 1990}},
        {'a', 4, 22334455, "Ana Martinez", {30, 6, 1992}},
        {'a', 6, 33445566, "Lucia Fernandez", {9, 3, 1993}},
        {'a', 9, 66778899, "Fernando Ruiz", {19, 7, 1987}},
        {'a', 12, 99001122, "Elena Diaz", {12, 8, 1992}},
        {'a', 15, 12233445, "Joaquin Vargas", {6, 4, 1991}},

        //Empleados del sector 'b' - CASO MAX 4 EMPLEADOS(exceso de empleados)
        {'b', 2, 87654321, "Maria Gomez", {22, 8, 1985}},
        {'b', 5, 99887766, "Pedro Sanchez", {11, 11, 1988}},
        {'b', 8, 55667788, "Laura Herrera", {14, 9, 1995}},
        {'b', 11, 88990011, "Tomas Gutierrez", {2, 2, 1984}},
        {'b', 14, 11122334, "Gabriela Castro", {17, 12, 1989}},

        //Empleados del sector 'c' - CASO CATEGORIA NECESARIA = 9999 y como MAX 3 EMPLEADOS(exceso de empleados)
        {'c', 3, 11223344, "Carlos Lopez", {5, 12, 1975}},
        {'c', 7, 44556677, "Jorge Ramirez", {27, 1, 1980}},
        {'c', 10, 77889900, "Sofia Navarro", {23, 11, 1990}},
        {'c', 13, 10011223, "Martin Rojas", {29, 5, 1985}},

        //Empleados del sector 'd' - CASO CATEGORIA NECESARIA = 8888
        {'d', 1, 40123456, "Juan Perez", {30, 1, 2000}}
    };

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_EMPLEADOS, "wb"))
    {
        return;
    }

    fwrite(empleados, sizeof(empleados), 1, pf);

    fclose(pf);
}

void crearReestructuradoBin()
{
    FILE* pf;
    tReestructurado condicionesDeReestructuracionPorSector[] =
    {
        {'a', 12, 6},
        {'b', 1, 4},
        {'c', 9999, 3},
        {'d', 8888, 1}
    };

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_REESTRUCTURADO, "wb"))
    {
        return;
    }

    fwrite(condicionesDeReestructuracionPorSector, sizeof(condicionesDeReestructuracionPorSector), 1, pf);

    fclose(pf);
}

void generarReporte(FILE* aEmpleados, FILE* aReestructurado, FILE* aDptosAReestructurar, FILE* aDptosNoReestructurados, int (*comparar)(const void* a, const void* b))
{
    t_cola colaDeEmpleados;
    tEmpleado lecturaEmpleado;
    tReestructurado lecturaReestructurado;
    int contadorDeEmpleados;
    int categoriaMaximaDeEmpleados;

    crearCola(&colaDeEmpleados);

    fread(&lecturaEmpleado, sizeof(tEmpleado), 1, aEmpleados);
    fread(&lecturaReestructurado, sizeof(tReestructurado), 1, aReestructurado);

    while(!feof(aEmpleados)&&!feof(aReestructurado))
    {
        contadorDeEmpleados = 0;
        categoriaMaximaDeEmpleados = CATEGORIA_INEXISTENTE;

        while(!feof(aEmpleados) && !comparar(&lecturaEmpleado, &lecturaReestructurado))
        {
            contadorDeEmpleados++;
            acolar(&colaDeEmpleados, &lecturaEmpleado, sizeof(tEmpleado));

            if(lecturaEmpleado.categoria == lecturaReestructurado.categoriaNecesariaEnSector)
            {
                categoriaMaximaDeEmpleados = lecturaReestructurado.categoriaNecesariaEnSector;
            }
            fread(&lecturaEmpleado, sizeof(tEmpleado), 1, aEmpleados);
        }
        ///aEmpleados quedo apuntando al sector B
        ///aReestructurado quedo apuntando al sector A
        fseek(aEmpleados, (long)(-1 * sizeof(tEmpleado)), SEEK_CUR);

        if(
            CATEGORIA_INEXISTENTE == categoriaMaximaDeEmpleados ||
            contadorDeEmpleados > lecturaReestructurado.cantidadMaximaEmpleadosPorSector
           )
        {
            if(CATEGORIA_INEXISTENTE == categoriaMaximaDeEmpleados)
            {
                desacolar(&colaDeEmpleados, &lecturaEmpleado, sizeof(tEmpleado));
                lecturaEmpleado.categoria = lecturaReestructurado.categoriaNecesariaEnSector;

                fwrite(&lecturaEmpleado, sizeof(tEmpleado), 1, aDptosAReestructurar);
            }
            while(desacolar(&colaDeEmpleados, &lecturaEmpleado, sizeof(tEmpleado)))
            {
                fwrite(&lecturaEmpleado, sizeof(tEmpleado), 1, aDptosAReestructurar);
            }
        }
        else
        {
            while(desacolar(&colaDeEmpleados, &lecturaEmpleado, sizeof(tEmpleado)))
            {
                fwrite(&lecturaEmpleado, sizeof(tEmpleado), 1, aDptosNoReestructurados);
            }
        }

        fread(&lecturaEmpleado, sizeof(tEmpleado), 1, aEmpleados);
        fread(&lecturaReestructurado, sizeof(tReestructurado), 1, aReestructurado);
    }

    vaciarCola(&colaDeEmpleados);
}

void mostrarArchivosResultantes(FILE* aDptosAReestructurar, FILE* aDptosNoReestructurados)
{
    tEmpleado bufferEmpleado;

    printf("Mostrando archivo DPTOS Reestructurados:\n\n");
    fread(&bufferEmpleado, sizeof(tEmpleado), 1, aDptosAReestructurar);
    while(!feof(aDptosAReestructurar))
    {
        mostrarEmpleado(&bufferEmpleado);
        fread(&bufferEmpleado, sizeof(tEmpleado), 1, aDptosAReestructurar);
    }

    system("pause");
    system("cls");

    printf("Mostrando archivo DPTOS NO Reestructurados:\n\n");
    fread(&bufferEmpleado, sizeof(tEmpleado), 1, aDptosNoReestructurados);
    while(!feof(aDptosNoReestructurados))
    {
        mostrarEmpleado(&bufferEmpleado);
        fread(&bufferEmpleado, sizeof(tEmpleado), 1, aDptosNoReestructurados);
    }

    system("pause");
    system("cls");
}
