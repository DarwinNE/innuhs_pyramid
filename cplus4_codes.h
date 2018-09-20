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

void waitscreen(void) {printf("[return]"); getchar();}
void normaltxt(void)    {printf(cyan);}
void init_term(void) 
{   char* screen_col=(char*)65301;
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