#include "practica.h"

void ejercicio1()
{
    int dato = 5;
    int* pDato = &dato;

    printf( "DIRECCION DE VARIABLE ENTERA: %p\n", pDato );
    printf( "VALOR DEL DATO: %d\n", dato );
    printf( "DIRECCION DE LA VARIABLE PUNTERO: %p\n", &pDato );
    printf( "VALOR DE LA VARIABLE PUNTERO: %p\n", pDato );
    dato = 10;
    printf( "VALOR DEL DATO: %d\n", dato );
    *pDato = 20;
    printf( "VALOR DEL DATO: %d\n", dato );
}

void mostrarEntero( const void* dato )
{
    printf( "%d\t", *(int*)dato );
}

void mostrarLetra( const void* dato )
{
    printf( "%c\t", *(char*)dato );
}

void mostrarColeccion( const void* coleccion, unsigned tam, unsigned ce, void (*mostrar)( const void* dato ) )
{
    int i;

    printf( "\nMostrando coleccion:\n\n" );
    for( i = 0; i < ce; i++ )
    {
        mostrar( coleccion );
        coleccion += tam;
    }
    printf("\n");
}

void ejercicio2()
{
    int vec[] = {0,1,2,3,4,5,6,7,8,9};
    int* pVec = vec;
    char texto[] = {"Hola mundo"};
    char* cadena = texto;

    unsigned ce = sizeof(vec)/sizeof(vec[0]);
    unsigned tam = sizeof(vec[0]);

    pVec++;
    printf( "ENTERO: %d\n", *pVec );

    cadena++;
    printf( "LETRA: %c\n", *cadena );

    mostrarColeccion( vec, tam, ce, mostrarEntero );
}


void mostrarAlumno( const void* dato )
{
    printf( "Nombre: %s\nEdad: %u\nCarrera: %s\n",
            ((tAlumno*)dato)->nombre,
            ((tAlumno*)dato)->edad,
            ((tAlumno*)dato)->carrera
           );
}

void ejercicio3()
{
    tAlumno alumnos[] =
    {
        {"Karen", 27,"Ing"},
        {"Agustin",26,"Ing informatica"},
        {"Federico",21,"Ing informatica"}
    };
    int ce = sizeof(alumnos)/sizeof(alumnos[0]);
    int tam = sizeof(alumnos[0]);

    mostrarColeccion( alumnos, tam, ce, mostrarAlumno );
}

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
//        fprintf( stderr, "No pude abrir/crear archivo\n" );
        perror( "No pude abrir/crear archivo" );
        return NO_PUDE_CREAR_ABRIR_ARCHIVO;
    }

    return OK;
}

void ejercicio4()
{
    FILE* aAlumnos;
    char nombreArchivo[] = "alumnos.bin";
    char modo[] = "wb+";

    tAlumno alumnos[] =
    {
        {"Karen", 27,"Ing"},
        {"Agustin",26,"Ing informatica"},
        {"Federico",21,"Ing informatica"}
    };
    int tam = sizeof( alumnos[0] );
    int i = 1;
    tAlumno alumno;

    if(         !abrirArchivo( &aAlumnos, nombreArchivo, modo )           )
    {
        return;
    }

    fwrite( alumnos, sizeof(alumnos),1, aAlumnos );
    fseek( aAlumnos, 0L, SEEK_CUR );
    rewind( aAlumnos );

    fread( &alumno, tam, 1, aAlumnos );
    while(          !feof( aAlumnos )         )
    {
        printf( "Alumno %d:\n", i );
        mostrarAlumno( &alumno );
        printf( "\n" );
        fread( &alumno, tam, 1, aAlumnos );
        i++;
    }

    fclose( aAlumnos );
}

void tarea()
{
    //ESCRIBIR Y MOSTRAR EN UN ARCHIVO DE TEXTO
        //LONG FIJA
        //LONG VARIABLE
}

void ejercicio5()
{
    FILE* aAlumnos;
    char nombreArchivo[] = "alumnosLF.txt";
    char modo[] = "wt+";

    tAlumno alumnos[] =
    {
        {"Karen", 27,"Ing"},
        {"Agustin",26,"Ing informatica"},
        {"Federico",21,"Ing informatica"}
    };
    int ce = sizeof(alumnos)/sizeof(alumnos[0]);

    int i;
    tAlumno alumno;
    char buffer[TAM_BUFFER];

    if(         !abrirArchivo( &aAlumnos, nombreArchivo, modo )           )
    {
        return;
    }

    for( i = 0; i < ce; i++ )
    {
        fprintf( aAlumnos, "%50s%3u%50s\n", alumnos[i].nombre, alumnos[i].edad, alumnos[i].carrera );
    }

    rewind( aAlumnos );

    i = 1;
    while(          fgets( buffer, TAM_BUFFER, aAlumnos )         )
    {
        sscanf( buffer, "%50s%3u%50s", alumno.nombre, &alumno.edad, alumno.carrera );
        alumno.nombre[TAM_NOMBRE] = '\0';
        alumno.carrera[TAM_CARRERA] = '\0';

        printf( "Alumno %d:\n", i );
        mostrarAlumno( &alumno );
        printf( "\n" );
        i++;
    }

    fclose( aAlumnos );
}

void ejercicio6()
{
    FILE* aAlumnos;
    char nombreArchivo[] = "alumnosLV.txt";
    char modo[] = "wt+";

    tAlumno alumnos[] =
    {
        {"Karen", 27,"Ing"},
        {"Agustin",26,"Ing informatica"},
        {"Federico",21,"Ing informatica"}
    };
    int ce = sizeof(alumnos)/sizeof(alumnos[0]);

    int i;
    tAlumno alumno;
    char buffer[TAM_BUFFER];

    if(         !abrirArchivo( &aAlumnos, nombreArchivo, modo )           )
    {
        return;
    }


    for( i = 0; i < ce; i++ )
    {
        fprintf( aAlumnos, "%s-%u-%s\n", alumnos[i].nombre, alumnos[i].edad, alumnos[i].carrera );
    }

    rewind( aAlumnos );

    i = 1;
    while(          fgets( buffer, TAM_BUFFER, aAlumnos )         )
    {
        sscanf( buffer, "%[^-]-%u-%[^-]", alumno.nombre, &alumno.edad, alumno.carrera );
        alumno.nombre[TAM_NOMBRE] = '\0';
        alumno.carrera[TAM_CARRERA] = '\0';

        printf( "Alumno %d:\n", i );
        mostrarAlumno( &alumno );
        printf( "\n" );
        i++;
    }

    fclose( aAlumnos );
}
