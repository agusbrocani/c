#include "./unidad2.h"

int main()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
        "Menu:",
        "[0]SALIDA.",
        "[1]Biblioteca de Pila Estatica.",
        "[2]Biblioteca de Pila Dinamica.",
        "[3]Cargar Empleados a datos.bin.",
        "[4]Cargar Empleados desde archivo a Pila Estatica.",
        "[5]Cargar Empleados desde archivo a pila Dinamica.",
        "[6]Ordenar datos.bin con 2 pilas.",
        "[7]Sumar 2 enteros muy grandes desde archivos.",
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenu, NULL, DESACTIVAR_AYUDA_AL_USUARIO);

    return 0;
}
