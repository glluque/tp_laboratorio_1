#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#define TAM 3

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
    char seguir='s';

    ePersona equipo[TAM];

    inicializarArrar(equipo, TAM);

    do
    {

        switch(menu())
        {
        case 1:
            //system("cls");
            altaPersona(equipo, TAM);
            break;
        case 2:
            bajarPersona(equipo, TAM);
            break;
        case 3:
            mostrarPersonas(equipo, TAM);
            break;
        case 4:
            graficarPersonas(equipo, TAM);
            break;
        case 5:
            seguir = 'n';
            printf("\n\n**Saliendo del programa**\nPresione cualquier tecla para finalizar.\n\n");
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
