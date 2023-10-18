#include <decl_fun.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream ae; ofstream as;

void submenu(int& proceso){
    cout<<endl;
    int op;
    cout<<"Deseas volver al menu anterior o salir."<<endl;
    cout<<"1. Menu anterior, 2. Salir: ";cin>>op;
    if(op==1){
        cout<<"-----------------------Menu-------------------------------"<<endl<<endl;
        cout<<"1. Codificar"<<endl;
        cout<<"2. Decodificar"<<endl;
        cout<<"3. Aplicativo Cajero"<<endl;
        cout<<"4. Imprimir datos de usuario"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Selecciona una opcion: ";
        cin>>proceso;
    }else{
        proceso=5;
    }
}

//Funciones complementarias para el proceso de encriptar

string valueBinary(char a){
    string valueBinario; //Se guarda el valor binario de la letra
    for (int i=7; i>=0; i--) {
        int bit = a%2;
        a/=2;
        valueBinario=to_string(bit) + valueBinario; //to_string -> conv int a string.
    }
    //65 A ->string 01000000

    return valueBinario;
}

void deAscii_Abinario(string name){
    ifstream fileInput(name);
    ofstream fileBinary("Binario.txt");
    if(!fileInput){
        cerr<<"Error: No se pudo abrir el archivo o crear"<<endl;
    }else{
        char caracter;
        while(fileInput.get(caracter)){
            string valorBinario = valueBinary(caracter);
            fileBinary<<valorBinario;
        }
        fileBinary.close();
    }
    fileInput.close();
}

// ************************METODO 1********************************

void ceros_unos(string bloque, int conteo[2]){
    conteo[0]=0; conteo[1]=0;
    for(int i=0; i < bloque.size();i++){
        if(bloque[i]=='0'){
            conteo[0]+=1;
        }else conteo[1]+=1;
    }
}

string invertirDigitos(string bloque1){
    string bloque2;
    for(int i=0; i < bloque1.size();i++){
        if(bloque1[i]=='0'){
            bloque2+='1';
        }else{
            bloque2+='0';
        }
    }
    return bloque2;
}

string invertirC2Digitos(string bloque1){
    string bloque2=bloque1;
    for(int i=1; i < bloque1.size();i+=2){
        if(bloque1[i]=='0'){
            bloque2[i]='1';
        }else{
            bloque2[i]='0';
        }
    }
    return bloque2;
}

string invertirC3Digitos(string bloque1){
    string bloque2=bloque1;
    for(int i=2; i < bloque1.size();i+=3){
        if(bloque1[i]=='0'){
            bloque2[i]='1';
        }else{
            bloque2[i]='0';
        }
    }
    return bloque2;
}

void codificarM1(string salida, int semilla){
    int p=0; int b=0; int conteo[]={0,0};
    string bloque1;
    string bloque2;
    ifstream fileBinary("Binario.txt");
    ofstream fileCod(salida);
    while(fileBinary.good()){
        char temp = fileBinary.get(); //Lectura de caracter a caracter
        bloque1+=temp;
        p++;
        if(p==semilla){
            if(b==0){
                bloque2=invertirDigitos(bloque1);
                fileCod<<bloque2;
                b++;
            }else if(b!=0 && conteo[0]==conteo[1]){
                bloque2=invertirDigitos(bloque1);
                fileCod<<bloque2;
            }else if(b!=0 && conteo[0]>conteo[1]){
                bloque2=invertirC2Digitos(bloque1);
                fileCod<<bloque2;
            }else if(b!=0 && conteo[0]<conteo[1]){
                bloque2=invertirC3Digitos(bloque1);
                fileCod<<bloque2;
            }
            ceros_unos(bloque1,conteo);
            p=0; bloque1.erase(); bloque2.erase();
        }
    }

    cout<<"Codificacion Exitosa"<<endl;
}

void decodificarBinarioM1(string entrada, int semilla){
    int p=0; int b=0; int conteo[]={0,0};
    string bloque1;
    string bloque2;
    ifstream fileBinary(entrada);
    ofstream fileTemp("dBinario.txt");
    while(fileBinary.good()){
        char temp = fileBinary.get();
        bloque1+=temp;
        p++;
        if(p==semilla){
            if(b==0){
                bloque2=invertirDigitos(bloque1);
                fileTemp<<bloque2;
                b++;
            }else if(b!=0 && conteo[0]==conteo[1]){
                bloque2=invertirDigitos(bloque1);
                fileTemp<<bloque2;
            }else if(b!=0 && conteo[0]>conteo[1]){
                bloque2=invertirC2Digitos(bloque1);
                fileTemp<<bloque2;
            }else if(b!=0 && conteo[0]<conteo[1]){
                bloque2=invertirC3Digitos(bloque1);
                fileTemp<<bloque2;
            }
            bloque1=bloque2;
            ceros_unos(bloque1,conteo);
            p=0; bloque1.erase(); bloque2.erase();
        }
    }
}

void desencriptarM1(string entrada, string salida, int semilla){
    decodificarBinarioM1(entrada,semilla);

    int bit=0;
    string bloqueBinario;

    ifstream fileTemp("dBinario.txt");
    ofstream fileDesencriptado(salida);
    while(fileTemp.good()){
        char temp = fileTemp.get();
        bloqueBinario+=temp;
        bit++;
        if(bit==8){
            char ascii= dBinario_aAascii(bloqueBinario);
            fileDesencriptado<<ascii;
            bit=0;
            bloqueBinario.erase();
        }
    }
    cout<<"Descodificacion Exitosa"<<endl;
}
// ************************METODO 2********************************

//---Funcion encriptar Metodo 2---
void codificarM2(string salida, int semilla){
    int p=0;
    string bloque;
    ifstream fileBinary("Binario.txt");
    ofstream fileCod(salida);
    while(fileBinary.good()){
        char temp = fileBinary.get();
        bloque+=temp; // 1110
        p++;
        if(p==semilla){
            string tempoBloque; //0111
            for(int i=0; i<semilla;i++){
                if(i==0) tempoBloque+=bloque[p-1];
                else tempoBloque+=bloque[i-1];
            }
            fileCod<<tempoBloque;
            p=0;
            bloque.erase();
        }

    }
    cout<<"Codificacion Exitosa"<<endl;
}

//Funciones complementarias para el proceso de desencriptar    0  2  2 2
char dBinario_aAascii(string name){ // binario a ascii division  "10010101"
    int valueAscii=0;    // ascii a binario multiplicacion
    int base=1;
    for(int i=7; i>=0; i--){
        if(name[i]=='1') valueAscii+=base;
        base*=2;
    }
    char ascii= char(valueAscii);
    base=1;
    return ascii;
}


// Pasa de binario codificado a binario real
void decodificarBinarioM2(string entrada, int semilla){
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


// Funcion desencriptar Metodo 2
void desencriptarM2(string entrada, string salida, int semilla){
    decodificarBinarioM2(entrada,semilla);

    int bit=0;
    string bloqueBinario;

    ifstream fileTemp("dBinario.txt");
    ofstream fileDesencriptado(salida);
    while(fileTemp.good()){
        char temp = fileTemp.get();
        bloqueBinario+=temp;
        bit++;
        if(bit==8){
            char ascii= dBinario_aAascii(bloqueBinario);
            fileDesencriptado<<ascii;
            bit=0;
            bloqueBinario.erase();
        }
    }
    cout<<"Descodificacion Exitosa"<<endl;
}


// Aplicacion cajero

string asciiAbinarioSinFile(string variable){
    string binario;
    for(int j=0; j<variable.size();j++){
        char a = variable[j];
        string valueBinario; //Se guarda el valor binario de la letra
        for (int i=7; i>=0; i--) {
            int bit = a%2;
            a/=2;
            valueBinario=to_string(bit) + valueBinario; //to_string -> conv int a string.
        }
        binario+=valueBinario;
    }
    cout<<"Binario: "<<binario<<endl;
    return binario;
}

string codificarSinFile(string binario){
    int p=0;
    string binarioCompleto;
    string bloque;
    for(int j=0; j<binario.size(); j++){
        char temp = binario[j];
        bloque+=temp;
        p++;
        if(p==8){
            string tempoBloque; //0111
            for(int i=0; i<8;i++){
                if(i==0) tempoBloque+=bloque[p-1];
                else tempoBloque+=bloque[i-1];
            }
            p=0;
            bloque.erase();
            binarioCompleto+=tempoBloque;
        }
    }
    cout<<"Codificado: "<<binarioCompleto<<endl;
    return binarioCompleto;
}

int contadorUsuarios(){
    ifstream fileUsers("usuarios.txt");
    int c=0; string bloque; int p=0;
    while(fileUsers.good()){
        char temp = fileUsers.get();
        bloque+=temp;
        p++;
        //Conteo de cuantos usuarios hay
        if(p==8 && bloque=="00000101") {
            c++;
            p=0; bloque.erase();
        }else if(p==8 && bloque!="00000101"){
            p=0; bloque.erase();
        }
    }
    return c;
}

void baseDatos(string usuarios[][6], int c){
    string bloqueAll, bloque;
    ifstream fileUser("usuarios.txt");
    int j=0, p=0, i=0;
    while(fileUser.good() && i<c){
        char temp = fileUser.get();
        bloque+=temp;
        p++;
        if(p==8 && bloque!="00010110" && bloque!="00000101"){
            bloqueAll+= bloque;
            p=0; bloque.erase();
        }else if((p==8 && bloque=="00010110")){
            for (j;  j < 6;) {
                usuarios[i][j]=bloqueAll;
                p=0; bloqueAll.erase();
                break;
            }
            j++; usuarios[i][j]=bloque; bloque.erase(); j++;
        }else if(p==8 && bloque=="00000101"){
            for (j;  j < 6;) {
                usuarios[i][j]=bloqueAll;
                p=0; bloqueAll.erase();
                break;
            }
            j++;
            usuarios[i][j]=bloque;
            bloque.erase();
            j=0;
            i++;
        }
    }
}

bool validarAdministrador(string password){
    string binario=asciiAbinarioSinFile(password);
    string codificado = codificarSinFile(binario);
    string passSudo;
    ifstream fileSudo("sudo.txt");
    while (fileSudo.good()) {
        char temp = fileSudo.get();
        if(temp==48 or temp==49){
            passSudo += temp;
        }
    }
    return codificado==passSudo;
}

bool validarUsuario(string documento, int v, int c,string usuarios[][6], int& m){
    bool isRegister=false;
    if(v==1){
        for (int i = 0; i < c; ++i) {
            string docRegistrado = usuarios[i][0];
            if(codificarSinFile(asciiAbinarioSinFile(documento))==docRegistrado){
                isRegister=true;
                m = i;
                break;
            }
        }
    }else if(v==2){
        string claveRegistrado = usuarios[m][2];
        if(codificarSinFile(asciiAbinarioSinFile(documento))==claveRegistrado){
            isRegister=true;

        }
    }
    return isRegister;
}

string decodificarSinFile(string binario){
    int p=0;
    string binarioCompleto;
    string bloque;
    for(int j=0; j<binario.size(); j++){
        char temp = binario[j];
        bloque+=temp;
        p++;
        if(p==8){
            string tempoBloque;
            for(int i=0; i<8;i++){
                if(i==8-1) tempoBloque+=bloque[0];
                else tempoBloque+=bloque[i+1];
            }
            p=0;
            bloque.erase();
            binarioCompleto+=dBinario_aAascii(tempoBloque);
        }
    }
    return binarioCompleto;
}

void saveChanges(string usuarios[][6], int c){
    ofstream changes("usuarios.txt");
    for(int i=0; i <c; i++){
        for (int j = 0; j < 6; ++j) {
            changes<<usuarios[i][j];
        }
    }
}
