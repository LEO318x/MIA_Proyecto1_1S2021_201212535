#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <algorithm>
#include <time.h> 
#include "mbr.h"
#include <vector>
#include "mount.h"

    std::string quitarComillasRuta(std::string ruta);
    std::string quitarComillasTexto(std::string ruta);
    std::string obtenerRutaSinArchivo(std::string ruta);
    std::string extraerNombreArchivo(std::string ruta);
    std::string toLower(std::string cadena);
    std::string toUpper(std::string cadena);
    std::string obtenerFechaHora();
    int obtenerNumeroRandom();
    Partition obtenerParticionID(std::string id);
    std::string obtenerRutaID(std::string id);
//#include "funciones.cpp"
#endif // FUNCIONES_H
