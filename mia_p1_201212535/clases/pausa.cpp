#include "pausa.h"

using namespace std;
pausa::pausa()
{
    ejecutar();
}

void pausa::ejecutar(){
    string txt;
    cout << "Ejecución pausada, pulse cualquier tecla para continuar..." << endl;
    getline(cin, txt);
}
