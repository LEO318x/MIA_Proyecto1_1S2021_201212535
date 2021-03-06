#ifndef FDISK_H
#define FDISK_H
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "funciones.h"

using namespace std;
class fdisk
{
private:
    string size;
    string u;
    string path;
    string type;
    string f;
    string _delete;
    string name;
    string add;
    string pPrimero;

    char pF;
    char pU;
    char pType;

    struct espacioLibre
    {
        int inicio;
        int tamanio;
    };
    
public:
    fdisk(string []);
    void crearParticion();
    void eliminarParticion();
    void testEspacioDisco(int inicia, int tamanio, string ruta, char buf);
    void infoDisco();
    bool validarParametros();
    void ejecutarFdisk();
};

#endif // FDISK_H
