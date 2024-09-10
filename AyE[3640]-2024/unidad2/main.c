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
        "[5]Cargar Empleados desde archivo a Pila Dinamica.",
        "[6]Ordenar archivo con 2 pilas generico.",
        "[7]Sumar 2 enteros muy grandes desde archivos.",
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenu, NULL, DESACTIVAR_AYUDA_AL_USUARIO);

    remove(NOMBRE_ARCHIVO_BINARIO);
    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LV);
    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO);
    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LF);
    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO);
    remove(NOMBRE_ARCHIVO_LOTE_BINARIO);
    remove(NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO);
    remove(NOMBRE_ARCHIVO_NUMERO1);
    remove(NOMBRE_ARCHIVO_NUMERO2);
    remove(NOMBRE_ARCHIVO_RESULTADO);

    return 0;
}
