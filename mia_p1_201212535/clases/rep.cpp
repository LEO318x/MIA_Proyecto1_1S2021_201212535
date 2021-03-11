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
    cout << "---> REP <---" << endl;
    cout << this->name << endl;
    cout << this->path << endl;
    cout << this->id << endl;
    cout << this->ruta << endl;
    cout << "---------------" << endl;
    if(validarParametros()){
        if(toLower(this->name) == "mbr"){            
            reporteMBR();
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

void rep::crearReporte(string data){
    string dataDot = "digraph { graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\"]; \n node [shape=plain] \n rankdir=LR;\n";
    dataDot += data;
    dataDot += "\n}";
    crearCarpetaReporte(this->path);    
    ofstream file;
    file.open(obtenerRutaSinArchivo(this->path)+"data.dot");
    file << dataDot.c_str();
    file.close();

    string comando = "dot -Tpng "+obtenerRutaSinArchivo(this->path)+"data.dot -o "+this->path;
    system(comando.c_str());
}
