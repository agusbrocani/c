#include "../../include/cola/Estatica/cola.h"

void crearCola( tCola* c )
{
    c->pri = 0;
    c->ult = 0;
    c->tamDisponible = TAM_COLA;
}

int acolar( tCola* c, const void* dato, unsigned tam )
{
    unsigned primeraParte;
    unsigned segundaParte;

    if(         c->tamDisponible < tam + sizeof( unsigned ) )
    {
        return NO_HAY_LUGAR;
    }

    primeraParte = MENOR( sizeof( unsigned ), TAM_COLA - c->ult );

    if(         primeraParte            )
    {
        memcpy( c->cola + c->ult, &tam, primeraParte );
    }

    segundaParte = sizeof(unsigned) - primeraParte;

    if(         segundaParte            )
    {
        memcpy( c->cola, (&tam) + primeraParte, segundaParte );
    }

    c->ult = segundaParte ? segundaParte : c->ult + primeraParte;

    primeraParte = MENOR( tam, TAM_COLA - c->ult );

    if(         primeraParte            )
    {
        memcpy( c->cola + c->ult, dato, primeraParte );
    }

    segundaParte = tam - primeraParte;

    if(         segundaParte            )
    {
        memcpy( c->cola, dato + primeraParte, segundaParte );
    }

    c->ult = segundaParte ? segundaParte : c->ult + primeraParte;
    c->tamDisponible -= tam + sizeof( unsigned );

    return OK;
}

int desacolar( tCola* c, void* dato, unsigned tam )
{
    unsigned primeraParte;
    unsigned segundaParte;
    unsigned tamLeidoDeCola;        //esto es lo que actualiza el tamDisponible[SIEMPRE]
    unsigned tamFinalADesacolar;    //esto es lo que desacolo[SIEMPRE]

    if(         c->tamDisponible == TAM_COLA            )
    {
        return COLA_VACIA;
    }

    primeraParte = MENOR( sizeof( unsigned ), TAM_COLA - c->pri );

    if(         primeraParte            )
    {
        memcpy( &tamLeidoDeCola, c->cola + c->pri, primeraParte );
    }

    segundaParte = sizeof( unsigned ) - primeraParte;

    if(         segundaParte            )
    {
        memcpy( ( &tamLeidoDeCola ) + primeraParte, c->cola, segundaParte );
    }

    c->pri = segundaParte ? segundaParte : c->pri + primeraParte;

    tamFinalADesacolar = MENOR( tamLeidoDeCola, tam );

    primeraParte = MENOR( tamFinalADesacolar, TAM_COLA - c->pri );

    if(         primeraParte            )
    {
        memcpy( dato, c->cola + c->pri, primeraParte );
    }

    segundaParte = tamFinalADesacolar - primeraParte;

    if(         segundaParte            )
    {
        memcpy( dato + primeraParte, c->cola, segundaParte );
    }

    //c->pri = segundaParte ? segundaParte : c->pri + primeraParte;   //esto no esta bien -> segundaParte y primeraParte trabajan[EN ALGUNOS CASOS] con un tamaño que NO es el total
    c->pri = ( c->pri + tamLeidoDeCola ) % TAM_COLA;
    c->tamDisponible += tamLeidoDeCola + sizeof( unsigned );

    return OK;
}

int colaVacia( const tCola* c )
{
    return TAM_COLA == c->tamDisponible;
}

int colaLlena( const tCola* c, unsigned tam )
{
    if(         c->tamDisponible < tam + sizeof(unsigned)           )
    {
        return COLA_LLENA;
    }
    return HAY_LUGAR;
}

void vaciarCola( tCola* c )
{
    c->pri = 0;
    c->ult = 0;
    c->tamDisponible = TAM_COLA;
}

int verPrimero( const tCola* c, void* dato, unsigned tam )
{
    unsigned primeraParte;
    unsigned segundaParte;
    unsigned tamLeidoDeColaYPosteriormenteADesacolar;
    unsigned primero = c->pri;   // para no pisar c->pri despues de que leo el tamaño del dato

    if(         c->tamDisponible == TAM_COLA         )
    {
        return COLA_VACIA;
    }

    primeraParte = MENOR( sizeof( unsigned ), TAM_COLA - primero );

    if(         primeraParte            )
    {
        memcpy( &tamLeidoDeColaYPosteriormenteADesacolar, c->cola + primero, primeraParte );
    }

    segundaParte = sizeof( unsigned ) - primeraParte;

    if(         segundaParte            )
    {
        memcpy( (&tamLeidoDeColaYPosteriormenteADesacolar)+ primeraParte, c->cola, segundaParte );
    }

    primero = segundaParte ? segundaParte : primero + primeraParte;

    tamLeidoDeColaYPosteriormenteADesacolar = MENOR( tamLeidoDeColaYPosteriormenteADesacolar, tam );

    primeraParte = MENOR( tamLeidoDeColaYPosteriormenteADesacolar, TAM_COLA - primero );

    if(         primeraParte            )
    {
        memcpy( dato, c->cola + primero, primeraParte );
    }

    segundaParte = tamLeidoDeColaYPosteriormenteADesacolar - primeraParte;

    if(         segundaParte            )
    {
        memcpy( dato + primeraParte, c->cola, segundaParte );
    }

    return OK;
}
