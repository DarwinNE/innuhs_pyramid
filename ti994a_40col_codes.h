#ifndef __TI994A_40COL_CODES_H__
#define __TI994A_40COL_CODES_H__

#include "libti99/conio.h"

// The number of columns of the screen
#define NCOL 40

void wait1s(void)
{
    unsigned int retTime;
    volatile int r=5;
    // Implement a dull loop!
    for(retTime=0; retTime<1000;++retTime){
        r*=5;
        r/=5;
    }
}

#define LONGVERSION

void waitscreen(void) {}
void normaltxt(void)  {}
void init_term(void)
{
        set_text();
        bgcolor(COLOR_BLACK);
        bordercolor(COLOR_BLACK);
        textcolor(COLOR_LTGREEN);

        charsetlc();
}

void inputtxt(void) {}
void evidence1(void) {++colc;printf("-");}
void evidence2(void) {++colc;printf("*");}
void tab(void) {printf("  ");}

void leave(void) {}

#endif
