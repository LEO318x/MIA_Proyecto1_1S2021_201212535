#ifndef UNMOUNT_H
#define UNMOUNT_H
#include <string>
#include <iostream>
#include <vector>
#include "funciones.h"
#include "mount.h"

using namespace std;


class unmount
{
private:
string id;
public:
    unmount(string parametros[]);
    void ejecutar();
    void mostrar();
    void desmontar();
};

#endif // UNMOUNT_H
