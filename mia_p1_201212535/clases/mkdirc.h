#ifndef MKDIRC_H
#define MKDIRC_H
#include "funciones.h"

using namespace std;
class mkdirc
{
private:
    string path;
    string p;

public:
    mkdirc(string parametros[]);
    void ejecutar();
};

#endif // MKDIRC_H
