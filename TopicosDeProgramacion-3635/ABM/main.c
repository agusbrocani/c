#include "ABM.h"

int main()
{
    FILE* pfMaster;
    FILE* pfNovelties;
    FILE* pfTemp;

    createBatch("master.dat", "wb", createEmployeeBatch);
    createBatch("novelties.dat", "wb", createNoveltiesBatch);

    if(         openFile(&pfMaster,"master.dat","rb")         )
    {
        printf("No pude abrir el archivo master.dat\n");
    }

    if(         openFile(&pfNovelties,"novelties.dat","rb")         )
    {
        printf("No pude abrir el archivo Novelties.dat\n");
        fclose(pfMaster);
    }

    if(         openFile(&pfTemp,"temp.dat","w+b")          )
    {
        printf("No pude abrir el archivo temp.dat\n");
        fclose(pfMaster);
        fclose(pfNovelties);
    }

    ///NO ES NECESARIO, PERO POR LAS DUDAS QUE HAGA OTRAS OPERACIONES ANTES
    rewind(pfMaster);
    rewind(pfNovelties);
    rewind(pfTemp);
    updateFile(pfMaster,pfNovelties,pfTemp, compareDNI, updateEmp);

    tEmployee lectura;

    rewind(pfTemp);
    fread(&lectura,sizeof(tEmployee),1,pfTemp);

    while(!feof(pfTemp))
    {
        showEmployee(&lectura);
        fread(&lectura,sizeof(tEmployee),1,pfTemp);
    }

    fclose(pfMaster);
    fclose(pfNovelties);
    fclose(pfTemp);

    remove("master.dat");
    rename("temp.dat","master.dat");

    return 0;
}
