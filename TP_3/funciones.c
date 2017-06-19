#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#define INITIAL_LEN_MOVIES 2
#define INCREMENT_LEN_MOVIES 1

void loadMovies(EMovie* arrayMovies, FILE*pFile, int* countMovies)
{
    EMovie auxMovie;

    while(!feof(pFile))
    {
        if(fread(&auxMovie, sizeof(EMovie), 1, pFile) != 1)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("No se ha podido leer el ultimo registro.\n");
                break;
            }

        }
        else
        {
            *(arrayMovies+ *countMovies) = auxMovie;
            (*countMovies)++;
        }
    }
}

int addMovie(EMovie* arrayMovies, int* lenMovies, int* countMovies)
{
    EMovie auxMovie;
    int returnAux = 0;
    int flagArrayEnabled = 1;

    getString("Titulo: ", auxMovie.titulo);
    getString("Genero: ", auxMovie.genero);
    auxMovie.duracion = getInt("Duracion (en minutos): ");
    getString("Descripcion: ", auxMovie.descripcion);
    auxMovie.puntaje = getInt("Puntaje: ");
    getString("Link de la imagen: ", auxMovie.linkImagen);

    if(*lenMovies == *countMovies)
    {
        EMovie* auxArray;
        auxArray = (EMovie*) realloc(arrayMovies, sizeof(EMovie)* (*lenMovies + INCREMENT_LEN_MOVIES));
        if(auxArray != NULL)
        {
            arrayMovies = auxArray;
            *lenMovies = *lenMovies + INCREMENT_LEN_MOVIES;
        }
        else
        {
            flagArrayEnabled=0;
        }
    }

    if(flagArrayEnabled)
    {
        arrayMovies[*countMovies] = auxMovie;
        (*countMovies) = (*countMovies)+1;
        returnAux = 1;
    }

    return returnAux;
}

int removeMovie(EMovie* arrayMovies, int* countMovies)
{
    EMovie auxMovie;
    int returnAux = 0;
    int indexMovie = -1;

    getString("Ingrese el Titulo de la pelicula que desea ELIMINAR: ", auxMovie.titulo);
    for(int i=0; i<(*countMovies); i++)
    {
        if(strcmp(arrayMovies[i].titulo, auxMovie.titulo)==0)
        {
            indexMovie = i;
            break;
        }
    }

    if(indexMovie != -1)
    {
        if(indexMovie < (*countMovies - 1))
        {
            for(int i=indexMovie; i< (*countMovies - 1); i++)
            {
                arrayMovies[i] = arrayMovies[i+1];
            }
        }

        *countMovies = *countMovies - 1;
        returnAux = 1;
    }
    else
    {
        printf("\nNo se han encontrado peliculas con el titulo '%s'.\n\n", auxMovie.titulo);
    }


    return returnAux;
}

int modifyMovie(EMovie* arrayMovies, int* countMovies)
{
    EMovie auxMovie;
    int returnAux = 0;
    int indexMovie = -1;
    int option;
    char seguir = 's';

    getString("Ingrese el Titulo de la pelicula que desea MODIFICAR: ", auxMovie.titulo);
    for(int i=0; i<(*countMovies); i++)
    {
        if(strcmp(arrayMovies[i].titulo, auxMovie.titulo)==0)
        {
            indexMovie = i;
            break;
        }
    }

    if(indexMovie != -1)
    {
        auxMovie = arrayMovies[indexMovie];
        system("cls");
        while(seguir=='s')
        {
            printf("***\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n***\n", auxMovie.titulo, auxMovie.genero, auxMovie.duracion, auxMovie.descripcion, auxMovie.puntaje, auxMovie.linkImagen);
            option = getInt("\n\n¿Que desea modificar?\n\n1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Link de imagen\n\n");
            switch(option)
            {
            case 1:
                getString("\n\nNuevo titulo: ", auxMovie.titulo);
                break;
            case 2:
                getString("\n\nNuevo genero: ", auxMovie.genero);
                break;
            case 3:
                auxMovie.duracion = getInt("\n\nNueva duracion (en minutos): ");
                break;
            case 4:
                getString("\n\nNueva descripcion: ", auxMovie.descripcion);
                break;
            case 5:
                auxMovie.puntaje = getInt("\n\nNuevo puntaje: ");
                break;
            case 6:
                getString("\n\nNuevo link de la imagen: ", auxMovie.linkImagen);
                break;
            }
            system("cls");
            printf("***\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n***\n\n", auxMovie.titulo, auxMovie.genero, auxMovie.duracion, auxMovie.descripcion, auxMovie.puntaje, auxMovie.linkImagen);

            seguir = getChar("¿Desea realizar mas cambios en la pelicula?(s/n): ");
            system("cls");
        }

        arrayMovies[indexMovie] = auxMovie;
        returnAux = 1;
    }
    else
    {
        printf("\nNo se han encontrado peliculas con el titulo '%s'.\n\n", auxMovie.titulo);
    }


    return returnAux;
}

void makeHTML(EMovie* arrayMovies, int countMovies, char htmlName[]){
    char startHtml[] = "<!DOCTYPE html><html lang='en'><head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title> <link href='css/bootstrap.min.css' rel='stylesheet'> <link href='css/custom.css' rel='stylesheet'><!--[if lt IE 9]> <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script> <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body> <div class='container'> <div class='row'>";
    char endHtml[] = "</div></div><script src='js/jquery-1.11.3.min.js'></script> <script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";

    char article[1500];
    char startArticle[] = "<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='";
    char startTitle[] = "' alt=''> </a> <h3> <a href='#'>";
    char startGenere[] = "</a> </h3><ul><li>G&eacute;nero: ";
    char startScore[]= "</li><li>Puntaje: ";
    char startDuration[]= "</li><li>Duracion: ";
    char startDescription[]= "</li></ul> <p>";
    char endArticle[]= "</p></article>";

    char auxPuntaje [3];
    char auxDuracion [4];

    FILE* pHtml;
    pHtml = fopen(htmlName, "w");
    if(pHtml==NULL){
        printf("Error al generar pagina web.\n");
        exit(1);
    }

    fwrite(startHtml, sizeof(char), strlen(startHtml), pHtml);
    for(int i=0; i<countMovies; i++){
        sprintf(auxPuntaje, "%d", arrayMovies[i].puntaje);
        sprintf(auxDuracion, "%d", arrayMovies[i].duracion);

        strcpy(article, "");
        strcat(article, startArticle);
        strcat(article, &(arrayMovies[i].linkImagen));
        strcat(article, startTitle);
        strcat(article, &(arrayMovies[i].titulo));
        strcat(article, startGenere);
        strcat(article, &(arrayMovies[i].genero));
        strcat(article, startScore);
        strcat(article, auxPuntaje);
        strcat(article, startDuration);
        strcat(article, auxDuracion);
        strcat(article, startDescription);
        strcat(article, &(arrayMovies[i].descripcion));
        strcat(article, endArticle);

        fwrite(article, sizeof(char), strlen(article), pHtml);
    }

    fwrite(endHtml, sizeof(char), strlen(endHtml), pHtml);
    fclose(pHtml);
}
