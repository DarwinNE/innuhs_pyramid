#ifndef __C64_CODES_H__
#define __C64_CODES_H__

#define green       "\x1E"
#define red         "\x1C"
#define cyan        "\x9F"
#define blue        "\x1F"
#define yellow      "\x9E"
#define cls         "\x93"

// The number of columns of the screen
#define NCOL 40

#include<time.h>
void wait1s(void)
{
    unsigned int retTime = time(0) + 1;   // Get finishing time.
    while (time(0) < retTime);            // Loop until it arrives.
}

#define LONGVERSION

void waitscreen(void) {}
void normaltxt(void)    {printf(cyan);}
void init_term(void) 
{   
    char* screen_col=(char*)53280;
    *screen_col=0;
    screen_col=(char*)53281;
    *screen_col=0;
    printf(cls);
    normaltxt();
}
void inputtxt(void) {printf(green);}
void evidence1(void) {printf(red);}
void evidence2(void) {printf(yellow);}
void tab(void) {printf("    ");}

void leave(void) 
{
    printf(cyan);
}

#endif