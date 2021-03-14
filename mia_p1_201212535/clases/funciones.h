#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <algorithm>
#include <time.h> 
#include <vector>
#include <iostream>
#include "estructuras.h"
#include <bits/stdc++.h> 
#include <sys/stat.h> 
#include <sys/types.h> 

using namespace std;
    string quitarComillasRuta(string ruta);
    string quitarComillasTexto(string ruta);
    string obtenerRutaSinArchivo(string ruta);
    string extraerNombreArchivo(string ruta);
    string toLower(string cadena);
    string toUpper(string cadena);
    string obtenerFechaHora();
    int obtenerNumeroRandom();
    Partition obtenerParticionID(string id);
    superbloque obtenerSuperBloque(Partition particion, string id);
    bloqueCarpeta obtenerBloqueCarpeta(string id, int indiceBloque);
    bloqueArchivo obtenerBloqueArchivo(string id, int indiceBloqueArch);
    int buscarInodo(string ruta, string nombre);
    bloqueArchivo buscarIno(string ruta, string id);
    string obtenerRutaID(string id);
    int obtenerPosicionInodo(int inicioInodo, int indiceInodo);
    void escribirJournal(journal jlEscribir, string idPart);
    vector<string> split(string cadena, string limitador);
    bool verificarParticionID(string id);
    void crearCarpetaReporte(string ruta);
    MBR obtenerMbr(string ruta);
    string obtenerBitmapInodos(string idPart);
    string obtenerBitmapBloques(string idPart);
    vector<espacioLibre> obtenerEspacioLibreDisco(string ruta);
    void buscarRuta(string id, string ruta);
    int buscarIndiceRuta(inodo ino, string nombre, string id);
    inodo obtenerInodo(string id, int indInodo);
    
    
#endif // FUNCIONES_H
