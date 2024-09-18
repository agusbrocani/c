///AGUSTIN BROCANI-EZEQUIEL MUÑOZ-LAUTARO VEGA-LUCA ARCE
#include "listaSimplementeEnlazada.h"

int compararEmpleadosPorID(const void* a, const void* b)
{
    return ((tEmpleado*)a)->id - ((tEmpleado*)b)->id;
}

void mostrarEmpleado(const void* dato)
{
    fprintf(stdout, "\nID: %d\nNya: %s\nSexo: %c\nSalario: %.2f\n",
            ((tEmpleado*)dato)->id,
            ((tEmpleado*)dato)->nya,
            ((tEmpleado*)dato)->sexo,
            ((tEmpleado*)dato)->salario
            );
}

void mostrarColeccion(const void* coleccion, unsigned tam, unsigned ce, void (*mostrar)(const void* dato))
{
    int i;

    printf("Mostrando coleccion:\n");
    for(i = 0; i < ce; i++)
    {
        mostrar(coleccion);
        printf("\n");
        coleccion += tam;
    }
    printf("\n");
}

void sumar5(void* dato)
{
    ((tEmpleado*)dato)->salario += 5;
}

int main()
{
    t_lista lista;
    tEmpleado coleccion[] =
    {
      {1,"Agustin Brocani", 'M', 5000},
      {2,"Federico Martucci", 'M', 9000},
      {3,"Franco R.", 'M', 7000},
      {4,"Karen B.", 'F', 3600},
      {5,"Pablo M.", 'M', 5500}
    };
//    tEmpleado coleccion[] =
//    {
//      {5,"Pablo M.", 'M', 5500},
//      {4,"Karen B.", 'F', 3600},
//      {1,"Agustin Brocani", 'M', 5000},
//      {3,"Franco R.", 'M', 7888},
//      {2,"Federico Martucci", 'M', 9999}
//    };
//    tEmpleado coleccion[] =
//    {
//      {1,"Agustin Brocani", 'M', 5000}
//    };
//    tEmpleado coleccion[] = {};
    unsigned tam = sizeof(coleccion[0]);
    unsigned ce = sizeof(coleccion) / sizeof(coleccion[0]);
    void* mostrar = mostrarEmpleado;
    tEmpleado buffer;
    int i;

//    mostrarColeccion(coleccion, tam, ce, mostrar);
    crearLista(&lista);

    for(i = 0; i < ce; i++)
    {
        insertarAlFinal(&lista, &coleccion[i], tam);
    }

    printf("Mostrando lista en orden:\n");
    mostrarListaEnOrden(&lista, mostrar);
    system("pause");
    system("cls");

    printf("Ejecutando MAP: Sumando 5 al salario en lista.\n");
    mapEnListaSimple(&lista, sumar5);

//    printf("Mostrando lista en orden inverso:\n");
//    mostrarListaEnOrdenInverso(&lista, mostrar);

    mostrarListaEnOrden(&lista, mostrar);

    system("pause");
    system("cls");

    printf("Desalistando:\n");
    while(sacarFinal(&lista, &buffer, tam))
    {
        mostrarEmpleado(&buffer);
    }

    printf("\n");
    system("pause");
    system("cls");
    printf("Vaciando lista...\n");
    vaciarLista(&lista);

    return 0;
}
