#ifndef MOUNT_H
#define MOUNT_H
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h> 
#include "mbr.h"
#include "funciones.h"

using namespace std;

typedef struct {
        string id;
        string nombre;
}Particion;

typedef struct {
        int id;
        string ruta;
        vector<Particion> particiones;
}Disco;

class mount
{
private:
string ruta;
string nombre;

public:
    mount(string parametros[]);
    void ejecutar();
    void montarParticion();
    void mostrarMount();
    bool verificarExistenciaDiscoyParticion();
    bool verificarDiscoMontado();
    bool verificarParticion();
    void montarDisco();
};

#endif // MOUNT_H
