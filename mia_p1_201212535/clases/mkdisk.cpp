#include "mkdisk.h"

mkdisk::mkdisk()
{

}

//Creamos el disco.
void mkdisk::crearDisco(std::string pmkdisk[]){ // 0 = size, 1 = path, 2 = f,  3 = u
    std::string rutaAux = pmkdisk[1];
    std::string rutaOriginal = pmkdisk[1];
    std::string rutaSinArchivo;
    std::string parametroF = pmkdisk[2];
    std::string parametroU = pmkdisk[3];
    std::string tamanio = pmkdisk[0];
    int mb = 1024;
    int kb = 1;
    int discoTam = 0;
    char dFit = 'B';
    char buffer[1024];

    if (parametroU == ""){
        discoTam = atoi(tamanio.c_str()) * mb;
    }else if(parametroU == "k" || parametroU == "K"){
        discoTam = atoi(tamanio.c_str()) * kb;
    }else if(parametroU == "m" || parametroU == "M"){
        discoTam = atoi(tamanio.c_str()) * mb;
    }else{
        tamanio = "error";
    }

    if(parametroF == ""){
        dFit = 'B';
    }else if(parametroF == "BF"){
        dFit = 'B';
    }else if(parametroF == "FF"){
        dFit = 'F';
    }else if(parametroF == "WF"){
        dFit = 'W';
    }else{
        parametroF = "error";
    }

    // Creamos los directorios

    //Obtenemos el parametro de la ruta
    //Eliminamos las comillas de la ruta
    rutaAux.erase(remove(rutaAux.begin(), rutaAux.end(), '\"'), rutaAux.end());
    rutaOriginal = rutaAux;

    // Obtenemos la ruta sin la extensión del archivo
    size_t i = rutaAux.rfind("/", rutaAux.length());
    if (i != std::string::npos) {
        rutaSinArchivo = (rutaAux.substr(0, i+1));
    }
    
    // Obtenemos solo el nombre del archivo
    const size_t buscarUltimoSlash = rutaAux.find_last_of("\\/");
    if (std::string::npos != buscarUltimoSlash)
    {
        rutaAux.erase(0, buscarUltimoSlash + 1);
    }
    std::cout << "|--> " << rutaSinArchivo  << " -- " << rutaAux << "--" << discoTam << std::endl;

    if(tamanio == "error"){
        std::cout << "Error Parametro U";
    }else{
        if(parametroF == "error"){
            std::cout << "Error Parametro F";
        }else{
        //Creamos las carpetas si no existen
        if (mkdir(rutaSinArchivo.c_str(), 0777) == -1){ 
            //std::cerr << "Error :  " << strerror(errno) << std::endl; 
    
        }
            chmod(rutaSinArchivo.c_str(), 0777);
            //Creamos el archivo
            FILE *fichero;
            fichero = fopen(rutaOriginal.c_str(),"w+b");
            //if (!fichero)
            //perror("fopen");
            for(int i = 0 ; i < 1024 ; i++){
                buffer[i]='\0';
            }

            for(int i = 0 ; i < discoTam ; i++){
                fwrite(&buffer,1024,1,fichero);
            }            
            fclose(fichero);
            //std::cout << "Carpeta creada! :)";
            crearMBR(dFit, discoTam, rutaOriginal.c_str());
        }        
    }    
}

void mkdisk::crearMBR(char pF, int tamanio, const char* ruta){
    MBR mbr;
    char fecha[16];
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [16];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(buffer,16,"%d/%m/%y",timeinfo);
    mbr.mbr_tamano = tamanio;
    strcpy (mbr.mbr_fecha_creacion, buffer);
    mbr.disk_signature = (rand()%100);
    mbr.disk_fit = pF;

    partition partVacia;

    partVacia.part_status = '0';
    partVacia.part_start = '-1';
    partVacia.part_size = '-1';

    mbr.mbr_partition_1 = partVacia;
    mbr.mbr_partition_2 = partVacia;
    mbr.mbr_partition_3 = partVacia;
    mbr.mbr_partition_4 = partVacia;
    
    printf("%d\n", sizeof(MBR));

    FILE *arch;
    arch = fopen(ruta, "rb+");
    if(arch != NULL){
        fseek(arch,0,SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, arch);
        fclose(arch);
        printf("DISCO CREADO CORRECTAMENTE \nSE AGREGO EL MBR DE MANERA CORRECTA\n");
    }else{
        printf("Error!\n No se puede acceder al disco, MBR no creado\n");
    }
}
