#include "unidad4.h"

void accionGrabarArchivo(void* dato, void* recursos)
{
    printf("Duplicado:\n");
    grabarProductos(stdout, dato);
    fwrite((tProducto*)dato, sizeof(tProducto), 1, (FILE*)recursos);
}

int main()
{
    FILE* datos1;
    FILE* datos2;
    FILE* errores2;
    t_lista listaDatos1;
    t_lista listaDatos2;
    tProducto loteDatos1[CE_PRODUCTOS];
    tProducto loteDatos2[CE_PRODUCTOS];
    tProducto producto;
    int tam = sizeof(tProducto);

    if(!abrirArchivo(&datos1, "datos1.bin", "wb+"))
    {
        return NO_PUDE_ABRIR_DATOS1;
    }

    if(!abrirArchivo(&datos2, "datos2.bin", "wb+"))
    {
        fclose(datos1);
        return NO_PUDE_ABRIR_DATOS2;
    }

    if(!abrirArchivo(&errores2, "errores2.bin", "wb+"))
    {
        fclose(datos1);
        fclose(datos2);
        return NO_PUDE_ABRIR_ERRORES2;
    }

    cargarProductos(loteDatos1, CE_PRODUCTOS);
    cargarProductos(loteDatos2, CE_PRODUCTOS);

    fwrite(loteDatos1, sizeof(loteDatos1), 1, datos1);
    fseek(datos1, 0L, SEEK_CUR);
    fwrite(loteDatos2, sizeof(loteDatos2), 1, datos2);
    fseek(datos2, 0L, SEEK_CUR);

    rewind(datos1);
    rewind(datos2);

    crearListaSimple(&listaDatos1);
    crearListaSimple(&listaDatos2);

    fread(&producto, tam, 1, datos1);
    while(!feof(datos1))
    {
        insertarOrdenadoEnListaSimpleSinDuplicados(&listaDatos1, &producto, tam, compararPorFechaDeVentaProveedorClave, accionParaDuplicados);
        fread(&producto, tam, 1, datos1);
    }
    printf("Mostrando archivo de datos 1 en lista 1:\n");
    mostrarListaSimpleEnOrden(&listaDatos1, mostrarProducto);
    printf("\n");

    fread(&producto, tam, 1, datos2);
    while(!feof(datos2))
    {
        insertarPrimeroEnListaSimple(&listaDatos2, &producto, tam);
        fread(&producto, tam, 1, datos2);
    }
    ordenarListaSimple(&listaDatos2, compararPorFechaDeVentaProveedorClave);

    printf("Mostrando archivo de datos 2 en lista 2:\n");
    mostrarListaSimpleEnOrden(&listaDatos2, mostrarProducto);
    printf("\n");
    system("pause");
    system("cls");

    eliminarDuplicadosEnListaSimpleConAccion(&listaDatos2, errores2, compararPorFechaDeVentaProveedorClave, accionGrabarArchivo);

    fseek(errores2, 0L, SEEK_CUR);
    rewind(errores2);

    system("pause");
    system("cls");

    fread(&producto, tam, 1, errores2);
    while(!feof(errores2))
    {
        printf("Producto duplicado leido del archivo:\n");
        mostrarProducto(&producto);
        printf("\n");
        fread(&producto, tam, 1, errores2);
    }

    vaciarListaSimple(&listaDatos1);
    vaciarListaSimple(&listaDatos2);
    fclose(datos1);
    fclose(datos2);
    fclose(errores2);

    return 0;
}
