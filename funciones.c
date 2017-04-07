#include "funciones.h"

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
            resultado =  multiplicar(resultado, i - 1);
        }

        return resultado;
    }
}
