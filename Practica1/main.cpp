#include <iostream>
#include <string>

using namespace std;

void menuEjercicios();
void mostrar();
void ejecutando();

int main()
{

    //declaracion variables
    int ejercicio;
    int opcion = 1;

    //menu de ejercicios
    menuEjercicios();
    cout<<"Selecciona el ejercicio: ";
    cin>>ejercicio;

    //ciclo-seleccion de ejercicios
    while (ejercicio!=0) {

        switch (opcion) {
        case 1:
            char c;

            ejecutando();
            cout<<"Identificacion de caracter"<<endl;
            cout<<"Ingresa el caracter a identificar: ";
            cin>>c;
            if ((c>=65 && c<=90) || (c>=97 && c<=122)){
                char vocales[]={'A','E','I','O','U'};
                if (c>=97){
                    c-=32;
                    for (int i=0; i<5; i++){
                        if (vocales[i]==c){
                            cout<<c<<"es una vocal"<<endl;
                        break;
                        }else{
                            cout<<c<<"es una consonante"<<endl;
                            break;
                        }
                    }

                }
            }else{
                    cout<<c<<"no es una letra"<<endl;
                    break;
            }
        break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        default:
            break;
        }


    return 0;
    }
}

void menuEjercicios(){
    cout<<"---Menu principal---"<<endl;
    cout<<"1. Identificacion de caracter"<<endl;
    cout<<"2. Combinacion de billetes"<<endl;
    cout<<"3. Combinacion de mes y dia"<<endl;
    cout<<"4. Identificacion de caracter"<<endl;
    cout<<"5. Combinacion de billetes"<<endl;
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
