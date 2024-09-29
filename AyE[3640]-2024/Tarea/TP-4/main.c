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
      "[3]Crear playlist circular.",
      "[4]Reproducir playlist circular.",
      "[5]Guardar playlist circular en archivo de texto."
    };
    unsigned cantidadDeRegistros = sizeof(textoMenuPrincipal) / MAX_TAM_TEXTO;

    crearArchivoBinarioDeTemas();
    if(!abrirArchivo(&punterosAListaYArchivoDeTemas.aListaDeTemas, NOMBRE_ARCHIVO_BINARIO_LISTA_DE_TEMAS, "rb"))
    {
        return NO_PUDE_ABRIR_ARCHIVO_ARCHIVO_BINARIO_LISTA_DE_TEMAS;
    }

    punterosAListaYArchivoDeTemas.cantidadDePlaylistGrabadasEnArchivo = 1;
    crearListaSimple(&punterosAListaYArchivoDeTemas.listaSimpleDeTemas);
    crearListaCircular(&punterosAListaYArchivoDeTemas.listaCircularDeTemas);

    menu(textoMenuPrincipal, cantidadDeRegistros, switchMenuPrincipal, &punterosAListaYArchivoDeTemas, DESACTIVAR_AYUDA_AL_USUARIO);

    vaciarListaSimple(&punterosAListaYArchivoDeTemas.listaSimpleDeTemas);
    vaciarListaCircular(&punterosAListaYArchivoDeTemas.listaCircularDeTemas);
    fclose(punterosAListaYArchivoDeTemas.aListaDeTemas);

    return 0;
}
