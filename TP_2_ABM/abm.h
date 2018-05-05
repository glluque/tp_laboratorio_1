#ifndef ADM_H_INCLUDED
#define ADM_H_INCLUDED

typedef struct
{
    int dni;
    char nombre[50];
    unsigned int edad;
    int estado;

}ePersona;

/** \brief Menu de opcione a elegir
 *
 * \return El numero de la opcion elegida
 *
 */

int menu();
/** \brief Inicia el array de estructura ePersona en 1 al estado
 *
 * \param El array a recorrer e inicializar
 * \param El tamanio del array
 *
 */

void inicializarPersona(ePersona[], int);

/** \brief Muestra en una tabla la informacion de los empleados con estado en 0
 *
 * \param El array con la informacion a mostrar
 * \param El tamanio del array
 *
 */

void mostrarPersonas(ePersona [], int);

/** \brief Muestra los datos de una persona con el estado en 0
 *
 * \param El array con la informacion a mostrar
 *
 */

void mostrarPersona(ePersona);

/** \brief Busca un lugar libre en el array de estructura
 *
 * \param La estructura donde buscar
 * \param El tamanio de la estructura
 * \return Devuelve un entero con el subindice del lugar libre y -1 si no hay lugar
 *
 */

int buscarLibre(ePersona[], int);

/** \brief Busca a una persona dentro de la base de datos por su DNI
 *
 * \param El array de estructuras con los datos
 * \param El tamanio del array
 * \param El DNI de la persona a buscar
 * \return Devuelve un entero con el subindice del lugar si existe y -1 si no existe
 *
 */

int buscarPersona(ePersona[], int, int);

/** \brief Elimina una persona de la base de datos colocando su estando en 1
 *
 * \param El array de estructuras con los datos
 * \param El tamanio del array
 *
 */

void bajaPersona(ePersona[], int);

/** \brief Da de alta un persona poniendo su estado en 0 y pide ingresar sus datos
 *
 * \param El array de estructuras con los datos
 * \param El tamanio del array
 *
 */

void altaPersona(ePersona[], int);

/** \brief Ordena por orden alfabetico los apellido de las personas y tambien por edad
 *
 * \param El array de estructuras con los datos
 * \param El tamanio del array
 *
 */

void ordenarPersona(ePersona[], int);

/** \brief Concatena apellido y nombre
 *
 * \param apellido a concatenar
 * \param nombre a concatenar con apellido
 * \return apellido y nombre concatenados en un solo string y con sus mayusculas
 *
 */

char nombreCompleto(char[], char[]);

/** \brief Realiza un grafico de barras con las edades de las personas
 *
 * \param El array de estructuras con los datos
 * \param El tamanio del array
 *
 */

void graficarPersona(ePersona[], int);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char []);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char []);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
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
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char [],char []);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char [],char []);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char [],char []);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char [],char []);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char [],char [], int, int);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char []);



#endif // ADM_H_INCLUDED
