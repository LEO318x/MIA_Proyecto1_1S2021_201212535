#ifndef EXEC_H
#define EXEC_H
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <parser.h>
#include <scanner.h>
#include <QString>
#include "funciones.h"



using namespace std;


class exec
{
private:
     string ruta;
public:
    exec(string ruta[]);
    void ejecutar();
};

#endif // EXEC_H
