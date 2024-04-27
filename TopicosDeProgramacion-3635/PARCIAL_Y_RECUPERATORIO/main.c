#include "parcial.h"

///AGUSTIN BROCANI 40931870

int main()
{
    FILE* citas;
    FILE* resultados;
    char buffer[TAM];

    if(         !abrirArchivo( &citas, "citas.txt", "rt")         )
    {
        return 1;
    }

    if(         !abrirArchivo( &resultados, "resultados.txt", "wt")         )
    {
        fclose( citas );
        return 1;
    }

    while(          fgets( buffer, sizeof(buffer), citas )         )
    {
        desofuscarRegistro( buffer );
        printf("Registro desofuscado:\n%s\n", buffer );
        fprintf( resultados, "%s\n", buffer);
    }

    fclose( citas );
    fclose( resultados );
    //remove( "citas.txt" );
    rename( "resultados.txt","citasResultado.txt" );

    return 0;
}
