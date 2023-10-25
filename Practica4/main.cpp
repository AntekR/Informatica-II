#include <router.h>
#include <network.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cctype>
int main() {
    netWork n;

    bool c = true;
    while (c) {
        // Menú
        int choice;
        cout << endl ;
        cout << "\tSistema de simulacion de red de enrutadores"<<endl;
        cout << "\t1. Agregar enrutador" << endl;
        cout << "\t2. Agregar/Eliminar enlaces" << endl;
        cout << "\t3. Calcular costo de envio" << endl;
        cout << "\t4. Encontrar camino eficiente" << endl;
        cout << "\t5. Generar red aleatoria" << endl;
        cout << "\t6. Cargar red desde archivo" << endl;
        cout << "\t7. Salir" << endl;
        cout << "\tIngresa la seleccion: ";
        cin >> choice;
        map<string,map<string,int>> topologia = n.buildTopology();
        switch (choice) {
        case 1: {           //Agregar enrutadores - eliminar
            string routerName; int num;
            cout<<endl<<"\t\t\tAgregar enrutadores"<<endl;
            cout<<"\tIngrese el numero de enrutadores a agregar: ";
            cin>> num;
            for (int i = 0; i < num; ++i) {
                cout << "\tNombre del enrutador "<<i+1<<" : ";
                cin >> routerName;
                n.addRouter(routerName);
                routerName.erase();
            }
            break;
        }
        case 2: {           //Agregar enlaces entre enrutadores
            int opcion; string routerName; int enl; char p=' ';
            cout << endl << "\t\tSubmenu" << endl;
            cout << "\t1. Agregar enlace" << endl;
            cout << "\t2. Eliminar enlace" <<endl;
            cout << "\tIngrese su seleccion: "; cin >> opcion;
            string d; int costo;
            if(opcion==1){
                cout <<endl<< "\t\tAgregar enlaces"<<endl ;
                cout << "\tNombre del enrutador origen: ";
                cin >> routerName;
                cout << "\tIngrese el numero de enlaces: ";
                cin >> enl;
                for (int i = 0; i < enl; ++i) {

                    cout << "\tNombre del segundo enrutador en el enlace: ";
                    cin >> d;
                    cout << "\tCosto del enlace: ";
                    cin >> costo;
                    try {
                        n.routers.at(routerName).addLink(d, costo);
                        n.routers.at(d).addLink(routerName, costo);
                    } catch (const out_of_range& e) {
                        p = 'x';
                        cerr << "\tNo es posible agregar el enlace. Uno o ambos enrutadores no existen en la red." << endl;
                        break;
                    }
                    n.updateTopology(routerName,d,costo);
                }
                if(p!='x') cout<<"\tEnlaces agregados"<<endl;
            }else if(opcion==2){
                cout <<endl<< "\t\tEliminar enlaces"<<endl ;
                cout << "\tNombre del enrutador origen: ";
                cin >> routerName;
                cout << "\tIngrese el numero de enlaces: ";
                cin >> enl;
                for (int i = 0; i < enl; ++i) {
                    cout << "\tNombre del segundo enrutador en el enlace: ";
                    cin >> d;
                    try {
                        n.routers.at(routerName).removeLink(d);
                        n.routers.at(d).removeLink(routerName);
                        topologia = n.buildTopology();
                    } catch (const out_of_range& e) {
                        p = 'x';
                        cerr << "\tNo es posible eliminar el enlace. Uno o ambos enrutadores no existen en la red." << endl;
                        break;
                    }
                }
                if(p!='x') cout<<"\tEnlaces eliminados"<<endl;
            }

            break;
        }
        case 3: {           //Costo de envio entre enlaces existentes
            string origen; string destino;
            cout << "\tCosto de envio entre enlaces existentes"<<endl;
            cout << "\tEnrutador de origen: ";
            cin >> origen;
            cout << "\tEnrutador de destino: "; cin>>destino;
            int costo = n.routers.at(origen).getCost(destino);
            if(0<=costo){
                cout<<"\tEl costo de envio es de: "<<costo<<endl;
            }else{
                cout<<"\tNo se encontro una ruta valida"<<endl;
            }
            break;
        }
        case 4: {
            string origen, destino;
            cout<<"\tEnrutador de origen: "; cin>>origen;
            cout<<"\tEnrutador de destino: "; cin>>destino;
            string wayShort = n.getShortWay(origen,destino);
            cout <<"\t" << wayShort << endl;
            break;
        }
        case 5: {
            int numRouters;
            cout << "Número de enrutadores: ";
                    cin >> numRouters;
            // Metodo para generar red
            break;
        }
        case 6: {
            string filename;
            cout << "\t\tCarga de topologia desde archivo" << endl;
            cout << "\tNombre del archivo de topologia: ";
            cin >> filename;
            n.loadTopology(filename);
            break;
        }
        case 7:
            c = false;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
        cout<<"\t\t----------------------------"<<endl;
    }
    return 0;
}
