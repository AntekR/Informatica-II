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
    cout<<"6. Minisculas a Mayusculas"<<endl;
    cout<<"7. Eliminar caracteres repetidos"<<endl;
    cout<<"8. "<<endl;
    cout<<"9. Suma de los digitos n de un entero"<<endl;
    cout<<"10. "<<endl;
    cout<<"11. Reserva de asiento en Cine"<<endl;
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

void printArreglo(char (*arreglo)[20], int m, int n){
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            cout<<arreglo[i][j]<<' ';
        }
        cout<<endl;
    }
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

void delRepetido(char cadena[], int l){
    char cadSinRep[l];
    int log = 0;
    int l1=0;
    while(cadena[log]!='\0'){
        if(log==0) cadSinRep[l1++]=cadena[log++];
        else{
            char a=cadSinRep[l1-1]; char b= cadena[log++];
            if(a!=b){
                bool rep=false;
                for(int i=0;i<l;i++){
                    if(b==cadSinRep[i]){
                        rep=true;
                    }
                }
                if(rep==false)
                    cadSinRep[l1++]=b;
            }
        }
    }

    cout<<"Original: "<<cadena;cout<<". Sin repetidos: "<<cadSinRep<<endl;

}

int sumaDen(int numero, int n){
    int div = 1; for(int i=0; i<n;i++) div*=10;
    int suma=0;
    while(numero>0){
        suma += numero%div;
        numero/=div;
    }

    return suma;
}

void salaCine(char (*arreglo)[20]){
    int asiento, opcion, filaInt; char fila;
    char con = 'y';
    while (con!='x') {
        cout<<"Menu"<<endl<<"1. Deseas reservar"<<endl<<"2. Cancelar reserva "<<endl;cin>>opcion;
        if(opcion==1){
            cout<<"En la siguiente imagen vera la sala, recuerda que - es disponible y + reservada"<<endl;
            printArreglo(arreglo,15,20);
            //Se le pide fila y asiento a reservar
            cout<<"Que fila seleccionas (A-O): ";cin>>fila;
            cout<<"Que asiento seleccionas (1-20): ";cin>>asiento;
            //conversion de fila letra a numero
            filaInt = 15-('O'-fila)-1;
            if(arreglo[filaInt][asiento-1]=='-') arreglo[filaInt][asiento-1]='+';cout<<"Su reservacion fue exitosa"<<endl;

            cout<<"Deseas volver al menu anterior o salir del programa (y-menu anterior) o (x-salir): ";cin>>con;
        }else if(opcion==2){

            printArreglo(arreglo,15,20);
            cout<<"Cancelacion de reserva"<<endl;
            cout<<"Que fila seleccionas (A-O): ";cin>>fila;
            cout<<"Que asiento seleccionas (1-20): ";cin>>asiento;
            filaInt = 15-('O'-fila)-1;
            if(arreglo[filaInt][asiento-1]=='+') {
                arreglo[filaInt][asiento-1]='-'; cout<<"Cancelacion exitosa"<<endl;
            }
            else cout<<"Asiento sin reservar, cancelacion invalida"<<endl;

            cout<<"Deseas volver al menu anterior o salir del programa (y-menu anterior) o (x-salir): ";cin>>con;
        }

    }
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
