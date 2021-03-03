#include "mkfs.h"


using namespace std;
mkfs::mkfs(string parametros[])
{
    this->id = toLower(parametros[0]);
    this->type = toLower(parametros[1]);
    this->fs = toLower(parametros[2]);
}

void mkfs::ejecutar(){    
     //cout << "Parametros: " << this->id << " " << this->type << " " << this->fs << endl;
    if(validarParametros()){
        cout << "Todo correcto! :D" << endl;
        superbloque sb;
        Partition part = obtenerParticionID(this->id);
        sb.s_filesystem_type = int(this->fs[0])-48;
        if(this->fs == "2fs"){
            cout << "---------------2FS---------------" << endl;
            sb.s_inodes_count = obtenerN(part.part_size, 0);
            sb.s_blocks_count = 3*obtenerN(part.part_size, 0);
            sb.s_free_blocks_count = 3*obtenerN(part.part_size, 0);
            sb.s_free_inodes_count = obtenerN(part.part_size, 0);
            sb.s_bm_inode_start = sizeof(superbloque);
            sb.s_bm_block_start = sizeof(superbloque)+obtenerN(part.part_size, 0);
            sb.s_inode_start = sizeof(superbloque)+4*obtenerN(part.part_size, 0);
            sb.s_block_start = sizeof(superbloque)+(obtenerN(part.part_size, 0)*sizeof(inodo))+4*obtenerN(part.part_size, 0);
            cout << "\nTotal de inodos: " << sb.s_inodes_count << endl;
            cout << "\nTotal de bloques: " << sb.s_blocks_count << endl;
            cout << "\nBloques Libres: " << sb.s_blocks_count << endl;
            cout << "\nInodos Libres: " << sb.s_free_inodes_count << endl;
            cout << "\nInicio Bitmap Inodos: " << sb.s_bm_inode_start << endl;
            cout << "\nInicio Bitmap Bloques: " << sb.s_bm_block_start << endl;
            cout << "\nInicio Inodo: " << sb.s_inode_start << endl;
            cout << "\nInicio Bloque: " << sb.s_block_start << endl;

        }else if(this -> fs == "3fs"){
            cout << "---------------3FS---------------" << endl;
            sb.s_inodes_count = obtenerN(part.part_size, 0);
            sb.s_blocks_count = 3*obtenerN(part.part_size, 0);
            sb.s_free_blocks_count = 3*obtenerN(part.part_size, 0);
            sb.s_free_inodes_count = obtenerN(part.part_size, 0);
            sb.s_bm_inode_start = sizeof(superbloque) + sizeof(journal);
            sb.s_bm_block_start = sizeof(superbloque)+obtenerN(part.part_size, sizeof(journal));
            sb.s_inode_start = sizeof(superbloque)+4*obtenerN(part.part_size, sizeof(journal));
            sb.s_block_start = sizeof(superbloque)+(obtenerN(part.part_size, 0)*sizeof(inodo))+4*obtenerN(part.part_size, sizeof(journal));
            /*cout << "\nTotal de inodos: " << sb.s_inodes_count << endl;
            cout << "\nTotal de bloques: " << sb.s_blocks_count << endl;
            cout << "\nBloques Libres: " << sb.s_blocks_count << endl;
            cout << "\nInodos Libres: " << sb.s_free_inodes_count << endl;
            cout << "\nInicio Bitmap Inodos: " << sb.s_bm_inode_start << endl;
            cout << "\nInicio Bitmap Bloques: " << sb.s_bm_block_start << endl;
            cout << "\nInicio Inodo: " << sb.s_inode_start << endl;
            cout << "\nInicio Bloque: " << sb.s_block_start << endl;*/

        }
        strcpy(sb.s_mtime, obtenerFechaHora().c_str());
        sb.s_mnt_count = 1;
        sb.s_inode_size = sizeof(inodo);
        //cout << "\nTamaño Inodo: " << sb.s_inode_size << endl;
        sb.s_block_size = 64;
        sb.s_first_ino = 0;
        sb.s_first_blo = 0;
        formatear(sb); 
        leerSuperBloque();  
    }  
    //pesoEstructuras();
}

bool mkfs::validarParametros(){
    bool validacion = true;
    if (this->type == "") this->type = "full";
    if (this->fs == "") this->fs = "2fs";


    if(this->type != "fast" && this->type != "full"){
        validacion = false;
        cout << "ERROR_MKFS#001: Valor incorrecto en el parametro -type" << endl;
    }

    if(this->fs != "2fs" && this->fs != "3fs"){
        validacion = false;
        cout << "ERROR_MKFS#002: Valor incorrecto en el parametro -fs" << endl;
    }

    if(!buscarID()){
        cout << "ERROR_MKFS#003: No existe la partción con el id " << this->id << " ¿Se encuentra montada la particion?" << endl;
        validacion = false;
    }

    return validacion;
}

/*Partition part = obtenerParticionID(this->id);
cout << "Empieza: " << to_string(part.part_start) << endl;
cout << "Tamanio: " << to_string(part.part_size) << endl;*/

bool mkfs::buscarID(){
    bool verificacion = false;
    extern vector<Disco> registro;
    for(int i=0; i < registro.size(); i++){
        for(int j=0; j < registro[i].particiones.size(); j++){
            if(registro[i].particiones[j].id == this->id){
                verificacion = true;
                cout << "EXITO: Particion encontrada con el id " << this->id << endl;
                break;
            }
        }
    }
    return verificacion;
}

void mkfs::pesoEstructuras(){

    cout << "Superbloque: " << sizeof(superbloque) << endl;
    cout << "Inodo: " << sizeof(inodo) << endl;
    cout << "Contenido: " << sizeof(carpeta) << endl;
    cout << "Carpeta: " << sizeof(bloqueCarpeta) << endl;
    cout << "Archivo: " << sizeof(archivo) << endl;
    cout << "Apuntador: " << sizeof(apuntador) << endl;
    cout << "Journal: " << sizeof(journal) << endl;
    
}

int mkfs::obtenerN(int tamanioParticion, int journal){
    int n;
    n = floor((tamanioParticion - sizeof(superbloque))/(4+journal+sizeof(inodo)+(3*64))); 
    return n;
}

void mkfs::formatear(superbloque sb){
    Partition part = obtenerParticionID(this->id);
    FILE *disco;
    //superbloque sb;
    disco = fopen(quitarComillasRuta(obtenerRutaID(this->id)).c_str(), "rb+");
    char buffer = '\0';
    if(disco != NULL){
        fseek(disco,part.part_start,SEEK_SET);
        if(this->type == "full"){
            for(int i=0; i < part.part_size; i++){
                fwrite(&buffer, sizeof(buffer), 1, disco);
            }
        }
        fseek(disco,part.part_start,SEEK_SET);  
        fwrite(&sb, sizeof(superbloque), 1, disco);        
        fclose(disco);
    }
}

void mkfs::leerSuperBloque(){
    Partition part = obtenerParticionID(this->id);
    superbloque sb;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(this->id)).c_str(), "rb+");
    if(disco != NULL){
       fseek(disco,part.part_start,SEEK_SET); 
       fread(&sb, sizeof(superbloque), 1, disco);
       fclose; 
    }
    cout << "--------------LECTURA SUPERBLOQUE-------------" << endl;
    cout << "\nTotal de inodos: " << sb.s_inodes_count << endl;
    cout << "\nTotal de bloques: " << sb.s_blocks_count << endl;
    cout << "\nBloques Libres: " << sb.s_blocks_count << endl;
    cout << "\nInodos Libres: " << sb.s_free_inodes_count << endl;
    cout << "\nInicio Bitmap Inodos: " << sb.s_bm_inode_start << endl;
    cout << "\nInicio Bitmap Bloques: " << sb.s_bm_block_start << endl;
    cout << "\nInicio Inodo: " << sb.s_inode_start << endl;
    cout << "\nInicio Bloque: " << sb.s_block_start << endl;
}

