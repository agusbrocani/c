#include "preParcialTopicos.h"

void parseRow( char* buffer, int* mat, int row, int column);

int main( int argc, char* argv[] )  ///argv es un vector en donde cada indice apunta a un byte - argument count - argument vector
{
    FILE* fp;
    char buffer[BUFFER_SIZE];
    int row;
    int r = 0;
    int column;
    int mat[MAX_ROWS][MAX_COLUMNS];
    int c;

    fp = fopen("toDo.txt","rt");

    if(         !fp         )
    {
        perror("ERROR!");
        return 1;
    }

    if(         fgets(buffer,BUFFER_SIZE,fp)            )
    {
        sscanf(buffer, "%d %d", &row,&column);
        if(         row > MAX_ROWS || column > MAX_COLUMNS         )
        {
                return 1;
        }
        fgets(buffer,BUFFER_SIZE,fp);
    }



    printf("Number of rows = %d Number of columns = %d\n", row, column );

    while(          fgets(buffer,BUFFER_SIZE,fp)            )   ///procesamiento de la matriz
    {
        parseRow( buffer, &mat[r][0], row, column );
        r++;
    }

    for( r = 0; r < row; r++)
    {
        for( c = 0; c < column; c++ )
        {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }


    fclose(fp);
    return 0;
}
/**
fgets
fputs
sscanf
fprintf
parseo  -> PROBLEMAS CUANDO TENGO CADENAS para sscanf   -> 2 SOLUCIONES     -> [^|] TOMAME TODO HASTA ENCONTRAR EL | y ¡¡¡YO MANUALMENTE DEBO AGREGAR EL \0 en la ultima posicion del BUFFER!!!
                                                                            ->
*/
//mat[i][j] = trozar( punteroABuffer );   //DOBLE PUNTERO
//LEO TODO HASTA UN ESPACIO
//BUFFER -> ANALIZO EL BUFFER -> 12345 PASO TODO A NUMERO Y LUEGO HACER UN STRLEN PARA ASIGNAR PESOS

void parseRow( char* buffer, int* mat, int row, int column)
{
    char* traverseBuffer = buffer;

    while(          *traverseBuffer != '\0'          )
    {
        sscanf(traverseBuffer, "%d", mat+row*MAX_COLUMNS+column);
        column++;
        while(*traverseBuffer != ' ' && *traverseBuffer != '\0'){
            traverseBuffer++;
        }
        traverseBuffer++;
    }

}
