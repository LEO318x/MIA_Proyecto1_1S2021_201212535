/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tk_mkdisk = 258,               /* tk_mkdisk  */
    tk_rmdisk = 259,               /* tk_rmdisk  */
    tk_fdisk = 260,                /* tk_fdisk  */
    tk_mount = 261,                /* tk_mount  */
    tk_unmount = 262,              /* tk_unmount  */
    tk_mkfs = 263,                 /* tk_mkfs  */
    tk_login = 264,                /* tk_login  */
    tk_mkgrp = 265,                /* tk_mkgrp  */
    tk_rmgrp = 266,                /* tk_rmgrp  */
    tk_mkusr = 267,                /* tk_mkusr  */
    tk_rmusr = 268,                /* tk_rmusr  */
    tk_chmod = 269,                /* tk_chmod  */
    tk_mkfile = 270,               /* tk_mkfile  */
    tk_cat = 271,                  /* tk_cat  */
    tk_rem = 272,                  /* tk_rem  */
    tk_edit = 273,                 /* tk_edit  */
    tk_ren = 274,                  /* tk_ren  */
    tk_mkdir = 275,                /* tk_mkdir  */
    tk_cp = 276,                   /* tk_cp  */
    tk_mv = 277,                   /* tk_mv  */
    tk_find = 278,                 /* tk_find  */
    tk_chown = 279,                /* tk_chown  */
    tk_chgrp = 280,                /* tk_chgrp  */
    tk_logout = 281,               /* tk_logout  */
    tk_pause = 282,                /* tk_pause  */
    tk_recovery = 283,             /* tk_recovery  */
    tk_loss = 284,                 /* tk_loss  */
    tk_exec = 285,                 /* tk_exec  */
    tk_rep = 286,                  /* tk_rep  */
    tk_size = 287,                 /* tk_size  */
    tk_path = 288,                 /* tk_path  */
    tk_type = 289,                 /* tk_type  */
    tk_name = 290,                 /* tk_name  */
    tk_id = 291,                   /* tk_id  */
    tk_usr = 292,                  /* tk_usr  */
    tk_pwd = 293,                  /* tk_pwd  */
    tk_grp = 294,                  /* tk_grp  */
    tk_ugo = 295,                  /* tk_ugo  */
    tk_filen = 296,                /* tk_filen  */
    tk_cont = 297,                 /* tk_cont  */
    tk_p = 298,                    /* tk_p  */
    tk_dest = 299,                 /* tk_dest  */
    tk_f = 300,                    /* tk_f  */
    tk_u = 301,                    /* tk_u  */
    tk_delete = 302,               /* tk_delete  */
    tk_add = 303,                  /* tk_add  */
    tk_fs = 304,                   /* tk_fs  */
    tk_r = 305,                    /* tk_r  */
    tk_ruta = 306,                 /* tk_ruta  */
    tk_entero = 307,               /* tk_entero  */
    tk_negativo = 308,             /* tk_negativo  */
    tk_cadena = 309,               /* tk_cadena  */
    tk_eruta = 310,                /* tk_eruta  */
    tk_identificador = 311,        /* tk_identificador  */
    tk_punto = 312,                /* tk_punto  */
    tk_menos = 313,                /* tk_menos  */
    tk_guionbajo = 314,            /* tk_guionbajo  */
    tk_asterisco = 315,            /* tk_asterisco  */
    tk_interrogacion = 316,        /* tk_interrogacion  */
    tk_igual = 317                 /* tk_igual  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

//se especifican los tipo de valores para los no terminales y lo terminales
//char TEXT [256];
//QString TEXT;
char TEXT[256];

#line 133 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
