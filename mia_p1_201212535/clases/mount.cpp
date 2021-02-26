#include "mount.h"

using namespace std;
mount::mount(string parametros[])
{
    this->ruta = quitarComillasTexto(parametros[0]);
    this->nombre = quitarComillasTexto(parametros[1]);
    
}

void mount::ejecutar(){    
    verificarDiscoyParticion();
    validarExisteRegistro();
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

void mount::montarParticion(){
    extern int auxDisco;
    
}

void mount::validarExisteRegistro(){
    extern vector<Disco> registro;
    string ident;
    string digitoCarnet = "35";
    char idPart = 'a';
    


    if(registro.size() != 0){
        for(int i = 0; i < registro.size(); i++){
            if(registro[i].ruta == quitarComillasTexto(this->ruta)){
                Particion auxVector;
                cout << "char: " << registro[i].particiones.size() << endl;
                idPart = static_cast<char>(idPart + registro[i].particiones.size());               
                ident = digitoCarnet+to_string(i+1)+idPart;
                auxVector.id = ident;
                auxVector.nombre = quitarComillasTexto(this->nombre);
                registro[i].particiones.push_back(auxVector);
                cout << "Exito: Particion Montada" << endl;
                break;
            }
        }
    }
}

void mount::verificarDiscoyParticion(){
    extern vector<Disco> registro;
    extern int auxDiscoID;

    int idDisco = auxDiscoID;
    string ruta = quitarComillasTexto(this->ruta);

    FILE *arch;
    MBR mbr;
    arch = fopen(this->ruta.c_str(), "rb");
    if(arch != NULL){
         fseek(arch,0,SEEK_SET);
         fread(&mbr, sizeof(MBR), 1, arch);
         for(int i = 0; i < 4; i++){
             //cout << this->nombre << " --- " << mbr.mbr_partition[i].part_name << endl;
             if(quitarComillasTexto(toLower(mbr.mbr_partition[i].part_name)) == quitarComillasTexto(toLower(this->nombre))){
                for(int j = 0; j < registro.size(); j++){
                    if(registro[j].ruta == ruta){
                        return;
                    }
                }
                cout << "Partición encontrada" << endl;
                Disco auxDisco;
                auxDisco.id = idDisco;
                auxDisco.ruta = ruta;                
                registro.push_back(auxDisco);
                auxDiscoID++;
                break;
             }else{
                 
             }
             //cout << "ERROR_MOUNT#002: La particion no existe! :(" << endl;
         }
         fclose;
    }else{
        cout << "ERROR_MOUNT#001: El disco no existe! :(" << endl;
    }
}