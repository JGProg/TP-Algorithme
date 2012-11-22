tp3: tp3.o Graphe.o
	gcc -Wall tp3.o Graphe.o -o tp3

Graphe.o: Graphe.c Graphe.h
	gcc -Wall -c Graphe.c

tp3.o: tp3.c Graphe.h
	gcc -Wall -c tp3.c

clean:
	rm tp3.o Graphe.o tp3
