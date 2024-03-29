#include "unmount.h"

using namespace std;
unmount::unmount(string parametros[])
{
    this->id = parametros[0];
}

void unmount::ejecutar(){
    desmontar();
    mostrar();
}

void unmount::mostrar(){
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

void unmount::desmontar(){
extern vector<Disco> registro;
    bool verificacion = false;

    for(int i=0; i < registro.size(); i++){
            if(registro[i].particiones.size() != 0){
            for(int j = 0; j < registro[i].particiones.size(); j++){
                if(toLower(registro[i].particiones[j].id) == toLower(quitarComillasTexto(this->id))){
                    modificarFechaUnmount(this->id);
                    registro[i].particiones.erase(registro[i].particiones.begin()+j);
                    cout << "EXITO: Particion Desmontada" << endl;
                    break;
                }
                if(j == registro[i].particiones.size()-1){
                    cout << "ERROR: No existe el id" << endl;
                }
            }
        }else{
            cout << "ERROR: No existe el id" << endl;
        }
    }
    
}

void unmount::modificarFechaUnmount(string id){
    Partition part = obtenerParticionID(id);
    superbloque sb = obtenerSuperBloque(part, id);

    strcpy(sb.s_untime, obtenerFechaHora().c_str());

    FILE *disco;  
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb+");
    if(disco != NULL){
        fseek(disco, part.part_start, SEEK_SET);
        fwrite(&sb, sizeof(superbloque), 1, disco);
        fclose(disco);
    }

}
