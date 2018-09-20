#ifndef __MODERN_H__
#define __MODERN_H__

#include<time.h>

#define LONGVERSION

void waitscreen(void) {}

// The number of columns of the screen
#define NCOL 80

void inputtxt(void) {printf("\033[1m\x1b[32m\33[40m");}
void evidence1(void) {printf("\033[1m\x1b[31m\33[40m");}
void evidence2(void) {printf("\033[0m\x1b[93m\33[40m");}
void normaltxt(void) {printf("\033[0m\x1b[36m\33[40m");}
void tab(void) {printf("\t");}
void wait1s(void)
{
    unsigned int retTime = time(0) + 1;   // Get finishing time.
    fflush(stdout);

    while (time(0) < retTime);            // Loop until it arrives.
}
void init_term(void) {normaltxt();printf("\n\n");}

void leave(void) 
{
    printf("\033[0m\n\n");
}
#endif