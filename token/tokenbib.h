#ifndef __token_bib__
#define __token_bib__

typedef struct {
char* str;
int tam;
int pos;
} TokenReader;

//enum {false=0, true} boolean;

TokenReader *newTokenReader(char *str);
void freeTokenReader(TokenReader *reader);
char* nextToken(TokenReader *reader);
void setTokenString(TokenReader *reader, char* str);
int hasMoreTokens(TokenReader *reader);
#endif
