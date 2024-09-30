#include "reproductorConListaCircular.h"

int main()
{
    tRecursosMenu punteroAArchivoPunterosAListasBufferYContador;
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
    if(!abrirArchivo(&punteroAArchivoPunterosAListasBufferYContador.aListaDeTemas, NOMBRE_ARCHIVO_BINARIO_LISTA_DE_TEMAS, "rb"))
    {
        return NO_PUDE_ABRIR_ARCHIVO_ARCHIVO_BINARIO_LISTA_DE_TEMAS;
    }

    punteroAArchivoPunterosAListasBufferYContador.cantidadDePlaylistGrabadasEnArchivo = 0;
    crearListaSimple(&punteroAArchivoPunterosAListasBufferYContador.listaSimpleDeTemas);
    crearListaCircular(&punteroAArchivoPunterosAListasBufferYContador.listaCircularDeTemas);

    menu(textoMenuPrincipal, cantidadDeRegistros, switchMenuPrincipal, &punteroAArchivoPunterosAListasBufferYContador, DESACTIVAR_AYUDA_AL_USUARIO);

    vaciarListaSimple(&punteroAArchivoPunterosAListasBufferYContador.listaSimpleDeTemas);
    vaciarListaCircular(&punteroAArchivoPunterosAListasBufferYContador.listaCircularDeTemas);
    fclose(punteroAArchivoPunterosAListasBufferYContador.aListaDeTemas);

    return 0;
}
