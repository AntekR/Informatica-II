#include <decl_fun.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    int semilla, metodo, proceso;
    string entrada, salida;

    cout<<"Programa de codificacion y decodificacion/Aplicativo Cajero"<<endl<<endl;
    cout<<"-----------------------Menu-------------------------------"<<endl<<endl;
    cout<<"1. Codificar"<<endl;
    cout<<"2. Decodificar"<<endl;
    cout<<"3. Aplicativo Cajero"<<endl;
    cout<<"4. Imprimir datos de usuario"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Selecciona una opcion: ";
    cin>>proceso;

    while (proceso!=5) {

        switch (proceso) {
        case 1:{

            cout<<endl<<"-------------------Codificacion de textos----------------"<<endl;
            cout<<"Ingresa el nombre del archivo de entrada: ";
            cin>>entrada;
            cout<<"Ingresa el nombre del archivo de salida: ";
            cin>>salida;
            cout<<"Ingresa la semilla para codificar: ";
            cin>>semilla;
            cout<<"Metodos de codificacion"<<endl;
            cout<<"1. Metodo 1"<<endl;
            cout<<"2. Metodo 2"<<endl;
            cout<<"Selecciona un metodo: ";
            cin>>metodo;

            //Conversion de ASCII a Binario - NameFile: Binario.txt
            deAscii_Abinario(entrada);

            if(metodo==1){
                codificarM1(salida,semilla);
                submenu(proceso);
                break;
            }else if(metodo==2){
                codificarM2(salida,semilla);
                submenu(proceso);
            }else{
                cout<<"Opcion invalida"<<endl;
            }


            break;
        }
        case 2:{
            cout<<endl<<"--------------------Decodificar texto---------------------"<<endl;
            cout<<"Ingresa el nombre del archivo de entrada: ";
            cin>>entrada;
            cout<<"Ingresa el nombre del archivo de salida: ";
            cin>>salida;
            cout<<"Ingresa la semilla para decodificar(recuerda que debe ser la misma que utilizaste para codificar): ";
            cin>>semilla;
            cout<<"Metodo que uso al codificar."<<endl;
            cout<<"1. Metodo 1"<<endl;
            cout<<"2. Metodo 2"<<endl;
            cout<<"Selecciona un metodo: ";
            cin>>metodo;

            if(metodo==1){
                desencriptarM1(entrada,salida,semilla);
                submenu(proceso);
            }else if(metodo==2){
                desencriptarM2(entrada,salida,semilla);
                submenu(proceso);
            }else{
                cout<<"Opcion invalida"<<endl;
            }
            break;
        }
        case 3:{
            int opcion;  string passAdmin; bool isAdmin; int registros; string doc; string clave; string saldo;
            cout<<endl<<"--------------------Aplicacion----------------------------"<<endl;
            cout<<"1. Acceder como administrador"<<endl;
            cout<<"2. Acceder como usuario"<<endl;
            cout<<"Como deseas ingresar: "; cin>> opcion;
            switch (opcion) {
            case 1:{
                //Clave de administrador encriptada con M2 y semilla 8 - Fijo
                cout<<endl<<"-------------Acceso como administrador--------------------"<<endl;
                cout<<"Ingrese la clave: ";
                cin>> passAdmin;
                isAdmin = validarAdministrador(passAdmin);
                if(isAdmin==true){
                    cout<<endl<<"\t\t Acceso correcto"<<endl;
                    cout<<"\t   Bienvenido administrador"<<endl;
                    cout<<"1. Registrar usuarios"<<endl;
                    cout<<"0. Salir"<<endl;
                    cout<<"Selecciona una opcion: ";
                    int op;
                    cin>>op;
                    if(op==1){
                        cout<<"Ingrese el numero de registros a realizar: ";
                        cin>>registros;
                        ofstream fileUser("usuarios.txt", ios::app);
                        for(int i = 0; i < registros; ++i) {
                            string user; string doc; string clave; string saldo;
                            cout<<"Ingrese el documento: "; cin>> doc;
                            cout<<"Ingrese la clave: "; cin>>clave;
                            cout<<"Ingrese el saldo (COP): "; cin>> saldo;
                            user = doc+","+clave+","+saldo+"\n";

                            string userTemp = codificarSinFile(asciiAbinarioSinFile(user));
                            fileUser<<userTemp;
                        }
                        submenu(proceso);
                    }else{
                        break;
                    }
                }
                break;
            }
            case 2:{
                int opcion;
                int cUsuarios = contadorUsuarios(); int posSaldo; int m=0; int acepto;
                string usuarios[cUsuarios][6];
                baseDatos(usuarios,cUsuarios);
                cout<<endl<<"-------------Acceso como usuario--------------------"<<endl;
                cout<<"Ingrese su documento: ";cin>>doc;
                if(validarUsuario(doc,1,cUsuarios, usuarios, m)==true){
                    cout<<"Ingrese su clave: ";cin>>clave;
                    if(validarUsuario(clave,2,cUsuarios, usuarios, m)==true){
                        cout<<"Validacion exitosa"<<endl;
                        cout<<"1. Consultar saldo"<<endl;
                        cout<<"2. Retirar dinero"<<endl;
                        cout<<"Selecciona una opcion: ";
                        cin>>opcion;

                        if(opcion==1){// Consulta de saldo
                            cout<<"Consulta de saldo"<<endl;
                            cout<<"Ten presente que la consulta de saldo tiene un costo de $1.000 COP"<<endl;
                            cout<<"1. Continuar, 2. Salir: ";
                            cin>>acepto;
                            if(acepto==1){
                                saldo = decodificarSinFile(usuarios[m][4]);
                                posSaldo = stod(saldo)-1000;
                                cout<<"Saldo: "<<posSaldo<<endl;
                                cout<<"Tu saldo actual, descontando la consulta actual es: "<<posSaldo;
                                usuarios[m][4]=codificarSinFile(asciiAbinarioSinFile(to_string(posSaldo)));
                                saveChanges(usuarios,cUsuarios);
                            }else{
                                break;
                            }
                            submenu(proceso);
                        }else if(opcion==2){ // Retiro de dinero
                            int retiro;
                            cout<<"Retiro de dinero"<<endl;
                            cout<<"Ingresa el monto a retirar: "; cin>> retiro;
                            saldo = decodificarSinFile(usuarios[m][4]);
                            posSaldo = stod(saldo);
                            cout<<"Ten en cuenta que el retiro tiene un costo de $1.000"<<endl;
                            cout<<"1. Continuar, 2. Salir: ";
                            cin>>acepto;
                            if(acepto==1){
                                if(posSaldo<retiro){
                                    usuarios[m][4]=codificarSinFile(asciiAbinarioSinFile(to_string((posSaldo-retiro))));
                                    saveChanges(usuarios,cUsuarios);
                                    cout<<"Fondos insuficientes";
                                    break;
                                }else if(posSaldo>retiro){
                                    cout<<"Retiro exitoso"<<endl;
                                    cout<<"Por favor retire su dinero"<<endl;
                                    cout<<"Tu saldo actual es: "<<posSaldo-retiro<<endl;
                                    usuarios[m][4]=codificarSinFile(asciiAbinarioSinFile(to_string((posSaldo-retiro))));
                                    saveChanges(usuarios,cUsuarios);
                                }
                            }else{
                                break;
                            }
                            submenu(proceso);
                        }
                    }
                }
                break;
            }
            default:
                break;
            }
            break;
        }
        case 4:{
            cout<<"Impresion de usuarios sin encriptar, teniendo en cuenta consultas y retiros"<<endl;
            desencriptarM2("usuarios.txt","DecodificadoUser.txt",8);
            ifstream decodificado("DecodificadoUser.txt");
            char linea;
            while (decodificado.good()) {
                linea = decodificado.get();
                cout<<linea;
            }
            decodificado.close();
            proceso=5;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
