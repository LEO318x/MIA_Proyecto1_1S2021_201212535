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
    char fechaHora [16];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(fechaHora,16,"%d/%m/%y %H:%M",timeinfo);

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
                fclose(arch);
                break;
            }
        }
    }
    return particion;
}

std::string obtenerRutaID(std::string id){
std::string ruta;
extern vector<Disco> registro;
    for(int i=0; i < registro.size(); i++){
        for(int j=0; j < registro[i].particiones.size(); j++){
            if(registro[i].particiones[j].id == id){
                ruta = registro[i].ruta;
            }
        }
    }
    return ruta;
}

 int obtenerPosicionInodo(int inicioInodo, int indiceInodo){
        int pos = inicioInodo + (indiceInodo*sizeof(inodo));
        return pos;
    }

void escribirJournal(journal jlEscribir, std::string idPart){
    Partition part = obtenerParticionID(idPart);
    FILE *disco;
    journal jl;    
    disco = fopen(quitarComillasRuta(obtenerRutaID(idPart)).c_str(), "rb+");
    if(disco != NULL){
        int inicioJournal = part.part_start + sizeof(superbloque);
        fseek(disco, inicioJournal, SEEK_SET);
        fread(&jl, sizeof(journal), 1, disco);
        int journalIndice = part.part_start + sizeof(superbloque) + (jl.j_permisos * sizeof(journal));
        jl.j_permisos = jl.j_permisos + 1;
        fseek(disco, inicioJournal, SEEK_SET);
        fwrite(&jl, sizeof(journal), 1, disco);
        fseek(disco, journalIndice, SEEK_SET);
        fwrite(&jlEscribir, sizeof(journal), 1, disco);
        }    
    fclose(disco);    
}

void obtenerDatosUsuario(std::string id){
    Partition part = obtenerParticionID(id);
    FILE *disco;
    superbloque sb;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb+");
    if(disco != NULL){
        fseek(disco,part.part_start,SEEK_SET); 
        fread(&sb, sizeof(superbloque), 1, disco);        
    }
    fclose(disco);
}

std::vector<std::string> split(std::string cadena, std::string limitador){
    std::vector<std::string> v;
    size_t pos = 0;
    std::string token;
    while ((pos = cadena.find(limitador)) != std::string::npos) {
        token = cadena.substr(0, pos);
        v.push_back(token);
        cadena.erase(0, pos + limitador.length());
    }
    v.push_back(cadena);
    return v;
}


