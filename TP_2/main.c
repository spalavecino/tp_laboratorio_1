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
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");
        switch(opcion)
        {
            case 1:
                printf("INGRESO\n\n");
                indice = obtenerEspacioLibre(personas, CANT_P);
                if(indice == -1){
                    printf("NO HAY LUGAR PARA NUEVOS INGRESOS\n");
                    break;
                }

                if(!getStringLetras("Ingresar nombre: ", auxNombre)){
                    printf("EL NOMBRE DEBE CONTENER SOLO LETRAS\n");
                    break;
                }


                if(!getStringNumeros("Ingresar dni: ", auxDni)){
                    printf("EL DNI DEBE CONTENER SOLO NUMEROS\n");
                    break;
                }

                if(!getStringNumeros("Ingresar edad: ", auxEdad)){
                    printf("LA EDAD DEBE CONTENER SOLO NUMEROS\n");
                    break;
                }

                strcpy(personas[indice].nombre, auxNombre);
                personas[indice].edad = atoi(auxEdad);
                personas[indice].dni = atoi(auxDni);
                personas[indice].estado = 1;

                printf("INGRESO EXITOSO.\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("BORRAR\n\n");
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("NO HAY PERSONAS INGRESADAS\n");
                    break;
                }

                if(!getStringNumeros("Ingrese dni de la persona a borrar: ", auxDni)){
                    printf("EL DNI DEBE CONTENER NUMEROS SOLAMENTE\n");
                    break;
                }

                indice = buscarPorDni(personas, atoi(auxDni), CANT_P);
                if(indice == -1 || !personas[indice].estado){
                    printf("NO EXISTE PERSONA INGRESADA CON ESTE DNI.\n");
                    break;
                }

                personas[indice].estado = 0;
                printf("BAJA EXITOSA.\n");
                system("pause");
                system("cls");
                break;
            case 3:
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("NO HAY PERSONAS INGRESADAS\n");
                    break;
                }

                printf("\n*************************\n");
                printf("\NOMBRE - DNI - EDAD\n");
                printf("*************************\n\n");

                ordenarPersonasPorNombre(personas, CANT_P);
                imprimirPersonas(personas, CANT_P);
                system("pause");
                system("cls");
                break;
            case 4:
                if(arrayPersonasVacio(personas, CANT_P)){
                    printf("NO HAY PERSONAS INGRESADAS\n");
                    break;
                }

                printf("GRAFICOS POR EDADES\n\n");
                imprimirGraficoEdades(personas, CANT_P);
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
