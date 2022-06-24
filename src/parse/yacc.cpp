/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "./parse/grammar.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <string.h>
    #include "../ast/AST_node.h"
    #include "../main.h"
    extern int yylex();
    extern FILE* yyin;
    void yyerror(const char* s);
    #define setl(node) ((node)->set_last_line(yylloc.first_line))

#line 77 "./parse/yacc.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.hpp".  */
#ifndef YY_YY_PARSE_YACC_HPP_INCLUDED
# define YY_YY_PARSE_YACC_HPP_INCLUDED
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
#line 14 "./parse/grammar.y" /* yacc.c:355  */

    int location;
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

#line 292 "./parse/yacc.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_YACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 323 "./parse/yacc.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   100,   104,   111,   115,   119,   125,   129,
     133,   137,   144,   146,   148,   150,   152,   157,   160,   166,
     170,   174,   179,   185,   188,   193,   199,   205,   209,   214,
     216,   218,   220,   222,   224,   226,   231,   234,   239,   242,
     247,   249,   251,   253,   255,   261,   263,   265,   267,   269,
     271,   273,   278,   280,   282,   284,   289,   291,   293,   295,
     297,   299,   304,   306,   308,   310,   312,   314,   319,   325,
     328,   335,   338,   345,   347,   354,   357,   361,   366,   371
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
static const yytype_uint16 yytoknum[] =
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

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -134,     5,  -134,   -53,  -134,   -43,   -19,  -134,   -15,   -21,
    -134,   -34,   104,     4,   -31,  -134,     8,  -134,    11,   -14,
     -21,    12,    -6,    36,   104,    18,     9,    92,  -134,  -134,
      48,  -134,  -134,  -134,  -134,  -134,  -134,  -134,    40,   -43,
    -134,    23,    35,  -134,    81,    18,   103,    18,    18,    18,
    -134,  -134,  -134,  -134,    41,  -134,   -18,    -2,   191,  -134,
    -134,    18,    18,    18,  -134,  -134,    18,   -34,   -15,    69,
    -134,  -134,  -134,  -134,  -134,  -134,    80,  -134,    18,   172,
      18,  -134,  -134,   178,    18,    18,    18,    18,    18,    18,
      18,    78,    18,    18,    18,    18,    18,    18,    18,    18,
      79,   192,    49,   204,   148,  -134,    72,  -134,  -134,    55,
      73,    60,   154,  -134,    87,    -2,    -2,    -2,    -2,    -2,
      -2,    84,  -134,   191,   191,   191,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,    86,    18,  -134,    91,   -34,   100,    18,
      78,  -134,  -134,  -134,  -134,   204,    44,  -134,    71,    67,
      94,    88,  -134,   106,    78,    88,   -15,  -134,    96,    98,
    -134,  -134,   111,    44,  -134,  -134,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     2,    20,     0,     9,     0,     7,
       5,    20,     0,     0,     0,    19,     0,    18,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    34,    35,    33,    31,    32,     4,     0,    20,
       8,     0,     0,    77,     0,     0,     0,     0,     0,     0,
      41,    43,    42,    44,    40,    67,     0,    51,    55,    61,
      65,     0,     0,     0,    26,    27,     0,     0,     0,     0,
      17,    12,    13,    14,    15,    16,     0,    10,     0,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    24,     0,    25,    21,     0,
       0,     0,     0,    66,     0,    47,    45,    46,    48,    49,
      50,     0,    72,    52,    53,    54,    56,    57,    60,    58,
      59,    36,    68,     0,     0,    37,     0,     0,     0,     0,
       0,    79,    64,    71,    78,    38,     0,    23,     0,     0,
       0,    76,    22,     0,     0,    76,     0,    74,     0,     0,
      70,    73,     0,     0,    69,    75,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,   108,  -134,   -63,  -133,  -134,   142,
    -134,  -134,  -134,  -134,   -67,   136,   -25,  -134,    83,  -134,
     -22,   149,   -29,   -28,   -12,  -134,  -134,  -134,    13,  -134,
    -134,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,     8,    11,    18,    77,    19,     9,
      15,    16,   106,    69,    13,    27,    28,    29,   102,    55,
     103,    57,    58,    59,    60,    31,    32,    33,   157,    34,
      35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,   107,    65,    56,   105,     2,    85,    86,    87,    88,
      89,    90,    30,   152,     6,    30,    92,    93,     7,    81,
      82,    65,    10,    79,   121,    41,    42,    83,    94,    12,
     166,    91,    14,    17,    30,    47,    38,    48,    71,   100,
     101,    61,    37,    62,   104,    63,    72,    71,    73,    39,
      74,    75,    40,    43,    49,    72,   110,    73,   112,    74,
      75,    44,     3,   123,   124,   125,   122,   126,   127,   128,
     129,   130,    45,   150,   147,    62,    67,    84,    76,    30,
      66,    50,    51,    52,    53,    54,   133,   159,   134,   162,
      70,    85,    86,    87,    88,    89,    90,    85,    86,    87,
      88,    89,    90,    85,    86,    87,    88,    89,    90,   136,
     108,   137,   145,    78,   109,   151,   154,   149,   138,   140,
     131,   139,    12,    21,   142,   143,   134,   144,    30,   160,
      22,   146,    23,   148,   153,   155,    24,    21,   156,   164,
      25,   158,    30,    64,    22,    26,    23,    68,    21,    21,
      24,   163,   165,    20,    25,    22,    22,    23,    23,    26,
      46,    24,    24,    80,     0,    25,    25,   114,   161,     0,
      26,    26,    85,    86,    87,    88,    89,    90,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,   141,    85,    86,    87,    88,
      89,    90,    85,    86,    87,    88,    89,    90,     0,   111,
       0,    95,    96,    97,    98,   113,    85,    86,    87,    88,
      89,    90,    99,     0,     0,     0,     0,   132,    85,    86,
      87,    88,    89,    90,   115,   116,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      12,    68,    27,    25,    67,     0,    24,    25,    26,    27,
      28,    29,    24,   146,    67,    27,    18,    19,    61,    47,
      48,    46,    41,    45,    91,    39,    40,    49,    30,    44,
     163,    49,    53,    67,    46,    17,    67,    19,     3,    61,
      62,    32,    38,    34,    66,    36,    11,     3,    13,    41,
      15,    16,    41,    41,    36,    11,    78,    13,    80,    15,
      16,    67,    57,    92,    93,    94,    91,    95,    96,    97,
      98,    99,    36,   140,   137,    34,    36,    36,    43,    91,
      32,    63,    64,    65,    66,    67,    37,   154,    39,   156,
      67,    24,    25,    26,    27,    28,    29,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29,    37,
      41,    39,   134,    32,    34,   140,    49,   139,    63,    59,
      41,    48,    44,    45,    37,    41,    39,    41,   140,   154,
      52,    40,    54,    33,    63,    41,    58,    45,    50,    41,
      62,    35,   154,    51,    52,    67,    54,    39,    45,    45,
      58,    55,    41,    11,    62,    52,    52,    54,    54,    67,
      24,    58,    58,    60,    -1,    62,    62,    84,   155,    -1,
      67,    67,    24,    25,    26,    27,    28,    29,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    41,    24,    25,    26,    27,
      28,    29,    24,    25,    26,    27,    28,    29,    -1,    37,
      -1,    20,    21,    22,    23,    37,    24,    25,    26,    27,
      28,    29,    31,    -1,    -1,    -1,    -1,    35,    24,    25,
      26,    27,    28,    29,    85,    86,    87,    88,    89,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,     0,    57,    70,    71,    67,    61,    72,    77,
      41,    73,    44,    82,    53,    78,    79,    67,    74,    76,
      77,    45,    52,    54,    58,    62,    67,    83,    84,    85,
      92,    93,    94,    95,    97,    98,    99,    38,    67,    41,
      41,    39,    40,    41,    67,    36,    83,    17,    19,    36,
      63,    64,    65,    66,    67,    87,    88,    89,    90,    91,
      92,    32,    34,    36,    51,    84,    32,    36,    72,    81,
      67,     3,    11,    13,    15,    16,    43,    75,    32,    88,
      60,    91,    91,    88,    36,    24,    25,    26,    27,    28,
      29,    49,    18,    19,    30,    20,    21,    22,    23,    31,
      88,    88,    86,    88,    88,    74,    80,    82,    41,    34,
      88,    37,    88,    37,    86,    89,    89,    89,    89,    89,
      89,    82,    84,    90,    90,    90,    91,    91,    91,    91,
      91,    41,    35,    37,    39,    41,    37,    39,    63,    48,
      59,    41,    37,    41,    41,    88,    40,    74,    33,    88,
      82,    84,    75,    63,    49,    41,    50,    96,    35,    82,
      84,    96,    82,    55,    41,    41,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     4,     3,     3,     1,     3,     0,
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

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 104 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        ast_root = new Program((yyvsp[-3].prog_head), (yyvsp[-2].decl_part), (yyvsp[-1].exec_part));
        setl(ast_root);
    }
#line 1634 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.prog_head) = new ProgHead((yyvsp[-1].type_string)); setl((yyval.prog_head));}
#line 1640 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        (yyval.decl_part) = new DeclPart((yyvsp[-1].var_list), (yyvsp[0].func_list)); 
        setl((yyval.decl_part));
    }
#line 1649 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "./parse/grammar.y" /* yacc.c:1646  */
    {   VarDeclList* v =  new VarDeclList();
        (yyval.decl_part) = new DeclPart(v, (yyvsp[0].func_list));setl((yyval.decl_part));}
#line 1656 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.var_list) = (yyvsp[-2].var_list);
  (yyval.var_list)->pushVarDecl((yyvsp[-1].var_node)); setl((yyval.var_list));}
#line 1663 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.var_list) = new VarDeclList(); setl((yyval.var_list));}
#line 1669 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "./parse/grammar.y" /* yacc.c:1646  */
    {
        (yyval.var_node) = new VarDecl((yyvsp[0].simple_type), (yyvsp[-2].id_list)); 
        setl((yyval.var_node));
    }
#line 1678 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "./parse/grammar.y" /* yacc.c:1646  */
    {
        ArrayType* ary = new ArrayType((yyvsp[-5].type_int), (yyvsp[-3].type_int), (yyvsp[0].simple_type)->getSimpleTypeName()); 
        (yyval.var_node) = new VarDecl(ary, (yyvsp[-9].id_list)); setl((yyval.var_node));
    }
#line 1687 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.simple_type) = new SimpleType("integer"); setl((yyval.simple_type));}
#line 1693 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.simple_type) = new SimpleType("real"); setl((yyval.simple_type));}
#line 1699 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.simple_type) = new SimpleType("real"); setl((yyval.simple_type));}
#line 1705 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.simple_type) = new SimpleType("char"); setl((yyval.simple_type));}
#line 1711 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.simple_type) = new SimpleType("string"); setl((yyval.simple_type));}
#line 1717 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_list) = (yyvsp[-2].id_list);
  (yyval.id_list)->pushID((string)(yyvsp[0].type_string)); }
#line 1724 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_list) = new IDList(); setl((yyval.id_list));
  (yyval.id_list)->pushID((string)(yyvsp[0].type_string)); }
#line 1731 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 167 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.func_list) = (yyvsp[-1].func_list);
  (yyval.func_list)->pushOneFuncDecl((yyvsp[0].func_node)); }
#line 1738 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.func_list) = new FuncDeclList(); setl((yyval.func_list));}
#line 1744 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 175 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.func_node) = new OneFuncDecl((yyvsp[-3].func_head), (yyvsp[-1].func_body)); setl((yyval.func_node));}
#line 1750 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 179 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        (yyval.func_head) = new FuncHead((string)(yyvsp[-5].type_string), (yyvsp[0].simple_type), (yyvsp[-3].para_node)); setl((yyval.func_head));
    }
#line 1758 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.para_node) = (yyvsp[-2].para_node);
  (yyval.para_node)->pushNewPara((yyvsp[0].var_node)); }
#line 1765 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.para_node) = new ParaList((yyvsp[0].var_node)); setl((yyval.para_node));}
#line 1771 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "./parse/grammar.y" /* yacc.c:1646  */
    {
        (yyval.func_body) = new FuncBody((yyvsp[-1].decl_part), (yyvsp[0].exec_part)); setl((yyval.func_body));
    }
#line 1779 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        (yyval.exec_part) = new ExecPart((yyvsp[-1].stmt_list));setl((yyval.exec_part));
    }
#line 1787 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 205 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        (yyval.stmt_list)->pushStmt((yyvsp[0].stmt_node)); 
    }
#line 1796 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = new StmtList((yyvsp[0].stmt_node)); setl((yyval.stmt_list));}
#line 1802 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 215 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].assign_node); }
#line 1808 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].for_node); }
#line 1814 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].call_node); }
#line 1820 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].repeat_node); }
#line 1826 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 223 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].break_node); }
#line 1832 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].while_node); }
#line 1838 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 227 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[0].if_node); }
#line 1844 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "./parse/grammar.y" /* yacc.c:1646  */
    { IDExpr* id = new IDExpr("var", (string)(yyvsp[-3].type_string)); setl((yyval.assign_node));
  (yyval.assign_node) = new AssignStmt(id, (yyvsp[-1].expr_node)); }
#line 1851 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 235 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.assign_node) = new AssignStmt((yyvsp[-3].array_expr), (yyvsp[-1].expr_node)); setl((yyval.assign_node));}
#line 1857 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_list) = (yyvsp[-2].expr_list);
  (yyval.expr_list)->pushExprNode((yyvsp[0].expr_node)); }
#line 1864 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_list) = new ExprList((yyvsp[0].expr_node)); setl((yyval.expr_list));}
#line 1870 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 248 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_expr) = new IDExpr("var", (string)(yyvsp[0].type_string)); setl((yyval.id_expr));}
#line 1876 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 250 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_expr) = new IDExpr("Imm", (int)(yyvsp[0].type_int)); setl((yyval.id_expr));}
#line 1882 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_expr) = new IDExpr("Imm", (char)(yyvsp[0].type_char)); setl((yyval.id_expr));}
#line 1888 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 254 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.id_expr) = new IDExpr("Imm", (double)(yyvsp[0].type_float)); setl((yyval.id_expr));}
#line 1894 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 256 "./parse/grammar.y" /* yacc.c:1646  */
    {  string temp((yyvsp[0].type_string));
   (yyval.id_expr) = new IDExpr("Imm", temp.substr(1,temp.length()-2)); setl((yyval.id_expr));}
#line 1901 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 262 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("GT", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1907 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 264 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("LT", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1913 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 266 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("EQUAL", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1919 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 268 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("GE", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1925 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 270 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("LE", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1931 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 272 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("NE", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1937 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 274 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1943 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 279 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("PLUS", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1949 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("MINUS", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1955 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 283 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("OR", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1961 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1967 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("MUL", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1973 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 292 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("DIV", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1979 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 294 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("DIV", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1985 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 296 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("AND", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1991 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 298 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new BinExpr("MOD", (yyvsp[-2].expr_node), (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 1997 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 300 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 2003 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 305 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new UnaryExpr("NOT", (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 2009 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 307 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new UnaryExpr("SUB", (yyvsp[0].expr_node)); setl((yyval.expr_node));}
#line 2015 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 309 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new FunCallExpr((string)(yyvsp[-3].type_string), (yyvsp[-1].expr_list)); setl((yyval.expr_node));}
#line 2021 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 311 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].array_expr); }
#line 2027 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 313 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 2033 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 315 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].id_expr); }
#line 2039 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 319 "./parse/grammar.y" /* yacc.c:1646  */
    {
        (yyval.array_expr) = new ArrayExpr((string)(yyvsp[-3].type_string), (yyvsp[-1].expr_node));setl((yyval.array_expr));
    }
#line 2047 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 325 "./parse/grammar.y" /* yacc.c:1646  */
    {
        (yyval.for_node) = new ForStmt((string)(yyvsp[-7].type_string), (yyvsp[-5].expr_node), (yyvsp[-3].expr_node), (yyvsp[-1].exec_part)->sl); setl((yyval.for_node));
    }
#line 2055 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 328 "./parse/grammar.y" /* yacc.c:1646  */
    {
        StmtList* sl = new StmtList((yyvsp[0].stmt_node));
        (yyval.for_node) = new ForStmt((string)(yyvsp[-6].type_string), (yyvsp[-4].expr_node), (yyvsp[-2].expr_node), sl);setl((yyval.for_node));
    }
#line 2064 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "./parse/grammar.y" /* yacc.c:1646  */
    {
        (yyval.while_node) = new WhileStmt((yyvsp[-3].expr_node), (yyvsp[-1].exec_part)->sl); setl((yyval.while_node));
    }
#line 2072 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 338 "./parse/grammar.y" /* yacc.c:1646  */
    {
        StmtList* sl = new StmtList((yyvsp[0].stmt_node));
        (yyval.while_node) = new WhileStmt((yyvsp[-2].expr_node), sl);setl((yyval.while_node));
    }
#line 2081 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 346 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.if_node) = new IfStmt((yyvsp[-5].expr_node), (yyvsp[-2].exec_part)->sl, (yyvsp[0].else_node)); }
#line 2087 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 348 "./parse/grammar.y" /* yacc.c:1646  */
    { StmtList* sl = new StmtList();
  sl->pushStmt((yyvsp[-1].stmt_node));
  (yyval.if_node) = new IfStmt((yyvsp[-4].expr_node), sl, (yyvsp[0].else_node)); setl((yyval.if_node));}
#line 2095 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 355 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.else_node) = new ElseStmt((yyvsp[-1].exec_part)->sl); setl((yyval.else_node));}
#line 2101 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 357 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.else_node) = new ElseStmt(); setl((yyval.else_node));}
#line 2107 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 362 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.break_node) = new BreakStmt(); setl((yyval.break_node));}
#line 2113 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 367 "./parse/grammar.y" /* yacc.c:1646  */
    { (yyval.call_node) = new FuncCallStmt((string)(yyvsp[-4].type_string), (yyvsp[-2].expr_list)); setl((yyval.call_node));}
#line 2119 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 371 "./parse/grammar.y" /* yacc.c:1646  */
    { 
        (yyval.repeat_node) = new RepeatStmt((yyvsp[-1].expr_node), (yyvsp[-3].stmt_list)); setl((yyval.repeat_node));
    }
#line 2127 "./parse/yacc.cpp" /* yacc.c:1646  */
    break;


#line 2131 "./parse/yacc.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 376 "./parse/grammar.y" /* yacc.c:1906  */

void yyerror (char const *s) {
   printf ("%s at %d\n", s, yylval.location);
 }
