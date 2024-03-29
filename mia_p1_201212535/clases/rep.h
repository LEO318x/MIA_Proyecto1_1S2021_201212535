#ifndef REP_H
#define REP_H

#include <string>
#include <iostream>
#include "funciones.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

class rep
{
private:
    string name;
    string path;
    string id;
    string ruta;
    vector<string> bloque;
    int auxRB = 0;

public:
    rep(string parametros[]);
    void ejecutar();
    bool validarParametros();
    void reporteMBR();
    void crearReporte(string data);
    void reporteBmInode();
    void reporteBmBloques();
    void reporteSb();
    void reporteDisk();
    void reporteInodo();
    void reporteJournaling();
    void reporteTree();
    string obtenerInodosRec(int indInodo);
    string bloqueCarpetaRec(int indInodo);
    string bloqueArchivoRec(int indInodo);
    string obtenerBloqueRec(int indInodo);
    string bloqueCarpetaRecSinInodo(int indInodo);
    string bloqueArchivoRecSinInodo(int indInodo);
};

#endif // REP_H
