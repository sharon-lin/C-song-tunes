GCC = gcc -g

all: stest test

test: linkedlist.o playlist.o test.o
	$(GCC) linkedlist.o playlist.o test.o -o test

linkedlist.o: linkedlist.c linkedlist.h
	$(GCC) -c linkedlist.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

test.o: test.c playlist.h
	$(GCC) -c test.c

clean:
	rm *.o
	rm *~
	rm *#e