all:    modern_en modern_it c128_en vic20_en c64_en pet_en c128_it vic20_it c64_it pet_it plus4_en plus4_it clean

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

pet_en:
	cc65 innuh.c -t pet -D PET -o innuh-pet-en.s
	cl65 innuh-pet-en.s -t pet -o innuh-pet-en.prg
	rm innuh-pet-en.s

plus4_en:
	cc65 innuh.c -t plus4 -D PLUS4 -o innuh-plus4-en.s
	cl65 innuh-plus4-en.s -t plus4 -o innuh-plus4-en.prg
	rm innuh-plus4-en.s


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

pet_it:
	cc65 innuh.c -t pet -D PET -D ITALIAN -o innuh-pet-it.s
	cl65 innuh-pet-it.s -t pet -o innuh-pet-it.prg
	rm innuh-pet-it.s

plus4_it:
	cc65 innuh.c -t plus4 -D PLUS4 -D ITALIAN -o innuh-plus4-it.s
	cl65 innuh-plus4-it.s -t plus4 -o innuh-plus4-it.prg
	rm innuh-plus4-it.s

clean:
	rm *.o
    