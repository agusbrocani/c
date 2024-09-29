#include "reproductorConListaCircular.h"

void crearArchivoBinarioDeTemas()
{
    FILE* pf;
    tListaDeTemas temas[CE_TEMAS] =
    {
        {"Queen", "Bohemian Rhapsody", 355},
        {"Michael Jackson", "Thriller", 358},
        {"The Beatles", "Hey Jude", 431},
        {"Led Zeppelin", "Stairway to Heaven", 482},
        {"Mozart", "Requiem", 556},
        {"Beethoven", "Symphony No. 9", 1254},
        {"Pink Floyd", "Comfortably Numb", 383},
        {"The Rolling Stones", "Paint It Black", 236},
        {"David Bowie", "Heroes", 373},
        {"Prince", "Purple Rain", 508},
        {"Nirvana", "Smells Like Teen Spirit", 301},
        {"U2", "With or Without You", 296},
        {"The Eagles", "Hotel California", 390},
        {"Bob Dylan", "Like a Rolling Stone", 370},
        {"Whitney Houston", "I Will Always Love You", 273},
        {"The Police", "Every Breath You Take", 258},
        {"Nino Bravo", "Libre", 252},
        {"Bruce Springsteen", "Born to Run", 278},
        {"Elvis Presley", "Suspicious Minds", 265},
        {"Madonna", "Like a Prayer", 342},
        {"The Beach Boys", "Good Vibrations", 216},
        {"Fleetwood Mac", "Go Your Own Way", 225},
        {"Simon & Garfunkel", "Bridge Over Troubled Water", 296},
        {"The Who", "Baba O'Riley", 302},
        {"Bob Marley", "No Woman, No Cry", 430},
        {"ABBA", "Dancing Queen", 232},
        {"Stevie Wonder", "Superstition", 244},
        {"Guns N' Roses", "Sweet Child O' Mine", 356},
        {"Tina Turner", "What's Love Got to Do with It", 231},
        {"Adele", "Rolling in the Deep", 228},
        {"Coldplay", "Fix You", 269},
        {"Celine Dion", "My Heart Will Go On", 282},
        {"Johnny Cash", "Hurt", 215},
        {"Radiohead", "Creep", 238},
        {"The Clash", "London Calling", 220},
        {"The Doors", "Light My Fire", 427},
        {"Frank Sinatra", "My Way", 275},
        {"R.E.M.", "Losing My Religion", 249},
        {"Queen", "We Will Rock You", 122},
        {"Michael Jackson", "Billie Jean", 294},
        {"Elton John", "Rocket Man", 271},
        {"Journey", "Don't Stop Believin'", 251},
        {"Amy Winehouse", "Back to Black", 230},
        {"Rihanna", "Umbrella", 252},
        {"The Weeknd", "Blinding Lights", 200},
        {"Eminem", "Lose Yourself", 326},
        {"Drake", "Hotline Bling", 267},
        {"Billie Eilish", "Bad Guy", 194},
        {"Queen", "Another One Bites the Dust", 217},
        {"The Beatles", "Let It Be", 243},
        {"Metallica", "Enter Sandman", 331},
        {"Oasis", "Wonderwall", 258},
        {"Katy Perry", "Firework", 221},
        {"Taylor Swift", "Shake It Off", 242},
        {"Ariana Grande", "Thank U, Next", 207},
        {"Ed Sheeran", "Shape of You", 234},
        {"Post Malone", "Circles", 215},
        {"Lady Gaga", "Bad Romance", 294},
        {"Shakira", "Hips Don't Lie", 218},
        {"Beyonce", "Halo", 261},
        {"Bruno Mars", "Uptown Funk", 270},
        {"Justin Bieber", "Sorry", 200},
        {"Daft Punk", "Get Lucky", 248},
        {"The Chainsmokers", "Closer", 244},
        {"Maroon 5", "Sugar", 235},
        {"Dua Lipa", "Levitating", 203},
        {"Imagine Dragons", "Believer", 204},
        {"Sia", "Chandelier", 216},
        {"Shawn Mendes", "Stitches", 207},
        {"Sam Smith", "Stay With Me", 171},
        {"The Weeknd", "Starboy", 230},
        {"Queen", "Somebody to Love", 295},
        {"Toto", "Africa", 294},
        {"Luis Fonsi", "Despacito", 229},
        {"The Beatles", "Come Together", 259},
        {"Eagles", "Take It Easy", 205},
        {"The Rolling Stones", "Gimme Shelter", 272},
        {"The Beach Boys", "Wouldn't It Be Nice", 224},
        {"BTS", "Dynamite", 199},
        {"Kanye West", "Stronger", 311},
        {"Coldplay", "Viva La Vida", 242},
        {"Kendrick Lamar", "HUMBLE.", 177},
        {"Lana Del Rey", "Summertime Sadness", 271},
        {"Adele", "Hello", 295},
        {"Beyonce", "Single Ladies", 193},
        {"Rihanna", "Diamonds", 226},
        {"Harry Styles", "Watermelon Sugar", 173},
        {"Justin Timberlake", "Can't Stop the Feeling!", 236},
        {"Marvin Gaye", "What's Going On", 233},
        {"Stevie Wonder", "Isn't She Lovely", 198},
        {"Paul McCartney", "Maybe I'm Amazed", 276},
        {"Bob Dylan", "Blowin' in the Wind", 182},
        {"Aretha Franklin", "Respect", 152},
        {"John Lennon", "Imagine", 187},
        {"Queen", "Radio Ga Ga", 354},
        {"Michael Jackson", "Man in the Mirror", 321},
        {"Mozart", "Eine kleine Nachtmusik", 509}
    };

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO_BINARIO_LISTA_DE_TEMAS, "wb"))
    {
        return;
    }

    fwrite(&temas, sizeof(temas), 1, pf);

    fclose(pf);
}

void mostrarTema(const void* dato)
{
    printf("Autor: %s\nTema: %s\nDuracion: %u\n",
           ((tListaDeTemas*)dato)->autor,
           ((tListaDeTemas*)dato)->tema,
           ((tListaDeTemas*)dato)->duracion
           );
}

int comparaTemasSegunAutor(const void* a, const void* b)
{
    int cmp;

    cmp = strcmpi(((tListaDeTemas*)a)->autor, ((tListaDeTemas*)b)->autor);
    if(!cmp)
    {
        cmp = strcmpi(((tListaDeTemas*)a)->tema, ((tListaDeTemas*)b)->tema);
        if(!cmp)
        {
            return ((tListaDeTemas*)a)->duracion - ((tListaDeTemas*)b)->duracion;
        }
    }

    return cmp;
}

int comparaTemasSegunNombreTema(const void* a, const void* b)
{
    int cmp;

    cmp = strcmpi(((tListaDeTemas*)a)->tema, ((tListaDeTemas*)b)->tema);
    if(!cmp)
    {
        cmp = strcmpi(((tListaDeTemas*)a)->autor, ((tListaDeTemas*)b)->autor);
        if(!cmp)
        {
            return ((tListaDeTemas*)a)->duracion - ((tListaDeTemas*)b)->duracion;
        }
    }

    return cmp;
}

int comparaTemasSegunDuracion(const void* a, const void* b)
{
    int cmp;

    cmp = ((tListaDeTemas*)a)->duracion - ((tListaDeTemas*)b)->duracion;
    if(!cmp)
    {
        cmp = strcmpi(((tListaDeTemas*)a)->autor, ((tListaDeTemas*)b)->autor);
        if(!cmp)
        {
            return strcmpi(((tListaDeTemas*)a)->tema, ((tListaDeTemas*)b)->tema);
        }
    }

    return cmp;
}

void switchSubMenuListaSimpleOrdenadaSegunCriterio(int opcion, void* estructuraTDA)
{
    rewind(((tRecursosMenu*)estructuraTDA)->aListaDeTemas);
    switch(opcion)
    {
        case INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_AUTOR:
            if(listaSimpleVacia(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas))
            {
                insertarArchivoBinarioEnListaSimple(((tRecursosMenu*)estructuraTDA)->aListaDeTemas, &((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas,&(((tRecursosMenu*)estructuraTDA)->tema), sizeof(tListaDeTemas), comparaTemasSegunAutor);
                printf("Lista Simple insertada en orden segun Autor:\n\n");
                mostrarListaSimpleEnOrden(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, mostrarTema);
            }
            else
            {
                printf("La lista ya ha sido cargada previamente, vacie la Lista Simple de Temas e intente nuevamente si desea volver a insertar.\n");
            }
        break;
        case INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_TEMA:
            if(listaSimpleVacia(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas))
            {
                insertarArchivoBinarioEnListaSimple(((tRecursosMenu*)estructuraTDA)->aListaDeTemas, &((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas,&(((tRecursosMenu*)estructuraTDA)->tema), sizeof(tListaDeTemas), comparaTemasSegunNombreTema);
                printf("Lista Simple insertada en orden segun Tema:\n\n");
                mostrarListaSimpleEnOrden(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, mostrarTema);
            }
            else
            {
                printf("La lista ya ha sido cargada previamente, vacie la Lista Simple de Temas e intente nuevamente si desea volver a insertar.\n");
            }
        break;
        case INSERTAR_ORDENADO_LISTA_SIMPLE_DE_TEMAS_SEGUN_DURACION:
            if(listaSimpleVacia(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas))
            {
                insertarArchivoBinarioEnListaSimple(((tRecursosMenu*)estructuraTDA)->aListaDeTemas, &((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas,&(((tRecursosMenu*)estructuraTDA)->tema), sizeof(tListaDeTemas), comparaTemasSegunDuracion);
                printf("Lista Simple insertada en orden segun Duracion:\n\n");
                mostrarListaSimpleEnOrden(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, mostrarTema);
            }
            else
            {
                printf("La lista ya ha sido cargada previamente, vacie la Lista Simple de Temas e intente nuevamente si desea volver a insertar.\n");
            }
        break;
        case VACIAR_LISTA_SIMPLE_DE_TEMAS:
            printf("Vaciando Lista Simple de Temas.\n");
            vaciarListaSimple(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas);
        break;
    }
}

void crearListaSimpleOrdenadaSegunCriterio(void* estructuraTDA)
{
    char textoSubMenuListaSimpleOrdenadaSegunCriterio[][MAX_TAM_TEXTO] =
    {
      "Menu:",
      "[0]Salida",
      "[1]Insertar ordenado segun Autor.",
      "[2]Insertar ordenado segun Tema.",
      "[3]Insertar ordenado segun Duracion.",
      "[4]Vaciar Lista Simple de Temas."
    };
    unsigned cantidadDeRegistros = sizeof(textoSubMenuListaSimpleOrdenadaSegunCriterio) / MAX_TAM_TEXTO;

    menu(textoSubMenuListaSimpleOrdenadaSegunCriterio, cantidadDeRegistros, switchSubMenuListaSimpleOrdenadaSegunCriterio, estructuraTDA, DESACTIVAR_AYUDA_AL_USUARIO);
}

void cargarListaSimpleEnListaCircular(void* estructuraTDA)
{
    while(sacarPrimeroEnListaSimple(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, &((tRecursosMenu*)estructuraTDA)->tema, sizeof(tListaDeTemas)))
    {
        insertarSegundoEnListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas, &((tRecursosMenu*)estructuraTDA)->tema, sizeof(tListaDeTemas));
    }
}

void switchSubMenuCrearPlaylistCircular(int opcion, void* estructuraTDA)
{
    switch(opcion)
    {
        case INSERTAR_LISTA_CIRCULAR_DE_TEMAS:
            if(listaSimpleVacia(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas))
            {
                printf("No puede insertar en Lista Circular de Temas, primero debe insertar temas en Lista Simple de Temas.\n");
            }
            else
            {
                printf("Se cargo exitosamente Lista Simple de Temas en Lista Circular de Temas - Lista Simple de Temas vacia.\n");
                cargarListaSimpleEnListaCircular(estructuraTDA);
            }
        break;
        case CAMBIAR_DE_LUGAR_LISTA_CIRCULAR_DE_TEMAS:
            if(listaCircularVacia(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas))
            {
                printf("No puede cambiar de lugar en Lista Circular de Temas, primero debe insertar temas en Lista Circular de Temas.\n");
            }
            else
            {
                printf("Cambiando Nodos de lugar en Lista Circular de Temas.\n");
                cambiarNodosDeLugarEnListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas);
            }
        break;
        case ELIMINAR_TEMA_LISTA_CIRCULAR_DE_TEMAS:
            if(listaCircularVacia(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas))
            {
                printf("Lista Circular de Temas vacia.\n");
            }
            else
            {
                sacarSiguienteDelPrimeroListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas, &((tRecursosMenu*)estructuraTDA)->tema, sizeof(tListaDeTemas));
                printf("Tema sacado de Lista Circular de Temas.\n");
                mostrarTema(&((tRecursosMenu*)estructuraTDA)->tema);
            }
        break;
        case VACIAR_LISTA_CIRCULAR_DE_TEMAS:
            if(listaCircularVacia(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas))
            {
                printf("Lista Circular de Temas vacia.\n");
            }
            else
            {
                printf("Vaciando Lista Circular de Temas.\n");
                vaciarListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas);
            }
        break;
    }
}

void crearPlaylistCircular(void* estructuraTDA)
{
    char textoSubMenuCrearPlaylistCircular[][MAX_TAM_TEXTO] =
    {
      "Menu:",
      "[0]Salida",
      "[1]Agregar Tema a Lista Circular de Temas.",
      "[2]Cambiar Tema de lugar en Lista Circular de Temas.",
      "[3]Eliminar Tema de Lista Circular de Temas.",
      "[4]Vaciar Lista Circular de Temas.",
    };
    unsigned cantidadDeRegistros = sizeof(textoSubMenuCrearPlaylistCircular) / MAX_TAM_TEXTO;

    menu(textoSubMenuCrearPlaylistCircular, cantidadDeRegistros, switchSubMenuCrearPlaylistCircular, estructuraTDA, DESACTIVAR_AYUDA_AL_USUARIO);
}

void grabarListaCircularDeTemasEnArchivoDeTexto(void* estructuraTDA)
{
    FILE* archivoTxtPlaylist;
    char nombreArchivoTxtPlaylist[TAM_NOMBRE_ARCHIVO_TXT_PLAYLIST];

    sprintf(nombreArchivoTxtPlaylist, "PLAY-%u.txt", ((tRecursosMenu*)estructuraTDA)->cantidadDePlaylistGrabadasEnArchivo);

    if(!abrirArchivo(&archivoTxtPlaylist, nombreArchivoTxtPlaylist, "wt"))
    {
        return;
    }

    while(sacarSiguienteDelPrimeroListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas, &((tRecursosMenu*)estructuraTDA)->tema, sizeof(tListaDeTemas)))
    {
        fprintf(archivoTxtPlaylist, "Autor: %s\nTema: %s\nDuracion: %u\n\n",
            ((tRecursosMenu*)estructuraTDA)->tema.autor,
            ((tRecursosMenu*)estructuraTDA)->tema.tema,
            ((tRecursosMenu*)estructuraTDA)->tema.duracion
        );
    }

    ((tRecursosMenu*)estructuraTDA)->cantidadDePlaylistGrabadasEnArchivo++;

    fclose(archivoTxtPlaylist);
}

void switchMenuPrincipal(int opcion, void* estructuraTDA)
{
    rewind(((tRecursosMenu*)estructuraTDA)->aListaDeTemas);
    switch(opcion)
    {
        case CREAR_LISTA_SIMPLE_DE_TEMAS_ORDENADA_SEGUN_CRITERIO:
            crearListaSimpleOrdenadaSegunCriterio(estructuraTDA);
        break;
        case MEZCLAR_LISTA_SIMPLE_DE_TEMAS:
            if(listaSimpleVacia(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas))
            {
                printf("No se pudo mezclar, Lista Simple de Temas vacia.\n");
            }
            else
            {
                printf("Mezclando Lista Simple de Temas:\n");
                mezclarListaSimpleAleatoriamente(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, CE_TEMAS);
                mostrarListaSimpleEnOrden(&((tRecursosMenu*)estructuraTDA)->listaSimpleDeTemas, mostrarTema);
            }
        break;
        case CREAR_PLAYLIST_CIRCULAR:
            crearPlaylistCircular(estructuraTDA);
        break;
        case REPRODUCIR_PLAYLIST_CIRCULAR:
            if(listaCircularVacia(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas))
            {
                printf("No hay temas para reproducir, Lista Circular de Temas vacia.\n");
            }
            else
            {
                mostrarListaCircular(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas, mostrarTema);
            }
        break;
        case GUARDAR_PLAYLIST_CIRCULAR_EN_ARCHIVO_DE_TEXTO:
            if(listaCircularVacia(&((tRecursosMenu*)estructuraTDA)->listaCircularDeTemas))
            {
                printf("No hay temas para grabar en archivo de texto, Lista Circular de Temas vacia.\n");
            }
            else
            {
                printf("Se ha grabado exitosamente la playlist en el archivo PLAY-%u.txt - Lista Circular Vacia.\n", ((tRecursosMenu*)estructuraTDA)->cantidadDePlaylistGrabadasEnArchivo);
                grabarListaCircularDeTemasEnArchivoDeTexto(estructuraTDA);
            }
        break;
    }
}
