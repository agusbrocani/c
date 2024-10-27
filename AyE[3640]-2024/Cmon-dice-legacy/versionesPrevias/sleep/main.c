#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   // Para Sleep y funciones de Windows
#include <conio.h>     // Para _kbhit() y _getch()
#include <pthread.h>   // Biblioteca para hilos (threads)

// Definir la estructura que contiene los recursos
typedef struct
{
    int timeout;
    int remaining_time;
    int stop_timer;
    HANDLE hConsole;
} tRecursos;

// Función para ocultar el cursor
void hideCursor(tRecursos* recursos)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(recursos->hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Oculta el cursor
    SetConsoleCursorInfo(recursos->hConsole, &cursorInfo); // Cambia el cursor usando la referencia
}

// Función para limpiar la consola
void clearConsole(tRecursos* recursos)
{
    COORD topLeft = {0, 0};
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD length;
    GetConsoleScreenBufferInfo(recursos->hConsole, &screen);
    length = screen.dwSize.X * screen.dwSize.Y;
    FillConsoleOutputCharacter(recursos->hConsole, ' ', length, topLeft, &written);
    SetConsoleCursorPosition(recursos->hConsole, topLeft);
}

// Función para deshabilitar el modo de edición rápida (Quick Edit)
void disableQuickEditMode()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;

    // Obtiene el modo actual de la consola
    GetConsoleMode(hInput, &prev_mode);

    // Deshabilita el modo de edición rápida (Quick Edit) que permite la selección con el mouse
    // Mantiene otros modos como la entrada por teclado
    SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

// Función para el hilo del temporizador
void* timer_thread(void* arg)
{
    tRecursos* recursos = (tRecursos*)arg;
    LARGE_INTEGER frequency, start, end;
    double elapsed_time = 0.0;
    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
    QueryPerformanceCounter(&start);       // Inicio del conteo

    // Bucle del temporizador
    while (recursos->remaining_time > 0 && !recursos->stop_timer)
    {
        QueryPerformanceCounter(&end);
        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        if (elapsed_time >= 1.0) // Cada segundo
        {
            recursos->remaining_time--;
            start = end; // Reiniciar el contador para el próximo segundo

            if (recursos->stop_timer) break;

            // Mueve el cursor a la posición del cronómetro
            COORD pos = {90, 0};  // Posiciona el temporizador en el margen derecho
            SetConsoleCursorPosition(recursos->hConsole, pos);
            printf("%d seg   ", recursos->remaining_time); // Asegúrate de sobrescribir con espacios
            fflush(stdout); // Asegura que se muestre inmediatamente
        }

        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
    }

    if (recursos->remaining_time == 0) // Si el tiempo se agota
    {
        recursos->timeout = 1; // Marca que el tiempo ha pasado
    }

    return NULL;
}

int main()
{
    pthread_t tid; // Identificador del hilo
    char ch;
    int max_attempts = 5;  // Parámetro ajustable: Número de secuencias a ingresar
    int attempt_count = 0; // Contador de intentos
    COORD input_pos = {0, 2}; // Posición inicial para los mensajes de ingreso

    // Inicializar la estructura de recursos
    tRecursos recursos;
    recursos.timeout = 0;
    recursos.remaining_time = 10; // Tiempo total para la secuencia en segundos
    recursos.stop_timer = 0;      // Variable para detener el temporizador
    recursos.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Deshabilitar el modo de edición rápida (Quick Edit)
    disableQuickEditMode();

    // Ocultar el cursor del temporizador
    hideCursor(&recursos);

    // Limpiar consola al iniciar
    clearConsole(&recursos);

    // Iniciar el hilo del temporizador antes de imprimir el mensaje
    pthread_create(&tid, NULL, timer_thread, (void*)&recursos);

    // Imprimir el mensaje y el temporizador al mismo tiempo
    printf("Simon dice - Secuencia de colores:\n");
    COORD pos = {90, 0}; // Posición del temporizador
    SetConsoleCursorPosition(recursos.hConsole, pos);
    printf("%d seg   ", recursos.remaining_time); // Muestra el temporizador
    fflush(stdout); // Asegura que se muestre inmediatamente

    // Bucle principal para ingresar la secuencia
    while (attempt_count < max_attempts && !recursos.timeout)
    {
        recursos.stop_timer = 0;  // Mantener el temporizador corriendo para toda la secuencia

        // Mostrar el mensaje de ingreso en una línea fija
        SetConsoleCursorPosition(recursos.hConsole, input_pos); // Posición del mensaje de ingreso
        printf("Ingresa un caracter (X, V, A, R, N o en minusculas): ");

        // Bucle para esperar la entrada del usuario o el timeout
        while (!recursos.timeout)
        {
            if (_kbhit())
            { // Verifica si se ha presionado una tecla
                ch = _getch(); // Lee el caracter sin esperar a Enter

                // Verificar si el caracter es uno de los permitidos (mayúsculas o minúsculas)
                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
                {
                    COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posición para mostrar secuencia ingresada
                    SetConsoleCursorPosition(recursos.hConsole, char_pos); // Mueve el cursor para mostrar el caracter ingresado
                    printf("Letra de secuencia ingresada: %c", toupper(ch)); // Mostrar el caracter ingresado

                    attempt_count++; // Incrementar el contador de intentos
                    break;
                }
            }
        }

        // Si el tiempo se agotó
        if (recursos.timeout == 1)
        {
            COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posición para mostrar el mensaje de tiempo agotado
            SetConsoleCursorPosition(recursos.hConsole, char_pos);
            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
            break; // Puedes finalizar el juego si el tiempo se agota
        }

        // Si se ingresaron todos los caracteres antes de que se acabe el tiempo
        if (attempt_count == max_attempts)
        {
            recursos.stop_timer = 1; // Detener el temporizador
            COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posición para el resultado final
            SetConsoleCursorPosition(recursos.hConsole, result_pos);
            printf("Secuencia ingresada exitosamente!\n");
            break; // Finaliza el bucle
        }
    }

    // Espera a que el hilo del temporizador termine
    pthread_join(tid, NULL);

    if (recursos.timeout)
    {
        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posición para el resultado final
        SetConsoleCursorPosition(recursos.hConsole, result_pos);
        printf("No completaste la secuencia. Se acabo el tiempo.\n");
    }

    return 0;
}
///ESTE CODIGO ANDA
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 10; // Tiempo total para la secuencia en segundos
//int stop_timer = 0;      // Variable para detener el temporizador
//HANDLE hConsole;         // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo); // Cambia el cursor usando la referencia
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para deshabilitar el modo de edicion rapida (Quick Edit)
//void disableQuickEditMode()
//{
//    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//    DWORD prev_mode;
//
//    // Obtiene el modo actual de la consola
//    GetConsoleMode(hInput, &prev_mode);
//
//    // Deshabilita el modo de edicion rapida (Quick Edit) que permite la seleccion con el mouse
//    // Mantiene otros modos como la entrada por teclado
//    SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
//}
//
//// Funcion para el hilo del temporizador
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el proximo segundo
//
//            if (stop_timer) break;
//
//            // Mueve el cursor a la posicion del cronometro
//            COORD pos = {90, 0};  // Posiciona el temporizador en el margen derecho
//            SetConsoleCursorPosition(hConsole, pos);
//            printf("%d seg   ", remaining_time); // Asegurate de sobrescribir con espacios
//            fflush(stdout); // Asegura que se muestre inmediatamente
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//    int max_attempts = 5;  // Parametro ajustable: Numero de secuencias a ingresar
//    int attempt_count = 0; // Contador de intentos
//    COORD input_pos = {0, 2}; // Posicion inicial para los mensajes de ingreso
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Deshabilitar el modo de edicion rapida (Quick Edit)
//    disableQuickEditMode();
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Limpiar consola al iniciar
//    clearConsole();
//
//    // Iniciar el hilo del temporizador antes de imprimir el mensaje
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Imprimir el mensaje y el temporizador al mismo tiempo
//    printf("Simon dice - Secuencia de colores:\n");
//    COORD pos = {90, 0}; // Posicion del temporizador
//    SetConsoleCursorPosition(hConsole, pos);
//    printf("%d seg   ", remaining_time); // Muestra el temporizador
//    fflush(stdout); // Asegura que se muestre inmediatamente
//
//    // Bucle principal para ingresar la secuencia
//    while (attempt_count < max_attempts && !timeout)
//    {
//        stop_timer = 0;  // Mantener el temporizador corriendo para toda la secuencia
//
//        // Mostrar el mensaje de ingreso en una linea fija
//        SetConsoleCursorPosition(hConsole, input_pos); // Posicion del mensaje de ingreso
//        printf("Ingresa un caracter (X, V, A, R, N o en minusculas): ");
//
//        // Bucle para esperar la entrada del usuario o el timeout
//        while (!timeout)
//        {
//            if (_kbhit())
//            { // Verifica si se ha presionado una tecla
//                ch = _getch(); // Lee el caracter sin esperar a Enter
//
//                // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//                {
//                    COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar secuencia ingresada
//                    SetConsoleCursorPosition(hConsole, char_pos); // Mueve el cursor para mostrar el caracter ingresado
//                    printf("Letra de secuencia ingresada: %c", toupper(ch)); // Mostrar el caracter ingresado
//
//                    attempt_count++; // Incrementar el contador de intentos
//                    break;
//                }
//            }
//        }
//
//        // Si el tiempo se agoto
//        if (timeout == 1)
//        {
//            COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar el mensaje de tiempo agotado
//            SetConsoleCursorPosition(hConsole, char_pos);
//            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//            break; // Puedes finalizar el juego si el tiempo se agota
//        }
//
//        // Si se ingresaron todos los caracteres antes de que se acabe el tiempo
//        if (attempt_count == max_attempts)
//        {
//            stop_timer = 1; // Detener el temporizador
//            COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//            SetConsoleCursorPosition(hConsole, result_pos);
//            printf("Secuencia ingresada exitosamente!\n");
//            break; // Finaliza el bucle
//        }
//    }
//
//    // Espera a que el hilo del temporizador termine
//    pthread_join(tid, NULL);
//
//    if (timeout)
//    {
//        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//        SetConsoleCursorPosition(hConsole, result_pos);
//        printf("No completaste la secuencia. Se acabo el tiempo.\n");
//    }
//
//    return 0;
//}

///CODIGO QUE FUNCIONA BIEN
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 10; // Tiempo total para la secuencia en segundos
//int stop_timer = 0;      // Variable para detener el temporizador
//HANDLE hConsole;         // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo); // Cambia el cursor usando la referencia
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el proximo segundo
//
//            if (stop_timer) break;
//
//            // Mueve el cursor a la posicion del cronometro
//            COORD pos = {90, 0};  // Posiciona el temporizador en el margen derecho
//            SetConsoleCursorPosition(hConsole, pos);
//            printf("%d seg   ", remaining_time); // Asegurate de sobrescribir con espacios
//            fflush(stdout); // Asegura que se muestre inmediatamente
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//    int max_attempts = 5;  // Parametro ajustable: Numero de secuencias a ingresar
//    int attempt_count = 0; // Contador de intentos
//    COORD input_pos = {0, 2}; // Posicion inicial para los mensajes de ingreso
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
////    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Limpiar consola al iniciar
//    clearConsole();
//
//    // Iniciar el hilo del temporizador antes de imprimir el mensaje
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Imprimir el mensaje y el temporizador al mismo tiempo
//    printf("Simon dice - Secuencia de colores:\n");
//    COORD pos = {90, 0}; // Posición del temporizador
//    SetConsoleCursorPosition(hConsole, pos);
//    printf("%d seg   ", remaining_time); // Muestra el temporizador
//    fflush(stdout); // Asegura que se muestre inmediatamente
//
//    // Bucle principal para ingresar la secuencia
//    while (attempt_count < max_attempts && !timeout)
//    {
//        stop_timer = 0;  // Mantener el temporizador corriendo para toda la secuencia
//
//        // Mostrar el mensaje de ingreso en una linea fija
//        SetConsoleCursorPosition(hConsole, input_pos); // Posicion del mensaje de ingreso
//        printf("Ingresa un caracter (X, V, A, R, N o en minusculas): ");
//
//        // Bucle para esperar la entrada del usuario o el timeout
//        while (!timeout)
//        {
//            if (_kbhit())
//            { // Verifica si se ha presionado una tecla
//                ch = _getch(); // Lee el caracter sin esperar a Enter
//
//                // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//                {
//                    COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar secuencia ingresada
//                    SetConsoleCursorPosition(hConsole, char_pos); // Mueve el cursor para mostrar el caracter ingresado
//                    printf("Letra de secuencia ingresada: %c", ch); // Mostrar el caracter ingresado
//
//                    attempt_count++; // Incrementar el contador de intentos
//                    break;
//                }
//            }
//        }
//
//        // Si el tiempo se agoto
//        if (timeout == 1)
//        {
//            COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar el mensaje de tiempo agotado
//            SetConsoleCursorPosition(hConsole, char_pos);
//            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//            break; // Puedes finalizar el juego si el tiempo se agota
//        }
//
//        // Si se ingresaron todos los caracteres antes de que se acabe el tiempo
//        if (attempt_count == max_attempts)
//        {
//            stop_timer = 1; // Detener el temporizador
//            COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//            SetConsoleCursorPosition(hConsole, result_pos);
//            printf("Secuencia ingresada exitosamente!\n");
//            break; // Finaliza el bucle
//        }
//    }
//
//    // Espera a que el hilo del temporizador termine
//    pthread_join(tid, NULL);
//
//    if (timeout)
//    {
//        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//        SetConsoleCursorPosition(hConsole, result_pos);
//        printf("No completaste la secuencia. Se acabo el tiempo.\n");
//    }
//
//    return 0;
//}

///CASI CUMPLE TODO LO QUE NECESITO
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 10; // Tiempo total para la secuencia en segundos
//int stop_timer = 0;      // Variable para detener el temporizador
//HANDLE hConsole;         // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo); // Cambia el cursor usando la referencia
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el proximo segundo
//
//            if (stop_timer) break;
//
//            // Mueve el cursor a la posicion del cronometro
//            COORD pos = {90, 0};  // Posiciona el temporizador en el margen derecho
//            SetConsoleCursorPosition(hConsole, pos);
//            printf("%d seg   ", remaining_time); // Asegurate de sobrescribir con espacios
//            fflush(stdout); // Asegura que se muestre inmediatamente
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//    int max_attempts = 5;  // Parametro ajustable: Numero de secuencias a ingresar
//    int attempt_count = 0; // Contador de intentos
//    COORD input_pos = {0, 2}; // Posicion inicial para los mensajes de ingreso
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Limpiar consola al iniciar
//    clearConsole();
//
//    printf("Simon dice - Secuencia de colores:\n");
//
//    // Crear un hilo para el temporizador
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Bucle principal para ingresar la secuencia
//    while (attempt_count < max_attempts && !timeout)
//    {
//        stop_timer = 0;  // Mantener el temporizador corriendo para toda la secuencia
//
//        // Mostrar el mensaje de ingreso en una linea fija
//        SetConsoleCursorPosition(hConsole, input_pos); // Posicion del mensaje de ingreso
//        printf("Ingresa un caracter (X, V, A, R, N o en minusculas): ");
//
//        // Bucle para esperar la entrada del usuario o el timeout
//        while (!timeout)
//        {
//            if (_kbhit())
//            { // Verifica si se ha presionado una tecla
//                ch = _getch(); // Lee el caracter sin esperar a Enter
//
//                // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//                {
//                    COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar secuencia ingresada
//                    SetConsoleCursorPosition(hConsole, char_pos); // Mueve el cursor para mostrar el caracter ingresado
//                    printf("Letra de secuencia ingresada: %c", ch); // Mostrar el caracter ingresado
//
//                    attempt_count++; // Incrementar el contador de intentos
//                    break;
//                }
//            }
//        }
//
//        // Si el tiempo se agoto
//        if (timeout == 1)
//        {
//            COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar el mensaje de tiempo agotado
//            SetConsoleCursorPosition(hConsole, char_pos);
//            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//            break; // Puedes finalizar el juego si el tiempo se agota
//        }
//
//        // Si se ingresaron todos los caracteres antes de que se acabe el tiempo
//        if (attempt_count == max_attempts)
//        {
//            stop_timer = 1; // Detener el temporizador
//            COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//            SetConsoleCursorPosition(hConsole, result_pos);
//            printf("Secuencia ingresada exitosamente!\n");
//            break; // Finaliza el bucle
//        }
//    }
//
//    // Espera a que el hilo del temporizador termine
//    pthread_join(tid, NULL);
//
//    if (timeout)
//    {
//        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//        SetConsoleCursorPosition(hConsole, result_pos);
//        printf("No completaste la secuencia. Se acabo el tiempo.\n");
//    }
//
//    return 0;
//}
///VERSION QUE CASI ES LO QUE NECESITO
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 10; // Tiempo total para la secuencia en segundos
//int stop_timer = 0;      // Variable para detener el temporizador
//HANDLE hConsole;         // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo);
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el proximo segundo
//
//            if (stop_timer) break;
//
//            // Mueve el cursor a la posicion del cronometro
//            COORD pos = {90, 0};  // Posiciona el temporizador en el margen derecho
//            SetConsoleCursorPosition(hConsole, pos);
//            printf("%d seg   ", remaining_time); // Asegurate de sobrescribir con espacios
//            fflush(stdout); // Asegura que se muestre inmediatamente
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//    int max_attempts = 5;  // Parametro ajustable: Numero de secuencias a ingresar
//    int attempt_count = 0; // Contador de intentos
//    COORD input_pos = {0, 2}; // Posicion inicial para los mensajes de ingreso
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Limpiar consola al iniciar
//    clearConsole();
//
//    printf("Simon dice - Secuencia de colores:\n");
//
//    // Crear un hilo para el temporizador
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Bucle principal para ingresar la secuencia
//    while (attempt_count < max_attempts && !timeout)
//    {
//        stop_timer = 0;  // Mantener el temporizador corriendo para toda la secuencia
//
//        // Mostrar el mensaje de ingreso en una linea fija
//        SetConsoleCursorPosition(hConsole, input_pos); // Posicion del mensaje de ingreso
//        printf("Ingresa un caracter (X, V, A, R, N o en minusculas): ");
//
//        // Bucle para esperar la entrada del usuario o el timeout
//        while (!timeout)
//        {
//            if (_kbhit())
//            { // Verifica si se ha presionado una tecla
//                ch = _getch(); // Lee el caracter sin esperar a Enter
//
//                // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//                {
//                    COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar secuencia ingresada
//                    SetConsoleCursorPosition(hConsole, char_pos); // Mueve el cursor para mostrar el caracter ingresado
//                    printf("Letra de secuencia ingresada: %c", ch); // Mostrar el caracter ingresado
//
//                    attempt_count++; // Incrementar el contador de intentos
//                    break;
//                }
//            }
//        }
//
//        // Si el tiempo se agoto
//        if (timeout == 1)
//        {
//            COORD char_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para mostrar el mensaje de tiempo agotado
//            SetConsoleCursorPosition(hConsole, char_pos);
//            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//            break; // Puedes finalizar el juego si el tiempo se agota
//        }
//    }
//
//    // Espera a que el hilo del temporizador termine
//    pthread_join(tid, NULL);
//
//    if (attempt_count == max_attempts)
//    {
//        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//        SetConsoleCursorPosition(hConsole, result_pos);
//        printf("Secuencia completada con exito!\n");
//    }
//    else if (timeout)
//    {
//        COORD result_pos = {0, input_pos.Y + attempt_count + 2}; // Posicion para el resultado final
//        SetConsoleCursorPosition(hConsole, result_pos);
//        printf("No completaste la secuencia. Se acabo el tiempo.\n");
//    }
//
//    return 0;
//}
///CASI
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 5; // Tiempo restante en segundos
//int stop_timer = 0;     // Variable para detener el temporizador
//HANDLE hConsole;        // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo);
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador utilizando alta precisión
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Mostrar inmediatamente el tiempo inicial (sin esperar)
//    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
//    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//    COORD pos;
//    pos.X = 90;  // Posiciona el temporizador en el margen derecho
//    pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//    SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//    printf("%d seg", remaining_time); // Muestra el tiempo inicial (5 segundos)
//    fflush(stdout); // Asegura que se muestre inmediatamente
//
//    // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//    SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el próximo segundo
//
//            // Si stop_timer está activado, no mostrar más el contador
//            if (stop_timer) break;
//
//            // Guardar la posicion actual del cursor
//            GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//            // Mueve el cursor al margen derecho sin interferir con la entrada
//            pos.X = 90;  // Posiciona el temporizador en el margen derecho
//            pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//            SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//            printf("%d seg", remaining_time);
//            fflush(stdout); // Asegura que se muestre inmediatamente
//
//            // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//            SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//    int max_attempts = 3; // Puedes cambiarlo para el número de letras a ingresar en la secuencia
//    int attempt_count = 0;
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    while (attempt_count < max_attempts)
//    {
//        timeout = 0;
//        stop_timer = 0;
//        remaining_time = 5; // Reiniciar el temporizador para cada letra
//
//        // Crear un hilo para el temporizador
//        pthread_create(&tid, NULL, timer_thread, NULL);
//
//        // Mensaje inicial en una linea separada
//        printf("Ingresa un caracter (X, V, A, R, N o en minusculas) antes de que se agote el tiempo: ");
//        fflush(stdout);
//
//        // Bucle para esperar la entrada del usuario o el timeout
//        while (!timeout && !stop_timer)
//        {
//            if (_kbhit())
//            { // Verifica si se ha presionado una tecla
//                ch = _getch(); // Lee el caracter sin esperar a Enter
//
//                // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//                if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                    ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//                {
//                    clearConsole(); // Limpiar la consola antes de mostrar el resultado
//                    printf("Ingresaste un caracter valido: %c\n", ch); // Mostrar solo el caracter valido
//                    stop_timer = 1; // Detener el temporizador
//                    attempt_count++; // Incrementar el contador de intentos
//                    break;
//                }
//            }
//        }
//
//        // Si el tiempo se agoto
//        if (timeout == 1)
//        {
//            clearConsole(); // Limpiar la consola cuando se agote el tiempo
//            printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//            break; // Puedes finalizar el juego si el tiempo se agota
//        }
//
//        // Espera a que el hilo del temporizador termine (limpieza)
//        pthread_join(tid, NULL);
//    }
//
//    if (attempt_count == max_attempts)
//    {
//        printf("Secuencia completada con exito!\n");
//    }
//    else
//    {
//        printf("No completaste la secuencia.\n");
//    }
//
//    return 0;
//}

///VERSION MEJORADA POR MI
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 5; // Tiempo restante en segundos
//int stop_timer = 0;     // Variable para detener el temporizador
//HANDLE hConsole;        // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo);
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador utilizando alta precisión
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Mostrar inmediatamente el tiempo inicial (sin esperar)
//    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
//    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//    COORD pos;
//    pos.X = 90;  // Posiciona el temporizador en el margen derecho
//    pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//    SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//    printf("%d seg", remaining_time); // Muestra el tiempo inicial (5 segundos)
//    fflush(stdout); // Asegura que se muestre inmediatamente
//
//    // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//    SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el próximo segundo
//
//            // Si stop_timer está activado, no mostrar más el contador
//            if (stop_timer) break;
//
//            // Guardar la posicion actual del cursor
//            GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//            // Mueve el cursor al margen derecho sin interferir con la entrada
//            pos.X = 90;  // Posiciona el temporizador en el margen derecho
//            pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//            SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//            printf("%d seg", remaining_time);
//            fflush(stdout); // Asegura que se muestre inmediatamente
//
//            // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//            SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
//    char ch;
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Crear un hilo para el temporizador
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Mensaje inicial en una linea separada
//    printf("Ingresa un caracter (X, V, A, R, N o en minusculas) antes de que se agote el tiempo: ");
//    fflush(stdout);
//
//    // Bucle para esperar la entrada del usuario o el timeout
//    while(!timeout && !stop_timer)
//    {
//        if(_kbhit())
//        { // Verifica si se ha presionado una tecla
//            ch = _getch(); // Lee el caracter sin esperar a Enter
//
//            // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//            if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//            {
//                clearConsole(); // Limpiar la consola antes de mostrar el resultado
//                printf("Ingresaste un caracter valido: %c\n", ch); // Mostrar solo el caracter valido
//                stop_timer = 1; // Detener el temporizador
//                break;
//            }
//        }
//    }
//
//    // Si el tiempo se agoto
//    if (timeout == 1)
//    {
//        clearConsole(); // Limpiar la consola cuando se agote el tiempo
//        printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//    }
//
//    // Espera a que el hilo del temporizador termine (limpieza)
//    pthread_join(tid, NULL);
//
//    return 0;
//}


///VERSION ORIGINAL
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>   // Para Sleep y funciones de Windows
//#include <conio.h>     // Para _kbhit() y _getch()
//#include <pthread.h>   // Biblioteca para hilos (threads)
//
//int timeout = 0;
//int remaining_time = 5; // Tiempo restante en segundos
//int stop_timer = 0;     // Variable para detener el temporizador
//HANDLE hConsole;        // Manejador de la consola para mover el cursor
//
//// Funcion para ocultar el cursor
//void hideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(hConsole, &cursorInfo);
//    cursorInfo.bVisible = FALSE; // Oculta el cursor
//    SetConsoleCursorInfo(hConsole, &cursorInfo);
//}
//
//// Funcion para limpiar la consola
//void clearConsole()
//{
//    COORD topLeft = {0, 0};
//    DWORD written;
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD length;
//    GetConsoleScreenBufferInfo(hConsole, &screen);
//    length = screen.dwSize.X * screen.dwSize.Y;
//    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}
//
//// Funcion para el hilo del temporizador utilizando alta precisión
//void* timer_thread(void* arg)
//{
//    LARGE_INTEGER frequency, start, end;
//    double elapsed_time = 0.0;
//    QueryPerformanceFrequency(&frequency); // Obtiene la frecuencia del contador
//    QueryPerformanceCounter(&start);       // Inicio del conteo
//
//    // Mostrar inmediatamente el tiempo inicial (sin esperar)
//    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
//    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//    COORD pos;
//    pos.X = 90;  // Posiciona el temporizador en el margen derecho
//    pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//    SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//    printf("%d seg", remaining_time); // Muestra el tiempo inicial (5 segundos)
//    fflush(stdout); // Asegura que se muestre inmediatamente
//
//    // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//    SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//
//    // Bucle del temporizador
//    while (remaining_time > 0 && !stop_timer)
//    {
//        QueryPerformanceCounter(&end);
//        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
//
//        if (elapsed_time >= 1.0) // Cada segundo
//        {
//            remaining_time--;
//            start = end; // Reiniciar el contador para el próximo segundo
//
//            // Si stop_timer está activado, no mostrar más el contador
//            if (stop_timer) break;
//
//            // Guardar la posicion actual del cursor
//            GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
//
//            // Mueve el cursor al margen derecho sin interferir con la entrada
//            pos.X = 90;  // Posiciona el temporizador en el margen derecho
//            pos.Y = 0;   // Mantiene el mensaje de entrada en la primera linea
//            SetConsoleCursorPosition(hConsole, pos); // Mueve el cursor a la posicion
//            printf("%d seg", remaining_time);
//            fflush(stdout); // Asegura que se muestre inmediatamente
//
//            // Restaurar la posicion del cursor donde el usuario estaba escribiendo
//            SetConsoleCursorPosition(hConsole, bufferInfo.dwCursorPosition);
//        }
//
//        Sleep(10); // Breve pausa para evitar uso intensivo de CPU
//    }
//
//    if (remaining_time == 0) // Si el tiempo se agota
//    {
//        timeout = 1; // Marca que el tiempo ha pasado
//    }
//
//    return NULL;
//}
//
//int main()
//{
//    pthread_t tid; // Identificador del hilo
/////    char input[100] = {0}; // Buffer para capturar la entrada
//    int index = 0; // Para contar cuantos caracteres se ingresaron
//
//    // Obtener el manejador de la consola
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Ocultar el cursor del temporizador
//    hideCursor();
//
//    // Crear un hilo para el temporizador
//    pthread_create(&tid, NULL, timer_thread, NULL);
//
//    // Mensaje inicial en una linea separada
//    printf("Ingresa un caracter (X, V, A, R, N o en minusculas) antes de que se agote el tiempo: ");
//    fflush(stdout);
//
//    // Bucle para esperar la entrada del usuario o el timeout
//    while (!timeout && !stop_timer)
//    {
//        if (_kbhit())
//        { // Verifica si se ha presionado una tecla
//            char ch = _getch(); // Lee el caracter sin esperar a Enter
//
//            // Verificar si el caracter es uno de los permitidos (mayusculas o minusculas)
//            if (ch == 'X' || ch == 'V' || ch == 'A' || ch == 'R' || ch == 'N' ||
//                ch == 'x' || ch == 'v' || ch == 'a' || ch == 'r' || ch == 'n')
//            {
/////                input[index++] = ch; // Almacena el caracter valido
//                clearConsole(); // Limpiar la consola antes de mostrar el resultado
//                printf("Ingresaste un caracter valido: %c\n", ch); // Mostrar solo el caracter valido
//                stop_timer = 1; // Detener el temporizador
//                break;
//            }
//            else if (ch == '\b')
//            { // Si se presiona Backspace
////                if (index > 0)
////                {
////                    printf("\b \b"); // Borra el ultimo caracter en pantalla
////                    index--; // Elimina el ultimo caracter
////                }
//            }
//        }
//    }
//
//    // Si el tiempo se agoto
//    if (timeout == 1)
//    {
//        clearConsole(); // Limpiar la consola cuando se agote el tiempo
//        printf("Tiempo agotado, no ingresaste un caracter valido.\n");
//    }
//
//    // Espera a que el hilo del temporizador termine (limpieza)
//    pthread_join(tid, NULL);
//
//    return 0;
//}
