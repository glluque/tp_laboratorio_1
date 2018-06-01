#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
*
* Trabajo practico N°3 de Laboratorio 1 UTN FRA
*
* Crear una función que reciba un array de estructuras movie y el nombre del archivo html de
* salida, y se encargue de generarlo.
*
*
*
* Fecha de entrega Viernes 01 de Junio del 2018
*
* Guillermo Luque
* DNI 33911859
*
*/


int main()
{
    char menu='s';
    int option=0;

    eMovie movie;
    FILE *movieEstructuraFile;
    FILE *movieFileHtml;

    movieEstructuraFile = fopen("movieBin.dat","rb+");
    movieFileHtml = fopen("movieFileHtml.html","r+");

    esArchivo(movieEstructuraFile, movieFileHtml);

    while(menu=='s')
    {

        switch(menuLista())
        {
            case 1:
                altaMovie(movie, movieEstructuraFile, movieFileHtml);
                break;
            case 2:
                borraMovie(movie, movieEstructuraFile);
                break;
            case 3:
                modificaMovie(movie, movieEstructuraFile);
                break;
            case 4:
                creaHtml(movie, movieEstructuraFile, movieFileHtml);
                break;
            case 5:
                menu = 'n';
                printf("\n\n**Saliendo del programa**\nPresione cualquier tecla para finalizar.\n\n");
                break;
        }
    }

    return 0;
}
