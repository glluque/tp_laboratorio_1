#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#define TAM 20

/*
*
* Trabajo practico N°2 de Laboratorio 1 UTN FRA
*
* Objetivo: AMB, Usuario puede dar de alta y baja nombres, apellidos y numero de DNI.
* Devuelve un tabla con los datos y un grafico con las edades.
*
*
* Guillermo Luque
* DNI 33911859
*
*/

int main()
{
    int salir = 0;

    ePersona newPersona[TAM];

    inicializarPersona(newPersona, TAM);

    do
    {

        switch(menu())
        {
        case 1:
            altaPersona(newPersona, TAM);
            break;
        case 2:
            bajaPersona(newPersona, TAM);
            break;
        case 3:
            ordenarPersona(newPersona, TAM);
            break;
        case 4:
            mostrarPersonas(newPersona, TAM);
            break;
        case 5:
            graficarPersona(newPersona, TAM);
            break;
        case 6:
            salir = 1;
            printf("\n\n**Saliendo del programa**\nPresione cualquier tecla para finalizar.\n\n");
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }while(salir != 1);

    return 0;
}
