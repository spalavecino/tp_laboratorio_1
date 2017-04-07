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
            printf("3- Calcular la suma (%d+y)\n", primerOperando);
            printf("4- Calcular la resta (%d-y)\n", primerOperando);
            printf("5- Calcular la division (%d/y)\n", primerOperando);
            printf("6- Calcular la multiplicacion (%d*y)\n", primerOperando);
            printf("7- Calcular el factorial (%d!)\n", primerOperando);
        }else{
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (x+y)\n");
            printf("4- Calcular la resta (x-y)\n");
            printf("5- Calcular la division (x/y)\n");
            printf("6- Calcular la multiplicacion (x*y)\n");
            printf("7- Calcular el factorial (x!)\n");
        }

        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando: \n");
                scanf("%d", &primerOperando);
                primerOperandoCargado = 1;
                break;
            case 2:
                printf("Ingrese el 2do operando: \n");
                scanf("%d", &segundoOperando);
                segundoOperandoCargado = 1;
                break;
            case 3:
                if(primerOperandoCargado != 0 && segundoOperandoCargado != 0){
                    resultadoSuma = sumar(primerOperando, segundoOperando);
                    printf("%d + %d = %d\n", primerOperando, segundoOperando, resultadoSuma);

                    primerOperandoCargado  = 0;
                    segundoOperandoCargado = 0;
                }else{
                    prinf("Debe ingresar ambos operandos antes para poder realizar la suma.")
                }

                break;
            case 4:
                resultadoResta = restar(primerOperando, segundoOperando);
                printf("%d - %d = %d\n", primerOperando, segundoOperando, resultadoResta);
                primerOperandoCargado = 0;
                segundoOperandoCargado = 0;
                break;
            case 5:
                resultadoDivision = dividir(primerOperando, segundoOperando);
                printf("%d / %d = %f\n", primerOperando, segundoOperando, resultadoDivision);
                primerOperandoCargado = 0;
                segundoOperandoCargado = 0;
                break;
            case 6:
                resultadoMultiplicacion = multiplicar(primerOperando, segundoOperando);
                printf("%d x %d = %d\n", primerOperando, segundoOperando, resultadoMultiplicacion);
                primerOperandoCargado = 0;
                segundoOperandoCargado = 0;
                break;
            case 7:
                resultadoFactorial = factorial(primerOperando);
                printf("%d! = %d\n", primerOperando, resultadoFactorial);
                primerOperando = 0;
                segundoOperando = 0;
                break;
            case 8:
                break
                ;
            case 9:
                seguir = 'n';
                break;
        }

        }
    return 0;
}

int sumar(int numeroA, int numeroB){
    return numeroA + numeroB;
}

int restar(int numeroA, int numeroB){
    return numeroA - numeroB;
}

float dividir(int numeroA, int numeroB){
    return numeroA / numeroB;
}

int multiplicar(int numeroA, int numeroB){
    return numeroA * numeroB;
}

int factorial(int numero){

    if(numero == 0 || numero == 1){
        return 1;
    }else{
        int i, resultado = numero;

        for(i = numero; i > 1; i--){
            resultado = resultado * (i - 1);
        }

        return resultado;
    }
}
