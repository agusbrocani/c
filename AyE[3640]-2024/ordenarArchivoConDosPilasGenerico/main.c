#include "./funcionesMain.h"

int main()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
        "Menu de ordenar archivo con dos pilas generico:",
        "[0]-SALIR.",
        "[1]-Ver archivo desordenado.",
        "[2]-Ordenar archivo TEXTO-LF con 2 pilas.",
        "[3]-Ordenar archivo TEXTO-LV con 2 pilas.",
        "[4]-Ordenar archivo BINARIO con 2 pilas."
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenu, NULL, DESACTIVAR_AYUDA_AL_USUARIO);

    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LV);
//    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO);
    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LF);
//    remove(NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO);
    remove(NOMBRE_ARCHIVO_LOTE_BINARIO);
//    remove(NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO);

    return 0;
}
