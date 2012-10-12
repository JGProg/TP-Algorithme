exo3:	exo3.o liste.o
	gcc -Wall exo3.o liste.o -o exo3

liste.o:	liste.c liste.h
	gcc -Wall -c liste.c -o liste.o

exo3.o: exo3.c liste.h
	gcc -Wall -c exo3.c -o exo3.o

clean:
	rm exo3.o liste.o
