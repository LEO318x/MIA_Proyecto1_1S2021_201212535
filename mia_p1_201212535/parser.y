%{
#include "scanner.h"//se importa el header del analisis sintactico
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>
#include "clases/mkdisk.h"
#include "clases/rmdisk.h"
#include "clases/fdisk.h"


using namespace std;
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
std::string p_mkdisk[4]; // 0 = size, 1 = path, 2 = f,  3 = u
std::string p_fdisk[9]; // 0 = size, 1 = u, 2 = path, 3 = type, 4 = f, 5 = delete, 6 = name, 7 = add
bool pPrimero = true;
int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}
%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%define parse.error verbose
%locations
%union{
//se especifican los tipo de valores para los no terminales y lo terminales
//char TEXT [256];
//QString TEXT;
char TEXT[256];
}
//TERMINALES DE TIPO TEXT, SON STRINGS

%token<TEXT> tk_mkdisk;
%token<TEXT> tk_rmdisk;
%token<TEXT> tk_fdisk;
%token<TEXT> tk_mount;
%token<TEXT> tk_unmount;
%token<TEXT> tk_mkfs;
%token<TEXT> tk_login;
%token<TEXT> tk_mkgrp;
%token<TEXT> tk_rmgrp;
%token<TEXT> tk_mkusr;
%token<TEXT> tk_rmusr;
%token<TEXT> tk_chmod;
%token<TEXT> tk_mkfile;
%token<TEXT> tk_cat;
%token<TEXT> tk_rem;
%token<TEXT> tk_edit;
%token<TEXT> tk_ren;
%token<TEXT> tk_mkdir;
%token<TEXT> tk_cp;
%token<TEXT> tk_mv;
%token<TEXT> tk_find;
%token<TEXT> tk_chown;
%token<TEXT> tk_chgrp;
%token<TEXT> tk_logout;
%token<TEXT> tk_pause;
%token<TEXT> tk_recovery;
%token<TEXT> tk_loss;
%token<TEXT> tk_exec;
%token<TEXT> tk_rep;
%token<TEXT> tk_size;
%token<TEXT> tk_path;
%token<TEXT> tk_type;
%token<TEXT> tk_name;
%token<TEXT> tk_id;
%token<TEXT> tk_usr;
%token<TEXT> tk_pwd;
%token<TEXT> tk_grp;
%token<TEXT> tk_ugo;
%token<TEXT> tk_filen;
%token<TEXT> tk_cont;
%token<TEXT> tk_p;
%token<TEXT> tk_dest;
%token<TEXT> tk_f;
%token<TEXT> tk_u;
%token<TEXT> tk_delete;
%token<TEXT> tk_add;
%token<TEXT> tk_fs;
%token<TEXT> tk_r;
%token<TEXT> tk_ruta;
%token<TEXT> tk_entero;
%token<TEXT> tk_negativo;
%token<TEXT> tk_cadena;
%token<TEXT> tk_eruta;
%token<TEXT> tk_identificador;
%token<TEXT> tk_punto;
%token<TEXT> tk_menos;
%token<TEXT> tk_guionbajo;
%token<TEXT> tk_asterisco;
%token<TEXT> tk_interrogacion;
%token<TEXT> tk_igual;


//%type<mdisk> COMANDOMKDISK; // lista de instrucciones

/*%left suma menos
%left multi division
%left potencia*/

%start INICIO
%%

INICIO : LISTACOMANDOS {}
;

LISTACOMANDOS:  COMANDOS LISTACOMANDOS {}
                | COMANDOS {}
;

COMANDOS: MKDISK {}
        | RMDISK {}
        | FDISK {}
;

MKDISK: tk_mkdisk LP_MKDISK {mkdisk disco; disco.crearDisco(p_mkdisk); for (int i=0; i < 4; i++)p_mkdisk[i].clear();}
;

LP_MKDISK: P_MKDISK LP_MKDISK  {}
        | P_MKDISK {}
;
// 0 = size, 1 = path, 2 = f,  3 = u
P_MKDISK:  tk_menos tk_size tk_igual tk_entero  {p_mkdisk[0] = $4;}
    | tk_menos tk_path tk_igual tk_eruta {p_mkdisk[1] = $4;}
    | tk_menos tk_path tk_igual tk_cadena {p_mkdisk[1] = $4;}
    | tk_menos tk_f tk_igual tk_identificador {p_mkdisk[2]= $4;}
    | tk_menos tk_u tk_igual tk_identificador {p_mkdisk[3] = $4;}
;

RMDISK: tk_rmdisk tk_menos tk_path tk_igual tk_eruta {rmdisk disco2; disco2.eliminarDisco($5);}
    | tk_rmdisk tk_menos tk_path tk_igual tk_cadena {rmdisk disco2; disco2.eliminarDisco($5);}
;

FDISK: tk_fdisk LP_FDISK {fdisk fdisk(p_fdisk);  fdisk.ejecutarFdisk(); for (int i=0; i < 9; i++){p_fdisk[i].clear();} pPrimero = true;}
;

LP_FDISK: P_FDISK LP_FDISK {}
        | P_FDISK {}
;
// 0 = size, 1 = u, 2 = path, 3 = type, 4 = f, 5 = delete, 6 = name, 7 = add
P_FDISK: tk_menos tk_size tk_igual tk_entero {p_fdisk[0]=$4; if(pPrimero){pPrimero = false; p_fdisk[8] = "size";}}

        | tk_menos tk_path tk_igual tk_eruta {p_fdisk[2]=$4;}
        | tk_menos tk_path tk_igual tk_cadena {p_fdisk[2]=$4;}

        | tk_menos tk_name tk_igual tk_identificador {p_fdisk[6]=$4;}
        | tk_menos tk_name tk_igual tk_cadena {p_fdisk[6]=$4;}

        | tk_menos tk_u tk_igual tk_identificador {p_fdisk[1]=$4;}        
        | tk_menos tk_type tk_igual tk_identificador {p_fdisk[3]=$4;}
        | tk_menos tk_type tk_igual tk_p {p_fdisk[3]=$4;}
        | tk_menos tk_f tk_igual tk_identificador {p_fdisk[4]=$4;} 

        | tk_menos tk_delete tk_igual tk_identificador {p_fdisk[5]=$4; if(pPrimero){pPrimero = false; p_fdisk[8] = "delete";}}

        | tk_menos tk_add tk_igual tk_entero {p_fdisk[7]=$4; if(pPrimero){pPrimero = false; p_fdisk[8] = "add";}}
        | tk_menos tk_add tk_igual tk_negativo {p_fdisk[7]=$4; if(pPrimero){pPrimero = false; p_fdisk[8] = "add";}}
;
