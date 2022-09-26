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




/* First part of user prologue.  */
#line 1 "lab6.y"


/*
/_/\     /_______/\ /_______/\     /_____/\    
\:\ \    \::: _  \ \\::: _  \ \    \::::_\/_   
 \:\ \    \::(_)  \ \\::(_)  \/_    \:\/___/\  
  \:\ \____\:: __  \ \\::  _  \ \    \_::._\:\ 
   \:\/___/\\:.\ \  \ \\::(_)  \ \    /_____\/ 
    \_____\/ \__\/\__\/ \_______\/    \_____/ 
	                                    
 			
   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
	
	Editted by Jason Ivey, Sep 4, 2022:
		Added mult, uminus, and fixed spelling. 
		Fixed spacing issues. 
		Added int type to main. 
		Made debugsw external. 
		Added int yylex(); to supress warnings. 

	Editted by Jason Ivey, Sep 12, 2022:
	    Made debug = 0
	    added () to token list

	Editted by Jason Ivey, Sep 25, 2022:
	    removed old:
	    	symbol table
	    	rules
	    	debugsw
	    	base


	INPUT: LEX Description + Text
	OUTPUT: y.tab.c /h 
*/

// begin specs 
#include <stdio.h>
#include <ctype.h>

// Added this to supress warn
extern int yylex(void);

// Called by yyparse on error 
void yyerror (s, i)  
     char *s;
     int i;
{
  printf ("At line %d ERROR: %s\n", i, s);
}


#line 128 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 260 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_AND = 3,                      /* T_AND  */
  YYSYMBOL_T_ASSIGN = 4,                   /* T_ASSIGN  */
  YYSYMBOL_T_BOOLTYPE = 5,                 /* T_BOOLTYPE  */
  YYSYMBOL_T_BREAK = 6,                    /* T_BREAK  */
  YYSYMBOL_T_CHARCONSTANT = 7,             /* T_CHARCONSTANT  */
  YYSYMBOL_T_CONTINUE = 8,                 /* T_CONTINUE  */
  YYSYMBOL_T_DOT = 9,                      /* T_DOT  */
  YYSYMBOL_T_ELSE = 10,                    /* T_ELSE  */
  YYSYMBOL_T_EQ = 11,                      /* T_EQ  */
  YYSYMBOL_T_EXTERN = 12,                  /* T_EXTERN  */
  YYSYMBOL_T_FALSE = 13,                   /* T_FALSE  */
  YYSYMBOL_T_FOR = 14,                     /* T_FOR  */
  YYSYMBOL_T_FUNC = 15,                    /* T_FUNC  */
  YYSYMBOL_T_GEQ = 16,                     /* T_GEQ  */
  YYSYMBOL_T_GT = 17,                      /* T_GT  */
  YYSYMBOL_T_ID = 18,                      /* T_ID  */
  YYSYMBOL_T_IF = 19,                      /* T_IF  */
  YYSYMBOL_T_INTCONSTANT = 20,             /* T_INTCONSTANT  */
  YYSYMBOL_T_INTTYPE = 21,                 /* T_INTTYPE  */
  YYSYMBOL_T_LEFTSHT_IFT = 22,             /* T_LEFTSHT_IFT  */
  YYSYMBOL_T_LEQ = 23,                     /* T_LEQ  */
  YYSYMBOL_T_NEQ = 24,                     /* T_NEQ  */
  YYSYMBOL_T_NULL = 25,                    /* T_NULL  */
  YYSYMBOL_T_OR = 26,                      /* T_OR  */
  YYSYMBOL_T_PACKAGE = 27,                 /* T_PACKAGE  */
  YYSYMBOL_T_RETURN = 28,                  /* T_RETURN  */
  YYSYMBOL_T_RIGHTSHT_IFT = 29,            /* T_RIGHTSHT_IFT  */
  YYSYMBOL_T_STRINGCONSTANT = 30,          /* T_STRINGCONSTANT  */
  YYSYMBOL_T_STRINGTYPE = 31,              /* T_STRINGTYPE  */
  YYSYMBOL_T_TRUE = 32,                    /* T_TRUE  */
  YYSYMBOL_T_VAR = 33,                     /* T_VAR  */
  YYSYMBOL_T_VOID = 34,                    /* T_VOID  */
  YYSYMBOL_T_WHILE = 35,                   /* T_WHILE  */
  YYSYMBOL_T_LEFTSHIFT = 36,               /* T_LEFTSHIFT  */
  YYSYMBOL_T_RIGHTSHIFT = 37,              /* T_RIGHTSHIFT  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_Externs = 56,                   /* Externs  */
  YYSYMBOL_ExternDefn = 57,                /* ExternDefn  */
  YYSYMBOL_ExternParmList = 58,            /* ExternParmList  */
  YYSYMBOL_FullExternParmList = 59,        /* FullExternParmList  */
  YYSYMBOL_FieldDecls = 60,                /* FieldDecls  */
  YYSYMBOL_FieldDecl = 61,                 /* FieldDecl  */
  YYSYMBOL_MethodDecls = 62,               /* MethodDecls  */
  YYSYMBOL_MethodDecl = 63,                /* MethodDecl  */
  YYSYMBOL_MethodParmList = 64,            /* MethodParmList  */
  YYSYMBOL_FullMethodParmList = 65,        /* FullMethodParmList  */
  YYSYMBOL_Block = 66,                     /* Block  */
  YYSYMBOL_VarDecls = 67,                  /* VarDecls  */
  YYSYMBOL_VarDecl = 68,                   /* VarDecl  */
  YYSYMBOL_Statements = 69,                /* Statements  */
  YYSYMBOL_Statement = 70,                 /* Statement  */
  YYSYMBOL_Assign = 71,                    /* Assign  */
  YYSYMBOL_Lvalue = 72,                    /* Lvalue  */
  YYSYMBOL_MethodCall = 73,                /* MethodCall  */
  YYSYMBOL_MethodCallList = 74,            /* MethodCallList  */
  YYSYMBOL_FullMethodCallList = 75,        /* FullMethodCallList  */
  YYSYMBOL_MethodArg = 76,                 /* MethodArg  */
  YYSYMBOL_Expr = 77,                      /* Expr  */
  YYSYMBOL_Simpleexpression = 78,          /* Simpleexpression  */
  YYSYMBOL_Relop = 79,                     /* Relop  */
  YYSYMBOL_Additiveexpression = 80,        /* Additiveexpression  */
  YYSYMBOL_Addop = 81,                     /* Addop  */
  YYSYMBOL_Term = 82,                      /* Term  */
  YYSYMBOL_Multop = 83,                    /* Multop  */
  YYSYMBOL_Factor = 84,                    /* Factor  */
  YYSYMBOL_ExternType = 85,                /* ExternType  */
  YYSYMBOL_Type = 86,                      /* Type  */
  YYSYMBOL_MethodType = 87,                /* MethodType  */
  YYSYMBOL_BoolConstant = 88,              /* BoolConstant  */
  YYSYMBOL_ArrayType = 89,                 /* ArrayType  */
  YYSYMBOL_Constant = 90                   /* Constant  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,    53,     2,     2,     2,     2,     2,     2,
      40,    41,    51,    49,    43,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      47,    44,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   108,   108,   110,   111,   113,   115,   116,   118,   119,
     121,   122,   124,   126,   128,   130,   131,   133,   135,   136,
     138,   139,   141,   143,   144,   146,   147,   149,   150,   152,
     154,   156,   158,   158,   160,   162,   164,   165,   167,   168,
     170,   170,   172,   174,   176,   178,   179,   180,   182,   184,
     186,   188,   189,   191,   192,   193,   194,   195,   196,   198,
     199,   201,   202,   204,   205,   207,   208,   209,   210,   211,
     212,   214,   215,   216,   217,   218,   219,   220,   222,   223,
     225,   226,   228,   229,   231,   232,   234,   236,   237
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
  "\"end of file\"", "error", "\"invalid token\"", "T_AND", "T_ASSIGN",
  "T_BOOLTYPE", "T_BREAK", "T_CHARCONSTANT", "T_CONTINUE", "T_DOT",
  "T_ELSE", "T_EQ", "T_EXTERN", "T_FALSE", "T_FOR", "T_FUNC", "T_GEQ",
  "T_GT", "T_ID", "T_IF", "T_INTCONSTANT", "T_INTTYPE", "T_LEFTSHT_IFT",
  "T_LEQ", "T_NEQ", "T_NULL", "T_OR", "T_PACKAGE", "T_RETURN",
  "T_RIGHTSHT_IFT", "T_STRINGCONSTANT", "T_STRINGTYPE", "T_TRUE", "T_VAR",
  "T_VOID", "T_WHILE", "T_LEFTSHIFT", "T_RIGHTSHIFT", "'{'", "'}'", "'('",
  "')'", "';'", "','", "'='", "'['", "']'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'!'", "$accept", "Program", "Externs", "ExternDefn",
  "ExternParmList", "FullExternParmList", "FieldDecls", "FieldDecl",
  "MethodDecls", "MethodDecl", "MethodParmList", "FullMethodParmList",
  "Block", "VarDecls", "VarDecl", "Statements", "Statement", "Assign",
  "Lvalue", "MethodCall", "MethodCallList", "FullMethodCallList",
  "MethodArg", "Expr", "Simpleexpression", "Relop", "Additiveexpression",
  "Addop", "Term", "Multop", "Factor", "ExternType", "Type", "MethodType",
  "BoolConstant", "ArrayType", "Constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,    16,    40,    21,    -5,    36,   -91,    48,   -91,    27,
      39,    12,    41,   -91,   -91,   -91,    37,   -91,    38,   -91,
      67,    74,    41,    11,    12,    23,    72,    53,    74,   -91,
     -91,   -91,    54,   -91,    75,   -22,    56,    59,   -91,   -91,
     -91,    55,   -91,     5,   -91,    82,    34,   -91,   -91,   -91,
     -91,    60,    34,    65,   -91,   -91,   -91,    62,    11,    82,
      69,   -91,    76,   -91,    90,    85,    76,    23,    68,    73,
      18,    77,    31,    78,   -91,    80,    85,    79,    70,    83,
     -91,    84,    86,   -91,   -91,     6,    44,    44,    29,   -91,
      44,   -91,   -91,   -91,    44,   -91,   -91,   -91,    20,   -91,
      44,    44,    44,   -91,    81,   -91,    87,   -91,    64,   -36,
       1,   -91,   -91,    88,    91,    89,    92,    94,   -91,    44,
      95,   -91,   -91,   -91,     6,   -91,   -91,   -91,   -91,   -91,
     -91,    44,   -91,   -91,    44,   -91,   -91,   -91,   -91,   -91,
     -91,    44,   -91,    69,   -91,    96,    69,    93,   -91,   -91,
     -36,     1,   -91,   106,   -91,   -91,   -91,    44,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,     0,     4,     0,
       0,     6,    10,    81,    80,    78,     0,     7,     8,    79,
       0,    15,    10,     0,     6,     0,     0,     0,    15,    11,
      82,    83,     0,     9,     0,     0,     0,     0,     2,    16,
       5,     0,    12,     0,    13,    18,     0,    85,    87,    84,
      88,     0,     0,     0,    19,    86,    14,    20,     0,    18,
       0,    21,    23,    17,     0,    27,    23,     0,     0,     0,
      32,     0,     0,     0,    29,     0,    27,     0,     0,     0,
      24,     0,     0,    48,    49,    36,     0,     0,     0,    45,
       0,    22,    28,    30,     0,    34,    25,    26,    71,    41,
       0,     0,     0,    72,     0,    37,    38,    40,    50,    51,
      59,    63,    74,     0,     0,     0,     0,     0,    31,     0,
       0,    77,    76,    35,    36,    57,    56,    53,    58,    54,
      55,     0,    61,    62,     0,    67,    69,    68,    70,    65,
      66,     0,    33,     0,    46,     0,     0,     0,    75,    39,
      52,    60,    64,    43,    47,    44,    73,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   120,   -91,   103,   -91,   107,   -91,   109,   -91,
      97,   -91,   -60,    98,   -91,    66,   -91,   -91,   -91,   -55,
      17,   -91,   -91,   -85,   -91,   -91,     9,   -91,    10,   -91,
     -90,   -91,   -17,    99,   -91,   100,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    16,    17,    21,    22,    27,    28,
      53,    54,    74,    65,    66,    75,    76,    77,    78,   103,
     104,   105,   106,   107,   108,   131,   109,   134,   110,   141,
     111,    18,    19,    32,    50,    36,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,   113,   114,   116,   135,   117,    31,     1,    35,   118,
      79,   121,   122,   132,   133,   120,    13,    13,    47,    47,
      42,    79,    43,   136,    98,    48,    48,   137,    13,    55,
     138,     5,    14,    14,   147,    57,    99,    49,    49,    13,
       6,    31,    47,    15,    14,    30,   100,    98,     7,    48,
      81,   152,   139,   140,     9,    14,   101,    47,    85,   102,
      85,    49,    98,    86,    48,   119,    10,    11,    34,   100,
     115,    88,   158,    89,    20,   125,    49,    12,    23,   101,
     126,    24,   102,   153,   100,    25,   155,   127,   128,    26,
      37,    68,    38,    69,   101,    41,    40,   102,    44,    45,
      52,    46,    56,    70,    71,    59,    58,    62,    67,    64,
      83,   129,   130,    72,    94,    84,   157,    87,    90,    91,
      73,    93,   123,    62,     8,    95,    96,    33,    97,    29,
     124,   144,   143,   145,   142,   146,   148,    39,   154,   156,
     150,   149,    92,     0,   151,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    60,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      60,    86,    87,    88,     3,    90,    23,    12,    25,    94,
      65,   101,   102,    49,    50,   100,     5,     5,    13,    13,
      42,    76,    44,    22,    18,    20,    20,    26,     5,    46,
      29,    15,    21,    21,   119,    52,    30,    32,    32,     5,
       0,    58,    13,    31,    21,    34,    40,    18,    27,    20,
      67,   141,    51,    52,    18,    21,    50,    13,    40,    53,
      40,    32,    18,    45,    20,    45,    18,    40,    45,    40,
      41,    40,   157,    42,    33,    11,    32,    38,    41,    50,
      16,    43,    53,   143,    40,    18,   146,    23,    24,    15,
      18,     6,    39,     8,    50,    20,    42,    53,    42,    40,
      18,    46,    42,    18,    19,    43,    41,    38,    18,    33,
      42,    47,    48,    28,    44,    42,    10,    40,    40,    39,
      35,    42,    41,    38,     4,    42,    42,    24,    42,    22,
      43,    42,    41,    41,    46,    41,    41,    28,    42,    46,
     131,   124,    76,    -1,   134,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    55,    56,    57,    15,     0,    27,    56,    18,
      18,    40,    38,     5,    21,    31,    58,    59,    85,    86,
      33,    60,    61,    41,    43,    18,    15,    62,    63,    60,
      34,    86,    87,    58,    45,    86,    89,    18,    39,    62,
      42,    20,    42,    44,    42,    40,    46,    13,    20,    32,
      88,    90,    18,    64,    65,    86,    42,    86,    41,    43,
      87,    64,    38,    66,    33,    67,    68,    18,     6,     8,
      18,    19,    28,    35,    66,    69,    70,    71,    72,    73,
      67,    86,    89,    42,    42,    40,    45,    40,    40,    42,
      40,    39,    69,    42,    44,    42,    42,    42,    18,    30,
      40,    50,    53,    73,    74,    75,    76,    77,    78,    80,
      82,    84,    90,    77,    77,    41,    77,    77,    77,    45,
      77,    84,    84,    41,    43,    11,    16,    23,    24,    47,
      48,    79,    49,    50,    81,     3,    22,    26,    29,    51,
      52,    83,    46,    41,    42,    41,    41,    77,    41,    74,
      80,    82,    84,    66,    42,    66,    46,    10,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    70,    73,    74,    74,    75,    75,
      76,    76,    70,    70,    70,    70,    70,    70,    70,    70,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     2,     8,     0,     1,     1,     3,
       0,     2,     4,     4,     6,     0,     2,     7,     0,     1,
       2,     4,     4,     0,     2,     4,     4,     0,     2,     1,
       2,     3,     1,     4,     2,     4,     0,     1,     1,     3,
       1,     1,     7,     5,     5,     2,     4,     5,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1
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

#line 1438 "y.tab.c"

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

#line 240 "lab6.y"
	/* end of rules, start of program */

int main()
{ 
	yyparse();
}