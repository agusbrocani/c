/// Luca Arce, Agustin Brocani, Ezequiel Muñoz y Lautaro Vega
#include "funciones.h"

int abrirArchivo (FILE** fp, const char* nombreArch, const char* modo)
{
    *fp = fopen(nombreArch, modo);
    if(!*fp)
    {
        //perror("Error en la apertura del archivo.");
        fprintf(stderr,"Error en la apertura del archivo: %s.",nombreArch);
        return NO_SE_ABRIO_ARCH;
    }
    return TODO_OK;
}

///El primer array de empleados tiene 30 empleados
void crearLoteEmpleado ()
{
    FILE* fp;
    tEmpleado empleados[] =
    {
        {14, "Gabriela Ortega", 'F', 1550000},
        {5, "Carla Fernandez", 'F', 900000},
        {7, "Daniela Herrera", 'F', 980000},
        {19, "Luis Silva", 'M', 1800000},
        {30, "Valeria Barrera", 'F', 2900000},
        {4, "Carlos Delgado", 'M', 850000},
        {12, "Esteban Moreno", 'M', 1400000},
        {22, "Natalia Vargas", 'F', 1950000},
        {25, "Pablo Ximenez", 'M', 2100000},
        {1, "Agustin Brocani", 'M', 650000},
        {15, "Gabriel Perez", 'M', 1600000},
        {16, "Juliana Quiroga", 'F', 1650000},
        {11, "Emilia Martinez", 'F', 1300000},
        {8, "David Ibarra", 'M', 1100000},
        {21, "Martin Uribe", 'M', 1900000},
        {20, "Marta Torres", 'F', 1850000},
        {6, "Claudia Gomez", 'F', 920000},
        {27, "Rodrigo Zambrano", 'M', 2250000},
        {9, "Diana Juarez", 'F', 1150000},
        {2, "Ana Benitez", 'F', 720000},
        {3, "Ariel Castro", 'M', 780000},
        {13, "Federico Martucci", 'M', 1500000},
        {17, "Julian Rodriguez", 'M', 1700000},
        {24, "Patricia Wallace", 'F', 2050000},
        {28, "Silvia Zuniga", 'F', 2300000},
        {29, "Santiago Araujo", 'M', 2500000},
        {18, "Laura Sanchez", 'F', 1750000},
        {10, "Eduardo Lopez", 'M', 1200000},
        {23, "Nicolas Villegas", 'M', 2000000},
        {26, "Rosa Yanez", 'F', 2200000}
    };
///   CASO SIN ELEMENTOS
//    tEmpleado empleados[] =
//    {
//    };
///   CASO UN ELEMENTO
//    tEmpleado empleados[] =
//    {
//        {14, "Gabriela Ortega", 'F', 1550000}
//    };
///   CASO COLECCION ORDENADA
//    tEmpleado empleados[] =
//    {
//        {1, "Agustin Brocani", 'M', 650000},
//        {2, "Ana Benitez", 'F', 720000},
//        {3, "Ariel Castro", 'M', 780000},
//        {4, "Carlos Delgado", 'M', 850000},
//        {5, "Carla Fernandez", 'F', 900000},
//        {6, "Claudia Gomez", 'F', 920000},
//        {7, "Daniela Herrera", 'F', 980000},
//        {8, "David Ibarra", 'M', 1100000},
//        {9, "Diana Juarez", 'F', 1150000},
//        {10, "Eduardo Lopez", 'M', 1200000},
//        {11, "Emilia Martinez", 'F', 1300000},
//        {12, "Esteban Moreno", 'M', 1400000},
//        {13, "Federico Martucci", 'M', 1500000},
//        {14, "Gabriela Ortega", 'F', 1550000},
//        {15, "Gabriel Perez", 'M', 1600000},
//        {16, "Juliana Quiroga", 'F', 1650000},
//        {17, "Julian Rodriguez", 'M', 1700000},
//        {18, "Laura Sanchez", 'F', 1750000},
//        {19, "Luis Silva", 'M', 1800000},
//        {20, "Marta Torres", 'F', 1850000},
//        {21, "Martin Uribe", 'M', 1900000},
//        {22, "Natalia Vargas", 'F', 1950000},
//        {23, "Nicolas Villegas", 'M', 2000000},
//        {24, "Patricia Wallace", 'F', 2050000},
//        {25, "Pablo Ximenez", 'M', 2100000},
//        {26, "Rosa Yanez", 'F', 2200000},
//        {27, "Rodrigo Zambrano", 'M', 2250000},
//        {28, "Silvia Zuniga", 'F', 2300000},
//        {29, "Santiago Araujo", 'M', 2500000},
//        {30, "Valeria Barrera", 'F', 2900000}
//    };
///   CASO DUPLICADOS
//    tEmpleado empleados[] =
//    {
//        {1, "Agustin Brocani", 'M', 650000},
//        {2, "Ana Benitez", 'F', 720000},
//        {1, "Ariel Castro", 'M', 780000},
//        {4, "Carlos Delgado", 'M', 850000}
//    };

    if(!abrirArchivo(&fp, NOMBRE_ARCHIVO_BINARIO_DESORDENADO, "wb"))
        return;

    fwrite(empleados, sizeof(empleados), 1, fp);

    fclose(fp);
}

int comparaEmpleadosPorID(const void* a, const void* b)
{
    return ((tEmpleado*)a)->id - ((tEmpleado*)b)->id;
}

void mostrarEmpleado(const void* dato)
{
    printf("ID: %d\nNya: %s\nSexo: %c\nSalario: %.2f\n\n",
           ((tEmpleado*)dato)->id,
           ((tEmpleado*)dato)->nya,
           ((tEmpleado*)dato)->sexo,
           ((tEmpleado*)dato)->salario
          );
}

void ordenarArchivoConDosPilas (FILE* desordenado, FILE* ordenado, unsigned tamDato, int (*comparar)(const void* a, const void* b))
{
    t_pila pMayores;
    t_pila pMenores;
    void* dato;
    void* buffer;

    dato = malloc(tamDato);
    if(!dato)
    {
        fprintf(stderr,"No pude reservar memoria.");
        return;
    }

    buffer = malloc(tamDato);
    if(!buffer)
    {
        fprintf(stderr,"No pude reservar memoria.");
        free(dato);
        return;
    }

    crearPila(&pMayores);
    crearPila(&pMenores);

    fread(dato, tamDato, 1, desordenado);
    while(!feof(desordenado))
    {
        while(verTope(&pMayores, buffer, tamDato) && (comparar(dato, buffer) > 0))
        {
            desapilar(&pMayores, buffer, tamDato);
            apilar(&pMenores, buffer, tamDato);
        }

        while(verTope(&pMenores, buffer, tamDato) && (comparar(dato, buffer) < 0))
        {
            desapilar(&pMenores, buffer, tamDato);
            apilar(&pMayores, buffer, tamDato);
        }
        apilar(&pMayores, dato, tamDato);

        fread(dato, tamDato, 1, desordenado);
    }

    while(desapilar(&pMenores, dato, tamDato))
    {
        apilar(&pMayores, dato, tamDato);
    }

    while(desapilar(&pMayores, dato, tamDato))
    {
        fwrite(dato, tamDato, 1, ordenado);
    }

    free(dato);
    free(buffer);
    vaciarPila(&pMayores);
    vaciarPila(&pMenores);
}

void mostrarArchivoBinario (FILE* fp, unsigned tamDato, void (*mostrarEmpleado)(const void* dato))
{
    void* buffer = malloc(tamDato);
    if(!buffer)
    {
        fprintf(stderr,"No pude reservar memoria.");
        return;
    }

    fread(buffer, tamDato, 1, fp);
    while(!feof(fp))
    {
        mostrarEmpleado(buffer);
        fread(buffer, tamDato, 1, fp);
    }

    free(buffer);
}
