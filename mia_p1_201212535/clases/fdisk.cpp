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
    this->pPrimero = parametros[8];

}

void fdisk::test(){
    //cout << stoi(this->add) << endl;    
    crearParticion();
    infoDisco();
}


bool fdisk::validarParametros(){
    FILE *archivo;    
    int tamanio = stoi(this->size);
    bool verificacion = true;

    if(this->u == ""){
        this->pU = 'k';
        tamanio = tamanio * 1024;
    }else if(toLower(this->u) == "b"){
        this->pU = 'b';
        tamanio = tamanio;
    }else if(toLower(this->u) == "k"){
        this->pU = 'k';
        tamanio = tamanio * 1024;
    }else if(toLower(this->u) == "m"){
        this->pU = 'm';
        tamanio = tamanio * 1024 * 1024;
    }else{
        cout << "ERROR: Valor en el parametro -u incorrecta" << endl;
        return verificacion=false;
    }
    this->size = to_string(tamanio);

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
        return verificacion=false;
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
        return verificacion=false;
    }

    if(this->path == "" || this->name == ""){
        cout << "ERROR: FALTA PARAMETRO OBLIGATORIO (path, name)?" << endl;
        return verificacion=false;
    }

    if(this->add != "" && this->_delete != ""){
        cout << "ERROR: OYE, OYE!, NO puedes ejecutar -add y -delete en la misma operación";
        return verificacion=false;
    }

    if(stoi(this->size) <= 0){
        cout << "ERROR: El tamaño no puede ser 0 o menor que 0, intenta de nuevo" << endl;
        return verificacion=false;
    }

    archivo = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    if(archivo == NULL){
        cout << "ERROR: El disco no existe!" << endl;
        return verificacion=false;
    }
    fclose(archivo);

    return verificacion;
}

void fdisk::crearParticion(){

    int tamanioparticion;
    int unidad;
    if(!validarParametros()){
        return;
    } 

    FILE *archivo;
    archivo = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    fseek(archivo, 0, SEEK_SET);
    MBR mbr;
    fread(&mbr, sizeof(MBR), 1, archivo);

    mbr.mbr_partition_1.part_status = '1';
    mbr.mbr_partition_1.part_type = this->pType;
    mbr.mbr_partition_1.part_fit = this->pF;
    mbr.mbr_partition_1.part_start = sizeof(MBR);
    mbr.mbr_partition_1.part_size = stoi(this->size);
    strcpy(mbr.mbr_partition_1.part_name, this->name.c_str());
    
    fseek(archivo, mbr.mbr_partition_1.part_start, SEEK_SET);
    fwrite(&mbr, sizeof(MBR), 1, archivo);
    fclose(archivo);
    


}

void fdisk::infoDisco(){
    
    cout << "primer parametro: " << this->pPrimero << endl;

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
        std::cout << "\n\n\n";
        std::cout << "\n#---- INFO PARTICIONES ---#";
        std::cout << "\n#--> PARTICION 1";
        std::cout << "\n# NOMBRE: " << mbr.mbr_partition_1.part_name;
        std::cout << "\n# ESTADO: " << mbr.mbr_partition_1.part_status;
        std::cout << "\n# TIPO: " << mbr.mbr_partition_1.part_type;
        std::cout << "\n# AJUSTE: " << mbr.mbr_partition_1.part_fit;
        std::cout << "\n# TAMAÑO: " << mbr.mbr_partition_1.part_size;
        std::cout << "\n# INICIA: " << mbr.mbr_partition_1.part_start;
    }else{
        cout << "Disco no existe perro! >:'v" << endl;
        return;
    }
}


