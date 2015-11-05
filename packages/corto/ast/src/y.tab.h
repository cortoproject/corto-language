/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     MUL_ASSIGN = 269,
     DIV_ASSIGN = 270,
     ADD_ASSIGN = 271,
     SUB_ASSIGN = 272,
     OR_ASSIGN = 273,
     AND_ASSIGN = 274,
     UPDATE_ASSIGN = 275,
     LOR = 276,
     LAND = 277,
     LNOT = 278,
     LEQ = 279,
     GEQ = 280,
     EQ = 281,
     NEQ = 282,
     INC = 283,
     DEC = 284,
     SCOPE = 285,
     SCOPEPRE = 286,
     SHIFT_LEFT = 287,
     SHIFT_RIGHT = 288,
     ARROW_LEFT = 289,
     ARROW_RIGHT = 290,
     ENDL = 291,
     TAB = 292,
     INDENT = 293,
     DEDENT = 294,
     KW_UPDATE = 295,
     KW_DECLARE = 296,
     KW_DEFINE = 297,
     KW_DESTRUCT = 298,
     KW_ON = 299,
     KW_SCOPE = 300,
     KW_SELF = 301,
     KW_SYNCHRONIZED = 302,
     KW_IF = 303,
     KW_ELSE = 304,
     KW_WHILE = 305,
     KW_SWITCH = 306,
     KW_CASE = 307,
     KW_DEFAULT = 308,
     KW_BREAK = 309,
     KW_FOR = 310,
     KW_WAIT = 311,
     KW_TRY = 312,
     KW_CATCH = 313,
     KW_IMPORT = 314,
     KW_LOCAL = 315
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
#define MUL_ASSIGN 269
#define DIV_ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define OR_ASSIGN 273
#define AND_ASSIGN 274
#define UPDATE_ASSIGN 275
#define LOR 276
#define LAND 277
#define LNOT 278
#define LEQ 279
#define GEQ 280
#define EQ 281
#define NEQ 282
#define INC 283
#define DEC 284
#define SCOPE 285
#define SCOPEPRE 286
#define SHIFT_LEFT 287
#define SHIFT_RIGHT 288
#define ARROW_LEFT 289
#define ARROW_RIGHT 290
#define ENDL 291
#define TAB 292
#define INDENT 293
#define DEDENT 294
#define KW_UPDATE 295
#define KW_DECLARE 296
#define KW_DEFINE 297
#define KW_DESTRUCT 298
#define KW_ON 299
#define KW_SCOPE 300
#define KW_SELF 301
#define KW_SYNCHRONIZED 302
#define KW_IF 303
#define KW_ELSE 304
#define KW_WHILE 305
#define KW_SWITCH 306
#define KW_CASE 307
#define KW_DEFAULT 308
#define KW_BREAK 309
#define KW_FOR 310
#define KW_WAIT 311
#define KW_TRY 312
#define KW_CATCH 313
#define KW_IMPORT 314
#define KW_LOCAL 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 130 "src/ast.y"
{
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
}
/* Line 1529 of yacc.c.  */
#line 190 "src/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

