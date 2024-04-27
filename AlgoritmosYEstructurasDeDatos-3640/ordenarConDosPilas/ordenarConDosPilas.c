#include "ordenarConDosPilas.h"

void crearPila(tPila *p)
{
    *p = NULL;
}
int pilaLlena(const tPila *p,unsigned tam)
{
    tNodo *aux = (tNodo*) malloc(sizeof(tNodo));
    void *info = malloc(tam);
    free(aux);
    free(info);
    return (aux ==NULL || info ==NULL);
}
int apilar(tPila* p, const void* d, unsigned tam)
{
    tNodo* nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,tam);
    nue->tamInfo=tam;
    nue->sig = *p;
    *p = nue;
    return 1;

}

int verTope(const tPila *p, void* d, unsigned tam)
{
    if(*p == NULL)
        return 0;
    memcpy(d,(*p)->info,minimo(tam,(*p)->tamInfo));
    return 1;
}
int pilaVacia(const tPila* p)
{
    return *p ==NULL;
}
int desapilar(tPila*p, void*d, unsigned tam)
{
    tNodo* aux = *p; // usamos nodo auxiliar por que de otra forma no puedo liberar la memoria
    if(*p == NULL)
        return 0;
    *p = aux->sig;

    memcpy(d,aux->info,minimo(aux->tamInfo,tam));
    free(aux->info);
    free(aux);

    return 1;
}
void vaciarPila(tPila* p)
{
    tNodo *aux;
    while(*p)
    {
        aux= *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        printf("No pude abrir/crear archivo\n");
        return 1;
    }

    return 0; //CAMBIADO DE COMO LO HAGO SIEMPRE PORQUE FEDE USA EL OK CON EL 0
}


void mostrarProducto(FILE* destino, const void* p) {
    fprintf(destino, "%s|%s|%s|%d/%d/%d|%d/%d/%d|%d|%.2f|%.2f\n",
            ((tProducto*)p)->codigo,
            ((tProducto*)p)->descripcion,
            ((tProducto*)p)->proveedor,
            ((tProducto*)p)->fechaCompra.dia,
            ((tProducto*)p)->fechaCompra.mes,
            ((tProducto*)p)->fechaCompra.anio,
            ((tProducto*)p)->fechaVencimiento.dia,
            ((tProducto*)p)->fechaVencimiento.mes,
            ((tProducto*)p)->fechaVencimiento.anio,
            ((tProducto*)p)->cantidad,
            ((tProducto*)p)->precioCompra,
            ((tProducto*)p)->precioVenta);
}

void generarProductos(tProducto* vecProductos, int cantidad)
{
    int i;

    for (i = 0; i < cantidad; i++) {
        sprintf(vecProductos[i].codigo, "%07d", 1000000 + rand() % 915654);
        sprintf(vecProductos[i].descripcion, "Producto %d", i + 1);
        sprintf(vecProductos[i].proveedor, "Proveedor%d", i + 1);
        vecProductos[i].fechaCompra.dia = 1 + rand() % 31;
        vecProductos[i].fechaCompra.mes = 1 + rand() % 12;
        vecProductos[i].fechaCompra.anio = 2020 + rand() % 5; // Año entre 2020 y 2024
        vecProductos[i].fechaVencimiento.dia = 1 + rand() % 31;
        vecProductos[i].fechaVencimiento.mes = 1 + rand() % 12;
        vecProductos[i].fechaVencimiento.anio = vecProductos[i].fechaCompra.anio + rand() % 3; // Vencimiento entre 0 y 2 años después de la compra
        vecProductos[i].cantidad = 1 + rand() % 100;
        vecProductos[i].precioCompra = 10 + rand() % 1000; // Precio de compra entre 10 y 1009
        vecProductos[i].precioVenta = vecProductos[i].precioCompra * 1.5; // Precio de venta es 50% más que el de compra
    }

}

int cmpCodigo(const void* a, const void* b)
{
    return strcmp(((tProducto*)a)->codigo, ((tProducto*)b)->codigo);
}

void trozarProducto(char* cadena, void* destino)
{
    tProducto* producto = (tProducto*)destino;
    char* aux;

    aux = strrchr(cadena, '\n');
    *aux = '\0';

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    producto->precioVenta = atof(aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    producto->precioCompra = atof(aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    producto->cantidad = atoi(aux);

    aux = strrchr(cadena, '/');
    *aux = '\0';
    aux ++;

    producto->fechaVencimiento.anio = atoi(aux);

    aux = strrchr(cadena, '/');
    *aux = '\0';
    aux ++;

    producto->fechaVencimiento.mes = atoi(aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    producto->fechaVencimiento.dia = atoi(aux);

    aux = strrchr(cadena, '/');
    *aux = '\0';
    aux ++;

    producto->fechaCompra.anio = atoi(aux);

    aux = strrchr(cadena, '/');
    *aux = '\0';
    aux ++;

    producto->fechaCompra.mes = atoi(aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    producto->fechaCompra.dia = atoi(aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    strcpy(producto->proveedor, aux);

    aux = strrchr(cadena, '|');
    *aux = '\0';
    aux ++;

    strcpy(producto->descripcion, aux);

    strcpy(producto->codigo, cadena);

}

int generarArchivoProductos(const char* nombre, const char* tipo)
{
    int error;
    int i;

    FILE* archivoProductos;
    tProducto loteProductos[CANT_PRODUCTOS];

    generarProductos(loteProductos, CANT_PRODUCTOS);

    if(strcmpi(tipo, "BINARIO") == 0)
    {
        if((error = abrirArchivo(&archivoProductos, nombre, "wb")) != OK)
            return error;
        fwrite(loteProductos, sizeof(tProducto), CANT_PRODUCTOS, archivoProductos);
    }
    else if(strcmpi(tipo, "TEXTO") == 0)
    {
        if((error = abrirArchivo(&archivoProductos, nombre, "wt")) != OK)
            return error;
        for (i = 0; i < CANT_PRODUCTOS; i++)
            mostrarProducto(archivoProductos, &loteProductos[i]);//mostrarProducto(stdout, &loteProductos[i]);
    }
    else
        return FILE_OPEN_MODE_ERR;

    fclose(archivoProductos);
    return OK;
}

void ordenarConDosPilasAscendente( tPila* entrada, unsigned tam, int (*comparar)( const void* a, const void* b ) )
{
    tPila pMayores;
    tPila pMenores;
    void* buffer;
    void* aux;

    crearPila( &pMayores );
    crearPila( &pMenores );

    buffer = malloc( tam ); //tam es el tamaño del dato a ordenar
    if(         !buffer         )
    {
        printf("PROBLEMAS RESERVANDO MEMORIA PARA buffer\n");
        return;
    }

    aux = malloc(tam);
    if(         !aux         )
    {
        printf("PROBLEMAS RESERVANDO MEMORIA PARA aux\n");
        free(buffer);
        return;
    }

    while(          *entrada         )
    {
        desapilar( entrada, buffer, tam );
        if(         !pMayores           )
        {
            apilar( &pMayores, buffer, tam );
        }
        else
        {
            if(         comparar( pMayores->info, buffer ) > 0         )
            {
                while(          pMenores && comparar( buffer, pMenores->info ) < 0          )
                {
                    desapilar( &pMenores, aux, tam );
                    apilar( &pMayores, aux, tam );
                }
                apilar( &pMenores, buffer, tam );
            }
            else
            {
                while(          pMayores && comparar( buffer, pMayores->info ) > 0          )
                {
                    desapilar( &pMayores, aux, tam );
                    apilar( &pMenores, aux, tam );
                }
                apilar( &pMayores, buffer, tam );
            }
        }
    }

    while(          pMenores          )
    {
        desapilar( &pMenores, buffer, tam );
        apilar( &pMayores, buffer, tam );
    }

    //accion( &pMayores );

    while(          pMayores            )
    {
        desapilar( &pMayores, buffer, tam );
        printf("%d\t", *(int*)buffer);
    }

    vaciarPila( &pMayores );    //Lineas de código para asegurar el jamas tener memory leaks aunque en teoria al llegar acá siempre deberian estar vacias las 2 pilas
    vaciarPila( &pMenores );
    free( buffer );
    free( aux );
}
