#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;
/**
 *  Carga las peliculas en un array dinamico
 *  @param arrayMovies array dinamico de peliculas donde se cargaran las mismas
 *  @param pFile puntero al archivo
 *  @param countMovies cantidad de peliculas cargadas hasta el momento
 */
void loadMovies(EMovie* arrayMovies, FILE*pFile, int* countMovies);

/**
 *  Agrega una pelicula al array de peliculas
 *  @param arrayMovies array dinamico de peliculas
 *  @param lenMovies cantidad de peliculas que soporta el array actualmente
 *  @param countMovies peliculas cargadas en el array
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMovie(EMovie* arrayMovies, int* lenMovies, int* countMovies);

/**
 *  Borra una pelicula del array de peliculas
 *  @param arrayMovies array dinamico de peliculas
 *  @param countMovies puntero a cantidad de peliculas cargadas en el array
 *  @return retorna 1 o 0 de acuerdo a si pudo borrar la pelicula o no
 */
int removeMovie(EMovie* arrayMovies, int* countMovies);

/**
 *  Modifica una pelicula del array de peliculas
 *  @param arrayMovies array dinamico de peliculas
 *  @param countMovies puntero a cantidad de peliculas cargadas en el array
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modifyMovie(EMovie* arrayMovies, int* countMovies);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param arrayMovies la lista de peliculas a ser agregadas en el archivo.
 *  @param countMovies puntero a cantidad de peliculas cargadas en el array.
 *  @param htmlName el nombre para el archivo.
 */
void makeHTML(EMovie* arrayMovies, int countMovies, char htmlName[]);

#endif // FUNCIONES_H_INCLUDED
