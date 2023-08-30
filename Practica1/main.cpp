#include <iostream>
#include <string>

using namespace std;

void menuEjercicios();
void mostrar();
void ejecutando();

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
        }
    break;
    }

}


void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Identificacion de caracter"<<endl;
    cout<<"2. Combinacion de billetes"<<endl;
    cout<<"3. Combinacion de mes y dia"<<endl;
    cout<<"4. Suma de tiempo"<<endl;
    cout<<"5. Patron en pantalla - Rombo"<<endl;
    cout<<"6. Combinacion de mes y dia"<<endl;
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

void mostrar(string texto){
    cout<<texto<<endl;
}
void ejecutando(){
    mostrar("Ejecutando ejercicio...");
}
