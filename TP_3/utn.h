#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[], char cadena[]);
int getStringLetras(char mensaje[], char cadena[]);
int getStringNumeros(char mensaje[], char cadena[]);
//int getNumeroRandom(int desde, int hasta, int iniciar);

void inicializarArray(int arrayInt[], int largoArray, int valor);
int buscarPrimerCoincidencia(int arrayInt[], int largoArray, int valor);

int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
