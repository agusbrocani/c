#include "../../include/loteEmpleados/archivoEmpleados.h"

int leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam)
{
    char bufferLectura[TAM_BUFFER_LECTURA];

    if(NULL != fgets(bufferLectura, TAM_BUFFER_LECTURA, pf))
    {
        sscanf(bufferLectura, "%2d%50[^\n]%c%f",
               &((tEmpleado*)dato)->id,
               ((tEmpleado*)dato)->nya,
               &((tEmpleado*)dato)->sexo,
               &((tEmpleado*)dato)->salario
               );
        return HAY_REGISTROS_POR_LEER;
    }

    return FIN_DE_ARCHIVO;
}

void trozar(void* dato, char* cadena)
{
    ///10-Lionel Messi-M-999\n\0
    char* iniCadena = cadena;

    cadena = strrchr(iniCadena, '\n');
    if(NULL != cadena)
    {
        *cadena = '\0';
    }
    ///10-Lionel Messi-M-999\0\0

    cadena = strrchr(iniCadena, '-');
    if(NULL != cadena)
    {
        *cadena = '\0';
    }
    ///10-Lionel Messi-M\0999\0\0
    cadena++;
    ((tEmpleado*)dato)->salario = atof(cadena);

    cadena = strrchr(iniCadena, '-');
    if(NULL != cadena)
    {
        *cadena = '\0';
        cadena++;
        ((tEmpleado*)dato)->sexo = *cadena;
    }
    ///10-Lionel Messi\0M\0999\0\0

    cadena = strrchr(iniCadena, '-');
    if(NULL != cadena)
    {
        *cadena = '\0';
        cadena++;
        strcpy(((tEmpleado*)dato)->nya, cadena);
    }
    ///10\0Lionel Messi\0M\0999\0\0

    ((tEmpleado*)dato)->id = atoi(iniCadena);
}

int leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam)
{
    char bufferLectura[TAM_BUFFER_LECTURA];

    if(NULL != fgets(bufferLectura, TAM_BUFFER_LECTURA, pf))
    {
        trozar(dato, bufferLectura);

//        Forma alternativa a trozar:
//        sscanf(bufferLectura, "%d-%[^-]-%c-%f",
//               &((tEmpleado*)dato)->id,
//               ((tEmpleado*)dato)->nya,
//               &((tEmpleado*)dato)->sexo,
//               &((tEmpleado*)dato)->salario
//               );
//        (((tEmpleado*)dato)->nya)[TAM_NYA - 1] = '\0';

        return HAY_REGISTROS_POR_LEER;
    }

    return FIN_DE_ARCHIVO;
}
int leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam)
{
    fread(dato, tam, 1, pf);

    return feof(pf) ? FIN_DE_ARCHIVO : HAY_REGISTROS_POR_LEER;
}

void grabarDatoArchivoTxtLF(FILE* pf, const void* dato, unsigned tam)
{
    fprintf(pf, "%02d%-50s%c%9.2f\n",
            ((tEmpleado*)dato)->id,
            ((tEmpleado*)dato)->nya,
            ((tEmpleado*)dato)->sexo,
            ((tEmpleado*)dato)->salario
            );
}
void grabarDatoArchivoTxtLV(FILE* pf, const void* dato, unsigned tam)
{
    fprintf(pf, "%d-%s-%c-%.2f\n",
            ((tEmpleado*)dato)->id,
            ((tEmpleado*)dato)->nya,
            ((tEmpleado*)dato)->sexo,
            ((tEmpleado*)dato)->salario
            );
}
void grabarDatoArchivoBinario(FILE* pf, const void* dato, unsigned tam)
{
    fseek(pf, 0L, SEEK_CUR);
    fwrite(dato, tam, 1, pf);
}
