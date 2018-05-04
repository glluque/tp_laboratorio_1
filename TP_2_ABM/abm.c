#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm.h"

int menu()
{
    int opcion;

    system("cls");
    printf("      ---ABM Empleados---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Ordenar\n");
    printf("4- Listar\n");
    printf("5- Graficar por edades\n");
    printf("6-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].estado =1;
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].estado == 0 && vec[i].dni == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tamEmp)
{

    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;
    char apellido[50];
    char nombre[25];

    system("cls");
    printf("---Alta empleado---\n\n");

    indice = buscarLibre(vec, tamEmp);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
        legajo = getValidInt("Ingrese DNI: ", "Error, DNI no valido. ", 1, 99999999);

        esta = buscarEmpleado(vec, tamEmp, legajo);

        if(esta != -1)
        {
            printf("\nEl DNI %d ya esta dado de alta en el sistema\n", legajo);
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            nuevoEmpleado.estado = 0;
            nuevoEmpleado.dni = legajo;

            getStringLetras("Ingrese nombre: ", nombre);
            getStringLetras("Ingrese apellido ", apellido);

            strlwr(nombre);
            nombre[0]=toupper(nombre[0]);

            strlwr(apellido);
            apellido[0]=toupper(apellido[0]);

            sprintf( nuevoEmpleado.nombre, "%s, %s", apellido, nombre);

            nuevoEmpleado.edad = getValidInt("Ingrese edad: ", "Error, edad no valida. ", 17, 120);

            vec[indice] = nuevoEmpleado;

            printf("\nAlta exitosa!!!\n\n");

        }
    }
    system("pause");
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Empleado---\n\n");


    legajo = getValidInt("Ingrese DNI: ", "Error, DNI no valido. ", 1, 99999999);

    esta = buscarEmpleado(vec, tam, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta]);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'|| confirma == 'S')
        {
            vec[esta].estado = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }

    system("pause");
}


void ordenarEmpleados(eEmpleado vec[], int tam)
{

    eEmpleado auxEmpleado;

    system("cls");

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].nombre, vec[j].nombre)>0)
            {
                auxEmpleado = vec[i];
                vec [i] = vec[j];
                vec [j] = auxEmpleado;
            }
            else if(strcmp(vec[i].nombre, vec[j].nombre) == 0)
            {

                if(vec[i].edad > vec[j].edad)
                {
                    auxEmpleado = vec[i];
                    vec [i] = vec[j];
                    vec [j] = auxEmpleado;
                }

            }
        }
    }

    printf("\nSistema Ordenado\n\n");
    system("pause");
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); //UNIX
    scanf("%c",&auxiliar);
    return auxiliar;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }

}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}



void mostrarEmpleados(eEmpleado vec[], int tamEmp)
{
    system("cls");
    printf("      ---Lista de Empleados---\n\n");
    printf("   DNI\t\tNombre\t\t  Edad   \n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(vec[i].estado == 0)
        {
            mostrarEmpleado(vec[i]);
        }
    }

    printf("\n\n");
    system("pause");
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("%8d%20s\t%3d\n", emp.dni, emp.nombre, emp.edad);
}

void graficarEmpleados(eEmpleado persona[], int tam)
{
    system("cls");

    int i, j, hasta18=0, de19a35=0, mayorDe35=0, bandera=0, mayor;

    for(j=0; j<tam; j++)
    {
        if(persona[j].edad<18 && persona[j].edad>0)
        {
            hasta18++;

        }
        else if(persona[j].edad>35)
        {
            mayorDe35++;
        }
        else if( persona[j].edad > hasta18)
        {
            de19a35++;
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    printf("\n\n");

    for(i=mayor; i>0; i--)
    {
        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            bandera=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(bandera==0)
                printf("\t\t*");
            if(bandera==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("-------------------");
    printf("\n  <18\t19-35\t>35");
    printf("\n\n");
    system("pause");
}
