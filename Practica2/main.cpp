#include <iostream>
#include <typeinfo>
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
            con=submenu();
            break;
        }
        case 2:{
            ejecutando();
            cout<<"Arreglo de letras"<<endl;
            letrasAleartorias();
            con=submenu();
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
            else cout<<"Falso"<<endl<<endl;

            con=submenu();
            break;
        }
        case 4:{
            char cadena[20];
            ejecutando();

            cout<<"De cadena a Numero"<<endl;
            cout<<"Ingrese la cadena a convertir: ";cin>>cadena;

            cout<<"El tipo de dato de "<<cadenaAentero(cadena)<<" es: "<<typeid(cadenaAentero(cadena)).name()<<endl;
            con=submenu();
            break;
        }
        case 5:{
            int numero;
            ejecutando();

            cout<<"De numero a cadena"<<endl;
            cout<<"Ingrese el numero a convertir: ";cin>>numero;

            // recorro el entero para saber cuantos digitos tiene
            int lInt = longInt(numero); if(numero<0) lInt+=1; // Si el numero es negativo, sumo un digito mas para add el menos.
            char cadena[lInt];
            numAcad(numero,cadena,lInt);
            cout<<"El numero "<<numero<<" fue exitosamente convertido a cadena."<<endl;

            con=submenu();
            break;
        }
        case 6:{
            char cadena[20];
            ejecutando();

            cout<<"Convertir a Mayusculas"<<endl;
            cout<<"Ingrese la cadena a convertir: ";cin>>cadena;

            int l=longitud(cadena);
            char cadenaOri[l];
            convertirAmay(cadena, cadenaOri);

            cout<<"Original: "<<cadenaOri<<" En mayuscula: "<<cadena<<endl<<endl;
            con=submenu();
            break;
        }
        case 7:{
            char cadena[20];
            ejecutando();

            cout<<"Eliminar caracteres repetidos"<<endl;
            cout<<"Ingresa la cadena: ";cin>>cadena;

            int longCadena = longitud(cadena);
            delRepetido(cadena,longCadena);

            con=submenu();
            break;
        }
        case 8:{
            char cadena[20];
            ejecutando();

            cout<<"Separacion de cadena y numero"<<endl;
            cout<<"Ingrese la cadena a separar: ";cin>>cadena;

            int lg = longitud(cadena);
            char cadenaNew[lg]; char numeros[lg];

            separarLyN(cadena,cadenaNew,numeros);

            cout<<"Original: "<<cadena<<endl;
            cout<<"Texto: "<<cadenaNew<<".    Numero: "<<numeros<<endl;
            break;
        }
        case 9:{
            int numero, n;
            ejecutando();
            cout<<"Suma de un numero divido en n cifras"<<endl;
            cout<<"Ingrese el numero de cifras: ";cin>>n;
            cout<<"Ingrese el numero: ";cin>>numero;
            cout<<"Original: "<<numero<<endl;
            cout<<"Suma: "<<sumaDen(numero,n)<<endl;
            con=submenu();
            break;
        }
        case 10:{
            char romano[10];
            ejecutando();

            cout<<"Romano a Arabigo"<<endl;
            cout<<"Ingresa el numero en Romano (Mayuscula): "; cin>>romano;

            cout<<"El numero ingresado fue: "<<romano<<endl;
            cout<<"Que corresponde a: "<<romanoAarabigo(romano)<<endl;

            con=submenu();
            break;
        }
        case 11:{

            cout<<"Reserva de asiento en Cine"<<endl;

            salaCine();

            break;
        }
        case 12:{
            int n;
            ejecutando();

            cout<<"Cuadrado Magico"<<endl;
            cout<<"Ingresa el tamaño de la matriz cuadrada: ";cin>>n;

            cuadroMagico(n);

            con = submenu();
            break;
        }
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

            con=submenu();
            break;
        }
        case 14:{
            ejecutando();
            cout<<"Impresion matriz rotada"<<endl;
            matrizRotada();
            con=submenu();
            break;
        }
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
        case 16:{
            break;
        }
        case 17:{
            int n;
            ejecutando();

            cout<<"Numeros amigables"<<endl;
            cout<<"Ingrese un numero: ";cin>>n;
            numerosAmigables(n);
            con=submenu();
            break;
        }
        case 18:{
            int n;
            ejecutando();

            cout<<"Permutaciones lexicograficas"<<endl;
            cout<<"Ingresa un numero: ";cin>>n;

            if (n >= 1 && n <= 3628800) { // Valida que n esté en el rango válido
                char permutacion[11]; // 10 caracteres + 1 para el carácter nulo
                lexicografica(n,permutacion);
                cout << "La permutacion numero " << n << " es: " << permutacion << "." << endl;
            } else {
                cout << "El valor de n no esta en el rango permitido" << endl;
            }
        }default:
            if (opcion==0) con = 0;
            break;
        }

    }

    return 0;
}

