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
            sb.s_bm_inode_start = part.part_start+sizeof(superbloque);
            sb.s_bm_block_start = part.part_start+sizeof(superbloque)+obtenerN(part.part_size, 0);
            sb.s_inode_start = part.part_start+sizeof(superbloque)+4*obtenerN(part.part_size, 0);
            sb.s_block_start = part.part_start+sizeof(superbloque)+(obtenerN(part.part_size, 0)*sizeof(inodo))+4*obtenerN(part.part_size, 0);
            cout << "\nPart Start: " << part.part_start << endl;
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
            sb.s_inodes_count = obtenerN(part.part_size, sizeof(journal));
            sb.s_blocks_count = 3*obtenerN(part.part_size, sizeof(journal));
            sb.s_free_blocks_count = 3*obtenerN(part.part_size, sizeof(journal));
            sb.s_free_inodes_count = obtenerN(part.part_size, sizeof(journal));
            sb.s_bm_inode_start = part.part_start+sizeof(superbloque)+obtenerN(part.part_size, sizeof(journal))*sizeof(journal);
            sb.s_bm_block_start = part.part_start+sizeof(superbloque)+obtenerN(part.part_size, sizeof(journal))*sizeof(journal)+obtenerN(part.part_size, sizeof(journal));
            sb.s_inode_start = part.part_start+sizeof(superbloque)+obtenerN(part.part_size, sizeof(journal))*sizeof(journal)+obtenerN(part.part_size, sizeof(journal))+3*obtenerN(part.part_size, sizeof(journal));
            sb.s_block_start = part.part_start+sizeof(superbloque)+obtenerN(part.part_size, sizeof(journal))*sizeof(journal)+obtenerN(part.part_size, sizeof(journal))+3*obtenerN(part.part_size, sizeof(journal))+obtenerN(part.part_size, sizeof(journal))*sizeof(inodo);
            cout << "\nTotal de inodos: " << sb.s_inodes_count << endl;
            cout << "\nTotal de bloques: " << sb.s_blocks_count << endl;
            cout << "\nBloques Libres: " << sb.s_blocks_count << endl;
            cout << "\nInodos Libres: " << sb.s_free_inodes_count << endl;
            cout << "\nInicio Bitmap Inodos: " << sb.s_bm_inode_start << endl;
            cout << "\nInicio Bitmap Bloques: " << sb.s_bm_block_start << endl;
            cout << "\nInicio Inodo: " << sb.s_inode_start << endl;
            cout << "\nInicio Bloque: " << sb.s_block_start << endl;

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
        /*string xd = leerBitmapInodos();
        cout << "Bitmap Inodos: " << xd.size() << endl;
        cout << xd << endl;
        string xd2 = leerBitmapBloques();
        cout << "Bitmap Bloques: " <<  xd2.size() << endl;
        cout << xd2 << endl;*/
        quemarRoot();
        leerSuperBloque();
        //obtenerEspacioInodos();
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
    cout << "Archivo: " << sizeof(bloqueArchivo) << endl;
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
    char buffer = '0';
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
       fclose(disco); 
    }
    cout << "--------------LECTURA SUPERBLOQUE-------------" << endl;
    cout << "\nTotal de inodos: " << sb.s_inodes_count << endl;
    cout << "\nTotal de bloques: " << sb.s_blocks_count << endl;
    cout << "\nBloques Libres: " << sb.s_free_blocks_count << endl;
    cout << "\nInodos Libres: " << sb.s_free_inodes_count << endl;
    cout << "\nInicio Bitmap Inodos: " << sb.s_bm_inode_start << endl;
    cout << "\nInicio Bitmap Bloques: " << sb.s_bm_block_start << endl;
    cout << "\nInicio Inodo: " << sb.s_inode_start << endl;
    cout << "\nInicio Bloque: " << sb.s_block_start << endl;
}

string mkfs::leerBitmapInodos(){
    Partition part = obtenerParticionID(this->id);
    superbloque sb;    
    FILE *disco;
    string stringBitmap;
    char buffer = '8';
    disco = fopen(quitarComillasRuta(obtenerRutaID(this->id)).c_str(), "rb+");
    fseek(disco,part.part_start,SEEK_SET); 
    fread(&sb, sizeof(superbloque), 1, disco);
    char bitmapInodos[sb.s_inodes_count];
    if(disco != NULL){
        fseek(disco,sb.s_bm_inode_start,SEEK_SET);
        fwrite(&buffer,sizeof(buffer),1,disco);
        fseek(disco,sb.s_bm_block_start-1,SEEK_SET);
        fwrite(&buffer,sizeof(buffer),1,disco);

        fseek(disco,sb.s_bm_inode_start,SEEK_SET);
        fread(&bitmapInodos, sb.s_inodes_count, 1, disco);        
        for(int i=0; i < sb.s_inodes_count; i++){
            stringBitmap += bitmapInodos[i];
        }
       fclose(disco); 
    }

    return stringBitmap;    
}

string mkfs::leerBitmapBloques(){
    Partition part = obtenerParticionID(this->id);
    superbloque sb;    
    FILE *disco;
    string stringBloques;
    char buffer = '9';
    disco = fopen(quitarComillasRuta(obtenerRutaID(this->id)).c_str(), "rb+");
    fseek(disco,part.part_start,SEEK_SET); 
    fread(&sb, sizeof(superbloque), 1, disco);
    char bitmapBloques[sb.s_blocks_count];
    if(disco != NULL){
        fseek(disco,sb.s_bm_block_start,SEEK_SET);
        fwrite(&buffer,sizeof(buffer),1,disco);
        //fseek(disco,sb.s_bm_block_start-1,SEEK_SET);
        //fwrite(&buffer,sizeof(buffer),1,disco);
        fseek(disco,sb.s_bm_block_start,SEEK_SET);
        fread(&bitmapBloques, sb.s_blocks_count, 1, disco);        
        for(int i=0; i < sb.s_blocks_count; i++){
            stringBloques += bitmapBloques[i];
        }
       fclose(disco); 
    }

    return stringBloques;     
}

void mkfs::obtenerEspacioInodos(){
    //string test = "1000010000001011111111101111111111111";
    //string test = "0101100100";
    string test = "0110000100";
    int tam = 0;
    int inicio = 1;
    int fin = 0;

    for(int i=0; i < test.length(); i++){
        if(test[i] == '0'){
            tam++;
            inicio++;        
        }
        if(test[i] == '1'){            
            cout << "Pos: " << i-tam << "Tam: " << tam << endl;
            tam = 0;
            inicio++;
        }
    }
}

void mkfs::quemarRoot(){
    Partition part = obtenerParticionID(this->id);
    superbloque sb;
    FILE *disco;
    char buffer = '1';
    disco = fopen(quitarComillasRuta(obtenerRutaID(this->id)).c_str(), "rb+");
    if(disco != NULL){
       fseek(disco,part.part_start,SEEK_SET); 
       fread(&sb, sizeof(superbloque), 1, disco);
       sb.s_free_blocks_count -= 2;
       sb.s_free_inodes_count -= 2;
       sb.s_first_ino = 2;
       sb.s_first_blo = 2;
       fseek(disco,part.part_start,SEEK_SET); 
       fwrite(&sb, sizeof(superbloque), 1, disco);
       

        //Quemando bitmaps de inodos
        fseek(disco, sb.s_bm_inode_start, SEEK_SET);
        for(int i = 0; i < 2 ; i++){
            fwrite(&buffer, sizeof(buffer), 1, disco);
        }

       //Quemando bitmaps de bloques
       fseek(disco, sb.s_bm_block_start, SEEK_SET);
       for(int i = 0; i < 2 ; i++){
           fwrite(&buffer, sizeof(buffer), 1, disco);
       }
                 
    //fclose(disco);
}    

    inodo iCarpeta;
    iCarpeta.i_uid = 1;
    iCarpeta.i_gid = 1;
    iCarpeta.i_size = 0;
    strcpy(iCarpeta.i_atime, obtenerFechaHora().c_str());
    strcpy(iCarpeta.i_ctime, obtenerFechaHora().c_str());
    strcpy(iCarpeta.i_mtime, obtenerFechaHora().c_str());
    iCarpeta.i_block[0] = 0;
    for(int i=1; i < 15; i++){
        iCarpeta.i_block[i] = -1; 
    }
    iCarpeta.i_type = 0;
    iCarpeta.i_perm = 664; 

    bloqueCarpeta bCarpeta;

    bCarpeta.b_content[0].b_inodo = 0;
    strcpy(bCarpeta.b_content[0].b_name, ".");

    bCarpeta.b_content[1].b_inodo = 0;
    strcpy(bCarpeta.b_content[1].b_name, "..");

    bCarpeta.b_content[2].b_inodo = 1;
    strcpy(bCarpeta.b_content[2].b_name, "user.txt");

    bCarpeta.b_content[3].b_inodo = -1;
    strcpy(bCarpeta.b_content[3].b_name, "-1");

    inodo iArchivo;
    iArchivo.i_uid = 1;
    iArchivo.i_gid = 1;
    iArchivo.i_size = 0;

    strcpy(iArchivo.i_atime, obtenerFechaHora().c_str());
    strcpy(iArchivo.i_ctime, obtenerFechaHora().c_str());
    strcpy(iArchivo.i_mtime, obtenerFechaHora().c_str());
    iArchivo.i_block[0] = 1;
    for(int i=1; i < 15; i++){
        iCarpeta.i_block[i] = -1; 
    }
    iArchivo.i_type = 1;
    iArchivo.i_perm = 664; 

    bloqueArchivo bArchivo;
    strcpy(bArchivo.b_content, "root,root\n");

    fseek(disco, sb.s_inode_start, SEEK_SET);
    fwrite(&iCarpeta, sizeof(inodo), 1, disco);
    fwrite(&iArchivo, sizeof(inodo), 1, disco);

    fseek(disco, sb.s_block_start, SEEK_SET);
    fwrite(&bCarpeta, sizeof(bloqueCarpeta), 1, disco);
    fwrite(&bArchivo, sizeof(bloqueArchivo), 1, disco);
    fclose(disco);

}



