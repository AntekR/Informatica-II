#include <decl_fun.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    ifstream ae; ofstream as;
    int semilla, metodo, proceso;
    string entrada, salida;
    cout<<"Programa de codificacion y decodificacion"<<endl;
    cout<<"Menu"<<endl;
    cout<<"1. Codificar"<<endl<<"2. Decodificar"<<endl<<"Selecciona una opcion: ";
    cin>>proceso;
    switch (proceso) {
    case 1:

        cout<<"Codificacion de textos"<<endl;
        cout<<"Ingresa el nombre del archivo de entrada: ";
        cin>>entrada;
        cout<<"Ingresa el nombre del archivo de salida: ";
        cin>>salida;
        cout<<"Ingresa la semilla para codificar: ";
        cin>>semilla;
        cout<<"Metodos de codificacion"<<endl;
        cout<<"1. Metodo 1"<<endl<<"2. Metodo 2"<<endl;
        cout<<"Selecciona un metodo: ";
        cin>>metodo;

        //Conversion de ASCII a Binario - NameFile: Binario.txt
        asciiAbinario(entrada);

        if(metodo==1){
            break;
        }else if(metodo==2){
            metodo2(salida,semilla);
        }else{
            cout<<"Opcion invalida"<<endl;
        }
        break;
    case 2:
        cout<<"Decodificar texto"<<endl;
        cout<<"Ingresa el nombre del archivo de entrada: ";
        cin>>entrada;
        cout<<"Ingresa el nombre del archivo de salida: ";
        cin>>salida;
        cout<<"Ingresa la semilla para codificar: ";
        cin>>semilla;
        metodo2Desencriptar(entrada,salida,semilla);
        break;
    default:
        break;
    }

    return 0;
}
