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
#line 1 "a7_220101122.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_no;
int yylex(void);
void yyerror(const char *s);

/* Symbol table structure */
struct symbol {
    char *name;
    char *type;
    int scope;
    int line_no;
    struct symbol *next;
};

/* Symbol table operations */
struct symbol *symbol_table = NULL;
int current_scope = 0;
int current_line = 0;
char current_type[20];

void add_symbol(char *name, char *type, int scope, int line);
void print_symbol_table();
void enter_scope();
void exit_scope();

/* File for reductions */
FILE *reduction_file;
FILE *symbol_table_file;


#line 106 "y.tab.c"

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

#line 234 "y.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 4,           /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 5,          /* FLOATING_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 6,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_INTEGER = 13,                   /* INTEGER  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_CONST = 16,                     /* CONST  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_BEGIN_BLOCK = 22,               /* BEGIN_BLOCK  */
  YYSYMBOL_END_BLOCK = 23,                 /* END_BLOCK  */
  YYSYMBOL_ARROW = 24,                     /* ARROW  */
  YYSYMBOL_INC_OP = 25,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 26,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 27,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 28,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 29,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 30,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 31,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 32,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 33,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 34,                     /* OR_OP  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '!'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '?'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_primary_expression = 54,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 55,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 56,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 57,          /* unary_expression  */
  YYSYMBOL_unary_operator = 58,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 59, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 60,       /* additive_expression  */
  YYSYMBOL_relational_expression = 61,     /* relational_expression  */
  YYSYMBOL_equality_expression = 62,       /* equality_expression  */
  YYSYMBOL_logical_AND_expression = 63,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 64,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 65,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 66,     /* assignment_expression  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_init_declarator = 69,           /* init_declarator  */
  YYSYMBOL_type_specifier = 70,            /* type_specifier  */
  YYSYMBOL_declarator = 71,                /* declarator  */
  YYSYMBOL_direct_declarator = 72,         /* direct_declarator  */
  YYSYMBOL_pointer = 73,                   /* pointer  */
  YYSYMBOL_parameter_list = 74,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 75,     /* parameter_declaration  */
  YYSYMBOL_initializer = 76,               /* initializer  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_compound_statement = 78,        /* compound_statement  */
  YYSYMBOL_79_1 = 79,                      /* $@1  */
  YYSYMBOL_block_item_list_opt = 80,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 81,           /* block_item_list  */
  YYSYMBOL_block_item = 82,                /* block_item  */
  YYSYMBOL_expression_statement = 83,      /* expression_statement  */
  YYSYMBOL_selection_statement = 84,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 85,       /* iteration_statement  */
  YYSYMBOL_expression_opt = 86,            /* expression_opt  */
  YYSYMBOL_jump_statement = 87,            /* jump_statement  */
  YYSYMBOL_translation_unit = 88,          /* translation_unit  */
  YYSYMBOL_function_definition = 89,       /* function_definition  */
  YYSYMBOL_function_declarator = 90        /* function_declarator  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,    44,     2,     2,     2,    46,    40,     2,
      35,    36,    41,    42,    39,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    52,
      47,    51,    48,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    62,    64,    66,    68,    70,    75,    77,
      79,    81,    83,    88,    90,    95,    97,   102,   104,   106,
     108,   110,   115,   117,   119,   121,   126,   128,   130,   135,
     137,   139,   141,   143,   148,   150,   152,   157,   159,   164,
     166,   171,   173,   178,   180,   185,   190,   198,   200,   205,
     211,   217,   226,   235,   240,   245,   252,   259,   269,   274,
     276,   281,   288,   293,   295,   300,   305,   307,   309,   311,
     313,   318,   318,   326,   329,   333,   335,   340,   342,   347,
     352,   354,   359,   364,   367,   371,   376,   378,   380,   382,
     387,   392,   394
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHARACTER_CONSTANT",
  "STRING_LITERAL", "TRUE", "FALSE", "RETURN", "VOID", "FLOAT", "INTEGER",
  "CHAR", "FOR", "CONST", "WHILE", "BOOL", "IF", "DO", "ELSE",
  "BEGIN_BLOCK", "END_BLOCK", "ARROW", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "'('",
  "')'", "'['", "']'", "','", "'&'", "'*'", "'+'", "'-'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'?'", "':'", "'='", "';'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "init_declarator", "type_specifier", "declarator",
  "direct_declarator", "pointer", "parameter_list",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "$@1", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "expression_opt", "jump_statement",
  "translation_unit", "function_definition", "function_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   -80,   -80,   -80,    24,     1,    12,    24,   -80,    -7,
     -80,   -28,   -31,   -80,    36,     7,   -80,   -80,    -4,    59,
     -80,   159,    32,   -80,   -80,   -80,    46,     2,    49,   -80,
      61,   -80,   -80,   -80,   -80,   -80,   159,   -80,   -80,   -80,
     -80,   -80,   -80,   -16,    55,   159,   -23,    33,   -14,    60,
      51,   -32,   -80,   -80,   -80,     0,    67,   -80,   111,   103,
      24,   -80,   -80,    90,   125,   137,   159,   159,   -80,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   -80,    62,   159,    94,    95,   -80,   -80,
      23,   -80,   -80,   108,    67,   -80,   -80,   -80,   -80,    81,
     -80,   -80,   -80,   -80,   -80,   -80,    64,   -80,    96,   -80,
     -80,   -80,   -80,   -80,   -23,   -23,    33,    33,    33,    33,
     -14,   -14,    60,    51,    85,   -80,    86,   159,   159,   -80,
     -80,   -80,   -80,   159,   -80,   159,   -80,    93,   101,   -80,
     -80,   159,   117,    97,   126,   159,   117,   110,   -80,   117,
     -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    49,    51,    50,    87,     0,     0,    86,    89,    54,
      58,     0,    47,    53,     0,     0,     1,    88,     0,     0,
      46,     0,    54,    52,    71,    90,    57,    64,     0,    59,
       0,     2,     3,     4,     5,     6,     0,    17,    18,    19,
      20,    21,     8,    15,    22,     0,    26,    29,    34,    37,
      39,    41,    43,    65,    48,     0,    74,    62,    63,    56,
       0,    55,    45,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    84,     0,     0,    83,    77,
       0,    78,    66,     0,    73,    75,    67,    68,    69,     0,
      70,    61,    60,     7,    12,    10,     0,    13,     0,    44,
      23,    24,    25,    22,    27,    28,    32,    33,    30,    31,
      35,    36,    38,    40,     0,    56,     0,    84,     0,    72,
      76,    79,    11,     0,     9,     0,    85,     0,     0,    14,
      42,    84,    84,     0,    80,    84,    84,     0,    81,    84,
      82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -20,   -80,    45,    20,    26,    68,
      69,   -80,    16,   -21,   -35,   -29,   -80,   -15,   -80,   139,
     127,   100,   107,   -80,   -59,   141,   -80,   -80,   -80,    74,
     -80,   -80,   -80,   -79,   -80,   109,   -80,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    42,    43,   106,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    62,    88,     4,    11,     5,    12,    13,
      14,    28,    29,    54,    91,    92,    56,    93,    94,    95,
      96,    97,    98,    99,   100,     6,     7,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    63,    81,    27,     9,    57,   126,     1,    64,     2,
       3,     1,    16,     2,     3,    74,    75,    82,    69,    65,
      21,    66,    70,    71,    20,    68,    22,    89,    18,    24,
      19,   108,    26,    76,    77,     1,    83,     2,     3,    22,
      27,    90,    10,    10,   107,    27,   109,   124,   137,   110,
     111,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   143,    30,    10,    89,   147,    55,   -91,    19,
      31,    32,    33,    34,    35,    72,    73,    85,     1,    90,
       2,     3,    86,   144,    80,    59,    87,   148,    60,    24,
     150,    78,    79,   138,   116,   117,   118,   119,   125,    61,
     132,    60,    36,   133,   120,   121,    67,    37,    38,    39,
      40,    41,   139,     8,   101,   113,    17,   114,   115,   -84,
      31,    32,    33,    34,    35,   -92,   103,    85,   104,   127,
     128,   129,    86,   131,   134,   135,    87,   142,   136,    24,
      31,    32,    33,    34,    35,   141,   149,   146,   122,   145,
     123,   140,    36,    23,    58,    84,    25,    37,    38,    39,
      40,    41,    31,    32,    33,    34,    35,   102,   130,     0,
       0,     0,    36,   105,     0,     0,     0,    37,    38,    39,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,    37,
      38,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
      21,    36,    34,    18,     3,     3,    85,    11,    24,    13,
      14,    11,     0,    13,    14,    29,    30,    49,    41,    35,
      51,    37,    45,    46,    52,    45,     3,    56,    35,    22,
      37,    66,    36,    47,    48,    11,    36,    13,    14,     3,
      55,    56,    41,    41,    65,    60,    67,    82,   127,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   141,     4,    41,    94,   145,    35,    22,    37,
       3,     4,     5,     6,     7,    42,    43,    10,    11,    94,
      13,    14,    15,   142,    33,    36,    19,   146,    39,    22,
     149,    31,    32,   128,    74,    75,    76,    77,    36,    38,
      36,    39,    35,    39,    78,    79,    51,    40,    41,    42,
      43,    44,   133,     4,     3,   135,     7,    72,    73,    52,
       3,     4,     5,     6,     7,    22,    36,    10,     3,    35,
      35,    23,    15,    52,    38,    50,    19,    36,    52,    22,
       3,     4,     5,     6,     7,    52,    36,    21,    80,    52,
      81,   135,    35,    14,    27,    55,    15,    40,    41,    42,
      43,    44,     3,     4,     5,     6,     7,    60,    94,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    13,    14,    68,    70,    88,    89,    88,     3,
      41,    69,    71,    72,    73,    90,     0,    88,    35,    37,
      52,    51,     3,    72,    22,    78,    36,    70,    74,    75,
       4,     3,     4,     5,     6,     7,    35,    40,    41,    42,
      43,    44,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    76,    35,    79,     3,    73,    36,
      39,    38,    66,    67,    24,    35,    37,    51,    57,    41,
      45,    46,    42,    43,    29,    30,    47,    48,    31,    32,
      33,    34,    49,    36,    74,    10,    15,    19,    67,    68,
      70,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      87,     3,    75,    36,     3,    36,    56,    66,    67,    66,
      57,    57,    57,    57,    59,    59,    60,    60,    60,    60,
      61,    61,    62,    63,    67,    36,    86,    35,    35,    23,
      82,    52,    36,    39,    38,    50,    52,    86,    67,    66,
      65,    52,    36,    86,    77,    52,    21,    86,    77,    36,
      77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    76,    77,    77,    77,    77,
      77,    79,    78,    80,    80,    81,    81,    82,    82,    83,
      84,    84,    85,    86,    86,    87,    88,    88,    88,    88,
      89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     1,     1,     4,     4,     3,     1,     1,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     0,     1,     2,     1,     1,     2,
       5,     7,     9,     1,     0,     3,     1,     1,     2,     2,
       3,     3,     4
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 61 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> IDENTIFIER (%s)\n", line_no, (yyvsp[0].str_val)); }
#line 1428 "y.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 63 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> INTEGER_CONSTANT (%d)\n", line_no, (yyvsp[0].int_val)); }
#line 1434 "y.tab.c"
    break;

  case 4: /* primary_expression: FLOATING_CONSTANT  */
#line 65 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> FLOATING_CONSTANT (%f)\n", line_no, (yyvsp[0].float_val)); }
#line 1440 "y.tab.c"
    break;

  case 5: /* primary_expression: CHARACTER_CONSTANT  */
#line 67 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> CHARACTER_CONSTANT (%c)\n", line_no, (yyvsp[0].char_val)); }
#line 1446 "y.tab.c"
    break;

  case 6: /* primary_expression: STRING_LITERAL  */
#line 69 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> STRING_LITERAL (%s)\n", line_no, (yyvsp[0].str_val)); }
#line 1452 "y.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 71 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> ( expression )\n", line_no); }
#line 1458 "y.tab.c"
    break;

  case 8: /* postfix_expression: primary_expression  */
#line 76 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> primary_expression\n", line_no); }
#line 1464 "y.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 78 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression [ expression ]\n", line_no); }
#line 1470 "y.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression '(' ')'  */
#line 80 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression ( )\n", line_no); }
#line 1476 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 82 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression ( argument_expression_list )\n", line_no); }
#line 1482 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 84 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression -> IDENTIFIER (%s)\n", line_no, (yyvsp[0].str_val)); }
#line 1488 "y.tab.c"
    break;

  case 13: /* argument_expression_list: assignment_expression  */
#line 89 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: argument_expression_list -> assignment_expression\n", line_no); }
#line 1494 "y.tab.c"
    break;

  case 14: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 91 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: argument_expression_list -> argument_expression_list , assignment_expression\n", line_no); }
#line 1500 "y.tab.c"
    break;

  case 15: /* unary_expression: postfix_expression  */
#line 96 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_expression -> postfix_expression\n", line_no); }
#line 1506 "y.tab.c"
    break;

  case 16: /* unary_expression: unary_operator unary_expression  */
#line 98 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_expression -> unary_operator unary_expression\n", line_no); }
#line 1512 "y.tab.c"
    break;

  case 17: /* unary_operator: '&'  */
#line 103 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> & (address op) \n", line_no); }
#line 1518 "y.tab.c"
    break;

  case 18: /* unary_operator: '*'  */
#line 105 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> * (dereference op) \n", line_no); }
#line 1524 "y.tab.c"
    break;

  case 19: /* unary_operator: '+'  */
#line 107 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> + (positive sign op) \n", line_no); }
#line 1530 "y.tab.c"
    break;

  case 20: /* unary_operator: '-'  */
#line 109 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> - (neg sign op) \n", line_no); }
#line 1536 "y.tab.c"
    break;

  case 21: /* unary_operator: '!'  */
#line 111 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> ! (boolean negatn op) \n", line_no); }
#line 1542 "y.tab.c"
    break;

  case 22: /* multiplicative_expression: unary_expression  */
#line 116 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> unary_expression\n", line_no); }
#line 1548 "y.tab.c"
    break;

  case 23: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 118 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression * unary_expression (mult op) \n", line_no); }
#line 1554 "y.tab.c"
    break;

  case 24: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 120 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression / unary_expression (div op) \n", line_no); }
#line 1560 "y.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression '%' unary_expression  */
#line 122 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression %% unary_expression (mod op) \n", line_no); }
#line 1566 "y.tab.c"
    break;

  case 26: /* additive_expression: multiplicative_expression  */
#line 127 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> multiplicative_expression\n", line_no); }
#line 1572 "y.tab.c"
    break;

  case 27: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 129 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> additive_expression + multiplicative_expression (addn op) \n", line_no); }
#line 1578 "y.tab.c"
    break;

  case 28: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 131 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> additive_expression - multiplicative_expression (sub op) \n", line_no); }
#line 1584 "y.tab.c"
    break;

  case 29: /* relational_expression: additive_expression  */
#line 136 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> additive_expression\n", line_no); }
#line 1590 "y.tab.c"
    break;

  case 30: /* relational_expression: relational_expression '<' additive_expression  */
#line 138 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression < additive_expression (lt op) \n", line_no); }
#line 1596 "y.tab.c"
    break;

  case 31: /* relational_expression: relational_expression '>' additive_expression  */
#line 140 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression > additive_expression (gt op) \n", line_no); }
#line 1602 "y.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LE_OP additive_expression  */
#line 142 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression <= additive_expression (lte op) \n", line_no); }
#line 1608 "y.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GE_OP additive_expression  */
#line 144 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression >= additive_expression (gte op) \n", line_no); }
#line 1614 "y.tab.c"
    break;

  case 34: /* equality_expression: relational_expression  */
#line 149 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> relational_expression\n", line_no); }
#line 1620 "y.tab.c"
    break;

  case 35: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 151 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> equality_expression == relational_expression\n", line_no); }
#line 1626 "y.tab.c"
    break;

  case 36: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 153 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> equality_expression != relational_expression\n", line_no); }
#line 1632 "y.tab.c"
    break;

  case 37: /* logical_AND_expression: equality_expression  */
#line 158 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: logical_AND_expression -> equality_expression\n", line_no); }
#line 1638 "y.tab.c"
    break;

  case 38: /* logical_AND_expression: logical_AND_expression AND_OP equality_expression  */
#line 160 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: logical_AND_expression -> logical_AND_expression && equality_expression\n", line_no); }
#line 1644 "y.tab.c"
    break;

  case 39: /* logical_OR_expression: logical_AND_expression  */
#line 165 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: logical_OR_expression -> logical_AND_expression\n", line_no); }
#line 1650 "y.tab.c"
    break;

  case 40: /* logical_OR_expression: logical_OR_expression OR_OP logical_AND_expression  */
#line 167 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: logical_OR_expression -> logical_OR_expression || logical_AND_expression\n", line_no); }
#line 1656 "y.tab.c"
    break;

  case 41: /* conditional_expression: logical_OR_expression  */
#line 172 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: conditional_expression -> logical_OR_expression\n", line_no); }
#line 1662 "y.tab.c"
    break;

  case 42: /* conditional_expression: logical_OR_expression '?' expression ':' conditional_expression  */
#line 174 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: conditional_expression -> logical_OR_expression ? expression : conditional_expression (ternary op) \n", line_no); }
#line 1668 "y.tab.c"
    break;

  case 43: /* assignment_expression: conditional_expression  */
#line 179 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: assignment_expression -> conditional_expression\n", line_no); }
#line 1674 "y.tab.c"
    break;

  case 44: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 181 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: assignment_expression -> unary_expression = assignment_expression\n", line_no); }
#line 1680 "y.tab.c"
    break;

  case 45: /* expression: assignment_expression  */
#line 186 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: expression -> assignment_expression\n", line_no); }
#line 1686 "y.tab.c"
    break;

  case 46: /* declaration: type_specifier init_declarator ';'  */
#line 191 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: declaration -> type_specifier init_declarator ;\n", line_no);
            strcpy(current_type, "");
        }
#line 1695 "y.tab.c"
    break;

  case 47: /* init_declarator: declarator  */
#line 199 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: init_declarator -> declarator\n", line_no); }
#line 1701 "y.tab.c"
    break;

  case 48: /* init_declarator: declarator '=' initializer  */
#line 201 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: init_declarator -> declarator = initializer\n", line_no); }
#line 1707 "y.tab.c"
    break;

  case 49: /* type_specifier: VOID  */
#line 206 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> void\n", line_no);
            strcpy(current_type, "void");
            (yyval.str_val) = strdup("void");
        }
#line 1717 "y.tab.c"
    break;

  case 50: /* type_specifier: CHAR  */
#line 212 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> char\n", line_no);
            strcpy(current_type, "char");
            (yyval.str_val) = strdup("char");
        }
#line 1727 "y.tab.c"
    break;

  case 51: /* type_specifier: INTEGER  */
#line 218 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> integer\n", line_no);
            strcpy(current_type, "integer");
            (yyval.str_val) = strdup("integer");
        }
#line 1737 "y.tab.c"
    break;

  case 52: /* declarator: pointer direct_declarator  */
#line 227 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: declarator -> pointer direct_declarator\n", line_no);
            // Add pointer prefix to current_type
            char temp[30];
            strcpy(temp, "pointer to ");
            strcat(temp, current_type);
            strcpy(current_type, temp);
        }
#line 1750 "y.tab.c"
    break;

  case 53: /* declarator: direct_declarator  */
#line 236 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: declarator -> direct_declarator\n", line_no); }
#line 1756 "y.tab.c"
    break;

  case 54: /* direct_declarator: IDENTIFIER  */
#line 241 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER (%s)\n", line_no, (yyvsp[0].str_val));
            add_symbol((yyvsp[0].str_val), current_type, current_scope, line_no);
        }
#line 1765 "y.tab.c"
    break;

  case 55: /* direct_declarator: IDENTIFIER '[' INTEGER_CONSTANT ']'  */
#line 246 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER [ INTEGER_CONSTANT ]\n", line_no);
            char array_type[50];
            sprintf(array_type, "array[%d] of %s", (yyvsp[-1].int_val), current_type);
            add_symbol((yyvsp[-3].str_val), array_type, current_scope, line_no);
        }
#line 1776 "y.tab.c"
    break;

  case 56: /* direct_declarator: IDENTIFIER '(' parameter_list ')'  */
#line 253 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER ( parameter_list )\n", line_no);
            char func_type[50];
            sprintf(func_type, "function returning %s", current_type);
            add_symbol((yyvsp[-3].str_val), func_type, current_scope, line_no);
        }
#line 1787 "y.tab.c"
    break;

  case 57: /* direct_declarator: IDENTIFIER '(' ')'  */
#line 260 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER ( )\n", line_no);
            char func_type[50];
            sprintf(func_type, "function returning %s", current_type);
            add_symbol((yyvsp[-2].str_val), func_type, current_scope, line_no);
        }
#line 1798 "y.tab.c"
    break;

  case 58: /* pointer: '*'  */
#line 270 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: pointer -> *\n", line_no); }
#line 1804 "y.tab.c"
    break;

  case 59: /* parameter_list: parameter_declaration  */
#line 275 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: parameter_list -> parameter_declaration\n", line_no); }
#line 1810 "y.tab.c"
    break;

  case 60: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 277 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: parameter_list -> parameter_list , parameter_declaration\n", line_no); }
#line 1816 "y.tab.c"
    break;

  case 61: /* parameter_declaration: type_specifier pointer IDENTIFIER  */
#line 282 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier pointer IDENTIFIER (%s)\n", line_no, (yyvsp[0].str_val));
            char param_type[50];
            sprintf(param_type, "pointer to %s", (yyvsp[-2].str_val));
            add_symbol((yyvsp[0].str_val), param_type, current_scope + 1, line_no);
        }
#line 1827 "y.tab.c"
    break;

  case 62: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 289 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier IDENTIFIER (%s)\n", line_no, (yyvsp[0].str_val));
            add_symbol((yyvsp[0].str_val), (yyvsp[-1].str_val), current_scope + 1, line_no);
        }
#line 1836 "y.tab.c"
    break;

  case 63: /* parameter_declaration: type_specifier pointer  */
#line 294 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier pointer\n", line_no); }
#line 1842 "y.tab.c"
    break;

  case 64: /* parameter_declaration: type_specifier  */
#line 296 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier\n", line_no); }
#line 1848 "y.tab.c"
    break;

  case 65: /* initializer: assignment_expression  */
#line 301 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: initializer -> assignment_expression\n", line_no); }
#line 1854 "y.tab.c"
    break;

  case 66: /* statement: compound_statement  */
#line 306 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: statement -> compound_statement\n", line_no); }
#line 1860 "y.tab.c"
    break;

  case 67: /* statement: expression_statement  */
#line 308 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: statement -> expression_statement\n", line_no); }
#line 1866 "y.tab.c"
    break;

  case 68: /* statement: selection_statement  */
#line 310 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: statement -> selection_statement\n", line_no); }
#line 1872 "y.tab.c"
    break;

  case 69: /* statement: iteration_statement  */
#line 312 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: statement -> iteration_statement\n", line_no); }
#line 1878 "y.tab.c"
    break;

  case 70: /* statement: jump_statement  */
#line 314 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: statement -> jump_statement\n", line_no); }
#line 1884 "y.tab.c"
    break;

  case 71: /* $@1: %empty  */
#line 318 "a7_220101122.y"
                  { enter_scope(); }
#line 1890 "y.tab.c"
    break;

  case 72: /* compound_statement: BEGIN_BLOCK $@1 block_item_list_opt END_BLOCK  */
#line 319 "a7_220101122.y"
        { 
            fprintf(reduction_file, "Line %d: Reduce: compound_statement -> begin block_item_list end\n", line_no);
            exit_scope();
        }
#line 1899 "y.tab.c"
    break;

  case 73: /* block_item_list_opt: block_item_list  */
#line 327 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list_opt -> block_item_list\n", line_no); }
#line 1905 "y.tab.c"
    break;

  case 74: /* block_item_list_opt: %empty  */
#line 329 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list_opt -> empty\n", line_no); }
#line 1911 "y.tab.c"
    break;

  case 75: /* block_item_list: block_item  */
#line 334 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list -> block_item\n", line_no); }
#line 1917 "y.tab.c"
    break;

  case 76: /* block_item_list: block_item_list block_item  */
#line 336 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list -> block_item_list block_item\n", line_no); }
#line 1923 "y.tab.c"
    break;

  case 77: /* block_item: declaration  */
#line 341 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item -> declaration\n", line_no); }
#line 1929 "y.tab.c"
    break;

  case 78: /* block_item: statement  */
#line 343 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: block_item -> statement\n", line_no); }
#line 1935 "y.tab.c"
    break;

  case 79: /* expression_statement: expression_opt ';'  */
#line 348 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: expression_statement -> expression_opt ;\n", line_no); }
#line 1941 "y.tab.c"
    break;

  case 80: /* selection_statement: IF '(' expression ')' statement  */
#line 353 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: selection_statement -> if ( expression ) statement\n", line_no); }
#line 1947 "y.tab.c"
    break;

  case 81: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 355 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: selection_statement -> if ( expression ) statement else statement\n", line_no); }
#line 1953 "y.tab.c"
    break;

  case 82: /* iteration_statement: FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement  */
#line 360 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n", line_no); }
#line 1959 "y.tab.c"
    break;

  case 83: /* expression_opt: expression  */
#line 365 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: expression_opt -> expression\n", line_no); }
#line 1965 "y.tab.c"
    break;

  case 84: /* expression_opt: %empty  */
#line 367 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: expression_opt -> empty\n", line_no); }
#line 1971 "y.tab.c"
    break;

  case 85: /* jump_statement: RETURN expression_opt ';'  */
#line 372 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: jump_statement -> return expression_opt ;\n", line_no); }
#line 1977 "y.tab.c"
    break;

  case 86: /* translation_unit: function_definition  */
#line 377 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> function_definition\n", line_no); }
#line 1983 "y.tab.c"
    break;

  case 87: /* translation_unit: declaration  */
#line 379 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> declaration\n", line_no); }
#line 1989 "y.tab.c"
    break;

  case 88: /* translation_unit: function_definition translation_unit  */
#line 381 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> translation_unit function_definition\n", line_no); }
#line 1995 "y.tab.c"
    break;

  case 89: /* translation_unit: declaration translation_unit  */
#line 383 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> translation_unit declaration\n", line_no); }
#line 2001 "y.tab.c"
    break;

  case 90: /* function_definition: type_specifier function_declarator compound_statement  */
#line 388 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: function_definition -> type_specifier function_declarator compound_statement\n", line_no); }
#line 2007 "y.tab.c"
    break;

  case 91: /* function_declarator: IDENTIFIER '(' ')'  */
#line 393 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: function_declarator -> identifier ( )\n", line_no); }
#line 2013 "y.tab.c"
    break;

  case 92: /* function_declarator: IDENTIFIER '(' parameter_list ')'  */
#line 395 "a7_220101122.y"
        { fprintf(reduction_file, "Line %d: Reduce: function_declarator -> identifier ( parameter_list )\n", line_no); }
#line 2019 "y.tab.c"
    break;


#line 2023 "y.tab.c"

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

#line 398 "a7_220101122.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, line_no);
}

void add_symbol(char *name, char *type, int scope, int line) {
    struct symbol *new_symbol = (struct symbol*)malloc(sizeof(struct symbol));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->scope = scope;
    new_symbol->line_no = line;
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
    
    // Write to symbol table file
    fprintf(symbol_table_file, "%-20s %-30s %-10d %-10d\n", name, type, scope, line);
}

void print_symbol_table() {
    struct symbol *current = symbol_table;
    while(current != NULL) {
        fprintf(symbol_table_file, "%-20s %-30s %-10d %-10d\n", 
                current->name, current->type, current->scope, current->line_no);
        current = current->next;
    }
}

void enter_scope() {
    current_scope++;
}

void exit_scope() {
    current_scope--;
}

int main() {
    // Open the files for reductions and symbol table
    reduction_file = fopen("reductions_output.txt", "w");
    if (!reduction_file) {
        fprintf(stderr, "Error opening reductions output file\n");
        return 1;
    }
    
    symbol_table_file = fopen("symbol_table_output.txt", "w");
    if (!symbol_table_file) {
        fprintf(stderr, "Error opening symbol table output file\n");
        fclose(reduction_file);
        return 1;
    }
    
    // Write headers for the symbol table file
    fprintf(symbol_table_file, "%-20s %-30s %-10s %-10s\n", "Name", "Type", "Scope", "Line");
    fprintf(symbol_table_file, "--------------------------------------------------------------------------\n");
    
    // Parse the input
    yyparse();
    
    // Close the files
    fclose(reduction_file);
    fclose(symbol_table_file);
    
    printf("Parsing completed successfully. Check reductions_output.txt and symbol_table_output.txt for results.\n");
    
    return 0;
}
