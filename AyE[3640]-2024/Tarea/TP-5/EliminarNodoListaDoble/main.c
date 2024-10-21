#include "main.h"

/*
    GRUPO:
    - Quiroga Piegari Lucila
    - Monges Omar
    - Odriozola Ignacio
    - Fariello Ramiro
    - Brocani Agustin
    - Sierra Jazmin
*/

int main()
{
    t_empleado empleados [] =
    {
        {100, "Carlos", "Lopez", 'A', 47000.00},
        {200, "Sofia", "Sanchez", 'B', 51000.40},
        {300, "Ana", "Martinez", 'C', 48000.10},
        {400, "Lucia", "Garcia", 'A', 43000.25},
        {500, "Juan", "Perez", 'A', 45000.50},
        {600, "Maria", "Gonzalez", 'B', 52000.75},
        {700, "Miguel", "Diaz", 'A', 46000.60},
        {800, "Pablo", "Rodriguez", 'C', 60000.80},
        {900, "Luis", "Fernandez", 'B', 55000.90}
    };
    t_empleado empleadoEliminado, *pVec = empleados;
    t_listaDoble listaDoble;
    int clave = 800;
    unsigned i, aError;

    crearLista (&listaDoble);
    for (i = 0; i < sizeof (empleados) / sizeof (t_empleado); i ++)
    {
        aError = insertarEnListaDoble (&listaDoble, pVec, sizeof(t_empleado), &cmpLegajoEmpleado);
        if (aError != 0)
        {
            if (aError == 1)
                printf ("ERROR AL INGRESAR EN LISTA - SIN MEMORIA\n");
            else
                printf ("ERROR AL INGRESAR EN LISTA - NO SE ADMITEN DUPLICADOS\n");
        }
        pVec ++;
    }
    printf ("La lista doble es:\nLEGAJO\t\t      NOMBRE\t\t  APELLIDO   SECTOR\t  SUELDO\n");
    recorrerListaDobleMenorAMayor (&listaDoble, &mostrarEmpleado);
    printf ("\n");
    if (!eliminarEnListaDobleSinDuplicados (&listaDoble, &clave, &empleadoEliminado, sizeof (t_empleado), &cmpLegajoEmpleado))
    {
        printf ("El empleado eliminado es:\nLEGAJO\t\t      NOMBRE\t\t  APELLIDO   SECTOR\t  SUELDO\n");
        mostrarEmpleado (&empleadoEliminado);
    }
    else
        printf ("No se encontro el empleado en la lista doble.\n");
    printf ("\nLa lista doble quedo:\nLEGAJO\t\t      NOMBRE\t\t  APELLIDO   SECTOR\t  SUELDO\n");
    recorrerListaDobleMenorAMayor (&listaDoble, &mostrarEmpleado);
    vaciarListaDoble (&listaDoble);

    return OK;
}

int cmpLegajoEmpleado (void *a, void *b)
{
    t_empleado *x = (t_empleado*)a;
    t_empleado *y = (t_empleado*)b;

    return x->legajo - y->legajo;
}

void mostrarEmpleado (void *x)
{
    t_empleado *empleado = (t_empleado*)x;

    printf ("%6d %21s %21s %6c\t%3.2f\n", empleado->legajo, empleado->nombre, empleado->apellido, empleado->sector, empleado->sueldo);
}











