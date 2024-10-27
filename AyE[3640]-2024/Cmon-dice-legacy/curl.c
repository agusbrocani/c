#include "curl.h"

/// firma de funci�n de la biblioteca curl
size_t datosObtenidosDeRespuestaURL(const char* bufferParaDatosRecibidos, size_t itemSize, size_t nItems, void* sDato)
{
    size_t cantidadDeBytesRecibidos = itemSize * nItems;
    void* returnRealloc;
    //+1 para el \0, por las dudas
    while(
        (cantidadDeBytesRecibidos + 1) > ((tReconstruccionDato*)sDato)->cantBytesReservados - ((tReconstruccionDato*)sDato)->cantBytesCopiados
    )
    {
        (((tReconstruccionDato*)sDato)->cantBytesReservados) += (((tReconstruccionDato*)sDato)->cantBytesFijosAReservar);
        returnRealloc = realloc(((tReconstruccionDato*)sDato)->buffer, ((tReconstruccionDato*)sDato)->cantBytesReservados);
        if(NULL == returnRealloc)
        {
            fprintf(stderr, "No pude hacer realloc.\n");
            return NO_PUDE_HACER_REALLOC;
        }
        ((tReconstruccionDato*)sDato)->buffer = returnRealloc;
    }

    memcpy(((tReconstruccionDato*)sDato)->buffer + ((tReconstruccionDato*)sDato)->cantBytesCopiados, bufferParaDatosRecibidos, cantidadDeBytesRecibidos);
    (((tReconstruccionDato*)sDato)->cantBytesCopiados) += cantidadDeBytesRecibidos;
    (((tReconstruccionDato*)sDato)->buffer)[((tReconstruccionDato*)sDato)->cantBytesCopiados] = '\0'; // se agrega el \0 por seguridad, en caso de que la API no lo haga.

    return cantidadDeBytesRecibidos;
}

int inicializacionEstructuraCURL(CURL** curl)
{
    *curl = curl_easy_init();
    if(NULL == *curl)
    {
        fprintf(stderr, "No pude inicializar estructura CURL.\n");
        return ERROR_INICIAR_ESTRUCTURA_CURL;
    }

    return OK;
}

void configuracionEstructuraCURL(CURL* curl, const char* URL, void* dato)
{
    /* Activar el SSL, para que la comunicaci�n sea segura */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_CAINFO, CERTIFICADO_SITIO_SEGURO);
    curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_3);//feat: asegurarme que utilizo TLS[la version 1.3 utiliza mejores algoritmos de cifrado] y no SSL porque esta obsoleto, tiene vulnerabilidades[La macro se llama SSL por motivos historicos, pero es TLS].

    curl_easy_setopt(curl, CURLOPT_URL, URL); //utiliza la url que se arm� con los par�metros especificados

    /* configuraci�n de time out*/
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

    /* 'dato' es toda la estructura tReconstruccionDato de curl.h*/
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, dato); // le manda la estructura para que sepa d�nde almacenar la respuesta. Esta estructura ser� la que manejaremos para las jugadas.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL); /// funci�n que realiza todo el trabajo de almacenar la respuesta
}

int ejecutarSolicitudHTTPS(CURL* curl)
{
    CURLcode resultadoDeSolicitudHTTPS; // de la biblioteca curl, para mostrar el error.
    long codigoDeRepuestaHTTPS = 0;

    resultadoDeSolicitudHTTPS = curl_easy_perform(curl); // se manda el curl configurado en la funci�n configuracionEstructuraCURL.
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &codigoDeRepuestaHTTPS); // para obtener informaci�n sobre el tipo de error.
    if(CURLE_OK != resultadoDeSolicitudHTTPS)
    {
        fprintf(stderr, "Fallo en la solicitud HTTPS: %s.\n", curl_easy_strerror(resultadoDeSolicitudHTTPS));
    }

    return codigoDeRepuestaHTTPS;
}
