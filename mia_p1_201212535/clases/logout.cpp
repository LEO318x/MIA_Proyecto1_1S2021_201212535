#include "logout.h"

logout::logout()
{

}

void logout::ejecutar(){
    extern infoLogin loginfo;  
    if(loginfo.user != ""){
        cout << "EXITO: ->" << loginfo.user << "<- ha finalizado sesión correctamente" << endl;
        loginfo.user = "";
        loginfo.pass = "";
    }else{
        cout << "ERROR_LOGOUT#001: No existe sesión activa" << endl;
    }  
    
}
