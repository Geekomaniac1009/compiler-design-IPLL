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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 259,        /* INTEGER_CONSTANT  */
    FLOATING_CONSTANT = 260,       /* FLOATING_CONSTANT  */
    CHARACTER_CONSTANT = 261,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    TRUE = 263,                    /* TRUE  */
    FALSE = 264,                   /* FALSE  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    FLOAT = 267,                   /* FLOAT  */
    INTEGER = 268,                 /* INTEGER  */
    CHAR = 269,                    /* CHAR  */
    FOR = 270,                     /* FOR  */
    CONST = 271,                   /* CONST  */
    WHILE = 272,                   /* WHILE  */
    BOOL = 273,                    /* BOOL  */
    IF = 274,                      /* IF  */
    DO = 275,                      /* DO  */
    ELSE = 276,                    /* ELSE  */
    BEGIN_BLOCK = 277,             /* BEGIN_BLOCK  */
    END_BLOCK = 278,               /* END_BLOCK  */
    ARROW = 279,                   /* ARROW  */
    INC_OP = 280,                  /* INC_OP  */
    DEC_OP = 281,                  /* DEC_OP  */
    LEFT_OP = 282,                 /* LEFT_OP  */
    RIGHT_OP = 283,                /* RIGHT_OP  */
    LE_OP = 284,                   /* LE_OP  */
    GE_OP = 285,                   /* GE_OP  */
    EQ_OP = 286,                   /* EQ_OP  */
    NE_OP = 287,                   /* NE_OP  */
    AND_OP = 288,                  /* AND_OP  */
    OR_OP = 289                    /* OR_OP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER_CONSTANT 259
#define FLOATING_CONSTANT 260
#define CHARACTER_CONSTANT 261
#define STRING_LITERAL 262
#define TRUE 263
#define FALSE 264
#define RETURN 265
#define VOID 266
#define FLOAT 267
#define INTEGER 268
#define CHAR 269
#define FOR 270
#define CONST 271
#define WHILE 272
#define BOOL 273
#define IF 274
#define DO 275
#define ELSE 276
#define BEGIN_BLOCK 277
#define END_BLOCK 278
#define ARROW 279
#define INC_OP 280
#define DEC_OP 281
#define LEFT_OP 282
#define RIGHT_OP 283
#define LE_OP 284
#define GE_OP 285
#define EQ_OP 286
#define NE_OP 287
#define AND_OP 288
#define OR_OP 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "a7_220101122.y"

    int int_val;
    float float_val;
    char char_val;
    char *str_val;

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
