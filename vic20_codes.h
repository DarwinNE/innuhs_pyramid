#ifndef __VIC20_CODES_H__
#define __VIC20_CODES_H__

#define switch80col "\x1Bx\x0E"
#define green       "\x1E"
#define red         "\x1C"
#define cyan        "\x9F"
#define blue        "\x1F"
#define yellow      "\x9E"
#define cls         "\x93"

void waitscreen(void) {printf("[return]"); getchar();}
void normaltxt(void) {printf(cyan);}

void init_term(void) 
{
    char* screen_col=(char*)36879;
    *screen_col=8;
    printf(cls);
    normaltxt();
}
void inputtxt(void) {printf(green);}
void evidence1(void) {printf(red);}
void evidence2(void) {printf(yellow);}
void tab(void) {}
void leave(void) 
{
    char* screen_col=(char*)36879;
    writeln("\b");
    *screen_col=27;
    printf(blue);
}

#endif