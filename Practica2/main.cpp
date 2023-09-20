#include <iostream>
#include <decl_funciones.h>

using namespace std;


int main()
{
    //declaracion de variables
    int con = 1; int opcion = 0;
    cout<<"PRACTICA 2"<<endl;

    //impresion de menu



    //ciclo de ejercicios
    while (con!=0){
        //solicitud de datos
        menuEjercicios();
        cout<<"Selecciona el ejercicio a ejecutar: "; cin>>opcion;
        switch (opcion) {
        case 1:{
            int cantidad;
            ejecutando();
            cout<<"Combinacion de billetes"<<endl;
            cout<<"Ingrese la cantidad para validar la combinacion de billetes y monedas: ";
            cin>>cantidad;
            combinaciones(cantidad);
            cout<<endl;
            submenu();
            break;
        }
        case 2:{
            ejecutando();
            cout<<"Arreglo de letras"<<endl;
            letrasAleartorias();
            submenu();
            break;
        }
        case 3:{
            char cadUno[20]; char cadDos[20];
            ejecutando();
            cout<<"Comparacion de cadenas"<<endl;
            cout<<"Ingrese la primera cadena: ";cin>>cadUno;
            cout<<"Ingrese la segunda cadena: ";cin>>cadDos;
            bool comparacion = comparison(cadUno,cadDos);
            cout<<"Las cadenas "<<cadUno<<" y "<<cadDos<<" son iguales?: ";
            if(comparacion==1) cout<<"Verdadero"<<endl;
            else cout<<"Falso"<<endl;
            con = submenu();
            break;
        }
        case 4:{}
        case 5:{
            int numero;
            ejecutando();
            cout<<"De numero a cadena"<<endl;
            cout<<"Ingrese el numero a convertir: ";cin>>numero;
            int longEntero = longInt(numero); if(numero<0) longEntero+=1;
            char cadena[longEntero]; int l;
            //numAcad(numero,cadena,longEntero,l);
            cout<<cadena<<endl;
            con = submenu();
            break;
        }
        case 6:{}
        case 7:{
            char cadena[20];
            ejecutando();
            cout<<"Eliminar caracteres repetidos"<<endl;
            cout<<"Ingresa la cadena: ";cin>>cadena;
            int longCadena = longitud(cadena);
            delRepetido(cadena,longCadena);
            submenu();
            break;
        }
        case 8:{}
        case 9:{
            int numero, n;
            ejecutando();
            cout<<"Suma de un numero divido en n cifras"<<endl;
            cout<<"Ingrese el numero de cifras: ";cin>>n;
            cout<<"Ingrese el numero: ";cin>>numero;
            cout<<"Original: "<<numero<<endl;
            cout<<"Suma: "<<sumaDen(numero,n)<<endl;
            submenu();
            break;
        }
        case 10:{}
        case 11:{
            char sala[15][20];

            //Relleno de los asientos
            for(int i=0; i<15;i++){
                for(int j=0; j<20; j++){
                    sala[i][j]='-';
                }
            }

            ejecutando();
            cout<<"Reserva de asiento en Cine"<<endl;

            salaCine(sala);

            break;
        }
        case 12:{}
        case 13:{
            int imagen[6][8]={
                {0, 3, 4, 0, 0, 0, 6, 8},
                {5, 13, 6, 0, 0, 0, 2, 3},
                {2, 6, 2, 7, 3, 0, 10, 0},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {0, 0, 7, 12, 6, 9, 10, 4},
                {5, 0, 6, 10, 6, 4, 8, 0}
            };
            const int filas=6; const int columnas=8;
            int estrellas_encontradas=estrellas(imagen,filas,columnas);

            cout<<"Se encontraron "<<estrellas_encontradas<<" estrellas en la imagen."<<endl;

            break;
        }
        case 14:{}
        case 15:{
            int rectUno[4]; int rectDos[4]; int rectInt[4]; int ciclos=0;
            ejecutando();
            cout<<"Triangulo interseccion"<<endl;
            cout<<"Ingresa los datos, en el siguiente orden: coordenada x, coordenada y, ancho y altura"<<endl;
            while(ciclos<2){
                cout<<"Rectangulo "<<ciclos+1<<endl;
                for (int i = 0; i < 4; ++i) {
                    cout<<"Ingrese el dato: ";
                    if (ciclos==0) cin>>rectUno[i];
                    else cin>>rectDos[i];
                }
                ciclos++;
            }

        }
        case 16:{}
        case 17:{}

        default:
            if (opcion==0) con = 0;
            break;
        }

    }

    return 0;
}

