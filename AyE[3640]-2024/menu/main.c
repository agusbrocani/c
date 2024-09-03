#include "../Bibliotecas/include/menu.h"

//el usuario debe implementar:
#define OPCION1 1
#define OPCION2 2
#define OPCION3 3
#define OPCION4 4
#define OPCIONa 'a'

void switchMenuCasoPrueba(int opcion)
{
    switch(opcion)
    {
        case OPCION1:
            printf("ACCION 1\n");
        break;
        case OPCION2:
            printf("ACCION 2\n");
        break;
        case OPCION3:
            printf("ACCION 3\n");
        break;
        case OPCION4:
            printf("ACCION 4\n");
        break;
        case A_MAYUS(OPCIONa):
            printf("ACCION a\n");
        break;
        default:
            printf("ENTRE POR DEFAULT\n");
        break;
    }
}

int main()
{
//    char textoMenu[][MAX_TAM_TEXTO] =
//    {
//        "Menu:",
//        "[SALIDA]-TEXTO",
//        "[0123456789]-TEXTO",
//        "[-01234567]-TEXTO",
//        "[012345a78]-TEXTO",
//        "[a12345678]-TEXTO",
//        "[01234567a]-TEXTO",
//        "",
//        "]",
//        "[",
//        "[]",
//        "[*]",
//        "[0a]",
//        "[a0]",
//        "[A]",
//        "[B]",
//        "[C]",
//        "[D]",
//        "[E]",
//        "[F]",
//        "[G]",
//        "[H]",
//        "[I]",
//        "[J]",
//        "[K]",
//        "[L]",
//        "[M]",
//        "[N]",
//        "[O]",
//        "[P]",
//        "[Q]",
//        "[R]",
//        "[S]",
//        "[T]",
//        "[U]",
//        "[V]",
//        "[W]",
//        "[X]",
//        "[Y]",
//        "[Z]",
//        "[a]",
//        "[b]",
//        "[c]",
//        "[d]",
//        "[e]",
//        "[f]",
//        "[g]",
//        "[h]",
//        "[i]",
//        "[j]",
//        "[k]",
//        "[l]",
//        "[m]",
//        "[n]",
//        "[o]",
//        "[p]",
//        "[q]",
//        "[r]",
//        "[s]",
//        "[t]",
//        "[u]",
//        "[v]",
//        "[w]",
//        "[x]",
//        "[y]",
//        "[z]",
//        "[0]-VALIDO",
//        "[9]-VALIDO",
//        "[1]",
//        "[2]",
//        "[3]",
//        "[4]",
//        "[01]-VALIDO",
//        "[012345678]-MAX_RANGE_VALIDO",
//        "FIN MENU\n"
//    };

    char textoMenu[][MAX_TAM_TEXTO] =
    {
      "Menu:",
      "[0]-SALIR",//0 a 999999999 o a-z o A-Z
      "[1]-Opcion 1",
      "[2]-Opcion 2",
      "[3]-Opcion 3",
      "[4]-Opcion 4",
      "[a]-Opcion a",
    };
    unsigned cantidadDeRegistros = sizeof(textoMenu) / MAX_TAM_TEXTO;

    menu(textoMenu, cantidadDeRegistros, switchMenuCasoPrueba);

    return 0;
}
