arbre:	tp2.o Arbre.o
	gcc -Wall tp2.o Arbre.o -o tp2

arbre.o:	Arbre.c Arbre.h
	gcc -c Arbre.c -o arbre.o

tp2.o: tp2.c Arbre.h
	gcc -c tp2.c -o tp2.o

clean:
	rm tp2.o Arbre.o tp2
