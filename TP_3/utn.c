#ifndef UTN_C_INCLUDED
#define UTN_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"


#endif // UTN_C_INCLUDED

/**
*   \brief Pide un numero entero al usuario mediante un mensaje pasado por parametro y devuelve el numero
*   \param mensaje texto que se imprime por pantalla
*   \return numero ingresado por el usuario
*/
int getInt(char mensaje[]){
    int auxInt;

    printf("%s\t", mensaje);
    scanf("%d", &auxInt);

    return auxInt;
}

/**
*   \brief Pide un numero de tipo flotante al usuario mediante un mensaje pasado por parametro y devuelve el numero
*   \param mensaje texto que se imprime por pantalla
*   \return numero ingresado por el usuario
*/
float getFloat(char mensaje[]){
    int auxFloat;

    printf("%s\t", mensaje);
    scanf("%f", &auxFloat);

    return auxFloat;
}

/**
*   \brief Pide un caracter al usuario mediante un mensaje pasado por parametro y devuelve el caracter
*   \param mensaje texto que se imprime por pantalla
*   \return caracter ingresado por el usuario
*/
char getChar(char mensaje[]){
    int auxChar;

    printf("%s\t", mensaje);
    fflush(stdin);
    scanf("%c", &auxChar);

    return auxChar;
}

/**
*   \brief Pide el ingreso de texto al usuario mediante un mensaje pasado por parametro y lo guarda en un array de caracteres
*   \param mensaje texto que se imprime por pantalla
*   \param cadena array de caracteres donde se guarda el texto ingresado
*/
void getString(char mensaje[], char cadena[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(cadena);
}

/**
*   \brief Solicita un texto al usuario y lo guarda en un array de caracteres si está compuesto solo de letras
*   \param mensaje es el mensaje a ser mostrado
*   \param cadena array donde se cargará el texto ingresado
*   \return 1 si el texto es solo letras
*/
int getStringLetras(char mensaje[], char cadena[]){
    char aux [500];
    getString(mensaje, aux);

    if(!esSoloLetras(aux)){
        return 0;
    }

    strcpy(cadena, aux);
    return 1;
}

/**
*   \brief Solicita un texto al usuario y lo guarda en un array de caracteres si es alfanumerico
*   \param mensaje es el mensaje a ser mostrado
*   \param cadena array donde se cargará el texto ingresado
*   \return 1 si el texto es alfanumerico
*/
int getStringAlfanumerico(char mensaje[], char cadena[]){
    char aux [500];
    getString(mensaje, aux);

    if(!esAlfaNumerico(aux)){
        return 0;
    }

    strcpy(cadena, aux);
    return 1;
}

/**
*   \brief Solicita un numero y lo guarda en un array de caracteres si contiene solo numeros
*   \param mensaje es el mensaje a ser mostrado
*   \param cadena array donde se cargará el texto ingresado
*   \return 1 si el texto es numerico
*/
int getStringNumeros(char mensaje[], char cadena[]){
    char aux [500];
    getString(mensaje, aux);

    if(!esNumerico(aux)){
        return 0;
    }

    strcpy(cadena, aux);
    return 1;
}

/**
*   \brief Inicializa un array de enteros con un valor que se le pase
*   \param arrayInt array a cargar
*   \param largoArray cantidad de elementos del array
*   \param valor nuevo valor con el que se cargará el array
*/
void inicializarArray(int arrayInt[], int largoArray, int valor){
    for(int i =0; i<largoArray; i++){
        arrayInt[i] = valor;
    }
}

/**
*   \brief Recorre un array de enteros buscando un valor
*   \param arrayInt array a cargar
*   \param largoArray cantidad de elementos del array
*   \param valor valor que buscara
*   \return indice en el que se encuentra el valor o -1 si no está dentro del array
*/
int buscarPrimerCoincidencia(int arrayInt[], int largoArray, int valor){
    for(int i = 0; i<largoArray; i++){
        if(arrayInt[i]==valor){
            return i;
        }
    }
    return -1;
}

/*int getNumeroRandom(int desde, int hasta, int iniciar){

    if(iniciar){
        srand(time(NULL));
    }
    return desde + (rand() % (hasta + 1 - desde));
}*/

/**
*   \brief Valida si la cadena recibida es numerica
*   \param str texto a validar
*   \return 1 si es numerico
*/
int esNumerico(char str[]){
    int i = 0;

    while(str[i] != '\0'){
        if(str[i]<'0' || str[i]>'9'){
            return 0;
        }
        i++;
    }

    return 1;
}

/**
*   \brief Valida si la cadena recibida contiene solo letras
*   \param str texto a validar
*   \return 1 si contiene solo letras
*/
int esSoloLetras(char str[]){
    int i = 0;

    while(str[i]!='\0'){
        if(str[i]!=' ' && (str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z')){
            return 0;
        }
        i++;
    }

    return 1;
}

/**
*   \brief Valida si la cadena recibida es alfanumerica
*   \param str texto a validar
*   \return 1 si es alfanumerico
*/
int esAlfaNumerico(char str[]){
    int i=0;

    while(str[i]!='\0'){
        if(str[i]!=' ' && (str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && (str[i]<'0' || str[i]>'9')){
            return 0;
        }
        i++;
    }

    return 1;
}

/**
*   \brief Valida si la cadena recibida tiene formato de numero de telefono
*   \param str texto a validar
*   \return 1 si tiene formato de numero telefonico
*/
int esTelefono(char str[]){
    int i = 0;
    int contadorDeGuiones = 0;

    while(str[i]!='\0'){
        if(str[i]!= '-' && (str[i]<'0' || str[i]>'9')){
            return 0;
        }

        if(str[i]=='-'){
            contadorDeGuiones++;
        }

        i++;
    }

    if(contadorDeGuiones==1){
        return 1;
    }

    return 0;
}
