#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int primerOperando, primerOperandoCargado = 0, segundoOperando, segundoOperandoCargado = 0,
        resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoFactorial, opcion=0;
    float resultadoDivision;

    while(seguir=='s')
    {
        if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
            printf("1- Ingresar 1er operando (A=%d)\n", primerOperando);
            printf("2- Ingresar 2do operando (B=%d)\n", segundoOperando);
            printf("3- Calcular la suma (%d+%d)\n", primerOperando, segundoOperando);
            printf("4- Calcular la resta (%d-%d)\n", primerOperando, segundoOperando);
            printf("5- Calcular la division (%d/%d)\n", primerOperando, segundoOperando);
            printf("6- Calcular la multiplicacion (%d*%d)\n", primerOperando, segundoOperando);
            printf("7- Calcular el factorial (%d!)\n", primerOperando);

        }else if(primerOperandoCargado != 0 && segundoOperandoCargado == 0){
            printf("1- Ingresar 1er operando (A=%d)\n", primerOperando);
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (%d+B)\n", primerOperando);
            printf("4- Calcular la resta (%d-B)\n", primerOperando);
            printf("5- Calcular la division (%d/B)\n", primerOperando);
            printf("6- Calcular la multiplicacion (%d*B)\n", primerOperando);
            printf("7- Calcular el factorial (%d!)\n", primerOperando);
        }else if(primerOperandoCargado == 0 && segundoOperandoCargado != 0){
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=%d)\n", segundoOperando);
            printf("3- Calcular la suma (A+%d)\n", segundoOperando);
            printf("4- Calcular la resta (A-%d)\n", segundoOperando);
            printf("5- Calcular la division (A/%d)\n", segundoOperando);
            printf("6- Calcular la multiplicacion (A*%d)\n", segundoOperando);
            printf("7- Calcular el factorial (A!)\n");
        }else{
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
        }

        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando: \n\n");
                scanf("%d", &primerOperando);
                primerOperandoCargado = 1;

                system("cls");
                break;
            case 2:
                printf("Ingrese el 2do operando: \n\n");
                scanf("%d", &segundoOperando);
                segundoOperandoCargado = 1;

                system("cls");
                break;
            case 3:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    resultadoSuma = sumar(primerOperando, segundoOperando);
                    printf("%d + %d = %d\n\n", primerOperando, segundoOperando, resultadoSuma);

                    primerOperandoCargado  = 0;
                    segundoOperandoCargado = 0;

                }else{
                    printf("Debe ingresar ambos operandos antes para poder realizar la suma.\n\n");
                }

                system("pause");
                system("cls");

                break;
            case 4:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    resultadoResta = restar(primerOperando, segundoOperando);
                    printf("%d - %d = %d\n\n", primerOperando, segundoOperando, resultadoResta);
                    primerOperandoCargado = 0;
                    segundoOperandoCargado = 0;
                }else{
                    printf("Debe ingresar ambos operandos antes para poder realizar la resta.\n\n");
                }

                system("pause");
                system("cls");

                break;
            case 5:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    if(segundoOperando == 0){
                        printf("ERROR MATEMATICO. No se puede dividir por \"0\" \(cero \).\n\n");
                    }else{
                        resultadoDivision = dividir(primerOperando, segundoOperando);
                        printf("%d / %d = %f\n\n", primerOperando, segundoOperando, resultadoDivision);
                        primerOperandoCargado = 0;
                        segundoOperandoCargado = 0;
                    }
                }else{
                    printf("Debe ingresar ambos operandos antes para poder realizar la división.\n\n");
                }

                system("pause");
                system("cls");

                break;
            case 6:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    resultadoMultiplicacion = multiplicar(primerOperando, segundoOperando);
                    printf("%d x %d = %d\n\n", primerOperando, segundoOperando, resultadoMultiplicacion);
                    primerOperandoCargado = 0;
                    segundoOperandoCargado = 0;
                }else{
                    printf("Debe ingresar ambos operandos antes para poder realizar la multiplicación.\n\n");
                }

                system("pause");
                system("cls");
                break;
            case 7:
                if(primerOperandoCargado != 0){
                    resultadoFactorial = factorial(primerOperando);
                    printf("%d! = %d\n", primerOperando, resultadoFactorial);
                    primerOperandoCargado = 0;
                    segundoOperandoCargado = 0;
                }else{
                    printf("Debe ingresar el primer operando para poder calcular su factorial.\n\n");
                }

                system("pause");
                system("cls");
                break;
            case 8:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    printf("%d + %d = %d\n", sumar(primerOperando, segundoOperando));
                    printf("%d - %d = %d\n", restar(primerOperando, segundoOperando));
                    printf("%d / %d = %f\n", dividir(primerOperando, segundoOperando));
                    printf("%d x %d = %d\n", multiplicar(primerOperando, segundoOperando));
                    printf("%d! = %d\n", factorial(primerOperando));
                    primerOperando = 0;
                    segundoOperando = 0;
                }else{
                    printf("Para realizar todas las operaciones debe ingresar ambos operandos previamente.\n\n");
                }

                system("pause");
                system("cls");
                break
                ;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("La opcion ingresada no es valida. Por favor, intentelo nuevamente.\n\n");
                system("pause");
                system("cls");
            }
        }
    return 0;
}
