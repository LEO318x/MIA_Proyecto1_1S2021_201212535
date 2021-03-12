#ifndef MOUNT_H
#define MOUNT_H
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h> 
#include "funciones.h"

using namespace std;

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
    void modificarFechaMount(string id);
};

#endif // MOUNT_H
