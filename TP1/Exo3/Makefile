exo3:	exo3.o liste.o
	gcc -Wall exo3.o liste.o -o exo3

liste.o:	liste.c liste.h
	gcc -Wall -c liste.c

exo3.o: exo3.c liste.h
	gcc -Wall -c exo3.c

clean:
	rm exo3.o liste.o
