#include "unidad4TDA.h"

int esBisiesto(unsigned anio)
{
    return ( 0 == anio % 4 && 0 != anio % 100 ) || ( 0 == anio % 400 );
}

int esFechaValida(tFecha* f)
{
    unsigned matDias[][MESES_DEL_ANIO] =
    {
        {31,28,31,30,31,30,31,31,30,31,30,31},  //noEsBisiesto
        {31,29,31,30,31,30,31,31,30,31,30,31}   //esBisiesto
    };
    int diasMes;

    if(         f->anio < 1600 || !(f->mes >= 1 && f-> mes <= 12) || !(f->dia >= 1 && f-> dia <= 31)          )
    {
        return 0;
    }

    diasMes = matDias[esBisiesto((f->anio))][((f->mes)-1)];
    return (diasMes - (f->dia) >= 0) ? 1 : 0;
}
