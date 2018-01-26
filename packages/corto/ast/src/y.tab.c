/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ast.y" /* yacc.c:339  */


#include "corto/ast/ast.h"
#include "ast__private.h"

/* Forward declarations of yacc functions */
void yyerror(const char *str);
int yylex(void);
int yylex_destroy(void);
int yy_scan_string(const char* str);

#define PUSHLVALUE(l) ast_Parser_pushLvalue(yparser(), l, FALSE); fast_op;
#define PUSHASSIGN(l) ast_Parser_pushLvalue(yparser(), l, TRUE); fast_op;
#define POPLVALUE()   ast_Parser_popLvalue(yparser()); fast_op;
#define YYERROR_VERBOSE

#define PUSHCOMPLEX(l) ast_Parser_pushComplexType(yparser(), l); fast_op;
#define POPCOMPLEX() ast_Parser_popComplexType(yparser()); fast_op;

/* Thread local storage key for parser */
extern corto_tls ast_PARSER_KEY;

/* Obtain parser */
ast_Parser yparser(void) {
    return (ast_Parser)corto_tls_get(ast_PARSER_KEY);
}

#define fast_err(...) _fast_err(__VA_ARGS__); YYERROR;
#define fast_op if (ast_Parser_isAbortSet(yparser())) {YYABORT;} else if (ast_Parser_isErrSet(yparser())) {YYERROR;}

/* Report error */
void _fast_err(corto_string msg, ...) {
    va_list args;
    char msgbuff[1024];

    va_start(args, msg);
    vsprintf(msgbuff, msg, args);
    va_end(args);

    ast_reportError(yparser()->filename, yparser()->line, yparser()->column, msgbuff, yparser()->token);

    yparser()->errors++;
}

void ast_declarationSeqInsert( ast_ParserDeclarationSeq *seq, ast_ParserDeclaration *declaration )
{
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, sizeof(ast_ParserDeclaration) * seq->length);
    memcpy(&seq->buffer[seq->length-1], declaration, sizeof(ast_ParserDeclaration));
    seq->buffer[seq->length-1].name = corto_strdup(seq->buffer[seq->length-1].name);
}

ast_Expression ast_declarationSeqDo(ast_Storage type, ast_ParserDeclarationSeq *declarations, corto_bool isReference)
{
    unsigned int i;
    ast_Comma result = ast_Comma__create(NULL, NULL);
    ast_Expression expr = NULL;

    ast_Parser_collect(yparser(), result);
    yparser()->variableCount = 0;

    for(i = 0; i < declarations->length; i++)
    {
        type = ast_Storage(ast_Expression_resolve(type, NULL));

        if (type && !corto_instanceof(corto_type_o, ast_Object(type)->value)) {
            _fast_err("object in declaration is not a type");
            goto error;
        }

        if (!(declarations->buffer[i].storage = ast_Parser_declaration(
            yparser(),
            type ? ast_Object(type)->value : NULL,
            declarations->buffer[i].name,
            isReference)))
        {
            goto error;
        }

        corto_dealloc(declarations->buffer[i].name);
        expr = ast_Expression(declarations->buffer[i].storage);

        /* In a declaration of locals assignment is always a reference-assignment. */
        if (isReference) {
            expr = ast_Expression(
                ast_Parser_unaryExpr(yparser(),
                expr,
                CORTO_AND));

            ast_Parser_collect(yparser(), expr);
        }

        ast_Comma_addExpression(result, expr);
    }

    corto_dealloc(declarations->buffer);
    declarations->buffer = NULL;
    declarations->length = 0;

    return ast_Expression(result);
error:
    corto_dealloc(declarations->buffer);
    declarations->buffer = NULL;
    declarations->length = 0;

    return NULL;
}


#line 176 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    BOOLEAN = 259,
    CHARACTER = 260,
    INTEGER = 261,
    SIGNEDINTEGER = 262,
    FLOATINGPOINT = 263,
    STRING = 264,
    NUL = 265,
    ID = 266,
    GID = 267,
    PACKAGE = 268,
    IMPORT = 269,
    MUL_ASSIGN = 270,
    DIV_ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    OR_ASSIGN = 274,
    AND_ASSIGN = 275,
    UPDATE_ASSIGN = 276,
    LOR = 277,
    LAND = 278,
    LNOT = 279,
    LEQ = 280,
    GEQ = 281,
    EQ = 282,
    NEQ = 283,
    INC = 284,
    DEC = 285,
    SCOPE = 286,
    SCOPEPRE = 287,
    SHIFT_LEFT = 288,
    SHIFT_RIGHT = 289,
    ARROW_LEFT = 290,
    ARROW_RIGHT = 291,
    ENDL = 292,
    TAB = 293,
    INDENT = 294,
    DEDENT = 295,
    KW_IF = 296,
    KW_ELSE = 297,
    KW_WHILE = 298,
    KW_SWITCH = 299,
    KW_CASE = 300,
    KW_BREAK = 301,
    KW_FOR = 302,
    KW_TRY = 303,
    KW_CATCH = 304,
    KW_IN = 305,
    KW_IMPORT = 306,
    KW_LOCAL = 307
  };
#endif
/* Tokens.  */
#define ERROR 258
#define BOOLEAN 259
#define CHARACTER 260
#define INTEGER 261
#define SIGNEDINTEGER 262
#define FLOATINGPOINT 263
#define STRING 264
#define NUL 265
#define ID 266
#define GID 267
#define PACKAGE 268
#define IMPORT 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define OR_ASSIGN 274
#define AND_ASSIGN 275
#define UPDATE_ASSIGN 276
#define LOR 277
#define LAND 278
#define LNOT 279
#define LEQ 280
#define GEQ 281
#define EQ 282
#define NEQ 283
#define INC 284
#define DEC 285
#define SCOPE 286
#define SCOPEPRE 287
#define SHIFT_LEFT 288
#define SHIFT_RIGHT 289
#define ARROW_LEFT 290
#define ARROW_RIGHT 291
#define ENDL 292
#define TAB 293
#define INDENT 294
#define DEDENT 295
#define KW_IF 296
#define KW_ELSE 297
#define KW_WHILE 298
#define KW_SWITCH 299
#define KW_CASE 300
#define KW_BREAK 301
#define KW_FOR 302
#define KW_TRY 303
#define KW_CATCH 304
#define KW_IN 305
#define KW_IMPORT 306
#define KW_LOCAL 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 145 "ast.y" /* yacc.c:355  */

    /* Literals */
    corto_bool Boolean;
    corto_char Character;
    corto_uint64 Integer;
    corto_int64 SignedInteger;
    corto_float64 FloatingPoint;
    corto_string String;
    corto_object Reference;
    corto_string Identifier;
    corto_ll List;
    void *Null;
    void *ast;
    corto_operatorKind Operator;
    int Mask;
    ast_ParserDeclaration Declaration;
    ast_ParserDeclarationSeq Declarations;
    ast_ParserNew New;
    ast_Storage Variable;

#line 341 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 358 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   815

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,    59,    71,    55,     2,
      56,    57,    63,    72,    58,    67,    66,    70,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
      75,    54,    76,    77,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    73,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,    74,    61,    68,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   213,   213,   217,   218,   219,   228,   229,   230,   231,
     231,   232,   233,   234,   238,   239,   240,   241,   242,   243,
     244,   251,   252,   253,   253,   254,   254,   258,   259,   266,
     270,   270,   271,   271,   278,   278,   285,   285,   301,   318,
     334,   337,   338,   349,   353,   354,   358,   359,   363,   364,
     368,   369,   373,   380,   387,   403,   406,   412,   418,   424,
     425,   425,   429,   430,   434,   435,   439,   440,   441,   448,
     449,   453,   454,   458,   459,   463,   463,   463,   464,   468,
     469,   473,   473,   474,   478,   478,   479,   486,   487,   488,
     489,   490,   491,   492,   496,   496,   500,   501,   502,   506,
     507,   511,   512,   512,   513,   514,   515,   516,   517,   521,
     522,   526,   527,   528,   529,   530,   531,   532,   536,   537,
     537,   537,   541,   542,   543,   547,   548,   548,   548,   552,
     553,   557,   558,   558,   558,   559,   559,   559,   563,   564,
     564,   564,   568,   569,   569,   569,   573,   574,   574,   574,
     578,   579,   579,   579,   583,   584,   585,   586,   590,   591,
     591,   591,   595,   596,   600,   601,   601,   601,   605,   606,
     606,   606,   610,   610,   611,   615,   616,   620,   621,   634,
     635,   635,   635,   641,   642,   643,   644,   645,   646,   647,
     648,   652,   653,   653,   660,   666,   666,   667,   667,   667,
     668,   668,   669,   670,   670,   683,   690,   691,   691,   702,
     706,   707,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   733,   734,
     735,   739,   746,   747,   751
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "BOOLEAN", "CHARACTER",
  "INTEGER", "SIGNEDINTEGER", "FLOATINGPOINT", "STRING", "NUL", "ID",
  "GID", "PACKAGE", "IMPORT", "MUL_ASSIGN", "DIV_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "OR_ASSIGN", "AND_ASSIGN", "UPDATE_ASSIGN", "LOR", "LAND",
  "LNOT", "LEQ", "GEQ", "EQ", "NEQ", "INC", "DEC", "SCOPE", "SCOPEPRE",
  "SHIFT_LEFT", "SHIFT_RIGHT", "ARROW_LEFT", "ARROW_RIGHT", "ENDL", "TAB",
  "INDENT", "DEDENT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_SWITCH",
  "KW_CASE", "KW_BREAK", "KW_FOR", "KW_TRY", "KW_CATCH", "KW_IN",
  "KW_IMPORT", "KW_LOCAL", "':'", "'='", "'&'", "'('", "')'", "','", "'$'",
  "'{'", "'}'", "'@'", "'*'", "'['", "']'", "'.'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'+'", "'^'", "'|'", "'<'", "'>'", "'?'", "$accept",
  "code", "statements", "statement_nodecl", "@1", "statement", "scope",
  "$@2", "$@3", "scope_statement", "block_start", "block", "$@4", "@5",
  "function_implementation", "@6", "@7", "function_declaration",
  "function_argumentList", "function_arguments", "function_argument_inout",
  "argument_inout", "function_argument", "package_declaration",
  "import_declaration", "in_declaration", "declaration", "$@8",
  "declaration_ref", "declaration_list", "declaration_id", "initializer",
  "init_list_value", "init_value", "initializer_braces", "$@9", "$@10",
  "init_list_colon", "init_colon", "$@11", "init_key", "$@12",
  "literal_expr", "bracket_expr", "$@13", "primary_expr", "iter_expr",
  "postfix_expr", "$@14", "unary_expr", "unary_operator",
  "multiplicative_expr", "$@15", "$@16", "multiplicative_operator",
  "additive_expr", "$@17", "$@18", "additive_operator", "shift_expr",
  "$@19", "$@20", "$@21", "$@22", "and_expr", "$@23", "$@24", "xor_expr",
  "$@25", "$@26", "or_expr", "$@27", "$@28", "boolean_expr", "$@29",
  "$@30", "boolean_operator", "equality_expr", "$@31", "$@32",
  "equality_operator", "logical_and_expr", "$@33", "$@34",
  "logical_or_expr", "$@35", "$@36", "initializer_expr", "@37",
  "conditional_expr", "comma_expr", "assignment_expr", "$@38", "$@39",
  "assignment_operator", "declaration_expr", "$@40", "$@41", "$@42",
  "$@43", "$@44", "$@45", "expr", "identifier", "@46", "identifier_id",
  "identifier_string", "any_id", "if_statement", "if_start",
  "while_statement", "while_until", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    58,    61,    38,    40,    41,    44,    36,
     123,   125,    64,    42,    91,    93,    46,    45,   126,    33,
      47,    37,    43,    94,   124,    60,    62,    63
};
# endif

#define YYPACT_NINF -260

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-260)))

#define YYTABLE_NINF -235

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     256,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,    96,    24,  -260,  -260,  -260,  -260,  -260,   728,   728,
      77,  -260,     8,  -260,  -260,   763,    53,  -260,  -260,  -260,
      49,   322,  -260,  -260,  -260,   256,  -260,  -260,   -14,    14,
      31,    33,   152,  -260,  -260,  -260,  -260,   187,  -260,    53,
     140,   -34,   175,    46,    45,    48,    28,   200,   101,   110,
      57,    66,  -260,    82,   250,  -260,   123,    17,  -260,  -260,
    -260,  -260,   112,  -260,   -11,  -260,  -260,  -260,   133,   139,
      -7,  -260,   176,    13,  -260,   586,   728,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,   183,   322,  -260,   112,   150,
    -260,  -260,  -260,  -260,   104,  -260,   161,  -260,  -260,   172,
      55,  -260,   170,   187,   184,    38,   192,   207,   191,   198,
     174,   157,   231,   233,   254,   728,   218,  -260,   728,   213,
     726,  -260,   232,  -260,   100,   234,  -260,    66,   232,   247,
    -260,  -260,  -260,  -260,  -260,   102,  -260,   238,   388,   251,
    -260,   258,  -260,   168,   652,   728,   652,   230,  -260,  -260,
     168,  -260,  -260,  -260,   728,  -260,  -260,   728,   728,   728,
     728,   728,   728,  -260,  -260,  -260,  -260,   728,  -260,  -260,
     728,   728,   728,   243,  -260,   652,  -260,   652,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,   728,   109,  -260,   232,
     232,   176,  -260,    13,    -9,   176,   234,  -260,   256,  -260,
     261,   586,  -260,    84,   267,   134,   763,   252,  -260,  -260,
    -260,    88,  -260,   259,   260,   110,   263,    82,   252,  -260,
     240,  -260,   140,   -34,   -34,   175,    46,    45,    48,    28,
     200,   101,   728,   252,   252,    82,   268,  -260,  -260,    55,
     217,  -260,   269,  -260,    16,  -260,    13,  -260,  -260,  -260,
    -260,   234,   454,   256,  -260,  -260,    66,   652,  -260,  -260,
     263,   662,  -260,   276,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,   277,  -260,  -260,
    -260,   131,   190,    55,  -260,  -260,  -260,   520,  -260,  -260,
    -260,   662,  -260,  -260,  -260,  -260,  -260,  -260,  -260
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    87,    88,    89,    90,    91,    92,    93,   212,
     210,     0,     0,   114,   115,   116,    12,    13,   172,   172,
       0,    60,    32,   117,    94,     0,     0,   111,   112,   113,
       0,     2,    14,     3,     9,     0,    11,    20,    34,     0,
       0,     0,    28,    97,    96,    99,   101,   109,   118,     0,
     125,   131,   138,   142,   146,   150,   158,   164,   168,   174,
     175,     0,   177,   179,   180,   205,    27,    98,   206,   209,
     211,     7,     0,     8,     0,    56,    55,    57,   180,    98,
     180,    58,   207,     0,    29,   172,   172,   225,   224,   226,
     227,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   100,     1,     4,     0,    30,    19,     0,     0,
      15,    17,    16,    18,   195,   203,   197,   107,   108,    94,
       0,   105,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,    75,   173,   172,   192,
       0,     6,    67,    68,     0,    59,    64,     0,    66,   228,
     233,   232,    67,    66,    61,   207,    33,   180,   172,    25,
      10,     0,    35,   172,     0,   172,     0,     0,   104,   106,
     172,   122,   123,   124,     0,   130,   129,     0,     0,     0,
       0,     0,     0,   156,   157,   154,   155,     0,   162,   163,
       0,     0,     0,     0,    78,     0,   178,     0,   186,   187,
     184,   185,   189,   188,   190,   183,   172,     0,    40,     0,
       0,     0,   208,    38,     0,     0,    62,    95,     0,    22,
       0,   172,    31,     0,     0,    98,    84,   196,    69,    71,
      73,    72,    79,     0,    97,    74,   211,   204,   198,   201,
       0,   120,   127,   133,   136,   140,   144,   148,   152,   160,
     166,   170,   172,    76,   193,   181,   212,    51,    44,     0,
       0,    46,     0,    49,   207,    43,    41,    65,    39,   229,
     230,    63,   172,     0,    26,    37,     0,     0,    80,    86,
       0,     0,    81,     0,   103,   121,   128,   134,   137,   141,
     145,   149,   153,   161,   167,   171,   176,     0,   182,    54,
      45,     0,     0,     0,    52,    42,    21,   172,    85,    70,
      83,     0,   199,    77,    47,    48,    53,    24,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -260,  -260,   -33,  -260,  -260,   -30,  -260,  -260,  -260,  -260,
    -260,   -65,  -260,  -260,  -260,  -260,  -260,  -260,  -136,  -260,
      19,  -260,    37,  -260,  -260,  -260,   -15,  -260,  -260,  -134,
     129,   -41,    64,  -259,   -57,  -260,  -260,  -260,   111,  -260,
    -260,  -260,  -147,   -36,  -260,  -260,   317,   295,  -260,   171,
    -260,   173,  -260,  -260,  -260,   105,  -260,  -260,  -260,   167,
    -260,  -260,  -260,  -260,   177,  -260,  -260,   166,  -260,  -260,
     162,  -260,  -260,   163,  -260,  -260,  -260,   164,  -260,  -260,
    -260,   165,  -260,  -260,  -158,  -260,  -260,  -260,  -260,  -125,
    -120,    -4,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -129,     0,  -260,  -260,  -197,   -64,   142,  -260,
    -260,  -260
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,   105,    33,   160,   220,   221,    34,
      35,    36,   161,    85,    37,   108,   109,    38,   208,   260,
     261,   262,   263,    39,    40,    41,    42,    83,   154,   145,
     146,   227,   228,   229,   230,   195,   297,   231,   232,   311,
     233,   276,    43,    44,    86,    45,    46,    47,   122,    48,
      49,    50,   124,   285,   174,    51,   125,   286,   177,    52,
     126,   287,   127,   288,    53,   128,   289,    54,   129,   290,
      55,   130,   291,    56,   131,   292,   187,    57,   132,   293,
     190,    58,   133,   294,    59,   134,   295,    60,    61,    62,
      63,    64,   140,   298,   206,    65,   197,   164,   166,   283,
     167,   165,    66,    79,   147,    68,    69,    70,    71,    72,
      73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   104,   106,   148,   137,    81,   235,   149,   235,   151,
     193,   121,   213,   196,    78,    80,   268,   234,   153,   234,
      82,   216,   310,   107,     9,    10,   150,     9,     9,   142,
    -234,    67,    18,  -126,   224,    67,    77,   235,  -126,   235,
     -36,   240,    22,   162,    22,   237,  -234,    84,   234,   103,
     234,   110,   318,  -151,  -151,   156,   169,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     9,   143,   111,   305,
     112,   303,   144,   265,   266,    25,   104,  -207,    25,    25,
     210,   271,   157,   155,   279,    67,   255,   121,     9,    10,
     212,   153,     2,     3,     4,     5,     6,     7,     8,     9,
     236,  -139,   236,  -151,  -151,   175,    67,    75,    76,    24,
     176,     9,   209,     9,   152,    25,    26,    25,  -143,   235,
     256,    10,  -147,   235,  -165,   238,   136,   296,   219,    21,
     234,   236,  -169,   236,   135,  -202,  -202,   114,   115,    25,
     138,  -202,   256,    10,   116,     9,   152,   153,   223,   269,
     226,   153,   143,   235,   253,   223,   254,   215,    67,   257,
     141,   153,    25,   225,    25,    22,   258,   280,   259,  -202,
     225,    25,     2,     3,     4,     5,     6,     7,     8,     9,
      10,   257,   183,   184,   143,   272,  -231,     9,   152,   113,
     259,   274,    13,    25,  -207,   299,    25,    14,    15,  -207,
     304,     9,    10,  -119,   163,   114,   115,   264,  -132,  -135,
    -119,  -119,   116,   236,   158,   159,   117,   118,    67,   308,
      21,    67,  -200,    23,    24,   178,   143,  -159,  -159,   168,
      25,    26,   185,   186,   170,    27,    28,    29,    25,   316,
     307,   179,   104,   119,  -194,  -194,   180,   171,   182,   259,
    -194,  -102,    25,   120,   172,   173,   191,     1,   188,   189,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   181,    67,    67,   300,   301,   192,   104,  -194,   194,
      13,  -191,  -191,   243,   244,    14,    15,  -191,   207,   214,
     -23,   239,   211,    16,    17,   217,   252,    18,   222,    19,
     273,   264,   264,   139,   275,   284,    20,    67,    21,    22,
     277,    23,    24,   281,   -86,  -191,  -172,   282,    25,    26,
     314,   -50,   302,    27,    28,    29,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   312,   313,   315,
     267,   309,   278,   102,   123,   241,    13,   245,   247,   248,
     242,    14,    15,   249,     0,   250,   270,   251,   246,    16,
      17,     0,     0,    18,     0,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,     0,    23,    24,     0,
       0,     0,  -172,     0,    25,    26,     0,     0,     0,    27,
      28,    29,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,    16,    17,   218,     0,    18,
       0,    19,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,     0,    23,    24,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    27,    28,    29,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,    16,    17,     0,   306,    18,     0,    19,     0,     0,
       0,     0,     0,     0,    20,     0,    21,    22,     0,    23,
      24,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    27,    28,    29,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,    16,    17,     0,
     317,    18,     0,    19,     0,     0,     0,     0,     0,     0,
      20,     0,    21,    22,     0,    23,    24,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,    27,    28,    29,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    18,     0,    19,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
       0,    23,    24,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    27,    28,    29,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    13,     0,     0,     0,
       0,    14,    15,     0,     0,     0,    13,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
       0,     0,   136,     0,   226,    26,     0,    23,    24,    27,
      28,    29,   136,     0,    25,    26,     0,     0,     0,    27,
      28,    29,     2,     3,     4,     5,     6,     7,     8,     9,
      10,   198,   199,   200,   201,   202,   203,   204,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,    23,    24,    87,    88,    89,     0,     0,
      25,    26,     0,     0,    90,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,   100,   101
};

static const yytype_int16 yycheck[] =
{
       0,    31,    35,    67,    61,    20,   164,    72,   166,    74,
     135,    47,   148,   138,    18,    19,   213,   164,    82,   166,
      20,   155,   281,    37,    11,    12,    37,    11,    11,    12,
      37,    31,    41,    67,   163,    35,    12,   195,    72,   197,
      54,   170,    53,   108,    53,   165,    53,    39,   195,     0,
     197,    37,   311,    25,    26,    85,   120,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    11,    50,    37,   266,
      37,    55,    55,   209,   210,    62,   106,    60,    62,    62,
     144,   215,    86,    83,   231,    85,   206,   123,    11,    12,
     147,   155,     4,     5,     6,     7,     8,     9,    10,    11,
     164,    55,   166,    75,    76,    67,   106,    11,    12,    56,
      72,    11,    12,    11,    12,    62,    63,    62,    73,   277,
      11,    12,    74,   281,    23,   166,    60,   252,   158,    52,
     277,   195,    22,   197,    77,    31,    32,    53,    54,    62,
      58,    37,    11,    12,    60,    11,    12,   211,   163,   214,
      62,   215,    50,   311,   195,   170,   197,    55,   158,    50,
      37,   225,    62,   163,    62,    53,    57,   231,    59,    65,
     170,    62,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    50,    25,    26,    50,   218,    53,    11,    12,    37,
      59,   221,    24,    62,    60,   259,    62,    29,    30,    60,
     264,    11,    12,    63,    54,    53,    54,   207,    33,    34,
      70,    71,    60,   277,    31,    32,    29,    30,   218,   276,
      52,   221,    61,    55,    56,    33,    50,    27,    28,    57,
      62,    63,    75,    76,    64,    67,    68,    69,    62,   303,
     273,    34,   272,    56,    31,    32,    55,    63,    74,    59,
      37,    64,    62,    66,    70,    71,    23,     1,    27,    28,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    73,   272,   273,    57,    58,    22,   307,    65,    61,
      24,    31,    32,   178,   179,    29,    30,    37,    56,    42,
      39,    61,    58,    37,    38,    57,    53,    41,    40,    43,
      39,   301,   302,    53,    37,    65,    50,   307,    52,    53,
      58,    55,    56,    54,    54,    65,    60,    54,    62,    63,
     301,    53,    53,    67,    68,    69,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    61,    61,   302,
     211,   277,   231,    26,    49,   174,    24,   180,   182,   187,
     177,    29,    30,   190,    -1,   191,   214,   192,   181,    37,
      38,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    60,    -1,    62,    63,    -1,    -1,    -1,    67,
      68,    69,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    67,    68,    69,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,    68,    69,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    67,    68,    69,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    -1,    62,    63,    -1,    55,    56,    67,
      68,    69,    60,    -1,    62,    63,    -1,    -1,    -1,    67,
      68,    69,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    55,    56,    22,    23,    24,    -1,    -1,
      62,    63,    -1,    -1,    31,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    24,    29,    30,    37,    38,    41,    43,
      50,    52,    53,    55,    56,    62,    63,    67,    68,    69,
      79,    80,    81,    83,    87,    88,    89,    92,    95,   101,
     102,   103,   104,   120,   121,   123,   124,   125,   127,   128,
     129,   133,   137,   142,   145,   148,   151,   155,   159,   162,
     165,   166,   167,   168,   169,   173,   180,   181,   183,   184,
     185,   186,   187,   188,   189,    11,    12,    12,   169,   181,
     169,   104,   181,   105,    39,    91,   122,    22,    23,    24,
      31,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      51,    52,   124,     0,    83,    82,    80,    37,    93,    94,
      37,    37,    37,    37,    53,    54,    60,    29,    30,    56,
      66,   121,   126,   125,   130,   134,   138,   140,   143,   146,
     149,   152,   156,   160,   163,    77,    60,   112,    58,    53,
     170,    37,    12,    50,    55,   107,   108,   182,   185,    89,
      37,    89,    12,   185,   106,   181,    83,   169,    31,    32,
      84,    90,    89,    54,   175,   179,   176,   178,    57,   185,
      64,    63,    70,    71,   132,    67,    72,   136,    33,    34,
      55,    73,    74,    25,    26,    75,    76,   154,    27,    28,
     158,    23,    22,   167,    61,   113,   167,   174,    15,    16,
      17,    18,    19,    20,    21,    54,   172,    56,    96,    12,
     185,    58,   112,    96,    42,    55,   107,    57,    39,    83,
      85,    86,    40,   104,   180,   181,    62,   109,   110,   111,
     112,   115,   116,   118,   120,   162,   185,   168,   109,    61,
     180,   127,   129,   133,   133,   137,   142,   145,   148,   151,
     155,   159,    53,   109,   109,   168,    11,    50,    57,    59,
      97,    98,    99,   100,   181,    96,    96,   108,   184,    89,
     186,   107,    80,    39,    83,    37,   119,    58,   116,   120,
     185,    54,    54,   177,    65,   131,   135,   139,   141,   144,
     147,   150,   153,   157,   161,   164,   167,   114,   171,   185,
      57,    58,    53,    55,   185,   184,    40,    80,   112,   110,
     111,   117,    61,    61,    98,   100,   185,    40,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    80,    81,    81,    81,    82,
      81,    81,    81,    81,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    84,    86,    84,    87,    87,    88,
      90,    89,    91,    89,    93,    92,    94,    92,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   103,   104,
     105,   104,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   113,   114,   112,   112,   115,
     115,   117,   116,   116,   119,   118,   118,   120,   120,   120,
     120,   120,   120,   120,   122,   121,   123,   123,   123,   124,
     124,   125,   126,   125,   125,   125,   125,   125,   125,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   129,   130,
     131,   129,   132,   132,   132,   133,   134,   135,   133,   136,
     136,   137,   138,   139,   137,   140,   141,   137,   142,   143,
     144,   142,   145,   146,   147,   145,   148,   149,   150,   148,
     151,   152,   153,   151,   154,   154,   154,   154,   155,   156,
     157,   155,   158,   158,   159,   160,   161,   159,   162,   163,
     164,   162,   166,   165,   165,   167,   167,   168,   168,   169,
     170,   171,   169,   172,   172,   172,   172,   172,   172,   172,
     172,   173,   174,   173,   173,   175,   173,   176,   177,   173,
     178,   173,   173,   179,   173,   180,   181,   182,   181,   183,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   186,   186,
     186,   187,   188,   188,   189
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     0,
       3,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     4,     2,     0,     5,     0,     3,     1,     1,     2,
       0,     4,     0,     3,     0,     3,     0,     5,     3,     4,
       3,     4,     5,     4,     2,     3,     1,     3,     3,     1,
       1,     1,     2,     3,     2,     2,     2,     2,     2,     2,
       0,     3,     2,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     0,     0,     5,     2,     1,
       2,     0,     4,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     1,     1,
       2,     1,     0,     5,     3,     2,     3,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     5,     1,     1,     1,     1,     0,     0,     5,     1,
       1,     1,     0,     0,     5,     0,     0,     5,     1,     0,
       0,     5,     1,     0,     0,     5,     1,     0,     0,     5,
       1,     0,     0,     5,     1,     1,     1,     1,     1,     0,
       0,     5,     1,     1,     1,     0,     0,     5,     1,     0,
       0,     5,     0,     2,     1,     1,     5,     1,     3,     1,
       0,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     4,     0,     0,     6,
       0,     4,     2,     0,     4,     1,     1,     0,     3,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       4,     2,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 217 "ast.y" /* yacc.c:1646  */
    { ast_Parser_reset(yparser()); fast_op;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 218 "ast.y" /* yacc.c:1646  */
    { ast_Parser_reset(yparser()); fast_op;}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 219 "ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = NULL;
        if(!yparser()->errors) {
            printf("unreported error:%d: ast_Parser.c:%d\n", yparser()->line, yparser()->errLine);
        }
    }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[-1].ast)); fast_op; ast_Parser_defineObject(yparser()); fast_op;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 229 "ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 230 "ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 231 "ast.y" /* yacc.c:1646  */
    {(yyval.Variable) = ast_Parser_pushScope(yparser()); ast_Parser_pushLvalue(yparser(),NULL, FALSE); fast_op;}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 231 "ast.y" /* yacc.c:1646  */
    {ast_Parser_popScope(yparser(),(yyvsp[-1].Variable)); fast_op;}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 232 "ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 233 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "ast.y" /* yacc.c:1646  */
    {ast_Parser_error(yparser(), "usage of tabs is not allowed");}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 253 "ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 254 "ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 258 "ast.y" /* yacc.c:1646  */
    {if (!yparser()->variableCount) {yparser()->variables[0] = (yyvsp[0].ast); yparser()->variableCount=1;}}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 266 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 270 "ast.y" /* yacc.c:1646  */
    {ast_Parser_blockPop(yparser()); fast_op;}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 270 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-3].ast);}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 271 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "ast.y" /* yacc.c:1646  */
    {ast_Parser_blockPop(yparser()); fast_op; (yyval.ast)=(yyvsp[-1].ast);}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_declareFunctionParams(yparser(),(yyvsp[0].ast)); fast_op;
    }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 280 "ast.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].ast)) {
            ast_Parser_bind(yparser(), (yyvsp[-2].ast), (yyvsp[-1].ast)); fast_op;
        }
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 285 "ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_declareFunctionParams(yparser(),(yyvsp[0].ast)); fast_op;
        ast_Parser_blockPush(yparser(), FALSE); fast_op;
        ast_Expression s = ast_Expression_resolve((yyvsp[0].ast), NULL);
        if (!s) {
            YYERROR;
        }
        ast_Parser_pushReturnAsLvalue(yparser(), ast_Object(s)->value); fast_op;
    }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 293 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_popLvalue(yparser()); fast_op;
        ast_Parser_bindOneliner(yparser(), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)); fast_op;
        ast_Parser_blockPop(yparser()); fast_op;
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "ast.y" /* yacc.c:1646  */
    {
        corto_id id;
        ast_Expression e = ast_Expression_resolve((yyvsp[-2].Reference), NULL);
        if (!e) {
            YYERROR;
        }
        sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String));
        corto_dealloc((yyvsp[0].String));
        (yyval.ast) = ast_Parser_declareFunction(
            yparser(),
            e ? ast_Object(e)->value : NULL,
            id,
            NULL,
            FALSE
        );
        fast_op;
    }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 318 "ast.y" /* yacc.c:1646  */
    {
        corto_id id;
        corto_type kind = corto_resolve(NULL, (yyvsp[0].String));
        if (!kind) {
            ast_Parser_error(yparser(), "%s not found", (yyvsp[0].String));
            YYERROR;
        }
        if (!corto_instanceof(ast_Object_o, (yyvsp[-3].Reference))) {
            ast_Parser_error(yparser(), "invalid type");
            YYERROR;
        }
        sprintf(id, "%s(%s)", (yyvsp[-2].String), (yyvsp[-1].String));
        corto_dealloc((yyvsp[-1].String));
        (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference) ? ast_Object((yyvsp[-3].Reference))->value : NULL, id, kind, FALSE); fast_op;
        corto_release(kind);
    }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 334 "ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-2].Reference) ? ast_Object((yyvsp[-2].Reference))->value : NULL, id, NULL, FALSE); fast_op; }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 337 "ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference) ? ast_Object((yyvsp[-3].Reference))->value : NULL, id, NULL, TRUE); fast_op; }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "ast.y" /* yacc.c:1646  */
    {
        corto_id id;
        corto_type kind = corto_resolve(NULL, (yyvsp[0].String));
        if (!kind) {
            ast_Parser_error(yparser(), "%s not found", (yyvsp[-1].String));
            YYERROR;
        }
        sprintf(id, "%s(%s)", (yyvsp[-2].String), (yyvsp[-1].String));
        (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-4].Reference) ? ast_Object((yyvsp[-4].Reference))->value : NULL, id, kind, TRUE); fast_op;
        corto_release(kind);
    }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 349 "ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference) ? ast_Object((yyvsp[-3].Reference))->value : NULL, id, NULL, TRUE); fast_op; }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 353 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = corto_strdup("");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 354 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[-1].String);}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 358 "ast.y" /* yacc.c:1646  */
    {(yyval.String)=corto_alloc(sizeof(corto_id));strcpy((yyval.String),(yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 359 "ast.y" /* yacc.c:1646  */
    {(yyval.String)=(yyvsp[-2].String); strcat((yyval.String),","); strcat((yyval.String),(yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 363 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = corto_asprintf("%s:%s", (yyvsp[-2].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 368 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[0].String);}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 369 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "in";}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "ast.y" /* yacc.c:1646  */
    {
        ast_Expression e = ast_Expression_resolve((yyvsp[-1].Reference), NULL);
        if (!e) {
            YYERROR;
        }
        (yyval.String)=ast_Parser_argumentToString(yparser(), (yyvsp[-1].Reference) ? ast_Object(e)->value : NULL, (yyvsp[0].String), FALSE); fast_op;
    }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 380 "ast.y" /* yacc.c:1646  */
    {
        ast_Expression e = ast_Expression_resolve((yyvsp[-2].Reference), NULL);
        if (!e) {
            YYERROR;
        }
        (yyval.String)=ast_Parser_argumentToString(yparser(), (yyvsp[-2].Reference) ? ast_Object(e)->value : NULL, (yyvsp[0].String), TRUE); fast_op;
    }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 387 "ast.y" /* yacc.c:1646  */
    {
        corto_id argid;
        sprintf(argid, "$%s", (yyvsp[0].String));
        if (!strcmp((yyvsp[0].String), "__line")) {
            (yyval.String)=safe_ast_Parser_argumentToString(yparser(), corto_uint32_o, argid, FALSE); fast_op;
        } else {
            (yyval.String)=safe_ast_Parser_argumentToString(yparser(), corto_string_o, argid, FALSE); fast_op;
        }
    }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_pushPackage(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 406 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_pushPackage(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 412 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_import(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 418 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_with(yparser());
    }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 424 "ast.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op; }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 425 "ast.y" /* yacc.c:1646  */
    {yparser()->isLocal = TRUE;}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 429 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op;}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 430 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_declarationSeqDo((yyvsp[-2].Reference), &(yyvsp[0].Declarations), TRUE); fast_op;}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 434 "ast.y" /* yacc.c:1646  */
    {(yyval.Declarations).length = 0; (yyval.Declarations).buffer = NULL; ast_declarationSeqInsert(&(yyval.Declarations), &(yyvsp[0].Declaration));}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 435 "ast.y" /* yacc.c:1646  */
    {ast_declarationSeqInsert(&(yyvsp[-2].Declarations), &(yyvsp[0].Declaration)); (yyval.Declarations) = (yyvsp[-2].Declarations);}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 439 "ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = (yyvsp[0].String);}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 440 "ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = (yyvsp[0].String);}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 441 "ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = "in";}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 448 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 459 "ast.y" /* yacc.c:1646  */
    {if ((yyvsp[0].ast)) ast_Parser_initValue(yparser(), (yyvsp[0].ast)); fast_op}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 463 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPush(yparser()); fast_op;}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 463 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op;}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 463 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-2].ast);}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 464 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPush(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL;}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 473 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initMember(yparser(), (yyvsp[-1].String)); fast_op;}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 478 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValuePush(yparser());}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 478 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValuePop(yparser()); fast_op;}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 479 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValueSet(yparser(), (yyvsp[0].ast)); fast_op;}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 486 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Boolean__create(NULL, NULL, yyvsp[0].Boolean); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 487 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Character__create(NULL, NULL, yyvsp[0].Character); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 488 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Integer__create(NULL, NULL, yyvsp[0].Integer); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 489 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_SignedInteger__create(NULL, NULL, yyvsp[0].SignedInteger); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 490 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_FloatingPoint__create(NULL, NULL, yyvsp[0].FloatingPoint); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 491 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_String__create(NULL, NULL, yyvsp[0].String); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 492 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Null__create(NULL, NULL); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 496 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE(NULL)}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 496 "ast.y" /* yacc.c:1646  */
    {POPLVALUE(); (yyval.ast)=(yyvsp[-1].ast);}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 501 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 502 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].Reference);}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 507 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_unaryExpr(yparser(), (yyvsp[0].ast), CORTO_MUL); fast_op;}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 512 "ast.y" /* yacc.c:1646  */
    {PUSHCOMPLEX((yyvsp[0].ast))}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 512 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_elementExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast)); fast_op; POPCOMPLEX()}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 513 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_callExpr(yparser(), (yyvsp[-2].ast), NULL); fast_op;}
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 514 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_callExpr(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast)); fast_op;}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 515 "ast.y" /* yacc.c:1646  */
    {ast_String str = ast_String__create(NULL, NULL, yyvsp[0].String); if (!str) {YYERROR;} (yyval.ast) = ast_Parser_memberExpr(yparser(), (yyvsp[-2].ast), ast_Expression(str)); corto_release(str); fast_op;}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 516 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_postfixExpr(yparser(), (yyvsp[-1].ast), CORTO_INC); fast_op}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 517 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_postfixExpr(yparser(), (yyvsp[-1].ast), CORTO_DEC); fast_op}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 522 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_unaryExpr(yparser(), (yyvsp[0].ast), (yyvsp[-1].Operator)); fast_op;}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 526 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_SUB;}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 527 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_NOT;}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 528 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NOT;}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 529 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NOT;}
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 530 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_INC;}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 531 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_DEC;}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 532 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_AND;}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 537 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 537 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 537 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 541 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_MUL;}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 542 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_DIV;}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 543 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_MOD;}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 548 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 548 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 548 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 552 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ADD;}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 553 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_SUB;}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 558 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 558 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 558 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_SHIFT_LEFT); fast_op;}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 559 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 559 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 559 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_SHIFT_RIGHT); fast_op;}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 564 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 564 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 564 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_AND); fast_op;}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 569 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 569 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 569 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_XOR); fast_op;}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 574 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 574 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 574 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_OR); fast_op;}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 579 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 579 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 579 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 583 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_LT;}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 584 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_GT;}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 585 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_LTEQ;}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 586 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_GTEQ;}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 591 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 591 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 591 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 595 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_EQ;}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 596 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NEQ;}
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 601 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 601 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 601 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_COND_AND); fast_op;}
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 606 "ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 606 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 606 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_COND_OR); fast_op;}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 610 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_initPushExpression(yparser()); fast_op;}
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 610 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-1].ast);}
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 616 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ternaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); fast_op;}
#line 2751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 621 "ast.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].ast) && (yyvsp[0].ast)) {
            if (ast_Node((yyvsp[-2].ast))->kind != Ast_CommaExpr) {
                (yyval.ast) = ast_Comma__create(NULL, NULL); fast_op;
                ast_Comma_addExpression((yyval.ast), (yyvsp[-2].ast)); fast_op;
                ast_Parser_collect(yparser(), (yyval.ast)); fast_op;
            }
            ast_Comma_addExpression((yyval.ast), (yyvsp[0].ast)); fast_op;
        }
    }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 635 "ast.y" /* yacc.c:1646  */
    {PUSHASSIGN((yyvsp[0].ast))}
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 635 "ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 635 "ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;
    }
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 641 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN;}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 642 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_ADD;}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 643 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_SUB;}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 644 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_MUL;}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 645 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_DIV;}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 646 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_AND;}
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 647 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_OR;}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 648 "ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_UPDATE;}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 653 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initDeclare(yparser(), (yyvsp[-1].ast)); fast_op;
        ast_Parser_initPushStatic(yparser()); fast_op;
    }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 656 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initPop(yparser()); fast_op;
        (yyval.ast) = NULL;
    }
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 660 "ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initDeclare(yparser(), (yyvsp[-1].ast)); fast_op;
        ast_Parser_initPushStatic(yparser()); fast_op;
        ast_Parser_initPop(yparser()); fast_op;
        (yyval.ast) = NULL;
    }
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 666 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op;}
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 666 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL; }
#line 2875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 667 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op;}
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 667 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op;}
#line 2887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 667 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 668 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op;}
#line 2899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 668 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 669 "ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL; }
#line 2911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 670 "ast.y" /* yacc.c:1646  */
    {
        if (!yparser()->isLocal && !yparser()->blockCount) {
            _fast_err("invalid usage of assignment operator, initialize objects with ':'");
            YYERROR;
        }
        ast_Parser_pushLvalue(yparser(), (yyvsp[-1].ast), TRUE);
    }
#line 2923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 676 "ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-3].ast), (yyvsp[0].ast), CORTO_ASSIGN); fast_op;
        ast_Parser_popLvalue(yparser());
    }
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 691 "ast.y" /* yacc.c:1646  */
    {
        (yyval.Variable) = ast_Storage(ast_Parser_initPushIdentifier(yparser(), (ast_Expression)(yyvsp[0].Reference))); fast_op
    }
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 693 "ast.y" /* yacc.c:1646  */
    {
        (yyval.Reference) = (yyvsp[-1].Variable);
        if ((yyval.Reference)) {
            ast_Parser_defineObject(yparser()); fast_op;
        }
    }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 702 "ast.y" /* yacc.c:1646  */
    {(yyval.Reference) = ast_Parser_lookup(yparser(), (yyvsp[0].String)); fast_op;}
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 712 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "if";}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 713 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "else";}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 714 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "while";}
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 715 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "switch";}
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 716 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "case";}
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 717 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "break";}
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 718 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "for";}
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 719 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "try";}
#line 3005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 720 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "catch";}
#line 3011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 721 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "import";}
#line 3017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 722 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "local";}
#line 3023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 723 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "and";}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 724 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "or";}
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 725 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "not";}
#line 3041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 726 "ast.y" /* yacc.c:1646  */
    {(yyval.String) = "::";}
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 733 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast), NULL); fast_op;}
#line 3053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 734 "ast.y" /* yacc.c:1646  */
    {ast_If nestedIf = ast_If(ast_Parser_ifStatement(yparser(), NULL, (yyvsp[0].ast), NULL)); fast_op; (yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-3].ast), (yyvsp[-2].ast), nestedIf); fast_op;}
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 735 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); fast_op;}
#line 3065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 739 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 3071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 746 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_whileStatement(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast), FALSE); fast_op;}
#line 3077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 747 "ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_whileStatement(yparser(), (yyvsp[-1].ast), yparser()->block, TRUE); fast_op;}
#line 3083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 751 "ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 3089 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3093 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 754 "ast.y" /* yacc.c:1906  */


/* ======================================================================== */
/* Parser */
/* ======================================================================== */

void yyerror(const char *str)
{
    ast_Parser p = yparser();
    ast_reportError(p->filename, p->line, p->column, (corto_string)str, p->token);
    p->errors++;
}

/* Parse sourcecode */
int fast_yparse(ast_Parser parser, corto_uint32 line, corto_uint32 column) {
    int len = strlen(parser->source);

    /* Prepend and append the source with a newline */
    char *sourceWithNewline = corto_alloc(len + 3);
    sourceWithNewline[0] = '\n';
    strcpy(sourceWithNewline + 1, parser->source);
    sourceWithNewline[len + 1] = '\n';
    sourceWithNewline[len + 2] = '\0';

    /* Set pointer to source */
    yy_scan_string((char *) sourceWithNewline);

    /* Start parsing */
    parser->line = line;
    parser->column = column;

    if (!parser->block) {
        parser->block = ast_Block__create(NULL, NULL, NULL);
        parser->block->isRoot = TRUE;

        /* Declare argv variable */
        corto_type t = corto_resolve(NULL, "sequence{string}");
        ast_Block_declareVar(parser->block, "argv", t, TRUE, FALSE);
        corto_release(t);

        yparser()->blockCount = 0;
    }

    if (!parser->scope) {
        corto_set_ref(&parser->scope, root_o);
    }

    /* Compensate for insertion of the extra \n */
    parser->line--;
    yyparse();

    /* Destroy lexer resources */
    yylex_destroy();

    /* Set token to NULL - it points to lexer-memory */
    yparser()->token = NULL;
    corto_dealloc(sourceWithNewline);

    return yparser()->errors;
}
