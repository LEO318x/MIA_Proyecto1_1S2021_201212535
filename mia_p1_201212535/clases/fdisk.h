#ifndef FDISK_H
#define FDISK_H
#include <string>
#include <iostream>
#include "mbr.h"
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

    char pF;
    char pU;
    char pType;
public:
    fdisk(string []);
    void crearParticion();
    void infoDisco();
    void validarParametros();
    void test();
};

#endif // FDISK_H
