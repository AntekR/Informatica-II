
#ifndef DECL_FUN_H
#define DECL_FUN_H

#include <string>
using namespace std;

#endif // DECL_FUN_H

void submenu(int& proceso);

// Codificacion - Decodificación
string valueBinary(char a);
void deAscii_Abinario(string name);
void codificarM2(string salida, int semilla);
void decodificarBinarioM2(string entrada,int semilla);
void desencriptarM2(string entrada,string salida,int semilla);
char dBinario_aAascii(string temp);
void ceros_unos(string bloque, int conteo[2]);
string invertirDigitos(string bloque1);
string invertirC2Digitos(string bloque1);
string invertirC3Digitos(string bloque1);
void codificarM1(string salida, int semilla);
void decodificarBinarioM1(string entrada, int semilla);
void desencriptarM1(string entrada,string salida,int semilla);

//Aplicacion cajero

int contadorUsuarios();
void baseDatos(string usuarios[][6], int c);
bool validarAdministrador(string password);
string asciiAbinarioSinFile(string variable);
string codificarSinFile(string binario);
bool validarUsuario(string documento, int v, int c, string usuarios[][6], int& m);
string decodificarSinFile(string binario);
void saveChanges(string usuarios[][6], int c);

