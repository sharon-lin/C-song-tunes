GCC = gcc -g 

all: link_list.o music_library.o main.o
	$(GCC) link_list.o music_library.o main.o -o myTunes.out

link_list.o: link_list.c
	$(GCC) -c link_list.c 

main.o: main.c
	$(GCC) -c main.c

music_library.o: music_library.c
	$(GCC) -c music_library.c

run: myTunes.out
	./myTunes.out

clean:
	make -i cleanH

cleanH:
	rm *~
	rm *.o
