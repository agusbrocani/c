#include "f.h"

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        perror("No se pudo abrir/crear el archivo");
        return 0;
    }

    return 1;
}

/**
typedef struct
{
    int id;
    char nya[TAM];
    char sexo;
    tFecha nNac;
    float salario;
}tEmpleado;

*/

void crearLoteEmpleados()
{
    FILE* pf;
//    tEmpleado empleados[] =
//    {
//        { 1, "Agustin Brocani", 'H', {30,01,1998}, 1500.2},
//        { 2, "Federico Martucci", 'H', {01,01,2000}, 2500},
//        { 3, "Franco Ruggieri", 'H', {30,10,2000}, 3001.9},
//        { 4, "Simon Bombon", 'H', {29,02,2000}, 0.01},
//        { 5, "Algun Nombre De Mujer", 'M', {18,12,2022}, 1000},
//        { 6, "Leonardo Barbaro", 'H', {1,1,2003}, 2200.25}
//    };

    tEmpleado empleados[] =
    {
        { 6, "Leonardo Barbaro", 'H', {1,1,2003}, 2200.25},
        { 3, "Franco Ruggieri", 'H', {30,10,2000}, 3001.9},
        { 2, "Federico Martucci", 'H', {01,01,2000}, 2500},
        { 5, "Algun Nombre De Mujer", 'M', {18,12,2022}, 1000},
        { 1, "Agustin Brocani", 'H', {30,01,1998}, 1500.2},
        { 4, "Simon Bombon", 'H', {29,02,2000}, 0.01},
    };
    int i;

    if(         !abrirArchivo( &pf, "empleados.txt", "wt" )           )
    {
        printf("Error al crear lote\n");
        return;
    }

    for( i = 0; i < sizeof(empleados)/sizeof(tEmpleado); i++ )
    {
        fprintf( pf, "%03d|%s|%c|%02d|%02d|%04d|%4.2f\n", empleados[i].id, empleados[i].nya, empleados[i].sexo, empleados[i].fNac.dia, empleados[i].fNac.mes, empleados[i].fNac.anio, empleados[i].salario);
    }

    fclose(pf);
}

int comparaEmpleadosPorNYA( const void* a, const void* b)
{
    int cmp = strcmpi( ((tEmpleado*)a)->nya , ((tEmpleado*)b)->nya ) ;

    if(         !cmp          )  //((tEmpleado*)a)->
    {
        return (            ((tEmpleado*)a)->id - ((tEmpleado*)b)->id           ) ;
    }

    return cmp;
}

int comparaEmpleadosPorID( const void* a, const void* b)
{
    return ((tEmpleado*)a)->id - ((tEmpleado*)b)->id;
}

int comparaEmpleadosIDMayor( const void* a, const void* b)
{
    return ((tEmpleado*)b)->id - ((tEmpleado*)a)->id;
}

void mostrarEmpleado( const void* data )
{
    printf("Empleado:\n");
    printf("ID = %d\nNya = %s\nSexo = %c\nfNac = %d/%d/%d\nSalario = %.2f\n",
           ((tEmpleado*)data)->id,
           ((tEmpleado*)data)->nya,
           ((tEmpleado*)data)->sexo,
           ((tEmpleado*)data)->fNac.dia,
           ((tEmpleado*)data)->fNac.mes,
           ((tEmpleado*)data)->fNac.anio,
           ((tEmpleado*)data)->salario
           );
}

void mostrar( const void* data, size_t tam, int ce, void (*mostrar)( const void* data ) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        mostrar(data);
        data += tam;
        printf("\n");
    }
    printf("\n");
}

void* buscarMenor( void* data, size_t tam, int ce, int (*comparar)( const void* a, const void* b ) )
{
    void* menor = data;
    int i;

    if(         ce <= 0         )
    {
        return NULL;
    }

    data += tam;
    for( i = 1; i < ce; i++ )
    {
        if(         comparar( menor, data ) > 0          )
        {
            menor = data;
        }
        data += tam;
    }
    return menor;
}

void fSwap( void* a, void* b, size_t tam )
{
    char aux;
    int i;

    for( i = 0; i < tam; i++ )
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }
}

void ordenarPorSeleccion( void* data, size_t tam, int ce, int (*comparar)( const void* a, const void* b ))
{
    void* menor;

    if(         ce <= 1          )
    {
        return;
    }

    while(          ce          )
    {
        menor = buscarMenor( data, tam, ce, comparar );
        if(         comparar( data, menor ) > 0          )
        {
            fSwap( data, menor, tam );
        }
        data += tam;
        ce--;
    }
}

void insertarOrdenado( void* data, const void* aInsertar, size_t tam, int* ce, int (*comparar)( const void* a, const void* b ))
{
    void* ultimoElemento = data + *ce * tam - tam;
    int index = 0;
    int i;

    if(         *ce < 0 || (*ce + 1) > CE_MAX         )
    {
        return;
    }

    while(          *ce && comparar( aInsertar, data) > 0            )
    {
        data += tam;
        index++;
    }


    if(         !*ce || comparar( aInsertar, data) < 0          )
    {
        for( i = *ce - 1; i >= index; i-- )
        {
            memcpy( ultimoElemento + tam, ultimoElemento, tam );
            ultimoElemento -= tam;
        }

        memcpy( data, aInsertar, tam );

        if(         *ce < CE_MAX            )
        {
            (*ce)++;
        }//else *ce = CE_MAX;
    }
}

void trozar( tEmpleado* empleado, char* buffer )
{
    char* recorrido = strchr( buffer,'\n');
    //printf("BUFFER = \n%s",buffer);
    *recorrido = '\0';

    while(          '|' != *recorrido           )   ///SI FUESE UN ARCHIVO DE LONGITUD FIJA, EN VEZ DEL WHILE UTILIZO EL OFFSET QUE ME DEN
    {
        recorrido--;
    }
    recorrido++;
    empleado->salario = atof(recorrido);    ///ASCII TO float
    recorrido--;
    *recorrido = '\0';

    while(          '|' != *recorrido           )
    {
        recorrido--;
    }
    recorrido++;

    empleado->fNac.anio = atoi(recorrido);  ///ASCII TO int

    recorrido--;
    *recorrido = '\0';

    while(          '|' != *recorrido           )   ///-> si fuese de longitud fija, directamente pongo el offset y listo(como en la linea 221)
    {
        recorrido--;
    }
    recorrido++;

    empleado->fNac.mes = atoi(recorrido);

    recorrido--;
    *recorrido = '\0';

    while(          '|' != *recorrido           )
    {
        recorrido--;
    }
    recorrido++;

    empleado->fNac.dia = atoi(recorrido);

    recorrido -=2;

    empleado->sexo = *recorrido;

    recorrido--;
    *recorrido = '\0';

    while(          '|' != *recorrido           )
    {
        recorrido--;
    }
    recorrido++;    ///PRINCIPIO DE LA CADENA

    strcpy( empleado->nya , recorrido );

    recorrido--;    ///PARADO EN EL ULTIMO |
    *recorrido = '\0';

    empleado->id = atoi( buffer );  ///COMO ES EL COMIENZO DE LA CADENA, UTILIZO buffer QUE NUNCA LO MOVI
}
