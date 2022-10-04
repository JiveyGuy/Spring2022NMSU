#define T_AND 257
#define T_ASSIGN 258
#define T_BOOLTYPE 259
#define T_BREAK 260
#define T_CHARCONSTANT 261
#define T_CONTINUE 262
#define T_DOT 263
#define T_ELSE 264
#define T_EQ 265
#define T_EXTERN 266
#define T_FALSE 267
#define T_FOR 268
#define T_FUNC 269
#define T_GEQ 270
#define T_GT 271
#define T_LT 272
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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE
{
  int value;
  char* string;
  struct ASTnodetype *astnode; /*keeps track of our nodes*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
