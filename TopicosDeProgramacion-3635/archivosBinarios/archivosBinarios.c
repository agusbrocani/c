#include "archivosBinarios.h"

void crearLote()
{
    FILE* pf;
    tPatente patentes[] =
    {
        {"AA100XU",52,"Federico Martucci",42123456,{2023,10,9},375.22 },
        {"FUT316",350,"Simon Bombon",45123456,{2024,12,9},50000 },
        {"NWO870",100,"Agustin Brocani",40123456,{2023,11,15},105.5 },
        {"ABC123",999,"Carlos Maidana",10123456,{2023,11,22},17.9 },
        {"AG777GD",1,"Pablo Soligo",20123456,{2023,10,10},500.5 }
    };

    pf = fopen("registros","wb");

    if(!pf)
    {
        printf("PROBLEMA\n");
        return;
    }

    fwrite(patentes,sizeof(patentes),1,pf);

    fclose(pf);
}

int abrirArchivo(FILE** pf,const char* nombreArchivo,const char* modo)
{
    *pf = fopen(nombreArchivo,modo);

    if(!*pf)
    {
        printf("No pude abrir/crear el archivo\n");
        return 0;
    }

    return 1;
}

void mostrarTPatente(const void* dato)
{
    printf("Patente: %s\nNro Cuota: %d\nNya: %s\nDNI: %d\nFecha->\tDia: %02d Mes: %02d Anio: %02d\nImporte: U$D %.2f\n",   ((tPatente*)dato)->patente,
                                                                                                                           ((tPatente*)dato)->nroCuota,
                                                                                                                           ((tPatente*)dato)->nya,
                                                                                                                           ((tPatente*)dato)->dni,
                                                                                                                           ((tPatente*)dato)->fVencimiento.dia,
                                                                                                                           ((tPatente*)dato)->fVencimiento.mes,
                                                                                                                           ((tPatente*)dato)->fVencimiento.anio,
                                                                                                                           ((tPatente*)dato)->importe);
}

void mostrarArchivoBinario(FILE* pf,void* dato,unsigned tam, void (*mostrar)(const void* dato))
{
    fread(dato,tam,1,pf);
    while(!feof(pf))    ///MIENTRAS NO SEA NULL[file end of file]
    {
        mostrar(dato);
        printf("\n");
        //system("pause");
        //system("cls");//solo para windows, borra lo que mostre por consola
        //system("shutdown /r"); //solo para simon bombon, te reinicia el windows literal
        fread(dato,tam,1,pf);
    }
    rewind(pf); ///Como movi el puntero file, lo mando al comienzo nuevamente
}
