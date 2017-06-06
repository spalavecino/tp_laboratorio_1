#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarPersonas(EPersona personas[], int len, int valor){
    for(int i = 0; i<len; i++){
        personas[i].estado = valor;
    }
}

int getInt(char mensaje[]){
    int auxInt;

    printf("%s\t", mensaje);
    scanf("%d", &auxInt);

    return auxInt;
}

/**
*   \brief recibe un texto que imprime y devuelve numero ingresado por usuario
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
*   \brief recibe un texto que imprime y devuelve caracter ingresado por usuario
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
*   \brief recibe un texto que imprime y devuelve texto ingresada por usuario
*   \param mensaje texto que se imprime por pantalla
*   \param cadena array de caracteres donde se guarda el texto ingresado
*/
void getString(char mensaje[], char cadena[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(cadena);
}

/**
*   \brief Solicita un texto al usuario y lo devuelve
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
*   \brief valida si la cadena recibida es numerica
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
*   \brief valida si la cadena recibida contiene solo letras
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

int obtenerEspacioLibre(EPersona lista[], int len){
    for(int i = 0; i<len; i++){
        if(!lista[i].estado){
            return i;
        }
    }
    return -1;
}

int buscarPorDni(EPersona lista[], int dni, int len){
    for(int i = 0; i<len; i++){
        if(lista[i].dni == dni){
            return i;
        }
    }

    return -1;
}

int arrayPersonasVacio(EPersona personas[], int len){
    for(int i = 0; i<len; i++){
        if(personas[i].estado){
            return 0;
        }
    }
    return 1;
}

void ordenarPersonasPorNombre(EPersona personas[], int len){
    EPersona auxPersona;

    for(int i = 0; i<(len-1); i++){
        for(int j = i; j<len; j++){
            if(strcmp(personas[i].nombre, personas[j].nombre)>0){
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }
}

void imprimirPersonas(EPersona personas[], int len){
    for(int i = 0; i<len; i++){
        if(personas[i].estado){
            printf("%s - %d - %d\n", personas[i].nombre, personas[i].dni, personas[i].edad);
        }
    }
}

void imprimirGraficoEdades(EPersona personas[], int len){
    int menores18 = 0, entre18y35 = 0, mayores35 = 0;
    int auxMax;

    for(int i = 0; i<len; i++){
        if(personas[i].estado){
            if(personas[i].edad<18){
                menores18++;
            }else if(personas[i].edad <= 35){
                entre18y35++;
            }else{
                mayores35++;
            }
        }
    }

    if(menores18>=entre18y35 && menores18>= mayores35){
        auxMax = menores18;
    }else if(entre18y35>=menores18 && entre18y35>=mayores35){
        auxMax = entre18y35;
    }else{
        auxMax = mayores35;
    }

    for(int i = auxMax; i>0; i--){
        if(menores18>=i){
            printf(" * \t");
        }else{
            printf("   \t");
        }

        if(entre18y35>=i){
            printf(" * \t");
        }else{
            printf("   \t");
        }

        if(mayores35>=i){
            printf(" * ");
        }

        printf("\n");
    }

    printf("<18\t19-35\t>35\n\n");
}
#endif // FUNCIONES_C_INCLUDED
