#include "funciones.h"

std::string quitarComillasRuta(std::string ruta){
    std::string rutaAux = ruta;
    //Eliminamos las comillas de la ruta
    rutaAux.erase(remove(rutaAux.begin(), rutaAux.end(), '\"'), rutaAux.end());

    return rutaAux;
}

std::string quitarComillasTexto(std::string texto){
    std::string textoAux = texto;
    //Eliminamos las comillas del texto
    textoAux.erase(remove(textoAux.begin(), textoAux.end(), '\"'), textoAux.end());

    return textoAux;
}

std::string obtenerRutaSinArchivo(std::string ruta){
    std::string rutaAux = quitarComillasRuta(ruta);
    std::string rutaSinNombreArchivo;

    size_t i = rutaAux.rfind("/", rutaAux.length());
    if (i != std::string::npos) {
        rutaSinNombreArchivo = (rutaAux.substr(0, i+1));
    }

    return rutaSinNombreArchivo;
}

std::string extraerNombreArchivo(std::string ruta){
    std::string rutaAux = quitarComillasRuta(ruta);
    std::string nombreArchivo;
    const size_t buscarUltimoSlash = rutaAux.find_last_of("\\/");
    if (std::string::npos != buscarUltimoSlash)
    {
        rutaAux.erase(0, buscarUltimoSlash + 1);
    }
    nombreArchivo = rutaAux;

    return nombreArchivo;
}

std::string toLower(std::string cadena){
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::tolower(c);
    });
    return cadena;
}

std::string toUpper(std::string cadena){
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::toupper(c);
    });
    return cadena;
}

std::string obtenerFechaHora(){
    time_t rawtime;
    struct tm * timeinfo;
    char fechaHora [18];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(fechaHora,18,"%d/%m/%y %H:%M:%S",timeinfo);

    return fechaHora;
}

int obtenerNumeroRandom(){
    int numero;
    srand(time(0));
    numero = rand();

    return numero;
}

Partition obtenerParticionID(string id){
Partition particion;
extern vector<Disco> registro;
    for(int i=0; i < registro.size(); i++){
        for(int j=0; j < registro[i].particiones.size(); j++){
            if(registro[i].particiones[j].id == id){
                //cout << "EXITO: Particion encontrada con el id " << id << endl;
                //cout << "RUTA: " << registro[i].ruta << endl;
                FILE *arch;
                MBR mbr;
                arch = fopen(quitarComillasRuta(registro[i].ruta).c_str(), "rb");
                if(arch != NULL){
                    fseek(arch,0,SEEK_SET);
                    fread(&mbr, sizeof(MBR), 1, arch);
                }
                for(int k = 0; k < 4; k++){
                    if(quitarComillasTexto(toLower(mbr.mbr_partition[k].part_name)) == quitarComillasTexto(toLower(registro[i].particiones[j].nombre))){
                        //cout << "|--> Partición encontrada :DDDDDDD" << endl;
                        particion = mbr.mbr_partition[k];
                        break;
                    }
                    if(i == 3){
                        cout << "ERROR_FUNC#001: La particion no existe! :(" << endl;
                    }             
                }
                fclose;
                break;
            }
        }
    }
    return particion;
}




