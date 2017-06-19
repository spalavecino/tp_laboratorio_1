#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define ARCH "./peliculas.dat"
#define HTML_NAME "index.html"
#define INITIAL_LEN_MOVIES 4
#define INCREMENT_LEN_MOVIES 2

int main()
{
    char seguir='s';
    int opcion=0, lenMovies, countMovies = 0, countMoviesInFile;
    FILE* pFile;
    EMovie movie;
    EMovie* arrayMovies;

    //Abrimos el archivo como lectura para no sobreescribirlo, si no existe lo creamos.
    pFile = fopen(ARCH, "r+b");
    if(pFile==NULL){
        pFile = fopen(ARCH, "w+b");
        if(pFile==NULL){
            printf("Error al intentar abrir el archivo.");
            exit(1);
        }
        arrayMovies = (EMovie*) malloc(sizeof(EMovie)* INITIAL_LEN_MOVIES);
        lenMovies = INITIAL_LEN_MOVIES;
    }else{
        //Vemos cuantos registros hay cargados en el archivo, leyendo el primer registro que es un int que lo indica
        if(!feof(pFile)){
            fread(&countMoviesInFile, sizeof(int), 1, pFile);
            arrayMovies = (EMovie*) malloc(sizeof(EMovie)* (countMoviesInFile+INCREMENT_LEN_MOVIES));
            lenMovies = countMoviesInFile+INCREMENT_LEN_MOVIES;
            fseek(pFile, sizeof(int), SEEK_SET);
            loadMovies(arrayMovies, pFile, &countMovies);
        }else{
            arrayMovies = (EMovie*) malloc(sizeof(EMovie)* INITIAL_LEN_MOVIES);
            lenMovies = INITIAL_LEN_MOVIES;
        }
    }
    fclose(pFile);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Guardar cambios y salir\n\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("\n***NUEVA PELICULA***\n\n");
                if(addMovie(arrayMovies, &lenMovies, &countMovies)){
                    printf("\n\n¡PELICULA AGREGADA CON EXITO!\n\n");
                }
                break;
            case 2:
                if(countMovies==0){
                    printf("No se encuentran peliculas cargadas.\n\n");
                    break;
                }

                if(removeMovie(arrayMovies, &countMovies)){
                    printf("\n¡PELICULA BORRADA CON EXITO!\n\n");
                }
                break;
            case 3:
                if(countMovies==0){
                    printf("No se encuentran peliculas cargadas.\n\n");
                    break;
                }
                printf("\n***MODIFICAR PELICULA***\n\n");
                if(modifyMovie(arrayMovies, &countMovies)){
                    printf("\n\n¡PELICULA MODIFICADA CON EXITO!\n\n");
                }

               break;
            case 4:
                if(countMovies==0){
                    printf("No se encuentran peliculas cargadas.\n\n");
                    break;
                }
                makeHTML(arrayMovies, countMovies, HTML_NAME);
                printf("\n\n¡PAGINA WEB GENERADA CON EXITO!\n\n");
                break;
            case 5:
                pFile = fopen(ARCH, "wb");
                fwrite(&countMovies, sizeof(int),1, pFile);
                fseek(pFile, sizeof(int), SEEK_SET);
                for(int i=0; i<countMovies; i++){
                    fwrite(arrayMovies+i, sizeof(EMovie), 1, pFile);
                }
                fclose(pFile);

                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
