#include "mkdisk.h"

mkdisk::mkdisk()
{

}

//Creamos el disco.
void mkdisk::crearDisco(std::string pmkdisk[]){ // 0 = size, 1 = path, 2 = f,  3 = u

    std::string ruta = pmkdisk[1];
    std::string parametroF = pmkdisk[2];
    std::string parametroU = pmkdisk[3];
    std::string tamanio = pmkdisk[0];
    parametroF = toLower(parametroF);
    parametroU = toLower(parametroU);

    int mb = 1024;
    int kb = 1;
    int discoTam = 0;
    char dFit = 'F';
    char buffer[1024];

    if (strcmp(parametroU.c_str(), "") == 0){
        discoTam = atoi(tamanio.c_str()) * mb;
        tamanio = "";
    }else if(strcmp(parametroU.c_str(), "k") == 0){
        discoTam = atoi(tamanio.c_str()) * kb;
        tamanio = "";
    }else if(strcmp(parametroU.c_str(), "m") == 0){
        discoTam = atoi(tamanio.c_str()) * mb;
        tamanio = "";
    }else{
        tamanio = "error";
    }

    if(strcmp(parametroF.c_str(), "") == 0){
        dFit = 'F';        
    }else if(strcmp(parametroF.c_str(), "bf") == 0){
        dFit = 'B';
    }else if(strcmp(parametroF.c_str(), "ff") == 0){
        dFit = 'F';
    }else if(strcmp(parametroF.c_str(), "wf") == 0){
        dFit = 'W';
    }else{
        parametroF = "error";
    }

       
    //std::cout << "|--> " << rutaSinArchivo  << " -- " << rutaAux << "--" << discoTam << std::endl;

    if(strcmp(tamanio.c_str(), "error") == 0){
        std::cout << "Error Parametro U";
    }else{
        if(strcmp(parametroF.c_str(), "error") == 0){
            std::cout << "Error Parametro F";
        }else{
        //Creamos las carpetas si no existen
        if (mkdir(obtenerRutaSinArchivo(ruta).c_str(), 0777) == -1){ 
            //std::cerr << "Error :  " << strerror(errno) << std::endl; 
    
        }
            chmod(obtenerRutaSinArchivo(ruta).c_str(), 0777);
            //Creamos el archivo
            FILE *fichero;
            fichero = fopen(quitarComillasRuta(ruta).c_str(),"w+b");
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
            crearMBR(dFit, discoTam, quitarComillasRuta(ruta).c_str());
        }        
    }    
}

void mkdisk::crearMBR(char pF, int tamanio, const char* ruta){
    std::string fechaHora = obtenerFechaHora();
    MBR mbr;
    tamanio = tamanio * 1024;
    mbr.mbr_tamano = tamanio;
    strcpy (mbr.mbr_fecha_creacion, fechaHora.c_str());
    mbr.mbr_disk_signature = obtenerNumeroRandom();
    mbr.disk_fit = pF;

    partition partVacia;

    partVacia.part_status = '0';
    partVacia.part_start = 0;
    partVacia.part_size = 0;

    for(int i = 0 ; i < 4; i++){
        mbr.mbr_partition[i] = partVacia;
    }
   
    //printf("%d\n", sizeof(MBR));

    FILE *arch;
    arch = fopen(ruta, "rb+");
    if(arch != NULL){
        fseek(arch,0,SEEK_SET);
        fwrite(&mbr, sizeof(MBR), 1, arch);
        fclose(arch);        
        printf("#//////////////////////#\nDISCO CREADO CORRECTAMENTE \nSE AGREGO EL MBR DE MANERA CORRECTA\n");
        std::cout << "Disco Creado en: " << ruta << "\nTamaño: " << tamanio << " bytes \nFecha de Creación: " << fechaHora << "\n#//////////////////////#" << std::endl;
    }else{
        printf("Error!\n No se puede acceder al disco, MBR no creado\n");
    }
}
