#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() //Inicio programa principal
{

    char seguir='s';
    int opcion=0;
    float x, y;

    printf("**BIENVENIDO A CALCULADORA**");

    do //Inicio bucle principal
    {
        printf("\n\n*MENU*\n\n");
        printf("1- Calcular la suma\n");
        printf("2- Calcular la resta\n");
        printf("3- Calcular la division\n");
        printf("4- Calcular la multiplicacion\n");
        printf("5- Calcular el factorial\n");
        printf("6- Calcular todas las operacione\n");
        printf("7- Salir\n");
        printf("\nPor favor ingrese el numero de la operacion que desee realizar: ");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion) //Inicio interacion
        {
        case 1://Algoritmo de suma
            x = ingresoOperando("Ingresar 1er operando: ");
            y = ingresoOperando("Ingresar 2do operando: ");
            system("cls");
            printf("El resultado de la suma es: %.2f\n\n", suma(x, y));
            break;
        case 2://Algoritmo de resta
            x = ingresoOperando("Ingresar 1er operando: ");
            y = ingresoOperando("Ingresar 2do operando: ");
            system("cls");
            printf("El resultado de la resta es: %.2f\n\n", resta(x, y));
            break;
        case 3://Algoritmo de division
            x = ingresoOperando("Ingresar 1er operando: ");
            y = ingresoOperando("Ingresar 2do operando: ");
            system("cls");

            if (y == 0)
            {
                printf("\nError, no es posible dividir por 0\nPor favor realice otra operacion\n\n");
                break;
            }

            printf("El resultado de la division es: %.2f\n\n", division(x, y));
            break;
        case 4://Algoritmo de multiplicacion
            x = ingresoOperando("Ingresar 1er operando: ");
            y = ingresoOperando("Ingresar 2do operando: ");
            system("cls");
            printf("El resultado de la multiplicacion es: %.2f\n\n", producto(x, y));
            break;
        case 5://Algoritmo de de factorial
            x = ingresoOperando("Ingresar 1er operando: ");
            system("cls");
            printf("El resultado del factorial es: %.2f\n\n", factorial(x));
            break;
        case 6://Algoritmo de todas las operaciones
            x = ingresoOperando("Ingresar 1er operando: ");
            y = ingresoOperando("Ingresar 2do operando: ");
            system("cls");
            printf("El resultado de todas las operaciones son:\n\n");
            printf("Sumas: %.2f\n", suma(x, y));
            printf("Resta: %.2f\n", resta(x, y));


            if (y == 0)
            {
                printf("Division: Error, no es posible dividir por 0\n");
            }
            else
            {
                printf("Division: %.2f\n", division(x, y));
            }

            printf("Multiplicacion: %.2f\n", producto(x, y));
            printf("Factorial: %.2f\n\n", factorial(x));
            break;
        case 7://Algoritmo de salida interacion
            printf("Presione cualquier tecla para finalizar\n\n\n");
            seguir = 'n';
            break;
        }//Fin interacion
    }
    while(seguir=='s'); //Fin bucle principal
    return 0;
}//Final programa principal
