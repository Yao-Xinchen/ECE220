/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ece220parse
#define yylex           ece220lex
#define yyerror         ece220error
#define yydebug         ece220debug
#define yynerrs         ece220nerrs
#define yylval          ece220lval
#define yychar          ece220char

/* First part of user prologue.  */
#line 37 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"

    #include <stdio.h>
    #include <stdlib.h>

    #include "ece220_lex.h"
    #include "ece220_parse.h"
    #include "ece220_symtab.h"
    #define YYSTYPE ast220_t*

    extern int ece220lex ();

    void parse_program ();

    static void var_create (ast220_t* name, ast220_t* a_len);
    static void start_main ();
    static ast220_t* new_ast_node ();
    static ast220_t* new_ast_num (int32_t value);
    static ast220_t* new_ast_str (char* str);
    static ast220_t* new_ast_func (ast220_builtin_func_t id);
    static ast220_t* new_ast_op (ast220_type_t type, ast220_t* left, 
    				 ast220_t* right);

    static int32_t reading_globals;
    static int32_t global_offset;
    static int32_t local_offset;
    static int32_t has_main;

    static ast220_t* ece220_main;

#line 108 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"

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

#include "ece220_parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_C220_KEY_IDENT = 3,             /* C220_KEY_IDENT  */
  YYSYMBOL_C220_KEY_INT = 4,               /* C220_KEY_INT  */
  YYSYMBOL_C220_KEY_MAIN = 5,              /* C220_KEY_MAIN  */
  YYSYMBOL_C220_KEY_INT_TYPE = 6,          /* C220_KEY_INT_TYPE  */
  YYSYMBOL_C220_KEY_STRING = 7,            /* C220_KEY_STRING  */
  YYSYMBOL_C220_KEY_ELSE = 8,              /* C220_KEY_ELSE  */
  YYSYMBOL_C220_KEY_FOR = 9,               /* C220_KEY_FOR  */
  YYSYMBOL_C220_KEY_IF = 10,               /* C220_KEY_IF  */
  YYSYMBOL_C220_KEY_RETURN = 11,           /* C220_KEY_RETURN  */
  YYSYMBOL_C220_KEY_PRINTF = 12,           /* C220_KEY_PRINTF  */
  YYSYMBOL_C220_KEY_RAND = 13,             /* C220_KEY_RAND  */
  YYSYMBOL_C220_KEY_SCANF = 14,            /* C220_KEY_SCANF  */
  YYSYMBOL_C220_KEY_SRAND = 15,            /* C220_KEY_SRAND  */
  YYSYMBOL_C220_KEY_INCR = 16,             /* C220_KEY_INCR  */
  YYSYMBOL_C220_KEY_DECR = 17,             /* C220_KEY_DECR  */
  YYSYMBOL_C220_KEY_UNARY_NEG = 18,        /* C220_KEY_UNARY_NEG  */
  YYSYMBOL_C220_KEY_DEBUG_MARKER = 19,     /* C220_KEY_DEBUG_MARKER  */
  YYSYMBOL_20_ = 20,                       /* '='  */
  YYSYMBOL_C220_KEY_AND = 21,              /* C220_KEY_AND  */
  YYSYMBOL_C220_KEY_OR = 22,               /* C220_KEY_OR  */
  YYSYMBOL_C220_KEY_EQ = 23,               /* C220_KEY_EQ  */
  YYSYMBOL_C220_KEY_NE = 24,               /* C220_KEY_NE  */
  YYSYMBOL_25_ = 25,                       /* '<'  */
  YYSYMBOL_C220_KEY_LE = 26,               /* C220_KEY_LE  */
  YYSYMBOL_C220_KEY_GE = 27,               /* C220_KEY_GE  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_34_ = 34,                       /* '&'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_C220_KEY_POST_ID = 36,          /* C220_KEY_POST_ID  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_declarations = 47,              /* declarations  */
  YYSYMBOL_one_decl = 48,                  /* one_decl  */
  YYSYMBOL_type = 49,                      /* type  */
  YYSYMBOL_var_list = 50,                  /* var_list  */
  YYSYMBOL_variable = 51,                  /* variable  */
  YYSYMBOL_ident = 52,                     /* ident  */
  YYSYMBOL_array_sizes = 53,               /* array_sizes  */
  YYSYMBOL_number = 54,                    /* number  */
  YYSYMBOL_main = 55,                      /* main  */
  YYSYMBOL_main_open = 56,                 /* main_open  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_simple_stmt = 59,               /* simple_stmt  */
  YYSYMBOL_maybe_else = 60,                /* maybe_else  */
  YYSYMBOL_compound_stmt = 61,             /* compound_stmt  */
  YYSYMBOL_maybe_expr = 62,                /* maybe_expr  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_var_ref = 64,                   /* var_ref  */
  YYSYMBOL_array_index = 65,               /* array_index  */
  YYSYMBOL_lval = 66,                      /* lval  */
  YYSYMBOL_fn_call = 67,                   /* fn_call  */
  YYSYMBOL_fn_name = 68,                   /* fn_name  */
  YYSYMBOL_maybe_args = 69,                /* maybe_args  */
  YYSYMBOL_arg_list = 70,                  /* arg_list  */
  YYSYMBOL_str_or_expr = 71,               /* str_or_expr  */
  YYSYMBOL_string = 72                     /* string  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
       2,     2,     2,    35,     2,     2,     2,    33,    34,     2,
      43,    44,    31,    29,    40,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      25,    20,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    26,
      27,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    89,    90,    93,    94,    97,    99,   101,
     102,   105,   107,   109,   110,   113,   115,   121,   123,   124,
     138,   139,   142,   143,   150,   159,   164,   170,   171,   174,
     176,   177,   184,   190,   193,   196,   199,   202,   203,   208,
     209,   212,   215,   218,   221,   224,   227,   230,   233,   236,
     239,   242,   245,   248,   251,   254,   255,   258,   275,   276,
     279,   281,   288,   289,   290,   291,   294,   295,   298,   299,
     305,   306,   309
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "C220_KEY_IDENT",
  "C220_KEY_INT", "C220_KEY_MAIN", "C220_KEY_INT_TYPE", "C220_KEY_STRING",
  "C220_KEY_ELSE", "C220_KEY_FOR", "C220_KEY_IF", "C220_KEY_RETURN",
  "C220_KEY_PRINTF", "C220_KEY_RAND", "C220_KEY_SCANF", "C220_KEY_SRAND",
  "C220_KEY_INCR", "C220_KEY_DECR", "C220_KEY_UNARY_NEG",
  "C220_KEY_DEBUG_MARKER", "'='", "C220_KEY_AND", "C220_KEY_OR",
  "C220_KEY_EQ", "C220_KEY_NE", "'<'", "C220_KEY_LE", "C220_KEY_GE", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", "'!'", "C220_KEY_POST_ID",
  "'['", "']'", "';'", "','", "'{'", "'}'", "'('", "')'", "$accept",
  "program", "declarations", "one_decl", "type", "var_list", "variable",
  "ident", "array_sizes", "number", "main", "main_open", "statements",
  "stmt", "simple_stmt", "maybe_else", "compound_stmt", "maybe_expr",
  "expr", "var_ref", "array_index", "lval", "fn_call", "fn_name",
  "maybe_args", "arg_list", "str_or_expr", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,     6,  -114,  -114,  -114,    33,  -114,   -34,  -114,   -19,
     -35,  -114,    17,  -114,    -5,  -114,    59,    75,  -114,    77,
    -114,  -114,  -114,    48,  -114,    59,    61,  -114,    44,    45,
     153,  -114,  -114,  -114,  -114,    59,    59,    47,   153,    59,
     153,  -114,  -114,   153,    55,  -114,  -114,  -114,  -114,    54,
     280,     5,    41,  -114,    51,   153,   153,   224,  -114,  -114,
    -114,    75,  -114,  -114,  -114,    96,   176,   153,  -114,  -114,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,  -114,  -114,   153,   129,    58,   200,  -114,
      57,  -114,  -114,   262,   291,   291,     2,     2,   -13,   -13,
     -13,   -13,    35,    35,  -114,  -114,  -114,   280,  -114,   280,
      70,    76,  -114,  -114,   153,    78,  -114,  -114,  -114,   129,
     243,    90,  -114,   153,    78,  -114,    73,  -114,    78,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     8,     3,     0,     4,     0,    12,     0,
       0,     9,    13,     5,     0,     7,     0,     0,    11,    18,
      17,    10,    15,     0,     6,     0,    30,    14,     0,     0,
       0,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    18,    16,     0,    58,    55,    19,    20,    21,     0,
      31,    37,     0,    39,     0,    30,     0,     0,    60,    35,
      36,     0,    40,    38,    41,    30,     0,     0,    57,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,    66,     0,     0,    25,
       0,    29,    56,     0,    53,    54,    50,    47,    48,    49,
      51,    52,    42,    43,    44,    45,    46,    32,    72,    70,
       0,    67,    68,    71,     0,     0,    26,    59,    61,     0,
       0,    27,    69,    30,     0,    23,     0,    28,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,  -114,    99,   101,  -114,   105,    -2,  -114,    -8,
    -114,  -114,    81,  -114,  -114,  -114,  -113,   -54,   -30,    24,
    -114,    46,  -114,  -114,  -114,  -114,     4,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    19,     4,     5,    10,    11,    44,    18,    45,
       6,     7,    26,    46,    47,   125,    48,    49,    50,    51,
      68,    52,    53,    54,   110,   111,   112,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    87,   121,    12,    15,    16,     2,    13,    62,    23,
      64,   127,     3,    66,    12,   129,    78,    79,    80,    81,
      82,   -60,   -60,    12,    14,   -60,    88,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     8,    93,     9,    20,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    90,    17,   107,   109,    83,    84,    58,
      58,    85,     8,    58,     8,    22,    80,    81,    82,   126,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    22,
      37,    59,    60,     3,   120,    63,    27,    55,    56,   109,
      61,    38,    67,    69,    86,    39,    40,   114,   124,     8,
      22,   116,    41,    42,    43,    28,    29,    30,    31,    32,
      33,    34,    35,    36,   118,    37,   119,   128,    24,    41,
      25,    21,    65,   122,     0,     0,    38,     0,     0,     0,
      39,    40,     8,    22,     0,     0,   108,    41,    91,    43,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    22,     0,    38,
       0,     0,     0,    39,    40,    31,    32,    33,    34,    35,
      36,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,    39,    40,     0,
       0,     0,     0,     0,     0,     0,    43,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,    89,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,   123,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
     117,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      30,    55,   115,     5,    39,    40,     0,    41,    38,    17,
      40,   124,     6,    43,    16,   128,    29,    30,    31,    32,
      33,    16,    17,    25,    43,    20,    56,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     3,    67,     5,    44,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    61,    37,    85,    86,    16,    17,    35,
      36,    20,     3,    39,     3,     4,    31,    32,    33,   123,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     4,
      19,    35,    36,     6,   114,    39,    38,    43,    43,   119,
      43,    30,    37,    39,    43,    34,    35,    39,     8,     3,
       4,    44,    41,    42,    43,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    44,    19,    40,    44,    19,    41,
      19,    16,    41,   119,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,     3,     4,    -1,    -1,     7,    41,    42,    43,
      -1,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    30,
      -1,    -1,    -1,    34,    35,    12,    13,    14,    15,    16,
      17,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    39,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,     0,     6,    48,    49,    55,    56,     3,     5,
      50,    51,    52,    41,    43,    39,    40,    37,    53,    47,
      44,    51,     4,    54,    48,    49,    57,    38,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    19,    30,    34,
      35,    41,    42,    43,    52,    54,    58,    59,    61,    62,
      63,    64,    66,    67,    68,    43,    43,    63,    64,    66,
      66,    43,    63,    66,    63,    57,    63,    37,    65,    39,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    16,    17,    20,    43,    62,    63,    39,
      54,    42,    44,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,     7,    63,
      69,    70,    71,    72,    39,    44,    44,    38,    44,    40,
      63,    61,    71,    39,     8,    60,    62,    61,    44,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    49,    50,
      50,    51,    52,    53,    53,    54,    55,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    65,
      66,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     3,     1,     1,
       3,     2,     1,     0,     3,     1,     5,     4,     0,     2,
       1,     1,     2,     6,     9,     3,     4,     0,     2,     3,
       0,     1,     3,     2,     2,     2,     2,     1,     2,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     2,     0,     3,
       1,     4,     1,     1,     1,     1,     0,     1,     1,     3,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* program: program main  */
#line 90 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                             {ece220_main = yyvsp[0];}
#line 1293 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 11: /* variable: ident array_sizes  */
#line 105 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                  { var_create (yyvsp[-1], yyvsp[0]); yyval = NULL;}
#line 1299 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 12: /* ident: C220_KEY_IDENT  */
#line 107 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                               {yyval = new_ast_str (ece220token.name);}
#line 1305 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 13: /* array_sizes: %empty  */
#line 109 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = new_ast_num (0);}
#line 1311 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 14: /* array_sizes: '[' number ']'  */
#line 110 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                               {yyval = yyvsp[-1];}
#line 1317 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 15: /* number: C220_KEY_INT  */
#line 113 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                             { yyval = new_ast_num (ece220token.ival); }
#line 1323 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 16: /* main: main_open '{' declarations statements '}'  */
#line 115 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                          {
		    reading_globals = 0;
		    yyval = yyvsp[-1];
		}
#line 1332 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 17: /* main_open: type C220_KEY_MAIN '(' ')'  */
#line 121 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                           {start_main ();}
#line 1338 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 18: /* statements: %empty  */
#line 123 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = NULL;}
#line 1344 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 19: /* statements: statements stmt  */
#line 124 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {
		    /* slow for long code, but simple... */
		    if (NULL == yyvsp[-1]) {
		        yyval = yyvsp[0];
		    } else {
			ast220_t* find;

			for (find = yyvsp[-1]; NULL != find->next; find = find->next);
			find->next = yyvsp[0];
			yyval = yyvsp[-1];
		    }
		}
#line 1361 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 20: /* stmt: simple_stmt  */
#line 138 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = yyvsp[0];}
#line 1367 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 21: /* stmt: compound_stmt  */
#line 139 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {yyval = yyvsp[0];}
#line 1373 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 22: /* simple_stmt: maybe_expr ';'  */
#line 142 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                               {yyval = yyvsp[-1];}
#line 1379 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 23: /* simple_stmt: C220_KEY_IF '(' expr ')' compound_stmt maybe_else  */
#line 143 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                                  {
	            yyval = new_ast_node ();
		    yyval->type = AST220_IF_STMT;
		    yyval->test = yyvsp[-3];
		    yyval->left = yyvsp[-1];
		    yyval->right = yyvsp[0];
		}
#line 1391 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 24: /* simple_stmt: C220_KEY_FOR '(' maybe_expr ';' expr ';' maybe_expr ')' compound_stmt  */
#line 151 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                          { 
	            yyval = new_ast_node ();
		    yyval->type = AST220_FOR_STMT;
		    yyval->test = yyvsp[-4];
		    yyval->left = yyvsp[-6];
		    yyval->middle = yyvsp[0];
		    yyval->right = yyvsp[-2];
		}
#line 1404 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 25: /* simple_stmt: C220_KEY_RETURN expr ';'  */
#line 159 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                         {
	            yyval = new_ast_node ();
		    yyval->type = AST220_RETURN_STMT;
		    yyval->left = yyvsp[-1];
	        }
#line 1414 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 26: /* simple_stmt: C220_KEY_DEBUG_MARKER '(' number ')'  */
#line 164 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                     {
	            yyval = yyvsp[-1];
		    yyval->type = AST220_DEBUG_MARKER;
	        }
#line 1423 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 27: /* maybe_else: %empty  */
#line 170 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = NULL;}
#line 1429 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 28: /* maybe_else: C220_KEY_ELSE compound_stmt  */
#line 171 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                            {yyval = yyvsp[0];}
#line 1435 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 29: /* compound_stmt: '{' statements '}'  */
#line 174 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                   {yyval = yyvsp[-1];}
#line 1441 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 30: /* maybe_expr: %empty  */
#line 176 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = NULL;}
#line 1447 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 31: /* maybe_expr: expr  */
#line 177 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                     {
	      	    yyval = new_ast_node (); 
		    yyval->type = AST220_POP_STACK; 
		    yyval->left = yyvsp[0];
		}
#line 1457 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 32: /* expr: lval '=' expr  */
#line 184 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_node ();
		    yyval->type = AST220_OP_ASSIGN;
		    yyval->left = yyvsp[-2];
		    yyval->right = yyvsp[0];
		}
#line 1468 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 33: /* expr: lval C220_KEY_INCR  */
#line 190 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                          {
	            yyval = new_ast_op (AST220_OP_POST_INCR, yyvsp[-1], NULL);
	        }
#line 1476 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 34: /* expr: lval C220_KEY_DECR  */
#line 193 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                          {
	            yyval = new_ast_op (AST220_OP_POST_DECR, yyvsp[-1], NULL);
	        }
#line 1484 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 35: /* expr: C220_KEY_INCR lval  */
#line 196 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                   {
	            yyval = new_ast_op (AST220_OP_PRE_INCR, yyvsp[0], NULL);
	        }
#line 1492 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 36: /* expr: C220_KEY_DECR lval  */
#line 199 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                   {
	            yyval = new_ast_op (AST220_OP_PRE_DECR, yyvsp[0], NULL);
	        }
#line 1500 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 37: /* expr: var_ref  */
#line 202 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                        {yyval = yyvsp[0];}
#line 1506 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 38: /* expr: '&' lval  */
#line 203 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                         {
	            yyval = new_ast_node ();
		    yyval->type = AST220_GET_ADDRESS;
		    yyval->left = yyvsp[0];
		}
#line 1516 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 39: /* expr: fn_call  */
#line 208 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                        {yyval = yyvsp[0];}
#line 1522 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 40: /* expr: '-' expr  */
#line 209 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                                  {
	            yyval = new_ast_op (AST220_OP_NEGATE, yyvsp[0], NULL);
	        }
#line 1530 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 41: /* expr: '!' expr  */
#line 212 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                         {
	            yyval = new_ast_op (AST220_OP_LOG_NOT, yyvsp[0], NULL);
	        }
#line 1538 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 42: /* expr: expr '+' expr  */
#line 215 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_OP_ADD, yyvsp[-2], yyvsp[0]);
	        }
#line 1546 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 43: /* expr: expr '-' expr  */
#line 218 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_OP_SUB, yyvsp[-2], yyvsp[0]);
	        }
#line 1554 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 44: /* expr: expr '*' expr  */
#line 221 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_OP_MULT, yyvsp[-2], yyvsp[0]);
	        }
#line 1562 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 45: /* expr: expr '/' expr  */
#line 224 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_OP_DIV, yyvsp[-2], yyvsp[0]);
	        }
#line 1570 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 46: /* expr: expr '%' expr  */
#line 227 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_OP_MOD, yyvsp[-2], yyvsp[0]);
	        }
#line 1578 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 47: /* expr: expr C220_KEY_NE expr  */
#line 230 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                      {
	            yyval = new_ast_op (AST220_CMP_NE, yyvsp[-2], yyvsp[0]);
	        }
#line 1586 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 48: /* expr: expr '<' expr  */
#line 233 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_CMP_LESS, yyvsp[-2], yyvsp[0]);
	        }
#line 1594 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 49: /* expr: expr C220_KEY_LE expr  */
#line 236 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                      {
	            yyval = new_ast_op (AST220_CMP_LE, yyvsp[-2], yyvsp[0]);
	        }
#line 1602 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 50: /* expr: expr C220_KEY_EQ expr  */
#line 239 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                      {
	            yyval = new_ast_op (AST220_CMP_EQ, yyvsp[-2], yyvsp[0]);
	        }
#line 1610 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 51: /* expr: expr C220_KEY_GE expr  */
#line 242 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                      {
	            yyval = new_ast_op (AST220_CMP_GE, yyvsp[-2], yyvsp[0]);
	        }
#line 1618 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 52: /* expr: expr '>' expr  */
#line 245 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                              {
	            yyval = new_ast_op (AST220_CMP_GREATER, yyvsp[-2], yyvsp[0]);
	        }
#line 1626 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 53: /* expr: expr C220_KEY_AND expr  */
#line 248 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                       {
	            yyval = new_ast_op (AST220_OP_LOG_AND, yyvsp[-2], yyvsp[0]);
	        }
#line 1634 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 54: /* expr: expr C220_KEY_OR expr  */
#line 251 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                      {
	            yyval = new_ast_op (AST220_OP_LOG_OR, yyvsp[-2], yyvsp[0]);
	        }
#line 1642 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 55: /* expr: number  */
#line 254 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                       {yyval = yyvsp[0]; yyval->type = AST220_PUSH_INT;}
#line 1648 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 56: /* expr: '(' expr ')'  */
#line 255 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                             {yyval = yyvsp[-1];}
#line 1654 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 57: /* var_ref: ident array_index  */
#line 258 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                  {
		    symtab_entry_t* entry = symtab_lookup (yyvsp[-1]->name);

		    if (NULL == entry ||
			(0 == entry->array_len && NULL != yyvsp[0]) ||
			(0 != entry->array_len && NULL == yyvsp[0])) {
			ece220errorf ("invalid variable access");
			/* should discard AST nodes here... */
			yyval = NULL;
		    } else {
			yyval = yyvsp[-1]; 
			yyval->type = AST220_VARIABLE;
			yyval->left = yyvsp[0];
		    }
		}
#line 1674 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 58: /* array_index: %empty  */
#line 275 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = NULL;}
#line 1680 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 59: /* array_index: '[' expr ']'  */
#line 276 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                             {yyval = yyvsp[-1];}
#line 1686 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 60: /* lval: var_ref  */
#line 279 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                        {yyval = yyvsp[0];}
#line 1692 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 61: /* fn_call: fn_name '(' maybe_args ')'  */
#line 281 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                           {
		    yyval = yyvsp[-3]; 
		    yyval->type = AST220_FUNC_CALL;
		    yyval->left = yyvsp[-1];
		}
#line 1702 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 62: /* fn_name: C220_KEY_PRINTF  */
#line 288 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {yyval = new_ast_func (AST220_PRINTF);}
#line 1708 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 63: /* fn_name: C220_KEY_RAND  */
#line 289 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {yyval = new_ast_func (AST220_RAND);}
#line 1714 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 64: /* fn_name: C220_KEY_SCANF  */
#line 290 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {yyval = new_ast_func (AST220_SCANF);}
#line 1720 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 65: /* fn_name: C220_KEY_SRAND  */
#line 291 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {yyval = new_ast_func (AST220_SRAND);}
#line 1726 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 66: /* maybe_args: %empty  */
#line 294 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = NULL;}
#line 1732 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 67: /* maybe_args: arg_list  */
#line 295 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                         {yyval = yyvsp[0];}
#line 1738 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 68: /* arg_list: str_or_expr  */
#line 298 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                            {yyval = yyvsp[0];}
#line 1744 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 69: /* arg_list: arg_list ',' str_or_expr  */
#line 299 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                         {
	            yyvsp[0]->next = yyvsp[-2];
		    yyval = yyvsp[0];
		}
#line 1753 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 70: /* str_or_expr: expr  */
#line 305 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                     {yyval = yyvsp[0];}
#line 1759 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 71: /* str_or_expr: string  */
#line 306 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                       {yyval = yyvsp[0]; yyval->type = AST220_PUSH_STR;}
#line 1765 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;

  case 72: /* string: C220_KEY_STRING  */
#line 309 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"
                                {yyval = new_ast_str (ece220token.name);}
#line 1771 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"
    break;


#line 1775 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  ++yynerrs;

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 311 "/home/xinchen/Dev/ECE220_test/mp11/ece220_parse.y"


ast220_t*
ece220_parse_program ()
{
    ece220_reset_lexer ();
    ece220_main = NULL;
    reading_globals = 1;
    global_offset = 0;
    local_offset = 0;
    has_main = 0;
    ece220parse ();
    return ece220_main;
}

static void
var_create (ast220_t* name, ast220_t* a_len)
{
    int32_t var_size;
    symtab_entry_t* entry;

    entry = symtab_create (name->name);
    if (NULL == entry) {
	ece220errorf ("can't create variable: %s", name->name);
    } else {
	entry->array_len = a_len->value;
	entry->is_global = reading_globals;
	var_size = (a_len->value == 0 ? 1 : a_len->value);
	if (reading_globals) {
	    entry->offset = global_offset;
	    global_offset += var_size;
	} else {
	    entry->offset = local_offset - (var_size - 1);
	    local_offset -= var_size;
	}
    }
    free (name->name);
    free (name);
    free (a_len);
}

static void 
start_main ()
{
    reading_globals = 0;
    if (has_main) {
        ece220errorf ("multiple main functions");
    } else {
        has_main = 1;
    }
}

static ast220_t* 
new_ast_node ()
{
    ast220_t* node;

    /* not good practice to terminate in the middle of the program... */
    if (NULL == (node = malloc (sizeof (ast220_t)))) {
        perror ("panic");
	exit (3);
    }
    return node;
}

static ast220_t* 
new_ast_num (int32_t value)
{
    ast220_t* node;

    node = new_ast_node ();
    node->value = value;
    return node;
}

static ast220_t* 
new_ast_str (char* str)
{
    ast220_t* node;

    node = new_ast_node ();
    node->name = str;
    return node;
}

static ast220_t* 
new_ast_func (ast220_builtin_func_t id)
{
    ast220_t* node;

    node = new_ast_node ();
    node->fnum = id;
    return node;
}

static ast220_t* 
new_ast_op (ast220_type_t type, ast220_t* left, ast220_t* right)
{
    ast220_t* node;

    node = new_ast_node ();
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

int32_t
ece220_local_var_space ()
{
    return -local_offset;
}

int32_t
ece220_global_var_space ()
{
    return global_offset;
}

