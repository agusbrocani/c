#include "./unidad2.h"

void switchMenu(int opcion, void* parametro)
{
    switch(opcion)
    {
        case OPCION_1:  //ejecuto 2 opciones en 1
        case OPCION_2:
            printf("Biblioteca de Pila %s implementada.\n", OPCION_1 == opcion ? "Estatica" : "Dinamica");
        break;
        case OPCION_3:
            printf("Cargar Productos a datos.bin.\n");
            cargarProductosAArchivoBinario();
        break;
        case OPCION_4:
        case OPCION_5:
            printf("Cargar Empleados desde archivo a Pila %s.\n", OPCION_4 == opcion ? "Estatica" : "Dinamica");
            opcion4y5();
        break;
        case OPCION_6:
            printf("Ordenar archivo con 2 pilas generico.\n");
            ordenarDatosArchivoConDosPilas();
        break;
        case OPCION_7:
            printf("Sumar 2 enteros muy grandes desde archivos.\n");
            sumarEnterosDesdeDosArchivos();
        break;
    }
}

void cargarProductosAArchivoBinario()
{
    FILE* pf;
    tProducto productos[CE_PRODUCTOS];
    unsigned tam = sizeof(productos[0]);
    cargarProductos(productos, CE_PRODUCTOS);

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_BINARIO, "wb"))
    {
        return;
    }

    fwrite(productos, CE_PRODUCTOS * tam, 1, pf);

    fclose(pf);
}

void switchMenu4y5(int opcion, void* parametro)
{
    tPilaCargada* dato = (tPilaCargada*)parametro;
    srand(time(NULL));

    switch(opcion)
    {
        case APILAR_4_Y_5:
            printf("Apilando:\n");
            (dato->producto) = ((dato->productos)[rand() % CE_PRODUCTOS]);
            mostrarProducto(&(dato->producto));
            apilar(dato->p, &(dato->producto), dato->tam);
        break;
        case VER_TOPE_4_Y_5:
            if(!verTope(dato->p, &(dato->producto), dato->tam))
            {
                printf("Pila vacia.\n");
            }
            else
            {
                printf("Viendo tope:\n");
                mostrarProducto(&(dato->producto));
            }
        break;
        case DESAPILAR_4_Y_5:
            if(!desapilar(dato->p, &(dato->producto), dato->tam))
            {
                printf("Pila Vacia.\n");
            }
            else
            {
                printf("Desapilando:\n");
                mostrarProducto(&(dato->producto));
            }
        break;
    }
}

void opcion4y5()
{
    FILE* datosBin;
    tPila pilaCargada;
    tProducto producto;
    unsigned tam = sizeof(tProducto);
    unsigned cantBytesArchivo;
    tPilaCargada sPilaCargada;

    char textoMenu[][MAX_TAM_TEXTO] =
    {
      "Submenu pila con datos.bin:",
      "[0]SALIR del submenu.",
      "[1]Apilar.",
      "[2]Ver Tope.",
      "[3]Desapilar."
    };
    unsigned cantidadDeRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    crearPila(&pilaCargada);

    fread(&producto, tam, 1, datosBin);
    while(!feof(datosBin))
    {
        apilar(&pilaCargada, &producto, tam);
        fread(&producto, tam, 1, datosBin);
    }
    fclose(datosBin);

    sPilaCargada.p = &pilaCargada;
    sPilaCargada.tam = tam;
    cargarProductos(sPilaCargada.productos, CE_PRODUCTOS);

    menu(textoMenu, cantidadDeRegistros, switchMenu4y5, &sPilaCargada, DESACTIVAR_AYUDA_AL_USUARIO);

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "wb"))
    {
        return;
    }

    while(desapilar(&pilaCargada, &producto, tam))
    {
        fwrite(&producto, tam, 1, datosBin);
    }

    fseek(datosBin, 0L, SEEK_END);
    cantBytesArchivo = ftell(datosBin);//cuenta cant bytes desde el inicio

    vaciarPila(&pilaCargada);
    fclose(datosBin);

    if(!cantBytesArchivo)
    {
        printf("\nBorrando archivo...\n");
        remove(NOMBRE_ARCHIVO_BINARIO);
        system("pause");
        system("cls");
        return;
    }

    if(!abrirArchivo(&datosBin, NOMBRE_ARCHIVO_BINARIO, "rb"))
    {
        return;
    }

    printf("Mostrando archivo grabado:\n\n");
    fread(&producto, tam, 1, datosBin);
    while(!feof(datosBin))
    {
        mostrarProducto(&producto);
        fread(&producto, tam, 1, datosBin);
    }

    fclose(datosBin);
}

void switchMenuOrdenarArchivoConDosPilas(int opcion, void* parametro)
{
    tEmpleado empleados[CE_EMPLEADOS];
    unsigned ce = CE_EMPLEADOS;
    unsigned tam = sizeof(tEmpleado);

    cargaEmpleadosAVector(empleados);

    switch(opcion)
    {
        case VER_ARCHIVO_DESORDENADO:
            mostrarColeccion(empleados, tam, ce, mostrarEmpleado);
        break;
        case LOTE_TEXTO_LF:
            printf("\n***************LOTE TextoLF***************\n");
            loteTextoLF(empleados, tam, ce);
            printf("\n***************FIN LOTE TextoLF***************\n");
        break;
        case LOTE_TEXTO_LV:
            printf("\n***************LOTE TextoLV***************\n");
            loteTextoLV(empleados, tam, ce);
            printf("\n***************FIN LOTE TextoLV***************\n");
        break;
        case LOTE_BINARIO:
            printf("\n***************LOTE BINARIO***************\n");
            loteBinario(empleados, tam, ce);
            printf("\n***************FIN LOTE BINARIO***************\n");
        break;
    }
}

void loteTextoLF(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_TEXTO_LF, "wt+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_TEXTO_LF_ORDENADO, "wt+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoTxtLF(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion, grabarDatoArchivoTxtLF);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}

void loteTextoLV(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_TEXTO_LV, "wt+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_TEXTO_LV_ORDENADO, "wt+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoTxtLV(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion, grabarDatoArchivoTxtLV);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}

void loteBinario(const void* coleccion, unsigned tam, unsigned ce)
{
    FILE* origen;
    FILE* destino;
    tEmpleado empleado;
    int i;

    if(!abrirArchivo(&origen, NOMBRE_ARCHIVO_LOTE_BINARIO, "wb+"))
    {
        return;
    }

    if(!abrirArchivo(&destino, NOMBRE_ARCHIVO_LOTE_BINARIO_ORDENADO, "wb+"))
    {
        fclose(origen);
        return;
    }

    for(i = 0; i < ce; i++)
    {
        grabarDatoArchivoBinario(origen, coleccion, tam);
        coleccion += tam;
    }
    rewind(origen);

    ordenarArchivoConDosPilasGen(origen, destino, tam, comparaEmpleadosPorID, leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion, grabarDatoArchivoBinario);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion(destino, &empleado, tam))
    {
        mostrarEmpleado(&empleado);
    }

    fclose(origen);
    fclose(destino);
}


void ordenarDatosArchivoConDosPilas()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
        "SubMenu de ordenar archivo con 2 pilas generico:",
        "[0]-SALIR del submenu.",
        "[1]-Ver archivo desordenado.",
        "[2]-Ordenar archivo TEXTO-LF con 2 pilas.",
        "[3]-Ordenar archivo TEXTO-LV con 2 pilas.",
        "[4]-Ordenar archivo BINARIO con 2 pilas."
    };
    unsigned cantRegistros = sizeof(textoMenu)/MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenuOrdenarArchivoConDosPilas, NULL, DESACTIVAR_AYUDA_AL_USUARIO);
}

void crearLoteNumero(const char* nombreArchivo, const char* numero)
{
    FILE* pf;

    if(!abrirArchivo(&pf, nombreArchivo, "wt"))
    {
        return;
    }

    fprintf(pf, "%s\n", numero);

    fclose(pf);
}

void grabarEntero(FILE* pf, const void* dato)
{
    fprintf(pf, "%d", *(int*)dato);

    if(stdout == pf)
    {
        printf("\n");
    }
}

void sumarEnterosDesdeDosArchivos()
{
    FILE* aNumero1;
    FILE* aNumero2;
    FILE* aResultado;
    tPila pNumero1;
    tPila pNumero2;
    tPila resultado;
    int numero;
    int tamEntero = sizeof(int);
    char numeroLeidoComoCaracter;

    char numero1[] = "9";
    char numero2[] = "991";

    crearLoteNumero(NOMBRE_ARCHIVO_NUMERO1, numero1);
    crearLoteNumero(NOMBRE_ARCHIVO_NUMERO2, numero2);

    if(!abrirArchivo(&aNumero1, NOMBRE_ARCHIVO_NUMERO1, "rt"))
    {
        return;
    }

    if(!abrirArchivo(&aNumero2, NOMBRE_ARCHIVO_NUMERO2, "rt"))
    {
        fclose(aNumero1);
        return;
    }

    if(!abrirArchivo( &aResultado, NOMBRE_ARCHIVO_RESULTADO, "wt" ))
    {
        fclose(aNumero1);
        fclose(aNumero2);
        return;
    }

    crearPila(&pNumero1);
    crearPila(&pNumero2);
    crearPila(&resultado);

    while(EOF != (numeroLeidoComoCaracter = fgetc(aNumero1)))
    {
        if(ES_NUMERO(numeroLeidoComoCaracter))
        {
            numero = A_NUMERO(numeroLeidoComoCaracter);
            apilar(&pNumero1, &numero, tamEntero);
        }
    }

    while(EOF != (numeroLeidoComoCaracter = fgetc(aNumero2)))
    {
        if(ES_NUMERO( numeroLeidoComoCaracter))
        {
            numero = A_NUMERO(numeroLeidoComoCaracter);
            apilar(&pNumero2, &numero, tamEntero);
        }
    }

    printf("Numero 1:\n");
    printf("%s\n", numero1);
    printf("Numero 2:\n");
    printf("%s\n", numero2);
    sumarEnterosConDosPilas(&pNumero1, &pNumero2, &resultado);
    printf("Resultado: \n");
    while(desapilar(&resultado, &numero, tamEntero))
    {
        printf("%d", numero);
        grabar(aResultado, &numero, grabarEntero);
    }

    vaciarPila(&pNumero1);
    vaciarPila(&pNumero2);
    vaciarPila(&resultado);
    fclose(aNumero1);
    fclose(aNumero2);
    fclose(aResultado);
}

