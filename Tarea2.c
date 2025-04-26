#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos struct Song con punteros
typedef struct {
    char *song_id;
    char *song_title;
    char *artist;
    char *album;
    char *genre;
    char *release_date;
    float duration; //Ver para verlo en int si pide en seguntos
    int popularity;
    long stream;
    char *language;
    char *explicit_content;
    char *label;
    char *composer;
    char *producer;
    char *collaboration;
} Song;

Song* ListaCanciones(FILE *archivo,int *cantidad){
    //Codigo para leer el archivo y llenar la lista de canciones
    char Temporal[4096];
    fgets(Temporal,sizeof(Temporal),archivo);

    //ListaInterna variable, el 100 lo cambio despues es para porbar las primeras 100 canciones
    Song *ListaInterna = malloc(sizeof(Song)*100);

    //Verificar errores
    if (fgets(Temporal,sizeof(Temporal),archivo)==NULL){
        printf("Error al leer el archivo\n");
        //Luego vemos como ver el error
        return NULL; 
    }
    else{
        /*printf("La Cancion numero 1 es: %s\n",buffer);
        era para ver si funcionaba coomo queria el codgio*/

        //Ir llenando la lista
        
        /*Sorry si comento mucho pero quiero aprender de tokens entonces voy haciendolo
        de manera bien comentada para no perderme*/


        while (fgets(Temporal,sizeof(Temporal),archivo)!=NULL){

        Song *Cancion = &ListaInterna[*cantidad];
        //Genera token
        char *ContenidoCelda;
        //Seaparador
        char *SeparadorDeCelda=",";

        //Para escribir la pimrera Cancion luego lo cambio

        //Separa la linea y la guarda en la variable
        ContenidoCelda=strtok(Temporal,SeparadorDeCelda);
        int Categoria=0;

            while (ContenidoCelda != NULL) {
                /*Poir otro lado quiero tambien entender a usar la función switch entonces tambien lo voy a dejar bien comentado
                en resumen switch es un if con esteroides para que no quede tan feo (puede servir en el menú)*/

                //Para agregar el '\0' ponemos un +1
                int TamanoCelda=strlen(ContenidoCelda)+1;
                switch (Categoria){
                    //Song_id
                    case 0:
                        //Uso -> por que es un struct de punteros Song entnces uso eso en vez de Song.algo es mas abreviado que (*Song).algo

                        Cancion->song_id = malloc(TamanoCelda);
                        //Copia el contenido de la celda a la la variable simple y bonito
                        strcpy(Cancion->song_id,ContenidoCelda);
                        break;
                    
                    //Song_title
                    case 1:
                        Cancion->song_title = malloc(TamanoCelda);
                        strcpy(Cancion->song_title,ContenidoCelda);
                        break;

                    //Artist
                    case 2:
                        Cancion->artist = malloc(TamanoCelda);
                        strcpy(Cancion->artist,ContenidoCelda);
                        break;

                    //Album
                    case 3:
                        Cancion->album = malloc(TamanoCelda);
                        strcpy(Cancion->album,ContenidoCelda);
                        break;

                    //Genre
                    case 4:
                        Cancion->genre = malloc(TamanoCelda);
                        strcpy(Cancion->genre,ContenidoCelda);
                        break;

                    //Release_date
                    case 5:
                        Cancion->release_date = malloc(TamanoCelda);
                        strcpy(Cancion->release_date,ContenidoCelda);
                        break;

                    //Duration
                    case 6:
                        //Es más simple por que necesitamos un numero no texto
    //VER SI SE PUEDE HACER CON UN INT =================================================================================================== TAL VEZ SEA MEJOR
                        Cancion->duration = atof(ContenidoCelda);
                        break;

                    //Popularity
                    case 7:
                        Cancion->popularity = atoi(ContenidoCelda);
                        break;

                    //Stream
                    case 8:
                        Cancion->stream = atol(ContenidoCelda);
                        break;
                    
                    //Language
                    case 9:
                        Cancion->language = malloc(TamanoCelda);
                        strcpy(Cancion->language,ContenidoCelda);
                        break;

                    //Explicit_content
                    case 10:
                        Cancion->explicit_content = malloc(TamanoCelda);
                        strcpy(Cancion->explicit_content,ContenidoCelda);
                        break;

                    //Label
                    case 11:
                        Cancion->label = malloc(TamanoCelda);
                        strcpy(Cancion->label,ContenidoCelda);
                        break;

                    //Composer
                    case 12:
                        Cancion->composer = malloc(TamanoCelda);
                        strcpy(Cancion->composer,ContenidoCelda);
                        break;

                    //Producer
                    case 13:
                        Cancion->producer = malloc(TamanoCelda);
                        strcpy(Cancion->producer,ContenidoCelda);
                        break;

                    //Collaboration
                    case 14:
                        Cancion->collaboration = malloc(TamanoCelda);
                        strcpy(Cancion->collaboration,ContenidoCelda);
                        break;

                    //¿Otro caso? Musica fantasma?
                    default:
                        printf("Aparecio un fantasma en la cancion");
                        break;  
                }
                //Contador y para cerrar el whhile
                ContenidoCelda = strtok(NULL, SeparadorDeCelda);
                Categoria++;
            }
            (*cantidad)++;
            //Aumenta la cantidad de canciones
        }
    }


    //Para ver si
    //*cantidad = 1;
    //Devuelve la ListaInterna
    return ListaInterna;
}


int main(int argc,char *argv[])
{
    FILE *archivo; 
    if (argc<2){
        //Verifica que este nombre del archivo
        printf("Error, no nombraste el archivo, ej:\n./programa archivo.txt\n");
        return 1;
    }
        else{
        //Todo bien :)
    }
    archivo=fopen(argv[1],"r");
        //Abre el archivo correcto
    if (archivo==NULL){
        printf("Puede que no hayas ingresado el archivo\n");
        return 1;
    }
        else{
        //Todo bien x2 :)
    }

    //Para ver si funciona con esto vez la cantidad de canciones
    int cantidad=0;

    //&cantidad es para que modifique el valor de cantidad
    Song *Lista = ListaCanciones(archivo, &cantidad);
    printf("Se cargaron %d canciones\n", cantidad);
    fclose(archivo);

    for (int i = 0; i < cantidad; i++) {
        printf("Canción %d:\n", i+1);
        printf("ID: %s\n", Lista[i].song_id);
        printf("Título: %s\n", Lista[i].song_title);
        printf("Artista: %s\n", Lista[i].artist);
        printf("Álbum: %s\n", Lista[i].album);
        printf("Género: %s\n", Lista[i].genre);
        printf("Fecha de Lanzamiento: %s\n", Lista[i].release_date);
        printf("Duración: %.2f segundos\n", Lista[i].duration);
        printf("Popularidad: %d\n", Lista[i].popularity);
        printf("Streams: %ld\n", Lista[i].stream);
        printf("Idioma: %s\n", Lista[i].language);
        printf("Contenido explícito: %s\n", Lista[i].explicit_content);
        printf("Sello: %s\n", Lista[i].label);
        printf("Compositor: %s\n", Lista[i].composer);
        printf("Productor: %s\n", Lista[i].producer);
        printf("Colaboración: %s\n", Lista[i].collaboration);
        printf("----------------------------------------\n");
    }
    

    for (int i = 0; i < cantidad; i++) {
        free(Lista[i].song_id);
        free(Lista[i].song_title);
        free(Lista[i].artist);
        free(Lista[i].album);
        free(Lista[i].genre);
        free(Lista[i].release_date);
        free(Lista[i].language);
        free(Lista[i].explicit_content);
        free(Lista[i].label);
        free(Lista[i].composer);
        free(Lista[i].producer);
        free(Lista[i].collaboration);
    }
    // Finalmente liberar la lista completa
    free(Lista);
    
    //Test de lectura de arcvhio
    printf("Se cargaron %d canciones\n", cantidad);
 
    return 0;
}
