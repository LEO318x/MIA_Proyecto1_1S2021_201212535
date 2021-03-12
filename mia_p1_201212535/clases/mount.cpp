#include "mount.h"

using namespace std;
mount::mount(string parametros[])
{
    this->ruta = quitarComillasTexto(parametros[0]);
    this->nombre = quitarComillasTexto(parametros[1]);
    
}

void mount::ejecutar(){    
    //verificarDiscoyParticion();
    //validarExisteRegistro();
    //verificarExistenciaDiscoyParticion();
    //verificarDiscoMontado();

    if(verificarExistenciaDiscoyParticion()){
        if(verificarDiscoMontado()){
            if(!verificarParticion()){
                montarParticion();
            }
        }else{
            montarDisco();
            montarParticion();
        }
    }
    mostrarMount();
}

void mount::mostrarMount(){
    extern vector <Disco> registro;
    
    for(int i= 0; i < registro.size(); i++){
        cout << "|--> ID_DISCO: "  <<registro[i].id << " Ruta: " << registro[i].ruta << endl;

        for(int j=0; j < registro[i].particiones.size(); j++){
            vector <Particion> auxParticion;
            auxParticion = registro[i].particiones;
            cout << "   |--> ID_PARTICION: " << auxParticion[j].id << " Nombre: " << auxParticion[j].nombre << endl;
        }
    }    
}

bool mount::verificarExistenciaDiscoyParticion(){
    bool verificacion = false;

    string ruta = quitarComillasTexto(this->ruta);
    FILE *arch;
    MBR mbr;
    arch = fopen(this->ruta.c_str(), "rb");
    if(arch != NULL){
         fseek(arch,0,SEEK_SET);
         fread(&mbr, sizeof(MBR), 1, arch);

         for(int i = 0; i < 4; i++){
             if(quitarComillasTexto(toLower(mbr.mbr_partition[i].part_name)) == quitarComillasTexto(toLower(this->nombre))){
                cout << "|--> Partición encontrada" << endl;
                verificacion = true;                
                break;
             }
             if(i == 3){
                cout << "ERROR_MOUNT#002: La particion no existe! :(" << endl;
             }             
         }
         fclose(arch);
    }else{
        cout << "ERROR_MOUNT#001: El disco no existe! :(" << endl;
    }

    return verificacion;

}

bool mount::verificarDiscoMontado(){
   extern vector<Disco> registro;
    bool verificacion = false;
   if(registro.size() != 0){
        for(int i = 0; i < registro.size(); i++){
            string ruta = quitarComillasTexto(this->ruta);
            if(registro[i].ruta == ruta){
                verificacion = true;
                cout << "El disco esta montado :D" << endl;
                break;
            }
            if(i == registro.size() -1){
                cout << "ERROR_MOUNT#003: El disco no esta montado" << endl;
            }
        } 
   }else{
       cout << "ADVERTENCIA_MOUNT#001: El disco no esta montado, por lo cual se estará montando" << endl;
   }
   return verificacion;
   
}

bool mount::verificarParticion(){
    extern vector<Disco> registro;
    ruta = quitarComillasTexto(this->ruta);
    bool verificacion = false;
    for(int i=0; i < registro.size(); i++){
        if(registro[i].ruta == ruta){
            for(int j = 0; j < registro[i].particiones.size(); j++){
                if(toLower(registro[i].particiones[j].nombre) == toLower(quitarComillasTexto(this->nombre))){
                    cout << "ERROR_PARTICION#002: La partición ya se encuentra montada" << endl;
                    verificacion = true;
                    break;
                }
            }
        }
    }
    return verificacion;
}

void mount::montarDisco(){
    ruta = quitarComillasTexto(this->ruta);
    extern vector<Disco> registro;
    extern int auxDiscoID;

    Disco auxDisco;
    auxDisco.id = auxDiscoID;
    auxDisco.ruta = ruta;                
    registro.push_back(auxDisco);
    auxDiscoID++;

}

void mount::montarParticion(){
    extern vector<Disco> registro;
    ruta = quitarComillasTexto(this->ruta);
    string ident;
    string digitoCarnet = "35";
    char idPart = 'a';

    for(int i=0; i < registro.size(); i++){
        if(registro[i].ruta == ruta){
                Particion auxVector;
                cout << "char: " << registro[i].particiones.size() << endl;
                idPart = static_cast<char>(idPart + registro[i].particiones.size());               
                ident = digitoCarnet+to_string(i+1)+idPart;
                auxVector.id = ident;
                auxVector.nombre = quitarComillasTexto(this->nombre);
                registro[i].particiones.push_back(auxVector);
                modificarFechaMount(ident);
                cout << "Exito: Particion Montada :3" << endl; 
        }
    }
}

void mount::modificarFechaMount(string id){
    Partition part = obtenerParticionID(id);
    superbloque sb = obtenerSuperBloque(part, id);

    strcpy(sb.s_mtime, obtenerFechaHora().c_str());
    sb.s_mnt_count++;

    FILE *disco;  
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb+");
    if(disco != NULL){
        fseek(disco, part.part_start, SEEK_SET);
        fwrite(&sb, sizeof(superbloque), 1, disco);
        fclose(disco);
    }

}


