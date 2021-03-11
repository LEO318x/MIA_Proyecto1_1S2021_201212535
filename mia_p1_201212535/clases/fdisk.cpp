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
    int tamanio;
    bool verificacion = true;

    try{    
        tamanio = stoi(this->size);
    }
    catch(exception e){
        tamanio = 0;
    }

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

    
    if (this->pPrimero == "add"){

    }else if(this->pPrimero == "delete"){
        // Validaciones Eliminar
        if(this->name == "" || this->path == ""){
            cout << "ERROR: Faltan parametros para ejecutar -delete (path, name)?" << endl;
            return verificacion = false;
        }
        if((toLower(this->_delete).compare("fast") != 0) && (toLower(this->_delete).compare("full") != 0)){
            cout << "#######---------> " << toLower(this->_delete).compare("fast") << endl;
            cout << "ERROR: El parametro -delete tiene un valor no válido" << endl;
            return verificacion = false;
        }
        //Eliminar Particion
        eliminarParticion();
    }else if(this->pPrimero == "size"){
        //Crear Particion
        crearParticion();
    }

    /*if(tamanio <= 0){
        cout << "ERROR: El tamaño no puede ser 0 o menor que 0, intenta de nuevo" << endl;
        return verificacion=false;
    }*/
    

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


    for(int i = 0; i < 4; i++){
        //Verificamos si ya existe el nombre
        if(toLower(mbr.mbr_partition[i].part_name) == toLower(this->name)){
            cout << "--Nombre:" << mbr.mbr_partition[i].part_name << endl;
            cout << "---Nombre:" << this->name << endl;
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


    //Ajuste
    if(this->pF == 'F'){
        cout << "Espacios Vacios: " << vES.size() << endl;
        /*for(int i = 0; i < vES.size(); i++){
            cout << "inicio" << vES[i].inicio << "tamanaio" << vES[i].tamanio;
        }*/

        if(!vES.empty()){
            for(int i = 0; i < vES.size(); i++){
                for(int j = 0; j < 4; j++){
                    if(mbr.mbr_partition[j].part_status == '0'){
                        if(stoi(this->size) <= vES[i].tamanio){
                            mbr.mbr_partition[j].part_status = '1';
                            mbr.mbr_partition[j].part_type = this->pType;
                            mbr.mbr_partition[j].part_fit = this->pF;
                            mbr.mbr_partition[j].part_start = vES[i].inicio;
                            mbr.mbr_partition[j].part_size = stoi(this->size);
                            strcpy(mbr.mbr_partition[j].part_name, this->name.c_str());
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&mbr, sizeof(MBR), 1, archivo);
                            fclose(archivo);
                            //testEspacioDisco(mbr.mbr_partition[j].part_start, mbr.mbr_partition[j].part_size, this->path, '1');
                            cout << "EXITO: La partición se ha creado!" << endl;
                            break;
                        }
                    }
                }
            }
        }

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

void fdisk::eliminarParticion(){
    FILE *disco;
    disco = fopen(quitarComillasRuta(this->path).c_str(), "rb+");
    if(disco != NULL){
        MBR mbr;
        Partition particionVacia;

        fseek(disco, 0, SEEK_SET);
        fread(&mbr, sizeof(MBR), 1, disco);
        
        char buffer = '\0';
        for(int i = 0; i < 4; i++){
            if(toLower(quitarComillasTexto(this->name)) == toLower(quitarComillasTexto(mbr.mbr_partition[i].part_name))){
                string nVacio = "";
                if(toLower(this->_delete) == "fast"){    
                    cout << "Eliminando Partición en modo FAST!" << endl;
                    particionVacia.part_status = '0';
                    strncpy(particionVacia.part_name,nVacio.c_str(),sizeof(nVacio));
                    particionVacia.part_size = 0;
                    particionVacia.part_start = 0;
                    particionVacia.part_type = '\0';                       
                    mbr.mbr_partition[i] = particionVacia;
                }else if(toLower(this->_delete) == "full"){
                    cout << "Eliminando Partición en modo FULL!" << to_string(mbr.mbr_partition[i].part_size) << endl;
                    fseek(disco, mbr.mbr_partition[i].part_start, SEEK_SET);
                    for(int j = 0; j < mbr.mbr_partition[i].part_size; j++){
                        fwrite(&buffer, sizeof(buffer), 1, disco);
                    }
                    particionVacia.part_status = '0';
                    strncpy(particionVacia.part_name,nVacio.c_str(),sizeof(nVacio));
                    particionVacia.part_size = 0;
                    particionVacia.part_start = 0;
                    particionVacia.part_type = '\0';
                    mbr.mbr_partition[i] = particionVacia;
                }
                cout << "EXITO: Particion Eliminada" << endl;
                break; 
            }else{
                cout << "ERROR: La partición que deseas eliminar no existe" << endl;
            }
        }
        fseek(disco, 0, SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, disco);
        fclose(disco); 
              
    }else{
        cout << "ERROR: No existe el disco" << endl;
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
