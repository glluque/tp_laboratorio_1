#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[150];
    float puntaje;
    char linkImagen[500];
}eMovie;


void altaMovie(eMovie movie, FILE *movieEstructuraFile, FILE *movieFileHtml);
void borraMovie(eMovie movie, FILE *movieEstructuraFile);
void modificaMovie(eMovie movie, FILE *movieEstructuraFile);
void creaHtml(eMovie movie, FILE *movieEstructuraFile, FILE *movieFileHtml);
void esArchivo (FILE *movieEstructuraFile, FILE *movieFileHtml);
int menuLista();


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void clean_stdin(void);
void pause(char message[]);
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);


#endif // FUNCIONES_H_INCLUDED

