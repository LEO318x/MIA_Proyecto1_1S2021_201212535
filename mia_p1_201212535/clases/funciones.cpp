#include "funciones.h"
using namespace std;

string quitarComillasRuta(string ruta){
    string rutaAux = ruta;
    //Eliminamos las comillas de la ruta
    rutaAux.erase(remove(rutaAux.begin(), rutaAux.end(), '\"'), rutaAux.end());

    return rutaAux;
}

string quitarComillasTexto(string texto){
    string textoAux = texto;
    //Eliminamos las comillas del texto
    textoAux.erase(remove(textoAux.begin(), textoAux.end(), '\"'), textoAux.end());

    return textoAux;
}

string obtenerRutaSinArchivo(string ruta){
    string rutaAux = quitarComillasRuta(ruta);
    string rutaSinNombreArchivo;

    size_t i = rutaAux.rfind("/", rutaAux.length());
    if (i != string::npos) {
        rutaSinNombreArchivo = (rutaAux.substr(0, i+1));
    }

    return rutaSinNombreArchivo;
}

string extraerNombreArchivo(string ruta){
    string rutaAux = quitarComillasRuta(ruta);
    string nombreArchivo;
    const size_t buscarUltimoSlash = rutaAux.find_last_of("\\/");
    if (string::npos != buscarUltimoSlash)
    {
        rutaAux.erase(0, buscarUltimoSlash + 1);
    }
    nombreArchivo = rutaAux;

    return nombreArchivo;
}

string toLower(string cadena){
    for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::tolower(c);
    });
    return cadena;
}

string toUpper(string cadena){
    for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::toupper(c);
    });
    return cadena;
}

string obtenerFechaHora(){
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

bool verificarParticionID(string id){
    bool verificacion = false;

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
                        verificacion = true;
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
    return verificacion;
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

superbloque obtenerSuperBloque(Partition particion, string id){
    superbloque sb;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb+");
    if(disco != NULL){
       fseek(disco,particion.part_start,SEEK_SET); 
       fread(&sb, sizeof(superbloque), 1, disco);
       fclose(disco); 
    }
    return sb;
}

string obtenerRutaID(string id){
string ruta;
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

int buscarIndiceInodo(inodo ino, string nombre, string id){
bloqueCarpeta bc;

   for(int i = 0; i < 12; i++){
        if(ino.i_block[i] != -1){
            bc = obtenerBloqueCarpeta(id, ino.i_block[i]);
            for(int j = 0; j < 4; j++){
                if(bc.b_content[j].b_inodo != -1){
                    cout << "Nombreb: " << bc.b_content[j].b_name << endl;
                    cout << "Nombreb_: " << nombre << endl;
                    if(bc.b_content[j].b_name == nombre){
                        return bc.b_content[j].b_inodo; //retorno el indice del nodo :)
                    }
                }
            }
        }
    }
    return -1;
}

bloqueCarpeta obtenerBloqueCarpeta(string id, int indiceBloque){
    Partition part = obtenerParticionID(id);
    superbloque sb = obtenerSuperBloque(part, id);
    int inicioBloque = sb.s_block_start;
    int bloquePos = inicioBloque + indiceBloque*sizeof(bloqueCarpeta);
    bloqueCarpeta bc;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    if(disco != NULL){
        fseek(disco, bloquePos, SEEK_SET);
        fread(&bc, sizeof(bloqueCarpeta), 1, disco);        
        fclose(disco);
    }
    return bc;
}

bloqueArchivo obtenerBloqueArchivo(string id, int indiceBloqueArch){
    Partition part = obtenerParticionID(id);
    superbloque sb = obtenerSuperBloque(part, id);
    int inicioBloque = sb.s_block_start;
    int bloquePos = inicioBloque + indiceBloqueArch*sizeof(bloqueArchivo);
    bloqueArchivo ba;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    if(disco != NULL){
        fseek(disco, bloquePos, SEEK_SET);
        fread(&ba, sizeof(bloqueArchivo), 1, disco);        
        fclose(disco);
    }
    return ba;
}


bloqueArchivo buscarIno(string ruta, string id){
 Partition part = obtenerParticionID(id);
 superbloque sb = obtenerSuperBloque(part, id);
 int inicioInodo = sb.s_inode_start;
 vector<string> rutaPam = split(quitarComillasRuta(ruta), "/");
 inodo ino;
 int indiceInodo;

 bloqueArchivo ba;

    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    if(disco != NULL){
        fseek(disco, inicioInodo, SEEK_SET);
        fread(&ino, sizeof(inodo), 1, disco);

        for(int i = 1; i < rutaPam.size(); i++){
           indiceInodo = buscarIndiceInodo(ino, rutaPam[i].c_str(), id);
           if(indiceInodo == -1){cout << "ERROR_FUNC: No existe la data" << endl; break;}
           fseek(disco, inicioInodo+(indiceInodo*sizeof(inodo)), SEEK_SET);
           fread(&ino, sizeof(inodo), 1, disco);
        }

        //Separar luego en otro método
        for(int i = 0; i < 12; i++){
            if(ino.i_block[i] != -1){
                ba = obtenerBloqueArchivo(id, ino.i_block[i]);
                break;
            }
        }        
    }
    fclose(disco);
    return ba;
}

void escribirJournal(journal jlEscribir, string idPart){
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

void obtenerDatosUsuario(string id){
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

vector<string> split(string cadena, string limitador){
    vector<string> v;
    size_t pos = 0;
    string token;
    while ((pos = cadena.find(limitador)) != string::npos) {
        token = cadena.substr(0, pos);
        v.push_back(token);
        cadena.erase(0, pos + limitador.length());
    }
    v.push_back(cadena);
    return v;
}

void crearCarpetaReporte(string ruta){
    if (mkdir(obtenerRutaSinArchivo(ruta).c_str(), 0777) == -1){ 
            //std::cerr << "Error :  " << strerror(errno) << std::endl; 
    
    }
        chmod(obtenerRutaSinArchivo(ruta).c_str(), 0777);
        /*//Creamos el archivo
        FILE *fichero;
        fichero = fopen(quitarComillasRuta(ruta).c_str(),"w+b");
        //if (!fichero)
        //perror("fopen");            
        fclose(fichero);*/
}

MBR obtenerMbr(string ruta){
    MBR mbr;
    FILE *arch;
    arch = fopen(ruta.c_str(), "rb+");
    if(arch != NULL){
        fseek(arch,0,SEEK_SET);
        fread(&mbr, sizeof(MBR), 1, arch);
        fclose(arch);        
    }else{
        printf("Error!\n No se puede acceder al disco\n");
    }
    return mbr;
}
