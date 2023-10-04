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
    cout<<"18. Permutaciones lexicograficas"<<endl;
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
        arreglo[i]='A'+rand()%26; //rellena el arreglo con las letras, el 26 porque la diferencia entre A Y Z es eso
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

//Ejercicio 4
int cadenaAentero(char cadena[]){
    int numero = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        int valor = cadena[i] - '0';
        numero = numero * 10 + valor;
    }
    return numero;
}

//Ejercicio 5
void numAcad(int numero, char cadena[], int l){

    if(numero<0) l+=1;
    if(numero==0) cadena[0]='0';

    for(int i=0; i<l;i++){
        cadena[i]= '0'+numero%10;
        numero/=10;
    }
    cadena[l]='\0';

};

//Ejercicio 6
void convertirAmay(char cadena[], char cadenaNew[]){
    int i = 0;
    for (; cadena[i] != '\0'; i++) {
        cadenaNew[i]=cadena[i];
        if (cadena[i] >= 'a' && cadena[i] <= 'z'){
            cadena[i] = cadena[i] - 'a' + 'A';
        }
    }
    cadenaNew[i]='\0';

}

//Ejercicio 7
void delRepetido(char cadena[], int l){
    char cadSinRep[l]; int l1=0; //contador para cadena nueva
    int log = 0; //contador para cadena ingresada

    while(cadena[log]!='\0'){
        if(log==0) {
            char a=cadena[log++];
            if ('A'<a && a<'Z') a = a+' '; // validacion si es mayuscula
            cadSinRep[l1++]=a;
        }
        else{
            char a=cadSinRep[l1-1]; char b= cadena[log++];
            if ('A'<b && b<'Z') b +=' ';
            if(a!=b){
                bool rep=false;
                for(int i=0;i<l;i++){ // Ciclo para validar con las letras ya add
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

//Ejercicio 8
void separarLyN(char cadena[], char cadenaNew[], char numero[]){
    int j=0; int k=0;
    for (int i = 0; cadena[i] != '\0'; i++){
        if (!isdigit(cadena[i])){
            cadenaNew[j] = cadena[i];
            j++;
        }else{
            numero[k++]=cadena[i];
        }
    }
    numero[k]='\0';
    cadenaNew[j]='\0';
}

//Ejercicio 9
int sumaDen(int numero, int n){
    int div = 1; for(int i=0; i<n;i++) div*=10;
    int suma=0;
    while(numero>0){
        suma += numero%div;
        numero/=div;
    }

    return suma;
}

//Ejercicio 10
int romanoAarabigo(char cadena[]){
    int l=longitud(cadena);
    int valores[]={1000,500,100,50,10,5,1};
    char simbolos[]={'M','D','C','L','X','V','I'};
    int resultado=0; int prevalor=0;

    for(int i=l-1;i>=0;i--){
        int valor = 0;
        for (int j = 0; j < 7; ++j) {
            if(cadena[i]==simbolos[j]){
                valor = valores[j];
                break;
            }
        }

        if(valor==0){
            cout<<"Numero romano invalido"<<endl;
            return 0;
        }else if(valor<prevalor){
            resultado-=valor;
        }else if(valor>=prevalor){
            resultado+=valor;
        }
        prevalor = valor;
    }
    return resultado;
}

//Ejercicio 11
void salaCine(){
    char arreglo[15][20]; // Matriz de asientos


    // Inicializar la matriz de asientos con asientos disponibles ('-')
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            arreglo[i][j] = '-';
        }
    }

    int asiento, opcion, filaInt; char fila;

    char con = 'y';

    while (con!='x') {
        cout<<"Menu"<<endl<<"1. Deseas reservar"<<endl<<"2. Cancelar reserva "<<endl;
        cout<<"Selecciona la opcion: ";cin>>opcion;

        if(opcion==1){
            cout<<endl<<"Sala"<<endl;
            printArreglo(arreglo,15,20);

            //Se le pide fila y asiento a reservar
            cout<<"Que fila seleccionas (A-O): ";cin>>fila;

            if (fila < 'A' || fila > 'O') {
                cout << "Fila no valida. Debe ser una letra entre A y O." << endl;
                continue; // Volver al inicio del bucle
            }

            cout<<"Que asiento seleccionas (1-20): ";cin>>asiento;

            if (asiento < 1 || asiento > 20) {
                cout << "Asiento no valido. Debe estar entre 1 y 20." << endl;
                continue; // Volver al inicio del bucle
            }

            //conversion de fila letra a numero
            filaInt = 15-('O'-fila)-1;

            if(arreglo[filaInt][asiento-1]=='-') {
                arreglo[filaInt][asiento-1]='+';
                cout<<"Su reservacion fue exitosa"<<endl;
            }else{
                cout<<"El asiento ya esta reservado"<<endl;
            }
        }else if(opcion==2){
            printArreglo(arreglo,15,20);

            cout<<"Cancelacion de reserva"<<endl;

            cout<<"Que fila seleccionas (A-O): ";cin>>fila;

            if (fila < 'A' || fila > 'O') {
                cout << "Fila no válida. Debe ser una letra entre A y O." << endl;
                continue; // Volver al inicio del bucle
            }

            cout<<"Que asiento seleccionas (1-20): ";cin>>asiento;

            if (asiento < 1 || asiento > 20) {
                cout << "Asiento no válido. Debe estar entre 1 y 20." << endl;
                continue; // Volver al inicio del bucle
            }

            filaInt = 15-('O'-fila)-1;

            if(arreglo[filaInt][asiento-1]=='+') {
                arreglo[filaInt][asiento-1]='-';
                cout<<"Cancelacion exitosa"<<endl;
            }
            else cout<<"Asiento sin reservar, cancelacion invalida"<<endl;
        }
        cout<<"Deseas volver al menu anterior o salir del programa (y-menu anterior) o (x-salir): ";cin>>con;
        if(con=='Y') con='y';
        else if(con=='X') con='x';
    }
}

//Ejercicio 12
void cuadroMagico(int n){
    int matriz[n][n];
    cout<<"Ingrese los datos de la matriz"<<endl;
    for(int i=0;i<n;i++){
        for (int j=0; j<n;j++){
            int valor=0;
            bool repetido=false;

            do{
                cout<<"El dato de la posicion "<<i<<","<<j<<": ";
                cin>>valor;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if(valor==matriz[x][y]){
                            cout<<"El valor ya ha sido ingresado";
                            break;
                        }
                    }
                    if(repetido) break;
                }
                if(!repetido)
                    matriz[i][j]=valor;
            }while(repetido);
        }
    }

    cout<<"Matriz ingresada"<<endl;
    for (int f = 0; f < n; ++f) {
        for (int c = 0; c < n; ++c) {
            cout<<matriz[f][c]<<" ";
        }
        cout<<endl;
    }

    //Validaciones para saber si es cuadro magico
    int suma_fila=0;
    for (int suma = 0; suma < n; ++suma) {
        suma_fila+=matriz[0][suma];
    }

    bool cuadroMagico=true;

    for (int i = 0; i < n; ++i) {
        int sumaFilaActual=0;
        for (int j = 0; j < n; ++j) {
            sumaFilaActual+=matriz[i][j];
        }
        if(sumaFilaActual!=suma_fila){
            cuadroMagico = false;
            break;
        }
    }

    int suma_columna=0;
    for (int suma = 0; suma < n; ++suma) {
        suma_columna+=matriz[0][suma];
    }

    for (int j = 0; j < n; ++j) {
        int sumaColumnaActual=0;
        for (int i = 0; i < n; ++i) {
            sumaColumnaActual+=matriz[i][j];
        }
        if(sumaColumnaActual!=suma_columna){
            cuadroMagico = false;
            break;
        }
    }

    // Verificar la suma de la diagonal principal
    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonalPrincipal += matriz[i][i];
    }
    if (sumaDiagonalPrincipal != suma_fila) {
        cuadroMagico = false;
    }

    // Verificar la suma de la diagonal secundaria
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonalSecundaria += matriz[i][n - 1 - i];
    }
    if (sumaDiagonalSecundaria != suma_fila) {
        cuadroMagico = false;
    }

    if (cuadroMagico) {
        cout << "La matriz es un cuadrado magico." << endl;
    } else {
        cout << "La matriz no es un cuadrado magico." << endl;
    }



}

//Ejericio 13
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

//Ejercicio 14
void matrizRotada(){
    int matriz[5][5];
    int valor=1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matriz[i][j]=valor;
            valor+=1;
        }
    }
    cout<<endl<<"Matriz normal"<<endl;
    //Impresion normal
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<"Matriz rotada 90 grados"<<endl;
    //Impresion 90 grados
    for (int  j= 0; j<5; ++j) {
        for (int i = 4; i >= 0; --i) {
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout << "Matriz rotada 180 grados:" << endl;
    for (int i = 4; i >= 0; i--) {
        for (int j = 4; j >= 0; j--) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
    // Imprimir matriz rotada 270 grados
    cout << "Matriz rotada 270 grados:" << endl;
    for (int j = 4; j>=0; j--) {
        for (int i = 0; i < 5; i++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
}

//Ejercicio 17
int sumaDiv(int a){
    int sumaA=1;
    for(int i=2; i<a; i++){
        if(a%i==0){
            sumaA+=i;
        }
    }
    return sumaA;
}

void numerosAmigables(int a){
    int suma=0;
    //Verificacion
    for (int i = 1; i <= a; ++i) {
        int b = sumaDiv(i);
        // b<i ->> no contemos los pares de números amigables más de una vez
        if(b>i && sumaDiv(b)==i){
            suma+= i+b;
        }
    }
    cout<<"El resultado de la suma es: "<<suma<<endl;
}

//Ejercicio 18
int factorial(int n){
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}
void lexicografica(int n, char cad[]){
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        numeros[i] = i + '0'; // Inicializa con caracteres
    }
    n--; // Restamos 1 para ajustar al índice base 0

    for (int i = 9; i >= 0; i--) {
        int f = factorial(i);
        int posicion = n / f;
        n %= f;
        cad[9 - i] = numeros[posicion]; // Guarda el carácter en la permutación

        // Eliminamos el número utilizado
        for (int j = posicion; j < 9; j++) {
            numeros[j] = numeros[j + 1];
        }
    }

    cad[10] = '\0';
}
