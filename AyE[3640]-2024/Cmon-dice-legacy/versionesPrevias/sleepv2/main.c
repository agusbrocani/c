#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   //Para Sleep y funciones de Windows
#include <conio.h>     //Para _kbhit() y _getch()
#include <pthread.h>   //Para usar hilos para temporizador en paralelo
#define ES_LETRA(X) (((X) >= 'A' && (X) <= 'Z') || ((X) >= 'a' && (X) <= 'z'))

typedef struct
{
    COORD posicionDeOrigen;
    COORD posicionDeTextoLetraIngresada;
    COORD posicionDeTextoFinal;
    COORD posicionDelTemporizadorEnConsola;
}tCoordenadas;

typedef struct
{
    tCoordenadas coordenadas;
    int timeout;
    int tiempoRestanteParaIngresoDeSecuencia;
    int detenerTemporizador;
    HANDLE hConsole;
}tRecursos;

// Función para ocultar el cursor
void ocultarCursor(tRecursos* recursos)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(recursos->hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; //Oculta el cursor
    SetConsoleCursorInfo(recursos->hConsole, &cursorInfo); //Cambia el cursor usando la referencia
}

// Función para limpiar la consola
void limpiarConsola(tRecursos* recursos)
{
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD length;

    GetConsoleScreenBufferInfo(recursos->hConsole, &screen);
    length = screen.dwSize.X * screen.dwSize.Y;
    FillConsoleOutputCharacter(recursos->hConsole, ' ', length, recursos->coordenadas.posicionDeOrigen, &written);
    SetConsoleCursorPosition(recursos->hConsole, recursos->coordenadas.posicionDeOrigen);
}

void deshabilitarQuickEditMode()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;

    // Obtiene el modo actual de la consola
    GetConsoleMode(hInput, &prev_mode);

    //Deshabilita el modo de edición rápida(Quick Edit) que permite la selección con el mouse[Mantiene la entrada por teclado]
    SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);///~ es para hacer el complemento bit a bit
}

void* accionParaThreadDeTemporizador(void* arg)
{
    tRecursos* recursos = (tRecursos*)arg;
    LARGE_INTEGER frequency, start, end;
    double tiempoTranscurrido = 0.0;

    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
    QueryPerformanceCounter(&start);       // Inicio del conteo

    SetConsoleCursorPosition(recursos->hConsole, recursos->coordenadas.posicionDelTemporizadorEnConsola);
    printf("%d seg   ", recursos->tiempoRestanteParaIngresoDeSecuencia); // Muestra el temporizador
    fflush(stdout); // Asegura que se muestre inmediatamente

    //Bucle del temporizador
    while(recursos->tiempoRestanteParaIngresoDeSecuencia > 0 && !recursos->detenerTemporizador)
    {
        QueryPerformanceCounter(&end);
        tiempoTranscurrido = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        if(tiempoTranscurrido >= 1.0) // Cada segundo
        {
            recursos->tiempoRestanteParaIngresoDeSecuencia--;
            start = end; // Reiniciar el contador para el próximo segundo

            if (recursos->detenerTemporizador)
                break;

            // Mueve el cursor a la posición del cronómetro
            SetConsoleCursorPosition(recursos->hConsole, recursos->coordenadas.posicionDelTemporizadorEnConsola);
            printf("%d seg   ", recursos->tiempoRestanteParaIngresoDeSecuencia);
            fflush(stdout); //Asegura que se muestre inmediatamente
        }

        Sleep(10); //Breve pausa para evitar uso intensivo de CPU
    }

    if(!recursos->tiempoRestanteParaIngresoDeSecuencia)//Si no queda tiempo restante
    {
        recursos->timeout = 1;///SE TERMINO EL TIEMPO
    }

    return NULL;
}

void configuracionesGraficas(tRecursos* recursos)
{
    //Deshabilitar el modo de edición rápida(Quick Edit)
    deshabilitarQuickEditMode();
    //Ocultar el cursor del temporizador
    ocultarCursor(recursos);
    //Limpiar consola al iniciar
    limpiarConsola(recursos);
}

void inicializacionDeRecursos(tRecursos* recursos)
{
    recursos->detenerTemporizador = 0;  // Mantener el temporizador corriendo para toda la secuencia

    recursos->coordenadas.posicionDelTemporizadorEnConsola.X = 90; // Posición del temporizador X
    recursos->coordenadas.posicionDelTemporizadorEnConsola.Y = 0; // Posición del temporizador Y

    recursos->coordenadas.posicionDeOrigen.X = 0;
    recursos->coordenadas.posicionDeOrigen.Y = 0;

    recursos->timeout = 0;
    recursos->tiempoRestanteParaIngresoDeSecuencia = 4; /// TIEMPO TOTAL PARA INGRESAR LA SECUENCIA
    recursos->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ingresoDeSecuencia(tRecursos* recursos)
{
    pthread_t id; //ID del hilo
    char ch;
    int maximaCantidadDeCaracteresDeSecuenciaPorRonda = 5;  /// CANTIDAD DE CARACTERES DE SECUENCIA A INGRESAR
    int cantidadDeCaracteresDeSecuenciaIngresados = 0; // Contador de intentos

    inicializacionDeRecursos(recursos);
    configuracionesGraficas(recursos);

    printf("Ingresa un caracter (X, V, A, R, N):\n");
    pthread_create(&id, NULL, accionParaThreadDeTemporizador, recursos);   //EJECUTA TEMPORIZADOR EN PARALELO
    while(1)// Bucle principal para ingresar la secuencia
    {
        //Bucle para esperar la entrada del usuario o el timeout
        while(!recursos->timeout)
        {
            if(_kbhit())//Verifica si presione una tecla
            {
                ch = _getch(); //Lee un caracter SIN ESPERAR ENTER

                if(ES_LETRA(ch))
                {
                    ch = toupper(ch);
                }

                if ('X' == ch || 'V' == ch || 'A' == ch || 'R' == ch || 'N' == ch)
                {
                    //Posición para mostrar secuencia ingresada
                    recursos->coordenadas.posicionDeTextoLetraIngresada.X = recursos->coordenadas.posicionDeOrigen.X;
                    recursos->coordenadas.posicionDeTextoLetraIngresada.Y = recursos->coordenadas.posicionDeOrigen.Y + cantidadDeCaracteresDeSecuenciaIngresados + 2;

                    SetConsoleCursorPosition(recursos->hConsole, recursos->coordenadas.posicionDeTextoLetraIngresada); // Mueve el cursor para mostrar el caracter ingresado
                    printf("Letra de secuencia ingresada: %c", ch); // Mostrar el caracter ingresado

                    cantidadDeCaracteresDeSecuenciaIngresados++; // Incrementar el contador de intentos
                    break;
                }
            }
        }

        if(recursos->timeout || cantidadDeCaracteresDeSecuenciaIngresados == maximaCantidadDeCaracteresDeSecuenciaPorRonda || 'X' == ch)//NO es timeout
        {
            recursos->detenerTemporizador = 1;
            break; //Fin ronda
        }
    }

    pthread_join(id, NULL);///FUERZO AL HILO MAIN a que el hilo del temporizador termine para proseguir con la ejecucion del codigo

    if(recursos->timeout)
    {
        recursos->coordenadas.posicionDeTextoFinal.X = recursos->coordenadas.posicionDeOrigen.X;
        recursos->coordenadas.posicionDeTextoFinal.Y = recursos->coordenadas.posicionDeOrigen.Y + cantidadDeCaracteresDeSecuenciaIngresados + 2;
        SetConsoleCursorPosition(recursos->hConsole, recursos->coordenadas.posicionDeTextoFinal);
    }

    printf("\n");
    if(recursos->timeout)
    {
        printf("No completaste la secuencia. Se acabo el tiempo.\n");
    }else if(cantidadDeCaracteresDeSecuenciaIngresados == maximaCantidadDeCaracteresDeSecuenciaPorRonda)
        {
            printf("Secuencia ingresada exitosamente!\n");
        }
        else
        {
            printf("Uso de vida.\n");
        }
}

int main()
{
    tRecursos recursos;

    ingresoDeSecuencia(&recursos);

    return 0;
}
