#include <iostream>
#include <string>


using namespace std;

int main()
{
    int semilla, metodo, proceso;
    string entrada, salida;
    cout<<"Programa de codificacion y decodificacion"<<endl;
    cout<<"Menu"<<endl;
    cout<<"1. Codificar"<<endl<<"2. Decodificar"<<endl<<"Selecciona una opcion: ";
    cin>>proceso;
    switch (proceso) {
    case 1:
        cout<<"Codificacion de textos"<<endl;
        cout<<"Metodos de codificacion"<<endl<<"1. Metodo 1"<<endl<<"2. Metodo 2"<<endl;
        cout<<"Selecciona un metodo: ";
        cin>>metodo;
        cout<<"Archivo a codificar"<<endl<<"Ingresa el nombre del archivo de entrada: ";
        cin>>entrada;
        cout<<"Ingresa el nombre del archivo de salida: ";
        cin>>salida;
        if(metodo==1){

        }else if(metodo==2){

        }else{
            cout<<"Opcion invalida"<<endl;
        }

        break;
    case 2:
        break;
    default:
        break;
    }

    return 0;
}
