#include "defs.h"

typedef struct Token Token;

int scan(Token* t);
static int scanInteger(int c);
static int charPoS(char* s, int c);
