#ifndef DECL_FUNCIONES_H
#define DECL_FUNCIONES_H

#endif // DECL_FUNCIONES_H

void menuEjercicios();
int submenu();
void ejecutando();
int longitud(char cadena[]); //Longitud de cadenas de char
int longInt(int numero); //Longitud de un numero entero
void printArreglo(char (*arreglo)[20],int m, int n); //Impresion de arreglos m*n

void combinaciones(int cantidad); //Billetes
void letrasAleartorias(); // Letras aleartorias
bool comparison(char a[], char b[]); //Comparacion de cadenas
int cadenaAentero(char cadena[]);
void numAcad(int numero, char cadena[], int l); //Conversion de numero a cadena
void convertirAmay(char cadena[],char cadenaNew[]); //Conversion de minuscula a mayuscula
void separarLyN(char cadena[], char cadenaNew[], char numero[]);
void delRepetido(char cadena[], int longitud);//Eliminacion de elementos repetidos
int sumaDen(int numero, int n); //Suma de dividiendo un entero en n cifras
void salaCine(char (*arreglo)[20]); //Reserva o cancelacion de sillas cine
int estrellas(int (*imagen)[8], const int fila, const int columna); //contar estrellas
void interseccionTr(int arreglo[4], int arreglo1[4], int (*arregloI)[4]);



void quitar(char cadena[], char newcadena[]);

