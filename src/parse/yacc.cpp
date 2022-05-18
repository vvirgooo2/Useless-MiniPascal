/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "temp.y"

    #include <stdio.h>
    #include <string.h>
    #include "../ast/AST_node.h"
    #include "main.h"
    extern int yylex();
    extern FILE* yyin;
    void yyerror(const char* s);

#line 80 "yacc.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_HPP_INCLUDED
# define YY_YY_YACC_HPP_INCLUDED
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
    TYPE_INT = 258,
    TYPE_INT_8 = 259,
    TYPE_INT_16 = 260,
    TYPE = 261,
    TYPE_INT_32 = 262,
    TYPE_INT_64 = 263,
    TYPE_BYTE = 264,
    TYPE_WORD = 265,
    TYPE_FLOAT_8 = 266,
    TYPE_FLOAT_16 = 267,
    TYPE_FLOAT_32 = 268,
    TYPE_BOOL = 269,
    TYPE_CHAR = 270,
    TYPE_STRING = 271,
    NOT = 272,
    ADD = 273,
    SUB = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    IDIV = 278,
    EQ = 279,
    GRE = 280,
    LES = 281,
    GREQ = 282,
    LESQ = 283,
    NE = 284,
    OR = 285,
    AND = 286,
    ASSIGN = 287,
    ARANGE = 288,
    LBR = 289,
    RBR = 290,
    LPR = 291,
    RPR = 292,
    DOT = 293,
    COM = 294,
    COL = 295,
    SEMI = 296,
    CARET = 297,
    ARRAY = 298,
    BEGN = 299,
    BREAK = 300,
    CASE = 301,
    CONST = 302,
    TO = 303,
    DO = 304,
    ELSE = 305,
    END = 306,
    FOR = 307,
    FUNC = 308,
    IF = 309,
    OF = 310,
    PROC = 311,
    PROG = 312,
    REPEAT = 313,
    THEN = 314,
    UNTIL = 315,
    VAR = 316,
    WHILE = 317,
    INT = 318,
    FLOAT = 319,
    CHAR = 320,
    STRING = 321,
    ID = 322
  };
#endif
/* Tokens.  */
#define TYPE_INT 258
#define TYPE_INT_8 259
#define TYPE_INT_16 260
#define TYPE 261
#define TYPE_INT_32 262
#define TYPE_INT_64 263
#define TYPE_BYTE 264
#define TYPE_WORD 265
#define TYPE_FLOAT_8 266
#define TYPE_FLOAT_16 267
#define TYPE_FLOAT_32 268
#define TYPE_BOOL 269
#define TYPE_CHAR 270
#define TYPE_STRING 271
#define NOT 272
#define ADD 273
#define SUB 274
#define MUL 275
#define DIV 276
#define MOD 277
#define IDIV 278
#define EQ 279
#define GRE 280
#define LES 281
#define GREQ 282
#define LESQ 283
#define NE 284
#define OR 285
#define AND 286
#define ASSIGN 287
#define ARANGE 288
#define LBR 289
#define RBR 290
#define LPR 291
#define RPR 292
#define DOT 293
#define COM 294
#define COL 295
#define SEMI 296
#define CARET 297
#define ARRAY 298
#define BEGN 299
#define BREAK 300
#define CASE 301
#define CONST 302
#define TO 303
#define DO 304
#define ELSE 305
#define END 306
#define FOR 307
#define FUNC 308
#define IF 309
#define OF 310
#define PROC 311
#define PROG 312
#define REPEAT 313
#define THEN 314
#define UNTIL 315
#define VAR 316
#define WHILE 317
#define INT 318
#define FLOAT 319
#define CHAR 320
#define STRING 321
#define ID 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "temp.y"

    int type_int;
    float type_float;
    char type_char;
    char* type_string;
    char* id;
    ExprList* expr_list;
    Expr* expr_node;
    IDExpr* id_expr;
    Program* program_node;
    DeclPart* decl_part;
    FuncDeclList* func_list;
    OneFuncDecl* func_node;
    FuncHead* func_head;
    FuncBody* func_body;
    ExecPart* exec_part;
    Stmt* stmt_node;
    StmtList* stmt_list;
    AssignStmt* assign_node;
    ForStmt* for_node;
    FuncCallStmt* call_node;
    RepeatStmt* repeat_node;
    WhileStmt* while_node;
    IfStmt* if_node;
    ElseStmt* else_node;
    BreakStmt* break_node;
    VarDeclList* var_list;
    VarDecl* var_node;
    MyType* type_node;
    SimpleType* simple_type;
    IDList* id_list;
    ArrayType* array_type;
    ParaList* para_node;
    ProgHead* prog_head;
    BinExpr* bin_expr;
    UnaryExpr* un_expr;
    FunCallExpr* funcall_expr;
    ArrayExpr* array_expr;

#line 306 "yacc.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

#define YYUNDEFTOK  2
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    97,   101,   107,   111,   115,   119,   123,
     127,   130,   137,   139,   141,   143,   145,   150,   153,   159,
     163,   167,   172,   178,   181,   186,   192,   198,   202,   207,
     209,   211,   213,   215,   217,   219,   224,   227,   232,   235,
     240,   242,   244,   246,   248,   253,   255,   257,   259,   261,
     263,   265,   270,   272,   274,   276,   281,   283,   285,   287,
     289,   291,   296,   298,   300,   302,   304,   306,   311,   317,
     320,   327,   330,   337,   339,   346,   349,   353,   358,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_INT", "TYPE_INT_8", "TYPE_INT_16",
  "TYPE", "TYPE_INT_32", "TYPE_INT_64", "TYPE_BYTE", "TYPE_WORD",
  "TYPE_FLOAT_8", "TYPE_FLOAT_16", "TYPE_FLOAT_32", "TYPE_BOOL",
  "TYPE_CHAR", "TYPE_STRING", "NOT", "ADD", "SUB", "MUL", "DIV", "MOD",
  "IDIV", "EQ", "GRE", "LES", "GREQ", "LESQ", "NE", "OR", "AND", "ASSIGN",
  "ARANGE", "LBR", "RBR", "LPR", "RPR", "DOT", "COM", "COL", "SEMI",
  "CARET", "ARRAY", "BEGN", "BREAK", "CASE", "CONST", "TO", "DO", "ELSE",
  "END", "FOR", "FUNC", "IF", "OF", "PROC", "PROG", "REPEAT", "THEN",
  "UNTIL", "VAR", "WHILE", "INT", "FLOAT", "CHAR", "STRING", "ID",
  "$accept", "program", "program_node", "prog_head", "decl_part",
  "var_list", "var_node", "simple_type", "id_list", "func_list",
  "func_node", "func_head", "para_node", "func_body", "exec_part",
  "stmt_list", "stmt_node", "assign_node", "expr_list", "id_expr",
  "expr_node", "first_bin_expr", "second_bin_expr", "third_bin_expr",
  "array_expr", "for_node", "while_node", "if_node", "else_node",
  "break_node", "call_node", "repeat_node", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,     4,  -100,   -60,  -100,   -50,   -24,  -100,   -29,  -100,
     -15,    91,    26,  -100,    28,    27,    29,    42,    17,    49,
      91,    14,   -18,    80,  -100,  -100,    73,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    41,    43,    44,  -100,    68,
    -100,    81,    14,   -32,    14,    14,    14,  -100,  -100,  -100,
    -100,   -26,  -100,    63,    19,   201,  -100,  -100,    14,    14,
      14,  -100,  -100,    14,  -100,  -100,  -100,  -100,  -100,  -100,
      85,  -100,    86,  -100,    14,   165,    14,  -100,  -100,   179,
      14,    14,    14,    14,    14,    14,    14,    62,    14,    14,
      14,    14,    14,    14,    14,    14,   135,   185,    -3,   202,
     141,    58,   -15,   -38,    87,    75,    74,   159,  -100,     8,
      19,    19,    19,    19,    19,    19,   103,  -100,   201,   201,
     201,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   105,    14,
    -100,   115,  -100,    23,  -100,  -100,    14,    62,  -100,  -100,
    -100,  -100,   202,    88,   110,   -15,    69,   111,   104,   120,
     124,  -100,    62,   104,   -29,  -100,   101,  -100,   116,  -100,
    -100,   130,   124,  -100,  -100,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,     2,     7,     0,     9,     0,     5,
      20,     0,     0,    18,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,    28,    29,     0,    30,    34,    35,
      33,    31,    32,     4,     8,     0,     0,     0,    19,     0,
      77,     0,     0,     0,     0,     0,     0,    41,    43,    42,
      44,    40,    67,     0,    51,    55,    61,    65,     0,     0,
       0,    26,    27,     0,    17,    12,    13,    14,    15,    16,
       0,    10,     0,     9,     0,     0,     0,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      47,    45,    46,    48,    49,    50,     0,    72,    52,    53,
      54,    56,    57,    60,    58,    59,    36,    68,     0,     0,
      37,     0,    24,     0,    25,    21,     0,     0,    79,    64,
      71,    78,    38,     0,     0,     0,     0,     0,    76,     0,
       0,    23,     0,    76,     0,    74,     0,    22,     0,    70,
      73,     0,     0,    69,    75,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,    99,   -97,   -99,  -100,  -100,
    -100,  -100,  -100,  -100,   -84,   153,   -22,  -100,    94,  -100,
     -19,   152,   -47,   -20,   -11,  -100,  -100,  -100,    22,  -100,
    -100,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,     8,    10,    14,    71,    15,    16,
      38,    39,   133,   104,    12,    23,    24,    25,    98,    52,
      99,    54,    55,    56,    57,    27,    28,    29,   155,    30,
      31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    62,    53,   116,     2,   132,    11,     6,    59,    26,
      80,     7,    26,    17,    58,    11,    59,     9,    60,   134,
      18,    62,    19,    75,    77,    78,    20,    79,    76,    13,
      21,    44,    26,    45,   128,    22,   129,    88,    89,    96,
      97,   118,   119,   120,   100,   139,    65,   129,   151,    90,
      46,   157,    13,   147,    66,   105,    67,   107,    68,    69,
     144,     3,   145,   165,    33,   117,    35,    36,   158,    34,
     161,   121,   122,   123,   124,   125,    26,    47,    48,    49,
      50,    51,    37,    40,    41,    42,    70,    81,    82,    83,
      84,    85,    86,    81,    82,    83,    84,    85,    86,    81,
      82,    83,    84,    85,    86,    63,    11,    17,    64,    73,
     142,    72,    87,    74,    18,   148,    19,   146,   152,   101,
      20,   131,   102,   136,    21,    17,    26,    65,   135,    22,
     159,    61,    18,   137,    19,    66,    17,    67,    20,    68,
      69,    26,    21,    18,   140,    19,   141,    22,   143,    20,
     150,   149,   153,    21,   154,   156,   162,   163,    22,    81,
      82,    83,    84,    85,    86,    81,    82,    83,    84,    85,
      86,   164,   103,    43,   109,   160,   126,     0,     0,     0,
       0,     0,   130,    81,    82,    83,    84,    85,    86,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
     138,     0,   106,    81,    82,    83,    84,    85,    86,    81,
      82,    83,    84,    85,    86,     0,   108,     0,     0,     0,
     127,    91,    92,    93,    94,     0,    81,    82,    83,    84,
      85,    86,    95,   110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      11,    23,    21,    87,     0,   102,    44,    67,    34,    20,
      36,    61,    23,    45,    32,    44,    34,    41,    36,   103,
      52,    43,    54,    42,    44,    45,    58,    46,    60,    67,
      62,    17,    43,    19,    37,    67,    39,    18,    19,    58,
      59,    88,    89,    90,    63,    37,     3,    39,   145,    30,
      36,   150,    67,   137,    11,    74,    13,    76,    15,    16,
      37,    57,    39,   162,    38,    87,    39,    40,   152,    41,
     154,    91,    92,    93,    94,    95,    87,    63,    64,    65,
      66,    67,    53,    41,    67,    36,    43,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29,    24,
      25,    26,    27,    28,    29,    32,    44,    45,    67,    41,
     129,    67,    49,    32,    52,   137,    54,   136,    49,    34,
      58,    63,    36,    48,    62,    45,   137,     3,    41,    67,
     152,    51,    52,    59,    54,    11,    45,    13,    58,    15,
      16,   152,    62,    52,    41,    54,    41,    67,    33,    58,
      40,    63,    41,    62,    50,    35,    55,    41,    67,    24,
      25,    26,    27,    28,    29,    24,    25,    26,    27,    28,
      29,    41,    73,    20,    80,   153,    41,    -1,    -1,    -1,
      -1,    -1,    41,    24,    25,    26,    27,    28,    29,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    37,    24,    25,    26,    27,    28,    29,    24,
      25,    26,    27,    28,    29,    -1,    37,    -1,    -1,    -1,
      35,    20,    21,    22,    23,    -1,    24,    25,    26,    27,
      28,    29,    31,    81,    82,    83,    84,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,     0,    57,    70,    71,    67,    61,    72,    41,
      73,    44,    82,    67,    74,    76,    77,    45,    52,    54,
      58,    62,    67,    83,    84,    85,    92,    93,    94,    95,
      97,    98,    99,    38,    41,    39,    40,    53,    78,    79,
      41,    67,    36,    83,    17,    19,    36,    63,    64,    65,
      66,    67,    87,    88,    89,    90,    91,    92,    32,    34,
      36,    51,    84,    32,    67,     3,    11,    13,    15,    16,
      43,    75,    67,    41,    32,    88,    60,    91,    91,    88,
      36,    24,    25,    26,    27,    28,    29,    49,    18,    19,
      30,    20,    21,    22,    23,    31,    88,    88,    86,    88,
      88,    34,    36,    73,    81,    88,    37,    88,    37,    86,
      89,    89,    89,    89,    89,    89,    82,    84,    90,    90,
      90,    91,    91,    91,    91,    91,    41,    35,    37,    39,
      41,    63,    74,    80,    82,    41,    48,    59,    41,    37,
      41,    41,    88,    33,    37,    39,    88,    82,    84,    63,
      40,    74,    49,    41,    50,    96,    35,    75,    82,    84,
      96,    82,    55,    41,    41,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    80,    80,    81,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    98,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     4,     3,     3,     0,     3,     0,
       3,    10,     1,     1,     1,     1,     1,     3,     1,     2,
       0,     4,     7,     3,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     2,     2,     4,     1,     3,     1,     4,     9,
       8,     5,     4,     8,     7,     3,     0,     2,     5,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 4:
#line 101 "temp.y"
                                      { 
        ast_root = new Program((yyvsp[-3].prog_head), (yyvsp[-2].decl_part), (yyvsp[-1].exec_part)); 
    }
#line 1618 "yacc.cpp"
    break;

  case 5:
#line 107 "temp.y"
                 { (yyval.prog_head) = new ProgHead((yyvsp[-1].type_string)); }
#line 1624 "yacc.cpp"
    break;

  case 6:
#line 111 "temp.y"
                           { 
        (yyval.decl_part) = new DeclPart((yyvsp[-1].var_list), (yyvsp[0].func_list)); 
    }
#line 1632 "yacc.cpp"
    break;

  case 7:
#line 115 "temp.y"
    { (yyval.decl_part) = new DeclPart(); }
#line 1638 "yacc.cpp"
    break;

  case 8:
#line 120 "temp.y"
{ (yyval.var_list) = (yyvsp[-2].var_list);
  (yyval.var_list)->pushVarDecl((yyvsp[-1].var_node)); }
#line 1645 "yacc.cpp"
    break;

  case 9:
#line 123 "temp.y"
{ (yyval.var_list) = new VarDeclList(); }
#line 1651 "yacc.cpp"
    break;

  case 10:
#line 127 "temp.y"
                           {
        (yyval.var_node) = new VarDecl((yyvsp[0].simple_type), (yyvsp[-2].id_list)); 
    }
#line 1659 "yacc.cpp"
    break;

  case 11:
#line 130 "temp.y"
                                                             {
        ArrayType* ary = new ArrayType((yyvsp[-5].type_int), (yyvsp[-3].type_int), (yyvsp[0].simple_type)->getSimpleTypeName()); 
        (yyval.var_node) = new VarDecl(ary, (yyvsp[-9].id_list));
    }
#line 1668 "yacc.cpp"
    break;

  case 12:
#line 138 "temp.y"
{ (yyval.simple_type) = new SimpleType("integer"); }
#line 1674 "yacc.cpp"
    break;

  case 13:
#line 140 "temp.y"
{ (yyval.simple_type) = new SimpleType("real"); }
#line 1680 "yacc.cpp"
    break;

  case 14:
#line 142 "temp.y"
{ (yyval.simple_type) = new SimpleType("double"); }
#line 1686 "yacc.cpp"
    break;

  case 15:
#line 144 "temp.y"
{ (yyval.simple_type) = new SimpleType("char"); }
#line 1692 "yacc.cpp"
    break;

  case 16:
#line 146 "temp.y"
{ (yyval.simple_type) = new SimpleType("string"); }
#line 1698 "yacc.cpp"
    break;

  case 17:
#line 151 "temp.y"
{ (yyval.id_list) = (yyvsp[-2].id_list);
  (yyval.id_list)->pushID((string)(yyvsp[0].type_string)); }
#line 1705 "yacc.cpp"
    break;

  case 18:
#line 154 "temp.y"
{ (yyval.id_list) = new IDList(); 
  (yyval.id_list)->pushID((string)(yyvsp[0].type_string)); }
#line 1712 "yacc.cpp"
    break;

  case 19:
#line 160 "temp.y"
{ (yyval.func_list) = (yyvsp[-1].func_list);
  (yyval.func_list)->pushOneFuncDecl((yyvsp[0].func_node)); }
#line 1719 "yacc.cpp"
    break;

  case 20:
#line 163 "temp.y"
{ (yyval.func_list) = new FuncDeclList(); }
#line 1725 "yacc.cpp"
    break;

  case 21:
#line 168 "temp.y"
{ (yyval.func_node) = new OneFuncDecl((yyvsp[-3].func_head), (yyvsp[-1].func_body)); }
#line 1731 "yacc.cpp"
    break;

  case 22:
#line 172 "temp.y"
                                              { 
        (yyval.func_head) = new FuncHead((string)(yyvsp[-5].type_string), (yyvsp[0].simple_type), (yyvsp[-3].para_node)); 
    }
#line 1739 "yacc.cpp"
    break;

  case 23:
#line 179 "temp.y"
{ (yyval.para_node) = (yyvsp[-2].para_node);
  (yyval.para_node)->pushNewPara((yyvsp[0].var_node)); }
#line 1746 "yacc.cpp"
    break;

  case 24:
#line 182 "temp.y"
{ (yyval.para_node) = new ParaList((yyvsp[0].var_node)); }
#line 1752 "yacc.cpp"
    break;

  case 25:
#line 186 "temp.y"
                       {
        (yyval.func_body) = new FuncBody((yyvsp[-1].var_list), (yyvsp[0].exec_part)); 
    }
#line 1760 "yacc.cpp"
    break;

  case 26:
#line 192 "temp.y"
                       { 
        (yyval.exec_part) = new ExecPart((yyvsp[-1].stmt_list));
    }
#line 1768 "yacc.cpp"
    break;

  case 27:
#line 198 "temp.y"
                        { 
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        (yyval.stmt_list)->pushStmt((yyvsp[0].stmt_node)); 
    }
#line 1777 "yacc.cpp"
    break;

  case 28:
#line 203 "temp.y"
{ (yyval.stmt_list) = new StmtList((yyvsp[0].stmt_node)); }
#line 1783 "yacc.cpp"
    break;

  case 29:
#line 208 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].assign_node); }
#line 1789 "yacc.cpp"
    break;

  case 30:
#line 210 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].for_node); }
#line 1795 "yacc.cpp"
    break;

  case 31:
#line 212 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].call_node); }
#line 1801 "yacc.cpp"
    break;

  case 32:
#line 214 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].repeat_node); }
#line 1807 "yacc.cpp"
    break;

  case 33:
#line 216 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].break_node); }
#line 1813 "yacc.cpp"
    break;

  case 34:
#line 218 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].while_node); }
#line 1819 "yacc.cpp"
    break;

  case 35:
#line 220 "temp.y"
{ (yyval.stmt_node) = (yyvsp[0].if_node); }
#line 1825 "yacc.cpp"
    break;

  case 36:
#line 225 "temp.y"
{ IDExpr* id = new IDExpr("var", (string)(yyvsp[-3].type_string)); 
  (yyval.assign_node) = new AssignStmt(id, (yyvsp[-1].expr_node)); }
#line 1832 "yacc.cpp"
    break;

  case 37:
#line 228 "temp.y"
{ (yyval.assign_node) = new AssignStmt((yyvsp[-3].array_expr), (yyvsp[-1].expr_node)); }
#line 1838 "yacc.cpp"
    break;

  case 38:
#line 233 "temp.y"
{ (yyval.expr_list) = (yyvsp[-2].expr_list);
  (yyval.expr_list)->pushExprNode((yyvsp[0].expr_node)); }
#line 1845 "yacc.cpp"
    break;

  case 39:
#line 236 "temp.y"
{ (yyval.expr_list) = new ExprList((yyvsp[0].expr_node)); }
#line 1851 "yacc.cpp"
    break;

  case 40:
#line 241 "temp.y"
{ (yyval.id_expr) = new IDExpr("var", (string)(yyvsp[0].type_string)); }
#line 1857 "yacc.cpp"
    break;

  case 41:
#line 243 "temp.y"
{ (yyval.id_expr) = new IDExpr("int", (yyvsp[0].type_int)); }
#line 1863 "yacc.cpp"
    break;

  case 42:
#line 245 "temp.y"
{ (yyval.id_expr) = new IDExpr("char", (yyvsp[0].type_char)); }
#line 1869 "yacc.cpp"
    break;

  case 43:
#line 247 "temp.y"
{ (yyval.id_expr) = new IDExpr("float", (yyvsp[0].type_float)); }
#line 1875 "yacc.cpp"
    break;

  case 44:
#line 249 "temp.y"
{ (yyval.id_expr) = new IDExpr("string", (yyvsp[0].type_string)); }
#line 1881 "yacc.cpp"
    break;

  case 45:
#line 254 "temp.y"
{ (yyval.expr_node) = new BinExpr("GRE", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1887 "yacc.cpp"
    break;

  case 46:
#line 256 "temp.y"
{ (yyval.expr_node) = new BinExpr("LES", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1893 "yacc.cpp"
    break;

  case 47:
#line 258 "temp.y"
{ (yyval.expr_node) = new BinExpr("EQ", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1899 "yacc.cpp"
    break;

  case 48:
#line 260 "temp.y"
{ (yyval.expr_node) = new BinExpr("GREQ", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1905 "yacc.cpp"
    break;

  case 49:
#line 262 "temp.y"
{ (yyval.expr_node) = new BinExpr("LESQ", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1911 "yacc.cpp"
    break;

  case 50:
#line 264 "temp.y"
{ (yyval.expr_node) = new BinExpr("NE", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1917 "yacc.cpp"
    break;

  case 51:
#line 266 "temp.y"
{ (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1923 "yacc.cpp"
    break;

  case 52:
#line 271 "temp.y"
{ (yyval.expr_node) = new BinExpr("add", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1929 "yacc.cpp"
    break;

  case 53:
#line 273 "temp.y"
{ (yyval.expr_node) = new BinExpr("sub", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1935 "yacc.cpp"
    break;

  case 54:
#line 275 "temp.y"
{ (yyval.expr_node) = new BinExpr("or", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1941 "yacc.cpp"
    break;

  case 55:
#line 277 "temp.y"
{ (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1947 "yacc.cpp"
    break;

  case 56:
#line 282 "temp.y"
{ (yyval.expr_node) = new BinExpr("mul", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1953 "yacc.cpp"
    break;

  case 57:
#line 284 "temp.y"
{ (yyval.expr_node) = new BinExpr("div", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1959 "yacc.cpp"
    break;

  case 58:
#line 286 "temp.y"
{ (yyval.expr_node) = new BinExpr("idiv", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1965 "yacc.cpp"
    break;

  case 59:
#line 288 "temp.y"
{ (yyval.expr_node) = new BinExpr("and", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1971 "yacc.cpp"
    break;

  case 60:
#line 290 "temp.y"
{ (yyval.expr_node) = new BinExpr("mod", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); }
#line 1977 "yacc.cpp"
    break;

  case 61:
#line 292 "temp.y"
{ (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1983 "yacc.cpp"
    break;

  case 62:
#line 297 "temp.y"
{ (yyval.expr_node) = new UnaryExpr("not", (yyvsp[0].expr_node)); }
#line 1989 "yacc.cpp"
    break;

  case 63:
#line 299 "temp.y"
{ (yyval.expr_node) = new UnaryExpr("sub", (yyvsp[0].expr_node)); }
#line 1995 "yacc.cpp"
    break;

  case 64:
#line 301 "temp.y"
{ (yyval.expr_node) = new FunCallExpr((string)(yyvsp[-3].type_string), (yyvsp[-1].expr_list)); }
#line 2001 "yacc.cpp"
    break;

  case 65:
#line 303 "temp.y"
{ (yyval.expr_node) = (yyvsp[0].array_expr); }
#line 2007 "yacc.cpp"
    break;

  case 66:
#line 305 "temp.y"
{ (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 2013 "yacc.cpp"
    break;

  case 67:
#line 307 "temp.y"
{ (yyval.expr_node) = (yyvsp[0].id_expr); }
#line 2019 "yacc.cpp"
    break;

  case 68:
#line 311 "temp.y"
                         {
        (yyval.array_expr) = new ArrayExpr((string)(yyvsp[-3].type_string), (yyvsp[-1].expr_node));
    }
#line 2027 "yacc.cpp"
    break;

  case 69:
#line 317 "temp.y"
                                                           {
        (yyval.for_node) = new ForStmt((string)(yyvsp[-7].type_string), (yyvsp[-5].expr_node), (yyvsp[-3].expr_node), (yyvsp[-1].exec_part)->sl); 
    }
#line 2035 "yacc.cpp"
    break;

  case 70:
#line 320 "temp.y"
                                                        {
        StmtList* sl = new StmtList((yyvsp[0].stmt_node));
        (yyval.for_node) = new ForStmt((string)(yyvsp[-6].type_string), (yyvsp[-4].expr_node), (yyvsp[-2].expr_node), sl);
    }
#line 2044 "yacc.cpp"
    break;

  case 71:
#line 327 "temp.y"
                                     {
        (yyval.while_node) = new WhileStmt((yyvsp[-3].expr_node), (yyvsp[-1].exec_part)->sl); 
    }
#line 2052 "yacc.cpp"
    break;

  case 72:
#line 330 "temp.y"
                                   {
        StmtList* sl = new StmtList((yyvsp[0].stmt_node));
        (yyval.while_node) = new WhileStmt((yyvsp[-2].expr_node), sl);
    }
#line 2061 "yacc.cpp"
    break;

  case 73:
#line 338 "temp.y"
{ (yyval.if_node) = new IfStmt((yyvsp[-5].expr_node), (yyvsp[-2].exec_part)->sl, (yyvsp[0].else_node)); }
#line 2067 "yacc.cpp"
    break;

  case 74:
#line 340 "temp.y"
{ StmtList* sl = new StmtList();
  sl->pushStmt((yyvsp[-1].stmt_node));
  (yyval.if_node) = new IfStmt((yyvsp[-4].expr_node), sl, (yyvsp[0].else_node)); }
#line 2075 "yacc.cpp"
    break;

  case 75:
#line 347 "temp.y"
{ (yyval.else_node) = new ElseStmt((yyvsp[-1].exec_part)->sl); }
#line 2081 "yacc.cpp"
    break;

  case 76:
#line 349 "temp.y"
{ (yyval.else_node) = new ElseStmt(); }
#line 2087 "yacc.cpp"
    break;

  case 77:
#line 354 "temp.y"
{ (yyval.break_node) = new BreakStmt(); }
#line 2093 "yacc.cpp"
    break;

  case 78:
#line 359 "temp.y"
{ (yyval.call_node) = new FuncCallStmt((string)(yyvsp[-4].type_string), (yyvsp[-2].expr_list)); }
#line 2099 "yacc.cpp"
    break;

  case 79:
#line 363 "temp.y"
                                         { 
        (yyval.repeat_node) = new RepeatStmt((yyvsp[-1].expr_node), (yyvsp[-3].stmt_list)); 
    }
#line 2107 "yacc.cpp"
    break;


#line 2111 "yacc.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 368 "temp.y"

void yyerror (char const *s) {
   printf ("%s\n", s);
   
 }
