#ifndef __ITALIAN_H__
#define __ITALIAN_H__

// Object descriptions
char* obj[22]=
    {"",
    "a torch",
    "a key",
    "a wooden girder",
    "a sign",
    "a door",
    "a flute",
    "a skull",
    "a *necklace encrusted with diamonds*",
    "a beheaded skeleton",
    "an altar stained with blood",
    "clean bandages",
    "an *golden axe*",
    "charged batteries",
    "drugs",
    "a cobra",
    "a *sapphire*",
    "a broken sword",
    "an *ancient vase*",
    "an open sarcophagus",
    "a *golden mask*",
    "a mummy with dirty bandages"};

#ifndef LONGVERSION
// Description of places, short version
char* ploc[25]= {"", "in the desert","in the desert","in the desert",
    "in the desert",
    "in the desert, in front of me there is a pyramid.",
    "in the antechamber of the Innuh's pyramid.",
    "in a triangular room.",
    "in a white room. A sapphire is set on the wall.",
    "in a recess.",
    "in a hallway.",
    "in a red room.",
    "in a small room.",
    "in the alchemists laboratory.",
    "in the embalmer's room.",
    "in Iankho's room.",
    "in a tunnel.",
    "in a tunnel. An ancient writing says: do not pass, or YOU'LL DIE.",
    "in a tunnel. An ancient writing says: do not pass, or YOU'LL DIE.",
    "in a green room",
    "in a narrow tunnel, with a trench too wide to be jumped across.",
    "in the old armory.",
    "in the hieroglyphic's room.",
    "in Hanyke's room.",
    "in the funerary chapel."};
#else
// Description of places, longer version.
char* ploc[25]= {"", "in the desert","in the desert","in the desert",
    "in the desert",
    "in the desert, in front of me there is a pyramid. Tall and huge, it is "
    "the tomb of the ancient pharaoh Innuh.",
    "in the antechamber of the Innuh's pyramid. Unadorned, the walls bear "
    "still  visible the holes used to hoist the magnificent sarcophagus during "
    "the funeral  ceremony.",
    "in a triangular room. Someone has been here in the past. Many traces are "
    "visible, but the dust now covers them. The last visitor must "
    "have come here at least one year ago.",
    "in a white room. Colour comes from the perfectly polished marble employed "
    "  for the walls. The alignment of the marble plates is "
    "astounding.\nA sapphire is set in the centre of one of the walls.",
    "in a small recess, inside the stone wall.",
    "in a long hallway, paved with stones of different sizes, tracing "
    "irregular  patterns on the ground.",
    "in a room with red granite walls.",
    "in a small room, with the pharaoh's cartouche visible on the ceiling.",
    "in the alchemist's laboratory. Instruments have been stolen long ago, but "
    "  smoke and traces of chemical substances still stain the walls.",
    "in the embalmer's room, beautifully decorated with multicolour paintings.",
    "in Iankho's room, the great priest of the pharaoh.",
    "in a gallery.",
    "in a tunnel. An ancient writing says: do not pass, or YOU'LL DIE.",
    "in a tunnel. An ancient writing says: do not pass, or YOU'LL DIE.",
    "in a green room",
    "in a narrow tunnel, with a trench too wide to be jumped across.",
    "in the old armoury, with corroded bronze hooks still attached to the "
    "walls.",
    "in the hieroglyphics' room. They are carved in the wall, they seem "
    "to describe ancient formulas and spells for alchemists.",
    "in Hanyke's room. She was the wife of the pharaoh and her effigy as "
    "the Nut goddess rising among sycamore leaves covers the vault in "
    "a colourful and living portrait on a blue starry background.",
    "in the funerary chapel. Figures from the Book of the Dead are painted on "
    "the walls, with among other things Anubi weighing the heart of the dead."};
#endif

// Abbreviated names
char *namesabb[NN] = {"", "torc", "key ", "gird", "sign", "door",
    "flut", "skul", "neck", "skel", "alta", "band", "axe ", "batt", "drug",
    "cobr", "sapp", "swor", "vase", "sarc", "mask", "mumm", "sand", "room",
    "hier", "room", "hall", "tunn", "ladd", "nort", "sout", "east", "west",
    "up  ", "down", "n   ", "s   ", "e   ", "w   ", "abov", "belo", "arou"};

// Abbreviated verbs
char *verbsabb[NV] = {"",   "poin", "exit", "inve", "i   ", "see ", "go  ",
    "run ", "walk", "look", "take", "grab", "put ", "leav", "give", "open",
    "*   ", "play", "read", "wave", "dig ", "eat ", "drin", "clos", "drop",
    "dest", "ligh", "swit", "jump", "fuck", "get ", "chan"};

char *cunicolostretto=
    "in a narrow tunnel, with a trench too large to be jumped across.";
char *cunicolocontrave=
    "in a narrow tunnel, with a trench too large to be jumped across. "
    "There is a girder, though, put there as a bridge.";

char *scheletrocontento="A happy skeleton.";

char* directions[7] = {"", "north", "south", "east", "west", "up  ",
    "down"};

char* doorclose="The door is closed.";
char* dooropen="The door is open.";
char* icangoto="I can go to: ";
char* adventurefinished="Congratulations! You finished the adventure.";
char* iamdead="I'm dead!";
char* mummyfollowing="The mummy's following me!";
char* whatshallido="What shall I do?";
char* whatdoyoumean=" what?";
char* idontunderstand="I don't understand.";
char* itspitchblack="Now it's pitch black. It is dangerous to wander around in this darkness.";
char* iam="I'm ";
char* mummyattacks="Help! The mummy attacks!";
char* isee="I see: ";
char* unknownverb="Unrecognized verb.";
char* yougot="You got ";
char* ihavewithme="I have with me:";
char* nothing="Nothing.";
char* idonotknowthisword="I don't understand this word.";
char* idonotunderstand="I don't understand.";
char* icantdothatyet="I can't do that, yet.";
char* ifell="I fell and I break my neck!";
char* cantgothere="I can't go over there!";
char* dontknowthatword="I don't understand this word: ";
char* somethingiswritten="Something is written on it.";
char* iseesomething="I see something...";
char* torchdesc="It is a nice professional torch, with a very powerful light "
    "bulb and a Fresnel lens.";
char* anythingspecial="I don't see anything special.";
char* idonotsee="I don't see any ";
char* aroundhere=" around here";
char* dontbesilly="Don't be silly!";
char* dontbestupid="Don't act as a stupid person!";
char* cantcarrymore="I can't carry more than that.";
char* cobrabitten="The cobra bit me!";
char* donthavethat="I do not have that with me.";
char* wowpassage="Wow! Now I can go south by walking on the girder.";
char* skeletongoesout="The skeleton puts the skull on his shoulders, then "
    "pulls a lever and a ladder   comes down from the ceiling.";
char* mummythanks="The mommy says: -Thank you stranger, it was about time that "
    "someone comes. Now I can rest in peace for another two thousands "
    "years.-  It then takes clean bandages and goes away.";
char* nothingtoopen="There is anything to open here.";
char* itsopen="It's already open!";
char* nothingtodoit="I do not have anything for it.";
char* stillcantdothat="I can't do that yet.";
char* letstry="Let's try!";
char* nothinghappens="Nothing happens.";
char* itworkscobraaway="It works! The cobra goes away.";
char* getheretreasures="It tells: -collect here your treasures-";
char* sayswaveme="It says: -wave me-";
char* passageopens="\nIt's incredible! The wall lights up and a passage "
    "appears, bringing downstairs.";
char* inawhiteroom="in a white room, with a passage towards downstairs.";
char* ionlyhavehandstodig="I only have my bare hands. I can only dig the sand.";
char* idigwithmyhands="I dig with my bare hands and";
char* ifoundsomething="I find something!";
char* idonotfindanything="I don't find anything.";
char* idontlikeit="I don't like it!";
char* scream="AAGHHH!";
char* badtaste="It does not taste good.";
char* idontdrink="I won't drink that!";
char* betterleaveopen="Better leave that open. Who knows?";
char* ifyoulikebreaking="If you like breaking things, you should definitely "
    "choose another type of game!";
char* dontjoke="Don's make jokes.";
char* idonothaveit="I don't have that with me.";
char* alreadyon="It's already on.";
char* batterydischarged="I can't do that, batteries are dead!";
char* explainyourself="Explain yourself.";
char* cantdothat="I cant't do that.";
char* alreadyoff="It's already switched off.";
char* lookbuddy="Listen, the adventure will be long if you start this way!";
char* youshouldtry="For me, the situation is quite difficult. You should try "
    "to be at my place.";
char* stopinsulting="Stop cursing and use your brain!";
char* letssaywedidnotunderstand="Let's say that I did not understand...";
char* idonthavebatteries="I do not have charged batteries with me.";
char* batteriesstillok="Those already in are still working fine.";
char* what="What?";

// the '\b' character is used to pause the execution in a very small screen

char* gamepres=
    "\t\t\t===================\n"
    "\t\t\t-THE INNUH'S PYRAMID-\n"
    "\t\t\t===================\n"
    "\n"
    "Originally on TI99/4A by Aristide Torrelli (MCmicrocomputer 33, sett. 1984).\n"
    "ZX Spectrum version by Manlio Severi, (MCmicrocomputer 35, nov. 1984).\n"
    "C language and English translation by Davide Bucci "
    "(davbucci@tiscali.it)\n"
    "Sept. 16 2018.\n"
    "\n"
    "\b"
    "The Innuh's pyramid was built three thousand years ago, somewhere in "
    "the desert.\n"
    "Ancient tales say it is full of *treasures*, but nobody who dared "
    "to try to\nreveal its secrets could come back to tell his adventure.\n\n"
    "I'll be your eyes and ears.\n"
    "Your goal is to find all the *treasures* hidden in the pyramid.\n\n"
    "Good luck, you'll need it!\n\b";

#endif