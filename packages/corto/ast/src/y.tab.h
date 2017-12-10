/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 145 "src/ast.y" /* yacc.c:1909  */

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

#line 181 "src/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
