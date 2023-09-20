#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <decl_funciones.h>

using namespace std;
//Funciones complementarias
void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Combinacion de billetes"<<endl;
    cout<<"2. Repeticion aleartoria"<<endl;
    cout<<"3. Comparacion de cadenas"<<endl;
    cout<<"4. De cadena a numero"<<endl;
    cout<<"5. De numero a cadena"<<endl;
    cout<<"6. Minisculas a Mayusculas"<<endl;
    cout<<"7. Eliminar caracteres repetidos"<<endl;
    cout<<"8. Separacion de numeros en una cadena"<<endl;
    cout<<"9. Suma de los digitos n de un entero"<<endl;
    cout<<"10. De romano a Arabigo"<<endl;
    cout<<"11. Reserva de asiento en Cine"<<endl;
    cout<<"12. Es cuadro magico?"<<endl;
    cout<<"13. Numero de estrellas"<<endl;
    cout<<"14. Imprimir matriz rotada"<<endl;
    cout<<"15. Interseccion de rectangulos"<<endl;
    cout<<"16. Caminos posibles"<<endl;
    cout<<"17. Numeros amigables"<<endl;
    cout<<"0. Salir"<<endl;

}
int submenu(){
    int con=1;
    cout<<"Deseas volver al menu o salir definitivamente del programa"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"1. Volver al menu"<<endl;
    cout<<"Que eliges?: ";cin>>con;
    cout<<endl;
    return con;
}
void ejecutando(){
    cout<<endl<<"Ejecutando ejercicio..."<<endl<<endl;
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
    if(numero==0) longitud++;
    else{
        while (con!=0){
        numero=numero/10;
        con = numero;
        longitud++;
        }
    }
    return longitud;
}
//Funcione de cada ejercicios

//Ejercicio 1
void combinaciones(int cantidad){
    int valores[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int combinaciones[11]; //guarda {50000= , 20000= , }

    for (int i=0;i<10; i++){
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

}

//Ejercicio 2
void letrasAleartorias(){
    srand(time(NULL));
    char arreglo[200];

    for (int i = 0; i < 200; i++) {
        arreglo[i]='A'+rand()%26;
    }
    for (int i = 0; i < 200; i++) {
        cout<<arreglo[i];
    }
    cout<<endl;
    int rep[26]={0};
    for (int i = 0; i < 200; i++){
        if (arreglo[i] >= 'A' && arreglo[i] <= 'Z'){
        rep[arreglo[i] - 'A']++;
        }
    }
    for (char letra = 'A'; letra <= 'Z'; letra++) cout<<letra<<": "<<rep[letra - 'A']<<endl;
}
//Ejercicio 3
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

void numAcad(int numero, char cadena[],int longEntero, int *l){
    int n=0;
    char cadenaReverse[longEntero];
    if(numero==0) cadenaReverse[n]='0';
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
    /*int l = 0;
    if(numero==0) cadena[l]={'0'};
    else{
        while (longEntero>0){
            cadena[l]=cadenaReverse[longEntero-1];
            l +=1;
            longEntero-=1;
        }

    }*/

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

int estrellas(int (*imagen)[8], const int fila, const int columna){
    int starsFound=0;
    for (int i = 1; i < fila-1; ++i) {
        for (int j = 1; j < columna-1; ++j) {
            int sumaFormula = imagen[i][j]+imagen[i][j-1]+imagen[i][j+1]+imagen[i-1][j]+imagen[i+1][j];
            double is_star = sumaFormula/5;
            if(is_star>6) starsFound++;
        }
    }
    return starsFound;
}

void interseccionTr(int arreglo[4], int arreglo1[4], int (*arregloI)[4]){

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
