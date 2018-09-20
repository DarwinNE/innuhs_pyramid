#ifndef __C128_CODES_H__
#define __C128_CODES_H__

// The number of columns of the screen
#define NCOL 80

#include<time.h>
void wait1s(void)
{
    unsigned int retTime;
    int r=5;
    // Implement a dull loop!
    for(retTime=0; retTime<1000;++retTime){
        r*=5;
        r/=5;
    }
}

#define LONGVERSION

void waitscreen(void) {}
void normaltxt(void)  {}
void init_term(void)  {}
void inputtxt(void) {}
void evidence1(void) {++colc;printf("-");}
void evidence2(void) {++colc;printf("*");}
void tab(void) {printf("        ");}

void leave(void) {}

#endif