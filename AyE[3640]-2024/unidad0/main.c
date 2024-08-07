#include "unidad0.h"

int main()
{
    tPersona coleccion[] =
    {
        {5,"Pablo M",'M',5000},
        {4,"Karen B",'F',7500},
        {1,"Agustin Brocani",'M',8900},
        {3,"Franco Ruggieri",'M',6000},
        {2,"Federico Martucci",'M',8900}
    };

    int ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );
    char nombreArchivo[] = "LoteEnArchivoDeTexto.bin";
//    ejercicio2();
//    ejercicio3();
//
//    ejercicio4();

//    ejercicio5( nombreArchivo, coleccion, tam, ce, comparaPersonasPorID, grabarPersona );

//    ejercicio6( nombreArchivo, coleccion, tam, ce, comparaPersonasPorID, grabarPersona );

    ejercicio7();

    return 0;
}
