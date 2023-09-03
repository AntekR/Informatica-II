#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void menuEjercicios();
void ejecutando();
int factorial(int n);
bool primo(int n);
int mcdGFC(int a, int b);

int main()
{

    //declaracion variables
    //int ejercicio;
    int opcion = 1;

    //menu de ejercicios
    menuEjercicios();
    cout<<"Selecciona el ejercicio: ";
    cin>>opcion;

    //ciclo-seleccion de ejercicios

    switch(opcion){
    case 1:{
        char c;
        ejecutando();
        cout<<"Identificacion de caracter"<<endl;
        cout<<"Ingresa el caracter a identificar: ";
        cin>>c;
        if ((c>=65 && c<=90) || (c>=97 && c<=122)){
            char vocales[]={'A','E','I','O','U','a','e','i','o','u'};
            bool vocal = true;
            for (int i=0; i<10; i++){
                if (vocales[i]==c){
                    cout<<c<<" es una vocal"<<endl;
                    vocal = true;
                    break;
                }else{vocal=false;}
            }
            if (vocal==false){
                cout<<c<<" es una consonante"<<endl;
            }
        }else{
            cout<<c<<" no es una letra"<<endl;
            break;
        }
        break;}
    case 2:{
        int cantidad;
        int valores[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
        int combinaciones[11];
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
    case 3:{
        int mes, dia;
        int meses[]={31,29,31,30,31,30,31,31,30,31,30,31};
        ejecutando();
        cout<<"Validacion de combinacion de mes y dia";
        cout<<endl<<"Ingrese el dia: ";
        cin>>dia;
        cout<<"Ingrese el mes: ";
        cin>>mes;

        if (mes>=1 && mes<=12){
            if (dia>=1 && dia<=meses[mes-1]) cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;
            else cout<<dia<<"/"<<mes<<" es una fecha invalida"<<endl;
        }else{
            cout<<mes<<" es un mes invalido"<<endl;
        }
        break;
        }
    case 4:{
        int hora, duracion;
        ejecutando();
        cout<<"Suma de tiempo"<<endl;
        cout<<"Ingrese la hora: ";
        cin>> hora;
        int invalido_hor = hora%100;
        if (invalido_hor<60){
            cout<<"Ingrese la duracion: ";
            cin>> duracion;
            int invalido_dur = duracion%100;
            if (invalido_dur<60){
                int dur_min = duracion%100; cout<<dur_min<<endl;
                int hor_min = hora%100; cout<<hor_min<<endl;
                int res_min = (dur_min+hor_min)%60; cout<<res_min<<endl;
                int hor = (hora/100); int hor_dur = duracion/100 ;
                int sum_hr = hor+hor_dur+((dur_min+hor_min)/60); cout<<"La hora es: "<<sum_hr<<res_min<<endl;
            }else{cout<<duracion<<" es una duracion invalida"<<endl;}

        }else{
            cout<<hora<<" es un tiempo invalido"<<endl;
        }
        break;
        }
    case 5:{
        char caracter = 42;
        int espacio = 7;
        ejecutando();
        caracter = '*';
        for (int r=1; r<=14; r+=2){
            if (r<=7){
                for (int e=1; e<=(espacio-r)/2; e++){
                    cout<<' ';
                }
                for (int c=1; c<=r; c++){
                    cout<<caracter;
                }
                for (int e=1; e<=(espacio-r)/2; e++){
                    cout<<' ';
                }
                cout<<endl;
            }

        }
        break;}
    case 6:{
        int numero;
        float aproximacion = 0;
        ejecutando();
        cout<<"Aproximacion euler"<<endl;
        cout<<"Ingresa el numero para la aproximacion: "; cin>>numero;
        for(int j=0;j<numero;j++){
            float f =  factorial(j);
            float d = 1/f;
            aproximacion += d;

        }
        cout<<"e es aproximadamente: "<<aproximacion<<endl;
        break;}
    case 7:{
        int suma=0; int n;
        int suma_fibonacci = 0;
        int acumulados[]={1,1};
        ejecutando();
        cout<<"Serie de Fibonnaci"<<endl;
        cout<<"Ingrese el numero a hallar la suma de los pares: "; cin>>n;
        while (suma_fibonacci<=n) {
            int s = acumulados[0]+acumulados[1];
            acumulados[0]= acumulados[1]; acumulados[1]=s;
            if (s%2==0 && s<=n) suma += s;

            suma_fibonacci=s;

        }
        cout<<"El resultado de la suma es: "<<suma<<endl;
        break;
    }
    case 8:{
        int a, b, c;
        ejecutando();
        cout<<"Calculo de suma de multiplos de a y b menores a c"<<endl;
        cout<<"Ingrese el valor de a: ";cin>>a;
        cout<<"Ingrese el valor de b: ";cin>>b;
        cout<<"Ingrese el valor de c: ";cin>>c;
        int mul_a=c/a; int mul_b=c/b;
        if (c%a==0){
            mul_a-=1;
            if(c%b==0){
                mul_b-=1;
            }
        }else if(c%b==0 or b*5<c) {
            mul_b-=1;
        }
        int cant_mul = mul_a + mul_b;
        int n_multiplos[cant_mul];
        int suma_multiplos = 0;
        for (int i=1; i<=mul_a;i++){
            int mult = a*i;
            suma_multiplos += mult;
            n_multiplos[i-1]=mult;

        }
        for (int j=1; j<=mul_b;j++){
            int mult = b*j;
            suma_multiplos += mult;
            n_multiplos[(mul_a-1)+j]=mult;

        }
        for (int p=0;p<cant_mul;p++){
            if (p==0)  cout<<n_multiplos[p];
            else cout<<"+"<<n_multiplos[p];
        }
        cout<<"="<<suma_multiplos<<endl;
        break;

    }
    case 9:{
        int numero;
        int suma = 0;
        ejecutando();
        cout<<"Suma de digitos"<<endl;
        cout<<"Ingres el numero: "; cin>>numero;

        while (numero>0) {
            int resto = numero%10;
            numero /= 10;
            int elevado = pow(resto,resto);
            suma += elevado;
        }
        cout<<"El resultado de la suma es: "<<suma<<endl;
        break;
    }
    case 10:{
        int n;
        int con=0;
        int numero = 2;
        ejecutando();
        cout<<"Enesimo numero primo"<<endl;
        cout<<"Ingresa un numero: ";cin>>n;

        while (con<n) {
            if(primo(numero)){
                con +=1;
                if(con==n){
                    cout<<"El primo numero "<<n<<" es: "<<numero<<endl;
                    break;
                }
            }
            numero++;
        }
        break;
    }
    case 11:{
        int n;
        int mcm=1;
        ejecutando();
        cout<<"Minimo comun multiplo"<<endl;
        cout<<"Ingrese un numero: ";
        cin>>n;
        for(int i=2;i<=n;i++){
            int mcd = mcdGFC(mcm,i);
            mcm = (mcm*i)/mcd;
        }
        cout<<"El minimo comun multiplo es: "<<mcm<<endl;

        break;
    }
    case 12:{
        int n;
        int con=0;
        int numero = 2;
        ejecutando();
        cout<<"Factores primos"<<endl;
        cout<<"Ingresa un numero: ";cin>>n;
        int factor = 0;
        while (con<n) {
            if(primo(numero)){
                con +=1;
                if(n%numero==0){
                    factor = numero;
                }
            }
            numero++;
        }
        cout<<"El mayor factor primo de "<<n<<" es: "<<factor<<endl;
        break;
    }
    }

}


void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Identificacion de caracter"<<endl;
    cout<<"2. Combinacion de billetes"<<endl;
    cout<<"3. Combinacion de mes y dia"<<endl;
    cout<<"4. Suma de tiempo"<<endl;
    cout<<"5. Patron en pantalla - Rombo"<<endl;
    cout<<"6. Aproximacion euler"<<endl;
    cout<<"7. Serie de Fibonnaci"<<endl;
    cout<<"8. Suma de multiplos"<<endl;
    cout<<"9. Suma de digitos"<<endl;
    cout<<"10. Enesimo numero primo"<<endl;
    cout<<"11. Minimo comun multiplo"<<endl;
    cout<<"12. Factores primos"<<endl;
    cout<<"13. "<<endl;
    cout<<"14. "<<endl;
    cout<<"15. "<<endl;
    cout<<"16. "<<endl;
    cout<<"17. "<<endl;


}

void ejecutando(){
    cout<<"Ejecutando ejercicio..."<<endl;
}

int factorial(int n){
    int fact = n;
    int suma = 0;
    if (n==0){
        suma = 1;
    }else if (n==1){
        n = n+1;
        for (int i=1; i<n;i++){
            suma+= fact*(n-1);
            fact-= 1;
            n-=1;
        }
    }else{
        for (int i=1; i<n;i++){
            suma+= fact*(n-1);
            fact-= 1;
        }
    }

    return suma;
}

bool primo(int n){
    if (n<=1) return false;
    for (int i = 2; i*i <= n; i++) {
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int mcdGFC(int a, int b){
    if (b==0) return a;

    return mcdGFC(b,a%b);
}
