
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "syntax.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


char *get_value(char* name);  // Declare get_value
void Rechercher(char entite[], char code[], char type[], char val[], int y);
void inserer(char entite[], char code[], char type[], char val[], int y);
void initialization();
void afficher();
char *getInput();
void setArrayElement(char *idf, int index, char *val);
void setArraySize(char *idf, int size);
bool is_integer(char *str);
int is_initialized(char *idf) ;
bool insererConstante(char *idf, char *type, float value);
bool is_float(char *str);
void verifierDoubleDeclaration(char* idf, char* type);
void verifierDeclaration(char* idf);
void verifierAffectation(char* idf_left, char* idf_right_or_val, int is_const);
bool verifierTypeCompatibility(char *idf, char *exprValue);
int verifierConstanteModification(char* idf);
int isNumeric(char* val);
char* getType(char* idf);
int isConstant(char* idf);
int expression_error = 0;
int idf_error = 0;
int inputVar;
bool verifierIdf(char idf[]);
extern int yylex();
extern int nb_ligne;
void yyerror(const char* msg);

int valType;
int intValue;
float floatValue;
char* strValue;



/* Line 189 of yacc.c  */
#line 116 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     LET = 262,
     DEFINE = 263,
     CONST = 264,
     INT = 265,
     FLOAT = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     DO = 270,
     WHILE = 271,
     FOR = 272,
     FROM = 273,
     TO = 274,
     STEP = 275,
     INPUT = 276,
     OUTPUT = 277,
     PLUS = 278,
     MINUS = 279,
     MULT = 280,
     DIV = 281,
     AFF = 282,
     EGAL = 283,
     INF = 284,
     SUP = 285,
     SUPEG = 286,
     INFEG = 287,
     EGALITE = 288,
     DIFFERENT = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     PVG = 293,
     DP = 294,
     COMMA = 295,
     PO = 296,
     PF = 297,
     AO = 298,
     AF = 299,
     CO = 300,
     CF = 301,
     INTEGER = 302,
     FLOATING = 303,
     STRING = 304,
     IDF = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 44 "syntax.y"

    int integer;
    float real;
    char* str;  



/* Line 214 of yacc.c  */
#line 210 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 222 "syntax.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    13,    15,    18,    24,    34,    43,    45,
      49,    51,    53,    55,    57,    59,    61,    64,    66,    68,
      70,    72,    74,    79,    87,    89,    91,    95,    99,   103,
     107,   111,   116,   129,   138,   148,   160,   166,   174,   180,
     184,   188,   192,   196,   199,   201,   203,   205,   207,   209
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,     3,    50,    38,     4,    53,     5,    58,
       6,    38,    -1,    54,    -1,    53,    54,    -1,     7,    55,
      39,    56,    38,    -1,     7,    55,    39,    45,    56,    38,
      47,    46,    38,    -1,     8,     9,    50,    39,    56,    28,
      57,    38,    -1,    50,    -1,    55,    40,    50,    -1,    10,
      -1,    11,    -1,    47,    -1,    48,    -1,    49,    -1,    59,
      -1,    58,    59,    -1,    60,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    50,    27,    61,    38,    -1,    50,
      45,    61,    46,    27,    61,    38,    -1,    57,    -1,    50,
      -1,    61,    23,    61,    -1,    61,    24,    61,    -1,    61,
      25,    61,    -1,    61,    26,    61,    -1,    41,    61,    42,
      -1,    50,    45,    61,    46,    -1,    12,    41,    66,    42,
      13,    43,    58,    44,    14,    43,    58,    44,    -1,    12,
      41,    66,    42,    13,    43,    58,    44,    -1,    15,    43,
      58,    44,    16,    41,    66,    42,    38,    -1,    17,    50,
      18,    61,    19,    61,    20,    61,    43,    58,    44,    -1,
      21,    41,    50,    42,    38,    -1,    22,    41,    49,    40,
      50,    42,    38,    -1,    22,    41,    49,    42,    38,    -1,
      61,    67,    61,    -1,    66,    36,    66,    -1,    66,    35,
      66,    -1,    41,    66,    42,    -1,    37,    66,    -1,    30,
      -1,    29,    -1,    28,    -1,    31,    -1,    32,    -1,    34,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    88,    89,    91,   103,   116,   139,   148,
     162,   163,   165,   170,   175,   181,   183,   185,   186,   187,
     188,   189,   193,   239,   245,   248,   266,   270,   274,   278,
     288,   292,   299,   306,   314,   315,   356,   363,   367,   370,
     395,   399,   403,   407,   414,   418,   422,   426,   430,   434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAINPRGM", "VAR", "BEGINPG", "ENDPG",
  "LET", "DEFINE", "CONST", "INT", "FLOAT", "IF", "THEN", "ELSE", "DO",
  "WHILE", "FOR", "FROM", "TO", "STEP", "INPUT", "OUTPUT", "PLUS", "MINUS",
  "MULT", "DIV", "AFF", "EGAL", "INF", "SUP", "SUPEG", "INFEG", "EGALITE",
  "DIFFERENT", "AND", "OR", "NOT", "PVG", "DP", "COMMA", "PO", "PF", "AO",
  "AF", "CO", "CF", "INTEGER", "FLOATING", "STRING", "IDF", "$accept",
  "programme", "declarations", "declaration", "var_list", "type", "value",
  "instructions", "instruction", "affectation", "expression", "condition",
  "boucle", "lecture", "ecriture", "conditions", "comparison", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    65,    65,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     2,     5,     9,     8,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     7,     1,     1,     3,     3,     3,     3,
       3,     4,    12,     8,     9,    11,     5,     7,     5,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       3,     8,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    17,    18,    19,
      20,    21,    10,    11,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     5,     0,
       0,     0,    12,    13,    14,    25,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,    46,    45,    44,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,    30,    42,     0,
      26,    27,    28,    29,    39,    41,    40,     0,     0,     0,
      36,     0,    38,     0,     0,     7,    31,     0,     0,     0,
       0,     0,     6,     0,     0,     0,    37,    23,    33,     0,
       0,     0,    34,     0,     0,     0,     0,    35,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     9,    10,    12,    35,    56,    25,    26,    27,
      57,    28,    29,    30,    31,    58,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
      14,   -29,    27,    16,   -42,    61,    52,    17,    64,    82,
     -42,   -42,     1,    28,    97,   -42,     5,    36,    53,    60,
      51,    55,    62,    67,   -15,     7,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   105,    75,   -42,   105,   121,    97,
      99,    70,    96,   141,   141,   108,   -42,   119,   -42,   133,
     121,   121,   -42,   -42,   -42,   120,   -42,   149,    13,    30,
     141,   122,   -22,   141,   125,   -21,   -42,   146,   -16,   -42,
     102,    33,   141,   141,   141,   141,   141,   -42,   -42,   -42,
     -42,   -42,   -42,   141,   121,   121,   163,   178,   173,   157,
     151,   164,   114,   -42,   181,   165,   169,   -42,   -42,    58,
     117,   117,   -42,   -42,   161,   -42,   174,   167,   171,   141,
     -42,   172,   -42,   141,   175,   -42,   -42,    97,   121,   180,
     177,   129,   -42,    41,   124,   141,   -42,   -42,   202,   179,
      98,   176,   -42,    97,    97,    49,    85,   -42,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   209,   -42,   -26,   152,   -38,   -25,   -42,
     -37,   -42,   -42,   -42,   -42,   -41,   -42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    59,    73,    74,    75,    76,    64,    65,    47,    69,
      71,    49,    43,    45,    70,    32,    33,     1,    90,    19,
      91,     3,    20,    88,    21,    94,    92,     4,    22,    23,
      44,    52,    53,    54,    46,    99,   100,   101,   102,   103,
      16,    17,    19,   105,   106,    20,   104,    21,    84,    85,
      34,    22,    23,    19,     5,    86,    20,    24,    21,     7,
       8,    19,    22,    23,    20,     6,    21,    11,    84,    85,
      22,    23,   119,    13,    87,    98,   121,   124,    18,   123,
      24,    73,    74,    75,    76,   128,    36,    14,   130,     7,
       8,    24,    37,   137,    39,   135,   136,    19,    46,    24,
      20,    38,    21,    41,   116,    40,    22,    23,    42,    19,
      46,    46,    20,    48,    21,    32,    33,    60,    22,    23,
      61,    73,    74,    75,    76,    73,    74,    75,    76,   138,
      77,    78,    79,    80,    81,    24,    82,    73,    74,    75,
      76,   133,    75,    76,    97,    62,    66,    24,    73,    74,
      75,    76,    73,    74,    75,    76,    97,    67,    50,    84,
      85,    68,    51,    93,    89,    72,   129,   127,    52,    53,
      54,    55,    73,    74,    75,    76,   107,    77,    78,    79,
      80,    81,    63,    82,    73,    74,    75,    76,    52,    53,
      54,    55,   109,    95,   108,   110,    73,    74,    75,    76,
     125,   111,   112,    73,    74,    75,    76,   115,   113,    84,
     117,   114,   118,   122,   120,   126,   131,   132,    15,   134,
      96
};

static const yytype_uint8 yycheck[] =
{
      25,    39,    23,    24,    25,    26,    43,    44,    34,    50,
      51,    37,    27,     6,    51,    10,    11,     3,    40,    12,
      42,    50,    15,    60,    17,    46,    63,     0,    21,    22,
      45,    47,    48,    49,    59,    72,    73,    74,    75,    76,
      39,    40,    12,    84,    85,    15,    83,    17,    35,    36,
      45,    21,    22,    12,    38,    42,    15,    50,    17,     7,
       8,    12,    21,    22,    15,     4,    17,    50,    35,    36,
      21,    22,   109,     9,    44,    42,   113,   118,    50,   117,
      50,    23,    24,    25,    26,    44,    50,     5,   125,     7,
       8,    50,    39,    44,    43,   133,   134,    12,   123,    50,
      15,    41,    17,    41,    46,    50,    21,    22,    41,    12,
     135,   136,    15,    38,    17,    10,    11,    18,    21,    22,
      50,    23,    24,    25,    26,    23,    24,    25,    26,    44,
      28,    29,    30,    31,    32,    50,    34,    23,    24,    25,
      26,    43,    25,    26,    42,    49,    38,    50,    23,    24,
      25,    26,    23,    24,    25,    26,    42,    38,    37,    35,
      36,    28,    41,    38,    42,    45,    42,    38,    47,    48,
      49,    50,    23,    24,    25,    26,    13,    28,    29,    30,
      31,    32,    41,    34,    23,    24,    25,    26,    47,    48,
      49,    50,    19,    47,    16,    38,    23,    24,    25,    26,
      20,    50,    38,    23,    24,    25,    26,    38,    27,    35,
      43,    46,    41,    38,    42,    38,    14,    38,     9,    43,
      68
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    50,     0,    38,     4,     7,     8,    53,
      54,    50,    55,     9,     5,    54,    39,    40,    50,    12,
      15,    17,    21,    22,    50,    58,    59,    60,    62,    63,
      64,    65,    10,    11,    45,    56,    50,    39,    41,    43,
      50,    41,    41,    27,    45,     6,    59,    56,    38,    56,
      37,    41,    47,    48,    49,    50,    57,    61,    66,    58,
      18,    50,    49,    41,    61,    61,    38,    38,    28,    66,
      61,    66,    45,    23,    24,    25,    26,    28,    29,    30,
      31,    32,    34,    67,    35,    36,    42,    44,    61,    42,
      40,    42,    61,    38,    46,    47,    57,    42,    42,    61,
      61,    61,    61,    61,    61,    66,    66,    13,    16,    19,
      38,    50,    38,    27,    46,    38,    46,    43,    41,    61,
      42,    61,    38,    58,    66,    20,    38,    38,    44,    42,
      61,    14,    38,    43,    43,    58,    58,    44,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 84 "syntax.y"
    {
    printf("PARSER: Programme parsed successfully. %s\n", (yyvsp[(2) - (9)].str));
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 88 "syntax.y"
    { printf("PARSER: Single declaration processed.\n"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 89 "syntax.y"
    { printf("PARSER: Multiple declarations processed.\n"); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 91 "syntax.y"
    { 
    printf("PARSER: Variable declaration of type %s.\n", (yyvsp[(4) - (5)].str));
    
    char* token = strtok((yyvsp[(2) - (5)].str), ",");
    while(token != NULL) {

        verifierDoubleDeclaration(token, (yyvsp[(4) - (5)].str)); 

        Rechercher(token, "IDF", (yyvsp[(4) - (5)].str), "", 1);  // Update type for each variable
        token = strtok(NULL, ",");
    }
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 103 "syntax.y"
    { 
        printf("PARSER: Array declaration of type %s.\n", (yyvsp[(5) - (9)].str));
        char arrayType[20];
        sprintf(arrayType, "%s[%d]", (yyvsp[(5) - (9)].str), (yyvsp[(7) - (9)].integer));
        char* token = strtok((yyvsp[(2) - (9)].str), ",");
        while (token != NULL) {
            verifierDoubleDeclaration(token, arrayType);
            Rechercher(token, "IDF", arrayType, "", 1);
            setArraySize(token, (yyvsp[(7) - (9)].integer));  // Set array_size and init val_array
            token = strtok(NULL, ",");
        }
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 116 "syntax.y"
    { 
    printf("PARSER: Constant definition: %s\n", (yyvsp[(3) - (8)].str));
    printf("Birgo :  %d\n", verifierIdf((yyvsp[(3) - (8)].str)));
    if (verifierIdf((yyvsp[(3) - (8)].str)) == 1) {
        printf("Abdou : %s\n", (yyvsp[(3) - (8)].str));
        verifierDoubleDeclaration((yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].str));
        char strval[64];
        sprintf(strval, "%f", (yyvsp[(7) - (8)].real)); 
        Rechercher((yyvsp[(3) - (8)].str), "CONST", (yyvsp[(5) - (8)].str), "", 1);
        if (verifierTypeCompatibility((yyvsp[(3) - (8)].str), strval)) {

            if (strcmp((yyvsp[(5) - (8)].str), "int") == 0) {
                sprintf(strval, "%d", (int)(yyvsp[(7) - (8)].real));  
            }
            Rechercher((yyvsp[(3) - (8)].str), "CONST", (yyvsp[(5) - (8)].str), strval, 1); 
        } else {
            printf("Error: Failed to define constant '%s' due to type mismatch.\n", (yyvsp[(3) - (8)].str));
        
        }
    }
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 139 "syntax.y"
    { 
    printf("PARSER: Variable: %s\n", (yyvsp[(1) - (1)].str));
    if(verifierIdf((yyvsp[(1) - (1)].str)) == 1) {
        Rechercher((yyvsp[(1) - (1)].str), "IDF", "", "", 1);
        (yyval.str) = (yyvsp[(1) - (1)].str);
    }else{
        (yyval.str) = "";
    }
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 148 "syntax.y"
    { 
    printf("PARSER: Variable list extended: %s\n", (yyvsp[(3) - (3)].str));
    if (verifierIdf((yyvsp[(3) - (3)].str)) == 1) {
        Rechercher((yyvsp[(3) - (3)].str), "IDF", "", "", 1);
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 2);
        strcpy((yyval.str), (yyvsp[(1) - (3)].str));
        strcat((yyval.str), ",");
        strcat((yyval.str), (yyvsp[(3) - (3)].str));
    } else {
        (yyval.str) = (yyvsp[(1) - (3)].str); // Keep the previous list if the new IDF is invalid
        printf("PARSER: Invalid identifier %s ignored.\n", (yyvsp[(3) - (3)].str));
    }
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 162 "syntax.y"
    { (yyval.str) = "int"; printf("PARSER: Type: Integer.\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 163 "syntax.y"
    { (yyval.str) = "float"; printf("PARSER: Type: Float.\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "syntax.y"
    { 
    // valType = 0;  // Integer type
    // intValue = $1;  // Store integer value
    (yyval.real) = (float)(yyvsp[(1) - (1)].integer);  // Store integer value
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 170 "syntax.y"
    { 
    // valType = 1;  // Float type
    // floatValue = $1;  // Store float value
    (yyval.real) = (yyvsp[(1) - (1)].real);  // Store float value
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 175 "syntax.y"
    { 
    // valType = 2;  // String type
    // strValue = malloc(strlen($1) + 1);  // Allocate memory for string
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 181 "syntax.y"
    {printf("PARSER: Single instruction processed.\n");
      ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 183 "syntax.y"
    { printf("PARSER: Multiple instructions processed.\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 185 "syntax.y"
    { printf("PARSER: Affectation processed.\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 186 "syntax.y"
    { printf("PARSER: Condition processed.\n"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 "syntax.y"
    { printf("PARSER: Loop processed.\n"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 188 "syntax.y"
    { printf("PARSER: Input instruction processed.\n"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 189 "syntax.y"
    { printf("PARSER: Output instruction processed.\n"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 193 "syntax.y"
    {
        printf("PARSER: Assignment to variable: %s\n", (yyvsp[(1) - (4)].str));

        verifierDeclaration((yyvsp[(1) - (4)].str));
        char strval[64];
        sprintf(strval, "%f", (yyvsp[(3) - (4)].real));  // Convert expression result to string

        if (verifierConstanteModification((yyvsp[(1) - (4)].str)) == 0) {
            if (expression_error) {
                printf("PARSER: Assignment ignored due to invalid expression (e.g., division by zero).\n");
                expression_error = 0;
            } else if (idf_error) {
                printf("PARSER: Assignment ignored due to invalid variable value.\n");
                idf_error = 0;
            } else if (verifierTypeCompatibility((yyvsp[(1) - (4)].str), strval)) {
                // Adjust value format based on type
                const char *varType = getType((yyvsp[(1) - (4)].str));

                if (strcmp(varType, "float") == 0) {
                    sprintf(strval, "%f", (yyvsp[(3) - (4)].real));
                    if (is_float(strval) || is_integer(strval)) {
                        Rechercher((yyvsp[(1) - (4)].str), "IDF", "", strval, 1);

                    }else {
                        printf("Error: Type mismatch (expected float or integer convertible to float).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else if (strcmp(varType, "int") == 0) {
                    sprintf(strval, "%f", (yyvsp[(3) - (4)].real));
                    if (is_integer(strval)) {
                        sprintf(strval, "%d", (int)(yyvsp[(3) - (4)].real));
                        Rechercher((yyvsp[(1) - (4)].str), "IDF", "", strval, 1);

                    } else {
                        printf("Error: Type mismatch (expected integer).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else {
                    printf("PARSER: Unknown type for variable %s.\n", (yyvsp[(1) - (4)].str));
                }
            }
        }
        expression_error = 0;  // Reset after processing
        idf_error = 0;  // Reset after processing
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 239 "syntax.y"
    { printf("PARSER: Array assignment.\n"); 
            // Add semantic checks
    verifierDeclaration((yyvsp[(1) - (7)].str)); // Check if array is declared
    verifierConstanteModification((yyvsp[(1) - (7)].str)); // Check if trying to modify a constant
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 245 "syntax.y"
    { 
        (yyval.real) = (yyvsp[(1) - (1)].real); 
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 248 "syntax.y"
    { 
        verifierDeclaration((yyvsp[(1) - (1)].str));
        char *value = get_value((yyvsp[(1) - (1)].str));
        if (is_initialized((yyvsp[(1) - (1)].str)) == 0) {
            printf("Error: Variable %s not initialized.\n", (yyvsp[(1) - (1)].str));
            idf_error = 1;
            (yyval.real) = 0;
        }
        if (is_integer(value)) {
            int result = atoi(value);
            (yyval.real) = result;
            printf("Integer value: %d\n", result);
        } else if (is_float(value)) {
            float result = atof(value);
            (yyval.real) = result;
            printf("Float value: %.2f\n", result);
        }
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 266 "syntax.y"
    { 
        (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].real); 
        printf("PARSER: Addition operation. %f\n", (yyval.real)); 
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 270 "syntax.y"
    { 
        (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real); 
        printf("PARSER: Subtraction operation. %f - %f = %f\n", (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].real), (yyval.real)); 
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 274 "syntax.y"
    { 
        (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].real); 
        printf("PARSER: Multiplication operation. %f\n", (yyval.real)); 
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 278 "syntax.y"
    { 
        if ((yyvsp[(3) - (3)].real) == 0) {
            printf("PARSER: Division by zero error.\n");
            printf("Operation will be ignored.\n");
            expression_error = 1;  // Mark the expression as invalid
            (yyval.real) = 0;
        } else {
            (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real);  
        }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 288 "syntax.y"
    { 
        (yyval.real) = (yyvsp[(2) - (3)].real); 
        printf("PARSER: Parenthesized expression : %f\n", (yyvsp[(2) - (3)].real)); 
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 292 "syntax.y"
    { 
        printf("PARSER: Array expression.\n"); 
        char *valStr;
        valStr = get_value((yyvsp[(1) - (4)].str));
        (yyval.real) = atoi(valStr);
        verifierDeclaration((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 299 "syntax.y"
    {printf("PARSER: If-Else condition processed.\n");
    if ((yyvsp[(3) - (12)].integer) == 1) {
        printf("PARSER: If condition is true.\n");
    } else {
        printf("PARSER: If condition is false.\n");
    }
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 306 "syntax.y"
    { printf("PARSER: If condition processed.\n"); 
        if ((yyvsp[(3) - (8)].integer) == 1) {
        printf("PARSER: If condition is true.\n");
        } else {
            printf("PARSER: If condition is false.\n");
        }
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 314 "syntax.y"
    { printf("PARSER: Do-While loop processed.\n"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 315 "syntax.y"
    {
          printf("PARSER: For loop with variable: %s\n", (yyvsp[(2) - (11)].str));
          verifierDeclaration((yyvsp[(2) - (11)].str));
        char strval[64];
        sprintf(strval, "%f", (yyvsp[(4) - (11)].real));  // Convert expression result to string

        if (verifierConstanteModification((yyvsp[(2) - (11)].str)) == 0) {
           if (idf_error) {
                printf("PARSER: Assignment ignored due to invalid variable value.\n");
                idf_error = 0;
            } else if (verifierTypeCompatibility((yyvsp[(2) - (11)].str), strval)) {
                // Adjust value format based on type
                const char *varType = getType((yyvsp[(2) - (11)].str));

                if (strcmp(varType, "float") == 0) {
                    sprintf(strval, "%f", (yyvsp[(4) - (11)].real));
                    if (is_float(strval) || is_integer(strval)) {
                        Rechercher((yyvsp[(2) - (11)].str), "IDF", "", strval, 1);

                    }else {
                        printf("Error: Type mismatch (expected float or integer convertible to float).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else if (strcmp(varType, "int") == 0) {
                    sprintf(strval, "%f", (yyvsp[(4) - (11)].real));
                    if (is_integer(strval)) {
                        sprintf(strval, "%d", (int)(yyvsp[(4) - (11)].real));
                        Rechercher((yyvsp[(2) - (11)].str), "IDF", "", strval, 1);

                    } else {
                        printf("Error: Type mismatch (expected integer).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else {
                    printf("PARSER: Unknown type for variable %s.\n", (yyvsp[(2) - (11)].str));
                }
            }
        }
        expression_error = 0;  // Reset after processing
        idf_error = 0;  // Reset after processing
     ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 356 "syntax.y"
    { printf("PARSER: Input received into variable: %s\n", (yyvsp[(3) - (5)].str));

    verifierDeclaration((yyvsp[(3) - (5)].str));
    verifierConstanteModification((yyvsp[(3) - (5)].str));

  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 363 "syntax.y"
    { printf("PARSER: Outputting: %s with variable: %s\n", (yyvsp[(3) - (7)].str), (yyvsp[(5) - (7)].str));
    verifierDeclaration((yyvsp[(5) - (7)].str));
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 367 "syntax.y"
    { printf("PARSER: Outputting: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 370 "syntax.y"
    {
        if (idf_error == 1) {
            printf("Error semantique: Variable non initialisee dans la condition\n");
            idf_error = 0;
            (yyval.integer) = 0;  // Default to false on error
        } else {
            // Evaluate the comparison based on the operator
            if (strcmp((yyvsp[(2) - (3)].str), "SUP") == 0) {
                (yyval.integer) = ((yyvsp[(1) - (3)].real) > (yyvsp[(3) - (3)].real)) ? 1 : 0;
            } else if (strcmp((yyvsp[(2) - (3)].str), "INF") == 0) {
                (yyval.integer) = ((yyvsp[(1) - (3)].real) < (yyvsp[(3) - (3)].real)) ? 1 : 0;
            } else if (strcmp((yyvsp[(2) - (3)].str), "EGAL") == 0) {
                (yyval.integer) = (((yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real)) < 0) ? 1 : 0;  // Use epsilon for float comparison
            } else if (strcmp((yyvsp[(2) - (3)].str), "SUPEG") == 0) {
                (yyval.integer) = ((yyvsp[(1) - (3)].real) >= (yyvsp[(3) - (3)].real) - 1e-6) ? 1 : 0;  // Use epsilon for float comparison
            } else if (strcmp((yyvsp[(2) - (3)].str), "INFEG") == 0) {
                (yyval.integer) = ((yyvsp[(1) - (3)].real) <= (yyvsp[(3) - (3)].real) + 1e-6) ? 1 : 0;  // Use epsilon for float comparison
            } else if (strcmp((yyvsp[(2) - (3)].str), "DIFFERENT") == 0) {
                (yyval.integer) = (((yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real)) >= 0) ? 1 : 0;  // Use epsilon for float comparison
            } else {
                (yyval.integer) = 0;  // Unknown operator, default to false
            }
            printf("PARSER: Comparison condition processed: %s, result = %d\n", (yyvsp[(2) - (3)].str), (yyval.integer));
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 395 "syntax.y"
    {
        (yyval.integer) = ((yyvsp[(1) - (3)].integer) || (yyvsp[(3) - (3)].integer)) ? 1 : 0;
        printf("PARSER: OR condition processed, result = %d\n", (yyval.integer));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 399 "syntax.y"
    {
        (yyval.integer) = ((yyvsp[(1) - (3)].integer) && (yyvsp[(3) - (3)].integer)) ? 1 : 0;
        printf("PARSER: AND condition processed, result = %d\n", (yyval.integer));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 403 "syntax.y"
    {
        (yyval.integer) = (yyvsp[(2) - (3)].integer);
        printf("PARSER: Parenthesized condition processed, result = %d\n", (yyval.integer));
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 407 "syntax.y"
    {
        (yyval.integer) = ((yyvsp[(2) - (2)].integer) == 0) ? 1 : 0;
        printf("PARSER: NOT condition processed, result = %d\n", (yyval.integer));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 414 "syntax.y"
    {
        (yyval.str) = "SUP";
        printf("PARSER: Greater than condition processed.\n");
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 418 "syntax.y"
    {
        (yyval.str) = "INF";
        printf("PARSER: Less than condition processed.\n");
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 422 "syntax.y"
    {
        (yyval.str) = "EGAL";
        printf("PARSER: Equality condition processed.\n");
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 426 "syntax.y"
    {
        (yyval.str) = "SUPEG";
        printf("PARSER: Greater than or equal condition processed.\n");
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 430 "syntax.y"
    {
        (yyval.str) = "INFEG";
        printf("PARSER: Less than or equal condition processed.\n");
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 434 "syntax.y"
    {
        (yyval.str) = "DIFFERENT";
        printf("PARSER: Not equal condition processed.\n");
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2157 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 439 "syntax.y"


int main() {
    printf("Debut de l'analyse syntaxique...\n");
    initialization();
    expression_error = 0; 
    idf_error = 0;
    yyparse();
    afficher();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

void yyerror(const char* msg) {
    printf("Error Syntaxique a la ligne %d : %s\n", nb_ligne, msg);
}
