arbre:	tp2.o Arbre.o
	gcc -gdb -Wall tp2.o Arbre.o -o tp2

arbre.o:	Arbre.c Arbre.h
	gcc -Wall -c Arbre.c

tp2.o: tp2.c Arbre.h
	gcc -Wall -c tp2.c

clean:
	rm tp2.o Arbre.o tp2
