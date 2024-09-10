#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Bibliotecas/include/cola/Dinamica/cola.h"

int main()
{
//    simularColaCajero();
    srand(time(NULL));

    printf("%d", rand() % 15);
    return 0;
}
