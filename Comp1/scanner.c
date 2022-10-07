#include "stdlib.h"
#include "data.h"
#include "defs.h"

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