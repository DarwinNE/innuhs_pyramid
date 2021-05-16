#include "ti994a_compat.h"

extern int printf(const char *format, ...);
static int tolower(int ch);
static void tolowerstring(char* str);

FILE* stdin = NULL;

char *strncpy(char *toHere, const char *fromHere, size_t count)
{
    if (toHere != NULL && fromHere != NULL)
    {
        while ((*toHere = *fromHere) != 0 && (count > 0))
        {
            toHere++;
            fromHere++;
            count--;
        }
    }

    return toHere;
}

char* fgets(char *buffer, int size, FILE *f)
{
    gets(buffer, size);
    // printf("'%s'\n", buffer);

    // ti gets routine only supports UPPERCASE input
    // for whatever reason. Convert all to lc.
    tolowerstring(buffer);

    // add a space to the end... this is a hack because
    // there is a bug that removes one char from the string
    char* p = buffer;
    while (*p != 0) p++;
    *p = ' '; p++;
    *p = 0;
    // end hack

    //printf("'%s'\n", buffer);
 
    return buffer;
}

static int tolower(int ch)
{
    if (ch >= (int)'A' && ch <= (int)'Z') ch = ch + ('a' - 'A');
    return ch;
}

static void tolowerstring(char* str)
{
    if (str != NULL)
    {
        while (*str != 0)
        {
            *str = tolower(*str);
            str++;
        }
    }
}
