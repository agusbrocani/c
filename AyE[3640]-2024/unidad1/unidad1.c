#include "./unidad1.h"

void mostrarCadena(const void* dato)
{
    printf("%s\n", (char*)dato);
}

void mostrarVectorDeCadenas(char mat[][TAM_MAX], unsigned cantidadDeRegistros, void(*mostrar)(const void* dato))
{
    int i;
    for(i = 0; i < cantidadDeRegistros; i++)
    {
        mostrar(&mat[i][0]);
    }
}

void ejercicio1()
{
    char TDAPila[][TAM_MAX] =
    {
        "\nPrimitivas TDA Pila:\n",
        "void crearPila(tPila* p);",
        "int apilar(tPila* p, const void* dato, unsigned tam);",
        "int desapilar(tPila* p, void* dato, unsigned tam);",
        "void vaciarPila(tPila* p );",
        "int pilaVacia(const tPila* p );",
        "int pilaLlena(const tPila* p, unsigned tam);",
        "int verTope(const tPila* p, void* dato, unsigned tam);"
    };
    unsigned cantRegistrosTDAPila = sizeof(TDAPila) / TAM_MAX;

    char TDACola[][TAM_MAX] =
    {
        "\nPrimitivas TDA Cola:\n",
        "void crearCola(tCola* c);",
        "int acolar(tCola* c, const void* dato, unsigned tam);",
        "int desacolar(tCola* c, void* dato, unsigned tam);",
        "int colaLlena(const tCola* c, unsigned tam);",
        "int colaVacia(const tCola* c);",
        "int verPrimero(const tCola* c, void* dato, unsigned tam);",
        "void vaciarCola(tCola* c);"
    };
    unsigned cantRegistrosTDACola = sizeof(TDACola) / TAM_MAX;

    printf("EJERCICIO 1\n");
    mostrarVectorDeCadenas(TDAPila, cantRegistrosTDAPila, mostrarCadena);
    mostrarVectorDeCadenas(TDACola, cantRegistrosTDACola, mostrarCadena);
}

void ejercicio2()
{
    char estructuraRecursiva[][TAM_MAX] =
    {
        "\ntypedef struct sNodo",
        "{",
        "    void* dato;",
        "    unsigned tam;",
        "    struct sNodo* sig;",
        "}tNodo;\n\n"
    };
    unsigned cantRegistrosEstructuraRecursiva = sizeof(estructuraRecursiva) / TAM_MAX;

    printf("EJERCICIO 2\n");
    printf("\nImplementacion estructura recursiva:\n");
    mostrarVectorDeCadenas(estructuraRecursiva, cantRegistrosEstructuraRecursiva, mostrarCadena);
    printf("TDAs con estructuras recursivas:\n-TDA Pila.\n-TDA Cola.\n");
    printf("Tipo de implementacion: dinamica\n");
    printf("Primitivas aclaradas en ejercicio 1.\n");
}

void ejercicio3()
{
    char nodo[][TAM_MAX] =
    {
        "\ntypedef struct sNodo",
        "{",
        "    void* dato;",
        "    unsigned tam;",
        "    struct sNodo* sig;",
        "}tNodo;\n\n"
    };
    unsigned cantRegistrosNodo = sizeof(nodo) / TAM_MAX;

    printf("EJERCICIO 3\n");

    printf("\nGrafico del Nodo:");
    printf("\n\t __________ __________ __________ \n");
    printf("\t|   dato   |   tam    |   sig    |\n");
    printf("\t|          |          |          |\n");
    printf("\t|          |          |          |\n");
    printf("\t|__________|__________|__________|\n");

    printf("\nImplementacion:\n");
    mostrarVectorDeCadenas(nodo, cantRegistrosNodo, mostrarCadena);
}

void ejercicio4()
{
    char insertarListaSimpleAlFinal[][TAM_MAX] =
    {
        "int insertarAlFinal(tLista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b))",
        "{",
        "    tNodo* nuevoNodo;",
        "",
        "    nuevoNodo = malloc(sizeof(tNodo));",
        "",
        "    if(!nuevoNodo)",
        "    {",
        "        return NO_PUEDO_INSERTAR;",
        "    }",
        "",
        "    nuevoNodo->dato = malloc(tam);",
        "",
        "    if(!nuevoNodo->dato)",
        "    {",
        "        free(nuevoNodo);",
        "        return NO_PUEDO_INSERTAR;",
        "    }",
        "",
        "    memcpy(nuevoNodo->dato, dato, tam);",
        "    nuevoNodo->tam = tam;",
        "",
        "    while(*pl)",
        "    {",
        "        pl = &((*pl)->sig);",
        "    }",
        "    nuevoNodo->sig = *pl;",
        "    *pl = nuevoNodo;",
        "",
        "    return OK;",
        "}"
    };
    unsigned cantRegistrosInsertarListaSimpleAlFinal = sizeof(insertarListaSimpleAlFinal) / TAM_MAX;

    printf("EJERCICIO 4\n");

    printf("\nImplementacion listaSimplementeEnlazada:\n\n");
    mostrarVectorDeCadenas(insertarListaSimpleAlFinal, cantRegistrosInsertarListaSimpleAlFinal, mostrarCadena);
}

void ejercicio5()
{
    char nodoArbol[][TAM_MAX] =
    {
        "typedef struct sNodoa",
        "{",
        "    void* d;",
        "    unsigned tam;",
        "    struct sNodoa* der;",
        "    struct sNodoa* izq;",
        "}tNodoa;"
    };
    unsigned cantRegistrosNodoArbol = sizeof(nodoArbol) / TAM_MAX;

    char insertarEnArbol[][TAM_MAX] =
    {
        "int insertarEnArbol(tArbol* a, const void* d,unsigned tam, int (*comparar)(const void*a,const void* b))",
        "{",
        "    tNodoa* nuevo;",
        "    int cmp;",
        "",
        "    if(*a == NULL)",
        "    {",
        "        nuevo = (tNodoa*)malloc(sizeof(tNodoa));",
        "        if(!nuevo)",
        "        {",
        "            return NO_PUDE_INSERTAR;",
        "        }",
        "        nuevo->d = malloc(tam);",
        "        if(!(nuevo->d))",
        "        {",
        "            free(nuevo);",
        "            return NO_PUDE_INSERTAR;",
        "        }",
        "        nuevo->tam = tam;",
        "        nuevo->der = NULL;",
        "        nuevo->izq = NULL;",
        "        memcpy(nuevo->d, d, tam);",
        "        *a = nuevo;",
        "        return OK;",
        "    }",
        "    cmp = comparar((*a)->d, d);",
        "",
        "    if(cmp > 0)",
        "    {",
        "        return insertarEnArbol(&((*a)->izq), d, tam, comparar);",
        "    }",
        "    if(cmp < 0)",
        "    {",
        "        return insertarEnArbol(&((*a)->der), d, tam, comparar);",
        "    }",
        "",
        "    if(!cmp)",
        "    {",
        "        return OK; // hubo duplicados pero no me interesa, sigo insertando",
        "    }",
        "",
        "    return NO_PUDE_INSERTAR;",
        "}"
    };
    unsigned cantRegistrosInsertarEnArbol = sizeof(insertarEnArbol) / TAM_MAX;

    printf("EJERCICIO 5\n");

    printf("Grafico de arbol binario:\n");
    printf("\t    2\n");
    printf("\t  /   \\\n");
    printf("\t1\t3\n");

    printf("Los nodos utilizados anteriormente ya no sirve.\n");
    printf("Tipos de recorrido en arbol:\n");
    printf("-[R-I-D]PreOrden\n");
    printf("-[I-R-D]Orden\n");
    printf("-[I-D-R]PostOrden\n");

    printf("\nImplementacion nodoArbol:\n\n");
    mostrarVectorDeCadenas(nodoArbol, cantRegistrosNodoArbol, mostrarCadena);

    printf("\nImplementacion arbol:\n\n");
    mostrarVectorDeCadenas(insertarEnArbol, cantRegistrosInsertarEnArbol, mostrarCadena);
}



