exo1:	exo1.o pile.o
	gcc -Wall exo1.o pile.o -o exo1

pile.o:	pile.c pile.h
	gcc -Wall -c pile.c

exo1.o: exo1.c pile.h
	gcc -Wall -c exo1.c

clean:
	rm exo1.o pile.o exo1
