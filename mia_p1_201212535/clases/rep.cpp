#include "rep.h"
#include <sstream>

using namespace std;
rep::rep(string parametros[])
{
    this->name = quitarComillasTexto(parametros[0]);
    this->path = quitarComillasRuta(parametros[1]);
    this->id = quitarComillasTexto(parametros[2]);
    this->ruta = quitarComillasRuta(parametros[3]);
}

void rep::ejecutar(){
    /*cout << "---> REP <---" << endl;
    cout << this->name << endl;
    cout << this->path << endl;
    cout << this->id << endl;
    cout << this->ruta << endl;
    cout << "---------------" << endl;*/
    if(validarParametros()){
        if(toLower(this->name) == "mbr"){            
            reporteMBR();
        }else if(toLower(this->name) == "bm_inode"){
            reporteBmInode();
        }else if(toLower(this->name) == "bm_block"){
            reporteBmBloques();
        }else if(toLower(this->name) == "sb"){
            reporteSb();
        }else if(toLower(this->name)== "disk"){
            reporteDisk();
        }else if(toLower(this->name) == "inode"){
            reporteInodo();
        }else if(toLower(this->name) == "journaling"){
            reporteJournaling();
        }else if(toLower(this->name) == "tree"){
            //reporteTree();
            crearReporte(obtenerInodosRec(0));
        }
        
    }
}

bool rep::validarParametros(){
    bool resultado = false;

    if(this->name == "" || this->path == "" || this->id == ""){
        cout << "ERROR: El parametro -name/-path/-id no puede estar vacio." << endl;
        resultado = false;
    }else{
        resultado = true;
    }
    return resultado;
}

void rep::reporteMBR(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: La partición no existe" << endl;
    }else{
        MBR mbr;
        //crearCarpetaReporte(this->path);    
        mbr = obtenerMbr(obtenerRutaID(this->id));
        string textoRep;
        textoRep = "MBR [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
        textoRep += "<tr><td><i>MBR</i></td><td>"+ extraerNombreArchivo(obtenerRutaID(this->id)) +"</td></tr>";
        textoRep += "<tr><td>Nombre</td><td>Valor</td></tr>\n";
        textoRep += "<tr><td>mbr_tamaño</td><td>"+ to_string(mbr.mbr_tamano) +"</td></tr>\n";
        textoRep += "<tr><td>mbr_fecha_creacion</td><td>"+ string(mbr.mbr_fecha_creacion)  +"</td></tr>\n";
        textoRep += "<tr><td>mbr_disk_signature</td><td>"+ to_string(mbr.mbr_disk_signature) +"</td></tr>\n";
        textoRep += "<tr><td>disk_fit</td><td>"+ string(&mbr.disk_fit,1) +"</td></tr>\n";

        for(int i=0; i < 4; i++){
            if(mbr.mbr_partition[i].part_status == '1'){
                textoRep += "<tr><td>part_name_"+to_string(i+1)+"</td><td>"+ string(mbr.mbr_partition[i].part_name) +"</td></tr>\n";
                textoRep += "<tr><td>part_status_"+to_string(i+1)+"</td><td>"+ string(&mbr.mbr_partition[i].part_status, 1)  +"</td></tr>\n";
                textoRep += "<tr><td>part_type_"+to_string(i+1)+"</td><td>"+ string(&mbr.mbr_partition[i].part_type, 1) +"</td></tr>\n";
                textoRep += "<tr><td>part_fit_"+to_string(i+1)+"</td><td>"+ string(&mbr.mbr_partition[i].part_fit, 1) +"</td></tr>\n";
                textoRep += "<tr><td>part_size_"+to_string(i+1)+"</td><td>"+ to_string(mbr.mbr_partition[i].part_size) +"</td></tr>\n";
                textoRep += "<tr><td>part_start_"+to_string(i+1)+"</td><td>"+ to_string(mbr.mbr_partition[i].part_start) +"</td></tr>\n";
            }
            
        }
        textoRep += "</table>>];";
        crearReporte(textoRep);
    }
    

}

void rep::reporteBmInode(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: La partición no existe" << endl;
        return;
    }
    string bitmap = obtenerBitmapInodos(this->id);
    crearCarpetaReporte(this->path);
    ofstream file;
    file.open(quitarComillasRuta(this->path));
    int auxContador = 1;
    for (int i=0; i < bitmap.length(); i++){        
        file << bitmap[i];
        if(auxContador == 20){
            file << "\n";
            auxContador = 0;
        }
        auxContador++;
    }
    file.close();
}

void rep::reporteBmBloques(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: La partición no existe" << endl;
        return;
    }
    string bitmap = obtenerBitmapBloques(this->id);
    crearCarpetaReporte(this->path);
    ofstream file;
    file.open(quitarComillasRuta(this->path));
    int auxContador = 1;
    for (int i=0; i < bitmap.length(); i++){        
        file << bitmap[i];
        if(auxContador == 20){
            file << "\n";
            auxContador = 0;
        }
        auxContador++;
    }
    file.close();
}

void rep::reporteSb(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: La partición no existe" << endl;
        return;
    }
    Partition part = obtenerParticionID(this->id);
    superbloque sb = obtenerSuperBloque(obtenerParticionID(this->id), this->id);
    string textoRep;

    textoRep = "SuperBloque [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
    textoRep += "<tr><td><i>SuperBloque</i></td><td>" + string(part.part_name) + "("+this->id + ") en " + extraerNombreArchivo(obtenerRutaID(this->id)) +"</td></tr>";
    textoRep += "<tr><td>Nombre</td><td>Valor</td></tr>\n";
    textoRep += "<tr><td>s_filesystem_type</td><td>"+ to_string(sb.s_filesystem_type) +"</td></tr>\n";
    textoRep += "<tr><td>s_inodes_count</td><td>"+ to_string(sb.s_inodes_count) +"</td></tr>\n";
    textoRep += "<tr><td>s_blocks_count</td><td>"+ to_string(sb.s_blocks_count)  +"</td></tr>\n";
    textoRep += "<tr><td>s_free_blocks_count</td><td>"+ to_string(sb.s_free_blocks_count) +"</td></tr>\n";
    textoRep += "<tr><td>s_free_inodes_count</td><td>"+ to_string(sb.s_free_inodes_count) +"</td></tr>\n";

    textoRep += "<tr><td>s_mtime</td><td>"+ string(sb.s_mtime) +"</td></tr>\n";
    textoRep += "<tr><td>s_untime</td><td>"+ string(sb.s_untime) +"</td></tr>\n";
    textoRep += "<tr><td>s_mnt_count</td><td>"+ to_string(sb.s_mnt_count) +"</td></tr>\n";
    textoRep += "<tr><td>s_magic</td><td>"+ to_string(sb.s_magic) +"</td></tr>\n";
    textoRep += "<tr><td>s_inode_size</td><td>"+ to_string(sb.s_inode_size) +"</td></tr>\n";
    textoRep += "<tr><td>s_block_size</td><td>"+ to_string(sb.s_block_size) +"</td></tr>\n";
    textoRep += "<tr><td>s_first_ino</td><td>"+ to_string(sb.s_first_ino) +"</td></tr>\n";
    textoRep += "<tr><td>s_first_blo</td><td>"+ to_string(sb.s_first_blo) +"</td></tr>\n";
    textoRep += "<tr><td>s_bm_inode_start</td><td>"+ to_string(sb.s_bm_inode_start) +"</td></tr>\n";
    textoRep += "<tr><td>s_bm_block_start</td><td>"+ to_string(sb.s_bm_block_start) +"</td></tr>\n";
    textoRep += "<tr><td>s_inode_start</td><td>"+ to_string(sb.s_inode_start) +"</td></tr>\n";
    textoRep += "<tr><td>s_block_start</td><td>"+ to_string(sb.s_block_start) +"</td></tr>\n";
    textoRep += "</table>>];";
    crearReporte(textoRep);

}

void rep::reporteDisk(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: La partición no existe" << endl;
        return;
    }
    string textoRep;
    
    MBR mbr = obtenerMbr(obtenerRutaID(this->id));
    vector<espacioLibre> vES = obtenerEspacioLibreDisco(obtenerRutaID(this->id));
    vector<espacioLibre> vPart;

    for(int i = 0; i < 4; i++){
        if(mbr.mbr_partition[i].part_status == '1'){
            espacioLibre pA;
            pA.inicio = mbr.mbr_partition[i].part_start;
            pA.tamanio = mbr.mbr_partition[i].part_size;
            pA.tipo = 1;
            pA.type = mbr.mbr_partition[i].part_type;
            vPart.push_back(pA);
        }        
    }

    for(int i = 0; i < vES.size(); i++){
        vPart.push_back(vES[i]);
    }

    cout << "Reporte Disk: " << vPart.size() << endl;
    
    espacioLibre aux;
    for(int i = 0; i < vPart.size(); i++){
    	for(int j = i+1; j < vPart.size(); j++){
    	      if(vPart[i].inicio > vPart[j].inicio){
    			aux = vPart[i];
    			vPart[i] = vPart[j];
    			vPart[j] = aux;
		    }
        }
    }

    cout << "Tamanio Disco: " << mbr.mbr_tamano << endl;
    for(int i = 0; i < vPart.size(); i++){
        if(vPart[i].tipo == 0){
            cout << "Espacio Libre: " << vPart[i].tamanio << endl;
        }else{
            cout << "Particion: " << vPart[i].tamanio << endl;
        }
        cout << "TIPO:" << vPart[i].type << endl;
    }

    textoRep = "DISK [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
    textoRep += "<tr><td><i>DISK</i></td><td>"+ extraerNombreArchivo(obtenerRutaID(this->id)) +"</td></tr>";
    textoRep += "<tr><td>MBR "+ to_string(static_cast<float>(sizeof(mbr))/static_cast<float>(mbr.mbr_tamano)*100)+"%</td>";
    for(int i = 0; i < vPart.size(); i++){
        float operacion = (static_cast<float>(vPart[i].tamanio)/static_cast<float>(mbr.mbr_tamano))*100;
        if(toUpper(string(1, vPart[i].type)) == "V"){
            textoRep += "<td>Libre "+to_string(operacion)+"%</td>";
        }else if(toUpper(string(1, vPart[i].type)) == "P"){
            textoRep += "<td>Primaria "+to_string(operacion)+"%</td>";
        }else if(toUpper(string(1, vPart[i].type)) == "E"){
            textoRep += "<td>Extendida "+to_string(operacion)+"%</td>";
        }
    }
    textoRep += "</tr>\n</table>>];";
    crearReporte(textoRep);

}

void rep::reporteInodo(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: No existe la partición o disco" << endl;
        return;
    }
    string bmInodos = obtenerBitmapInodos(this->id);
    superbloque sb = obtenerSuperBloque(obtenerParticionID(this->id), this->id);
    int startInodo = sb.s_inode_start;
    FILE *disco;
    disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
    inodo ind;
    string textoRep;
    string apuntAux;
    int auxC = 0;
    string nombre = extraerNombreArchivo(obtenerRutaID(this->id));
    
    if(disco != NULL){
        for(int i=0; i < bmInodos.size(); i++){
            if(bmInodos[i] != '0'){
                fseek(disco, obtenerPosicionInodo(startInodo, i), SEEK_SET);
                fread(&ind, sizeof(inodo), 1, disco);
                //cout << ind.i_type << endl;
                textoRep += "Inodo"+to_string(i)+" [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
                textoRep += "<tr><td>" + nombre +"</td><td>Inodo "+to_string(i)+"</td></tr>";
                textoRep += "<tr><td>Nombre</td><td>Valor</td></tr>\n";
                textoRep += "<tr><td>i_uid</td><td>"+ to_string(ind.i_uid) +"</td></tr>\n";
                textoRep += "<tr><td>i_gid</td><td>"+ to_string(ind.i_gid) +"</td></tr>\n";
                textoRep += "<tr><td>i_size</td><td>"+ to_string(ind.i_size) +"</td></tr>\n";
                textoRep += "<tr><td>i_atime</td><td>"+ string(ind.i_atime) +"</td></tr>\n";
                textoRep += "<tr><td>i_ctime</td><td>"+ string(ind.i_ctime) +"</td></tr>\n";
                textoRep += "<tr><td>i_mtime</td><td>"+ string(ind.i_mtime) +"</td></tr>\n";
                for(int j = 0; j < 15; j++){
                    textoRep += "<tr><td>APT"+to_string(j)+"</td><td>"+ to_string(ind.i_block[j]) +"</td></tr>\n";
                }
                textoRep += "<tr><td>i_type</td><td>"+ to_string(ind.i_type) +"</td></tr>\n";
                textoRep += "<tr><td>i_perm</td><td>"+ to_string(ind.i_perm) +"</td></tr>\n";
                textoRep += "</table>>];";

                if(auxC == 0){
                    apuntAux += "Inodo"+to_string(i); 
                    auxC++;
                }else{
                    apuntAux += "->Inodo"+to_string(i); 
                }
            }            
        }
                  
        fclose(disco);
        textoRep += apuntAux+";";
        crearReporte(textoRep);
    }
}

void rep::reporteJournaling(){
    if(!verificarParticionID(this->id)){
        cout << "ERROR: No existe la partición o disco" << endl;
        return;
    }
    Partition part = obtenerParticionID(this->id);
    superbloque sb = obtenerSuperBloque(part, this->id);
    

    int inicioPart = part.part_start;
    int tamSb = sizeof(superbloque);

    journal jl;

    if(sb.s_filesystem_type == 3){
        FILE *disco;
        disco = fopen(quitarComillasRuta(obtenerRutaID(id)).c_str(), "rb");
        if(disco != NULL){
            fseek(disco, inicioPart+tamSb, SEEK_SET);
            fread(&jl, sizeof(journal), 1, disco);


            string textoRep;
            string nombre = extraerNombreArchivo(obtenerRutaID(this->id));
            string nombrePart = part.part_name;
            int indiceJl = jl.j_permisos - 1;
            //cout << "jlpermisos " << indiceJl << endl;
            textoRep += "jl[label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
            textoRep += "<tr><td colspan=\"9\">Journaling de " + nombrePart + " en "  + nombre +"</td></tr>";
            textoRep += "<tr><td>#</td><td>Tipo Operacion</td><td>Tipo</td><td>Nombre</td><td>Contenido</td><td>Fecha</td><td>UID</td><td>GID</td><td>Permisos</td></tr>\n";
            for(int i=1; i <= indiceJl; i++){
                fseek(disco, (inicioPart+tamSb + (i*sizeof(journal))), SEEK_SET);
                fread(&jl, sizeof(journal), 1, disco);
                textoRep += "<tr><td>"+to_string(i)+"</td>";
                textoRep += "<td>"+ string(jl.j_tipo_operacion) +"</td>\n";
                textoRep += "<td>"+ string(1, jl.j_tipo) +"</td>\n";
                textoRep += "<td>"+ string(jl.j_nombre) +"</td>\n";
                textoRep += "<td>"+ string(jl.j_contenido) +"</td>\n";
                textoRep += "<td>"+ string(jl.j_fecha) +"</td>\n";
                textoRep += "<td>"+ to_string(jl.j_userid) +"</td>\n";
                textoRep += "<td>"+ to_string(jl.j_groupid) +"</td>\n";
                textoRep += "<td>"+ to_string(jl.j_permisos) +"</td></tr>\n";                

                //cout << jl.j_tipo_operacion << endl;
            }
            fclose(disco);
            textoRep += "</table>>];";
            crearReporte(textoRep);
        }
    }
}

void rep::reporteTree(){
    obtenerInodosRec(0);
}

void rep::crearReporte(string data){
    string dataDot = "digraph { graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\"]; \n node [shape=plain] \n rankdir=LR;\n";
    dataDot += data;
    dataDot += "\n}";
    crearCarpetaReporte(this->path);    
    ofstream file;
    file.open(obtenerRutaSinArchivo(this->path)+"data.dot");
    file << dataDot.c_str();
    file.close();

    string nombre = extraerNombreArchivo(this->path);
    string ext = "-Tpng";
    if(nombre.substr(nombre.find_last_of(".") + 1) == "png") {
        ext = "-Tpng";
    }else if(nombre.substr(nombre.find_last_of(".") + 1) == "jpg"){
        ext = "-Tjpg";
    }else if(nombre.substr(nombre.find_last_of(".") + 1) == "pdf"){
        ext = "-Tpdf";
    }else if(nombre.substr(nombre.find_last_of(".") + 1) == "svg"){
        ext = "-Tsvg";
    }
    string comando = "dot "+ ext +" "+obtenerRutaSinArchivo(this->path)+"data.dot -o "+this->path;
    system(comando.c_str());
}


string rep::obtenerInodosRec(int indInodo){
    string data;
    superbloque sb = obtenerSuperBloque(obtenerParticionID(this->id), this->id);
    inodo ind = obtenerInodo(this->id, indInodo);

    data += "";
    data = "Inodo"+to_string(indInodo)+" [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
    data += "<tr><td port=\"T\" colspan=\"2\" bgcolor=\"dodgerblue\">INODO</td></tr>\n";
    data += "<tr><td>Propietario</td><td>"+to_string(ind.i_uid)+"</td></tr>\n";
    data += "<tr><td>Grupo</td><td>"+to_string(ind.i_gid)+"</td></tr>\n";
    data += "<tr><td>Tamaño</td><td>"+to_string(ind.i_size)+"</td></tr>\n";
    data += "<tr><td>Tipo</td><td>"+string(1, ind.i_type)+"</td></tr>\n";
    data += "<tr><td>Permisos</td><td>"+to_string(ind.i_perm)+"</td></tr>\n";
    data += "<tr><td>Fecha Acceso</td><td>"+string(ind.i_atime)+"</td></tr>\n";
    data += "<tr><td>Fecha Creación</td><td>"+string(ind.i_ctime)+"</td></tr>\n";
    data += "<tr><td>Fecha Modificación</td><td>"+string(ind.i_mtime)+"</td></tr>\n";
    for(int i = 0; i < 15; i++ ){
        data += "<tr><td>APT"+to_string(i)+"</td><td port=\""+to_string(i)+"\">"+to_string(ind.i_block[i])+"</td></tr>\n";
    }
    data += "</table>>];\n";

    for (int i = 0; i < 12; i++){
        if(ind.i_block[i] != -1){
            if(ind.i_type == '0'){ //bloque carpeta
                //cout << "Entra acá Carpeta" << endl;                
                data += bloqueCarpetaRec(ind.i_block[i]);
                data += "Inodo"+to_string(indInodo)+":"+to_string(i)+"->bloqueCarpeta"+to_string(indInodo)+":T;\n";

            }else if(ind.i_type == '1'){ //bloque archivo
                //cout << "Entra acá Archivo" << endl;
                data += bloqueArchivoRec(ind.i_block[i]);
                data += "Inodo"+to_string(indInodo)+":"+to_string(i)+"->bloqueArchivo"+to_string(indInodo)+":T;\n";
 
            }
        }
    }
    return data;
}

string rep::bloqueCarpetaRec(int indInodo){
    string dataC;
    bloqueCarpeta bC = obtenerBloqueCarpeta(this->id, indInodo);

        //cout << "bCI " << bC.b_content->b_inodo << endl;
        //cout << "bCN " << bC.b_content->b_name << endl;

        dataC += "bloqueCarpeta"+to_string(indInodo)+" [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
        dataC += "<tr><td port=\"T\" colspan=\"2\" bgcolor=\"green2\">Bloque Carpeta</td></tr>\n";
        for(int i = 0; i < 4; i++){
            dataC += "<tr><td>"+string(bC.b_content[i].b_name)+"</td>\n";
            dataC += "<td port=\""+to_string(bC.b_content[i].b_inodo)+"\">"+to_string(bC.b_content[i].b_inodo)+"</td></tr>\n";
        }
        dataC += "</table>>];\n";

        for (int i = 0; i < 4; i++){
            if(bC.b_content[i].b_inodo != -1 && string(bC.b_content[i].b_name) != "." && string(bC.b_content[i].b_name) != ".."){
                //cout << "R" << endl;
                //cout << bC.b_content[i].b_inodo << endl;
                //cout << bC.b_content[i].b_name << endl;
                //cout << "R/" << endl;
                dataC += obtenerInodosRec(bC.b_content[i].b_inodo);
                dataC += "bloqueCarpeta"+to_string(indInodo)+":"+to_string(bC.b_content[i].b_inodo)+"->Inodo"+to_string(bC.b_content[i].b_inodo)+":T;\n";
            }
        }

    return dataC;
}

string rep::bloqueArchivoRec(int indInodo){
    string dataA;
    bloqueArchivo bA = obtenerBloqueArchivo(this->id, indInodo);
    //cout << bA.b_content << endl;
    dataA += "bloqueArchivo"+to_string(indInodo)+" [label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
    dataA += "<tr><td port=\"T\" colspan=\"2\" bgcolor=\"gold1\">Bloque Archivo</td></tr>";
    dataA += "<tr><td>Contenido:</td><td>"+string(bA.b_content)+"</td></tr>";
    dataA += "</table>>];\n";       

    return dataA;
}
