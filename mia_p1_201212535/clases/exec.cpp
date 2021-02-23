#include "exec.h"

using namespace std;

exec::exec(string ruta[]){
    this->ruta = ruta[0];
}

void exec::ejecutar(){

extern int yyparse(); //
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;


std::ifstream input(quitarComillasRuta(ruta).c_str());
    if(input.is_open()) {
        string line;
        while (std::getline(input, line)) {
            QString line2 = line.c_str();
            printf("%s", line.c_str());
            cout << "\n";
            if(!line.empty()){
                YY_BUFFER_STATE buffer = yy_scan_string(line2.toUtf8().constData());
                linea = 0;
                columna = 0;
                yylineno = 0;
                if(yyparse()==0) // Si nos da un número negativo, signifca error.
                    {
                        printf("\n\Comando ejecutado correctamente desde el script\n\n");

                    }else {

                        printf("\n\nhay errores\n\n");
                    }
            }

        }
        input.close();
    }
}

