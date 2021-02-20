#include "fdisk.h"

using namespace std;


// 0 = size, 1 = u, 2 = path, 3 = type, 4 = f, 5 = delete, 6 = name, 7 = add
fdisk::fdisk(string parametros[]){
    this->size = parametros[0];
    this->u = parametros[1];
    this->path = parametros[2];
    this->type = parametros[3];
    this->f = parametros[4];
    this->_delete = parametros[5];
    this->name = parametros[6];
    this->add = parametros[7];

}

void fdisk::test(){
    //cout << stoi(this->add) << endl;
    infoDisco();
    //crearParticion();
}


void fdisk::validarParametros(){
    FILE *archivo;    

    if(this->u == ""){
        this->pU = 'k';
    }else if(toLower(this->u) == "b"){
        this->pU = 'b';
    }else if(toLower(this->u) == "k"){
        this->pU = 'k';
    }else if(toLower(this->u) == "m"){
        this->pU = 'm';
    }else{
        cout << "ERROR: Valor en el parametro -u incorrecta" << endl;
        return;
    }

    if(this->f == ""){
        this->pF = 'W';
    }else if(toLower(this->f) == "BF"){
        this->pF = 'B';
    }else if(toLower(this->f) == "FF"){
        this->pF = 'F';
    }else if(toLower(this->f) == "WF"){
        this->pF = 'W';
    }else{
        cout << "ERROR: Valor en el parametro -f incorrecta" << endl;
        return;
    }

    if(this->type == ""){
        this->pType = 'p';
    }else if(toLower(this->type) == "p"){
        this->pType = 'p';
    }else if(toLower(this->type) == "e"){
        this->pType = 'e';
    }else if(toLower(this->type) == "l"){
        this->pType = 'l';
    }else{
        cout << "ERROR: Valor en el parametro -type incorrecta" << endl;
        return;
    }

    if(this->path != "" || this->name != ""){
        cout << "ERROR: FALTA PARAMETRO OBLIGATORIO (size, path, name)?" << endl;
        return;
    }

    if(this->add != "" && this->_delete != ""){
        cout << "ERROR: OYE, OYE!, NO puedes ejecutar -add y -delete en la misma operación";
        return;
    }

    if(stoi(this->size) <= 0){
        cout << "ERROR: El tamaño no puede ser 0 o menor que 0, intenta de nuevo" << endl;
        return;
    }

    archivo = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    if(archivo == NULL){
        cout << "ERROR: El disco no existe! :'(" << endl;
        return;
    }
}

void fdisk::crearParticion(){

    int tamanioparticion;
    int unidad;
    validarParametros(); 

    FILE *archivo;
    fseek(archivo, 0, SEEK_SET);
    MBR mbr;
    fread(&mbr, sizeof(MBR), 1, archivo);
}

void fdisk::infoDisco(){
    
    FILE *disco;
    disco = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    if(disco != NULL){
        MBR mbr;
        fseek(disco, 0, SEEK_SET);
        fread(&mbr, sizeof(MBR), 1, disco);
        fclose(disco);
        std::cout << "\n#---- INFO DISCO ----#";
        std::cout << "\n# SIGNATURE: " << mbr.mbr_disk_signature;
        std::cout << "\n# TAMAÑO: " << mbr.mbr_tamano;
        std::cout << "\n# FIT: " << mbr.disk_fit;
        std::cout << "\n# FECHA CREACIÓN: " << mbr.mbr_fecha_creacion;
        std::cout << "\n#---- FIN DISCO ----#";
    }else{
        cout << "Disco no existe perro! >:'v" << endl;
        return;
    }
}


