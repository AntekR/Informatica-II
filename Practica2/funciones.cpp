#include <iostream>
#include <decl_funciones.h>

using namespace std;

void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Combinacion de billetes"<<endl;
    cout<<"2. Repeticion aleartoria"<<endl;
    cout<<"3. Comparacion de cadenas"<<endl;
    cout<<"4. De cadena a numero"<<endl;
    cout<<"5. De numero a cadena"<<endl;
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
    cout<<"0. Salir"<<endl;

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

int longInt(int numero){
    int longitud=0;
    int con=numero;
    while (con!=0){
        numero=numero/10;
        con = numero;
        longitud++;
    }
    return longitud;
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

void numAcad(int numero, char cadena[],int longEntero){
    int n=0;
    char cadenaReverse[longEntero];
    if(numero==0) cadenaReverse[n++]='0';
    else{
        if(numero<0){
            //Se agrega el guión para el numero negativo y se convierte el numero a positivo para facilitar la conversion
            cadenaReverse[longEntero-1]='-';
            numero = -numero;
        }
        while(numero>0){
            int digito = numero%10;
            cadenaReverse[n++]='0'+digito;
            numero /= 10;
        }

    }
    int l = 0;
    while (longEntero>0){
        cadena[l]=cadenaReverse[longEntero-1];
        l +=1;
        longEntero-=1;
    }

};
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
