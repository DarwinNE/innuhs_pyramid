all:    modern_en modern_it  c128_en vic20_en c64_en pet_en ti_en_40 ti_en_80 c128_it vic20_it c64_it pet_it plus4_en plus4_it ti_it_40 ti_it_80 clean

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

ti_en_40:
	/usr/local/bin/gccti/bin/tms9900-as  ti994a_crt0.asm -o ti994a_crt0.o
	/usr/local/bin/gccti/bin/tms9900-gcc ti994a_compat.c -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-gcc innuh.c -o innuh-ti-en-40.o -D TI994A -D NCOL=40 -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-ld innuh-ti-en-40.o ti994a_compat.o ti994a_crt0.o -L"libti99" -lti99 -o inutien40.elf --script=ti994a_linkfile
	../elf2ea5/elf2ea5 inutien40.elf inutien40.ea5
	../ea5split/ea5split inutien40.ea5

ti_en_80:
	/usr/local/bin/gccti/bin/tms9900-as  ti994a_crt0.asm -o ti994a_crt0.o
	/usr/local/bin/gccti/bin/tms9900-gcc ti994a_compat.c -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-gcc innuh.c -o innuh-ti-en-80.o -D TI994A -D NCOL=80 -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-ld innuh-ti-en-80.o ti994a_compat.o ti994a_crt0.o -L"libti99" -lti99 -o inutien80.elf --script=ti994a_linkfile
	../elf2ea5/elf2ea5 inutien80.elf inutien80.ea5
	../ea5split/ea5split inutien80.ea5

ti_it_40:
	/usr/local/bin/gccti/bin/tms9900-as  ti994a_crt0.asm -o ti994a_crt0.o
	/usr/local/bin/gccti/bin/tms9900-gcc ti994a_compat.c -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-gcc innuh.c -o innuh-ti-it-40.o -D ITALIAN -D TI994A -D NCOL=40 -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-ld innuh-ti-it-40.o ti994a_compat.o ti994a_crt0.o -L"libti99" -lti99 -o inutiit40.elf --script=ti994a_linkfile
	../elf2ea5/elf2ea5 inutiit40.elf inutiit40.ea5
	../ea5split/ea5split inutiit40.ea5

ti_it_80:
	/usr/local/bin/gccti/bin/tms9900-as  ti994a_crt0.asm -o ti994a_crt0.o
	/usr/local/bin/gccti/bin/tms9900-gcc ti994a_compat.c -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-gcc innuh.c -o innuh-ti-it-80.o -D ITALIAN -D TI994A -D NCOL=80 -c -O2 -std=c99 -Wall
	/usr/local/bin/gccti/bin/tms9900-ld innuh-ti-it-80.o ti994a_compat.o ti994a_crt0.o -L"libti99" -lti99 -o inutiit80.elf --script=ti994a_linkfile
	../elf2ea5/elf2ea5 inutiit80.elf inutiit80.ea5
	../ea5split/ea5split inutiit80.ea5


clean:
	rm *.o -f
	rm *.elf -f
	rm *.ea5 -f
	rm *.s -f

