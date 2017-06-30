#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT_P 20

int main()
{
    EPersona personas [CANT_P];
    char seguir='s';
    char auxNombre [30], auxDni [10], auxEdad [4];
    int opcion=0, indice;

    inicializarPersonas(personas, CANT_P, 0);

    while(seguir=='s')
    {
        printf("*** MENU ***\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n\n");

        scanf("%d",&opcion);

        system("cls");
        switch(opcion)
        {
            case 1:
                printf("INGRESO\n\n");
                indice = obtenerEspacioLibre(personas, CANT_P);
                if(indice == -1){
                    printf("\nNO HAY LUGAR PARA NUEVOS INGRESOS\n\n");
                    break;
                }

                if(!getStringLetras("Ingresar nombre: ", auxNombre)){
                    printf("\nEL NOMBRE DEBE CONTENER SOLO LETRAS\n\n");
                    break;
                }


                if(!getStringNumeros("Ingresar dni: ", auxDni)){
                    printf("\nEL DNI DEBE CONTENER SOLO NUMEROS\n\n");
                    break;
                }

                if(!getStringNumeros("Ingresar edad: ", auxEdad)){
                    printf("\nLA EDAD DEBE CONTENER SOLO NUMEROS\n\n");
                    break;
                }

                strcpy(personas[indice].nombre, auxNombre);
                personas[indice].edad = atoi(auxEdad);
                personas[indice].dni = atoi(auxDni);
                personas[indice].estado = 1;

                printf("\nINGRESO EXITOSO.\n\n");
                break;
            case 2:
                printf("BORRAR\n\n");
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("\nNO HAY PERSONAS INGRESADAS\n\n");
                    break;
                }

                if(!getStringNumeros("Ingrese dni de la persona a borrar: ", auxDni)){
                    printf("\nEL DNI DEBE CONTENER NUMEROS SOLAMENTE\n\n");
                    break;
                }

                indice = buscarPorDni(personas, atoi(auxDni), CANT_P);
                if(indice == -1 || !personas[indice].estado){
                    printf("\nNO EXISTE PERSONA INGRESADA CON ESTE DNI.\n\n");
                    break;
                }

                personas[indice].estado = 0;
                printf("\nBAJA EXITOSA.\n\n");
                break;
            case 3:
                printf("IMPRIMIR PERSONAS\n\n");
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("\nNO HAY PERSONAS INGRESADAS\n\n");
                    break;
                }

                printf("\n*************************\n");
                printf("\NOMBRE - DNI - EDAD\n");
                printf("*************************\n\n");

                ordenarPersonasPorNombre(personas, CANT_P);
                imprimirPersonas(personas, CANT_P);
                break;
            case 4:
                printf("IMPRIMIR GRAFICO DE EDADES\n\n");
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("\nNO HAY PERSONAS INGRESADAS\n\n");
                    break;
                }

                printf("\nGRAFICOS POR EDADES\n\n");
                imprimirGraficoEdades(personas, CANT_P);
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
