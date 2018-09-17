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
    c1          doorIsOpen
    c2          cobraIsPresent
    fbc         chargeOfBatteries
*/

#include<stdio.h>
#include<string.h>

#include"innuh.h"

#ifdef C128
    #include"c128_codes.h"
#elif defined(VIC20)
    #include"vic20_codes.h"
#else
    #include"modern.h"
#endif


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
boolean doorIsOpen;

// Cobra (true: is present, false: is absent)
boolean cobraIsPresent;

// Current position of the player
int currentPosition;

// It is true if the description has changed and should be shown.
boolean showDesc;

char q[BUFFERSIZE];

// The index of the found verb
int verb=0;

#define NN 40


int numberOfObjects;

char buffer[BUFFERSIZE];

boolean isDead;

// Batteries charged or not
int chargeOfBatteries;
char* istring;


// Connections between places
int pcon[25][7] =
    {{0,0,0,0,0,0,0}, // This index is not used
    {0,2,4,2,1,0,0},        // 1 Deserto
    {0,2,3,3,1,0,0},        // 2 Deserto
    {0,2,5,2,4,0,0},        // 3 Deserto
    {0,1,5,3,4,0,0},        // 4 Deserto
    {0,4,0,3,0,0,0},        // 5 Deserto, di fronte ad una piramide
    {0,5,10,7,8,0,0},       // 6 Anticamera
    {0,0,10,0,6,0,0},       // 7 Stanza triangolare
    {0,0,9,6,0,0,0},        // 8 Sala bianca
    {0,8,0,10,0,0,0},       // 9 Nicchia
    {0,6,0,7,9,0,0},        // 10 Corridoio
    {0,0,13,14,0,0,0},      // 11
    {0,0,15,13,0,0,10},     // 12
    {0,11,15,14,12,0,0},    // 13
    {0,11,0,0,13,0,0},      // 14
    {0,13,0,0,12,0,0},      // 15
    {0,0,0,17,0,8,0},       // 16
    {0,0,0,18,16,0,0},      // 17
    {0,0,21,19,17,0,0},     // 18
    {0,0,0,0,18,0,0},       // 19
    {0,0,0,21,0,0,0},       // 20
    {0,18,0,22,20,0,0},
    {0,0,0,0,21,0,0},
    {0,20,24,0,0,0,0},
    {0,23,0,0,0,0,0}};

// The locations of the different objects
int objloc[22];
const int objloc_org[] = {0,1,0,3,4,5,6,8,9,10,11,11,11,
    12,13,15,15,16,22,24,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void (*actions[NV])(void) ={NULL,&punteggio,&resa,&inventario,
    &inventario,&guarda,&vai,&vai,
    &vai,&esamina,&prendi,&prendi,&posa,&posa,&posa,&apri,
    &guarda,&suona,&leggi,&ondeggia,&scava,&mangia,&bevi,&chiudi,
    &rompi,&rompi,&accendi,&spegni,&salta,&insulta,&insulta,&cambia};


int main(int argc, char** argv)
{
    init_term();
    setup();
    presentation();
    while(!isDead)
        play();

    leave();
    return 0;
}

void presentation(void)
{
    writeln(gamepres);
}


void process(char *line)
{
    int i;
    boolean flag=false;
    char c;

    for(i=0; (c=line[i])!=0;++i) {
        if(c=='*' && flag==false) {
            evidence2();
            flag=true;
        } else if(c=='*' && flag==true) {
            normaltxt();
            flag=false;
        } else if(c=='-' && flag==false) {
            evidence1();
            flag=true;
        } else if(c=='-' && flag==true) {
            normaltxt();
            flag=false;
        } else if(c=='\b') {
            waitscreen();
        } else if(c=='\t') {
            tab();
        } else {
            putc(c, stdout);
        }
    }
}

void writeln(char* line)
{
    process(line);
    printf("\n");
}
void writesameln(char* line)
{
    process(line);
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
    doorIsOpen = true;
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
    if((currentPosition==4)&&(objloc[8]==currentPosition)&&
       (objloc[12]==currentPosition)&&(objloc[16]==currentPosition)&&
       (objloc[18]==currentPosition)&&(objloc[20]==currentPosition)) {
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
            fstsee=false;
            // one may test if the index i is valid...
            writesameln(obj[i]);
            writesameln(", ");
        }
    }
    writeln("");

    if(currentPosition==5 && doorIsOpen) {
        writeln(doorclose);
    }
    if(currentPosition==5 && !doorIsOpen) {
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
    return;
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

/** Main parsing function
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
    
    for(i=0; i<lc; ++i) {
        if(playerInput[i]==' ')
            break;
        s[i]=playerInput[i];
        ++ls;
    }
    ols=ls;
    // Compensate for strings smaller than 4 chars
    if(ls<4) {
        for(x=0; x<=4-ls;++x)
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


    if (!flag) {
        verb=6;
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
    else
        writeln("Unimplemented action.");
    
}

/** Calcola il punteggio totale raggiunto.
*/
void punteggio(void)
{
    int der1 = 0;
    if (objloc[8]==-1)
        ++der1;
    if (objloc[12]==-1)
        ++der1;
    if (objloc[18]==-1)
        ++der1;
    if (objloc[20]==-1)
        ++der1;
    if (objloc[16]==-1)
        ++der1;

    writesameln(yougot);
    printf("%d%%\n",(der1*20+(der1>0?5:0)));
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
    for(i = 0; i<LO; ++i)
    {
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
    if(currentPosition==5 && numberObject ==5 && !doorIsOpen) {
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
    if(numberObject==0) {
        writesameln(dontknowthatword);
        writeln(q);
        return;
    }
    if((numberObject==4 && currentPosition==4) || (numberObject==16 &&
        objloc[16]==-1)) {
        writeln(somethingiswritten);
        return;
    }
    if(currentPosition==24 && numberObject==19) {
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
    if(numberObject!=3 && numberObject!=7 && numberObject!=11) {
        objloc[numberObject]=currentPosition;
        --numberOfObjects;
        showDesc = true;
        return; // goto 95
    }
    if(numberObject==3 && currentPosition==20) {
        writeln(wowpassage);
        ploc[20]=cunicolocontrave;
        pcon[20][2]=23;
        objloc[3]=0;
    }
    if(numberObject==7 && currentPosition==10) {
        writeln(skeletongoesout);
        pcon[10][5]=12;
        obj[9]=scheletrocontento;
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
        writeln("Uhu?!");
        return;
    }
    if(currentPosition!=5) {
        writeln(nothingtoopen);
        return;
    }
    if(!doorIsOpen) {
        writeln(itsopen);
        return;
    }
    if (objloc[2]!=-1) {
        writeln(nothingtodoit);
        return;
    }
    writeln("Ok.");
    doorIsOpen=false;
    pcon[5][1+1]=6;
    showDesc = true;
    return;
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
    return; // goto 95
}

/** Wait for a few seconds.
*/
void suspence(void)
{
    writesameln("... ");
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
        return;
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
        ploc[8]=inawhiteroom;
        showDesc=true;
        return;
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
    return;
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
    return;

}

/** Bevi
*/
void bevi(void)
{
    writeln(idontdrink);
    showDesc = true;
    return;
}

/** Chiudi
*/
void chiudi(void)
{
    writeln(betterleaveopen);
    return;
}


/** Rompi, sfonda
*/
void rompi(void)
{
    writeln(ifyoulikebreaking);
    return;
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
    return;
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
    return;
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
    return;
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
