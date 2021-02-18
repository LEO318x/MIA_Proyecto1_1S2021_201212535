#include "rmdisk.h"

rmdisk::rmdisk()
{

}

void rmdisk::eliminarDisco(std::string ruta){
    std::string rutaOriginal;
    std::string rutaAux = ruta;
    //Eliminamos las comillas de la ruta
    rutaAux.erase(remove(rutaAux.begin(), rutaAux.end(), '\"'), rutaAux.end());
    rutaOriginal = rutaAux;

    char entrada;
    std::cout << "¿Estas seguro de eliminar el disco? Y/N " << std::endl;
    std::cin >> entrada;

    if(entrada == 'Y' || entrada == 'y'){
        if(remove(rutaOriginal.c_str())){
            std::cout << "DISCO ELIMINADO! X_X" << std::endl; 
        }else{
            std::cout << "NO EXISTE EL DISCO :P" << std::endl; 
        }
        //std::cout << "El disco ha sido eliminado" << std::endl;
    }else{
        std::cout << "La operación ha sido cancelada!" << std::endl;
    }
    
}
