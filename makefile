all:    modern_en modern_it c128_en vic20_en c64_en c128_it vic20_it c64_it clean

modern_en:
	gcc innuh.c -o innuh-en

modern_it:
	gcc innuh.c -D ITALIAN -o innuh-it

c128_en:
	cc65 innuh.c -t c128 -D C128 -o innuh-c128-en.s
	cl65 innuh-c128-en.s -t c128 -o innuh-c128-en.prg
	rm innuh-c128-en.s

vic20_en:
	cc65 innuh.c -t vic20 -D VIC20 -C vic20-16k_exp.cfg -o innuh-vic-en.s
	cl65 innuh-vic-en.s -t vic20 -C vic20-16k_exp.cfg -o innuh-vic-en.prg
	rm innuh-vic-en.s
	
c64_en:
	cc65 innuh.c -t c64 -D C64 -o innuh-c64-en.s
	cl65 innuh-c64-en.s -t c64 -o innuh-c64-en.prg
	rm innuh-c64-en.s

c128_it:
	cc65 innuh.c -t c128 -D C128 -D ITALIAN -o innuh-c128-it.s
	cl65 innuh-c128-it.s -t c128 -o innuh-c128-it.prg
	rm innuh-c128-it.s

vic20_it:
	cc65 innuh.c -t vic20 -D VIC20  -D ITALIAN -C vic20-16k_exp.cfg -o innuh-vic-it.s
	cl65 innuh-vic-it.s -t vic20 -C vic20-16k_exp.cfg -o innuh-vic-it.prg
	rm innuh-vic-it.s

c64_it:
	cc65 innuh.c -t c64 -D C64 -D ITALIAN -o innuh-c64-it.s
	cl65 innuh-c64-it.s -t c64 -o innuh-c64-it.prg
	rm innuh-c64-it.s

clean:
	rm *.o
    