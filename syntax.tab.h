
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAINPRGM = 258,
     VAR = 259,
     BEGINPG = 260,
     ENDPG = 261,
     EN = 262,
     LET = 263,
     DEFINE = 264,
     CONST = 265,
     INT = 266,
     FLOAT = 267,
     IF = 268,
     THEN = 269,
     ELSE = 270,
     DO = 271,
     WHILE = 272,
     FOR = 273,
     FROM = 274,
     TO = 275,
     STEP = 276,
     INPUT = 277,
     OUTPUT = 278,
     PLUS = 279,
     MINUS = 280,
     MULT = 281,
     DIV = 282,
     AFF = 283,
     EGAL = 284,
     INF = 285,
     SUP = 286,
     SUPEG = 287,
     INFEG = 288,
     EGALITE = 289,
     DIFFERENT = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     PVG = 294,
     DP = 295,
     COMMA = 296,
     PO = 297,
     PF = 298,
     AO = 299,
     AF = 300,
     CO = 301,
     CF = 302,
     INTEGER = 303,
     FLOATING = 304,
     STRING = 305,
     IDF = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 11 "syntax.y"

    int integer;
    float real;
    char* str;  // For strings and identifiers



/* Line 1676 of yacc.c  */
#line 111 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


