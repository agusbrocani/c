#include "f.h"

int main()
{
    FILE* aEmpleados;
    tEmpleado aInsertarEmpleados[CE_MAX];
    tEmpleado aInsertar = {};
    int tam = sizeof(tEmpleado);
    int ceAInsertarEmpleados = 0;
    char buffer[BUFFER_SIZE];

    crearLoteEmpleados();

    if(         !abrirArchivo( &aEmpleados, "empleados.txt", "rt" )           )
    {
        return 1;
    }

    while(          fgets( buffer, BUFFER_SIZE - 1, aEmpleados )         )
    {
        trozar( &aInsertar, buffer );
        insertarOrdenado( aInsertarEmpleados, &aInsertar, tam, &ceAInsertarEmpleados, comparaEmpleadosPorID );  ///con comparaEmpleadosIDMayor ROMPE
    }
    mostrar( aInsertarEmpleados, tam, ceAInsertarEmpleados, mostrarEmpleado );

    ordenarPorSeleccion( aInsertarEmpleados, tam, ceAInsertarEmpleados, comparaEmpleadosIDMayor );

    printf("EN ORDEN DESCENDENTE:\n");
    mostrar( aInsertarEmpleados, tam, ceAInsertarEmpleados, mostrarEmpleado );

    fclose( aEmpleados );

//    tEmpleado empleados[] =
//    {
//        { 6, "Leonardo Barbaro", 'H', {1,1,2003}, 2200.25},
//        { 3, "Franco Ruggieri", 'H', {30,10,2000}, 3001.9},
//        { 2, "Federico Martucci", 'H', {01,01,2000}, 2500},
//        { 5, "Algun Nombre De Mujer", 'M', {18,12,2022}, 1000},
//        { 1, "Agustin Brocani", 'H', {30,01,1998}, 1500.2},
//        { 4, "Simon Bombon", 'H', {29,02,2000}, 0.01},
//    };
//    int tam = sizeof(tEmpleado);
//    int ce = sizeof(empleados)/sizeof(tEmpleado);
//
//ordenarPorSeleccion( empleados, tam, ce, comparaEmpleadosPorID ); ///SI CAMBIO comparaEmpleadosPorID, por comparaEmpleadosIDMayor me ordena de mayor a menor
//mostrar( empleados, tam, ce, mostrarEmpleado );

    return 0;
}
