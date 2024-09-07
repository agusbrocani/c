#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define CANT_BYTES_MEMORIA_RESERVADA 10000

#define NO_PUDE_HACER_REALLOC 0
#define NO_PUDE_RESERVAR_MEMORIA 1
#define ERROR_INICIAR_ESTRUCTURA_CURL -1
#define ERROR_SOLICITUD_HTTP_EASY_PERFORM -2

typedef struct
{
    void* buffer;
    size_t cantBytesCopiados;
    size_t cantBytesReservados;
}tDatoRecibidoReconstruido;

size_t datosObtenidosDeRespuestaURL(char* bufferParaDatosRecibidos, size_t itemSize, size_t nItems, void* sDato)
{
    size_t cantidadDeBytesRecibidos = itemSize * nItems;

    while(
       cantidadDeBytesRecibidos > ((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados - ((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados
       )
    {
        ((tDatoRecibidoReconstruido*)sDato)->buffer = realloc(((tDatoRecibidoReconstruido*)sDato)->buffer, ((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados);

        if(NULL == ((tDatoRecibidoReconstruido*)sDato)->buffer)
        {
            return NO_PUDE_HACER_REALLOC;
        }
        (((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados) += CANT_BYTES_MEMORIA_RESERVADA;
    }

    memcpy(((tDatoRecibidoReconstruido*)sDato)->buffer + ((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados , bufferParaDatosRecibidos, cantidadDeBytesRecibidos);
    (((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados) += cantidadDeBytesRecibidos;
    ((char*)(((tDatoRecibidoReconstruido*)sDato)->buffer))[((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados] = '\0';

    return cantidadDeBytesRecibidos;
}

int main()
{
    CURL* curl = curl_easy_init();//ABRO CONEXION A LA API
    char url[] = "https://jsonplaceholder.typicode.com/users";
    tDatoRecibidoReconstruido dato;
    void* iniMemoriaReservada;
    CURLcode resultadoDeSolicitudHTTP;

    dato.buffer = malloc(CANT_BYTES_MEMORIA_RESERVADA);
    dato.cantBytesReservados = CANT_BYTES_MEMORIA_RESERVADA;
    dato.cantBytesCopiados = 0;

    if(NULL == dato.buffer)
    {
        return NO_PUDE_RESERVAR_MEMORIA;
    }
    iniMemoriaReservada = dato.buffer;

    if(NULL == curl)
    {
        fprintf(stderr, "fallo init\n");
        free(iniMemoriaReservada);
        return ERROR_INICIAR_ESTRUCTURA_CURL;
    }

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dato);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL);

    resultadoDeSolicitudHTTP = curl_easy_perform(curl);
    if(CURLE_OK != resultadoDeSolicitudHTTP)
    {
        fprintf(stderr, "fallo descargando con solicitud HTTP: %s\n", curl_easy_strerror(resultadoDeSolicitudHTTP));
        curl_easy_cleanup(curl);
        free(iniMemoriaReservada);
        return ERROR_SOLICITUD_HTTP_EASY_PERFORM;
    }

    fprintf(stdout, "%s",(char*)(dato.buffer));

    curl_easy_cleanup(curl);//CIERRO CONEXION A LA API
    free(iniMemoriaReservada);

    return 0;
}
