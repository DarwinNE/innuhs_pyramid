#ifndef __TI994A_40COL_CODES_H__
#define __TI994A_40COL_CODES_H__

#include "libti99/conio.h"

// The number of columns of the screen
// NCOL definition moved to makefile

void wait1s(void)
{
    unsigned int retTime;
    volatile int r=5;
    // Implement a dull loop!
    for(retTime=0; retTime<10000;++retTime){
        r*=5;
        r/=5;
    }
}

#define LONGVERSION

void waitscreen(void) { wait1s(); }
void normaltxt(void)  {}
void init_term(void)
{
#if NCOL==80
        // 80 col mode requires additional hardware:
        // F18A, other?
        set_text80();
#else
        // TI supports 40 col text mode in box
        set_text();
#endif
        bgcolor(COLOR_BLACK);
        bordercolor(COLOR_BLACK);
        textcolor(COLOR_LTGREEN);

        charsetlc();
}

void inputtxt(void) {}
void evidence1(void) {++colc;printf("-");}
void evidence2(void) {++colc;printf("*");}

#if NCOL==80
void tab(void) {printf("    ");}
#else
void tab(void) {printf("  ");}
#endif

void leave(void) {}

#endif
