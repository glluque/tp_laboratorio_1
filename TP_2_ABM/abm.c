#include <stdio.h>
#include <stdlib.h>
#include "abm.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].isEmpty =1;
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
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
        if(vec[i].isEmpty == 0 && vec[i].legajo == legajo)
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
    int auxInt;
    char auxSting[50];
    char auxString2[25];

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
        /*printf("Ingrese DNI: ");
        scanf("%d", &legajo);*/

        esta = buscarEmpleado(vec, tamEmp, legajo);

        if(esta != -1)
        {
            printf("\nEl DNI %d ya esta dado de alta en el sistema\n", legajo);
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.dni = legajo;

            getStringLetras("Ingrese nombre: ", auxString2);
            getStringLetras("Ingrese apellido ", auxSting);

            strcpy(nuevoEmpleado.nombre, nombreCompleto(auxString2, auxSting));
            /*printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);*/

            nuevoEmpleado.edad = getValidInt("Ingrese edad: ", "Error, edad no valida. ", 17, 120);

            vec[indice] = nuevoEmpleado;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Empleado---\n\n");


    legajo = getValidInt("Ingrese DNI: ", "Error, DNI no valido. ", 1, 99999999);
    /*printf("Ingrese legajo: ");
    scanf("%d", &legajo);*/

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

        if(confirma == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}


void ordenarEmpleados(eEmpleado vec[], int tam)
{

    eEmpleado auxEmpleado;
    char auxString[50];

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(auxEmpleado.nombre[i], auxEmpleado.nombre[j])>0)
            {
                strcpy(auxString, auxEmpleado.nombre[i]);
                strcpy(auxEmpleado.nombre[i], auxEmpleado.nombre[j]);
                strcpy(auxEmpleado.nombre[j], auxString);

            }
    }
    printf("\nSistema Ordenado\n\n");
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

char nombreCompleto (char nombre[], char apellido[])
{
    char apeNom[50]; //suma los char con la coma y el espacio

    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);

    strlwr(apellido);
    apellido[0]=toupper(apellido[0]);

    strcpy(apeNom, apellido);
    strcat(apeNom, ", ");
    strcat(apeNom, nombre);

    return apeNom;
}
