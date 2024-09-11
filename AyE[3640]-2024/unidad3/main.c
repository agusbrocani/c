#include "unidad3.h"

int main()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
        "Menu:",
        "[0]SALIDA.",
        "[1]Biblioteca de Cola Estatica.",
        "[2]Biblioteca de Cola Dinamica.",
        "[3]Cargar Empleados a datos.bin.",
        "[4]Cargar Empleados desde archivo a Cola Estatica.",
        "[5]Cargar Empleados desde archivo a Cola Dinamica.",
        "[6]Cola de espera en cajero.",
        "[7]Ejercicio raro",
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenu, NULL, DESACTIVAR_AYUDA_AL_USUARIO);

    remove(NOMBRE_ARCHIVO_BINARIO);

    return 0;
}
