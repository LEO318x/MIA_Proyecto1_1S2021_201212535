#ifndef RMDISK_H
#define RMDISK_H
#include <QTextStream>
#include <string>
#include <iostream>
#include <cstdio>
#include "funciones.h"

class rmdisk
{
public:
    rmdisk();
    void eliminarDisco(std::string ruta);
};

#endif // RMDISK_H
