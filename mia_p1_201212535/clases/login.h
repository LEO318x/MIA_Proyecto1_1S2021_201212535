#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <iostream>
#include <vector>
#include "funciones.h"

using namespace std;
class login
{
private:
    string usuario;
    string password;
    string id;
public:
    login(string parametros[]);
    void ejecutar();
    bool validarParametros();
    void test();
    void testArchivo();
    bool iniciarSesion();
    void testLogin();
};

#endif // LOGIN_H
