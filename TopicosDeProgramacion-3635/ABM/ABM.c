#include "ABM.h"

int compareDNI(const void* a, const void* b)
{
    return *(int*)a - *(int*)b ;
}

void showEmployee(const void* data){
    printf("Employee: \nDNI: \t\t%d\nSurname: \t%s\nName: \t\t%s\nSalary: \tU$D %.2f\n",    ((tEmployee*)data)->dni,
                                                                                            ((tEmployee*)data)->surname,
                                                                                            ((tEmployee*)data)->name,
                                                                                            ((tEmployee*)data)->salary);
    printf("=====================================================\n");
}

void showNovelty(const void* data){
    printf("Novelty: \nDNI: \t\t%d\nSurname: \t%s\nName: \t\t%s\nSalary: \tU$D %.2f\nType: \t\t%c\n",    ((tNovelty*)data)->employee.dni,
                                                                                                        ((tNovelty*)data)->employee.surname,
                                                                                                        ((tNovelty*)data)->employee.name,
                                                                                                        ((tNovelty*)data)->employee.salary,
                                                                                                        ((tNovelty*)data)->noveltyType);
    printf("=====================================================\n");
}

int createBatch(const char* fileName, const char* fileMode, int(*createTypeBatch)(const char*, const char*))
{
    return createTypeBatch(fileName, fileMode);
}

int openFile(FILE** filePointer, const char* fileName, const char* mode)
{
    *filePointer = fopen(fileName, mode);

    if(!*filePointer){
        perror("Oops! Something wrong occurred.");
        return FILE_ERR;
    }
    return OK;
}

int createEmployeeBatch(const char* fileName, const char* fileMode)
{
    tEmployee data[] =
    {
        {10123456, "Maidana", "Carlos", 40000.44},
        {20123456, "Soligo", "Pablo", 50000.55},
        {40123456, "Brocani", "Agustin", 30000.33},
        {42123456, "Martucci", "Federico", 10000.11},
        {44444444, "Cassiani", "Joaquin", 60000.66},
        {45123456, "Bombon", "Simon", 20000.22},
        {55555555, "Antelo", "Pedro", 70000.77},
        {66666666, "Vazquez", "Juan Cruz", 80000.88},
        {100000000, "Ruggieri", "Franco", 6666666.88},
        {100000001, "Ruggieri", "Franco1", 6666666.88},
        {100000002, "Ruggieri", "Franco2", 6666666.88},
        {100000003, "Ruggieri", "Franco3", 6666666.88},

    };

    FILE* filePointer;
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}
int createNoveltiesBatch(const char* fileName, const char* fileMode)
{
    tNovelty data[] =
    {
        {{10123456, "Maidana", "Carlos", 5555.44}, 'm'},
        {{11111111, "Freire", "Nacho", 40000.44}, 'a'},
        {{20123456, "Soligo", "Pablo", 50000.55}, 'b'},
        {{42123456, "Martucci", "Federico", 99999.99}, 'm'},
        {{45123456, "Bombon", "Simon", 20000.22}, 'b'},
        {{99999999, "Dougan", "Pablo", 60000.66}, 'b'}
    };

    FILE* filePointer;
    if(openFile(&filePointer, fileName, fileMode) == FILE_ERR)
        return FILE_ERR;
    fwrite(data, sizeof(data), 1, filePointer);

    fclose(filePointer);
    return OK;
}

void updateEmp(void* a, void* b)
{
    ((tEmployee*)a)->dni = ((tNovelty*)b)->employee.dni;
    strcpy( ((tEmployee*)a)->surname,((tNovelty*)b)->employee.surname );
    strcpy( ((tEmployee*)a)->name,((tNovelty*)b)->employee.name );
    ((tEmployee*)a)->salary = ((tNovelty*)b)->employee.salary;
}

void updateFile(FILE* pfMaster,FILE* pfNovelties,FILE* pfTemp, int (*compare) (const void* a, const void* b), void (*update)(void* a ,void* b))
{
    tEmployee employee;
    tEmployee employeeAux;
    tNovelty novelty;
    int resultCmp;

    fread(&employee,sizeof(tEmployee),1,pfMaster);
    fread(&novelty,sizeof(tNovelty),1,pfNovelties);

    while(          !feof(pfMaster) && !feof(pfNovelties)         )
    {
        resultCmp = compare(&(employee.dni),&(novelty.employee.dni));

        if(         !resultCmp          )
        {
            if(         'A' == toupper(novelty.noveltyType)         )
            {
                printf("\nERROR:\nDNI = %d\nAPELLIDO = %s\nNOMBRE = %s\nACCION = %c\n\n",novelty.employee.dni,novelty.employee.name,novelty.employee.surname,novelty.noveltyType);
            }
            else if(            'M' == toupper(novelty.noveltyType)         )
                {
                    update(&employee,&novelty);
                    fwrite(&employee,sizeof(tEmployee),1,pfTemp);
                }
                else
                {
                    ///SI ERA BAJA, NO LO GRABO EN EL ARCHIVO temp y listo
                }

            fread(&employee,sizeof(tEmployee),1,pfMaster);
            fread(&novelty,sizeof(tNovelty),1,pfNovelties);
        }else if(           resultCmp > 0           )
            {
                ///TRATAMIENTO A LAS NOVEDADES RESTANTES

                if(         'A' == toupper(novelty.noveltyType)            )
                {
                    employeeAux.dni = novelty.employee.dni;
                    strcpy(employeeAux.surname,novelty.employee.surname);
                    strcpy(employeeAux.name,novelty.employee.name);
                    employeeAux.salary = novelty.employee.salary;

                    fwrite(&employeeAux,sizeof(tEmployee),1,pfTemp);
                }
                else    ///BAJA O MODIFICACION
                {
                    printf("\nERROR 2:\nDNI = %d\nAPELLIDO = %s\nNOMBRE = %s\nACCION = %c\n\n",novelty.employee.dni,novelty.employee.name,novelty.employee.surname,novelty.noveltyType);
                }
                fread(&novelty,sizeof(tNovelty),1,pfNovelties);
            }
            else
            {
                ///TENIA REGISTROS CORRECTOS EN MASTER Y TENGO QUE GUARDARLOS EN temp
                fwrite(&employee,sizeof(tEmployee),1,pfTemp);
                fread(&employee,sizeof(tEmployee),1,pfMaster);
            }
    }

    while(          !feof(pfMaster)         )
    {
        ///SI MASTER TENIA MAS QUE NOVEDADES
        ///SOLAMENTE COPIO LOS REGISTROS QUE ME QUEDAN EN TEMP[siempre es valido]
        fwrite(&employee,sizeof(tEmployee),1,pfTemp);
        fread(&employee,sizeof(tEmployee),1,pfMaster);
    }

    while(          !feof(pfNovelties)          )
    {
        ///SI NOVEDADES TENIA MAS QUE MASTER
        ///SOLAMENTE COPIO LOS REGISTROS QUE ME QUEDAN EN TEMP[si es valido]
        if(         'A' == toupper(novelty.noveltyType)            )
        {
            update(&employee,&novelty);
            fwrite(&employee,sizeof(employee),1,pfTemp);
        }
        else
        {
            printf("\nERROR:\nDNI = %d\nAPELLIDO = %s\nNOMBRE = %s\nACCION = %c\n\n",novelty.employee.dni,novelty.employee.name,novelty.employee.surname,novelty.noveltyType);
        }
        fread(&novelty,sizeof(tNovelty),1,pfNovelties);
    }

}


