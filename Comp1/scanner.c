#include "stdlib.h"
#include "data.h"
#include "defs.h"
#include "ctype.h"

typedef struct Token Token;

//Get next character
static int nextChar(void)
{
    int c;

    if(Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);

    /*If next character is newline, go to the next line*/
    if(c == '\n')
    {
        Line++;
        return c;
    }
}

static int skip(void)
{
    int c;

    c = nextChar();
    while(c == ' ' || c == '\t' || c == '\n' || c == '\n' || c == '\r' || c == '\f') {
        c = nextChar();
    }

    return c;
}

int scan(Token* t)
{
    int c;
    
    //Skip whitespace
    c = skip();

    switch (c)
    {
        case EOF:
            return 0;
            break;
    
        case '+':
            t->token = T_PLUS;
            break;
            
        case '-':
            t->token = T_MINUS;
            break;

        case '*':
            t->token = T_MULT;
            break;
        
        case '/':
            t->token = T_DIVIDE;
            break;

        default:
            if(isdigit(c))
            {
                t->iValue = scanint(c);
                t->token = T_INTLIT;
                break;
            }
        }

    //Return 1 if token found.
    return 1;
}
