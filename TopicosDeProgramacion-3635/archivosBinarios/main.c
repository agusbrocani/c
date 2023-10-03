#include "archivosBinarios.h"

int main()
{
    FILE* pf;   ///F116 : INICIO ARCHIVO
    tPatente unRegistro;

    crearLote();
    if(!abrirArchivo(&pf,"registros","rb"))
    {
        printf("No pude abrir el archivo");
        return 0;
    }

    mostrarArchivoBinario(pf,&unRegistro,sizeof(tPatente),mostrarTPatente);

    fclose(pf); ///¿Cómo sabe cerrar el archivo si esta apuntando al ultimo registro?

    return 0;
}
/*
printf("Patente: %s\nNro Cuota: %d\nNya: %s\nDNI: %d\nFecha->\tDia: %d Mes: %d Anio: %d\nImporte: U$D %.2f\n",unRegistro.patente,unRegistro.nroCuota,unRegistro.nya,unRegistro.dni,
               unRegistro.fVencimiento.dia,unRegistro.fVencimiento.mes,unRegistro.fVencimiento.anio,unRegistro.importe);
*/
