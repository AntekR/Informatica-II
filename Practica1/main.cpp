#include <iostream>

using namespace std;

void menuEjercicios();

int main()
{
    int ejercicio;
    menuEjercicios();
    cout<<"Selecciona el ejercicio: ";
    cin>>ejercicio;
    while (ejercicio!=0) {
        switch (ejercicio) {
        case 1:
            cout<<"Este es el primer ejercicio"<<endl;
            break;
        default:
            break;
        }
    }
}

void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Identificacion de caracter"<<endl;

}
