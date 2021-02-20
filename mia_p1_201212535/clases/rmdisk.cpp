#include "rmdisk.h"

rmdisk::rmdisk()
{

}

void rmdisk::eliminarDisco(std::string ruta){
    char respuesta[1];
    QTextStream entrada(stdin);
    std::cout << "¿Estas seguro de eliminar el disco? Y/N " << std::endl;
    entrada >> respuesta;

    if(respuesta[0] == 'Y' || respuesta[0] == 'y'){
        if(!remove(quitarComillasRuta(ruta).c_str())){
            std::cout << "DISCO ELIMINADO! X_X" << std::endl; 
        }else{
            std::cout << "NO EXISTE EL DISCO :P" << std::endl; 
        }
        //std::cout << "El disco ha sido eliminado" << std::endl;
    }else{
        std::cout << "La operación ha sido cancelada!" << std::endl;
    }
    
}
