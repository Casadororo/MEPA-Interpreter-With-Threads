/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LEMEPA_TAB_H_INCLUDED
# define YY_YY_LEMEPA_TAB_H_INCLUDED
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
    DOIS_PONTOS = 258,             /* DOIS_PONTOS  */
    ROTULO = 259,                  /* ROTULO  */
    INTEIRO = 260,                 /* INTEIRO  */
    VIRGULA = 261,                 /* VIRGULA  */
    INPP = 262,                    /* INPP  */
    PARA = 263,                    /* PARA  */
    SOMA = 264,                    /* SOMA  */
    SUBT = 265,                    /* SUBT  */
    MULT = 266,                    /* MULT  */
    DIVI = 267,                    /* DIVI  */
    INVR = 268,                    /* INVR  */
    CONJ = 269,                    /* CONJ  */
    DISJ = 270,                    /* DISJ  */
    NEGA = 271,                    /* NEGA  */
    CMME = 272,                    /* CMME  */
    CMMA = 273,                    /* CMMA  */
    CMIG = 274,                    /* CMIG  */
    CMDG = 275,                    /* CMDG  */
    CMEG = 276,                    /* CMEG  */
    CMAG = 277,                    /* CMAG  */
    NADA = 278,                    /* NADA  */
    LEIT = 279,                    /* LEIT  */
    IMPR = 280,                    /* IMPR  */
    STHR = 281,                    /* STHR  */
    CRCT = 282,                    /* CRCT  */
    AMEM = 283,                    /* AMEM  */
    DMEM = 284,                    /* DMEM  */
    ENPR = 285,                    /* ENPR  */
    ENRT = 286,                    /* ENRT  */
    DSVS = 287,                    /* DSVS  */
    DSVF = 288,                    /* DSVF  */
    ETHR = 289,                    /* ETHR  */
    CRVL = 290,                    /* CRVL  */
    ARMZ = 291,                    /* ARMZ  */
    CRVI = 292,                    /* CRVI  */
    ARMI = 293,                    /* ARMI  */
    CREN = 294,                    /* CREN  */
    CHPR = 295,                    /* CHPR  */
    RTPR = 296,                    /* RTPR  */
    DSVR = 297,                    /* DSVR  */
    CTHR = 298                     /* CTHR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LEMEPA_TAB_H_INCLUDED  */
