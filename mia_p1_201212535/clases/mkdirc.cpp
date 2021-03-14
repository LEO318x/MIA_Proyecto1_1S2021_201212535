#include "mkdirc.h"

using namespace std;
mkdirc::mkdirc(string parametros[])
{
    this->path = parametros[0];
    this->p = parametros[1];
}

void mkdirc::ejecutar(){
    extern infoLogin loginfo;
    if(loginfo.uid != ""){

        /*cout << this->path << endl;
        cout << this->p << endl;*/

        buscarRuta(loginfo.pid, this->path);

    }else{
        cout << "ERROR: No puedes ejecutar este comando si no estas logueado." << endl;
    }

    
}
