

my.pre: main.o cmnd_rm.o head_inc.o macro_rp.o 
	gcc main.o cmnd_rm.o head_inc.o macro_rp.o -o my.pre

main.o: main.c header.h
	gcc -c main.c
cmnd_rm.o: cmnd_rm.c header.h
	gcc -c cmnd_rm.c
head_inc.o: head_inc.c header.h
	gcc -c head_inc.c
macro_rp.o: macro_rp.c header.h
	gcc -c macro_rp.c
