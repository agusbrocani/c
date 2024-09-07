#include "../include/generico.h"

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        fprintf(stderr,"No pude abrir/crear el archivo: %s\n", nombreArchivo);
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    return OK;
}
