#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Hello world!\n");
    return 0;
}

/***

    SOLUCION DEL EJERCICIO QUE MANDO EL PROFE

int disminuirNUltimos(tTDA* pl,unsigned tam)///LISTA Y CANTIDAD A ELIMINAR NODOS DE LISTA
{
    tTDA pila;///ES DE tNodos* LA PILA --->Me va a guardar las direcciones de los nodos de la lista
    tNodo** eliminar;
    unsigned cantElementos=0;
    unsigned i;

    crearPila(&pila);

    while((*pl))
    {
        apilar(&pila,&pl,sizeof(tNodo**));///pl es un doble puntero
        cantElementos++;
        pl=&((*pl)->sig);
    }

    ///APILAMOS TODOS LOS NODOS DE LA LISTA EN LA PILA
    ///CONTAMOS CUANTOS ELEMENTOS HABIA

    if(tam>cantElementos)
    {
        ///NO PUEDO ELIMINAR NADA

        vaciarPila(&pila);
        return 0;
    }

    for(i=0;i<tam;i++)
    {
        desapilar(&pila,&eliminar,sizeof(tNodo**));///RESCATO LA DIRECCION DE LOS ULTIMOS NODOS DE LA LISTA
        free((*eliminar)->d);
        free((*eliminar));
        (*eliminar)=NULL;///ACCEDO A LA DIRECCION DEL NODO
    }

    vaciarPila(&pila);

    return 1;
}



***/

