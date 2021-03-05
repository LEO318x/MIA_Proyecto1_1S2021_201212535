#include "login.h"

using namespace std;
login::login(string parametros[0]){

this->usuario = quitarComillasTexto(parametros[0]);
this->password = quitarComillasTexto(parametros[1]);
this->id = quitarComillasTexto(parametros[2]);

}

void login::ejecutar(){    
    if(validarParametros()){
        cout << "PARAMETROS OK :)" << endl;
        cout << "usuario: " << this->usuario << endl;
        cout << "contraseña: " << this->password << endl;
        cout << "id: " << this->id << endl;
        vector <string> s = split("hola,mundo,prueba,texto,cosa", ",");
        for(int i=0; i < s.size(); i++){
            cout << s[i] << endl;
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
