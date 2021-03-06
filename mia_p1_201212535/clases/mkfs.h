#ifndef MKFS_H
#define MKFS_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "math.h"
#include "funciones.h"

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
    void obtenerEspacioBitmapInodos();
    void obtenerEspacioBitmapBloques();
    void quemarRoot();
    void testInodo(superbloque sb);
    void testJournal(int part_start, int indice);
};



#endif // MKFS_H
