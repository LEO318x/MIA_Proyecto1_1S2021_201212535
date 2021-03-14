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
        loginfo.uid = "";
        loginfo.pid = "";
        loginfo.grupo = "";
        loginfo.gid = "";
    }else{
        cout << "ERROR_LOGOUT#001: No existe sesión activa" << endl;
    }  
    
}
