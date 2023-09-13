#include <iostream>
#include <decl_funciones.h>
using namespace std;


int main()
{
    //declaracion de variables
    int con = 1; int opcion = 0;
    cout<<"PRACTICA 2"<<endl;

    //impresion de menu
    menuEjercicios();


    //ciclo de ejercicios
    while (con!=0){
        //solicitud de datos
        cout<<"Selecciona el ejercicio a ejecutar: "; cin>>opcion;
        switch (opcion) {
        case 1:{
            int cantidad;
            int valores[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
            int combinaciones[11];
            ejecutando();
            cout<<"Combinacion de billetes"<<endl;
            cout<<"Ingrese la cantidad para validar la combinacion de billetes y monedas: ";
            cin>>cantidad;
            for (int i=0; i<10; i++){
                combinaciones[i]= cantidad/valores[i];
                cantidad %= valores[i];
            }
            for (int j=0; j<11; j++){
                if(j==10){
                    cout<<"Faltante: "<<cantidad<<endl;
                }else{
                    cout<<valores[j]<<": "<<combinaciones[j]<<endl;
                }
            }
            break;}
        case 2:{

            break;
        }
        case 3:{
            char cadUno[20]; char cadDos[20];
            ejecutando();
            cout<<"Comparacion de cadenas"<<endl;
            cout<<"Ingrese la primera cadena: ";cin>>cadUno;
            cout<<"Ingrese la segunda cadena: ";cin>>cadDos;
            bool comparacion = comparison(cadUno,cadDos);
            cout<<"Las cadenas "<<cadUno<<" y "<<cadDos<<" son iguales?: ";
            if(comparacion==1) cout<<"Verdadero"<<endl;
            else cout<<"Falso"<<endl;
            con = submenu();
        break;
        }
        case 4:{}
        case 5:{

        break;
        }
        case 6:{}
        case 7:{}
        case 8:{}
        case 9:{}
        case 10:{}
        case 11:{}
        case 12:{}
        case 13:{}
        case 14:{}
        case 15:{}
        case 16:{}
        case 17:{}

        default:
            break;
        }
    }

    return 0;
}
