all:
	gcc innuh.c -o innuh-en
	gcc innuh.c -D ITALIAN -o innuh-it

	cc65 innuh.c -t c128 -D C128 -o innuh-c128-en.s
	cl65 innuh-c128-en.s -t c128 -o innuh-c128-en.prg
	rm innuh-c128-en.s
	
	cc65 innuh.c -t vic20 -D VIC20 -C vic20-16k_exp.cfg -o innuh-vic-en.s
	cl65 innuh-vic-en.s -t vic20 -C vic20-16k_exp.cfg -o innuh-vic-en.prg
	rm innuh-vic-en.s
	
	cc65 innuh.c -t c128 -D C128 -D ITALIAN -o innuh-c128-it.s
	cl65 innuh-c128-it.s -t c128 -o innuh-c128-it.prg
	rm innuh-c128-it.s

	cc65 innuh.c -t vic20 -D VIC20  -D ITALIAN -C vic20-16k_exp.cfg -o innuh-vic-it.s
	cl65 innuh-vic-it.s -t vic20 -C vic20-16k_exp.cfg -o innuh-vic-it.prg
	rm innuh-vic-it.s
	
	rm *.o
    