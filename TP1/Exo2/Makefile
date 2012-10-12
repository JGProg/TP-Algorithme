exo2:	exo2.o file.o
	gcc -Wall exo2.o file.o -o exo2

file.o:	file.c file.h
	gcc -Wall -c file.c -o file.o

exo2.o: exo2.c file.h
	gcc -Wall -c exo2.c -o exo2.o

clean:
	rm exo2.o file.o exo2
