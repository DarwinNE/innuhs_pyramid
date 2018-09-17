#ifndef __ITALIAN_H__
#define __ITALIAN_H__

// Number of complete descriptions of objects
#define LO 41
#define NV 32

// Object descriptions
char* obj[22]=
    {"",
    "una torcia",
    "una chiave",
    "una trave di legno",
    "una scritta",
    "una porta",
    "un flauto",
    "un teschio",
    "una *collana d'oro*",
    "uno scheletro senza testa",
    "un altare insanguinato",
    "bende pulite",
    "una *scure d'oro*",
    "batterie cariche",
    "droghe",
    "un cobra velenoso",
    "uno *zaffiro*",
    "una spada rotta",
    "un *antico vaso*",
    "un sarcofago aperto",
    "una *maschera d'oro*",
    "una mummia con le bende sporche"};

// Description of places
char* ploc[25]= {"", "nel deserto","nel deserto","nel deserto","nel deserto",
    "nel deserto, di fronte c'e' una piramide.",
    "nell'anticamera della piramide di Innuh.",
    "in una stanza triangolare.",
    "in una sala bianca e sul muro c'e' incastonato uno zaffiro.",
    "in una nicchia.",
    "in un corridoio.",
    "in una sala rossa.",
    "in una saletta.",
    "nella sala dell'alchimista.",
    "nella sala dell'imbalsamatore.",
    "nella stanza di Iankho.",
    "in un tunnel.",
    "in un tunnel. Una scritta dice: non passare, o MORIRAI.",
    "in un tunnel. Una scritta dice: non passare, o MORIRAI.",
    "in una stanza verde.",
    "in un cunicolo stretto con un fosso troppo largo da saltare.",
    "nella vecchia armeria.",
    "nella sala dei geroglifici.",
    "nella sala di Hanyke.",
    "nella cappella funeraria."};

// Abbreviated names
char *namesabb[LO] = {"", "torc", "chia", "trav", "scri", "port",
    "flau", "tesc", "coll", "sche", "alta", "bend", "scur", "batt", "drog",
    "cobr", "zaff", "spad", "vaso", "sarc", "masc", "mumm", "sabb", "stan",
    "gero", "sala", "corr", "cuni", "scal", "nord", "sud ", "est ", "oves",
    "su  ", "giu ", "n   ", "s   ", "e   ", "o   ", "sopr", "sott"};

// Abbreviated verbs
char *verbsabb[NV] = {"", "punt", "arre", "inve", "i   ", "guar", "vai ",
    "corr", "camm", "esam", "pren", "pigl", "posa", "lasc", "dai ", "apri",
    "*   ", "suon", "legg", "onde", "scav", "mang", "bevi", "chiu", "romp",
    "sfon", "acce", "speg", "salt", "vaff", "crep", "camb"};


char *cunicolostretto=
    "In un cunicolo stretto, con un fosso troppo largo da saltare.";
char *cunicolocontrave=
    "In un cunicolo stretto, con un fosso troppo largo da saltare, "
    "ma c'e' una trave che fa da passaggio.";
char *scheletrocontento="Uno scheletro contento.";

char* directions[7] = {"", "nord", "sud ", "est ", "ovest", "sopra",
    "sotto"};

char* doorclose="La porta e' chiusa.";
char* dooropen="La porta e' aperta.";
char* icangoto="Posso andare a: ";
char* adventurefinished="Complimenti! Hai risolto l'avventura.";
char* iamdead="Sono morto!";
char* mummyfollowing="La mummia mi segue!";
char* whatshallido="Cosa devo fare?";
char* whatdoyoumean=" cosa?";
char* idontunderstand="Non ho capito.";
char* itspitchblack="Ora e' buio pesto! E' pericoloso muoversi alla cieca";
char* iam="Sono ";
char* mummyattacks="Aiuto! La mummia mi attacca!";
char* isee="Vedo: ";
char* unknownverb="Verbo non riconosciuto.";
char* yougot="Hai raggiunto il ";
char* ihavewithme="Ho con me:";
char* nothing="nulla.";
char* idonotknowthisword="Non conosco questa parola";
char* idonotunderstand="Non ti capisco";
char* icantdothatyet="Ancora non posso farlo.";
char* ifell="Sono caduto e mi sono rotto la testa!";
char* cantgothere="Non posso andare di la'!";
char* dontknowthatword="Non conosco la parola ";
char* somethingiswritten="C'e' scritto qualcosa";
char* iseesomething="Vedo qualcosa...";
char* torchdesc="E' un bel modello di torcia elettrica professionale: 1000 "
         "candele e lente di Fresnel.";
char* anythingspecial="Non vedo nulla di speciale.";
char* idonotsee="Non vedo ";
char* aroundhere=" qui intorno";
char* dontbesilly="Non essere sciocco!";
char* dontbestupid="Non fare lo scemo!";
char* cantcarrymore="Non riesco a  portare nient'altro";
char* cobrabitten="Il cobra mi ha morso!";
char* donthavethat="Non l'ho con me.";
char* wowpassage="Wow! Ora posso andare a sud passando sulla trave.";
char* skeletongoesout="Lo scheletro se lo mette sulle spalle, poi tira una "
        "leva e una scala scende dal soffitto.";
char* mummythanks="La mummia dice: -Grazie, straniero, era proprio ora che "
        "qualcuno passasse! Ora potro' passare altri duemila anni in pace-"
        " prende le bende e se ne va";
char* nothingtoopen="Qui non c'e' nulla da aprire.";
char* itsopen="Ma e' aperta!";
char* nothingtodoit="Non ho nulla per farlo.";
char* stillcantdothat="Ancora non posso farlo.";
char* letstry="Proviamo";
char* nothinghappens="Non accade nulla.";
char* itworkscobraaway="Funziona! Il cobra si allontana.";
char* getheretreasures="Dice: portare qui i tesori.";
char* sayswaveme="Dice: ondeggiami.";
char* passageopens="Incredibile! Il muro si illumina e appare un passaggio che "
        "porta di sotto.";
char* inawhiteroom="in una sala bianca, c'e' un passaggio che porta di sotto.";
char* ionlyhavehandstodig="Ho solo le mani per scavare; posso scavare solo la "
        "sabbia.";
char* idigwithmyhands="Scavo con le mani e";
char* ifoundsomething="Trovo qualcosa!";
char* idonotfindanything="Non trovo nulla.";
char* idontlikeit="Non mi piace!";
char* scream="AAGHHH!";
char* badtaste="Non ha un buon sapore.";
char* idontdrink="Questa non me la bevo!";
char* betterleaveopen="Meglio lasciare tutto aperto, non si sa mai.";
char* ifyoulikebreaking="Se ti piace sfasciare le cose, perche' non giochi ad "
        "uno sparatutto?";
char* dontjoke="Non scherzare.";
char* idonothaveit="Non l'ho con me.";
char* alreadyon="E' gia' accesa.";
char* batterydischarged="Non posso, le batterie si sono scaricate!";
char* explainyourself="Spiegati meglio.";
char* cantdothat="Non posso.";
char* alreadyoff="E' gia' spenta.";
char* lookbuddy="Guarda che l'avventura e' lunga e difficile se cominci in "
        "questo modo!";
char* youshouldtry="Per me e' oltremodo difficile, dovresti provare tu.";
char* stopinsulting="Smettila di imprecare ed usa il cervello!";
char* letssaywedidnotunderstand="Beh, facciamo finta di non aver capito...";
char* idonthavebatteries="Non ho batterie cariche con me.";
char* batteriesstillok="Quelle che ci sono vanno ancora bene.";

// the '\b' character is used to pause the execution in a very small screen

char* gamepres=
    "\t\t\t====================\n"
    "\t\t\t-LA PIRAMIDE DI INNUH-\n"
    "\t\t\t====================\n"
    "\n"
    "Versione per TI99/4A, Aristide Torrelli (MCmicrocomputer 33, sett. 1984).\n"
    "Versione per ZX Spectrum, Manlio Severi, (MCmicrocomputer 35, nov. 1984).\n"
    "Versione C di Davide Bucci, 16 settembre 2018 (davbucci@tiscali.it).\n"
    "\n\b"
    "Da qualche parte nel deserto giace la piramide di Innuh.\n"
    "Le antiche leggende dicono che sia piena di *tesori*, ma nessun uomo che "
    "abbia cercato di svelarne il segreto e' mai tornato indietro per "
    "raccontarlo.\n"
    "Saro' per te occhi ed orecchie.\n"
    "Il tuo scopo e' di portar via tutti i *tesori* che la piramide nasconde.\n"
    "Buona fortuna, ne avrai bisogno!\n\b";

#endif