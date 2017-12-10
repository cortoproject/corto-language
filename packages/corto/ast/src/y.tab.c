/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/ast.y" /* yacc.c:339  */


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
    ast_Comma result = ast_CommaCreate();
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


#line 176 "src/y.tab.c" /* yacc.c:339  */

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
#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
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
    KW_DEFAULT = 301,
    KW_BREAK = 302,
    KW_FOR = 303,
    KW_TRY = 304,
    KW_CATCH = 305,
    KW_IN = 306,
    KW_IMPORT = 307,
    KW_LOCAL = 308
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
#define KW_DEFAULT 301
#define KW_BREAK 302
#define KW_FOR 303
#define KW_TRY 304
#define KW_CATCH 305
#define KW_IN 306
#define KW_IMPORT 307
#define KW_LOCAL 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 145 "src/ast.y" /* yacc.c:355  */

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

#line 343 "src/y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 358 "src/y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  110
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   824

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,    60,    72,    56,     2,
      57,    58,    64,    73,    59,    68,    67,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      76,    55,    77,    78,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    75,    62,    69,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
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
     425,   429,   429,   433,   434,   438,   439,   443,   444,   445,
     452,   453,   457,   458,   462,   463,   467,   467,   467,   468,
     472,   473,   477,   477,   478,   482,   482,   483,   490,   491,
     492,   493,   494,   495,   496,   500,   500,   504,   505,   506,
     510,   511,   515,   516,   516,   517,   518,   519,   520,   521,
     525,   526,   530,   531,   532,   533,   534,   535,   536,   540,
     541,   541,   541,   545,   546,   547,   551,   552,   552,   552,
     556,   557,   561,   562,   562,   562,   563,   563,   563,   567,
     568,   568,   568,   572,   573,   573,   573,   577,   578,   578,
     578,   582,   583,   583,   583,   587,   588,   589,   590,   594,
     595,   595,   595,   599,   600,   604,   605,   605,   605,   609,
     610,   610,   610,   614,   614,   615,   619,   620,   624,   625,
     638,   639,   639,   639,   645,   646,   647,   648,   649,   650,
     651,   652,   656,   657,   657,   664,   670,   670,   671,   671,
     671,   672,   672,   673,   674,   674,   687,   694,   695,   695,
     706,   710,   711,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     738,   739,   740,   744,   751,   752,   756
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
  "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_FOR", "KW_TRY", "KW_CATCH",
  "KW_IN", "KW_IMPORT", "KW_LOCAL", "':'", "'='", "'&'", "'('", "')'",
  "','", "'$'", "'{'", "'}'", "'@'", "'*'", "'['", "']'", "'.'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'+'", "'^'", "'|'", "'<'", "'>'", "'?'",
  "$accept", "code", "statements", "statement_nodecl", "@1", "statement",
  "scope", "$@2", "$@3", "scope_statement", "block_start", "block", "$@4",
  "@5", "function_implementation", "@6", "@7", "function_declaration",
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
     305,   306,   307,   308,    58,    61,    38,    40,    41,    44,
      36,   123,   125,    64,    42,    91,    93,    46,    45,   126,
      33,    47,    37,    43,    94,   124,    60,    62,    63
};
# endif

#define YYPACT_NINF -243

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-243)))

#define YYTABLE_NINF -237

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     228,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,    76,    35,  -243,  -243,  -243,  -243,  -243,   728,   728,
     135,   112,  -243,    14,  -243,  -243,   771,    93,  -243,  -243,
    -243,    90,   307,  -243,  -243,  -243,   228,  -243,  -243,    41,
      19,    27,    98,    -4,  -243,  -243,  -243,  -243,   148,  -243,
      93,    62,    75,    78,    89,    81,    84,    33,   179,   138,
     144,   105,   126,  -243,   133,   165,  -243,   157,    23,  -243,
    -243,  -243,  -243,   145,  -243,     6,  -243,  -243,  -243,   149,
     151,     8,  -243,  -243,   155,  -243,  -243,  -243,   135,    43,
    -243,   575,   728,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   186,   307,  -243,   145,   173,  -243,  -243,  -243,
    -243,   222,  -243,   158,  -243,  -243,   172,     7,  -243,   183,
     148,   137,   100,   217,   221,   195,   182,   185,    95,   196,
     239,   241,   728,   202,  -243,   728,   236,   744,  -243,   213,
      54,   155,   126,   213,   230,  -243,  -243,   135,  -243,    29,
    -243,   219,   374,   244,  -243,   238,  -243,   642,   652,   728,
     652,   224,  -243,  -243,   642,  -243,  -243,  -243,   728,  -243,
    -243,   728,   728,   728,   728,   728,   728,  -243,  -243,  -243,
    -243,   728,  -243,  -243,   728,   728,   728,   240,  -243,   652,
    -243,   652,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
     728,    56,  -243,   213,   213,  -243,    43,    74,  -243,   135,
     155,  -243,   228,  -243,   251,   575,  -243,   109,   256,   118,
     771,   242,  -243,  -243,  -243,    18,  -243,   245,   248,   144,
     252,   133,   242,  -243,   229,  -243,    62,    75,    75,    78,
      89,    81,    84,    33,   179,   138,   728,   242,   242,   133,
     254,  -243,  -243,     7,   168,  -243,   255,  -243,   128,  -243,
      43,  -243,  -243,  -243,   155,   441,   228,  -243,  -243,   126,
     652,  -243,  -243,   252,   719,  -243,   237,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
     260,  -243,  -243,  -243,   125,   130,     7,  -243,  -243,  -243,
     508,  -243,  -243,  -243,   719,  -243,  -243,  -243,  -243,  -243,
    -243,  -243
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    88,    89,    90,    91,    92,    93,    94,   213,
     211,     0,     0,   115,   116,   117,    12,    13,   173,   173,
       0,     0,    61,    32,   118,    95,     0,     0,   112,   113,
     114,     0,     2,    14,     3,     9,     0,    11,    20,    34,
       0,     0,     0,    28,    98,    97,   100,   102,   110,   119,
       0,   126,   132,   139,   143,   147,   151,   159,   165,   169,
     175,   176,     0,   178,   180,   181,   206,    27,    99,   207,
     210,   212,     7,     0,     8,     0,    56,    55,    57,   181,
      99,   181,    68,    69,    60,    65,    67,    58,   208,     0,
      29,   173,   173,   227,   226,   228,   229,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   101,
       1,     4,     0,    30,    19,     0,     0,    15,    17,    16,
      18,   196,   204,   198,   108,   109,    95,     0,   106,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,    76,   174,   173,   193,     0,     6,    68,
       0,    59,     0,    67,   230,   235,   234,     0,    62,   208,
      33,   181,   173,    25,    10,     0,    35,   173,     0,   173,
       0,     0,   105,   107,   173,   123,   124,   125,     0,   131,
     130,     0,     0,     0,     0,     0,     0,   157,   158,   155,
     156,     0,   163,   164,     0,     0,     0,     0,    79,     0,
     179,     0,   187,   188,   185,   186,   190,   189,   191,   184,
     173,     0,    40,     0,     0,   209,    38,     0,    66,     0,
      63,    96,     0,    22,     0,   173,    31,     0,     0,    99,
      85,   197,    70,    72,    74,    73,    80,     0,    98,    75,
     212,   205,   199,   202,     0,   121,   128,   134,   137,   141,
     145,   149,   153,   161,   167,   171,   173,    77,   194,   182,
     213,    51,    44,     0,     0,    46,     0,    49,   208,    43,
      41,    39,   231,   232,    64,   173,     0,    26,    37,     0,
       0,    81,    87,     0,     0,    82,     0,   104,   122,   129,
     135,   138,   142,   146,   150,   154,   162,   168,   172,   177,
       0,   183,    54,    45,     0,     0,     0,    52,    42,    21,
     173,    86,    71,    84,     0,   200,    78,    47,    48,    53,
      24,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,   -33,  -243,  -243,   -30,  -243,  -243,  -243,  -243,
    -243,   -63,  -243,  -243,  -243,  -243,  -243,  -243,  -137,  -243,
       2,  -243,    20,  -243,  -243,  -243,   -14,  -243,  -243,   -15,
     166,  -126,    44,  -242,   -58,  -243,  -243,  -243,    91,  -243,
    -243,  -243,  -153,   -35,  -243,  -243,   300,   278,  -243,   152,
    -243,   153,  -243,  -243,  -243,    64,  -243,  -243,  -243,   154,
    -243,  -243,  -243,  -243,   147,  -243,  -243,   143,  -243,  -243,
     142,  -243,  -243,   141,  -243,  -243,  -243,   146,  -243,  -243,
    -243,   150,  -243,  -243,  -162,  -243,  -243,  -243,  -243,  -131,
    -139,     1,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -136,     0,  -243,  -243,  -207,   -19,   122,  -243,
    -243,  -243
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,    33,   112,    34,   164,   224,   225,    35,
      36,    37,   165,    91,    38,   115,   116,    39,   212,   264,
     265,   266,   267,    40,    41,    42,    43,    89,   158,   151,
      85,   231,   232,   233,   234,   199,   300,   235,   236,   314,
     237,   279,    44,    45,    92,    46,    47,    48,   129,    49,
      50,    51,   131,   288,   178,    52,   132,   289,   181,    53,
     133,   290,   134,   291,    54,   135,   292,    55,   136,   293,
      56,   137,   294,    57,   138,   295,   191,    58,   139,   296,
     194,    59,   140,   297,    60,   141,   298,    61,    62,    63,
      64,    65,   147,   301,   210,    66,   201,   168,   170,   286,
     171,   169,    67,    80,   152,    69,    70,    71,    72,    73,
      74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    86,   111,   113,   144,    84,   239,    87,   239,   271,
     154,   197,   156,   128,   200,   238,   216,   238,     9,    79,
      81,    88,     2,     3,     4,     5,     6,     7,     8,     9,
     241,   228,    68,   120,     9,   149,    68,   239,   244,   239,
       9,    82,   313,   155,   242,  -236,   238,    78,   238,   153,
     121,   122,   166,    90,     9,    10,   117,   123,  -152,  -152,
      23,   160,  -236,   308,   118,     9,   213,   260,    10,    86,
      26,   259,   321,   257,    83,   258,   269,   270,   114,   150,
      83,   230,   282,   111,  -208,   219,    26,    76,    77,   159,
     110,    68,    26,   161,   215,   128,   -36,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    26,   261,   173,  -152,
    -152,  -133,  -136,    68,   262,    18,   263,    26,   239,    26,
     187,   188,   239,     9,    10,   299,  -120,   238,    23,     9,
      82,   214,   223,  -120,  -120,   119,   260,    10,    86,     9,
      86,     9,    10,  -127,   220,  -140,     9,    82,  -127,   240,
      25,   240,   239,   227,   272,  -144,    26,    27,    20,  -148,
     227,  -166,    68,   121,   122,    22,  -170,   229,   179,    83,
     123,   189,   190,   180,   229,    26,   261,   124,   125,  -208,
     240,    26,   240,   142,   306,   263,    83,   143,    26,   275,
     263,    26,   145,    26,   148,   277,  -192,  -192,    26,    23,
      86,   175,  -192,  -233,   274,   126,  -160,  -160,   176,   177,
      86,   268,  -208,  -103,   157,   127,   283,   162,   163,   146,
    -201,   311,    68,   192,   193,    68,   303,   304,   167,     1,
     172,  -192,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   310,   302,   111,   247,   248,   174,   307,
     182,   184,    13,  -203,  -203,   183,   185,    14,    15,  -203,
     186,   240,   195,   196,   198,    16,    17,  -195,  -195,    18,
     211,    19,   217,  -195,    20,    68,    68,   221,   226,    21,
     111,    22,    23,   -23,    24,    25,   243,   319,  -203,  -173,
     276,    26,    27,   278,   256,   287,    28,    29,    30,   315,
     284,   280,  -195,   -87,   268,   268,   317,   285,   -50,   305,
      68,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   316,   218,   312,   318,   281,   109,   130,   251,
     245,    13,   250,   252,   246,   253,    14,    15,   249,   273,
       0,   254,     0,     0,    16,    17,   255,     0,    18,     0,
      19,     0,     0,    20,     0,     0,     0,     0,    21,     0,
      22,    23,     0,    24,    25,     0,     0,     0,  -173,     0,
      26,    27,     0,     0,     0,    28,    29,    30,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,    16,    17,   222,     0,    18,     0,    19,     0,     0,
      20,     0,     0,     0,     0,    21,     0,    22,    23,     0,
      24,    25,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,    28,    29,    30,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,    16,    17,
       0,   309,    18,     0,    19,     0,     0,    20,     0,     0,
       0,     0,    21,     0,    22,    23,     0,    24,    25,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,    28,
      29,    30,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,    16,    17,     0,   320,    18,
       0,    19,     0,     0,    20,     0,     0,     0,     0,    21,
       0,    22,    23,     0,    24,    25,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,    28,    29,    30,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    18,     0,    19,     0,
       0,    20,     0,     0,     0,     0,    21,     0,    22,    23,
       0,    24,    25,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,    28,    29,    30,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    13,     0,     0,     0,
       0,    14,    15,     0,     0,     0,    13,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,    22,     0,     0,    24,    25,
       0,     0,     0,     0,     0,    26,    27,     0,    24,    25,
      28,    29,    30,   143,     0,   230,    27,     0,     0,     0,
      28,    29,    30,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     2,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     0,    13,     0,     0,     0,     0,    14,    15,
       0,     0,    13,     0,     0,     0,     0,    14,    15,   202,
     203,   204,   205,   206,   207,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
     143,     0,    26,    27,    24,    25,     0,    28,    29,    30,
       0,    26,    27,    93,    94,    95,    28,    29,    30,   209,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108
};

static const yytype_int16 yycheck[] =
{
       0,    20,    32,    36,    62,    20,   168,    21,   170,   216,
      73,   142,    75,    48,   145,   168,   153,   170,    11,    18,
      19,    21,     4,     5,     6,     7,     8,     9,    10,    11,
     169,   167,    32,    37,    11,    12,    36,   199,   174,   201,
      11,    12,   284,    37,   170,    37,   199,    12,   201,    68,
      54,    55,   115,    39,    11,    12,    37,    61,    25,    26,
      54,    91,    54,   270,    37,    11,    12,    11,    12,    88,
      63,   210,   314,   199,    51,   201,   213,   214,    37,    56,
      51,    63,   235,   113,    61,    56,    63,    11,    12,    89,
       0,    91,    63,    92,   152,   130,    55,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    63,    51,   127,    76,
      77,    33,    34,   113,    58,    41,    60,    63,   280,    63,
      25,    26,   284,    11,    12,   256,    64,   280,    54,    11,
      12,   150,   162,    71,    72,    37,    11,    12,   157,    11,
     159,    11,    12,    68,   159,    56,    11,    12,    73,   168,
      57,   170,   314,   167,   217,    74,    63,    64,    46,    75,
     174,    23,   162,    54,    55,    53,    22,   167,    68,    51,
      61,    76,    77,    73,   174,    63,    51,    29,    30,    61,
     199,    63,   201,    78,    56,    60,    51,    61,    63,   222,
      60,    63,    59,    63,    37,   225,    31,    32,    63,    54,
     219,    64,    37,    54,   219,    57,    27,    28,    71,    72,
     229,   211,    61,    65,    59,    67,   235,    31,    32,    54,
      62,   279,   222,    27,    28,   225,    58,    59,    55,     1,
      58,    66,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   276,   263,   275,   182,   183,    65,   268,
      33,    56,    24,    31,    32,    34,    74,    29,    30,    37,
      75,   280,    23,    22,    62,    37,    38,    31,    32,    41,
      57,    43,    42,    37,    46,   275,   276,    58,    40,    51,
     310,    53,    54,    39,    56,    57,    62,   306,    66,    61,
      39,    63,    64,    37,    54,    66,    68,    69,    70,    62,
      55,    59,    66,    55,   304,   305,   304,    55,    54,    54,
     310,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    62,   157,   280,   305,   235,    27,    50,   186,
     178,    24,   185,   191,   181,   194,    29,    30,   184,   217,
      -1,   195,    -1,    -1,    37,    38,   196,    -1,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      63,    64,    -1,    -1,    -1,    68,    69,    70,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    68,    69,    70,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    68,
      69,    70,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    68,    69,    70,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    56,    57,
      68,    69,    70,    61,    -1,    63,    64,    -1,    -1,    -1,
      68,    69,    70,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,    64,    56,    57,    -1,    68,    69,    70,
      -1,    63,    64,    22,    23,    24,    68,    69,    70,    55,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    24,    29,    30,    37,    38,    41,    43,
      46,    51,    53,    54,    56,    57,    63,    64,    68,    69,
      70,    80,    81,    82,    84,    88,    89,    90,    93,    96,
     102,   103,   104,   105,   121,   122,   124,   125,   126,   128,
     129,   130,   134,   138,   143,   146,   149,   152,   156,   160,
     163,   166,   167,   168,   169,   170,   174,   181,   182,   184,
     185,   186,   187,   188,   189,   190,    11,    12,    12,   170,
     182,   170,    12,    51,   108,   109,   186,   105,   182,   106,
      39,    92,   123,    22,    23,    24,    31,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    52,    53,   125,
       0,    84,    83,    81,    37,    94,    95,    37,    37,    37,
      37,    54,    55,    61,    29,    30,    57,    67,   122,   127,
     126,   131,   135,   139,   141,   144,   147,   150,   153,   157,
     161,   164,    78,    61,   113,    59,    54,   171,    37,    12,
      56,   108,   183,   186,    90,    37,    90,    59,   107,   182,
      84,   170,    31,    32,    85,    91,    90,    55,   176,   180,
     177,   179,    58,   186,    65,    64,    71,    72,   133,    68,
      73,   137,    33,    34,    56,    74,    75,    25,    26,    76,
      77,   155,    27,    28,   159,    23,    22,   168,    62,   114,
     168,   175,    15,    16,    17,    18,    19,    20,    21,    55,
     173,    57,    97,    12,   186,   113,    97,    42,   109,    56,
     108,    58,    39,    84,    86,    87,    40,   105,   181,   182,
      63,   110,   111,   112,   113,   116,   117,   119,   121,   163,
     186,   169,   110,    62,   181,   128,   130,   134,   134,   138,
     143,   146,   149,   152,   156,   160,    54,   110,   110,   169,
      11,    51,    58,    60,    98,    99,   100,   101,   182,    97,
      97,   185,    90,   187,   108,    81,    39,    84,    37,   120,
      59,   117,   121,   186,    55,    55,   178,    66,   132,   136,
     140,   142,   145,   148,   151,   154,   158,   162,   165,   168,
     115,   172,   186,    58,    59,    54,    56,   186,   185,    40,
      81,   113,   111,   112,   118,    62,    62,    99,   101,   186,
      40,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    82,    82,    82,    83,
      82,    82,    82,    82,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    85,    87,    85,    88,    88,    89,
      91,    90,    92,    90,    94,    93,    95,    93,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   103,   104,   105,
     105,   106,   105,   107,   107,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   114,   115,   113,   113,
     116,   116,   118,   117,   117,   120,   119,   119,   121,   121,
     121,   121,   121,   121,   121,   123,   122,   124,   124,   124,
     125,   125,   126,   127,   126,   126,   126,   126,   126,   126,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   130,
     131,   132,   130,   133,   133,   133,   134,   135,   136,   134,
     137,   137,   138,   139,   140,   138,   141,   142,   138,   143,
     144,   145,   143,   146,   147,   148,   146,   149,   150,   151,
     149,   152,   153,   154,   152,   155,   155,   155,   155,   156,
     157,   158,   156,   159,   159,   160,   161,   162,   160,   163,
     164,   165,   163,   167,   166,   166,   168,   168,   169,   169,
     170,   171,   172,   170,   173,   173,   173,   173,   173,   173,
     173,   173,   174,   175,   174,   174,   176,   174,   177,   178,
     174,   179,   174,   174,   180,   174,   181,   182,   183,   182,
     184,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   187,   187,   188,   189,   189,   190
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
       2,     0,     3,     2,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     0,     0,     5,     2,
       1,     2,     0,     4,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     2,     1,     0,     5,     3,     2,     3,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     5,     1,     1,     1,     1,     0,     0,     5,
       1,     1,     1,     0,     0,     5,     0,     0,     5,     1,
       0,     0,     5,     1,     0,     0,     5,     1,     0,     0,
       5,     1,     0,     0,     5,     1,     1,     1,     1,     1,
       0,     0,     5,     1,     1,     1,     0,     0,     5,     1,
       0,     0,     5,     0,     2,     1,     1,     5,     1,     3,
       1,     0,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     2,     0,     4,     0,     0,
       6,     0,     4,     2,     0,     4,     1,     1,     0,     3,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     2,     2
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
#line 217 "src/ast.y" /* yacc.c:1646  */
    { ast_Parser_reset(yparser()); fast_op;}
#line 1818 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 218 "src/ast.y" /* yacc.c:1646  */
    { ast_Parser_reset(yparser()); fast_op;}
#line 1824 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 219 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = NULL;
        if(!yparser()->errors) {
            printf("unreported error:%d: ast_Parser.c:%d\n", yparser()->line, yparser()->errLine);
        }
    }
#line 1835 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[-1].ast)); fast_op; ast_Parser_defineObject(yparser()); fast_op;}
#line 1841 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 229 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1847 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 230 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1853 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 231 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Variable) = ast_Parser_pushScope(yparser()); ast_Parser_pushLvalue(yparser(),NULL, FALSE); fast_op;}
#line 1859 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 231 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_popScope(yparser(),(yyvsp[-1].Variable)); fast_op;}
#line 1865 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 232 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_addStatement(yparser(), (yyvsp[0].ast)); fast_op;}
#line 1871 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 233 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1877 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_error(yparser(), "usage of tabs is not allowed");}
#line 1883 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 242 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1889 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1895 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1901 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1907 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1913 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 253 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1919 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 254 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_defineScope(yparser()); fast_op;}
#line 1925 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 258 "src/ast.y" /* yacc.c:1646  */
    {if (!yparser()->variableCount) {yparser()->variables[0] = (yyvsp[0].ast); yparser()->variableCount=1;}}
#line 1931 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 266 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 1937 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 270 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_blockPop(yparser()); fast_op;}
#line 1943 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 270 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-3].ast);}
#line 1949 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 271 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 1955 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_blockPop(yparser()); fast_op; (yyval.ast)=(yyvsp[-1].ast);}
#line 1961 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_declareFunctionParams(yparser(),(yyvsp[0].ast)); fast_op;
    }
#line 1969 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 280 "src/ast.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].ast)) {
            ast_Parser_bind(yparser(), (yyvsp[-2].ast), (yyvsp[-1].ast)); fast_op;
        }
    }
#line 1979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 285 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_declareFunctionParams(yparser(),(yyvsp[0].ast)); fast_op;
        ast_Parser_blockPush(yparser(), FALSE); fast_op;
        ast_Expression s = ast_Expression_resolve((yyvsp[0].ast), NULL);
        if (!s) {
            YYERROR;
        }
        ast_Parser_pushReturnAsLvalue(yparser(), ast_Object(s)->value); fast_op;
    }
#line 1993 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 293 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_popLvalue(yparser()); fast_op;
        ast_Parser_bindOneliner(yparser(), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)); fast_op;
        ast_Parser_blockPop(yparser()); fast_op;
    }
#line 2003 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "src/ast.y" /* yacc.c:1646  */
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
#line 2025 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 318 "src/ast.y" /* yacc.c:1646  */
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
#line 2046 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 334 "src/ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-2].Reference) ? ast_Object((yyvsp[-2].Reference))->value : NULL, id, NULL, FALSE); fast_op; }
#line 2052 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 337 "src/ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference) ? ast_Object((yyvsp[-3].Reference))->value : NULL, id, NULL, TRUE); fast_op; }
#line 2058 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "src/ast.y" /* yacc.c:1646  */
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
#line 2074 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 349 "src/ast.y" /* yacc.c:1646  */
    {corto_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String)); (yyval.ast) = ast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference) ? ast_Object((yyvsp[-3].Reference))->value : NULL, id, NULL, TRUE); fast_op; }
#line 2080 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 353 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = corto_strdup("");}
#line 2086 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 354 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[-1].String);}
#line 2092 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 358 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String)=corto_alloc(sizeof(corto_id));strcpy((yyval.String),(yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2098 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 359 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String)=(yyvsp[-2].String); strcat((yyval.String),","); strcat((yyval.String),(yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2104 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 363 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = corto_asprintf("%s:%s", (yyvsp[-2].String), (yyvsp[0].String)); corto_dealloc((yyvsp[0].String));}
#line 2110 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 368 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[0].String);}
#line 2116 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 369 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "in";}
#line 2122 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Expression e = ast_Expression_resolve((yyvsp[-1].Reference), NULL);
        if (!e) {
            YYERROR;
        }
        (yyval.String)=ast_Parser_argumentToString(yparser(), (yyvsp[-1].Reference) ? ast_Object(e)->value : NULL, (yyvsp[0].String), FALSE); fast_op;
    }
#line 2134 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 380 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Expression e = ast_Expression_resolve((yyvsp[-2].Reference), NULL);
        if (!e) {
            YYERROR;
        }
        (yyval.String)=ast_Parser_argumentToString(yparser(), (yyvsp[-2].Reference) ? ast_Object(e)->value : NULL, (yyvsp[0].String), TRUE); fast_op;
    }
#line 2146 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 387 "src/ast.y" /* yacc.c:1646  */
    {
        corto_id argid;
        sprintf(argid, "$%s", (yyvsp[0].String));
        if (!strcmp((yyvsp[0].String), "__line")) {
            (yyval.String)=safe_ast_Parser_argumentToString(yparser(), corto_uint32_o, argid, FALSE); fast_op;
        } else {
            (yyval.String)=safe_ast_Parser_argumentToString(yparser(), corto_string_o, argid, FALSE); fast_op;
        }
    }
#line 2160 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_pushPackage(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2168 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 406 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_pushPackage(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2176 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 412 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_import(yparser(), (yyvsp[0].String)); fast_op;
    }
#line 2184 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 418 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_with(yparser());
    }
#line 2192 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 424 "src/ast.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op; }
#line 2198 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 425 "src/ast.y" /* yacc.c:1646  */
    {
        corto_object type = ast_Parser_lookup(yparser(), "default");
        (yyval.ast) = ast_declarationSeqDo(type, &(yyvsp[0].Declarations), FALSE); fast_op;
    }
#line 2207 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 429 "src/ast.y" /* yacc.c:1646  */
    {yparser()->isLocal = TRUE;}
#line 2213 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 429 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 2219 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 433 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op;}
#line 2225 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 434 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_declarationSeqDo((yyvsp[-2].Reference), &(yyvsp[0].Declarations), TRUE); fast_op;}
#line 2231 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 438 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Declarations).length = 0; (yyval.Declarations).buffer = NULL; ast_declarationSeqInsert(&(yyval.Declarations), &(yyvsp[0].Declaration));}
#line 2237 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 439 "src/ast.y" /* yacc.c:1646  */
    {ast_declarationSeqInsert(&(yyvsp[-2].Declarations), &(yyvsp[0].Declaration)); (yyval.Declarations) = (yyvsp[-2].Declarations);}
#line 2243 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 443 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = (yyvsp[0].String);}
#line 2249 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 444 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = (yyvsp[0].String);}
#line 2255 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 445 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = "in";}
#line 2261 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 452 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2267 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 463 "src/ast.y" /* yacc.c:1646  */
    {if ((yyvsp[0].ast)) ast_Parser_initValue(yparser(), (yyvsp[0].ast)); fast_op}
#line 2273 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 467 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPush(yparser()); fast_op;}
#line 2279 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 467 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op;}
#line 2285 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 467 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-2].ast);}
#line 2291 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 468 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPush(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL;}
#line 2297 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 477 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initMember(yparser(), (yyvsp[-1].String)); fast_op;}
#line 2303 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 482 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValuePush(yparser());}
#line 2309 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 482 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValuePop(yparser()); fast_op;}
#line 2315 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 483 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initKeyValueSet(yparser(), (yyvsp[0].ast)); fast_op;}
#line 2321 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 490 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_BooleanCreate((yyvsp[0].Boolean)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2327 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 491 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_CharacterCreate((yyvsp[0].Character)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2333 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 492 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_IntegerCreate((yyvsp[0].Integer)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2339 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 493 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_SignedIntegerCreate((yyvsp[0].SignedInteger)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2345 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 494 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_FloatingPointCreate((yyvsp[0].FloatingPoint)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2351 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 495 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_StringCreate((yyvsp[0].String)); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2357 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 496 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_NullCreate(); ast_Parser_collect(yparser(), (yyval.ast));}
#line 2363 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 500 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE(NULL)}
#line 2369 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 500 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE(); (yyval.ast)=(yyvsp[-1].ast);}
#line 2375 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 505 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2381 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 506 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].Reference);}
#line 2387 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 511 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_unaryExpr(yparser(), (yyvsp[0].ast), CORTO_MUL); fast_op;}
#line 2393 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 516 "src/ast.y" /* yacc.c:1646  */
    {PUSHCOMPLEX((yyvsp[0].ast))}
#line 2399 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 516 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_elementExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast)); fast_op; POPCOMPLEX()}
#line 2405 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 517 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_callExpr(yparser(), (yyvsp[-2].ast), NULL); fast_op;}
#line 2411 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 518 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_callExpr(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast)); fast_op;}
#line 2417 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 519 "src/ast.y" /* yacc.c:1646  */
    {ast_String str = ast_StringCreate((yyvsp[0].String)); if (!str) {YYERROR;} (yyval.ast) = ast_Parser_memberExpr(yparser(), (yyvsp[-2].ast), ast_Expression(str)); corto_release(str); fast_op;}
#line 2423 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 520 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_postfixExpr(yparser(), (yyvsp[-1].ast), CORTO_INC); fast_op}
#line 2429 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 521 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_postfixExpr(yparser(), (yyvsp[-1].ast), CORTO_DEC); fast_op}
#line 2435 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 526 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_unaryExpr(yparser(), (yyvsp[0].ast), (yyvsp[-1].Operator)); fast_op;}
#line 2441 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 530 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_SUB;}
#line 2447 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 531 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_NOT;}
#line 2453 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 532 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NOT;}
#line 2459 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 533 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NOT;}
#line 2465 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 534 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_INC;}
#line 2471 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 535 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_DEC;}
#line 2477 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 536 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_AND;}
#line 2483 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 541 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2489 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 541 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2495 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 541 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2501 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 545 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_MUL;}
#line 2507 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 546 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_DIV;}
#line 2513 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 547 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_MOD;}
#line 2519 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 552 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2525 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 552 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2531 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 552 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2537 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 556 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ADD;}
#line 2543 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 557 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_SUB;}
#line 2549 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 562 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2555 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 562 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2561 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 562 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_SHIFT_LEFT); fast_op;}
#line 2567 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 563 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2573 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 563 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2579 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 563 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_SHIFT_RIGHT); fast_op;}
#line 2585 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 568 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2591 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 568 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2597 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 568 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_AND); fast_op;}
#line 2603 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 573 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2609 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 573 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2615 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 573 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_XOR); fast_op;}
#line 2621 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 578 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2627 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 578 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2633 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 578 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_OR); fast_op;}
#line 2639 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 583 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2645 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 583 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2651 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 583 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2657 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 587 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_LT;}
#line 2663 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 588 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_GT;}
#line 2669 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 589 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_LTEQ;}
#line 2675 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 590 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_GTEQ;}
#line 2681 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 595 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2687 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 595 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2693 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 595 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;}
#line 2699 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 599 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_EQ;}
#line 2705 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 600 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_COND_NEQ;}
#line 2711 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 605 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2717 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 605 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2723 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 605 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_COND_AND); fast_op;}
#line 2729 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 610 "src/ast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].ast))}
#line 2735 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 610 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2741 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 610 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), CORTO_COND_OR); fast_op;}
#line 2747 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 614 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_initPushExpression(yparser()); fast_op;}
#line 2753 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 614 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-1].ast);}
#line 2759 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 620 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ternaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); fast_op;}
#line 2765 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 625 "src/ast.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].ast) && (yyvsp[0].ast)) {
            if (ast_Node((yyvsp[-2].ast))->kind != Ast_CommaExpr) {
                (yyval.ast) = ast_CommaCreate(); fast_op;
                ast_Comma_addExpression((yyval.ast), (yyvsp[-2].ast)); fast_op;
                ast_Parser_collect(yparser(), (yyval.ast)); fast_op;
            }
            ast_Comma_addExpression((yyval.ast), (yyvsp[0].ast)); fast_op;
        }
    }
#line 2780 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 639 "src/ast.y" /* yacc.c:1646  */
    {PUSHASSIGN((yyvsp[0].ast))}
#line 2786 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 639 "src/ast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2792 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 639 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[-2].Operator)); fast_op;
    }
#line 2800 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 645 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN;}
#line 2806 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 646 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_ADD;}
#line 2812 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 647 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_SUB;}
#line 2818 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 648 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_MUL;}
#line 2824 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 649 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_DIV;}
#line 2830 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 650 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_AND;}
#line 2836 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 651 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_OR;}
#line 2842 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 652 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Operator) = CORTO_ASSIGN_UPDATE;}
#line 2848 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 657 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initDeclare(yparser(), (yyvsp[-1].ast)); fast_op;
        ast_Parser_initPushStatic(yparser()); fast_op;
    }
#line 2857 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 660 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initPop(yparser()); fast_op;
        (yyval.ast) = NULL;
    }
#line 2866 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 664 "src/ast.y" /* yacc.c:1646  */
    {
        ast_Parser_initDeclare(yparser(), (yyvsp[-1].ast)); fast_op;
        ast_Parser_initPushStatic(yparser()); fast_op;
        ast_Parser_initPop(yparser()); fast_op;
        (yyval.ast) = NULL;
    }
#line 2877 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 670 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op;}
#line 2883 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 670 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL; }
#line 2889 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 671 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op;}
#line 2895 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 671 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPop(yparser()); fast_op;}
#line 2901 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 671 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2907 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 672 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op;}
#line 2913 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 672 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2919 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 673 "src/ast.y" /* yacc.c:1646  */
    {ast_Parser_initPushStatic(yparser()); fast_op; ast_Parser_initPop(yparser()); fast_op; (yyval.ast) = NULL; }
#line 2925 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 674 "src/ast.y" /* yacc.c:1646  */
    {
        if (!yparser()->isLocal && !yparser()->blockCount) {
            _fast_err("invalid usage of assignment operator, initialize objects with ':'");
            YYERROR;
        }
        ast_Parser_pushLvalue(yparser(), (yyvsp[-1].ast), TRUE);
    }
#line 2937 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 680 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.ast) = ast_Parser_binaryExpr(yparser(), (yyvsp[-3].ast), (yyvsp[0].ast), CORTO_ASSIGN); fast_op;
        ast_Parser_popLvalue(yparser());
    }
#line 2946 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 695 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.Variable) = ast_Storage(ast_Parser_initPushIdentifier(yparser(), (ast_Expression)(yyvsp[0].Reference))); fast_op
    }
#line 2954 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 697 "src/ast.y" /* yacc.c:1646  */
    {
        (yyval.Reference) = (yyvsp[-1].Variable);
        if ((yyval.Reference)) {
            ast_Parser_defineObject(yparser()); fast_op;
        }
    }
#line 2965 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 706 "src/ast.y" /* yacc.c:1646  */
    {(yyval.Reference) = ast_Parser_lookup(yparser(), (yyvsp[0].String)); fast_op;}
#line 2971 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 716 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "if";}
#line 2977 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 717 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "else";}
#line 2983 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 718 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "while";}
#line 2989 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 719 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "switch";}
#line 2995 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 720 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "case";}
#line 3001 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 721 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "default";}
#line 3007 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 722 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "break";}
#line 3013 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 723 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "for";}
#line 3019 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 724 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "try";}
#line 3025 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 725 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "catch";}
#line 3031 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 726 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "import";}
#line 3037 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 727 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "local";}
#line 3043 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 728 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "and";}
#line 3049 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 729 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "or";}
#line 3055 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 730 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "not";}
#line 3061 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 731 "src/ast.y" /* yacc.c:1646  */
    {(yyval.String) = "::";}
#line 3067 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 738 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast), NULL); fast_op;}
#line 3073 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 739 "src/ast.y" /* yacc.c:1646  */
    {ast_If nestedIf = ast_If(ast_Parser_ifStatement(yparser(), NULL, (yyvsp[0].ast), NULL)); fast_op; (yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-3].ast), (yyvsp[-2].ast), nestedIf); fast_op;}
#line 3079 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 740 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=ast_Parser_ifStatement(yparser(), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); fast_op;}
#line 3085 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 744 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 3091 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 751 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_whileStatement(yparser(), (yyvsp[-1].ast), (yyvsp[0].ast), FALSE); fast_op;}
#line 3097 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 752 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast) = ast_Parser_whileStatement(yparser(), (yyvsp[-1].ast), yparser()->block, TRUE); fast_op;}
#line 3103 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 756 "src/ast.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 3109 "src/y.tab.c" /* yacc.c:1646  */
    break;


#line 3113 "src/y.tab.c" /* yacc.c:1646  */
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
#line 759 "src/ast.y" /* yacc.c:1906  */


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
        parser->block = ast_BlockCreate(NULL);
        parser->block->isRoot = TRUE;

        /* Declare argv variable */
        corto_type t = corto_resolve(NULL, "sequence{string}");
        ast_Block_declare(parser->block, "argv", t, TRUE, FALSE);
        corto_release(t);

        yparser()->blockCount = 0;
    }

    if (!parser->scope) {
        corto_ptr_setref(&parser->scope, root_o);
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
