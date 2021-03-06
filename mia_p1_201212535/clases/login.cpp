#include "login.h"

using namespace std;
login::login(string parametros[0]){

this->usuario = quitarComillasTexto(parametros[0]);
this->password = quitarComillasTexto(parametros[1]);
this->id = quitarComillasTexto(parametros[2]);

}

void login::ejecutar(){    
    if(validarParametros()){
        extern infoLogin loginfo;
        /*cout << "PARAMETROS OK :)" << endl;
        cout << "usuario: " << this->usuario << endl;
        cout << "contraseña: " << this->password << endl;
        cout << "id: " << this->id << endl;
        //test();
        //testArchivo();*/
        if(loginfo.user == ""){
            iniciarSesion();
            testLogin();
        }else{
            cout << "ERROR_LOGIN#001: Ya existe una sesión activa, cierra sesión y vuelve a loguear." << endl;
        }
        
        
    }else{
        cout << "ERROR_LOGIN#001: Falta parametro obligatorio (usuario/contraseña/id)?" << endl;
    }
}

bool login::validarParametros(){
    bool verificacion = true;

    if(this->usuario == ""){
        verificacion = false;
    }else if(this->password == ""){
        verificacion = false;

    }else if(this->id == ""){
        verificacion = false;
    }
    return verificacion;

}


bool login::iniciarSesion(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR_LOGIN#idNO: No existe o no se ha montado la partición" << endl;        
    }else{
        bloqueArchivo ba = buscarIno("/users.txt", this->id);
        string data = ba.b_content;
        vector <string> info = split(data.c_str(), "\n");
        vector <string> datos;
        vector <vector<string>> aux;
        for(int i = 0; i < info.size(); i++){
            //cout << info[i] << endl;
            datos = split(info[i].c_str(), ",");
            aux.push_back(datos);
        }

        for(int i = 0; i < aux.size(); i++){
            if(aux[i].size() == 3){
                /*cout << "----> GRUPO <----" << endl;
                cout << "GID: " << aux[i][0] << endl;
                cout << "TIPO: " << aux[i][1] << endl;
                cout << "GRUPO: " << aux[i][2] << endl;*/
            }else if(aux[i].size() == 5){
                /*cout << "----> USUARIO <----" << endl;
                cout << "GID: " << aux[i][0] << endl;
                cout << "TIPO: " << aux[i][1] << endl;
                cout << "GRUPO: " << aux[i][2] << endl;
                cout << "USER: " << aux[i][3] << endl;
                cout << "PASS: " << aux[i][4] << endl;*/
                string gid = aux[i][0];
                string tipo = aux[i][1];
                string grupo = aux[i][2];
                string user = aux[i][3];
                string pass = aux[i][4];

                if(user == this->usuario && pass == this->password){
                    extern infoLogin loginfo;
                    loginfo.gid = gid;
                    loginfo.tipo = tipo;
                    loginfo.grupo = grupo;
                    loginfo.user = user;
                    loginfo.pass = pass;
                    cout << "EXITO: Usuario logueado exitosamente! :)" << endl;
                    break;
                }
            }
        }
    }
}


void login::testLogin(){
    extern infoLogin loginfo;
    cout << "---> INFO DE SESIÓN <---" << endl;
    cout << loginfo.user << endl;
    cout << loginfo.pass << endl;

}

void login::test(){
    string usuariob = "root";
    string contrab = "123";

    string cadena = "1,G,root\n1,U,root,root,123\n";
    vector <string> info = split(cadena.c_str(), "\n");
    vector <string> datos;
    vector <vector<string>> aux; 
    for(int i = 0; i < info.size(); i++){
        //cout << info[i] << endl;
        datos = split(info[i].c_str(), ",");
        aux.push_back(datos);
    }

    for(int i = 0; i < aux.size(); i++){
        if(aux[i].size() == 3){
            cout << "----> GRUPO <----" << endl;
            cout << "GID: " << aux[i][0] << endl;
            cout << "TIPO: " << aux[i][1] << endl;
            cout << "GRUPO: " << aux[i][2] << endl;
        }else if(aux[i].size() == 5){
            cout << "----> USUARIO <----" << endl;
            cout << "GID: " << aux[i][0] << endl;
            cout << "TIPO: " << aux[i][1] << endl;
            cout << "GRUPO: " << aux[i][2] << endl;
            cout << "USER: " << aux[i][3] << endl;
            cout << "PASS: " << aux[i][4] << endl;
        }
    }
    
}

void login::testArchivo(){
    Partition part = obtenerParticionID(this->id);
    superbloque sb = obtenerSuperBloque(part, this->id);
    cout << "TIPO DE FORMATO: " << sb.s_filesystem_type << endl;
    if(sb.s_filesystem_type != 2 && sb.s_filesystem_type != 3){
        cout << "ERROR: NO HAY SISTEMA DE ARCHIVOS" << endl;
    }else{
        cout << "SISTEMA DE ARCHIVOS ENCONTRADO!" << endl;
    }
}
