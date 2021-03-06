
#ifndef __UTILS_H__
#define __UTILS_H__
#define YYEOF 0
// Lex and Yacc interface utility.

#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

#include "astree.h"
#include "auxlib.h"


extern FILE* yyin;
extern char* yytext;
extern int yy_flex_debug;
extern int yydebug;
extern size_t yyleng;

int yylex();
int yylex_destroy();
int yyparse();
extern astree* yyparse_astree;
const char *get_yytname (int symbol);
void yyerror (const char* message);


struct lexer {
   static bool interactive;
   static location lloc;
   static size_t last_yyleng;
   static vector<string> filenames;
   static const string* filename (int filenr);
   static FILE* tokFile;
   static astree* root;
   static void newfilename (const string& filename, FILE* tok);
   static void advance();
   static void newline();
   static void badchar (unsigned char bad);
   static void badtoken (char* lexeme);
   static void include();
   static void dump (int symbol);
};

struct parser {
   static astree* root;
   static const char* get_tname (int symbol);
};

#define YYSTYPE astree*
#include "yyparse.h"

#endif
