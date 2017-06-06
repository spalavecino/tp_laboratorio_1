#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Inicializa un array de personas asignandole a su estado el valor que se le pase.
 * @param personas el array se pasa como parametro.
 * @param len largo del array
 * @param valor nuevo valor para el estado de cada persona
 * @return el primer indice disponible
 */
void inicializarPersonas(EPersona personas[], int len, int valor);

/**
*   Recibe un texto que imprime y asigna texto ingresada por usuario a la cadena que se le pase
*   @param mensaje texto que se imprime por pantalla
*   @param cadena array de caracteres donde se guarda el texto ingresado
*/
void getString(char mensaje[], char cadena[]);

/**
*   Solicita un texto al usuario y valida que sean solo letras
*   @param mensaje es el mensaje a ser mostrado
*   @param cadena array donde se cargará el texto ingresado
*   @return 1 si el texto es solo letras
*/
int getStringLetras(char mensaje[], char cadena[]);

/**
*   Solicita un texto al usuario y valida que sean solo numeros
*   @param mensaje es el mensaje a ser mostrado
*   @param cadena array donde se cargará el texto ingresado
*   @return 1 si el texto es solo letras
*/
int getStringNumeros(char mensaje[], char cadena[]);

/**
*   Valida si la cadena recibida es numerica
*   @param str texto a validar
*   @return 1 si es numerico
*/
int esNumerico(char str[]);

/**
*   Valida si la cadena recibida contiene solo letras
*   @param str texto a validar
*   @return 1 si contiene solo letras
*/
int esSoloLetras(char str[]);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param len largo del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param len largo del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int len);

/**
 * Dice si el array no contiene alguna persona de estado '1'
 * @param personas el array se pasa como parametro.
 * @param len largo del array.
 * @return 1 si el array esta vacio, de caso contrario devuelve 0
 */
int arrayPersonasVacio(EPersona personas[], int len);

/**
 * Ordena el array de personas por nombre
 * @param personas el array se pasa como parametro.
 * @param len largo del array.
 */
void ordenarPersonasPorNombre(EPersona personas[], int len);

/**
 * Imprime cada persona del array (nombre, edad y dni)
 * @param personas el array se pasa como parametro.
 * @param len largo del array.
 */
void imprimirPersonas(EPersona personas[], int len);

/**
 * Imprime grafico de edades de las personas del array
 * @param personas el array se pasa como parametro.
 * @param len largo del array.
 */
void imprimirGraficoEdades(EPersona personas[], int len);
#endif // FUNCIONES_H_INCLUDED
