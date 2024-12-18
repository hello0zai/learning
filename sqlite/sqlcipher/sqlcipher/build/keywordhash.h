/***** This file contains automatically generated code ******
**
** The code in this file has been automatically generated by
**
**   sqlite/tool/mkkeywordhash.c
**
** The code in this file implements a function that determines whether
** or not a given identifier is really an SQL keyword.  The same thing
** might be implemented more directly using a hand-written hash table.
** But by using this automatically generated code, the size of the code
** is substantially reduced.  This is important for embedded applications
** on platforms with limited memory.
*/
/* Hash score: 231 */
/* zKWText[] encodes 1007 bytes of keyword text in 667 bytes */
/*   REINDEXEDESCAPEACHECKEYBEFOREIGNOREGEXPLAINSTEADDATABASELECT       */
/*   ABLEFTHENDEFERRABLELSEXCLUDELETEMPORARYISNULLSAVEPOINTERSECT       */
/*   IESNOTNULLIKEXCEPTRANSACTIONATURALTERAISEXCLUSIVEXISTS             */
/*   CONSTRAINTOFFSETRIGGERANGENERATEDETACHAVINGLOBEGINNEREFERENCES     */
/*   UNIQUERYWITHOUTERELEASEATTACHBETWEENOTHINGROUPSCASCADEFAULT        */
/*   CASECOLLATECREATECURRENT_DATEIMMEDIATEJOINSERTMATCHPLANALYZE       */
/*   PRAGMATERIALIZEDEFERREDISTINCTUPDATEVALUESVIRTUALWAYSWHENWHERE     */
/*   CURSIVEABORTAFTERENAMEANDROPARTITIONAUTOINCREMENTCASTCOLUMN        */
/*   COMMITCONFLICTCROSSCURRENT_TIMESTAMPRECEDINGFAILASTFILTER          */
/*   EPLACEFIRSTFOLLOWINGFROMFULLIMITIFORDERESTRICTOTHERSOVER           */
/*   ETURNINGRIGHTROLLBACKROWSUNBOUNDEDUNIONUSINGVACUUMVIEWINDOWBY      */
/*   INITIALLYPRIMARY                                                   */
static const char zKWText[666] = {
  'R','E','I','N','D','E','X','E','D','E','S','C','A','P','E','A','C','H',
  'E','C','K','E','Y','B','E','F','O','R','E','I','G','N','O','R','E','G',
  'E','X','P','L','A','I','N','S','T','E','A','D','D','A','T','A','B','A',
  'S','E','L','E','C','T','A','B','L','E','F','T','H','E','N','D','E','F',
  'E','R','R','A','B','L','E','L','S','E','X','C','L','U','D','E','L','E',
  'T','E','M','P','O','R','A','R','Y','I','S','N','U','L','L','S','A','V',
  'E','P','O','I','N','T','E','R','S','E','C','T','I','E','S','N','O','T',
  'N','U','L','L','I','K','E','X','C','E','P','T','R','A','N','S','A','C',
  'T','I','O','N','A','T','U','R','A','L','T','E','R','A','I','S','E','X',
  'C','L','U','S','I','V','E','X','I','S','T','S','C','O','N','S','T','R',
  'A','I','N','T','O','F','F','S','E','T','R','I','G','G','E','R','A','N',
  'G','E','N','E','R','A','T','E','D','E','T','A','C','H','A','V','I','N',
  'G','L','O','B','E','G','I','N','N','E','R','E','F','E','R','E','N','C',
  'E','S','U','N','I','Q','U','E','R','Y','W','I','T','H','O','U','T','E',
  'R','E','L','E','A','S','E','A','T','T','A','C','H','B','E','T','W','E',
  'E','N','O','T','H','I','N','G','R','O','U','P','S','C','A','S','C','A',
  'D','E','F','A','U','L','T','C','A','S','E','C','O','L','L','A','T','E',
  'C','R','E','A','T','E','C','U','R','R','E','N','T','_','D','A','T','E',
  'I','M','M','E','D','I','A','T','E','J','O','I','N','S','E','R','T','M',
  'A','T','C','H','P','L','A','N','A','L','Y','Z','E','P','R','A','G','M',
  'A','T','E','R','I','A','L','I','Z','E','D','E','F','E','R','R','E','D',
  'I','S','T','I','N','C','T','U','P','D','A','T','E','V','A','L','U','E',
  'S','V','I','R','T','U','A','L','W','A','Y','S','W','H','E','N','W','H',
  'E','R','E','C','U','R','S','I','V','E','A','B','O','R','T','A','F','T',
  'E','R','E','N','A','M','E','A','N','D','R','O','P','A','R','T','I','T',
  'I','O','N','A','U','T','O','I','N','C','R','E','M','E','N','T','C','A',
  'S','T','C','O','L','U','M','N','C','O','M','M','I','T','C','O','N','F',
  'L','I','C','T','C','R','O','S','S','C','U','R','R','E','N','T','_','T',
  'I','M','E','S','T','A','M','P','R','E','C','E','D','I','N','G','F','A',
  'I','L','A','S','T','F','I','L','T','E','R','E','P','L','A','C','E','F',
  'I','R','S','T','F','O','L','L','O','W','I','N','G','F','R','O','M','F',
  'U','L','L','I','M','I','T','I','F','O','R','D','E','R','E','S','T','R',
  'I','C','T','O','T','H','E','R','S','O','V','E','R','E','T','U','R','N',
  'I','N','G','R','I','G','H','T','R','O','L','L','B','A','C','K','R','O',
  'W','S','U','N','B','O','U','N','D','E','D','U','N','I','O','N','U','S',
  'I','N','G','V','A','C','U','U','M','V','I','E','W','I','N','D','O','W',
  'B','Y','I','N','I','T','I','A','L','L','Y','P','R','I','M','A','R','Y',
};
/* aKWHash[i] is the hash value for the i-th keyword */
static const unsigned char aKWHash[127] = {
    84,  92, 134,  82, 105,  29,   0,   0,  94,   0,  85,  72,   0,
    53,  35,  86,  15,   0,  42,  97,  54,  89, 135,  19,   0,   0,
   140,   0,  40, 129,   0,  22, 107,   0,   9,   0,   0, 123,  80,
     0,  78,   6,   0,  65, 103, 147,   0, 136, 115,   0,   0,  48,
     0,  90,  24,   0,  17,   0,  27,  70,  23,  26,   5,  60, 142,
   110, 122,   0,  73,  91,  71, 145,  61, 120,  74,   0,  49,   0,
    11,  41,   0, 113,   0,   0,   0, 109,  10, 111, 116, 125,  14,
    50, 124,   0, 100,   0,  18, 121, 144,  56, 130, 139,  88,  83,
    37,  30, 126,   0,   0, 108,  51, 131, 128,   0,  34,   0,   0,
   132,   0,  98,  38,  39,   0,  20,  45, 117,  93,
};
/* aKWNext[] forms the hash collision chain.  If aKWHash[i]==0
** then the i-th keyword has no more hash collisions.  Otherwise,
** the next keyword with the same hash is aKWHash[i]-1. */
static const unsigned char aKWNext[148] = {0,
     0,   0,   0,   0,   4,   0,  43,   0,   0, 106, 114,   0,   0,
     0,   2,   0,   0, 143,   0,   0,   0,  13,   0,   0,   0,   0,
   141,   0,   0, 119,  52,   0,   0, 137,  12,   0,   0,  62,   0,
   138,   0, 133,   0,   0,  36,   0,   0,  28,  77,   0,   0,   0,
     0,  59,   0,  47,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     0,  69,   0,   0,   0,   0,   0, 146,   3,   0,  58,   0,   1,
    75,   0,   0,   0,  31,   0,   0,   0,   0,   0, 127,   0, 104,
     0,  64,  66,  63,   0,   0,   0,   0,   0,  46,   0,  16,   8,
     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  81, 101,   0,
   112,  21,   7,  67,   0,  79,  96, 118,   0,   0,  68,   0,   0,
    99,  44,   0,  55,   0,  76,   0,  95,  32,  33,  57,  25,   0,
   102,   0,   0,  87,
};
/* aKWLen[i] is the length (in bytes) of the i-th keyword */
static const unsigned char aKWLen[148] = {0,
     7,   7,   5,   4,   6,   4,   5,   3,   6,   7,   3,   6,   6,
     7,   7,   3,   8,   2,   6,   5,   4,   4,   3,  10,   4,   7,
     6,   9,   4,   2,   6,   5,   9,   9,   4,   7,   3,   2,   4,
     4,   6,  11,   6,   2,   7,   5,   5,   9,   6,  10,   4,   6,
     2,   3,   7,   5,   9,   6,   6,   4,   5,   5,  10,   6,   5,
     7,   4,   5,   7,   6,   7,   7,   6,   5,   7,   3,   7,   4,
     7,   6,  12,   9,   4,   6,   5,   4,   7,   6,  12,   8,   8,
     2,   6,   6,   7,   6,   4,   5,   9,   5,   5,   6,   3,   4,
     9,  13,   2,   2,   4,   6,   6,   8,   5,  17,  12,   7,   9,
     4,   4,   6,   7,   5,   9,   4,   4,   5,   2,   5,   8,   6,
     4,   9,   5,   8,   4,   3,   9,   5,   5,   6,   4,   6,   2,
     2,   9,   3,   7,
};
/* aKWOffset[i] is the index into zKWText[] of the start of
** the text for the i-th keyword. */
static const unsigned short int aKWOffset[148] = {0,
     0,   2,   2,   8,   9,  14,  16,  20,  23,  25,  25,  29,  33,
    36,  41,  46,  48,  53,  54,  59,  62,  65,  67,  69,  78,  81,
    86,  90,  90,  94,  99, 101, 105, 111, 119, 123, 123, 123, 126,
   129, 132, 137, 142, 146, 147, 152, 156, 160, 168, 174, 181, 184,
   184, 187, 189, 195, 198, 206, 211, 216, 219, 222, 226, 236, 239,
   244, 244, 248, 252, 259, 265, 271, 277, 277, 283, 284, 288, 295,
   299, 306, 312, 324, 333, 335, 341, 346, 348, 355, 359, 370, 377,
   378, 385, 391, 397, 402, 408, 412, 415, 424, 429, 433, 439, 441,
   444, 453, 455, 457, 466, 470, 476, 482, 490, 495, 495, 495, 511,
   520, 523, 527, 532, 539, 544, 553, 557, 560, 565, 567, 571, 579,
   585, 588, 597, 602, 610, 610, 614, 623, 628, 633, 639, 642, 645,
   648, 650, 655, 659,
};
/* aKWCode[i] is the parser symbol code for the i-th keyword */
static const unsigned char aKWCode[148] = {0,
  TK_REINDEX,    TK_INDEXED,    TK_INDEX,      TK_DESC,       TK_ESCAPE,     
  TK_EACH,       TK_CHECK,      TK_KEY,        TK_BEFORE,     TK_FOREIGN,    
  TK_FOR,        TK_IGNORE,     TK_LIKE_KW,    TK_EXPLAIN,    TK_INSTEAD,    
  TK_ADD,        TK_DATABASE,   TK_AS,         TK_SELECT,     TK_TABLE,      
  TK_JOIN_KW,    TK_THEN,       TK_END,        TK_DEFERRABLE, TK_ELSE,       
  TK_EXCLUDE,    TK_DELETE,     TK_TEMP,       TK_TEMP,       TK_OR,         
  TK_ISNULL,     TK_NULLS,      TK_SAVEPOINT,  TK_INTERSECT,  TK_TIES,       
  TK_NOTNULL,    TK_NOT,        TK_NO,         TK_NULL,       TK_LIKE_KW,    
  TK_EXCEPT,     TK_TRANSACTION,TK_ACTION,     TK_ON,         TK_JOIN_KW,    
  TK_ALTER,      TK_RAISE,      TK_EXCLUSIVE,  TK_EXISTS,     TK_CONSTRAINT, 
  TK_INTO,       TK_OFFSET,     TK_OF,         TK_SET,        TK_TRIGGER,    
  TK_RANGE,      TK_GENERATED,  TK_DETACH,     TK_HAVING,     TK_LIKE_KW,    
  TK_BEGIN,      TK_JOIN_KW,    TK_REFERENCES, TK_UNIQUE,     TK_QUERY,      
  TK_WITHOUT,    TK_WITH,       TK_JOIN_KW,    TK_RELEASE,    TK_ATTACH,     
  TK_BETWEEN,    TK_NOTHING,    TK_GROUPS,     TK_GROUP,      TK_CASCADE,    
  TK_ASC,        TK_DEFAULT,    TK_CASE,       TK_COLLATE,    TK_CREATE,     
  TK_CTIME_KW,   TK_IMMEDIATE,  TK_JOIN,       TK_INSERT,     TK_MATCH,      
  TK_PLAN,       TK_ANALYZE,    TK_PRAGMA,     TK_MATERIALIZED, TK_DEFERRED,   
  TK_DISTINCT,   TK_IS,         TK_UPDATE,     TK_VALUES,     TK_VIRTUAL,    
  TK_ALWAYS,     TK_WHEN,       TK_WHERE,      TK_RECURSIVE,  TK_ABORT,      
  TK_AFTER,      TK_RENAME,     TK_AND,        TK_DROP,       TK_PARTITION,  
  TK_AUTOINCR,   TK_TO,         TK_IN,         TK_CAST,       TK_COLUMNKW,   
  TK_COMMIT,     TK_CONFLICT,   TK_JOIN_KW,    TK_CTIME_KW,   TK_CTIME_KW,   
  TK_CURRENT,    TK_PRECEDING,  TK_FAIL,       TK_LAST,       TK_FILTER,     
  TK_REPLACE,    TK_FIRST,      TK_FOLLOWING,  TK_FROM,       TK_JOIN_KW,    
  TK_LIMIT,      TK_IF,         TK_ORDER,      TK_RESTRICT,   TK_OTHERS,     
  TK_OVER,       TK_RETURNING,  TK_JOIN_KW,    TK_ROLLBACK,   TK_ROWS,       
  TK_ROW,        TK_UNBOUNDED,  TK_UNION,      TK_USING,      TK_VACUUM,     
  TK_VIEW,       TK_WINDOW,     TK_DO,         TK_BY,         TK_INITIALLY,  
  TK_ALL,        TK_PRIMARY,    
};
/* Hash table decoded:
**   0: INSERT
**   1: IS
**   2: ROLLBACK TRIGGER
**   3: IMMEDIATE
**   4: PARTITION
**   5: TEMP
**   6:
**   7:
**   8: VALUES WITHOUT
**   9:
**  10: MATCH
**  11: NOTHING
**  12:
**  13: OF
**  14: TIES IGNORE
**  15: PLAN
**  16: INSTEAD INDEXED
**  17:
**  18: TRANSACTION RIGHT
**  19: WHEN
**  20: SET HAVING
**  21: MATERIALIZED IF
**  22: ROWS
**  23: SELECT
**  24:
**  25:
**  26: VACUUM SAVEPOINT
**  27:
**  28: LIKE UNION VIRTUAL REFERENCES
**  29: RESTRICT
**  30:
**  31: THEN REGEXP
**  32: TO
**  33:
**  34: BEFORE
**  35:
**  36:
**  37: FOLLOWING COLLATE CASCADE
**  38: CREATE
**  39:
**  40: CASE REINDEX
**  41: EACH
**  42:
**  43: QUERY
**  44: AND ADD
**  45: PRIMARY ANALYZE
**  46:
**  47: ROW ASC DETACH
**  48: CURRENT_TIME CURRENT_DATE
**  49:
**  50:
**  51: EXCLUSIVE TEMPORARY
**  52:
**  53: DEFERRED
**  54: DEFERRABLE
**  55:
**  56: DATABASE
**  57:
**  58: DELETE VIEW GENERATED
**  59: ATTACH
**  60: END
**  61: EXCLUDE
**  62: ESCAPE DESC
**  63: GLOB
**  64: WINDOW ELSE
**  65: COLUMN
**  66: FIRST
**  67:
**  68: GROUPS ALL
**  69: DISTINCT DROP KEY
**  70: BETWEEN
**  71: INITIALLY
**  72: BEGIN
**  73: FILTER CHECK ACTION
**  74: GROUP INDEX
**  75:
**  76: EXISTS DEFAULT
**  77:
**  78: FOR CURRENT_TIMESTAMP
**  79: EXCEPT
**  80:
**  81: CROSS
**  82:
**  83:
**  84:
**  85: CAST
**  86: FOREIGN AUTOINCREMENT
**  87: COMMIT
**  88: CURRENT AFTER ALTER
**  89: FULL FAIL CONFLICT
**  90: EXPLAIN
**  91: CONSTRAINT
**  92: FROM ALWAYS
**  93:
**  94: ABORT
**  95:
**  96: AS DO
**  97: REPLACE WITH RELEASE
**  98: BY RENAME
**  99: RANGE RAISE
** 100: OTHERS
** 101: USING NULLS
** 102: PRAGMA
** 103: JOIN ISNULL OFFSET
** 104: NOT
** 105: OR LAST LEFT
** 106: LIMIT
** 107:
** 108:
** 109: IN
** 110: INTO
** 111: OVER RECURSIVE
** 112: ORDER OUTER
** 113:
** 114: INTERSECT UNBOUNDED
** 115:
** 116:
** 117: RETURNING ON
** 118:
** 119: WHERE
** 120: NO INNER
** 121: NULL
** 122:
** 123: TABLE
** 124: NATURAL NOTNULL
** 125: PRECEDING
** 126: UPDATE UNIQUE
*/
/* Check to see if z[0..n-1] is a keyword. If it is, write the
** parser symbol code for that keyword into *pType.  Always
** return the integer n (the length of the token). */
static int keywordCode(const char *z, int n, int *pType){
  int i, j;
  const char *zKW;
  assert( n>=2 );
  i = ((charMap(z[0])*4) ^ (charMap(z[n-1])*3) ^ n*1) % 127;
  for(i=(int)aKWHash[i]; i>0; i=aKWNext[i]){
    if( aKWLen[i]!=n ) continue;
    zKW = &zKWText[aKWOffset[i]];
#ifdef SQLITE_ASCII
    if( (z[0]&~0x20)!=zKW[0] ) continue;
    if( (z[1]&~0x20)!=zKW[1] ) continue;
    j = 2;
    while( j<n && (z[j]&~0x20)==zKW[j] ){ j++; }
#endif
#ifdef SQLITE_EBCDIC
    if( toupper(z[0])!=zKW[0] ) continue;
    if( toupper(z[1])!=zKW[1] ) continue;
    j = 2;
    while( j<n && toupper(z[j])==zKW[j] ){ j++; }
#endif
    if( j<n ) continue;
    testcase( i==1 ); /* REINDEX */
    testcase( i==2 ); /* INDEXED */
    testcase( i==3 ); /* INDEX */
    testcase( i==4 ); /* DESC */
    testcase( i==5 ); /* ESCAPE */
    testcase( i==6 ); /* EACH */
    testcase( i==7 ); /* CHECK */
    testcase( i==8 ); /* KEY */
    testcase( i==9 ); /* BEFORE */
    testcase( i==10 ); /* FOREIGN */
    testcase( i==11 ); /* FOR */
    testcase( i==12 ); /* IGNORE */
    testcase( i==13 ); /* REGEXP */
    testcase( i==14 ); /* EXPLAIN */
    testcase( i==15 ); /* INSTEAD */
    testcase( i==16 ); /* ADD */
    testcase( i==17 ); /* DATABASE */
    testcase( i==18 ); /* AS */
    testcase( i==19 ); /* SELECT */
    testcase( i==20 ); /* TABLE */
    testcase( i==21 ); /* LEFT */
    testcase( i==22 ); /* THEN */
    testcase( i==23 ); /* END */
    testcase( i==24 ); /* DEFERRABLE */
    testcase( i==25 ); /* ELSE */
    testcase( i==26 ); /* EXCLUDE */
    testcase( i==27 ); /* DELETE */
    testcase( i==28 ); /* TEMPORARY */
    testcase( i==29 ); /* TEMP */
    testcase( i==30 ); /* OR */
    testcase( i==31 ); /* ISNULL */
    testcase( i==32 ); /* NULLS */
    testcase( i==33 ); /* SAVEPOINT */
    testcase( i==34 ); /* INTERSECT */
    testcase( i==35 ); /* TIES */
    testcase( i==36 ); /* NOTNULL */
    testcase( i==37 ); /* NOT */
    testcase( i==38 ); /* NO */
    testcase( i==39 ); /* NULL */
    testcase( i==40 ); /* LIKE */
    testcase( i==41 ); /* EXCEPT */
    testcase( i==42 ); /* TRANSACTION */
    testcase( i==43 ); /* ACTION */
    testcase( i==44 ); /* ON */
    testcase( i==45 ); /* NATURAL */
    testcase( i==46 ); /* ALTER */
    testcase( i==47 ); /* RAISE */
    testcase( i==48 ); /* EXCLUSIVE */
    testcase( i==49 ); /* EXISTS */
    testcase( i==50 ); /* CONSTRAINT */
    testcase( i==51 ); /* INTO */
    testcase( i==52 ); /* OFFSET */
    testcase( i==53 ); /* OF */
    testcase( i==54 ); /* SET */
    testcase( i==55 ); /* TRIGGER */
    testcase( i==56 ); /* RANGE */
    testcase( i==57 ); /* GENERATED */
    testcase( i==58 ); /* DETACH */
    testcase( i==59 ); /* HAVING */
    testcase( i==60 ); /* GLOB */
    testcase( i==61 ); /* BEGIN */
    testcase( i==62 ); /* INNER */
    testcase( i==63 ); /* REFERENCES */
    testcase( i==64 ); /* UNIQUE */
    testcase( i==65 ); /* QUERY */
    testcase( i==66 ); /* WITHOUT */
    testcase( i==67 ); /* WITH */
    testcase( i==68 ); /* OUTER */
    testcase( i==69 ); /* RELEASE */
    testcase( i==70 ); /* ATTACH */
    testcase( i==71 ); /* BETWEEN */
    testcase( i==72 ); /* NOTHING */
    testcase( i==73 ); /* GROUPS */
    testcase( i==74 ); /* GROUP */
    testcase( i==75 ); /* CASCADE */
    testcase( i==76 ); /* ASC */
    testcase( i==77 ); /* DEFAULT */
    testcase( i==78 ); /* CASE */
    testcase( i==79 ); /* COLLATE */
    testcase( i==80 ); /* CREATE */
    testcase( i==81 ); /* CURRENT_DATE */
    testcase( i==82 ); /* IMMEDIATE */
    testcase( i==83 ); /* JOIN */
    testcase( i==84 ); /* INSERT */
    testcase( i==85 ); /* MATCH */
    testcase( i==86 ); /* PLAN */
    testcase( i==87 ); /* ANALYZE */
    testcase( i==88 ); /* PRAGMA */
    testcase( i==89 ); /* MATERIALIZED */
    testcase( i==90 ); /* DEFERRED */
    testcase( i==91 ); /* DISTINCT */
    testcase( i==92 ); /* IS */
    testcase( i==93 ); /* UPDATE */
    testcase( i==94 ); /* VALUES */
    testcase( i==95 ); /* VIRTUAL */
    testcase( i==96 ); /* ALWAYS */
    testcase( i==97 ); /* WHEN */
    testcase( i==98 ); /* WHERE */
    testcase( i==99 ); /* RECURSIVE */
    testcase( i==100 ); /* ABORT */
    testcase( i==101 ); /* AFTER */
    testcase( i==102 ); /* RENAME */
    testcase( i==103 ); /* AND */
    testcase( i==104 ); /* DROP */
    testcase( i==105 ); /* PARTITION */
    testcase( i==106 ); /* AUTOINCREMENT */
    testcase( i==107 ); /* TO */
    testcase( i==108 ); /* IN */
    testcase( i==109 ); /* CAST */
    testcase( i==110 ); /* COLUMN */
    testcase( i==111 ); /* COMMIT */
    testcase( i==112 ); /* CONFLICT */
    testcase( i==113 ); /* CROSS */
    testcase( i==114 ); /* CURRENT_TIMESTAMP */
    testcase( i==115 ); /* CURRENT_TIME */
    testcase( i==116 ); /* CURRENT */
    testcase( i==117 ); /* PRECEDING */
    testcase( i==118 ); /* FAIL */
    testcase( i==119 ); /* LAST */
    testcase( i==120 ); /* FILTER */
    testcase( i==121 ); /* REPLACE */
    testcase( i==122 ); /* FIRST */
    testcase( i==123 ); /* FOLLOWING */
    testcase( i==124 ); /* FROM */
    testcase( i==125 ); /* FULL */
    testcase( i==126 ); /* LIMIT */
    testcase( i==127 ); /* IF */
    testcase( i==128 ); /* ORDER */
    testcase( i==129 ); /* RESTRICT */
    testcase( i==130 ); /* OTHERS */
    testcase( i==131 ); /* OVER */
    testcase( i==132 ); /* RETURNING */
    testcase( i==133 ); /* RIGHT */
    testcase( i==134 ); /* ROLLBACK */
    testcase( i==135 ); /* ROWS */
    testcase( i==136 ); /* ROW */
    testcase( i==137 ); /* UNBOUNDED */
    testcase( i==138 ); /* UNION */
    testcase( i==139 ); /* USING */
    testcase( i==140 ); /* VACUUM */
    testcase( i==141 ); /* VIEW */
    testcase( i==142 ); /* WINDOW */
    testcase( i==143 ); /* DO */
    testcase( i==144 ); /* BY */
    testcase( i==145 ); /* INITIALLY */
    testcase( i==146 ); /* ALL */
    testcase( i==147 ); /* PRIMARY */
    *pType = aKWCode[i];
    break;
  }
  return n;
}
int sqlite3KeywordCode(const unsigned char *z, int n){
  int id = TK_ID;
  if( n>=2 ) keywordCode((char*)z, n, &id);
  return id;
}
#define SQLITE_N_KEYWORD 147
int sqlite3_keyword_name(int i,const char **pzName,int *pnName){
  if( i<0 || i>=SQLITE_N_KEYWORD ) return SQLITE_ERROR;
  i++;
  *pzName = zKWText + aKWOffset[i];
  *pnName = aKWLen[i];
  return SQLITE_OK;
}
int sqlite3_keyword_count(void){ return SQLITE_N_KEYWORD; }
int sqlite3_keyword_check(const char *zName, int nName){
  return TK_ID!=sqlite3KeywordCode((const u8*)zName, nName);
}
