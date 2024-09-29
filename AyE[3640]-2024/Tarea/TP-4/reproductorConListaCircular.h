#ifndef REPRODUCTORCONLISTACIRCULAR_H_INCLUDED
#define REPRODUCTORCONLISTACIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "./Biblioteca/include/listaSimple/listaSimple.h"
#include "./Biblioteca/include/listaCircular/listaCircular.h"
#include "./Biblioteca/include/menu/menu.h"
#include "./Biblioteca/include/generico.h"

#define NOMBRE_ARCHIVO_BINARIO_LISTA_DE_TEMAS "temas.dat"
#define CE_TEMAS 97

///MENU PRINCIPAL
#define CREAR_LISTA_SIMPLE_DE_TEMAS_ORDENADA_SEGUN_CRITERIO 1
#define MEZCLAR_LISTA_SIMPLE_DE_TEMAS 2
#define CREAR_PLAYLIST_CIRCULAR 3
#define REPRODUCIR_PLAYLIST_CIRCULAR 4
#define GUARDAR_PLAYLIST_CIRCULAR_EN_ARCHIVO_DE_TEXTO 5

///SUBMENU INSERTAR ORDENADO EN LISTA SIMPLE
#define INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_AUTOR 1
#define INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_TEMA 2
#define INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_DURACION 3
#define VACIAR_LISTA_SIMPLE_DE_TEMAS 4

///SUBMENU CREAR PLAYLIST CIRCULAR
#define INSERTAR_LISTA_CIRCULAR_DE_TEMAS 1
#define CAMBIAR_DE_LUGAR_LISTA_CIRCULAR_DE_TEMAS 2
#define ELIMINAR_TEMA_LISTA_CIRCULAR_DE_TEMAS 3
#define VACIAR_LISTA_CIRCULAR_DE_TEMAS 4

#define TAM_AUTOR 100
#define TAM_TEMA 100
typedef struct
{
    char autor[TAM_AUTOR];
    char tema[TAM_TEMA];
    unsigned duracion;
}tListaDeTemas;

typedef struct
{
    FILE* aListaDeTemas;
    t_lista listaSimpleDeTemas;
    t_lista listaCircularDeTemas;
    tListaDeTemas tema;
}tRecursosMenu;

void crearArchivoBinarioDeTemas();

void mostrarTema(const void* dato);
int comparaTemasSegunAutor(const void* a, const void* b);
int comparaTemasSegunNombreTema(const void* a, const void* b);
int comparaTemasSegunDuracion(const void* a, const void* b);

void switchSubMenuListaSimpleOrdenadaSegunCriterio(int opcion, void* estructuraTDA);
void crearListaSimpleOrdenadaSegunCriterio(void* estructuraTDA);

void switchSubMenuCrearPlaylistCircular(int opcion, void* estructuraTDA);
void crearPlaylistCircular(void* estructuraTDA);

void switchMenuPrincipal(int opcion, void* estructuraTDA);

#endif // REPRODUCTORCONLISTACIRCULAR_H_INCLUDED
