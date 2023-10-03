#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    int dni;
    char nya[35];
    char c;
    float sueldo;
}tPersona;

void trozadoVariable(char* cad, tPersona* p);
void mostrarPersona(const tPersona * miPersona);
void trozadoFijo(char* cad, tPersona * p);

int main()
{
    char buffer[100];
    FILE* longVar = fopen("longVar.txt","wt+"), *longFija = fopen("longFija.txt","wt+");

    if(!longVar)
    {
        exit(1);
    }

    if(!longFija)
    {
        fclose(longVar);
        exit(1);
    }

    tPersona miPersona = {1234,"Alberto Fernandez",'M',1000.50};
    tPersona lectura,lectura2;

    fprintf(longVar,"%08d|%-34s|%c|%0.2f\n",miPersona.dni,miPersona.nya,miPersona.c,miPersona.sueldo);
    fprintf(longFija,"%08d%-34.34s%c%09.2f\n",miPersona.dni,miPersona.nya,miPersona.c,miPersona.sueldo);

    rewind(longVar);
    rewind(longFija);

    fgets(buffer,100,longVar);

    trozadoVariable(buffer,&lectura);
    mostrarPersona(&lectura);

    printf("\n\n");
    fgets(buffer,100,longFija);
    trozadoFijo(buffer,&lectura2);
    mostrarPersona(&lectura2);

    fclose(longVar);
    fclose(longFija);
    return 0;
}

void trozadoVariable(char* cad, tPersona* p)
{
    char* aux = strrchr(cad,'\n');
    *aux = '\0';
    aux = strrchr(cad,'|');
    sscanf(aux+1,"%f",&(p->sueldo));
    *aux = '\0';
    aux = strrchr(cad,'|');
    p->c = *(aux+1);
    *aux = '\0';
    aux = strrchr(cad,'|');
    strcpy(p->nya,aux+1);
    *aux = '\0';
    sscanf(cad,"%d",&(p->dni));
}

void trozadoFijo(char* cad, tPersona * p) //"%08d%-34.34s%c%09.2f\n"
{
    char* aux = strrchr(cad,'\n');
    aux-=9;
    sscanf(aux,"%f",&(p->sueldo));
    *aux = 0;
    aux--;
    p->c = *aux;
    aux-=34;
    strcpy(p->nya,aux);
    *aux = 0;
    sscanf(cad,"%d",&(p->dni));
}

void mostrarPersona(const tPersona * miPersona)
{
    printf("%08d %-35s %c %0.2f\n",miPersona->dni,miPersona->nya,miPersona->c,miPersona->sueldo);
}
