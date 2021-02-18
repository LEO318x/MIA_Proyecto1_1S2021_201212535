#ifndef MKDISK_H
#define MKDISK_H
#include <string>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include "mbr.h"
#include <time.h>  

class mkdisk
{
public:
    mkdisk();
    void crearDisco(std::string pmkdisk[]);
private:
    void crearMBR(char pF, int tamanio, const char* ruta);
};

#endif // MKDISK_H
