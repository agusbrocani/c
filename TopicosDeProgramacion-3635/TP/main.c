#include "tp.h"

int main()
{
    tPatente lectura;
    long tamArchivo;
    long cantRegistros;
    //long double raw = 1;

    FILE* pf = fopen("../archivosBinarios/registros","rb");

    if(!pf)
    {
        printf("No pude abrir el archivo\n");
        return 1;
    }

    fread(&lectura,sizeof(tPatente),1,pf);

    while(          !feof(pf)           )
    {
        printf("Patente: %s\nNro Cuota: %d\nNya: %s\nDNI: %d\nFecha->\tDia: %d Mes: %d Anio: %d\nImporte: U$D %.2f\n",lectura.patente,lectura.nroCuota,lectura.nya,lectura.dni,
               lectura.fVencimiento.dia,lectura.fVencimiento.mes,lectura.fVencimiento.anio,lectura.importe);
        printf("\n");
        fread(&lectura,sizeof(tPatente),1,pf);
    }
    rewind(pf);

    fseek(pf, 0, SEEK_END);

    tamArchivo = ftell(pf);
    cantRegistros = tamArchivo/sizeof(tPatente);
    rewind(pf);

    printf("Tam del archivo en bytes:\t\t%li\n",tamArchivo);
    printf("Cantidad de registros del archivo:\t%li\n",cantRegistros);

/*
    printf("ld with lf = %.335Lf \n",CORRECTION_RAW(raw));
    printf("ld with lg = %.335Lg \n",CORRECTION_RAW(raw));
    printf("ld with le = %.335Le \n",CORRECTION_RAW(raw));
*/


    fclose(pf);


    /**
    int endianness = checkEndianness();

    if (endianness == 1)
    {
        printf("El hardware utiliza el formato little-endian.\n");
        // Aquí puedes realizar el ajuste necesario para el formato big-endian si es necesario.
    }
    else if (endianness == 0)
        {
            printf("El hardware utiliza el formato big-endian.\n");
        // Aquí puedes realizar el ajuste necesario para el formato little-endian si es necesario.
        }
        else
        {
            printf("El formato del hardware es desconocido o inusual.\n");
            // Manejo de error si el formato no es reconocido.
        }
    */
    return 0;
}

/**
    FILE* pf;
    long tamArchivo;
    long cantRegistros;

    pf = fopen("HKTMST.bin","rb");

    if(         !pf         )
    {
        printf("No se pudo abrir el archivo\n");
    }

    fseek(pf, 0, SEEK_END);
    tamArchivo = ftell(pf);

    if(         0 != tamArchivo % 4000            )
    {
        printf("Abortando el proceso...\n");
        return 0;
    }
    cantRegistros = tamArchivo/4000;    // 4000 puede ser sizeof(tDato)
    rewind(pf);

    printf("Tam del archivo en bytes:\t\t%li\n",tamArchivo);
    printf("Cantidad de registros del archivo:\t%li\n",cantRegistros);

    fclose(pf);

*/
