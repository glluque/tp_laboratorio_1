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
    //int auxInt;
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
            printf("\nSistema Ordenado\n\n");
        }
    }

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
    printf("  DNI  Nombre   Sexo   \n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(vec[i].estado == 0)
        {
            //printf("%8d%30s%4d\n", vec[i].dni, vec[i].nombre, vec[i].edad);
            mostrarEmpleado(vec[i]);
        }
    }

    system("pause");
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("%8d%30s%4d\n", emp.dni, emp.nombre, emp.edad);
}

void graficarEmpleados(eEmpleado persona[], int tam)
{
    int i;
    int cont18 = 0;
    int cont19a35 = 0;
    int cont35 = 0;
    int flag=0;
    int mayor;


    for(i=0; i < tam; i++)
    {
        if(persona[i].estado == 1)
        {
            if(persona[i].edad < 19)
            {
                cont18++;
            }
            else
            {
                if(persona[i].edad > 18 && persona[i].edad < 36)
                {
                    cont19a35++;
                }
                else
                {
                    cont35++;
                }
            }
        }
    }

    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {
        if(cont19a35 >= cont18 && cont19a35 >= cont35)
        {
            mayor = cont19a35;
        }
        else
        {
            mayor = cont35;
        }
    }

    for(i=mayor; i>0; i--)
    {

        if(i <= cont18)
        {
            printf("*");
        }

        if(i <= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }

        printf("\n");
    }

    printf("<18\t19-35\t>35\n");
    system("pause");
}