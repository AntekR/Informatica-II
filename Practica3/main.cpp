#include <decl_fun.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    int semilla, metodo, proceso;
    string entrada, salida;

    cout<<"Programa de codificacion y decodificacion/Aplicativo Cajero"<<endl<<endl;
    cout<<"-----------------------Menu-------------------------------"<<endl<<endl;
    cout<<"1. Codificar"<<endl;
    cout<<"2. Decodificar"<<endl;
    cout<<"3. Aplicativo Cajero"<<endl;
    cout<<"Selecciona una opcion: ";
    cin>>proceso;

    while (proceso!=4) {

        switch (proceso) {
        case 1:{

            cout<<endl<<"-------------------Codificacion de textos----------------"<<endl;
            cout<<"Ingresa el nombre del archivo de entrada: ";
            cin>>entrada;
            cout<<"Ingresa el nombre del archivo de salida: ";
            cin>>salida;
            cout<<"Ingresa la semilla para codificar: ";
            cin>>semilla;
            cout<<"Metodos de codificacion"<<endl;
            cout<<"1. Metodo 1"<<endl;
            cout<<"2. Metodo 2"<<endl;
            cout<<"Selecciona un metodo: ";
            cin>>metodo;

            //Conversion de ASCII a Binario - NameFile: Binario.txt
            deAscii_Abinario(entrada);

            if(metodo==1){
                codificarM1(salida,semilla);
            }else if(metodo==2){
                codificarM2(salida,semilla);
            }else{
                cout<<"Opcion invalida"<<endl;
            }
            break;
        }
        case 2:{
            cout<<endl<<"--------------------Decodificar texto---------------------"<<endl;
            cout<<"Ingresa el nombre del archivo de entrada: ";
            cin>>entrada;
            cout<<"Ingresa el nombre del archivo de salida: ";
            cin>>salida;
            cout<<"Ingresa la semilla para decodificar(recuerda que debe ser la misma que utilizaste para codificar): ";
            cin>>semilla;

            //Funcion que desencripta
            desencriptarM2(entrada,salida,semilla);

            break;
        }
        case 3:{

            break;
        }
        default:
            break;
        }
    }

    return 0;
}
