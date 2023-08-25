#include <iostream>
#include <string>

using namespace std;

void menuEjercicios();

int main()
{
    int ejercicio;
    string consonante;
    string vocal;

    menuEjercicios();
    cout<<"Selecciona el ejercicio: ";
    cin>>ejercicio;
    while (ejercicio!=0) {



        switch (ejercicio) {
        case 1:
            consonante= "bcdfghjklmnpqrstvwxyz";
            vocal = "aeiou";
            char c;
            cout<<"Identificacion de caracteres"<<endl;
            cout<<"Ingresa el caracter a identificar (vocal-consonante-na): "<<endl;
            cin>>c;
            if (consonante.find(c)){
                cout<<c<<" es una consonante"<<endl;
            }else if (vocal.find(c)){
                cout<<c<<" es una vocal"<<endl;
            }else{
                cout<<c<<" No es una leta"<<endl;
            };
        break;
        case 2:
            break;
        default:
            break;
        }
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
