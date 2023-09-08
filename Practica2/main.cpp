#include <iostream>

using namespace std;

void menuEjercicios();
void ejecutando();

int main()
{
    //declaracion de variables
    int con = 1; int opcion = 0;
    cout<<"PRACTICA 2"<<endl;

    //impresion de menu
    menuEjercicios();

    //solicitud de datos
    cout<<"Selecciona el ejercicio a ejecutar: "; cin>>opcion;

    //ciclo de ejercicios
    while (con!=0){
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
        case 2:{}
        case 3:{}
        case 4:{}
        case 5:{}
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

void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Combinacion de billetes"<<endl;
    cout<<"2. "<<endl;
    cout<<"3. "<<endl;
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
void ejecutando(){
    cout<<"Ejecutando ejercicio..."<<endl;
}
