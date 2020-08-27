CC = gcc

all:	lab12

lab12:	cscd240Lab12.c  lab12.o ./utils/fileUtils.c ./utils/fileUtils.h ./utils/utils.c ./utils/utils.h
	gcc -m32 cscd240Lab12.c ./utils/fileUtils.c ./utils/utils.c lab12.o -o lab12

lab12.o:	lab12.c lab12.h
	gcc -c -m32 lab12.c

clean:
	rm lab12.o
	rm lab12

