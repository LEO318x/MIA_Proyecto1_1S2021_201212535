/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "scanner.h"//se importa el header del analisis sintactico
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>
#include "clases/mkdisk.h"
#include "clases/rmdisk.h"
#include "clases/fdisk.h"
#include "clases/exec.h"
#include "clases/mount.h"
#include "clases/unmount.h"
#include "clases/mkfs.h"
#include "clases/login.h"
#include "clases/logout.h"
#include "clases/rep.h"
#include "clases/pausa.h"
#include "clases/mkdirc.h"


using namespace std;
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
std::string p_mkdisk[4]; // 0 = size, 1 = path, 2 = f,  3 = u
std::string p_fdisk[9]; // 0 = size, 1 = u, 2 = path, 3 = type, 4 = f, 5 = delete, 6 = name, 7 = add
std::string p_exec[1]; // 0 = ruta
std::string p_mount[2]; // 0 = path, 1 = name
std::string p_unmount[1]; // 0 = id
std::string p_mkfs[3]; // 0 = id, 1=type, 2=fs
std::string p_login[3]; //0=usuario, 1=password, 2=id
std::string p_rep[4]; // 0 = name, 1 = path, 2 = id, 3 = ruta
std::string p_mkdir[2]; //0 = ruta, 1 = p

bool pPrimero = true;
int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}

#line 113 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tk_mkdisk = 3,                  /* tk_mkdisk  */
  YYSYMBOL_tk_rmdisk = 4,                  /* tk_rmdisk  */
  YYSYMBOL_tk_fdisk = 5,                   /* tk_fdisk  */
  YYSYMBOL_tk_mount = 6,                   /* tk_mount  */
  YYSYMBOL_tk_unmount = 7,                 /* tk_unmount  */
  YYSYMBOL_tk_mkfs = 8,                    /* tk_mkfs  */
  YYSYMBOL_tk_login = 9,                   /* tk_login  */
  YYSYMBOL_tk_mkgrp = 10,                  /* tk_mkgrp  */
  YYSYMBOL_tk_rmgrp = 11,                  /* tk_rmgrp  */
  YYSYMBOL_tk_mkusr = 12,                  /* tk_mkusr  */
  YYSYMBOL_tk_rmusr = 13,                  /* tk_rmusr  */
  YYSYMBOL_tk_chmod = 14,                  /* tk_chmod  */
  YYSYMBOL_tk_mkfile = 15,                 /* tk_mkfile  */
  YYSYMBOL_tk_cat = 16,                    /* tk_cat  */
  YYSYMBOL_tk_rem = 17,                    /* tk_rem  */
  YYSYMBOL_tk_edit = 18,                   /* tk_edit  */
  YYSYMBOL_tk_ren = 19,                    /* tk_ren  */
  YYSYMBOL_tk_mkdir = 20,                  /* tk_mkdir  */
  YYSYMBOL_tk_cp = 21,                     /* tk_cp  */
  YYSYMBOL_tk_mv = 22,                     /* tk_mv  */
  YYSYMBOL_tk_find = 23,                   /* tk_find  */
  YYSYMBOL_tk_chown = 24,                  /* tk_chown  */
  YYSYMBOL_tk_chgrp = 25,                  /* tk_chgrp  */
  YYSYMBOL_tk_logout = 26,                 /* tk_logout  */
  YYSYMBOL_tk_pause = 27,                  /* tk_pause  */
  YYSYMBOL_tk_recovery = 28,               /* tk_recovery  */
  YYSYMBOL_tk_loss = 29,                   /* tk_loss  */
  YYSYMBOL_tk_exec = 30,                   /* tk_exec  */
  YYSYMBOL_tk_rep = 31,                    /* tk_rep  */
  YYSYMBOL_tk_size = 32,                   /* tk_size  */
  YYSYMBOL_tk_path = 33,                   /* tk_path  */
  YYSYMBOL_tk_type = 34,                   /* tk_type  */
  YYSYMBOL_tk_name = 35,                   /* tk_name  */
  YYSYMBOL_tk_id = 36,                     /* tk_id  */
  YYSYMBOL_tk_usr = 37,                    /* tk_usr  */
  YYSYMBOL_tk_pwd = 38,                    /* tk_pwd  */
  YYSYMBOL_tk_grp = 39,                    /* tk_grp  */
  YYSYMBOL_tk_ugo = 40,                    /* tk_ugo  */
  YYSYMBOL_tk_filen = 41,                  /* tk_filen  */
  YYSYMBOL_tk_cont = 42,                   /* tk_cont  */
  YYSYMBOL_tk_p = 43,                      /* tk_p  */
  YYSYMBOL_tk_dest = 44,                   /* tk_dest  */
  YYSYMBOL_tk_usuario = 45,                /* tk_usuario  */
  YYSYMBOL_tk_password = 46,               /* tk_password  */
  YYSYMBOL_tk_f = 47,                      /* tk_f  */
  YYSYMBOL_tk_u = 48,                      /* tk_u  */
  YYSYMBOL_tk_delete = 49,                 /* tk_delete  */
  YYSYMBOL_tk_add = 50,                    /* tk_add  */
  YYSYMBOL_tk_fs = 51,                     /* tk_fs  */
  YYSYMBOL_tk_r = 52,                      /* tk_r  */
  YYSYMBOL_tk_ruta = 53,                   /* tk_ruta  */
  YYSYMBOL_tk_entero = 54,                 /* tk_entero  */
  YYSYMBOL_tk_negativo = 55,               /* tk_negativo  */
  YYSYMBOL_tk_cadena = 56,                 /* tk_cadena  */
  YYSYMBOL_tk_eruta = 57,                  /* tk_eruta  */
  YYSYMBOL_tk_identificador = 58,          /* tk_identificador  */
  YYSYMBOL_tk_punto = 59,                  /* tk_punto  */
  YYSYMBOL_tk_menos = 60,                  /* tk_menos  */
  YYSYMBOL_tk_guionbajo = 61,              /* tk_guionbajo  */
  YYSYMBOL_tk_asterisco = 62,              /* tk_asterisco  */
  YYSYMBOL_tk_interrogacion = 63,          /* tk_interrogacion  */
  YYSYMBOL_tk_igual = 64,                  /* tk_igual  */
  YYSYMBOL_tk_comentario = 65,             /* tk_comentario  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_INICIO = 67,                    /* INICIO  */
  YYSYMBOL_LISTACOMANDOS = 68,             /* LISTACOMANDOS  */
  YYSYMBOL_COMANDOS = 69,                  /* COMANDOS  */
  YYSYMBOL_COMENTARIO = 70,                /* COMENTARIO  */
  YYSYMBOL_MKDISK = 71,                    /* MKDISK  */
  YYSYMBOL_LP_MKDISK = 72,                 /* LP_MKDISK  */
  YYSYMBOL_P_MKDISK = 73,                  /* P_MKDISK  */
  YYSYMBOL_RMDISK = 74,                    /* RMDISK  */
  YYSYMBOL_FDISK = 75,                     /* FDISK  */
  YYSYMBOL_LP_FDISK = 76,                  /* LP_FDISK  */
  YYSYMBOL_P_FDISK = 77,                   /* P_FDISK  */
  YYSYMBOL_EXEC = 78,                      /* EXEC  */
  YYSYMBOL_P_EXEC = 79,                    /* P_EXEC  */
  YYSYMBOL_MOUNT = 80,                     /* MOUNT  */
  YYSYMBOL_LP_MOUNT = 81,                  /* LP_MOUNT  */
  YYSYMBOL_P_MOUNT = 82,                   /* P_MOUNT  */
  YYSYMBOL_UNMOUNT = 83,                   /* UNMOUNT  */
  YYSYMBOL_P_UNMOUNT = 84,                 /* P_UNMOUNT  */
  YYSYMBOL_MKFS = 85,                      /* MKFS  */
  YYSYMBOL_LP_MKFS = 86,                   /* LP_MKFS  */
  YYSYMBOL_P_MKFS = 87,                    /* P_MKFS  */
  YYSYMBOL_LOGIN = 88,                     /* LOGIN  */
  YYSYMBOL_LP_LOGIN = 89,                  /* LP_LOGIN  */
  YYSYMBOL_P_LOGIN = 90,                   /* P_LOGIN  */
  YYSYMBOL_LOGOUT = 91,                    /* LOGOUT  */
  YYSYMBOL_REP = 92,                       /* REP  */
  YYSYMBOL_LP_REP = 93,                    /* LP_REP  */
  YYSYMBOL_P_REP = 94,                     /* P_REP  */
  YYSYMBOL_MKDIR = 95,                     /* MKDIR  */
  YYSYMBOL_LP_MKDIR = 96,                  /* LP_MKDIR  */
  YYSYMBOL_P_MKDIR = 97,                   /* P_MKDIR  */
  YYSYMBOL_PAUSE = 98                      /* PAUSE  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   131,   132,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   150,   152,
     155,   156,   159,   160,   161,   162,   163,   166,   167,   170,
     173,   174,   177,   179,   180,   182,   183,   185,   186,   187,
     188,   190,   192,   193,   196,   199,   200,   203,   206,   207,
     209,   210,   211,   212,   216,   219,   222,   225,   226,   229,
     230,   231,   234,   237,   238,   241,   242,   244,   245,   246,
     248,   251,   254,   257,   258,   261,   262,   264,   265,   268,
     270,   271,   275,   278,   279,   282,   283,   284,   287
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tk_mkdisk",
  "tk_rmdisk", "tk_fdisk", "tk_mount", "tk_unmount", "tk_mkfs", "tk_login",
  "tk_mkgrp", "tk_rmgrp", "tk_mkusr", "tk_rmusr", "tk_chmod", "tk_mkfile",
  "tk_cat", "tk_rem", "tk_edit", "tk_ren", "tk_mkdir", "tk_cp", "tk_mv",
  "tk_find", "tk_chown", "tk_chgrp", "tk_logout", "tk_pause",
  "tk_recovery", "tk_loss", "tk_exec", "tk_rep", "tk_size", "tk_path",
  "tk_type", "tk_name", "tk_id", "tk_usr", "tk_pwd", "tk_grp", "tk_ugo",
  "tk_filen", "tk_cont", "tk_p", "tk_dest", "tk_usuario", "tk_password",
  "tk_f", "tk_u", "tk_delete", "tk_add", "tk_fs", "tk_r", "tk_ruta",
  "tk_entero", "tk_negativo", "tk_cadena", "tk_eruta", "tk_identificador",
  "tk_punto", "tk_menos", "tk_guionbajo", "tk_asterisco",
  "tk_interrogacion", "tk_igual", "tk_comentario", "$accept", "INICIO",
  "LISTACOMANDOS", "COMANDOS", "COMENTARIO", "MKDISK", "LP_MKDISK",
  "P_MKDISK", "RMDISK", "FDISK", "LP_FDISK", "P_FDISK", "EXEC", "P_EXEC",
  "MOUNT", "LP_MOUNT", "P_MOUNT", "UNMOUNT", "P_UNMOUNT", "MKFS",
  "LP_MKFS", "P_MKFS", "LOGIN", "LP_LOGIN", "P_LOGIN", "LOGOUT", "REP",
  "LP_REP", "P_REP", "MKDIR", "LP_MKDIR", "P_MKDIR", "PAUSE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,   -34,   -21,    -5,    17,    19,    20,    21,    22,   -44,
     -44,    23,    24,   -44,    53,   -44,    -3,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -17,   -44,   -34,    28,   -14,   -44,    -5,     5,   -44,    17,
      29,   -44,   -26,   -44,    20,    -4,   -44,    21,     4,   -44,
      22,    43,   -44,   -24,   -44,    24,   -44,   -44,    25,    26,
      27,    30,   -44,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   -44,    40,    41,   -44,    42,    44,    45,    46,
     -44,    47,    48,    49,   -44,    50,   -44,   -44,    51,    52,
      54,    55,    56,   -44,    63,   -43,    64,    65,     1,    67,
       3,   -36,   -13,    66,    68,    69,     9,    10,    -7,    70,
      71,    72,    73,    74,    -6,   -10,    12,    14,    16,    -2,
      75,    18,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      88,     0,     0,    18,     0,     2,     4,    17,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    16,    15,
       0,    19,    21,     0,     0,    29,    31,     0,    47,    49,
       0,    54,     0,    56,    58,     0,    62,    64,     0,    82,
      84,     0,    44,     0,    72,    74,     1,     3,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,    48,     0,     0,     0,     0,
      57,     0,     0,     0,    63,     0,    87,    83,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    24,    23,    25,    26,    28,    27,    32,
      34,    33,    39,    38,    36,    35,    40,    37,    41,    42,
      43,    50,    51,    53,    52,    55,    60,    59,    61,    70,
      66,    65,    69,    68,    67,    86,    85,    45,    46,    78,
      77,    75,    76,    79,    81,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,    62,   -44,   -44,   -44,    60,   -44,   -44,   -44,
      57,   -44,   -44,   -44,   -44,    86,   -44,   -44,   -44,   -44,
      90,   -44,   -44,    88,   -44,   -44,   -44,    81,   -44,   -44,
      87,   -44,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    31,    32,    19,    20,
      35,    36,    21,    52,    22,    38,    39,    23,    41,    24,
      43,    44,    25,    46,    47,    26,    27,    54,    55,    28,
      49,    50,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,   132,    77,    89,
      78,    90,    91,   123,   124,    58,    59,     8,    64,    65,
      66,    67,   133,     9,    10,    79,    30,    11,    12,    92,
      60,    61,    81,    68,    69,    70,    71,    85,    73,    33,
      74,    82,    83,   134,   152,   135,   153,    86,   154,   143,
     150,   144,   151,    56,   161,    34,   162,   127,   128,   130,
     131,    63,    13,   139,   140,    76,   141,   142,   155,   156,
     157,   158,   159,   160,   164,   165,    88,    37,    57,    40,
      42,    45,    48,    51,    53,     0,     0,     0,     0,    94,
      95,    96,    62,    72,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   122,   119,   120,
     121,   129,   125,   126,   136,    75,   137,   138,   145,   146,
     147,   148,   149,   163,    80,    84,    93,    87
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    43,    34,    33,
      36,    35,    36,    56,    57,    32,    33,    20,    32,    33,
      34,    35,    58,    26,    27,    51,    60,    30,    31,    53,
      47,    48,    36,    47,    48,    49,    50,    33,    33,    60,
      35,    45,    46,    56,    54,    58,    56,    43,    58,    56,
      56,    58,    58,     0,    56,    60,    58,    56,    57,    56,
      57,    33,    65,    54,    55,    36,    56,    57,    56,    57,
      56,    57,    56,    57,    56,    57,    33,    60,    16,    60,
      60,    60,    60,    60,    60,    -1,    -1,    -1,    -1,    64,
      64,    64,    32,    36,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    -1,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    54,    64,    64,
      64,    54,    58,    58,    58,    39,    58,    58,    58,    58,
      58,    58,    58,    58,    44,    47,    55,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    20,    26,
      27,    30,    31,    65,    67,    68,    69,    70,    71,    74,
      75,    78,    80,    83,    85,    88,    91,    92,    95,    98,
      60,    72,    73,    60,    60,    76,    77,    60,    81,    82,
      60,    84,    60,    86,    87,    60,    89,    90,    60,    96,
      97,    60,    79,    60,    93,    94,     0,    68,    32,    33,
      47,    48,    72,    33,    32,    33,    34,    35,    47,    48,
      49,    50,    76,    33,    35,    81,    36,    34,    36,    51,
      86,    36,    45,    46,    89,    33,    43,    96,    33,    33,
      35,    36,    53,    93,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    54,    56,    57,    58,    58,    56,    57,    54,
      56,    57,    43,    58,    56,    58,    58,    58,    58,    54,
      55,    56,    57,    56,    58,    58,    58,    58,    58,    58,
      56,    58,    54,    56,    58,    56,    57,    56,    57,    56,
      57,    56,    58,    58,    56,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    71,
      72,    72,    73,    73,    73,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    79,    80,    81,    81,
      82,    82,    82,    82,    83,    84,    85,    86,    86,    87,
      87,    87,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    95,    96,    96,    97,    97,    97,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     4,     4,     4,     4,     4,     5,     5,     2,
       2,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     4,     4,     2,     2,     1,
       4,     4,     4,     4,     2,     4,     2,     2,     1,     4,
       4,     4,     2,     2,     1,     4,     4,     4,     4,     4,
       4,     1,     2,     2,     1,     4,     4,     4,     4,     4,
       4,     4,     2,     2,     1,     4,     4,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* INICIO: LISTACOMANDOS  */
#line 128 "parser.y"
                       {}
#line 1680 "parser.cpp"
    break;

  case 3: /* LISTACOMANDOS: COMANDOS LISTACOMANDOS  */
#line 131 "parser.y"
                                       {}
#line 1686 "parser.cpp"
    break;

  case 4: /* LISTACOMANDOS: COMANDOS  */
#line 132 "parser.y"
                           {}
#line 1692 "parser.cpp"
    break;

  case 5: /* COMANDOS: MKDISK  */
#line 135 "parser.y"
                 {}
#line 1698 "parser.cpp"
    break;

  case 6: /* COMANDOS: RMDISK  */
#line 136 "parser.y"
                 {}
#line 1704 "parser.cpp"
    break;

  case 7: /* COMANDOS: FDISK  */
#line 137 "parser.y"
                {}
#line 1710 "parser.cpp"
    break;

  case 8: /* COMANDOS: EXEC  */
#line 138 "parser.y"
               {}
#line 1716 "parser.cpp"
    break;

  case 9: /* COMANDOS: MOUNT  */
#line 139 "parser.y"
                {}
#line 1722 "parser.cpp"
    break;

  case 10: /* COMANDOS: UNMOUNT  */
#line 140 "parser.y"
                  {}
#line 1728 "parser.cpp"
    break;

  case 11: /* COMANDOS: MKFS  */
#line 141 "parser.y"
               {}
#line 1734 "parser.cpp"
    break;

  case 12: /* COMANDOS: LOGIN  */
#line 142 "parser.y"
                {}
#line 1740 "parser.cpp"
    break;

  case 13: /* COMANDOS: LOGOUT  */
#line 143 "parser.y"
                 {}
#line 1746 "parser.cpp"
    break;

  case 14: /* COMANDOS: REP  */
#line 144 "parser.y"
              {}
#line 1752 "parser.cpp"
    break;

  case 15: /* COMANDOS: PAUSE  */
#line 145 "parser.y"
                {}
#line 1758 "parser.cpp"
    break;

  case 16: /* COMANDOS: MKDIR  */
#line 146 "parser.y"
                {}
#line 1764 "parser.cpp"
    break;

  case 17: /* COMANDOS: COMENTARIO  */
#line 147 "parser.y"
                     {}
#line 1770 "parser.cpp"
    break;

  case 19: /* MKDISK: tk_mkdisk LP_MKDISK  */
#line 152 "parser.y"
                            {mkdisk disco; disco.crearDisco(p_mkdisk); for (int i=0; i < 4; i++)p_mkdisk[i].clear();}
#line 1776 "parser.cpp"
    break;

  case 20: /* LP_MKDISK: P_MKDISK LP_MKDISK  */
#line 155 "parser.y"
                               {}
#line 1782 "parser.cpp"
    break;

  case 21: /* LP_MKDISK: P_MKDISK  */
#line 156 "parser.y"
                   {}
#line 1788 "parser.cpp"
    break;

  case 22: /* P_MKDISK: tk_menos tk_size tk_igual tk_entero  */
#line 159 "parser.y"
                                                {p_mkdisk[0] = (yyvsp[0].TEXT);}
#line 1794 "parser.cpp"
    break;

  case 23: /* P_MKDISK: tk_menos tk_path tk_igual tk_eruta  */
#line 160 "parser.y"
                                         {p_mkdisk[1] = (yyvsp[0].TEXT);}
#line 1800 "parser.cpp"
    break;

  case 24: /* P_MKDISK: tk_menos tk_path tk_igual tk_cadena  */
#line 161 "parser.y"
                                          {p_mkdisk[1] = (yyvsp[0].TEXT);}
#line 1806 "parser.cpp"
    break;

  case 25: /* P_MKDISK: tk_menos tk_f tk_igual tk_identificador  */
#line 162 "parser.y"
                                              {p_mkdisk[2]= (yyvsp[0].TEXT);}
#line 1812 "parser.cpp"
    break;

  case 26: /* P_MKDISK: tk_menos tk_u tk_igual tk_identificador  */
#line 163 "parser.y"
                                              {p_mkdisk[3] = (yyvsp[0].TEXT);}
#line 1818 "parser.cpp"
    break;

  case 27: /* RMDISK: tk_rmdisk tk_menos tk_path tk_igual tk_eruta  */
#line 166 "parser.y"
                                                     {rmdisk disco2; disco2.eliminarDisco((yyvsp[0].TEXT));}
#line 1824 "parser.cpp"
    break;

  case 28: /* RMDISK: tk_rmdisk tk_menos tk_path tk_igual tk_cadena  */
#line 167 "parser.y"
                                                    {rmdisk disco2; disco2.eliminarDisco((yyvsp[0].TEXT));}
#line 1830 "parser.cpp"
    break;

  case 29: /* FDISK: tk_fdisk LP_FDISK  */
#line 170 "parser.y"
                         {fdisk fdisk(p_fdisk);  fdisk.ejecutarFdisk(); for (int i=0; i < 9; i++){p_fdisk[i].clear();} pPrimero = true;}
#line 1836 "parser.cpp"
    break;

  case 30: /* LP_FDISK: P_FDISK LP_FDISK  */
#line 173 "parser.y"
                           {}
#line 1842 "parser.cpp"
    break;

  case 31: /* LP_FDISK: P_FDISK  */
#line 174 "parser.y"
                  {}
#line 1848 "parser.cpp"
    break;

  case 32: /* P_FDISK: tk_menos tk_size tk_igual tk_entero  */
#line 177 "parser.y"
                                             {p_fdisk[0]=(yyvsp[0].TEXT); if(pPrimero){pPrimero = false; p_fdisk[8] = "size";}}
#line 1854 "parser.cpp"
    break;

  case 33: /* P_FDISK: tk_menos tk_path tk_igual tk_eruta  */
#line 179 "parser.y"
                                             {p_fdisk[2]=(yyvsp[0].TEXT);}
#line 1860 "parser.cpp"
    break;

  case 34: /* P_FDISK: tk_menos tk_path tk_igual tk_cadena  */
#line 180 "parser.y"
                                              {p_fdisk[2]=(yyvsp[0].TEXT);}
#line 1866 "parser.cpp"
    break;

  case 35: /* P_FDISK: tk_menos tk_name tk_igual tk_identificador  */
#line 182 "parser.y"
                                                     {p_fdisk[6]=(yyvsp[0].TEXT);}
#line 1872 "parser.cpp"
    break;

  case 36: /* P_FDISK: tk_menos tk_name tk_igual tk_cadena  */
#line 183 "parser.y"
                                              {p_fdisk[6]=(yyvsp[0].TEXT);}
#line 1878 "parser.cpp"
    break;

  case 37: /* P_FDISK: tk_menos tk_u tk_igual tk_identificador  */
#line 185 "parser.y"
                                                  {p_fdisk[1]=(yyvsp[0].TEXT);}
#line 1884 "parser.cpp"
    break;

  case 38: /* P_FDISK: tk_menos tk_type tk_igual tk_identificador  */
#line 186 "parser.y"
                                                     {p_fdisk[3]=(yyvsp[0].TEXT);}
#line 1890 "parser.cpp"
    break;

  case 39: /* P_FDISK: tk_menos tk_type tk_igual tk_p  */
#line 187 "parser.y"
                                         {p_fdisk[3]=(yyvsp[0].TEXT);}
#line 1896 "parser.cpp"
    break;

  case 40: /* P_FDISK: tk_menos tk_f tk_igual tk_identificador  */
#line 188 "parser.y"
                                                  {p_fdisk[4]=(yyvsp[0].TEXT);}
#line 1902 "parser.cpp"
    break;

  case 41: /* P_FDISK: tk_menos tk_delete tk_igual tk_identificador  */
#line 190 "parser.y"
                                                       {p_fdisk[5]=(yyvsp[0].TEXT); if(pPrimero){pPrimero = false; p_fdisk[8] = "delete";}}
#line 1908 "parser.cpp"
    break;

  case 42: /* P_FDISK: tk_menos tk_add tk_igual tk_entero  */
#line 192 "parser.y"
                                             {p_fdisk[7]=(yyvsp[0].TEXT); if(pPrimero){pPrimero = false; p_fdisk[8] = "add";}}
#line 1914 "parser.cpp"
    break;

  case 43: /* P_FDISK: tk_menos tk_add tk_igual tk_negativo  */
#line 193 "parser.y"
                                               {p_fdisk[7]=(yyvsp[0].TEXT); if(pPrimero){pPrimero = false; p_fdisk[8] = "add";}}
#line 1920 "parser.cpp"
    break;

  case 44: /* EXEC: tk_exec P_EXEC  */
#line 196 "parser.y"
                     {exec exec(p_exec); exec.ejecutar(); p_exec[0].clear();}
#line 1926 "parser.cpp"
    break;

  case 45: /* P_EXEC: tk_menos tk_path tk_igual tk_cadena  */
#line 199 "parser.y"
                                            {p_exec[0] = (yyvsp[0].TEXT);}
#line 1932 "parser.cpp"
    break;

  case 46: /* P_EXEC: tk_menos tk_path tk_igual tk_eruta  */
#line 200 "parser.y"
                                             {p_exec[0] = (yyvsp[0].TEXT);}
#line 1938 "parser.cpp"
    break;

  case 47: /* MOUNT: tk_mount LP_MOUNT  */
#line 203 "parser.y"
                         {mount mount(p_mount); mount.ejecutar(); p_mount[0].clear(); p_mount[1].clear();}
#line 1944 "parser.cpp"
    break;

  case 48: /* LP_MOUNT: P_MOUNT LP_MOUNT  */
#line 206 "parser.y"
                           {}
#line 1950 "parser.cpp"
    break;

  case 49: /* LP_MOUNT: P_MOUNT  */
#line 207 "parser.y"
                  {}
#line 1956 "parser.cpp"
    break;

  case 50: /* P_MOUNT: tk_menos tk_path tk_igual tk_cadena  */
#line 209 "parser.y"
                                             {p_mount[0] = (yyvsp[0].TEXT);}
#line 1962 "parser.cpp"
    break;

  case 51: /* P_MOUNT: tk_menos tk_path tk_igual tk_eruta  */
#line 210 "parser.y"
                                             {p_mount[0] = (yyvsp[0].TEXT);}
#line 1968 "parser.cpp"
    break;

  case 52: /* P_MOUNT: tk_menos tk_name tk_igual tk_identificador  */
#line 211 "parser.y"
                                                     {p_mount[1] = (yyvsp[0].TEXT);}
#line 1974 "parser.cpp"
    break;

  case 53: /* P_MOUNT: tk_menos tk_name tk_igual tk_cadena  */
#line 212 "parser.y"
                                              {p_mount[1] = (yyvsp[0].TEXT);}
#line 1980 "parser.cpp"
    break;

  case 54: /* UNMOUNT: tk_unmount P_UNMOUNT  */
#line 216 "parser.y"
                              {unmount unmount(p_unmount); unmount.ejecutar(); p_unmount[0].clear();}
#line 1986 "parser.cpp"
    break;

  case 55: /* P_UNMOUNT: tk_menos tk_id tk_igual tk_identificador  */
#line 219 "parser.y"
                                                    {p_unmount[0] = (yyvsp[0].TEXT);}
#line 1992 "parser.cpp"
    break;

  case 56: /* MKFS: tk_mkfs LP_MKFS  */
#line 222 "parser.y"
                      {mkfs mkfs(p_mkfs); mkfs.ejecutar(); for(int i=0; i < 3; i++){p_mkfs[i].clear();}}
#line 1998 "parser.cpp"
    break;

  case 59: /* P_MKFS: tk_menos tk_id tk_igual tk_identificador  */
#line 229 "parser.y"
                                                 {p_mkfs[0] = (yyvsp[0].TEXT);}
#line 2004 "parser.cpp"
    break;

  case 60: /* P_MKFS: tk_menos tk_type tk_igual tk_identificador  */
#line 230 "parser.y"
                                                     {p_mkfs[1] = (yyvsp[0].TEXT);}
#line 2010 "parser.cpp"
    break;

  case 61: /* P_MKFS: tk_menos tk_fs tk_igual tk_identificador  */
#line 231 "parser.y"
                                                   {p_mkfs[2] = (yyvsp[0].TEXT);}
#line 2016 "parser.cpp"
    break;

  case 62: /* LOGIN: tk_login LP_LOGIN  */
#line 234 "parser.y"
                         {login login(p_login); login.ejecutar(); for(int i=0; i < 3; i++){p_login[i].clear();}}
#line 2022 "parser.cpp"
    break;

  case 65: /* P_LOGIN: tk_menos tk_usuario tk_igual tk_identificador  */
#line 241 "parser.y"
                                                       {p_login[0] = (yyvsp[0].TEXT);}
#line 2028 "parser.cpp"
    break;

  case 66: /* P_LOGIN: tk_menos tk_usuario tk_igual tk_cadena  */
#line 242 "parser.y"
                                                 {p_login[0] = (yyvsp[0].TEXT);}
#line 2034 "parser.cpp"
    break;

  case 67: /* P_LOGIN: tk_menos tk_password tk_igual tk_identificador  */
#line 244 "parser.y"
                                                        {p_login[1] = (yyvsp[0].TEXT);}
#line 2040 "parser.cpp"
    break;

  case 68: /* P_LOGIN: tk_menos tk_password tk_igual tk_cadena  */
#line 245 "parser.y"
                                                 {p_login[1] = (yyvsp[0].TEXT);}
#line 2046 "parser.cpp"
    break;

  case 69: /* P_LOGIN: tk_menos tk_password tk_igual tk_entero  */
#line 246 "parser.y"
                                                 {p_login[1] = (yyvsp[0].TEXT);}
#line 2052 "parser.cpp"
    break;

  case 70: /* P_LOGIN: tk_menos tk_id tk_igual tk_identificador  */
#line 248 "parser.y"
                                                  {p_login[2] = (yyvsp[0].TEXT);}
#line 2058 "parser.cpp"
    break;

  case 71: /* LOGOUT: tk_logout  */
#line 251 "parser.y"
                  {logout logout; logout.ejecutar();}
#line 2064 "parser.cpp"
    break;

  case 72: /* REP: tk_rep LP_REP  */
#line 254 "parser.y"
                   {rep rep(p_rep); rep.ejecutar(); for(int i=0; i < 4; i++){p_rep[i].clear();}}
#line 2070 "parser.cpp"
    break;

  case 75: /* P_REP: tk_menos tk_name tk_igual tk_cadena  */
#line 261 "parser.y"
                                           {p_rep[0] = (yyvsp[0].TEXT);}
#line 2076 "parser.cpp"
    break;

  case 76: /* P_REP: tk_menos tk_name tk_igual tk_identificador  */
#line 262 "parser.y"
                                                  {p_rep[0] = (yyvsp[0].TEXT);}
#line 2082 "parser.cpp"
    break;

  case 77: /* P_REP: tk_menos tk_path tk_igual tk_eruta  */
#line 264 "parser.y"
                                          {p_rep[1] = (yyvsp[0].TEXT);}
#line 2088 "parser.cpp"
    break;

  case 78: /* P_REP: tk_menos tk_path tk_igual tk_cadena  */
#line 265 "parser.y"
                                           {p_rep[1] = (yyvsp[0].TEXT);}
#line 2094 "parser.cpp"
    break;

  case 79: /* P_REP: tk_menos tk_id tk_igual tk_identificador  */
#line 268 "parser.y"
                                                {p_rep[2] = (yyvsp[0].TEXT);}
#line 2100 "parser.cpp"
    break;

  case 80: /* P_REP: tk_menos tk_ruta tk_igual tk_eruta  */
#line 270 "parser.y"
                                          {p_rep[3] = (yyvsp[0].TEXT);}
#line 2106 "parser.cpp"
    break;

  case 81: /* P_REP: tk_menos tk_ruta tk_igual tk_cadena  */
#line 271 "parser.y"
                                           {p_rep[3] = (yyvsp[0].TEXT);}
#line 2112 "parser.cpp"
    break;

  case 82: /* MKDIR: tk_mkdir LP_MKDIR  */
#line 275 "parser.y"
                         {mkdirc mkdirc(p_mkdir); mkdirc.ejecutar(); p_mkdir[0].clear(); p_mkdir[1].clear();}
#line 2118 "parser.cpp"
    break;

  case 85: /* P_MKDIR: tk_menos tk_path tk_igual tk_eruta  */
#line 282 "parser.y"
                                            {p_mkdir[0] = (yyvsp[0].TEXT);}
#line 2124 "parser.cpp"
    break;

  case 86: /* P_MKDIR: tk_menos tk_path tk_igual tk_cadena  */
#line 283 "parser.y"
                                              {p_mkdir[0] = (yyvsp[0].TEXT);}
#line 2130 "parser.cpp"
    break;

  case 87: /* P_MKDIR: tk_menos tk_p  */
#line 284 "parser.y"
                        {p_mkdir[1] = (yyvsp[0].TEXT);}
#line 2136 "parser.cpp"
    break;

  case 88: /* PAUSE: tk_pause  */
#line 287 "parser.y"
                {pausa pausa;}
#line 2142 "parser.cpp"
    break;


#line 2146 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

