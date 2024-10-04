#include "configuraciones.h"

void mostrarConfiguracionElegida(tConfiguracion* configuracion, unsigned indiceDeNivelDeConfiguracionElegida)
{
    printf("Configuracion seleccionada:\n");
    printf("\tNivel de dificultad: %s.\n",
           INDICE_NIVEL_FACIL == indiceDeNivelDeConfiguracionElegida ? "FACIL" : INDICE_NIVEL_MEDIO == indiceDeNivelDeConfiguracionElegida ? "MEDIO" : "DIFICIL"
          );
    printf("\tTiempo de visualizacion de secuencia: %u.\n", configuracion[indiceDeNivelDeConfiguracionElegida].tiempoDeVisualizacionSecuenciaCorrecta);
    printf("\tTiempo de respuesta: %u.\n", configuracion[indiceDeNivelDeConfiguracionElegida].tiempoRespuestaPorRonda);
    printf("\tCantidad de vidas: %u.\n", configuracion[indiceDeNivelDeConfiguracionElegida].cantidadDeVidas);
}

int cargarConfiguraciones(FILE* aConfiguracion, tConfiguracion* configuraciones)
{
    char buffer[TAM_BUFFER_CARGA_CONFIGURACIONES];
    unsigned indice;

    while(fgets(buffer, TAM_BUFFER_CARGA_CONFIGURACIONES, aConfiguracion))
    {
        if(INDICE_INVALIDO == (indice = defineIndiceDeNivelSegunCaracter(*buffer)))
        {
            fprintf(stderr, "Error de grabacion de archivo de configuraciones: LETRA INICIAL INCORRECTA.\n");
            return ARCHIVO_TXT_DE_CONFIGURACION_CON_ERRORES;
        }

        sscanf(buffer, "%*c|%u|%u|%u",
            &(configuraciones[indice].tiempoDeVisualizacionSecuenciaCorrecta),
            &(configuraciones[indice].tiempoRespuestaPorRonda),
            &(configuraciones[indice].cantidadDeVidas)
        );//%*c ignora la primer letra

        if(
            !(configuraciones[indice].tiempoDeVisualizacionSecuenciaCorrecta > MIN_TIEMPO_JUEGO_POR_RONDA && configuraciones[indice].tiempoDeVisualizacionSecuenciaCorrecta <= MAX_TIEMPO_JUEGO_POR_RONDA) ||
            !(configuraciones[indice].tiempoRespuestaPorRonda > MIN_TIEMPO_JUEGO_POR_RONDA && configuraciones[indice].tiempoRespuestaPorRonda <= MAX_TIEMPO_JUEGO_POR_RONDA) ||
            !(configuraciones[indice].cantidadDeVidas >= MIN_CANT_VIDAS && configuraciones[indice].cantidadDeVidas <= MAX_CANT_VIDAS)
        )
        {
            fprintf(stderr, "Error de grabacion de archivo de configuraciones: VALORES FUERA DE RANGO.\n");
            return ARCHIVO_TXT_DE_CONFIGURACION_CON_ERRORES;
        }
    }
    return OK;
}
