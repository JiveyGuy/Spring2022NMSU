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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_AND = 258,                   /* T_AND  */
    T_ASSIGN = 259,                /* T_ASSIGN  */
    T_BOOLTYPE = 260,              /* T_BOOLTYPE  */
    T_BREAK = 261,                 /* T_BREAK  */
    T_CHARCONSTANT = 262,          /* T_CHARCONSTANT  */
    T_CONTINUE = 263,              /* T_CONTINUE  */
    T_DOT = 264,                   /* T_DOT  */
    T_ELSE = 265,                  /* T_ELSE  */
    T_EQ = 266,                    /* T_EQ  */
    T_EXTERN = 267,                /* T_EXTERN  */
    T_FALSE = 268,                 /* T_FALSE  */
    T_FOR = 269,                   /* T_FOR  */
    T_FUNC = 270,                  /* T_FUNC  */
    T_GEQ = 271,                   /* T_GEQ  */
    T_GT = 272,                    /* T_GT  */
    T_ID = 273,                    /* T_ID  */
    T_IF = 274,                    /* T_IF  */
    T_INTCONSTANT = 275,           /* T_INTCONSTANT  */
    T_INTTYPE = 276,               /* T_INTTYPE  */
    T_LEFTSHT_IFT = 277,           /* T_LEFTSHT_IFT  */
    T_LEQ = 278,                   /* T_LEQ  */
    T_NEQ = 279,                   /* T_NEQ  */
    T_NULL = 280,                  /* T_NULL  */
    T_OR = 281,                    /* T_OR  */
    T_PACKAGE = 282,               /* T_PACKAGE  */
    T_RETURN = 283,                /* T_RETURN  */
    T_RIGHTSHT_IFT = 284,          /* T_RIGHTSHT_IFT  */
    T_STRINGCONSTANT = 285,        /* T_STRINGCONSTANT  */
    T_STRINGTYPE = 286,            /* T_STRINGTYPE  */
    T_TRUE = 287,                  /* T_TRUE  */
    T_VAR = 288,                   /* T_VAR  */
    T_VOID = 289,                  /* T_VOID  */
    T_WHILE = 290,                 /* T_WHILE  */
    T_LEFTSHIFT = 291,             /* T_LEFTSHIFT  */
    T_RIGHTSHIFT = 292             /* T_RIGHTSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_AND 258
#define T_ASSIGN 259
#define T_BOOLTYPE 260
#define T_BREAK 261
#define T_CHARCONSTANT 262
#define T_CONTINUE 263
#define T_DOT 264
#define T_ELSE 265
#define T_EQ 266
#define T_EXTERN 267
#define T_FALSE 268
#define T_FOR 269
#define T_FUNC 270
#define T_GEQ 271
#define T_GT 272
#define T_ID 273
#define T_IF 274
#define T_INTCONSTANT 275
#define T_INTTYPE 276
#define T_LEFTSHT_IFT 277
#define T_LEQ 278
#define T_NEQ 279
#define T_NULL 280
#define T_OR 281
#define T_PACKAGE 282
#define T_RETURN 283
#define T_RIGHTSHT_IFT 284
#define T_STRINGCONSTANT 285
#define T_STRINGTYPE 286
#define T_TRUE 287
#define T_VAR 288
#define T_VOID 289
#define T_WHILE 290
#define T_LEFTSHIFT 291
#define T_RIGHTSHIFT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "lab6.y"

	int value;
	char* string;

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
