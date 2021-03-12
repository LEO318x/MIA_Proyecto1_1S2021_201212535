#ifndef UNMOUNT_H
#define UNMOUNT_H
#include <string>
#include <iostream>
#include <vector>
#include "funciones.h"

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
    void modificarFechaUnmount(string id);
};

#endif // UNMOUNT_H
