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

void fdisk::ejecutarFdisk(){
    //cout << stoi(this->add) << endl;    
    validarParametros();
    infoDisco();
}


bool fdisk::validarParametros(){
    FILE *archivo;    
    int tamanio = stoi(this->size);
    bool verificacion = true;

    if(this->u == ""){
        this->pU = 'K';
        tamanio = tamanio * 1024;
    }else if(toUpper(this->u) == "B"){
        this->pU = 'B';
        tamanio = tamanio;
    }else if(toUpper(this->u) == "K"){
        this->pU = 'K';
        tamanio = tamanio * 1024;
    }else if(toUpper(this->u) == "M"){
        this->pU = 'M';
        tamanio = tamanio * 1024 * 1024;
    }else{
        cout << "ERROR: Valor en el parametro -u incorrecta" << endl;
        return verificacion=false;
    }
    this->size = to_string(tamanio);

    if(this->f == ""){
        this->pF = 'W';
    }else if(toUpper(this->f) == "BF"){
        this->pF = 'B';
    }else if(toUpper(this->f) == "FF"){
        this->pF = 'F';
    }else if(toUpper(this->f) == "WF"){
        this->pF = 'W';
    }else{
        cout << "ERROR: Valor en el parametro -f incorrecta" << endl;
        return verificacion=false;
    }

    if(this->type == ""){
        this->pType = 'P';
    }else if(toUpper(this->type) == "P"){
        this->pType = 'P';
    }else if(toUpper(this->type) == "E"){
        this->pType = 'E';
    }else if(toUpper(this->type) == "L"){
        this->pType = 'L';
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

    if (this->pPrimero == "add"){

    }else if(this->pPrimero == "delete"){
        // Validaciones Eliminar
        if(this->name == "" || this->path == ""){
            cout << "ERROR: Faltan parametros para ejecutar -delete (path, name)?" << endl;
            return verificacion = false;
        }
        if(toLower(this->_delete) != "fast" || toLower(this->_delete) != "full"){
            cout << "ERROR: El parametro -delete tiene un valor no válido" << endl;
            return verificacion = false;
        }
        //Eliminar Particion
        //eliminarParticion();
    }else if(this->pPrimero == "size"){
        //Crear Particion
        crearParticion();
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
    bool verificacion = true;
    FILE *archivo;
    archivo = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    fseek(archivo, 0, SEEK_SET);
    MBR mbr;
    fread(&mbr, sizeof(MBR), 1, archivo);


    for(int i = 0; i < 4; i++){
        //Verificamos si ya existe el nombre
        if(toLower(mbr.mbr_partition[i].part_name) == toLower(this->name)){
            cout << "ERROR: El nombre de la partición ya esta en uso, intenta de nuevo con otro nombre." << endl;
            verificacion = false;
            break;
        }
    }

    for (int i=0; i<4; i++){
        //Verificamos si ya existe una extendida.
        if(mbr.mbr_partition[i].part_type == 'E' && this->pType == 'E'){
            cout << "ERROR: Ya existe una partición extendida." << endl;
            verificacion = false;
            break;
        }
    }

    if (!verificacion){
        return;
    }
    
    int auxSuma = 0;
    int espacioLibre = 0;
    for(int i = 0; i < 4; i++){  

        auxSuma += mbr.mbr_partition[i].part_size;
        //Verificamos que haya alguna particion inactiva para crear la partición
        if(mbr.mbr_partition[i].part_status == '0'){
            
            // Verificamos que haya espacio suficiente antes de crear la partición
            espacioLibre = mbr.mbr_tamano - sizeof(MBR) - auxSuma - stoi(this->size);            
            cout << espacioLibre << endl;
            cout << "tamaño total: " << to_string(mbr.mbr_tamano) << endl;
            cout << "MBR: " << to_string(sizeof(MBR)) << endl;
            cout << "AuxSuma: " << to_string(auxSuma) << endl;
            cout << "tamaño particion: " << this->size << endl;
            if(espacioLibre < 0){
                cout << "ERROR: Espacio insuficiente" << endl;
                break;
            }
            mbr.mbr_partition[i].part_status = '1';
            mbr.mbr_partition[i].part_type = this->pType;
            mbr.mbr_partition[i].part_fit = this->pF;
            if(i != 0){
                mbr.mbr_partition[i].part_start = (mbr.mbr_partition[i-1].part_start+mbr.mbr_partition[i-1].part_size);
            }else{
                mbr.mbr_partition[i].part_start = sizeof(MBR);
            }
            mbr.mbr_partition[i].part_size = stoi(this->size);
            strcpy(mbr.mbr_partition[i].part_name, this->name.c_str());
            break;
        }else{
            
        }
    }
    
  
    fseek(archivo, 0, SEEK_SET);
    fwrite(&mbr, sizeof(MBR), 1, archivo);
    fclose(archivo);
    if(mbr.mbr_partition[0].part_status == '1'){
        cout << "entrooooooooooooooo a 1" << endl;
        testEspacioDisco(mbr.mbr_partition[0].part_start, mbr.mbr_partition[0].part_size, this->path, '1');
    }
    if(mbr.mbr_partition[1].part_status == '1'){
        cout << "entrooooooooooooooo a 2" << endl;
        testEspacioDisco(mbr.mbr_partition[1].part_start, mbr.mbr_partition[1].part_size, this->path, '2');
    }
    if(mbr.mbr_partition[2].part_status == '1'){
        cout << "entrooooooooooooooo a 2" << endl;
        testEspacioDisco(mbr.mbr_partition[2].part_start, mbr.mbr_partition[2].part_size, this->path, '3');
    }

    



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
        std::cout << "\n# AJUSTE: " << mbr.disk_fit;
        std::cout << "\n# FECHA CREACIÓN: " << mbr.mbr_fecha_creacion;
        std::cout << "\n#---- FIN DISCO ----#";
        std::cout << "\n\n\n";
        std::cout << "\n#---- INFO PARTICIONES ---#";
        for (int i = 0; i < 4 ; i++){
        std::cout << "\n#----> PARTICION <----"+std::to_string(i+1);
        std::cout << "\n# NOMBRE: " << mbr.mbr_partition[i].part_name;
        std::cout << "\n# ESTADO: " << mbr.mbr_partition[i].part_status;
        std::cout << "\n# TIPO: " << mbr.mbr_partition[i].part_type;
        std::cout << "\n# AJUSTE: " << mbr.mbr_partition[i].part_fit;
        std::cout << "\n# TAMAÑO: " << mbr.mbr_partition[i].part_size;
        std::cout << "\n# INICIA: " << mbr.mbr_partition[i].part_start;
        std::cout << "\n----> FIN PARTICION <----\n\n\n";
        }
        
    }else{
        cout << "Disco no existe perro! >:'v" << endl;
        return;
    }
}

void fdisk::testEspacioDisco(int inicia, int tamanio, string ruta, char buf){
    char buffer = buf;
    FILE *archivo;
    archivo = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    fseek(archivo, inicia, SEEK_SET);
    for(int i=0; i < tamanio; i++){
        fwrite(&buffer, sizeof(buffer), 1, archivo);
    }
    fclose(archivo);
}
