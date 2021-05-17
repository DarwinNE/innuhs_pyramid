#include "ti994a_compat.h"

extern int printf(const char *format, ...);
static int tolower(int ch);
static void tolowerstring(char* str);

FILE* stdin = NULL;

char *strncpy(char *toHere, const char *fromHere, size_t count)
{
    if (toHere != NULL && fromHere != NULL && count > 0)
    {
        do
        {
            *toHere = *fromHere;
            toHere++;
            fromHere++;
            count--;
        } while ((*fromHere != '\0') && (count > 0));
        *toHere = '\0';
    }
    else if (toHere != NULL)
    {
        *toHere = '\0';
    }

    return toHere;
}

char* fgets(char *buffer, int size, FILE *f)
{
    gets(buffer, size);
    // printf("'%s'\n", buffer);

    // ti gets routine only supports UPPERCASE input
    // for whatever reason. 
    // Convert all to lc, since this is what the game expects.
    char* p = buffer;
    while (*p != '\0')
    {
        *p = tolower(*p);
        p++;
    }

    // add a newline to the end. 'fgets' returns the newline,
    // but 'gets' does not.  Calling function 'readln' expects
    // (and removes) the newline.
    *p = '\n';
    p++;
    *p = '\0';

    //printf("'%s'\n", buffer);
    return buffer;
}

static int tolower(int ch)
{
    if (ch >= (int)'A' && ch <= (int)'Z') ch = ch + ('a' - 'A');
    return ch;
}

