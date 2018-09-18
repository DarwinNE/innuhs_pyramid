# The Innuh's pyramid

Originally on TI99/4A by Aristide Torrelli (MCmicrocomputer 33, sett. 1984).
ZX Spectrum version by Manlio Severi, (MCmicrocomputer 35, nov. 1984).
C language transcription, improvements and English translation by Davide Bucci.

Remarkably enough, in the original version of the game, the name of the pyramid is Iunnuh, and not Innuh. As you surely know, hieroglyphs do not use vocals, the second variant comes from a different transliteration of the pharaoh's cartouche found in the pyramid (more seriously, I mis-read the title of the game and I did not realise for 25 years!)

This game is a text adventure. You should play it by giving simple orders to your alter-ego in the game. Explore the situations and beware to the risks!

*The Innuh's pyramid was built three thousand years ago, somewhere in the desert.*
*Ancient tales say it is full of treasures, but nobody who dared to try to
reveal its secrets could come back to tell his adventure.*

*I'll be your eyes and ears.*
*Your goal is to find all the treasures hidden in the pyramid.*

*__Good luck, you'll need it!__*

The game is currently playable on the Commodore C128 (in 80-column mode), on the Commodore VIC-20 with the 16K RAM expansion and on a modern computer terminal.

To compile sources, you will need:

* `gcc`
* `Cc65`
* `make`

download the sources and type `make` in the directory where the code is present.
The following files will be created:

* `innuh-en` modern OS executable (maybe with a .exe extension if you are using Windows) with the English version of the game
* `innuh-en` modern OS executable (maybe with a .exe extension if you are using Windows) with the Italian version of the game
* `innuh-c128-it.prg` the Commodore C128 version of the game, in Italian
* `innuh-c128-en.prg` the Commodore C128 version of the game, in English
* `innuh-vic-it.prg` the Commodore VIC-20+16K version of the game, in Italian
* `innuh-vic-en.prg` the Commodore VIC-20+16K version of the game, in English

I tested the VIC-20 and the C128 versions on VICE emulators as well as on the real hardware (both PAL machines: the VIC-20 is a CR European version and the C128 is a C128D with the plastic case).

Here is the list of words understood by the game, while playing the version in English:
```
torch, key, girder, sign, door, flute, skull, necklace, skeleton,
altar, bandages, axe, batteries, drugs, cobra, sapphire, sword, vase,
sarcophagus, mask, mommy, sand, room, hieroglyphic, room, hallway,
tunnel, ladder, north, south, east, west, up, down, n, s, e, w, above, below,
switch off, exit, inventary, i, look, go, run, walk, see, take, grab, put, 
leave, give , open, *, play, read, wave, dig, eqt, drink, close,
grab, destroy, light, switch off, jump, change, around, get
```

Here is the list for the version in Italian:
```
torcia, chiave, trave, scritta, porta, flauto, teschio, collana, scheletro,
altare, bende, scure, batterie, droghe, cobra, zaffiro, spada, vaso, sarcofago,
maschera, mummia, sabbia, stanza, geroglifico, sala, corridoio, cunicolo, scala,
nord, sud, est, ovest, su, giù, n, s, e, o, sopra, sotto, punteggio, arrenditi,
inventario, i, guarda, vai, corri, cammina, esamina, prendi, piglia, posa, 
lascia, dai , apri, *, suona, leggi, ondeggia, scava, mangia, bevi, chiudi,
rompi, sfonda, accendi, spegni, salta, cambia, attorno, afferra
```

Here a few hints:
* To repeat the description of the current location, type `look around` (`esamina attorno`) or `see` (`vedi`) or simply `*`.
* You are not Hercules and you can not carry too many objects with you.


