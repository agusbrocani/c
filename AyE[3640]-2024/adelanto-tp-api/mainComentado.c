#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
//#include "CJSON.h"
//shift + f2

#define CANT_BYTES_MEMORIA_RESERVADA 10000

#define NO_PUDE_HACER_REALLOC 0
#define NO_PUDE_RESERVAR_MEMORIA 1
#define ERROR_INICIAR_ESTRUCTURA_CURL -1
#define ERROR_SOLICITUD_HTTP_EASY_PERFORM -2

///funcion de CALLBACK: cuando pase algo, va a ejecutar esa funcion.
//El servidor devuelve una porcion de los datos en cada solicitud[NO ENVIA TODO DE UNA]
//acá le puedo dar manejo
///SI NO USO el parametro CURLOPT_WRITEFUNCTION, POR DEFECTO lo saca por stdout


/**
    return: size_t que representa cantidad de bytes procesados en
    la funcion datosObtenidosDeRespuestaURL.

    char* bufferParaDatosRecibidos: donde se almacena la respuesta
    [NO DEBO PROPORCIONARLO, me lo da curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL);]

    size_t itemSize cantidad de bytes

    size_t nItems casi siempre va a ser 1

    void* si necesito info extra en esta funcion, la puedo enviar aca,
    para poder utilizar ese parametro, necesito usar
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, parametroPasadoDePrueba);

    LUEGO DECIR QUE VOY A MANEJAR LA RESPONSE CON FUNCION DE CALLBACK: va a rescatar la info
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL);

*/
typedef struct
{
    void* buffer;
    size_t cantBytesCopiados;
    size_t cantBytesReservados;
}tDatoRecibidoReconstruido;

size_t datosObtenidosDeRespuestaURL(char* bufferParaDatosRecibidos, size_t itemSize, size_t nItems, void* sDato)
{
    size_t cantidadDeBytesRecibidos = itemSize * nItems; //porque a veces nItems puede no ser 1[calculo cantBytes reales]

    while(
       cantidadDeBytesRecibidos > ((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados - ((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados
       )
    {
        (((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados) += CANT_BYTES_MEMORIA_RESERVADA;
        ((tDatoRecibidoReconstruido*)sDato)->buffer = realloc(((tDatoRecibidoReconstruido*)sDato)->buffer, ((tDatoRecibidoReconstruido*)sDato)->cantBytesReservados);

        if(NULL == ((tDatoRecibidoReconstruido*)sDato)->buffer)
        {
            return NO_PUDE_HACER_REALLOC;
        }
    }

    memcpy(((tDatoRecibidoReconstruido*)sDato)->buffer + ((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados , bufferParaDatosRecibidos, cantidadDeBytesRecibidos);
    (((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados) += cantidadDeBytesRecibidos;
    ((char*)(((tDatoRecibidoReconstruido*)sDato)->buffer))[((tDatoRecibidoReconstruido*)sDato)->cantBytesCopiados] = '\0';

    return cantidadDeBytesRecibidos;
}

int main()
{
    CURL* curl = curl_easy_init();//curl es un controlador[ABRO CONEXION A LA API]
    char url[] = "https://jsonplaceholder.typicode.com/users";
    tDatoRecibidoReconstruido dato;//capto response del servidor
    void* iniMemoriaReservada;
    ///manejo de errores de CURL
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
        fprintf(stderr, "init fallo\n");
        free(iniMemoriaReservada);
        return ERROR_INICIAR_ESTRUCTURA_CURL;
    }

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); ///ESTA OPCION NO ES RECOMENDADA PARA PRODUCCION: esta aca para poder ejecutar y ver algo

    ///SETEO DE OPCIONES: cada curl_easy_setopt configura la estructura a la que apunta CURL* curl
    //CURLOPT_URL:
    //opcion de configuracion[configuro el puntero a estructura curl]
    //sirve para especificar a que URL voy a hacer SOLICITUD HTTP
    //url es una cadena que yo envio con la URL real del sitio web

    curl_easy_setopt(curl, CURLOPT_URL, url);

    /**
        ESTAS 2 LINEAS SON NECESARIAS POR LO SIGUIENTE:
        Si no las pongo, a veces recibo json completo y a veces no.
        Me corta la conexion antes de recibir todo, con esto le doy mas tiempo
    */
    // Configurar un timeout general de 30 segundos para toda la transferencia
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
    // Configurar un timeout de conexión de 10 segundos
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);


    ///enviar parametro adicional de cualquier tipo a mi funcion de callback
    /**
        BUENA IDEA: USAR UNA ESTRUCTURA, PARA PODER ENVIAR MUCHA MAS INFO MEDIANTE
        UN SOLO PARAMETRO
    */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dato);
    //IMPORTANTE: C es secuencial, hasta que no se complete esta linea, no pasara a la siguiente,
    //por lo tanto, primero recibo TODA la info de la API[viene en rafagas]
    //y luego paso a la siguiente linea
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, datosObtenidosDeRespuestaURL);

    ///REALIZAR ACCION QUE REQUIERO
    //Por defecto: toma la estructura y realiza solicitud a url descargando contenido[puede fallar]
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


















/////COMO EMPEZAR
//
//int main()
//{
//    //CURL es un struct para realizar solicitudes HTTP
//    //return NULL si la inicializacion falla
//    CURL* curl = curl_easy_init();
//
//    if(NULL == curl)
//    {
//        fprintf(stderr, "init fallo\n");
//        return ERROR_INICIAR_ESTRUCTURA_CURL;
//    }
//
//    ///SETEO DE OPCIONES
//
//    ///REALIZAR ACCION QUE REQUIERO
//
//    curl_easy_cleanup(curl);
//    //libera memoria y cierra conexiones iniciadas con curl_easy_init
//    //evita memory leaks
//    return 0;
//}
