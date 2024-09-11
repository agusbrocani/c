#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define CANT_BYTES_MEMORIA_RESERVADA 10000

#define NO_PUDE_HACER_REALLOC 0
#define NO_PUDE_RESERVAR_MEMORIA 1
#define ERROR_INICIAR_ESTRUCTURA_CURL -1
#define ERROR_SOLICITUD_HTTP_EASY_PERFORM -2

#define URL "https://jsonplaceholder.typicode.com/users"
#define CERTIFICADO_SITIO_SEGURO "./CERTIFICADO-SITIO-jsonplaceholder.pem"


typedef struct
{
    void* buffer;
    size_t cantBytesCopiados;
    size_t cantBytesReservados;
}tReconstruccionDato;

size_t datosObtenidosDeRespuestaURL(const char* bufferParaDatosRecibidos, size_t itemSize, size_t nItems, void* sDato)
{
    size_t cantidadDeBytesRecibidos = itemSize * nItems;
    void* returnRealloc;

    while(
       cantidadDeBytesRecibidos > ((tReconstruccionDato*)sDato)->cantBytesReservados - ((tReconstruccionDato*)sDato)->cantBytesCopiados
       )
    {
        (((tReconstruccionDato*)sDato)->cantBytesReservados) += CANT_BYTES_MEMORIA_RESERVADA;
        returnRealloc = realloc(((tReconstruccionDato*)sDato)->buffer, ((tReconstruccionDato*)sDato)->cantBytesReservados);

        if(NULL == returnRealloc)
        {
            return NO_PUDE_HACER_REALLOC;
        }
        ((tReconstruccionDato*)sDato)->buffer = returnRealloc;
    }

    memcpy(((tReconstruccionDato*)sDato)->buffer + ((tReconstruccionDato*)sDato)->cantBytesCopiados , bufferParaDatosRecibidos, cantidadDeBytesRecibidos);
    (((tReconstruccionDato*)sDato)->cantBytesCopiados) += cantidadDeBytesRecibidos;
    ((char*)(((tReconstruccionDato*)sDato)->buffer))[((tReconstruccionDato*)sDato)->cantBytesCopiados] = '\0';

    return cantidadDeBytesRecibidos;
}

int main()
{
    CURL* curl;
    CURLcode resultadoDeSolicitudHTTP;
    tReconstruccionDato dato;

    dato.buffer = malloc(CANT_BYTES_MEMORIA_RESERVADA);
    if(NULL == dato.buffer)
    {
        fprintf(stderr,"No pude reservar memoria.");
        return NO_PUDE_RESERVAR_MEMORIA;
    }
    *((char*)(dato.buffer)) = '\0';
    dato.cantBytesReservados = CANT_BYTES_MEMORIA_RESERVADA;
    dato.cantBytesCopiados = 0;

    curl = curl_easy_init();    //RESERVO RECURSOS PARA REALIZAR CONFIGURACIONES DE REQUEST
    if(NULL == curl)
    {
        fprintf(stderr, "Fallo init.\n");
        free(dato.buffer);
        return ERROR_INICIAR_ESTRUCTURA_CURL;
    }

    //CONFIGURACION DE LOS RECURSOS RESERVADOS PARA HACER LA REQUEST
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_CAINFO, CERTIFICADO_SITIO_SEGURO);
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dato);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL);

    //SE HACE LA REQUEST Y SE REALIZA MANEJO DE ERRORES POR SI FALLA
    resultadoDeSolicitudHTTP = curl_easy_perform(curl);
    if(CURLE_OK != resultadoDeSolicitudHTTP)
    {
        fprintf(stderr, "Fallo descargando con solicitud HTTP: %s.\n", curl_easy_strerror(resultadoDeSolicitudHTTP));
        curl_easy_cleanup(curl);    //LIBERO RECURSOS RESERVADOS
        free(dato.buffer);
        return ERROR_SOLICITUD_HTTP_EASY_PERFORM;
    }

    fprintf(stdout, "%s",(char*)(dato.buffer)); //VERIFICACION VISUAL DE QUE SE RECIBIO CORRECTAMENTE LA INFO

    curl_easy_cleanup(curl);    //LIBERO RECURSOS RESERVADOS
    free(dato.buffer);

    return 0;
}
