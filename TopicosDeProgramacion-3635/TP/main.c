#include "tp.h"
///32398 REGISTROS

int main()
{
    FILE* pfDatos;
    FILE* resultados;
    void* lectura;
    void* iniLectura;
    unsigned cantBytesArchivo;
    int endianness;
    unsigned short vBatAverage;
    double volts;
    unsigned horaYFecha;

    if(         !abrirArchivo(&pfDatos,"HKTMST.bin","rb")         )
    {
        printf("ERROR1\n");
        return 1;
    }

    if(         !abrirArchivo(&resultados,"resultados.txt","wt")         )
    {
        printf("ERROR2\n");
        fclose(resultados);
        return 1;
    }

    endianness = checkEndianness();

    if(         -1 == endianness            )
    {
        fclose(pfDatos);
        fclose(resultados);
        return 1;
    }

    fseek(pfDatos,0,SEEK_END);
    cantBytesArchivo = ftell(pfDatos);
    rewind(pfDatos);

    if(         0 != cantBytesArchivo % 4000           )
    {
        fclose(pfDatos);
        fclose(resultados);
        return 1;
    }

    lectura = malloc( TAM_REGISTRO );
    iniLectura = lectura;

    if(         !lectura            )
    {
        printf("No pude reservar memoria\n");
        fclose(pfDatos);
        fclose(resultados);
        return 1;
    }


    fread(lectura,TAM_REGISTRO,1,pfDatos);

    while(          !feof(pfDatos)           )
    {
        if(         1 == endianness         )
        {
            swapRegister(lectura,TAM_REGISTRO);
        }

        memcpy(&vBatAverage,lectura+PCS+OFFSET_V_BAT_AVERAGE,2);    ///vBatAverage recibe correctamente los 2 bytes[ya está probado]
        volts = CORRIGE_RAW(vBatAverage);

        if (            volts >= LI_V && volts <= LS_V          )
        {
            printf("Voltaje: %.2lf\n", volts);
            ///GRABO RESULTADOS EN ARCHIVO TXT "resultados.txt", tengo el FILE* resultados
        }
        else
        {
            printf("ERROR: Voltaje fuera de rango\n");
        }

        memcpy(&horaYFecha,lectura+CDH+OFFSET_OBT,4);
        printf("Hora y fecha: %u\n",horaYFecha);

        fread(lectura,TAM_REGISTRO,1,pfDatos);
    }

    free(iniLectura);
    fclose(pfDatos);
    fclose(resultados);
    return 0;
}
