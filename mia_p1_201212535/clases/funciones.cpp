#include "funciones.h"

std::string quitarComillasRuta(std::string ruta){
    std::string rutaAux = ruta;
    //Eliminamos las comillas de la ruta
    rutaAux.erase(remove(rutaAux.begin(), rutaAux.end(), '\"'), rutaAux.end());

    return rutaAux;
}

std::string obtenerRutaSinArchivo(std::string ruta){
    std::string rutaAux = quitarComillasRuta(ruta);
    std::string rutaSinNombreArchivo;

    size_t i = rutaAux.rfind("/", rutaAux.length());
    if (i != std::string::npos) {
        rutaSinNombreArchivo = (rutaAux.substr(0, i+1));
    }

    return rutaSinNombreArchivo;
}

std::string extraerNombreArchivo(std::string ruta){
    std::string rutaAux = quitarComillasRuta(ruta);
    std::string nombreArchivo;
    const size_t buscarUltimoSlash = rutaAux.find_last_of("\\/");
    if (std::string::npos != buscarUltimoSlash)
    {
        rutaAux.erase(0, buscarUltimoSlash + 1);
    }
    nombreArchivo = rutaAux;

    return nombreArchivo;
}

std::string toLower(std::string cadena){
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::tolower(c);
    });
    return cadena;
}

std::string toUpper(std::string cadena){
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::toupper(c);
    });
    return cadena;
}

std::string obtenerFechaHora(){
    time_t rawtime;
    struct tm * timeinfo;
    char fechaHora [16];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(fechaHora,16,"%d/%m/%y %H:%M",timeinfo);

    return fechaHora;
}

int obtenerNumeroRandom(){
    int numero;
    srand(time(0));
    numero = rand();

    return numero;
}
