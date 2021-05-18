/** C transcription of the game
    "La piramide di Innuh"
    Proposed for the TI-99/4A by Aristide Torrelli
    Published in MCmicrocomputer n. 33, september 1984.

    I based my work from the Sinclair ZX Spectrum version
    by Manlio Severi, published in MCmicrocomputer n. 35,
    november 1984.

    I changed the name of some variables, to obtain a more readable listing.
    Here is the correspondance between the original names and those used
    here:

    cp          currentPosition
    p           pcon
    p$          ploc
    o           objloc
    o$          obj
    no          numberObject
    m$          foundName
    tm          mummiaSegue
    st          scalaAperta
    p12         passaggio12
    to1         torchIsOn
    zz          numberOfObjects
    c1          doorIsClosed
    c2          cobraIsPresent
    fbc         chargeOfBatteries
*/

#ifdef TI994A
    #include "ti994a_compat.h"
    #include "libti99/string.h"
#else
    #include<stdio.h>
    #include<string.h>
#endif

#include"innuh.h"

int colc=0;


#ifdef C128
    #include"c128_codes.h"
#elif defined(VIC20)
    #include"vic20_codes.h"
#elif defined(C64)
    #include"c64_codes.h"
#elif defined(PLUS4)
    #include"cplus4_codes.h"
#elif defined(PET)
    #include"cpet_codes.h"
#elif defined(TI994A)
    #include "ti994a_codes.h"
#else
    #include"modern.h"
#endif

#define IMPROVED_PARSER

// Number of complete descriptions of objects
#define LO 41
#define NV 32
#define NN 42

#ifdef ITALIAN
    #include"italian.h"
#elif defined(ENGLISH)
    #include"english.h"
#else
    #include"english.h"
#endif

typedef int boolean;
#define true -1
#define false 0
#define BUFFERSIZE 80

// Pitch black (true or false)
boolean pitchBlack;

boolean scalaAperta;

boolean passaggio12;
boolean mummiaSegue;

// Torch is on or off
boolean torchIsOn;

// Number of the selected object in the array
int numberObject;

// Name found in the string given by the user
char foundName[BUFFERSIZE];

char playerInput[BUFFERSIZE];

// Door state (true: close, false: open)
boolean doorIsClosed;

// Cobra (true: is present, false: is absent)
boolean cobraIsPresent;

// Current position of the player
int currentPosition;

// It is true if the description has changed and should be shown.
boolean showDesc;

char q[BUFFERSIZE];

// The index of the found verb
int verb=0;

int numberOfObjects;

boolean isDead;

// Batteries charged or not
int chargeOfBatteries;

// Connections between places
// not used, north, sud, east, west, up, down
int pcon[25][7] =
    {{0,0,0,0,0,0,0}, // This index is not used
    {0,2,4,2,1,0,0},        // 1 Desert
    {0,2,3,3,1,0,0},        // 2 Desert
    {0,2,5,2,4,0,0},        // 3 Desert
    {0,1,5,3,4,0,0},        // 4 Desert
    {0,4,0,3,0,0,0},        // 5 Desert, in front of the pyramid
    {0,5,10,7,8,0,0},       // 6 Antechamber
    {0,0,10,0,6,0,0},       // 7 Triangular room
    {0,0,9,6,0,0,0},        // 8 White room
    {0,8,0,10,0,0,0},       // 9 Recess
    {0,6,0,7,9,0,0},        // 10 Hallway
    {0,0,13,14,0,0,0},      // 11 Red room
    {0,0,15,13,0,0,10},     // 12 Little room
    {0,11,15,14,12,0,0},    // 13 Alchemist's
    {0,11,0,0,13,0,0},      // 14 Embalmer's
    {0,13,0,0,12,0,0},      // 15 Iankho's
    {0,0,0,17,0,8,0},       // 16 gallery
    {0,0,0,18,16,0,0},      // 17 tunnel
    {0,0,21,19,17,0,0},     // 18 tunnel
    {0,0,0,0,18,0,0},       // 19 green room
    {0,0,0,21,0,0,0},       // 20 small tunnel
    {0,18,0,22,20,0,0},     // 21 armoury
    {0,0,0,0,21,0,0},       // 22 hieroglyphs'
    {0,20,24,0,0,0,0},      // 23 Hanyke's
    {0,23,0,0,0,0,0}};      // 24 Funerary chapel

// The locations of the different objects
int objloc[22];
const int objloc_org[] = {0,1,0,3,4,5,6,8,9,10,11,11,11,
    12,13,15,15,16,22,24,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void (*actions[NV])(void) ={NULL,&insulta,&resa,&inventario,
    &inventario,&esamina,&vai,&vai,
    &vai,&esamina,&prendi,&prendi,&posa,&posa,&posa,&apri,
    &guarda,&suona,&leggi,&ondeggia,&scava,&mangia,&bevi,&chiudi,
    &posa,&rompi,&accendi,&spegni,&salta,&insulta,&prendi,&cambia};


int main(int argc, char** argv)
{
    init_term();
    setup();
    writeln(gamepres);
    while(!isDead)
        play();

    leave();
    return 0;
}

char wordbuffer[NCOL*2];

void writesameln(char *line)
{
    int i=0;
    boolean flag=false;
    boolean norm=false;
    char c;
    int pc=0;

    while(1){
        c=line[i++];
        if(c=='*' && flag==false) {
            evidence2();
            flag=true;
        } else if(c=='*' && flag==true) {
            norm=true;
            flag=false;
        } else if(c=='-' && flag==false) {
            evidence1();
            flag=true;
        } else if(c=='-' && flag==true) {
            norm=true;
            flag=false;
        } else if(c=='\b') {
            waitscreen();
        } else if(c=='\t') {
            tab();
        } else if(c==' ' || c=='\n'||c=='\0') {
            wordbuffer[pc]='\0';
            if(colc>=NCOL) {
                printf("\n");
                colc=strlen(wordbuffer);
            } 
            printf("%s",wordbuffer);
            if(norm==true) {
                normaltxt();
                norm=false;
            }
            if(c=='\0') 
                return;
            pc=0;
            if(c=='\n') {
                printf("\n");
                colc=0;
            } else if(colc<NCOL-1) {
                printf(" ");
                ++colc;
            }
        } else {
            wordbuffer[pc++]=c;
            ++colc;
        }
    }
}

void writeln(char* line)
{
    writesameln(line);
    printf("\n");
    colc=0;
}

void setup(void)
{
    int i;
    for(i=0;i<22;++i)
        objloc[i]=objloc_org[i];
    // Set up all the variables.
    pitchBlack = false;
    scalaAperta = false;
    passaggio12 = false;
    mummiaSegue = false;
    torchIsOn = false;
    doorIsClosed = true;
    cobraIsPresent = true;
    currentPosition = 1;
    numberOfObjects = 0;
    chargeOfBatteries = 15;
    isDead = false;
    showDesc = true;
    pcon[20][2]=0;
    pcon[10][5]=0;
    pcon[5][2]=0;
    pcon[8][6]=0;
    ploc[8]=inawhiteroomc;
    ploc[20]=cunicolostretto;
    obj[9]=skeletonb;
}

/** Main game routine
*/
void play(void)
{
    if(showDesc) {
        sonovedo();
        if(mummiaSegue) {
            objloc[21]=currentPosition;
            writeln(mummyfollowing);
        }

        writeln(whatshallido);

    }
    // Adventure completed?
    if((currentPosition==4)&&(objloc[8]==4)&&
       (objloc[12]==4)&&(objloc[16]==4)&&
       (objloc[18]==4)&&(objloc[20]==4)) {
        theEnd();
        return;
    }

    interrogationAndAnalysis();
    if(verb==29 || verb==30) {
        action(verb);
        return;
    }
    if(verb>8 && strlen(foundName)==0) {
        writesameln(playerInput);
        writeln(whatdoyoumean);
        return;
    }
    if(strlen(foundName)!=0 && (verb==6 || verb==7 || verb ==8) &&
        numberObject==0) {
        writeln(idontunderstand);
        return;
    }
    action(verb);
    return;
}

/** Describe the current situation in the game.
*/
void sonovedo(void)
{
    boolean fstsee=true;
    int i=0;
    boolean fl =false;

    showDesc = false;
    if(objloc[1]==-1 && torchIsOn) {
        // Light is on
    }
    if(chargeOfBatteries==0) {
        // Batteries are dead
        torchIsOn=false;
    }
    if(currentPosition>5) {
        if(objloc[1]!=-1|| !torchIsOn) {
            writeln(itspitchblack);
            pitchBlack=true;
            return;
        }
    }
    if(currentPosition==17 && objloc[21]!=0 && !pitchBlack) {
        mummiaSegue=true;
    }
    writeln("");
    writesameln(iam);
    writeln(ploc[currentPosition]);
    pitchBlack=false;

    if(((currentPosition==6) || (currentPosition==18)) && mummiaSegue) {
        writeln(mummyattacks);
        dropDead();
        return;
    }
    for(i=1; i<LO;++i) {
        if(objloc[i]==currentPosition) {
            if(fstsee)
                writesameln(isee);
            else
                writesameln(", ");
            fstsee=false;
            // one may test if the index i is valid...
            writesameln(obj[i]);
        }
    }
    writeln("");

    if(currentPosition==5 && doorIsClosed) {
        writeln(doorclose);
    }
    if(currentPosition==5 && !doorIsClosed) {
        writeln(dooropen);
    }
    writesameln(icangoto);
    for(i=1; i<=6; ++i) {
        if(pcon[currentPosition][i]!=0) {
            writesameln(directions[i]);
            writesameln(" ");
            fl=true;
        }
    }
    writeln("");
    return;
}

/** Fine gioco
*/
void theEnd(void)
{
    writeln(adventurefinished);
    isDead=true;
}

/** Morte
*/
void dropDead(void)
{
    writeln(iamdead);
    isDead=true;
}

/** read a line of text and return the length of the line (remove the \n char).
*/
int readln()
{
    int lc;
    inputtxt();
    writesameln("> ");
    fgets(playerInput,BUFFERSIZE,stdin);
    normaltxt();
    lc=strlen(playerInput);
    // remove the '\n'
    if(lc>0) {
        playerInput[lc-1]='\0';
        --lc;
    }
    return lc;
}

#ifdef IMPROVED_PARSER
/** Improved parser, more flexible than the simpler version.
*/
void interrogationAndAnalysis(void)
{
    boolean search=true;
    char s[BUFFERSIZE];
    int ls=0, lc, i, x, ols, app,k;
    boolean found = false;
    lc=readln();

    // Search at first the verb. In Italian and in English, it seems safe to
    // give precedence to the first recognised verb.
    while(search==true) {
        k=0;
        for(; ls<lc; ++ls) {
            if(playerInput[ls]==' ') {
                ls++;
                break;
            }
            s[k++]=playerInput[ls];
        }
        // Here s may not be finished by a '\0', but it is not an issue.
        ols=k;
        // k now contains the length of the first word.
        // Compensate for strings smaller than 4 chars
        if(k<4) {
            for(x=0; x<=4-ols;++x)
                s[k++]=' ';
        }
        // Truncate s if it is longer than 4 chars
        s[4]='\0';
        //printf("word 1: %s\n",s);
        // s now contains the word, truncated to 4 characters. Search to find
        // if it is recognized or not.
        for(i=1;i<NV; ++i) {
            if(strcmp(s,verbsabb[i])==0) {
                // a verb is found
                verb = i;
                found=true;
                search=false;
                break;
            }
        }
        if (ls==lc)
            search=false;
    }
    //printf("verb: %s, recognized: %d \n",s, found);
    if(ls==lc) {
        if(found==false){
            ls=0;
            verb=6;     // By default verb is "go".
        } else {
            return;
        }
    }
    search=true;
    found=false;
    numberObject=0;
    
    // Then search for the name/object. We give precedence to the first
    // recognised object.
    
    while(search==true) {
        k=0;
        for(; ls<lc; ++ls) {
            if(playerInput[ls]==' '){
                ls++;
                break;
            }
            s[k++]=playerInput[ls];
        }
        s[k]='\0';
        // ls now contains the length of the first word.
        ols=k;
        strncpy(q,s,BUFFERSIZE);
        // Compensate for strings smaller than 4 chars
        if(k<4) {
            for(x=0; x<=4-ols;++x)
                s[k++]=' ';
        }
        // Truncate s if it is longer than 4 chars
        s[4]='\0';
        //printf("word 2: %s\n",s);
        for(i=1; i<NN; ++i) {
            if(strcmp(s,namesabb[i])==0) {
                app=i;
                found=true;
                //printf("---->found!\n");
                numberObject=app;
                search=false;
                strncpy(foundName,s,BUFFERSIZE);
                break;
            }
        }
        if (ls==lc)
            search=false;
    }

    //printf("object: %s, recognized: %d \n",foundName, found);
}
#else
/** Simpler parsing function. It just take the first word as a verb (truncated
    to 4 chars and the last word as an object (truncated to 4 chars).
*/

void interrogationAndAnalysis(void)
{
    int app=0;
    int ls=0;
    int lc=0;
    int i,x,lf;
    int ols;
    int nounpos=0;
    char s[BUFFERSIZE];
    boolean flag = false;

    foundName[0]='\0';
    s[0]='\0';
    verb=0;
    numberObject = 0;
    lc=readln();
    
    for(ls=0; ls<lc; ++ls) {
        if(playerInput[ls]==' ')
            break;
        s[ls]=playerInput[ls];
    }
    // ls now contains the length of the first word.
    ols=ls;
    // Compensate for strings smaller than 4 chars
    if(ls<4) {
        for(x=0; x<=4-ols;++x)
            s[ls++]=' ';
    }
    // Truncate s if it is longer than 4 chars
    s[4]='\0';

    // s now contains the verb, truncated to 4 characters. Search to find
    // if it is recognized or not.
    for(i=1;i<NV; ++i) {
        if(strcmp(s,verbsabb[i])==0) {
            // a verb is found
            verb = i;
            flag=true;
            break;
        }
    }

    //printf("verb: %s, recognized: %d \n",s, flag);
    
    if (!flag) {
        verb=6;     // By default verb is "go".
        strncpy(foundName,s, BUFFERSIZE);
    } else {
        flag=false;
        if(strlen(s)+1>lc) {
            numberObject = 0;
        }
        for(i=lc-1; i>=0;--i){
            if(playerInput[i]==' ') {
                nounpos=i+1;
                break;
            }
        }
        strncpy(foundName,&playerInput[nounpos], BUFFERSIZE);
        lf=strlen(foundName);
        if(lf<4) {
            int w;
            for(w=0; w<=4-lf;++w)
                foundName[lf+w]=' ';
            foundName[lf+w]='\0';
        }
    }
    strncpy(q,foundName,BUFFERSIZE);
    if (strlen(foundName)>=4)
        foundName[4]='\0';

    for(i=1; i<=NN; ++i) {
        if(strcmp(foundName,namesabb[i])==0) {
            app=i;
            flag=true;
            break;
        }
    }
    if(flag) {
        numberObject=app;
    }
    //printf("object: %s, recognized: %d \n",foundName, flag);
} 
#endif

void action(int vb)
{
    void (*pf)(void);
    if(vb<0 || vb>31) {
        writeln(unknownverb);
        return;
    }
    pf=actions[vb];
    
    if(pf!=NULL)
        (*pf)();
}

/** Esci
*/
void resa(void)
{
    writeln("Ok.");
    isDead = true;
}

/** Inventario
*/
void inventario(void)
{
    int gs = 0,i;
    writeln(ihavewithme);
    for(i = 0; i<LO; ++i) {
        if(objloc[i]==-1) {
            ++gs;
            writeln(obj[i]);
        }
    }
    if(gs==0)
        writeln(nothing);

}

/** Vai, corri, cammina
*/
void vai(void)
{
    if (numberObject == 0) {
        writeln("Uh?");
        return;
    }
    if(numberObject == 0 && strlen(foundName)!=0) {
        writeln(idonotknowthisword);
        return;
    }
    if(numberObject<27 && numberObject!=5) {
        writeln(idonotunderstand);
        return;
    }
    if(numberObject>34) {
        numberObject = numberObject - 6;
    }
    if(currentPosition==5 && numberObject ==5 && !doorIsClosed) {
        writeln("Ok.");
        currentPosition = pcon[currentPosition][1+1];
        --chargeOfBatteries;
        showDesc = true;
        return;
    }
    if(currentPosition==8 && numberObject ==27 && !passaggio12) {
        writeln("Ok.");
        currentPosition = pcon[currentPosition][5+1];
        --chargeOfBatteries;
        showDesc = true;
        return;
    }
    if(currentPosition==10 && numberObject ==28 && scalaAperta) {
        writeln("Ok.");
        currentPosition = pcon[currentPosition][4+1];
        --chargeOfBatteries;
        showDesc = true;
        return;
    }
    if(numberObject <29) {
        writeln(icantdothatyet);
        return;
    }
    numberObject-=29;
    if(numberObject>0 && pitchBlack) {
        writeln(ifell);
        dropDead();
        return;
    }
    if(pcon[currentPosition][numberObject+1]==0) {
        writeln(cantgothere);
        return;
    }
    currentPosition = pcon[currentPosition][numberObject+1];
    if(currentPosition>=6)
        --chargeOfBatteries;

    showDesc = true;
    return;
}

/** Guarda rapidamente.
*/
void guarda(void)
{
    showDesc = true;
}

/** Esamina
*/
void esamina(void)
{

    if(numberObject==41) {
        showDesc=true;
        return;
    }
    if(objloc[numberObject]!=-1 && objloc[numberObject]!=currentPosition) {
        writeln("?");
        return;
    }
    if(numberObject==0) {
        writesameln(dontknowthatword);
        writeln(q);
        return;
    }
    if((numberObject==4) || (numberObject==16 &&
        objloc[16]==-1)) {
        writeln(somethingiswritten);
        return;
    }
    if(numberObject==19) {
        writeln(iseesomething);
        objloc[20]=24;
        showDesc = true;
        return;
    }
    if(numberObject==1) {
        writeln(torchdesc);
        return;
    }
    writeln(anythingspecial);
    return;
}

/** Prendi, piglia
*/
void prendi(void)
{
    if(numberObject==0) {
        esamina();
        return;
    }
    if(objloc[numberObject]!=currentPosition) {
        writesameln(idonotsee);
        writesameln(q);
        writeln(aroundhere);
        return;
    }
    if(numberObject==4 || numberObject==5 || numberObject==9 ||
       numberObject == 10 || numberObject==15 || numberObject==19) {
        writeln(dontbesilly);
        return;
    }
    if(numberObject>20) {
        writeln(dontbestupid);
        return;
    }
    if(numberOfObjects>4) {
        writeln(cantcarrymore);
        return;
    }
    if(currentPosition==20 && numberObject==3) {
        ploc[20]=cunicolostretto;
        pcon[20][2]=0;
    }
    if(currentPosition==15 && cobraIsPresent) {
        writeln(cobrabitten);
        dropDead();
        return;
    }

    ++numberOfObjects;
    writeln("Ok.");
    objloc[numberObject]=-1;
    if(numberObject==1 && currentPosition==17) {
        showDesc = true;
        return;
    }
    return;
}

/** Posa, lascia, dai
*/
void posa(void)
{
    if(numberObject==0) {
        esamina();
        return;
    }
    if(objloc[numberObject]!=-1) {
        writeln(donthavethat);
        return;
    }
    if(numberObject==3 && currentPosition==20) {
        writeln(wowpassage);
        ploc[20]=cunicolocontrave;
        pcon[20][2]=23;
        objloc[3]=0;
        --numberOfObjects;
        showDesc = true;
        return;
    }
    if(numberObject!=7 && numberObject!=11) {
        objloc[numberObject]=currentPosition;
        --numberOfObjects;
        showDesc = true;
        return; // goto 95
    }
    
    if(numberObject==7 && currentPosition==10) {
        writeln(skeletongoesout);
        pcon[10][5]=12;
        obj[9]=skeletonh;
        objloc[7]=0;
        scalaAperta=true;
    }
    if(numberObject==11 && mummiaSegue) {
        writeln(mummythanks);
        objloc[21]=0;
        objloc[11]=0;
        mummiaSegue=false;
    }

    --numberOfObjects;
    showDesc = true;
    return; // goto 95

}

/** Apri
*/
void apri(void)
{
    if(numberObject!=5) {
        writeln(what);
        return;
    }
    if(currentPosition!=5) {
        writeln(nothingtoopen);
        return;
    }
    if(!doorIsClosed) {
        writeln(itsopen);
        return;
    }
    if (objloc[2]!=-1) {
        writeln(nothingtodoit);
        return;
    }
    writeln("Ok.");
    doorIsClosed=false;
    pcon[5][1+1]=6;
    showDesc = true;
}


/** Suona
*/
void suona(void)
{
    if(numberObject!=6) {
        writeln("Eh?!");
        return;
    }
    if(objloc[6]!=-1) {
        writeln(stillcantdothat);
        return;
    }
    writeln(letstry);
    suspence();
    if(currentPosition!=15) {

        writeln(nothinghappens);
        return;
    }
    // musichetta
    writeln(itworkscobraaway);
    objloc[15]=0;
    cobraIsPresent=false;
    showDesc = true;
}

/** Wait for a few seconds.
*/
void suspence(void)
{
    writesameln(".");
    wait1s();
    writesameln(".");
    wait1s();
    writesameln(".");
    wait1s();
    writesameln(" ");
}

/** leggi
*/
void leggi(void)
{
    if(numberObject!=4 && numberObject!=16) {
        writeln(idontunderstand);
        return;
    }
    if(numberObject==4 && currentPosition==4) {
        writeln(getheretreasures);
        return;
    }
    if(numberObject==16 && objloc[16]==-1) {
        writeln(sayswaveme);
    }
}

/** Ondeggia
*/
void ondeggia(void)
{
    if(numberObject!=16) {
        writeln(idontunderstand);
        return;
    }
    if(currentPosition!=8) {
        writeln(nothinghappens);
        return;
    }
    if(objloc[16]==-1) {
        writeln("");
        suspence();
        writeln(passageopens);
        pcon[8][5+1]=16;
        passaggio12=true;
        ploc[8]=inawhiteroomo;
        showDesc=true;
    }
}

/** Scava
*/
void scava(void)
{
    if(numberObject!=22 && currentPosition>5) {
        writeln("Uhu?!");
        showDesc = true;
        return;
    }
    if(numberObject!=22) {
        writeln(ionlyhavehandstodig);
        return;
    }
    writesameln(idigwithmyhands);
    suspence();

    if(currentPosition==2&&objloc[2]==0) {
        writeln(ifoundsomething);
        showDesc = true;
        objloc[2]=2;
        return;
    }
    writeln(idonotfindanything);
}

/** Mangia
*/
void mangia(void)
{
    if(numberObject!=14 && numberObject!=16 && numberObject !=2) {
        writeln(idontlikeit);
        return;
    }
    writeln("Ok");
    suspence();
    if(objloc[14]==-1 || objloc[14]==currentPosition){
        writeln(scream);
        dropDead();
        return;
    }
    writeln(badtaste);
    objloc[numberObject]=0;
    showDesc = true;
}

/** Bevi
*/
void bevi(void)
{
    writeln(idontdrink);
    showDesc = true;
}

/** Chiudi
*/
void chiudi(void)
{
    writeln(betterleaveopen);
}


/** Rompi, sfonda
*/
void rompi(void)
{
    writeln(ifyoulikebreaking);
}
/** Accendi
*/
void accendi(void)
{
    if(numberObject!=1) {
        writeln(dontjoke);
        return;
    }
    if(objloc[1]!=-1) {
        writeln(idonothaveit);
        return;
    }
    if(torchIsOn && chargeOfBatteries!=0) {
        writeln(alreadyon);
        return;
    }
    if(chargeOfBatteries==0) {
        writeln(batterydischarged);
        return;
    }
    writeln("Ok.");
    torchIsOn=true;
    showDesc = true;
}

/** Spegni
*/
void spegni(void)
{
    if(numberObject!=1) {
        writeln(explainyourself);
        return;
    }
    if(objloc[1]!=-1) {
        writeln(cantdothat);
        return;
    }
    if(!torchIsOn) {
        writeln(alreadyoff);
        return;
    }
    writeln("Ok.");
    torchIsOn=false;
}


/** Salta
*/
void salta(void)
{
    if(currentPosition!=20) {
        writeln("Whee!");
        return;
    }
    if(currentPosition==20 && !passaggio12) {
        writeln(ifell);
        dropDead();
        return;
    }
}

/** Insulta
*/
void insulta(void)
{
    if(currentPosition<6) {
        writeln(lookbuddy);
        return;
    }
    if(currentPosition>6 && currentPosition<11) {
        writeln(youshouldtry);
        return;
    }
    if(currentPosition>=20 && objloc[3]==-1) {
        writeln(stopinsulting);
        return;
    }
    writeln(letssaywedidnotunderstand);
    return;
}

/** Cambia
*/
void cambia(void)
{
    if(numberObject!=13) {
        writeln(explainyourself);
        return;
    }
    if(objloc[13]!=-1) {
        writeln(idonthavebatteries);
        return;
    }
    if(chargeOfBatteries>0) {
        writeln(batteriesstillok);
        return;
    }
    writeln("Ok.");
    chargeOfBatteries=70;
    pitchBlack=false;
    objloc[13]=0;
    torchIsOn=true;
    showDesc = true;
    return; // goto 95
}

