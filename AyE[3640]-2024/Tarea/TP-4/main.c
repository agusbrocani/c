#include "reproductorConListaCircular.h"
#define NO_PUDE_ABRIR_ARCHIVO_ARCHIVO_BINARIO_LISTA_DE_TEMAS -1

int main()
{
    tRecursosMenu punterosAListaYArchivoDeTemas;
    char textoMenuPrincipal[][MAX_TAM_TEXTO] =
    {
      "Playlist:",
      "[0]Salida.",
      "[1]Crear Lista Simple de Temas ordenada segun criterio.",
      "[2]Mezclar Lista Simple de Temas de forma aleatoria.",
      "[3]Crear playlist circular.",                            ///TO DO
      "[4]Reproducir playlist circular.",                       ///TO DO
      "[5]Guardar playlist circular en archivo de texto."       ///TO DO
    };
    unsigned cantidadDeRegistros = sizeof(textoMenuPrincipal) / MAX_TAM_TEXTO;

    crearArchivoBinarioDeTemas();
    if(!abrirArchivo(&punterosAListaYArchivoDeTemas.aListaDeTemas, NOMBRE_ARCHIVO_BINARIO_LISTA_DE_TEMAS, "rb"))
    {
        return NO_PUDE_ABRIR_ARCHIVO_ARCHIVO_BINARIO_LISTA_DE_TEMAS;
    }

    crearListaSimple(&punterosAListaYArchivoDeTemas.listaSimpleDeTemas);
    crearListaCircular(&punterosAListaYArchivoDeTemas.listaCircularDeTemas);///IMPLEMENTAR PRIMITIVA en listaCircular.c

    menu(textoMenuPrincipal, cantidadDeRegistros, switchMenuPrincipal, &punterosAListaYArchivoDeTemas, DESACTIVAR_AYUDA_AL_USUARIO);

    vaciarListaSimple(&punterosAListaYArchivoDeTemas.listaSimpleDeTemas);
    vaciarListaCircular(&punterosAListaYArchivoDeTemas.listaCircularDeTemas);///IMPLEMENTAR PRIMITIVA en listaCircular.c
    fclose(punterosAListaYArchivoDeTemas.aListaDeTemas);

    return 0;
}
