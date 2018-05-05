#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm.h"

int menu()
{
    int opcion;

    system("cls");
    printf("      ---ABM Personas---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Ordenar por apellidos\n");
    printf("4- Listar\n");
    printf("5- Graficar por edades\n");
    printf("6- Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarPersona(ePersona vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].estado = 1;
        vec[i].edad = 0;
    }
}

int buscarLibre(ePersona vec[], int tam)
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

int buscarPersona(ePersona vec[], int tam, int dni)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].estado == 0 && vec[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaPersona(ePersona vec[], int tam)
{

    ePersona nuevaPersona
    ;
    int indice;
    int esta;
    int dni;
    char apellido[50];
    char nombre[25];

    system("cls");
    printf("---Alta persona---\n\n");

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a personas nuevas.\n\n");
    }
    else
    {
        dni = getValidInt("Ingrese DNI: ", "Error, DNI no valido. ", 1, 99999999);

        esta = buscarPersona(vec, tam, dni);

        if(esta != -1)
        {
            printf("\nEl DNI %d ya esta dado de alta en el sistema\n\n", dni);
            printf("   DNI\t\tNombre\t\t  Edad   \n\n");
            mostrarPersona(vec[esta]);
        }
        else
        {
            nuevaPersona.estado = 0;
            nuevaPersona.dni = dni;

            getStringLetras("Ingrese nombre: ", nombre);
            getStringLetras("Ingrese apellido: ", apellido);

            strlwr(nombre);
            nombre[0]=toupper(nombre[0]);

            strlwr(apellido);
            apellido[0]=toupper(apellido[0]);

            sprintf( nuevaPersona.nombre, "%s, %s", apellido, nombre);

            nuevaPersona.edad = getValidInt("Ingrese edad: ", "Error, edad no valida. ", 17, 120);

            vec[indice] = nuevaPersona;

            printf("\nAlta exitosa!!!\n\n");

        }
    }
    system("pause");
}

void bajaPersona(ePersona vec[], int tam)
{
    int dni;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Persona---\n\n");


    dni = getValidInt("Ingrese DNI: ", "Error, DNI no valido. ", 1, 99999999);

    esta = buscarPersona(vec, tam, dni);

    if(esta == -1)
    {
        printf("\nEl dni %d no se encuentra en el sistema\n\n", dni);

    }
    else
    {

        printf("\n\n   DNI\t\tNombre\t\t  Edad   \n\n");
        mostrarPersona(vec[esta]);

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


void ordenarPersona(ePersona vec[], int tam)
{

    ePersona auxPers;

    system("cls");

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].nombre, vec[j].nombre)>0)
            {
                auxPers = vec[i];
                vec [i] = vec[j];
                vec [j] = auxPers;
            }
            else if(strcmp(vec[i].nombre, vec[j].nombre) == 0)
            {

                if(vec[i].edad > vec[j].edad)
                {
                    auxPers = vec[i];
                    vec [i] = vec[j];
                    vec [j] = auxPers;
                }

            }
        }
    }

    system("cls");
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



void mostrarPersonas(ePersona vec[], int tam)
{
    system("cls");
    printf("      ---Lista de Empleados---\n\n");
    printf("   DNI\t\tNombre\t\t   Edad   \n\n");
    for(int i=0; i< tam; i++)
    {
        if(vec[i].estado == 0)
        {
            mostrarPersona(vec[i]);
        }
    }

    printf("\n\n");
    system("pause");
}

void mostrarPersona(ePersona per)
{
    printf("%8d%20s\t%3d\n", per.dni, per.nombre, per.edad);
}

void graficarPersona(ePersona lista[], int tam)
{
    system("cls");

    int i, j, hasta18=0, de19a35=0, mayorDe35=0, bandera=0, mayor;

    for(j=0; j<tam; j++)
    {
        if(lista[j].edad<18 && lista[j].edad>0)
        {
            hasta18++;

        }
        else if(lista[j].edad>35)
        {
            mayorDe35++;
        }
        else if( lista[j].edad > hasta18)
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

    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

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
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35\n\n");
    system("pause");

}
