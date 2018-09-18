#ifndef __C128_CODES_H__
#define __C128_CODES_H__

#define switch80col "\x1Bx\x0E"
#define green       "\x1E"
#define red         "\x1C"
#define cyan        "\x9F"
#define blue        "\x1F"
#define yellow      "\x9E"
#define cls         "\x93"

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
    char *pt80col=(char*)215;
    char *ptFast=(char*)53296;
    if (*pt80col==0) {          // Check if we are already in the 80 col. mode
        printf(switch80col);
    }
    *ptFast=1;      // FAST mode
    printf(cls);
    normaltxt();
}
void inputtxt(void) {printf(green);}
void evidence1(void) {printf(red);}
void evidence2(void) {printf(yellow);}
void tab(void) {printf("        ");}

void leave(void) 
{
    printf(cyan);
}

#endif