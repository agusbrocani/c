#include "funciones.h"

void mostrarEntero(const void* dato)
{
        printf("%d ", *(int*)dato);
}

void mostrarEntero2(void* dato)
{
        printf("%d ", *(int*)dato);
}

void acumularEntero(void* datoArbol, const void* dato)
{
        *(int*)datoArbol += *(int*)dato;
}

int comparaEnteros(const void* a, const void* b)
{
        return *(int*)a - *(int*)b;
}

int main()
{
        t_arbol arbolR;
        t_arbol arbolI;
        int coleccion[] = {4,1,3,2,5};
        unsigned ce = sizeof(coleccion) / sizeof(coleccion[0]);
        unsigned tam = sizeof(coleccion[0]);
        int i;

        crearArbol(&arbolR);
        crearArbol(&arbolI);

        for(i = 0; i < ce; i++)
        {
                insertarEnArbol(&arbolR , &coleccion[i], tam, comparaEnteros, acumularEntero);
        }

        for(i = 0; i < ce; i++)
        {
                insertarEnArbolIterativo(&arbolI , &coleccion[i], tam, comparaEnteros, acumularEntero);
        }

        recorrerEnPreOrden(&arbolR, mostrarEntero2);
        printf("\n");
        recorrerEnPreOrden(&arbolI, mostrarEntero2);
        printf("\n");
        recorrerEnOrden(&arbolR, mostrarEntero2);
        printf("\n");
        recorrerEnOrden(&arbolI, mostrarEntero2);
        printf("\n");
        recorrerEnPosOrden(&arbolR, mostrarEntero2);
        printf("\n");
        recorrerEnPosOrden(&arbolI, mostrarEntero2);

        printf("\nCantidad de nodos: %d\n", contarNodos(&arbolR));
        printf("\nCantidad hojas: %d\n", contarHojas(&arbolR));

        t_arbol arbolAPodar;

        crearArbol(&arbolAPodar);


        for(i = 0; i < ce; i++)
        {
                insertarEnArbol(&arbolAPodar , &coleccion[i], tam, comparaEnteros, acumularEntero);
        }

        podarHojas(&arbolAPodar);
        recorrerEnPosOrden(&arbolAPodar, mostrarEntero2);
        vaciarArbol(&arbolAPodar);

    return 0;
}
