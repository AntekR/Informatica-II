#include <decl_fun.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream ae; ofstream as;

string binario(char a){
    std::string valueBinario;
    for (int i=7; i>=0; i--) {
        int bit = a%2;
        a/=2;
        valueBinario=to_string(bit) + valueBinario;
    }


    return valueBinario;
}

void asciiAbinario(string name){
    ifstream fileInput(name);
    ofstream fileBinary("Binario.txt");
    if(!fileInput){
        cerr<<"Error: No se pudo abrir el archivo o crear"<<endl;
    }else{
        char caracter;
        while(fileInput.get(caracter)){
            string vBinario = binario(caracter);
            fileBinary<<vBinario;
        }
        fileBinary.close();
    }
    fileInput.close();
}

char binarioAascii(string name){
    int valueAscii=0;
    int base=1;
    for(int i=7; i>=0; i--){
        if(name[i]=='1') valueAscii+=base;
        base*=2;
    }
    char ascii= char(valueAscii);
    base=1;
    return ascii;
}

void metodo2(string salida, int semilla){
    int p=0;
    string bloque1;
    ifstream fileBinary("Binario.txt");
    ofstream fileCod(salida);
    while(fileBinary.good()){
        char temp = fileBinary.get();
        bloque1+=temp;
        p++;
        if(p==semilla){
            string tempoBloque;
            for(int i=0; i<semilla;i++){
                if(i==0) tempoBloque+=bloque1[p-1];
                else tempoBloque+=bloque1[i-1];
            }
            fileCod<<tempoBloque;
            p=0;
            bloque1.erase();
        }

    }
    cout<<"Codificacion Exitosa"<<endl;
}

void metodo2DBinario(string entrada, int semilla){
    int p=0;
    string bloque1;
    ifstream fileBinary(entrada);
    ofstream fileTemp("dBinario.txt");
    while(fileBinary.good()){
        char temp = fileBinary.get();
        bloque1+=temp;
        p++;
        if(p==semilla){
            string tempoBloque;
            for(int i=0; i<semilla;i++){
                if(i==semilla-1) tempoBloque+=bloque1[0];
                else tempoBloque+=bloque1[i+1];
            }
            fileTemp<<tempoBloque;
            p=0;
            bloque1.erase();
        }
    }
}

void metodo2Desencriptar(string entrada, string salida, int semilla){
    metodo2DBinario(entrada,semilla);

    int bit=0;
    string bloqueBinario;

    ifstream fileTemp("dBinario.txt");
    ofstream fileDesencriptado(salida);
    while(fileTemp.good()){
        char temp = fileTemp.get();
        bloqueBinario+=temp;
        bit++;
        if(bit==8){
            char ascii= binarioAascii(bloqueBinario);
            fileDesencriptado<<ascii;
            bit=0;
            bloqueBinario.erase();
        }
    }
    cout<<"Descodificacion Exitosa"<<endl;
}


