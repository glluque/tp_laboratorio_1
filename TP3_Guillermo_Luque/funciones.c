#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

/**
 * \brief Se pasan 2 punteros a FILE y una estructura eMovie. Permite agregar una pelicula escribiendo el archivo binario con los datos cargados
 * \param eMovie movie Estructura
 * \param FILE *movieEstructuraFile Puntero a file binario
 * \param FILE *movieFileHtml Puntero a file texto
 * \return -
 *
 */
void altaMovie(eMovie movie, FILE *movieEstructuraFile,FILE *movieFileHtml)
{

    movieEstructuraFile = fopen("movieBin.dat","rb+");

    char tituloAux[75],generoAux[75],descripcionAux[200];
    float floatAux, floatAuxDuracion;

    system("cls");

    printf("ALTA PELICULA\n");

    printf("\nIngrese el titulo: ");
    fflush(stdin);
    gets(tituloAux);
    strcpy(movie.titulo,tituloAux);

    getValidString("\nIngrese el genero: ","Solo es permitido el uso de letras, reingrese", generoAux);
    fflush(stdin);
    strcpy(movie.genero,generoAux);

    printf("\nIngrese la descripcion:");
    gets(descripcionAux);
    strcpy(movie.descripcion,descripcionAux);

    floatAux = getValidFloat("\nIngrese el puntaje: ","Solo son permitidos numeros",1,10);
    fflush(stdin);
    movie.puntaje = floatAux;

    floatAuxDuracion = getValidFloat("\nIngrese la duracion: ","Solo son permitidos numeros",1,500);
    fflush(stdin);
    movie.duracion=floatAuxDuracion;

    printf("\nIngrese el link de la imagen de la pelicula: ");
    fflush(stdin);
    gets(movie.linkImagen);

    fseek(movieEstructuraFile, 0L, SEEK_END);
    fwrite(&movie, sizeof(eMovie), 1, movieEstructuraFile);

    fclose(movieEstructuraFile);

    system("cls");

    printf("\nIngreso exitoso\n");

    system("pause");

}

/**
 * \brief Se pasa 1 puntero a FILE y una estructura eMovie. Permite eliminar una pelicula sobreescribiendo con un espacio vacio
 * \param eMovie movie Estructura
 * \param FILE *movieEstructuraFile Puntero a file binario
 * \return -
 *
 */
void borraMovie(eMovie movie, FILE *movieEstructuraFile)
{
    movieEstructuraFile = fopen("movieBin.dat","rb+");

    char tituloAux[21];
    int Aux, borraPuntajeDuracion=0;

    system("cls");

    printf("BORRAR PELICULA\n");


    printf("\nIngrese el titulo de la pelicula a borrar: ");
    fflush(stdin);
    gets(tituloAux);

    rewind(movieEstructuraFile);

    while(!feof(movieEstructuraFile))
    {
        fread(&movie, sizeof(eMovie), 1, movieEstructuraFile);

        if(strcmpi(tituloAux, movie.titulo) == 0)
        {
            strcpy(movie.titulo, "\0");
            strcpy(movie.descripcion, "\0");
            strcpy(movie.genero, "\0");
            strcpy(movie.linkImagen, "\0");
            movie.puntaje = borraPuntajeDuracion;
            movie.duracion = borraPuntajeDuracion;

            fseek(movieEstructuraFile,(-1)*sizeof(eMovie), SEEK_CUR);
            Aux=fwrite(&movie, sizeof(eMovie), 1, movieEstructuraFile);

            if(Aux < 1)
            {
                printf("ERROR al eliminar pelicula");
            }

            else
            {
                printf("\nPelicula eliminada");
            }

            fclose(movieEstructuraFile);
            break;

            system("cls");

    printf("\nOperacion exitosa\n");

    system("pause");
        }
        else
        {
            printf("\nLa pelicula indicada no existe");
            fclose(movieEstructuraFile);
            break;
        }
    }


}

/**
 * \brief Se pasa 1 puntero a FILE y una estructura movieStructure. Permite modificar datos sobreescribiendo el archivo binario
 * \param movieStructure movie Estructura
 * \param FILE *movieStructureFile Puntero a file binario
 * \return -
 *
 */
void modificaMovie(eMovie movie, FILE *movieEstructuraFile)
{
    movieEstructuraFile = fopen("movieBin.dat", "rb+");

    char tituloAux[21], descripcionAux[200], generoAux[75];
    float floatAux, floatAuxDuracion;

    printf("\nIngrese titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(tituloAux);

    rewind(movieEstructuraFile);

    while(!feof(movieEstructuraFile))
    {
        fread(&movie, sizeof(eMovie), 1, movieEstructuraFile);

        if(strcmpi(tituloAux, movie.titulo) == 0)
        {
            printf("\nLa pelicula a modificar posee los siguientes datos:\n");
            fflush(stdin);
            printf("\nTitulo: %s  \nGenero: %s  \nDuracion: %d  \nDescripcion: %s  \nPuntaje: %.2f  \nLink: %s\n", movie.titulo, movie.genero, movie.duracion, movie.descripcion, movie.puntaje, movie.linkImagen);
            fflush(stdin);
            printf("\n-DATOS A MODIFICAR-\n");
            fflush(stdin);

            printf("\nIngrese el titulo: ");
            fflush(stdin);
            gets(tituloAux);
            strcpy(movie.titulo, tituloAux);

            getValidString("\nIngrese el genero: ","Solo es permitido el uso de letras, reingrese", generoAux);
            fflush(stdin);
            strcpy(movie.genero,generoAux);

            printf("\nIngrese la descripcion:");
            fflush(stdin);
            gets(descripcionAux);
            strcpy(movie.descripcion, descripcionAux);

            floatAux = getValidFloat("\nIngrese el puntaje: ","Solo son permitidos numeros",1,10);
            fflush(stdin);
            movie.puntaje = floatAux;

            floatAuxDuracion = getValidFloat("\nIngrese la duracion: ","Solo son permitidos numeros",1,500);
            fflush(stdin);
            movie.duracion = floatAuxDuracion;

            printf("\nIngrese el link de la imagen de la pelicula: ");
            fflush(stdin);
            gets(movie.linkImagen);

            fseek(movieEstructuraFile, 0L, SEEK_SET);
            fwrite(&movie, sizeof(eMovie), 1, movieEstructuraFile);

            fclose(movieEstructuraFile);
            break;


            system("cls");

    printf("\nOperacion exitosa\n");

    system("pause");


        }
        else
        {
            printf("El titulo no existe");
            fclose(movieEstructuraFile);
            break;
        }
    }

}

/**
 * \brief Se pasan 2 punteros a FILE y la estructura movieStructure, escribe los contenidos del FILE binario en un FILE de texto
 * \brief controla si existe el archivo a crear, en caso que no exista lo crea
 * \param movieStructure movie Estructura
 * \param  FILE *movieStructureFile Puntero a file binario
 * \param  FILE *movieStructureFileHtml Puntero a file txt
 * \return -
 *
 */
void creaHtml(eMovie movie, FILE *movieEstructuraFile, FILE *movieFileHtml)
{
    if((movieEstructuraFile = fopen("movieBin.dat","rb")) == NULL)
    {
        printf("\nERROR de apertura movieBin.dat");
        exit(1);
    }

    if((movieFileHtml = fopen("movieFileHtml.html", "w+")) == NULL)
    {
        printf("\nERROR de apertura movieFileHtml.html");
        exit(1);
    }

    int auxDuplicaData;

    char content1[]="<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title>  <link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>";
    char content2[]="<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char content3[]="'alt=''></a><h3><a href='#'>";
    char content4[]="</a></h3><ul><li>Genero:";
    char content5[]="</li><li>Puntaje:";
    char content6[]="</li><li>Duracion:";
    char content7[]="</li></ul><p>";
    char content8[]="</p></article>";
    char content9[]="</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";

    fprintf(movieFileHtml, "%s\n", content1);

    rewind(movieEstructuraFile);
    while(!feof(movieEstructuraFile))
    {
        auxDuplicaData = fread(&movie, sizeof(eMovie), 1, movieEstructuraFile);
        if(auxDuplicaData != 1)
        {
            if(feof(movieEstructuraFile))
            {
                break;
            }

            else
            {
                printf("ERROR no se leyo el ultimo registro");
                break;
            }
        }
        fprintf(movieFileHtml,"%s %s %s %s %s %s %s %.02f %s %d %s %s %s\n",content2, movie.linkImagen, content3, movie.titulo, content4, movie.genero,content5,movie.puntaje,content6,movie.duracion,content7,movie.descripcion,content8);
    }

    fprintf(movieFileHtml, "%s", content9);

    fclose(movieEstructuraFile);
    fclose(movieFileHtml);

    system("cls");

    printf("\nArchivo HTML creado con exito\n");

    system("pause");
}

/** \brief Menu de opciones
 *
 * \return numero de opcion elegido por usuario
 *
 */
int menuLista ()
{
    int opcion = 0;

    system("cls");

    opcion = getInt("\n     _-Menu Peliculas-_\n\n1. Agregar pelicula\n2. Borrar pelicula\n3. Modificar pelicula\n4. Generar pagina web\n5. Salir\n\nPor favor elija una opcion: ");

    return opcion;
}

/**
 * \brief Se pasan 2 punteros file y controla si existe el archivo a crear, en caso que no exista lo crea
 * \param FILE *movieStructureFile Puntero a file binario
 * \param FILE *movieStructureFileHtml Puntero a file txt
 * \return -
 *
 */
void esArchivo (FILE *movieEstructuraFile, FILE *movieFileHtml)
{
    if(movieEstructuraFile == NULL || movieFileHtml == NULL)
    {
        if(movieEstructuraFile == NULL)
        {
            movieEstructuraFile = fopen("movieBin.dat", "wb+");
            printf("Se creo el archivo movieBin.dat\n");
            fclose(movieEstructuraFile);
        }
        if(movieFileHtml == NULL)
        {
            movieFileHtml = fopen("movieFileHtml.html", "w+");

            fclose(movieFileHtml);

            system("cls");

            printf("Se creo el archivo movieFileHtml.html\n");

            system("pause");
        }

        if(movieEstructuraFile == NULL || movieFileHtml == NULL)
        {
            printf("\nNo hay espacio para crear el archivo");
            exit(1);
        }
    }
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); //UNIX
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

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

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

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

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
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


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
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

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
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


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
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


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
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

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        clean_stdin();
        break;
    }

}

/**
 * \brief Detiene la ejecucion y muestra un mensaje
 * \param message Mensaje
 * \return -
 *
 */
void pause(char message[])
{
    getChar(message);
    clean_stdin();
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxFloat;
    }

}


