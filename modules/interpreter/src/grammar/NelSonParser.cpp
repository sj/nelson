//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================

/* A Bison parser, made by GNU Bison 3.5.0.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* First part of user prologue.  */
#line 1 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"

// clang-format off
//bison -L C -k -o NelSonParser.cpp NelSonParser.yxx

#include <stdio.h>
#include <stdlib.h>
#include "AST.hpp"
#include "AstManager.hpp"
#include "Evaluator.hpp"
#include "FunctionDef.hpp"
#include "ParserInterface.hpp"
#include "Error.hpp"
#include "FileParser.hpp"
#include "i18n.hpp"

#define YYSTYPE ParseRHS

#define MSGBUFLEN 2048
static char msgBuffer[MSGBUFLEN];

#include "LexerInterface.hpp"

extern int yylex(void);

extern int yydebug;

bool interactiveMode;

#ifdef WIN32
#define snprintf _snprintf
#endif

namespace Nelson {
  static ASTPtr mainAST;
  static MacroFunctionDef *mainMDef;


  void chainFunction(MacroFunctionDef *r) {
     r->nextFunction = nullptr;
     r->prevFunction = nullptr;
     if (mainMDef == nullptr)
   {
    mainMDef = r;
   }
     else 
   {
    r->localFunction = true;
        r->nextFunction = mainMDef->nextFunction;
    if (r->nextFunction)
    {
      r->nextFunction->prevFunction = r;
    }
    mainMDef->nextFunction = r;
    r->prevFunction = mainMDef;
     }
  }

  void yyerror(const char *s) {
     return;
  }

  std::string decodeline(ParseRHS val) {
    int tokenID;
    int linenumber;
    if (val.isToken) 
      tokenID = val.v.i;
    else
      tokenID = val.v.p->context();
    linenumber = tokenID & 0xFFFF;
    char buffer[IDENTIFIER_LENGTH_MAX + 1];
    sprintf(buffer,"%d",linenumber);
    return(std::string(buffer));
  }
  
  int yyxpt(const std::string &xStr, ParseRHS val) {
    int tokenID;
    int linenumber, colnumber;
    if (val.isToken) 
      tokenID = val.v.i;
    else
      tokenID = val.v.p->context();
    linenumber = tokenID & 0xFFFF;
    colnumber = tokenID >> 16;
    if (!interactiveMode)
      snprintf(msgBuffer,MSGBUFLEN,
      _("Expecting %s\n\tat line %d, column %d of file %s").c_str(),
       xStr.c_str(),linenumber,colnumber,getParserFilenameU().c_str());
    else
      snprintf(msgBuffer,MSGBUFLEN,_("Expecting %s").c_str(),xStr.c_str());
    Error(msgBuffer);
    return 0;
  }
}

using namespace Nelson;


#line 194 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"

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
# define YYERROR_VERBOSE 0
#endif


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
    IDENT = 258,
    NUMERIC = 259,
    ENDQSTMNT = 260,
    ENDSTMNT = 261,
    LE = 262,
    GE = 263,
    EQ = 264,
    DOTTIMES = 265,
    DOTRDIV = 266,
    DOTLDIV = 267,
    DOTPOWER = 268,
    DOTTRANSPOSE = 269,
    CHARACTER = 270,
    STRING = 271,
    SPECIALCALL = 272,
    END = 273,
    IF = 274,
    FUNCTION = 275,
    FOR = 276,
    BREAK = 277,
    MAGICEND = 278,
    WHILE = 279,
    ELSE = 280,
    ELSEIF = 281,
    SWITCH = 282,
    CASE = 283,
    OTHERWISE = 284,
    CONTINUE = 285,
    TRY = 286,
    CATCH = 287,
    FIELD = 288,
    REFLPAREN = 289,
    REFRPAREN = 290,
    KEYBOARD = 291,
    RETURN = 292,
    VARARGIN = 293,
    VARARGOUT = 294,
    QUIT = 295,
    ABORT = 296,
    ENDFUNCTION = 297,
    SOR = 298,
    SAND = 299,
    NE = 300,
    POS = 301,
    NEG = 302,
    NOT = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


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
       2,     2,     2,     2,     2,     2,     2,     2,    46,    60,
      61,    62,    53,    51,    66,    52,    71,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    67,
      47,    63,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,    55,    65,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    45,    69,    70,     2,     2,     2,
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
      49,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   157,   158,   162,   174,   182,   193,   200,
     211,   218,   219,   221,   222,   223,   224,   226,   227,   231,
     232,   236,   237,   238,   239,   240,   241,   242,   243,   247,
     248,   252,   252,   264,   265,   269,   273,   277,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   304,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   319,   323,   327,   330,
     334,   340,   345,   346,   350,   356,   360,   360,   360,   360,
     364,   364,   368,   368,   372,   375,   381,   387,   390,   396,
     399,   404,   409,   410,   411,   413,   414,   415,   416,   417,
     418,   422,   425,   430,   431,   436,   442,   443,   447,   450,
     454,   455,   459,   462,   468,   471,   474,   477,   478,   482,
     483,   487,   490,   494,   498,   502,   503,   504,   505,   506,
     507,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     585,   586,   589,   590,   591,   592,   593,   594,   595,   598,
     599,   600,   601,   602,   603,   606,   607,   610,   611,   614,
     615,   618,   619,   622,   625,   626
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMERIC", "ENDQSTMNT",
  "ENDSTMNT", "LE", "GE", "EQ", "DOTTIMES", "DOTRDIV", "DOTLDIV",
  "DOTPOWER", "DOTTRANSPOSE", "CHARACTER", "STRING", "SPECIALCALL", "END",
  "IF", "FUNCTION", "FOR", "BREAK", "MAGICEND", "WHILE", "ELSE", "ELSEIF",
  "SWITCH", "CASE", "OTHERWISE", "CONTINUE", "TRY", "CATCH", "FIELD",
  "REFLPAREN", "REFRPAREN", "KEYBOARD", "RETURN", "VARARGIN", "VARARGOUT",
  "QUIT", "ABORT", "ENDFUNCTION", "SOR", "SAND", "'|'", "'&'", "'<'",
  "'>'", "NE", "':'", "'+'", "'-'", "'*'", "'/'", "'\\\\'", "POS", "NEG",
  "NOT", "'^'", "'\\''", "'('", "')'", "'='", "'['", "']'", "','", "';'",
  "'{'", "'}'", "'~'", "'.'", "$accept", "program", "functionDef",
  "functionDefList", "returnDeclaration", "argumentList", "argument",
  "statementList", "statement", "statementType", "endfunctionStatement",
  "specialSyntaxStatement", "returnStatement", "pauseStatement",
  "continueStatement", "breakStatement", "tryStatement", "optionalCatch",
  "switchStatement", "optionalEndStatement", "newLine", "caseBlock",
  "caseList", "caseStatement", "otherwiseClause", "forStatement",
  "forIndexExpression", "whileStatement", "ifStatement",
  "conditionedStatement", "elseIfBlock", "elseIfStatementList",
  "elseIfStatement", "elseStatement", "assignmentStatement",
  "multiFunctionCall", "expr", "terminal", "symbRefList", "symbRef",
  "indexElement", "indexList", "cellDef", "matrixDef", "rowSeperator",
  "columnSep", "rowDef", YY_NULLPTR
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
     295,   296,   297,   298,   299,   124,    38,    60,    62,   300,
      58,    43,    45,    42,    47,    92,   301,   302,   303,    94,
      39,    40,    41,    61,    91,    93,    44,    59,   123,   125,
     126,    46
};
# endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-125)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     762,  -157,    49,  -157,    17,    56,  1288,    36,    40,  -157,
    -157,  1331,  2375,  -157,  2232,  -157,  -157,  -157,  -157,  -157,
    2375,  2375,  1356,   135,  1232,  1361,    57,  -157,    29,   694,
    -157,    30,  -157,   212,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  2623,  -157,   180,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   135,    58,
    2441,   -17,  -157,   148,    24,   142,    47,  -157,    74,    91,
     163,  -157,  2466,  2466,  1022,   199,   199,  -157,  2527,  -157,
    -157,  -157,  -157,  2623,   175,  2375,    94,  -157,  -157,    10,
    2375,    94,  -157,   199,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  1387,  1429,  1455,  1460,  1485,  1528,
    1553,  -157,  1558,  1584,  1626,  1652,  1657,  1682,  1725,  1750,
    1755,  1781,  1823,  1849,  1854,  1879,  -157,   757,  1922,  2262,
       8,  -157,   179,  1947,   141,    58,  -157,  -157,  -157,  -157,
    -157,  -157,  2232,   131,  -157,  -157,   162,  -157,  2232,  -157,
    -157,  -157,   186,   147,    32,  -157,  -157,   177,  1952,  -157,
      26,  2126,  2182,   176,  2232,    37,  -157,  -157,   160,  2276,
     192,  -157,  2375,  -157,  2302,    55,  -157,   689,  -157,   689,
    -157,   689,  -157,   199,  -157,   199,  -157,   199,  -157,   199,
    -157,  2677,  -157,  2693,  -157,  2747,  -157,  2761,  -157,   689,
    -157,   689,  -157,   689,  -157,  2492,  -157,   455,  -157,   455,
    -157,   199,  -157,   199,  -157,   199,  -157,   199,  -157,   143,
    -157,  2623,  -157,    16,  -157,  2623,     7,  -157,  2375,  -157,
    -157,  -157,   966,    41,  -157,  2070,  -157,   216,    -4,   348,
    -157,  -157,  -157,    46,    21,  -157,   174,  2232,  -157,  2623,
    -157,  1978,  -157,   830,  -157,   898,  2375,   188,   176,  -157,
    1078,  -157,  -157,   154,  -157,    94,  -157,  2332,  2623,  -157,
      94,  -157,  2353,  -157,   168,  -157,  -157,  2262,  -157,  -157,
    2603,  -157,  1134,  -157,  -157,  2232,    65,  -157,  -157,  -157,
    -157,   216,   128,   420,  -157,  2547,  -157,  -157,  -157,  -157,
    2466,  2232,    45,  -157,  -157,    25,  -157,  -157,  2020,  -157,
    -157,   476,  -157,  2232,  2232,   213,  -157,  -157,  2232,  1190,
    -157,  -157,  -157,  1258,  1263,  -157,  2623,   532,   588,  -157,
    2232,  2070,  -157,  -157,    33,  -157,    11,   644,  -157,  -157,
    -157,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,   200,   183,   184,   185,     0,     0,     0,    69,
     186,     0,     0,    68,    40,    67,    66,    52,    53,    55,
       0,     0,     0,     0,     0,     0,     0,    19,     3,    40,
      33,     0,    54,    51,    50,    49,    44,    43,    48,    47,
      42,    45,    46,    38,    41,    39,   133,   187,    61,    56,
      60,    59,    58,    57,   106,   200,   184,   185,     0,   110,
       0,   187,    11,     0,     0,     0,     0,   100,    94,     0,
       0,   103,     0,     0,    40,   171,   170,   182,     0,   189,
     222,   221,   193,   224,     0,     0,   219,   199,   198,     0,
       0,   217,   173,   172,     1,    20,    34,    35,    36,    37,
      64,    65,    63,    62,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   178,     0,     0,     0,
       0,   201,     0,     0,   117,   111,   112,   109,    78,    77,
      76,    79,    40,    12,    81,    80,     0,    22,    40,    21,
      26,    31,     0,     0,     0,    29,    15,     0,     0,    98,
       0,    40,    40,    82,    40,     0,   181,   180,   188,     0,
       0,   223,     0,   194,     0,     0,   155,   154,   159,   158,
     161,   160,   165,   164,   167,   166,   169,   168,   177,   176,
     149,   148,   151,   150,   145,   144,   147,   146,   153,   152,
     157,   156,   163,   162,   132,   131,   135,   134,   137,   136,
     139,   138,   141,   140,   143,   142,   175,   174,   210,     0,
     203,   209,   215,     0,   120,   119,     0,   207,     0,   188,
     115,   114,     0,     0,   113,   108,    13,     0,     0,    40,
      32,    24,    27,     0,     0,    16,     0,    40,    99,    93,
      97,     0,    89,     0,   101,     0,     0,    88,    83,    84,
      40,    71,    70,     0,   191,   220,   190,     0,   225,   196,
     218,   195,     0,   214,   213,   204,   202,     0,   206,   205,
       0,   118,    40,   107,   105,    40,     0,    28,    23,    30,
      17,     0,     0,    40,    96,     0,    91,    90,   104,   102,
       0,    40,     0,    85,   130,     0,   192,   197,     0,   216,
     208,    40,    14,    40,    40,     0,    95,    92,    40,    40,
      75,    74,   129,     0,     0,   212,   211,    40,    40,    18,
      40,    86,   127,   121,     0,   128,     0,    40,   126,   122,
     125,   123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   178,  -157,  -157,  -118,   -53,    31,   100,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   -67,
    -156,  -157,  -157,   -33,  -157,  -157,  -157,  -157,  -157,   101,
    -157,  -157,   102,  -157,  -157,  -157,    -2,  -157,     0,  -157,
     -35,  -122,   156,   -45,     1,  -157,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    66,   154,   155,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   165,    39,   142,
     148,   257,   258,   259,   302,    40,    70,    41,    42,    59,
     134,   135,   136,   233,    43,    44,    45,    46,    61,   131,
     222,   223,    89,    84,    85,   172,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   247,    91,   161,    60,   162,   163,   226,   278,    72,
      73,   227,   340,   132,    47,    80,    81,   275,    75,    76,
      78,    83,    83,    93,   151,    90,   322,   250,   238,    47,
    -124,  -124,    52,   242,   338,    97,    98,    62,   261,    63,
     170,    67,   283,    68,   127,    74,   320,   287,   156,     7,
     157,   129,    48,    49,   130,   262,    83,    94,   286,   284,
      80,    81,   244,   321,    50,    51,   312,   152,    91,   228,
     144,   145,    53,   277,    47,    64,   279,   277,   276,   173,
     341,   285,   277,    83,   133,   169,   323,   149,    83,   251,
     174,  -124,   159,   324,   160,   339,    99,   243,   244,   277,
      65,    69,   177,   179,   181,   183,   185,   187,   189,   288,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   209,
     211,   213,   215,   217,   271,   221,   225,   221,   292,    96,
     313,    60,   -25,   169,   -25,   314,    79,   158,    55,     3,
      80,    81,    47,   150,   273,   151,   274,   265,    47,   143,
      56,    57,   270,   144,   145,   304,   249,   305,    10,   330,
     171,    47,    47,   236,    47,   151,   232,    83,   138,   139,
     268,   267,    83,   235,    96,   290,   272,   151,   245,   239,
      80,    81,   144,   145,    80,    81,    20,    21,   152,   240,
     315,   289,   253,   255,   244,   260,    22,    80,    81,    58,
      82,   334,   336,    24,   256,    25,    95,   153,   152,   146,
     241,   147,   110,   111,   329,   100,   101,   301,   144,   145,
     152,   144,   145,   263,   237,   303,   280,   102,   103,   140,
     141,   308,    47,   318,   231,    47,   291,   234,   246,    47,
     168,   127,   309,   128,   229,   265,   175,    47,   129,   295,
     270,   130,     0,    47,   300,    47,     0,   266,   125,   126,
      47,     0,     0,   282,     0,    83,     0,     0,     0,     0,
      83,     0,     0,     0,     0,   221,     0,     0,   293,     0,
       0,     0,    47,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,   326,     0,     0,     0,
       0,    47,     0,    47,    47,     0,   311,     0,    47,    47,
       0,   221,   221,     0,     0,     0,     0,    47,    47,     0,
      47,    47,   319,     0,     0,    96,     0,    47,     0,    96,
       0,     0,     0,     0,   327,   328,     0,     0,    -8,   331,
       0,     2,     3,    96,     0,    96,     0,     0,     0,     0,
      96,   337,     0,     4,     5,     0,     0,     6,    -8,     8,
       9,    10,    11,     0,     0,    12,     0,     0,    13,    14,
       0,     0,    96,     0,    15,    16,     0,     0,    17,    18,
      19,     0,     0,    96,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    96,    23,     0,     0,     0,    24,     0,    25,    96,
      -7,     0,     0,     2,     3,     0,     0,    96,    96,     0,
       0,    96,     0,     0,     0,     4,     5,    96,     0,     6,
      -7,     8,     9,    10,    11,     0,     0,    12,     0,     0,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
      17,    18,    19,     0,     0,   107,   108,   109,   110,   111,
       0,    20,    21,     0,     0,     0,   -10,     0,     0,     2,
       3,    22,     0,     0,    23,     0,     0,     0,    24,     0,
      25,     4,     5,     0,     0,     6,   -10,     8,     9,    10,
      11,     0,     0,    12,     0,     0,    13,    14,   122,   123,
     124,     0,    15,    16,   125,   126,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,    -6,     0,     0,     2,     3,    22,     0,     0,
      23,     0,     0,     0,    24,     0,    25,     4,     5,     0,
       0,     6,    -6,     8,     9,    10,    11,     0,     0,    12,
       0,     0,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,     0,     0,    -9,     0,
       0,     2,     3,    22,     0,     0,    23,     0,     0,     0,
      24,     0,    25,     4,     5,     0,     0,     6,    -9,     8,
       9,    10,    11,     0,     0,    12,     0,     0,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,    -5,     0,     0,     2,     3,    22,
       0,     0,    23,     0,     0,     0,    24,     0,    25,     4,
       5,     0,     0,     6,    -5,     8,     9,    10,    11,     0,
       0,    12,     0,     0,    13,    14,     0,     0,     0,     0,
      15,    16,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,    -2,    20,    21,     2,     3,   107,
     108,   109,   110,   111,     0,    22,     0,     0,    23,     4,
       5,     0,    24,     6,    25,     8,     9,    10,    11,     0,
       0,    12,     0,     0,    13,    14,     0,     0,     0,     0,
      15,    16,     0,     0,    17,    18,    19,     0,     0,   119,
     120,   121,   122,   123,   124,    20,    21,     0,   125,   126,
       0,     0,     0,     0,     0,    22,     0,     0,    23,     0,
      55,     3,    24,     1,    25,     2,     3,   -40,   -40,     0,
       0,     0,    56,    57,     0,     0,     0,     4,     5,     0,
      10,     6,     7,     8,     9,    10,    11,     0,     0,    12,
       0,     0,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,    17,    18,    19,     0,     0,   218,    20,    21,
       0,   219,     0,    20,    21,     0,     0,     0,    22,   220,
       0,    58,     0,    22,     0,    24,    23,    25,   -40,     0,
      24,   296,    25,     2,     3,   -40,   -40,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,   297,     6,
       0,     8,     9,    10,    11,     0,     0,    12,     0,     0,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,    23,     0,   -40,     0,    24,   298,
      25,     2,     3,   -40,   -40,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     0,   299,     6,     0,     8,
       9,    10,    11,     0,     0,    12,     0,     0,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,    23,     0,   -40,     0,    24,   281,    25,     2,
       3,   -40,   -40,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     6,     0,     8,     9,    10,
      11,     0,     0,    12,     0,     0,    13,    14,     0,     0,
       0,     0,    15,    16,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,     0,   -73,     0,     2,     3,    22,     0,     0,
      23,     0,   -40,     0,    24,     0,    25,     4,     5,     0,
     -73,     6,     0,     8,     9,    10,    11,     0,     0,    12,
       0,     0,    13,    14,   164,     0,     0,     0,    15,    16,
       0,     0,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,     0,     0,     0,   -72,
       0,     2,     3,    22,     0,     0,    23,     0,     0,     0,
      24,     0,    25,     4,     5,     0,   -72,     6,     0,     8,
       9,    10,    11,     0,     0,    12,     0,     0,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,  -116,     0,     2,     3,    22,
       0,     0,    23,     0,     0,     0,    24,     0,    25,     4,
       5,     0,  -116,     6,     0,     8,     9,    10,    11,     0,
       0,    12,     0,     0,    13,    14,     0,     0,     0,     0,
      15,    16,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,   -87,     0,     2,     3,    22,     0,     0,    23,     0,
       0,     0,    24,     0,    25,     4,     5,     0,   -87,     6,
       0,     8,     9,    10,    11,     0,     0,    12,     0,     0,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
      17,    18,    19,    87,     0,    55,     3,    80,    81,     0,
       0,    20,    21,     0,     0,     0,     0,    56,    57,     0,
       0,    22,     0,     0,    23,    10,     0,     0,    24,   332,
      25,    55,     3,     0,   335,     0,    55,     3,     0,     0,
       0,     0,     0,    56,    57,     0,     0,     0,    56,    57,
       0,    10,     0,    20,    21,     0,    10,     0,     0,    54,
       0,    55,     3,    22,     0,     0,    58,     0,     0,     0,
      24,    88,    25,    56,    57,     0,     0,     0,   218,    20,
      21,    10,   219,   218,    20,    21,     0,   219,     0,    22,
     333,     0,    58,     0,    22,     0,    24,    58,    25,     0,
       0,    24,    71,    25,    55,     3,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,    56,    57,     0,    22,
       0,     0,    58,     0,    10,     0,    24,    77,    25,    55,
       3,     0,    92,     0,    55,     3,     0,     0,     0,     0,
       0,    56,    57,     0,     0,     0,    56,    57,     0,    10,
       0,     0,    20,    21,    10,     0,     0,     0,   176,     0,
      55,     3,    22,     0,     0,    58,     0,     0,     0,    24,
       0,    25,    56,    57,     0,     0,     0,    20,    21,     0,
      10,     0,    20,    21,     0,     0,     0,    22,     0,     0,
      58,     0,    22,     0,    24,    58,    25,     0,     0,    24,
     178,    25,    55,     3,     0,     0,     0,     0,    20,    21,
       0,     0,     0,     0,    56,    57,     0,     0,    22,     0,
       0,    58,    10,     0,     0,    24,   180,    25,    55,     3,
       0,   182,     0,    55,     3,     0,     0,     0,     0,     0,
      56,    57,     0,     0,     0,    56,    57,     0,    10,     0,
      20,    21,     0,    10,     0,     0,   184,     0,    55,     3,
      22,     0,     0,    58,     0,     0,     0,    24,     0,    25,
      56,    57,     0,     0,     0,     0,    20,    21,    10,     0,
       0,    20,    21,     0,     0,     0,    22,     0,     0,    58,
       0,    22,     0,    24,    58,    25,     0,     0,    24,   186,
      25,    55,     3,     0,     0,     0,    20,    21,     0,     0,
       0,     0,     0,    56,    57,     0,    22,     0,     0,    58,
       0,    10,     0,    24,   188,    25,    55,     3,     0,   190,
       0,    55,     3,     0,     0,     0,     0,     0,    56,    57,
       0,     0,     0,    56,    57,     0,    10,     0,     0,    20,
      21,    10,     0,     0,     0,   192,     0,    55,     3,    22,
       0,     0,    58,     0,     0,     0,    24,     0,    25,    56,
      57,     0,     0,     0,    20,    21,     0,    10,     0,    20,
      21,     0,     0,     0,    22,     0,     0,    58,     0,    22,
       0,    24,    58,    25,     0,     0,    24,   194,    25,    55,
       3,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    56,    57,     0,     0,    22,     0,     0,    58,    10,
       0,     0,    24,   196,    25,    55,     3,     0,   198,     0,
      55,     3,     0,     0,     0,     0,     0,    56,    57,     0,
       0,     0,    56,    57,     0,    10,     0,    20,    21,     0,
      10,     0,     0,   200,     0,    55,     3,    22,     0,     0,
      58,     0,     0,     0,    24,     0,    25,    56,    57,     0,
       0,     0,     0,    20,    21,    10,     0,     0,    20,    21,
       0,     0,     0,    22,     0,     0,    58,     0,    22,     0,
      24,    58,    25,     0,     0,    24,   202,    25,    55,     3,
       0,     0,     0,    20,    21,     0,     0,     0,     0,     0,
      56,    57,     0,    22,     0,     0,    58,     0,    10,     0,
      24,   204,    25,    55,     3,     0,   206,     0,    55,     3,
       0,     0,     0,     0,     0,    56,    57,     0,     0,     0,
      56,    57,     0,    10,     0,     0,    20,    21,    10,     0,
       0,     0,   208,     0,    55,     3,    22,     0,     0,    58,
       0,     0,     0,    24,     0,    25,    56,    57,     0,     0,
       0,    20,    21,     0,    10,     0,    20,    21,     0,     0,
       0,    22,     0,     0,    58,     0,    22,     0,    24,    58,
      25,     0,     0,    24,   210,    25,    55,     3,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,    56,    57,
       0,     0,    22,     0,     0,    58,    10,     0,     0,    24,
     212,    25,    55,     3,     0,   214,     0,    55,     3,     0,
       0,     0,     0,     0,    56,    57,     0,     0,     0,    56,
      57,     0,    10,     0,    20,    21,     0,    10,     0,     0,
     216,     0,    55,     3,    22,     0,     0,    58,     0,     0,
       0,    24,     0,    25,    56,    57,     0,     0,     0,     0,
      20,    21,    10,     0,     0,    20,    21,     0,     0,     0,
      22,     0,     0,    58,     0,    22,     0,    24,    58,    25,
       0,     0,    24,   224,    25,    55,     3,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,    56,    57,     0,
      22,     0,     0,    58,     0,    10,     0,    24,   230,    25,
      55,     3,     0,   248,     0,    55,     3,     0,     0,     0,
       0,     0,    56,    57,     0,     0,     0,    56,    57,     0,
      10,     0,     0,    20,    21,    10,     0,     0,     0,   294,
       0,    55,     3,    22,     0,     0,    58,     0,     0,     0,
      24,     0,    25,    56,    57,     0,     0,     0,    20,    21,
       0,    10,     0,    20,    21,     0,     0,     0,    22,     0,
       0,    58,     0,    22,     0,    24,    58,    25,     0,     0,
      24,   325,    25,    55,     3,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,    56,    57,     0,     0,    22,
       0,     0,    58,    10,     0,     0,    24,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     2,     3,   -40,   -40,     0,     0,     0,
       0,    22,     0,     0,    58,     4,     5,     0,    24,     6,
      25,     8,     9,    10,    11,     0,     0,    12,     0,     0,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     2,
       3,    22,     0,     0,    23,     0,   -40,     0,    24,     0,
      25,     4,     5,     0,   252,     6,     0,     8,     9,    10,
      11,     0,     0,    12,     0,     0,    13,    14,     0,     0,
       0,     0,    15,    16,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     2,     3,    22,     0,     0,
      23,     0,     0,     0,    24,     0,    25,     4,     5,     0,
     254,     6,     0,     8,     9,    10,    11,     0,     0,    12,
       0,     0,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     2,     3,     0,     0,     0,
       0,     0,     0,    22,     0,     0,    23,     4,     5,     0,
      24,     6,    25,     8,     9,    10,    11,     0,     0,    12,
       0,     0,    13,    14,     0,    55,     3,     0,    15,    16,
       0,     0,    17,    18,    19,     0,     0,    56,    57,    55,
       3,     0,     0,    20,    21,    10,     0,     0,     0,     0,
       0,    56,    57,    22,     0,     0,    23,     0,     0,    10,
      24,     0,    25,     0,     0,    55,     3,     0,     0,     0,
       0,     0,   218,    20,    21,     0,   219,    56,    57,     0,
       0,     0,     0,    22,     0,    10,    58,    20,    21,     0,
      24,     0,    25,     0,     0,    55,     3,    22,     0,     0,
      58,   264,     0,     0,    24,     0,    25,    56,    57,     0,
       0,     0,     0,    20,    21,    10,    55,     3,     0,     0,
       0,     0,     0,    22,     0,     0,    58,     0,    56,    57,
      24,   269,    25,     0,     0,     0,    10,     0,    55,     3,
       0,     0,     0,    20,    21,     0,     0,     0,     0,     0,
      56,    57,     0,    22,     0,     0,    58,   306,    10,     0,
      24,     0,    25,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,    58,     0,     0,
       0,    24,   307,    25,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,    58,
       0,     0,   137,    24,     0,    25,   138,   139,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,   126,   107,   108,   109,   110,   111,   140,   141,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,   125,   126,     0,   166,     0,
       0,     0,   140,   141,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   120,   121,   122,   123,   124,   316,     0,
       0,   125,   126,     0,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,     0,   167,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,     0,   317,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,     0,   310,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,   126,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,   126
};

static const yytype_int16 yycheck[] =
{
       0,   157,    24,    70,     6,    72,    73,   129,     1,    11,
      12,     3,     1,    58,    14,     5,     6,     1,    20,    21,
      22,    23,    24,    25,     3,    24,     1,     1,   146,    29,
       5,     6,    15,     1,     1,     5,     6,     1,     1,     3,
      85,     1,     1,     3,    61,    14,     1,     1,     1,    20,
       3,    68,     3,     4,    71,    18,    58,     0,    62,    18,
       5,     6,    66,    18,    15,    16,     1,    46,    90,    61,
       5,     6,    16,    66,    74,    39,    69,    66,    62,    69,
      69,   237,    66,    85,    26,    84,    61,    63,    90,    63,
      89,    66,     1,    68,     3,    62,    66,    65,    66,    66,
      64,    61,   104,   105,   106,   107,   108,   109,   110,    63,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    69,   127,   128,   129,   246,    29,
     286,   133,     1,   132,     3,   291,     1,    63,     3,     4,
       5,     6,   142,     1,     1,     3,     3,   169,   148,     1,
      15,    16,   174,     5,     6,     1,   158,     3,    23,   315,
      66,   161,   162,     1,   164,     3,    25,   169,     5,     6,
     172,   170,   174,   142,    74,     1,   175,     3,     1,   148,
       5,     6,     5,     6,     5,     6,    51,    52,    46,     3,
      62,   244,   161,   162,    66,   164,    61,     5,     6,    64,
      65,   323,   324,    68,    28,    70,    28,    65,    46,    61,
      63,    63,    13,    14,     1,     3,     4,    29,     5,     6,
      46,     5,     6,    63,    62,   258,   228,    15,    16,    66,
      67,    63,   232,   300,   133,   235,    62,   135,    61,   239,
      65,    61,   277,    63,    65,   267,    90,   247,    68,   251,
     272,    71,    -1,   253,   256,   255,    -1,    65,    59,    60,
     260,    -1,    -1,   232,    -1,   267,    -1,    -1,    -1,    -1,
     272,    -1,    -1,    -1,    -1,   277,    -1,    -1,   247,    -1,
      -1,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,
      -1,   311,    -1,   313,   314,    -1,   285,    -1,   318,   319,
      -1,   323,   324,    -1,    -1,    -1,    -1,   327,   328,    -1,
     330,   331,   301,    -1,    -1,   235,    -1,   337,    -1,   239,
      -1,    -1,    -1,    -1,   313,   314,    -1,    -1,     0,   318,
      -1,     3,     4,   253,    -1,   255,    -1,    -1,    -1,    -1,
     260,   330,    -1,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,   282,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,   311,    64,    -1,    -1,    -1,    68,    -1,    70,   319,
       0,    -1,    -1,     3,     4,    -1,    -1,   327,   328,    -1,
      -1,   331,    -1,    -1,    -1,    15,    16,   337,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    51,    52,    -1,    -1,    -1,     0,    -1,    -1,     3,
       4,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      70,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    30,    31,    53,    54,
      55,    -1,    36,    37,    59,    60,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    15,    16,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,     0,    -1,
      -1,     3,     4,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    51,    52,     3,     4,    10,
      11,    12,    13,    14,    -1,    61,    -1,    -1,    64,    15,
      16,    -1,    68,    19,    70,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    -1,    -1,    50,
      51,    52,    53,    54,    55,    51,    52,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,
       3,     4,    68,     1,    70,     3,     4,     5,     6,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    15,    16,    -1,
      23,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    -1,    50,    51,    52,
      -1,    54,    -1,    51,    52,    -1,    -1,    -1,    61,    62,
      -1,    64,    -1,    61,    -1,    68,    64,    70,    66,    -1,
      68,     1,    70,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    64,    -1,    66,    -1,    68,     1,
      70,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    -1,    66,    -1,    68,     1,    70,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    61,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    70,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    15,    16,    -1,    18,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    15,
      16,    -1,    18,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    -1,    70,    15,    16,    -1,    18,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    15,    16,    -1,
      -1,    61,    -1,    -1,    64,    23,    -1,    -1,    68,     1,
      70,     3,     4,    -1,     1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    15,    16,
      -1,    23,    -1,    51,    52,    -1,    23,    -1,    -1,     1,
      -1,     3,     4,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    69,    70,    15,    16,    -1,    -1,    -1,    50,    51,
      52,    23,    54,    50,    51,    52,    -1,    54,    -1,    61,
      62,    -1,    64,    -1,    61,    -1,    68,    64,    70,    -1,
      -1,    68,     1,    70,     3,     4,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    61,
      -1,    -1,    64,    -1,    23,    -1,    68,     1,    70,     3,
       4,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    15,    16,    -1,    23,
      -1,    -1,    51,    52,    23,    -1,    -1,    -1,     1,    -1,
       3,     4,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    15,    16,    -1,    -1,    -1,    51,    52,    -1,
      23,    -1,    51,    52,    -1,    -1,    -1,    61,    -1,    -1,
      64,    -1,    61,    -1,    68,    64,    70,    -1,    -1,    68,
       1,    70,     3,     4,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    61,    -1,
      -1,    64,    23,    -1,    -1,    68,     1,    70,     3,     4,
      -1,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    15,    16,    -1,    23,    -1,
      51,    52,    -1,    23,    -1,    -1,     1,    -1,     3,     4,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      15,    16,    -1,    -1,    -1,    -1,    51,    52,    23,    -1,
      -1,    51,    52,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    61,    -1,    68,    64,    70,    -1,    -1,    68,     1,
      70,     3,     4,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    15,    16,    -1,    61,    -1,    -1,    64,
      -1,    23,    -1,    68,     1,    70,     3,     4,    -1,     1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    15,    16,    -1,    23,    -1,    -1,    51,
      52,    23,    -1,    -1,    -1,     1,    -1,     3,     4,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    15,
      16,    -1,    -1,    -1,    51,    52,    -1,    23,    -1,    51,
      52,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    61,
      -1,    68,    64,    70,    -1,    -1,    68,     1,    70,     3,
       4,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    61,    -1,    -1,    64,    23,
      -1,    -1,    68,     1,    70,     3,     4,    -1,     1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
      -1,    -1,    15,    16,    -1,    23,    -1,    51,    52,    -1,
      23,    -1,    -1,     1,    -1,     3,     4,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    15,    16,    -1,
      -1,    -1,    -1,    51,    52,    23,    -1,    -1,    51,    52,
      -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    61,    -1,
      68,    64,    70,    -1,    -1,    68,     1,    70,     3,     4,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      15,    16,    -1,    61,    -1,    -1,    64,    -1,    23,    -1,
      68,     1,    70,     3,     4,    -1,     1,    -1,     3,     4,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      15,    16,    -1,    23,    -1,    -1,    51,    52,    23,    -1,
      -1,    -1,     1,    -1,     3,     4,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    70,    15,    16,    -1,    -1,
      -1,    51,    52,    -1,    23,    -1,    51,    52,    -1,    -1,
      -1,    61,    -1,    -1,    64,    -1,    61,    -1,    68,    64,
      70,    -1,    -1,    68,     1,    70,     3,     4,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    15,    16,
      -1,    -1,    61,    -1,    -1,    64,    23,    -1,    -1,    68,
       1,    70,     3,     4,    -1,     1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    15,
      16,    -1,    23,    -1,    51,    52,    -1,    23,    -1,    -1,
       1,    -1,     3,     4,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    70,    15,    16,    -1,    -1,    -1,    -1,
      51,    52,    23,    -1,    -1,    51,    52,    -1,    -1,    -1,
      61,    -1,    -1,    64,    -1,    61,    -1,    68,    64,    70,
      -1,    -1,    68,     1,    70,     3,     4,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
      61,    -1,    -1,    64,    -1,    23,    -1,    68,     1,    70,
       3,     4,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    15,    16,    -1,
      23,    -1,    -1,    51,    52,    23,    -1,    -1,    -1,     1,
      -1,     3,     4,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    -1,    70,    15,    16,    -1,    -1,    -1,    51,    52,
      -1,    23,    -1,    51,    52,    -1,    -1,    -1,    61,    -1,
      -1,    64,    -1,    61,    -1,    68,    64,    70,    -1,    -1,
      68,     1,    70,     3,     4,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    61,
      -1,    -1,    64,    23,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    64,    15,    16,    -1,    68,    19,
      70,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    61,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,
      70,    15,    16,    -1,    18,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    61,    -1,    -1,
      64,    -1,    -1,    -1,    68,    -1,    70,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,    15,    16,    -1,
      68,    19,    70,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,     3,     4,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    -1,    15,    16,     3,
       4,    -1,    -1,    51,    52,    23,    -1,    -1,    -1,    -1,
      -1,    15,    16,    61,    -1,    -1,    64,    -1,    -1,    23,
      68,    -1,    70,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    54,    15,    16,    -1,
      -1,    -1,    -1,    61,    -1,    23,    64,    51,    52,    -1,
      68,    -1,    70,    -1,    -1,     3,     4,    61,    -1,    -1,
      64,    65,    -1,    -1,    68,    -1,    70,    15,    16,    -1,
      -1,    -1,    -1,    51,    52,    23,     3,     4,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    15,    16,
      68,    69,    70,    -1,    -1,    -1,    23,    -1,     3,     4,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      15,    16,    -1,    61,    -1,    -1,    64,    65,    23,    -1,
      68,    -1,    70,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,     1,    68,    -1,    70,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60,    10,    11,    12,    13,    14,    66,    67,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    -1,     1,    -1,
      -1,    -1,    66,    67,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    51,    52,    53,    54,    55,     1,    -1,
      -1,    59,    60,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    -1,    62,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    -1,    62,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,    -1,    62,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    15,    16,    19,    20,    21,    22,
      23,    24,    27,    30,    31,    36,    37,    40,    41,    42,
      51,    52,    61,    64,    68,    70,    73,    74,    75,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    90,
      97,    99,   100,   106,   107,   108,   109,   110,     3,     4,
      15,    16,    15,    16,     1,     3,    15,    16,    64,   101,
     108,   110,     1,     3,    39,    64,    76,     1,     3,    61,
      98,     1,   108,   108,    79,   108,   108,     1,   108,     1,
       5,     6,    65,   108,   115,   116,   118,     1,    69,   114,
     116,   118,     1,   108,     0,    74,    80,     5,     6,    66,
       3,     4,    15,    16,     7,     8,     9,    10,    11,    12,
      13,    14,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    59,    60,    61,    63,    68,
      71,   111,   115,    26,   102,   103,   104,     1,     5,     6,
      66,    67,    91,     1,     5,     6,    61,    63,    92,    63,
       1,     3,    46,    65,    77,    78,     1,     3,    63,     1,
       3,    91,    91,    91,    32,    89,     1,    62,    65,   116,
     115,    66,   117,    69,   116,   114,     1,   108,     1,   108,
       1,   108,     1,   108,     1,   108,     1,   108,     1,   108,
       1,   108,     1,   108,     1,   108,     1,   108,     1,   108,
       1,   108,     1,   108,     1,   108,     1,   108,     1,   108,
       1,   108,     1,   108,     1,   108,     1,   108,    50,    54,
      62,   108,   112,   113,     1,   108,   113,     3,    61,    65,
       1,   101,    25,   105,   104,    79,     1,    62,    77,    79,
       3,    63,     1,    65,    66,     1,    61,    92,     1,   108,
       1,    63,    18,    79,    18,    79,    28,    93,    94,    95,
      79,     1,    18,    63,    65,   118,    65,   116,   108,    69,
     118,    69,   116,     1,     3,     1,    62,    66,     1,    69,
     108,     1,    79,     1,    18,    92,    62,     1,    63,    78,
       1,    62,    77,    79,     1,   108,     1,    18,     1,    18,
     108,    29,    96,    95,     1,     3,    65,    69,    63,   112,
      62,    79,     1,    92,    92,    62,     1,    62,    91,    79,
       1,    18,     1,    61,    68,     1,   108,    79,    79,     1,
      92,    79,     1,    62,   113,     1,   113,    79,     1,    62,
       1,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    86,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     8,     7,     5,     4,     7,
       6,     2,     3,     4,     6,     3,     4,     5,     7,     1,
       2,     2,     2,     4,     3,     2,     2,     3,     4,     1,
       3,     1,     2,     1,     2,     2,     2,     2,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       4,     4,     2,     0,     6,     6,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     4,     2,     0,     4,
       5,     5,     5,     3,     1,     5,     4,     3,     2,     3,
       1,     4,     5,     2,     5,     5,     2,     5,     3,     2,
       0,     1,     1,     2,     2,     2,     2,     0,     2,     3,
       3,     7,     8,     8,     5,     8,     8,     7,     7,     6,
       5,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     3,     2,
       4,     4,     5,     2,     3,     4,     4,     5,     2,     2,
       1,     2,     3,     2,     3,     3,     3,     2,     4,     1,
       1,     4,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3
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
                       yystos[yyssp[yyi + 1 - yynrhs]],
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
      int yyn = yypact[*yyssp];
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
  case 2:
#line 156 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {mainAST = yyvsp[0].v.p;}
#line 2221 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 4:
#line 158 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
          {yyxpt(_("statement list or function definition"), yyvsp[0]);}
#line 2227 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 5:
#line 162 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                                {
     MacroFunctionDef *r = new MacroFunctionDef();
   if (yyvsp[-6].v.p)
   {
    r->returnVals = yyvsp[-6].v.p->toStringList();
   }
     r->name = yyvsp[-5].v.p->text;
     r->arguments = yyvsp[-3].v.p->toStringList();
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
  }
#line 2244 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 6:
#line 174 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                              {
     MacroFunctionDef *r = new MacroFunctionDef();
     r->name = yyvsp[-5].v.p->text;
     r->arguments = yyvsp[-3].v.p->toStringList();
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
   }
#line 2257 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 7:
#line 182 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                           {
     MacroFunctionDef *r = new MacroFunctionDef();
   if (yyvsp[-3].v.p)
   {
    r->returnVals = yyvsp[-3].v.p->toStringList();
   }
     r->name = yyvsp[-2].v.p->text;
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
   }
#line 2273 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 8:
#line 193 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                         {
     MacroFunctionDef *r = new MacroFunctionDef();
     r->name = yyvsp[-2].v.p->text;
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
   }
#line 2285 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 9:
#line 200 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                   {
     MacroFunctionDef *r = new MacroFunctionDef();
   if (yyvsp[-5].v.p)
   {
    r->returnVals = yyvsp[-5].v.p->toStringList();
   }
     r->name = yyvsp[-4].v.p->text;
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
   }
#line 2301 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 10:
#line 211 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                 {
     MacroFunctionDef *r = new MacroFunctionDef();
     r->name = yyvsp[-4].v.p->text;
     r->code = yyvsp[0].v.p;
     r->fileName = getParserFilenameW();
     chainFunction(r);
   }
#line 2313 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 11:
#line 218 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("legal function name or return declaration after 'function'"), yyvsp[-1]);}
#line 2319 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 12:
#line 219 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                         {yyxpt(_("argument list or statement list after identifier '") + 
  yyvsp[-1].v.p->text.c_str() + "'",yyvsp[-1]);}
#line 2326 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 13:
#line 221 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                              {yyxpt(_("(possibly empty) argument list after '('"),yyvsp[-1]);}
#line 2332 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 14:
#line 222 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                              {yyxpt(_("statement list after ')'"),yyvsp[-1]);}
#line 2338 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 15:
#line 223 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                      {yyxpt(_("function name for function declared"),yyvsp[-2]);}
#line 2344 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 16:
#line 224 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                           {yyxpt(_("argument list or statement list following function name :") + 
  yyvsp[-1].v.p->text.c_str(), yyvsp[-1]);}
#line 2351 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 17:
#line 226 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                {yyxpt(_("(possibly empty) argument list after '('"),yyvsp[-1]);}
#line 2357 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 18:
#line 227 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                {yyxpt(_("statement list after ')'"),yyvsp[-1]);}
#line 2363 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 21:
#line 236 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyval.v.p = yyvsp[-1].v.p;}
#line 2369 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 22:
#line 237 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
            {yyval.v.p = yyvsp[-1].v.p;}
#line 2375 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 23:
#line 238 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                           {yyval.v.p = yyvsp[-2].v.p;}
#line 2381 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 24:
#line 239 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyval.v.p = nullptr;}
#line 2387 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 25:
#line 240 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyxpt(_("an '=' symbol after identifier in return declaration"),yyvsp[-1]);}
#line 2393 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 26:
#line 241 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
            {yyxpt(_("a valid list of return arguments in return declaration"),yyvsp[-1]);}
#line 2399 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 27:
#line 242 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                         {yyxpt(_("matching ']' in return declaration for '['"),yyvsp[-2]);}
#line 2405 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 28:
#line 243 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                             {yyxpt(_("an '=' symbol after return declaration"),yyvsp[-1]);}
#line 2411 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 29:
#line 247 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
           {yyval.v.p = yyvsp[0].v.p;}
#line 2417 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 30:
#line 248 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                              {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 2423 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 32:
#line 252 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {
  yyval.v.p = yyvsp[0].v.p;
  char *b = (char*) malloc(yyvsp[0].v.p->text.size() + 2);
  b[0] = '&';
  strcpy(b+1, yyvsp[0].v.p->text.c_str());
  yyval.v.p->text = b;
  free(b);
  }
#line 2436 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 33:
#line 264 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
             {yyval.v.p = allocateAbstractSyntaxTree(OP_BLOCK,yyvsp[0].v.p,yyvsp[0].v.p->context());}
#line 2442 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 34:
#line 265 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                           {yyval.v.p = yyvsp[-1].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 2448 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 35:
#line 269 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                           {
        yyval.v.p = allocateAbstractSyntaxTree(OP_QSTATEMENT,NULL,yyvsp[0].v.i);
      yyval.v.p->down = yyvsp[-1].v.p;
   }
#line 2457 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 36:
#line 273 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                            {
      yyval.v.p = allocateAbstractSyntaxTree(OP_RSTATEMENT,NULL,yyvsp[0].v.i);
            yyval.v.p->down = yyvsp[-1].v.p;
   }
#line 2466 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 37:
#line 277 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {
      yyval.v.p = allocateAbstractSyntaxTree(OP_RSTATEMENT,NULL,yyvsp[0].v.i);
      yyval.v.p->down = yyvsp[-1].v.p;
   }
#line 2475 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 40:
#line 286 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
    {yyval.v.p = allocateAbstractSyntaxTree(null_node,"",-1);}
#line 2481 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 56:
#line 307 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context());}
#line 2487 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 57:
#line 308 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context());}
#line 2493 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 58:
#line 309 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context());}
#line 2499 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 59:
#line 310 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                 {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context());}
#line 2505 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 60:
#line 311 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context());}
#line 2511 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 61:
#line 312 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyval.v.p = allocateAbstractSyntaxTree(OP_SCALL,yyvsp[-1].v.p,yyvsp[0].v.p,yyvsp[-1].v.p->context()); }
#line 2517 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 62:
#line 313 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                  {yyvsp[-1].v.p->addChild(yyvsp[0].v.p);}
#line 2523 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 63:
#line 314 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                     {yyvsp[-1].v.p->addChild(yyvsp[0].v.p);}
#line 2529 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 64:
#line 315 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                 {yyvsp[-1].v.p->addChild(yyvsp[0].v.p);}
#line 2535 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 65:
#line 316 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                   {yyvsp[-1].v.p->addChild(yyvsp[0].v.p);}
#line 2541 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 70:
#line 335 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
  { 
    yyval.v.p = yyvsp[-3].v.p;
    yyval.v.p->addChild(yyvsp[-2].v.p);
    if (yyvsp[-1].v.p != nullptr) yyval.v.p->addChild(yyvsp[-1].v.p);
  }
#line 2551 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 71:
#line 341 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
  {yyxpt(_("matching 'end' to 'try' clause from line ") + decodeline(yyvsp[-3]),yyvsp[0]);}
#line 2557 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 72:
#line 345 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                      {yyval.v.p = yyvsp[0].v.p;}
#line 2563 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 73:
#line 346 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
    {yyval.v.p = nullptr;}
#line 2569 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 74:
#line 350 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                  {
    yyval.v.p = yyvsp[-5].v.p;
    yyval.v.p->addChild(yyvsp[-4].v.p); 
    if (yyvsp[-2].v.p != nullptr) yyval.v.p->addChild(yyvsp[-2].v.p); 
    if (yyvsp[-1].v.p != nullptr) yyval.v.p->addChild(yyvsp[-1].v.p);
  }
#line 2580 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 75:
#line 356 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                      {
          yyxpt(_("matching 'end' to 'switch' clause from line ") + decodeline(yyvsp[-5]),yyvsp[0]);}
#line 2587 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 82:
#line 368 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
  {yyval.v.p = nullptr;}
#line 2593 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 84:
#line 372 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {
    yyval.v.p = allocateAbstractSyntaxTree(OP_CASEBLOCK,yyvsp[0].v.p,yyvsp[0].v.p->context());
  }
#line 2601 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 85:
#line 375 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                         {
    yyval.v.p = yyvsp[-1].v.p; yyval.v.p->addChild(yyvsp[0].v.p);
  }
#line 2609 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 86:
#line 381 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                               {
    yyval.v.p = yyvsp[-3].v.p; yyval.v.p->addChild(yyvsp[-2].v.p); yyval.v.p->addChild(yyvsp[0].v.p);
  }
#line 2617 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 87:
#line 387 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                          {
    yyval.v.p = yyvsp[0].v.p;
  }
#line 2625 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 88:
#line 390 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
  {
    yyval.v.p = nullptr;
  }
#line 2633 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 89:
#line 396 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                  {
   yyval.v.p = nullptr;
  }
#line 2641 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 90:
#line 399 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                                  {
    yyval.v.p = yyvsp[-4].v.p;
    yyval.v.p->addChild(yyvsp[-3].v.p);
    yyval.v.p->addChild(yyvsp[-1].v.p);
  }
#line 2651 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 91:
#line 405 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
           {yyxpt(_("'end' to match 'for' statement from line ") + decodeline(yyvsp[-4]),yyvsp[0]);}
#line 2657 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 92:
#line 409 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                         {yyval.v.p = yyvsp[-3].v.p; yyval.v.p->addChild(yyvsp[-1].v.p);}
#line 2663 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 93:
#line 410 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 2669 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 94:
#line 411 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
          {yyval.v.p = yyvsp[0].v.p; 
        yyval.v.p->addChild(allocateAbstractSyntaxTree(OP_RHS, allocateAbstractSyntaxTree(id_node,yyvsp[0].v.p->text.c_str(), yyvsp[0].v.p->context()),yyvsp[0].v.p->context())); }
#line 2676 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 95:
#line 413 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                             {yyxpt(_("matching right parenthesis"),yyvsp[-4]);}
#line 2682 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 96:
#line 414 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("indexing expression"),yyvsp[-1]);}
#line 2688 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 97:
#line 415 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("equals operator after loop index"),yyvsp[-1]);}
#line 2694 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 98:
#line 416 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyxpt(_("identifier that is the loop variable"),yyvsp[-1]);}
#line 2700 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 99:
#line 417 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("indexing expression"),yyvsp[-1]);}
#line 2706 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 100:
#line 418 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
          {yyxpt(_("identifier or assignment (id = expr) after 'for' "),yyvsp[0]);}
#line 2712 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 101:
#line 422 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                      {
    yyval.v.p = nullptr;
  }
#line 2720 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 102:
#line 425 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                      {
    yyval.v.p = yyvsp[-4].v.p;
    yyval.v.p->addChild(yyvsp[-3].v.p);
    yyval.v.p->addChild(yyvsp[-1].v.p);
  }
#line 2730 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 103:
#line 430 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyxpt(_("test expression after 'while'"),yyvsp[-1]);}
#line 2736 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 104:
#line 432 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
  {yyxpt(_("'end' to match 'while' statement from line ") + decodeline(yyvsp[-4]),yyvsp[0]);}
#line 2742 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 105:
#line 436 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                        {
    yyval.v.p = yyvsp[-4].v.p;
    yyval.v.p->addChild(yyvsp[-3].v.p);
    if (yyvsp[-2].v.p != nullptr) yyval.v.p->addChild(yyvsp[-2].v.p); 
    if (yyvsp[-1].v.p != nullptr) yyval.v.p->addChild(yyvsp[-1].v.p);
  }
#line 2753 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 106:
#line 442 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
             {yyxpt(_("condition expression for 'if'"),yyvsp[-1]);}
#line 2759 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 107:
#line 443 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                            {yyxpt(_("'end' to match 'if' statement from line ") + decodeline(yyvsp[-4]),yyvsp[0]);}
#line 2765 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 108:
#line 447 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                          {
    yyval.v.p = allocateAbstractSyntaxTree(OP_CSTAT,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-2].v.p->context());
  }
#line 2773 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 109:
#line 450 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
               {yyxpt(_("valid list of statements after condition"),yyvsp[0]);}
#line 2779 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 110:
#line 454 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyval.v.p = nullptr;}
#line 2785 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 112:
#line 459 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {
    yyval.v.p = allocateAbstractSyntaxTree(OP_ELSEIFBLOCK,yyvsp[0].v.p,yyvsp[0].v.p->context());
  }
#line 2793 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 113:
#line 462 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                        {
    yyval.v.p = yyvsp[-1].v.p; yyval.v.p->addChild(yyvsp[0].v.p);
  }
#line 2801 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 114:
#line 468 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                              {
    yyval.v.p = yyvsp[0].v.p;
  }
#line 2809 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 115:
#line 471 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                 {yyxpt(_("test condition for 'elseif' clause"),yyvsp[-1]);}
#line 2815 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 116:
#line 474 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                     {
    yyval.v.p = yyvsp[0].v.p;
  }
#line 2823 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 117:
#line 477 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyval.v.p = nullptr;}
#line 2829 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 118:
#line 478 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
               {yyxpt(_("statement list for 'else' clause"), yyvsp[-1]);}
#line 2835 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 119:
#line 482 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_ASSIGN,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2841 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 120:
#line 483 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                          {yyxpt(_("expression in assignment"),yyvsp[-1]);}
#line 2847 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 121:
#line 487 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                        {
  yyval.v.p = allocateAbstractSyntaxTree(OP_MULTICALL,yyvsp[-5].v.p,yyvsp[-2].v.p,yyvsp[-6].v.i);
  }
#line 2855 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 122:
#line 490 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                    {
    yyvsp[-3].v.p->addChild(allocateAbstractSyntaxTree(OP_PARENS,yyvsp[-1].v.p,yyvsp[-2].v.i));
    yyval.v.p = allocateAbstractSyntaxTree(OP_MULTICALL,yyvsp[-6].v.p,yyvsp[-3].v.p,yyvsp[-7].v.i);
  }
#line 2864 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 123:
#line 494 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                    {
    yyvsp[-3].v.p->addChild(allocateAbstractSyntaxTree(OP_PARENS,yyvsp[-1].v.p,yyvsp[-2].v.i));
    yyval.v.p = allocateAbstractSyntaxTree(OP_MULTICALL,yyvsp[-6].v.p,yyvsp[-3].v.p,yyvsp[-7].v.i);
  }
#line 2873 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 124:
#line 498 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                 {
    yyvsp[0].v.p->addChild(allocateAbstractSyntaxTree(OP_PARENS,NULL,-1));
    yyval.v.p = allocateAbstractSyntaxTree(OP_MULTICALL,yyvsp[-3].v.p,yyvsp[0].v.p,yyvsp[-4].v.i);
  }
#line 2882 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 125:
#line 502 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                      {yyxpt(_("matching right bracket"), yyvsp[-2]);}
#line 2888 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 126:
#line 503 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                      {yyxpt(_("matching right parenthesis"), yyvsp[-2]);}
#line 2894 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 127:
#line 504 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                            {yyxpt(_("indexing list"), yyvsp[-1]);}
#line 2900 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 128:
#line 505 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                            {yyxpt(_("indexing list"), yyvsp[-1]);}
#line 2906 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 129:
#line 506 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                       {yyxpt(_("left parenthesis"),yyvsp[-1]);}
#line 2912 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 130:
#line 507 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                {yyxpt("identifier",yyvsp[-1]);}
#line 2918 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 131:
#line 511 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyval.v.p = allocateAbstractSyntaxTree(OP_COLON,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2924 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 132:
#line 512 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after ':'"), yyvsp[-1]);}
#line 2930 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 134:
#line 514 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_PLUS,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2936 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 135:
#line 515 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '+'"), yyvsp[-1]);}
#line 2942 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 136:
#line 516 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_SUBTRACT,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2948 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 137:
#line 517 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '-'"), yyvsp[-1]);}
#line 2954 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 138:
#line 518 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_TIMES,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2960 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 139:
#line 519 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '*'"),yyvsp[-1]);}
#line 2966 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 140:
#line 520 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_RDIV,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2972 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 141:
#line 521 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '/'"),yyvsp[-1]);}
#line 2978 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 142:
#line 522 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyval.v.p = allocateAbstractSyntaxTree(OP_LDIV,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2984 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 143:
#line 523 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("an expression after '\\'"),yyvsp[-1]);}
#line 2990 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 144:
#line 524 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_OR,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 2996 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 145:
#line 525 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '|'"),yyvsp[-1]);}
#line 3002 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 146:
#line 526 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_AND,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3008 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 147:
#line 527 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '&'"),yyvsp[-1]);}
#line 3014 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 148:
#line 528 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_SOR,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3020 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 149:
#line 529 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '||'"),yyvsp[-1]);}
#line 3026 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 150:
#line 530 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyval.v.p = allocateAbstractSyntaxTree(OP_SAND,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3032 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 151:
#line 531 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("an expression after '&&'"),yyvsp[-1]);}
#line 3038 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 152:
#line 532 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_LT,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3044 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 153:
#line 533 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '<'"),yyvsp[-1]);}
#line 3050 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 154:
#line 534 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_LEQ,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3056 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 155:
#line 535 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '<='"),yyvsp[-1]);}
#line 3062 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 156:
#line 536 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_GT,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3068 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 157:
#line 537 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '>'"),yyvsp[-1]);}
#line 3074 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 158:
#line 538 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_GEQ,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3080 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 159:
#line 539 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '>='"),yyvsp[-1]);}
#line 3086 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 160:
#line 540 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_EQ,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3092 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 161:
#line 541 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '=='"),yyvsp[-1]);}
#line 3098 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 162:
#line 542 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_NEQ,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3104 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 163:
#line 543 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyxpt(_("an expression after '~='"),yyvsp[-1]);}
#line 3110 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 164:
#line 544 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT_TIMES,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3116 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 165:
#line 545 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("an expression after '.*'"), yyvsp[-1]);}
#line 3122 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 166:
#line 546 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT_RDIV,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3128 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 167:
#line 547 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("an expression after './'"),yyvsp[-1]);}
#line 3134 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 168:
#line 548 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                      {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT_LDIV,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3140 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 169:
#line 549 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyxpt(_("an expression after '.\\'"),yyvsp[-1]);}
#line 3146 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 170:
#line 550 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_NEG,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3152 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 171:
#line 551 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_POS, yyvsp[0].v.p, yyvsp[-1].v.i);}
#line 3158 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 172:
#line 552 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_NOT,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3164 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 173:
#line 553 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("an expression after logical not"),yyvsp[0]);}
#line 3170 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 174:
#line 554 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                   {yyval.v.p = allocateAbstractSyntaxTree(OP_POWER,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3176 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 175:
#line 555 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("an expression after '^'"),yyvsp[-1]);}
#line 3182 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 176:
#line 556 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT_POWER,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3188 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 177:
#line 557 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("an expression after '.^'"),yyvsp[-1]);}
#line 3194 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 178:
#line 558 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_TRANSPOSE,yyvsp[-1].v.p,yyvsp[0].v.i);}
#line 3200 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 179:
#line 559 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT_TRANSPOSE,yyvsp[-1].v.p,yyvsp[0].v.i);}
#line 3206 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 180:
#line 560 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = yyvsp[-1].v.p;}
#line 3212 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 181:
#line 561 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("a right parenthesis after expression to match this one"),yyvsp[-2]);}
#line 3218 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 182:
#line 562 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
               {yyxpt(_("an expression after left parenthesis"),yyvsp[-1]);}
#line 3224 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 187:
#line 570 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                {yyval.v.p = allocateAbstractSyntaxTree(OP_RHS,yyvsp[0].v.p,yyvsp[0].v.p->context());}
#line 3230 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 188:
#line 571 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                      {yyval.v.p = yyvsp[-1].v.p;}
#line 3236 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 189:
#line 572 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyxpt(_("a matrix definition followed by a right bracket"),yyvsp[-1]);}
#line 3242 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 190:
#line 573 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                   {yyval.v.p = yyvsp[-1].v.p;}
#line 3248 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 191:
#line 574 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                   {yyval.v.p = yyvsp[-2].v.p;}
#line 3254 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 192:
#line 575 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                                {yyval.v.p = yyvsp[-2].v.p;}
#line 3260 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 193:
#line 576 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_EMPTY,NULL,yyvsp[-1].v.i);}
#line 3266 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 194:
#line 577 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyval.v.p = yyvsp[-1].v.p;}
#line 3272 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 195:
#line 578 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                 {yyval.v.p = yyvsp[-1].v.p;}
#line 3278 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 196:
#line 579 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                 {yyval.v.p = yyvsp[-2].v.p;}
#line 3284 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 197:
#line 580 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                              {yyval.v.p = yyvsp[-2].v.p;}
#line 3290 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 198:
#line 581 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                  {yyval.v.p = allocateAbstractSyntaxTree(OP_EMPTY_CELL,NULL,yyvsp[-1].v.i);}
#line 3296 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 199:
#line 582 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyxpt(_("a cell-array definition followed by a right brace"),yyvsp[-1]);}
#line 3302 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 201:
#line 586 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyval.v.p = yyvsp[-1].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 3308 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 202:
#line 589 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                    {yyval.v.p = allocateAbstractSyntaxTree(OP_PARENS,yyvsp[-1].v.p,yyvsp[-2].v.i); }
#line 3314 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 203:
#line 590 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
            {yyval.v.p = allocateAbstractSyntaxTree(OP_PARENS,NULL,yyvsp[-1].v.i); }
#line 3320 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 204:
#line 591 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                              {yyxpt(_("matching right parenthesis"),yyvsp[-2]);}
#line 3326 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 205:
#line 592 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                      {yyval.v.p = allocateAbstractSyntaxTree(OP_BRACES,yyvsp[-1].v.p,yyvsp[-2].v.i); }
#line 3332 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 206:
#line 593 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                              {yyxpt(_("matching right brace"),yyvsp[-2]);}
#line 3338 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 207:
#line 594 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyval.v.p = allocateAbstractSyntaxTree(OP_DOT,yyvsp[0].v.p,yyvsp[-1].v.i); }
#line 3344 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 208:
#line 595 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                           {yyval.v.p = allocateAbstractSyntaxTree(OP_DOTDYN,yyvsp[-1].v.p,yyvsp[-3].v.i);}
#line 3350 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 210:
#line 599 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
        {yyval.v.p = allocateAbstractSyntaxTree(OP_ALL,NULL,yyvsp[0].v.i);}
#line 3356 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 211:
#line 600 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                       {yyval.v.p = allocateAbstractSyntaxTree(OP_KEYWORD,yyvsp[-2].v.p,yyvsp[0].v.p,yyvsp[-3].v.i);}
#line 3362 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 212:
#line 601 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                        {yyxpt(_("expecting expression after '=' in keyword assignment"),yyvsp[-1]);}
#line 3368 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 213:
#line 602 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyval.v.p = allocateAbstractSyntaxTree(OP_KEYWORD,yyvsp[0].v.p,yyvsp[-1].v.i);}
#line 3374 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 214:
#line 603 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
              {yyxpt(_("expecting keyword identifier after '/' in keyword assignment"),yyvsp[-1]);}
#line 3380 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 216:
#line 607 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                               {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addPeer(yyvsp[0].v.p);}
#line 3386 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 217:
#line 610 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
         {yyval.v.p = allocateAbstractSyntaxTree(OP_BRACES,yyvsp[0].v.p,yyvsp[0].v.p->context());}
#line 3392 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 218:
#line 611 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 3398 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 219:
#line 614 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
         {yyval.v.p = allocateAbstractSyntaxTree(OP_BRACKETS,yyvsp[0].v.p,yyvsp[0].v.p->context());}
#line 3404 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 220:
#line 615 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                                  {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 3410 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 224:
#line 625 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
            {yyval.v.p = allocateAbstractSyntaxTree(OP_SEMICOLON,yyvsp[0].v.p,yyvsp[0].v.p->context());}
#line 3416 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;

  case 225:
#line 626 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"
                             {yyval.v.p = yyvsp[-2].v.p; yyval.v.p->addChild(yyvsp[0].v.p);}
#line 3422 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"
    break;


#line 3426 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.cpp"

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
  return yyresult;
}
#line 628 "..\\..\\NelSon\\modules\\interpreter\\src\\grammar\\NelSonParser.yxx"


namespace Nelson {
  
  void resetParser() {
    if (mainAST)
    {
      mainAST = nullptr;
    }
    if (mainMDef)
    {
      mainMDef = nullptr;
    }
  }
  
  ASTPtr getParsedScriptBlock() {
    return mainAST;
  }
  
  MacroFunctionDef* getParsedFunctionDef() {
    return mainMDef;
  }
  
  ParserState parseState() {
    if (mainAST != nullptr) {
      return ScriptBlock;
    }
    else {
      return FuncDef;
    }
  }
  
  ParserState parseString(const std::string &txt) {
    resetParser();
    interactiveMode = true;
    setLexBuffer(txt);
    yyparse();
    return parseState();
  }
  
  ParserState parseFile(FILE *fp, const std::string &fname) {
    resetParser();
    interactiveMode = false;
    setParserFilename(fname);
    setLexFile(fp);
    yyparse();
    ParserState pstate = parseState();
    setParserFilename("");
    return pstate;
  }

}
// clang-format on
