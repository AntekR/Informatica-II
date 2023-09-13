#include <iostream>
#include <decl_funciones.h>

using namespace std;

void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Combinacion de billetes"<<endl;
    cout<<"2. Repeticion aleartoria"<<endl;
    cout<<"3. Comparacion de cadenas"<<endl;
    cout<<"4. "<<endl;
    cout<<"5. "<<endl;
    cout<<"6. "<<endl;
    cout<<"7. "<<endl;
    cout<<"8. "<<endl;
    cout<<"9. "<<endl;
    cout<<"10. "<<endl;
    cout<<"11. "<<endl;
    cout<<"12. "<<endl;
    cout<<"13. "<<endl;
    cout<<"14. "<<endl;
    cout<<"15. "<<endl;
    cout<<"16. "<<endl;
    cout<<"17. "<<endl;

}
int submenu(){
    int con=0;
    cout<<"Deseas volver al menu o salir definitivamente del programa"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"1. Volver al menu"<<endl;
    cout<<"Que eliges?: ";cin>>con;
    return con;
}
void ejecutando(){
    cout<<"Ejecutando ejercicio..."<<endl;
}

int longitud(char cadena[]){
    int length=0;
    while(cadena[length]!='\0'){
        length+=1;
    }
    return length;
}

bool comparison(char a[], char b[]){
    int longUno=longitud(a); int longDos=longitud(b);
    if (longUno!=longDos) return false;
    else{
        for(int i=0;i<longUno;i++){
            if(a[i]!=b[i]) return false;
        }
    }

    return true;
}

void quitar(char cadena[],char newCadena[]){

    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++){
        if (!isdigit(cadena[i])){
            newCadena[j] = cadena[i];
            j++;
        }
    }
    cout << newCadena << endl;


}
