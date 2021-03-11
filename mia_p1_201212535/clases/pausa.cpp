#include "pausa.h"

using namespace std;
pausa::pausa()
{
    ejecutar();
}

void pausa::ejecutar(){
    cout << "Ejecución pausada, pulse cualquier tecla para continuar..." << endl;
    cin.get();
}
