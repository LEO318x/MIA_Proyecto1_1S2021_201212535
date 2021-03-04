#ifndef MKFS_H
#define MKFS_H

#include <string>
#include <iostream>
#include "funciones.h"
#include <vector>
#include "mount.h"
#include "estructuras.h"
#include "math.h"

using namespace std;
class mkfs
{
private:
    string id;
    string type;
    string fs;
public:
    mkfs(string parametros[]);
    void ejecutar();
    bool validarParametros();
    bool buscarID();
    void pesoEstructuras();
    void buscarTamanioParticion();
    int obtenerN(int tamanioParticion, int journal);
    void formatear(superbloque sb);
    void leerSuperBloque();
    string leerBitmapInodos();
    string leerBitmapBloques();
    void obtenerEspacioInodos();
    void quemarRoot();
};



#endif // MKFS_H
