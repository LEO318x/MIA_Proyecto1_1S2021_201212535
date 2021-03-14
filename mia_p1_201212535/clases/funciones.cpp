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
    if(!verificarParticionID(id)){
        cout << "ERROR: No existe la partición!" << endl;
    }else{
        FILE *disco;
        disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb+");
        if(disco != NULL){
        fseek(disco,particion.part_start,SEEK_SET); 
        fread(&sb, sizeof(superbloque), 1, disco);
        fclose(disco); 
        }
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
                    //cout << "Nombreb: " << bc.b_content[j].b_name << endl;
                    //cout << "Nombreb_: " << nombre << endl;
                    if(bc.b_content[j].b_name == nombre){
                        return bc.b_content[j].b_inodo; //retorno el indice del nodo :)
                    }
                }
            }
        }
    }
    return -1;
}

inodo obtenerInodo(string id, int indInodo){
    Partition part = obtenerParticionID(id);
    superbloque sb = obtenerSuperBloque(part, id);
    int inicioInodo = sb.s_inode_start;
    inodo ind;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    if(disco != NULL){
        fseek(disco, inicioInodo+(indInodo*sizeof(inodo)), SEEK_SET);
        fread(&ind, sizeof(inodo), 1, disco);      
    }
    fclose(disco);
    return ind;
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
        printf("Error! No se puede acceder al disco\n");
    }
    return mbr;
}

string obtenerBitmapInodos(string idPart){
    string stringBitmap;
    if(!verificarParticionID(idPart)){
        cout << "ERROR: La partición no existe!" << endl;
    }else{
        Partition part = obtenerParticionID(idPart);
        superbloque sb;    
        FILE *disco;
        char buffer = '8';
        disco = fopen(quitarComillasRuta(obtenerRutaID(idPart)).c_str(), "rb+");
        fseek(disco,part.part_start,SEEK_SET); 
        fread(&sb, sizeof(superbloque), 1, disco);
        char bitmapInodos[sb.s_inodes_count];
        if(disco != NULL){
            /*fseek(disco,sb.s_bm_inode_start,SEEK_SET);
            fwrite(&buffer,sizeof(buffer),1,disco);
            fseek(disco,sb.s_bm_block_start-1,SEEK_SET);
            fwrite(&buffer,sizeof(buffer),1,disco);*/

            fseek(disco,sb.s_bm_inode_start,SEEK_SET);
            fread(&bitmapInodos, sb.s_inodes_count, 1, disco);        
            for(int i=0; i < sb.s_inodes_count; i++){
                stringBitmap += bitmapInodos[i];
            }
        fclose(disco); 
        }
    }
    return stringBitmap;    
}

string obtenerBitmapBloques(string idPart){

    string stringBloques;
    if(!verificarParticionID(idPart)){
        cout << "ERROR: La partición no existe!" << endl;        
    }else{
    Partition part = obtenerParticionID(idPart);
    superbloque sb;    
    FILE *disco;
    char buffer = '9';
    disco = fopen(quitarComillasRuta(obtenerRutaID(idPart)).c_str(), "rb+");
    fseek(disco,part.part_start,SEEK_SET); 
    fread(&sb, sizeof(superbloque), 1, disco);
    char bitmapBloques[sb.s_blocks_count];
        if(disco != NULL){
            /*fseek(disco,sb.s_bm_block_start,SEEK_SET);
            fwrite(&buffer,sizeof(buffer),1,disco);
            fseek(disco,sb.s_bm_block_start-1,SEEK_SET);
            fwrite(&buffer,sizeof(buffer),1,disco);*/
            fseek(disco,sb.s_bm_block_start,SEEK_SET);
            fread(&bitmapBloques, sb.s_blocks_count, 1, disco);        
            for(int i=0; i < sb.s_blocks_count; i++){
                stringBloques += bitmapBloques[i];
            }
        fclose(disco); 
        }
    }
    return stringBloques; 
}

vector<espacioLibre> obtenerEspacioLibreDisco(string ruta){
    FILE *archivo;
    archivo = fopen(quitarComillasRuta(ruta).c_str(), "rb+");
    fseek(archivo, 0, SEEK_SET);
    MBR mbr;
    fread(&mbr, sizeof(MBR), 1, archivo);

    vector<Partition> particionActiva;
    vector<Partition> particionAux;
    for (int i = 0; i < 4; i++){
        if(mbr.mbr_partition[i].part_status != '0'){
            particionActiva.push_back(mbr.mbr_partition[i]);
        }
    }

    vector<int> ordenStart;
    for (int i = 0; i < particionActiva.size(); i++){
        ordenStart.push_back(particionActiva[i].part_start);
    }

    sort(ordenStart.begin(), ordenStart.end());
    
    for(int i = 0; i < ordenStart.size(); i++){
        int auxs;
        auxs = ordenStart[i];
        for(int j = 0; j < particionActiva.size(); j++){
            if(particionActiva[j].part_start == auxs){
                particionAux.push_back(particionActiva[j]);
            }
        }
    }

    //Espacios Vacios
    int inicioVacio = sizeof(MBR);
    vector<espacioLibre> vES;
    //for(int i = 0; i < particionAux.size(); i++){
    int tamanio;
    for(int i = 0; i < particionAux.size(); i++){
        espacioLibre espacioVacio; 
        tamanio = particionAux[i].part_start - inicioVacio;
        if(tamanio > 0){
            espacioVacio.inicio = inicioVacio;
            espacioVacio.tamanio = tamanio;
            vES.push_back(espacioVacio);
        }
        inicioVacio =  particionAux[i].part_start + particionAux[i].part_size; 
    }
        espacioLibre espacioVacio; 
        tamanio = mbr.mbr_tamano - inicioVacio;
        if(tamanio > 0){
            espacioVacio.inicio = inicioVacio;
            espacioVacio.tamanio = tamanio;
            vES.push_back(espacioVacio);
        }

    fclose(archivo);
    return vES;
}

int buscarIndiceRuta(inodo ino, string nombre, string id){
bloqueCarpeta bc;
string rutaNoexiste;
   for(int i = 0; i < 12; i++){
        if(ino.i_block[i] != -1){
            bc = obtenerBloqueCarpeta(id, ino.i_block[i]);
            for(int j = 0; j < 4; j++){
                if(bc.b_content[j].b_inodo != -1){
                    //cout << "Nombreeee: " << nombre << endl;
                    //cout << "Nombreeee: " << bc.b_content[j].b_name << endl;
                    if(bc.b_content[j].b_name == nombre || nombre.empty()){
                        return bc.b_content[j].b_inodo; //retorno el indice del nodo :)
                        break;
                    }
                }
            }
        }
    }
    return -1;
}

void buscarRuta(string id, string ruta){
 Partition part = obtenerParticionID(id);
 superbloque sb = obtenerSuperBloque(part, id);
 int inicioInodo = sb.s_inode_start;
 vector<string> rutaPam = split(quitarComillasRuta(ruta), "/");
 inodo ino;
 int indiceInodo;
 vector <string> vRuta;
 bloqueArchivo ba;

    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    if(disco != NULL){
        fseek(disco, inicioInodo, SEEK_SET);
        fread(&ino, sizeof(inodo), 1, disco);

        for(int i = 1; i < rutaPam.size(); i++){
           indiceInodo = buscarIndiceRuta(ino, rutaPam[i].c_str(), id);
           
           if(indiceInodo == -1){
                vRuta.push_back(rutaPam[i].c_str());
                //break;
            }else{
                cout << "A partir de: " << indiceInodo << endl;
            }
           //fseek(disco, inicioInodo+(indiceInodo*sizeof(inodo)), SEEK_SET);
           //fread(&ino, sizeof(inodo), 1, disco);
           //cout << "IndiceInodo" << indiceInodo << endl;
        }
    }

    fclose(disco);
}



