#ifndef ADM_H_INCLUDED
#define ADM_H_INCLUDED

typedef struct
{
    int dni;
    char nombre[50];
    unsigned int edad;
    int estado;

}eEmpleado;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menu();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void inicializarEmpleados(eEmpleado[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarEmpleados(eEmpleado [], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarEmpleado(eEmpleado);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarLibre(eEmpleado[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarEmpleado(eEmpleado[], int, int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void bajaEmpleado(eEmpleado[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void altaEmpleado(eEmpleado[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void ordenarEmpleados(eEmpleado[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

char nombreCompleto(char[], char[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void graficarEmpleados(eEmpleado[], int);


/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumerico(char []);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char []);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char []);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char []);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char []);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char [],char []);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char [],char []);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char [],char []);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char [],char []);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char [],char [], int, int);

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char []);



#endif // ADM_H_INCLUDED
