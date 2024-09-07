#include "./funcionesMain.h"

int main()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
        "Menu:",
        "[0]-SALIR",
        "[1]-Ordenar archivo TEXTO-LF con 2 pilas.",
        "[2]-Ordenar archivo TEXTO-LV con 2 pilas.",
        "[3]-Ordenar archivo BINARIO con 2 pilas."
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, fSwitchMenu, DESACTIVAR_AYUDA_AL_USUARIO);

    return 0;
}
