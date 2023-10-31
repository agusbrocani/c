#include "unidad4TDA.h"

int main()
{
    tFecha fecha = {29,02,1900};

    if(!esFechaValida(&fecha))
    {
        printf("La fecha NO es valida\n");
    }
    else
    {
        printf("La fecha es valida\n");
    }

    return 0;
}
