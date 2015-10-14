#
#Makefile
#IJC-DU1, příklad a), 25.3.2014
#Autor: Vojtech Mašek, FIT 1BIB xmasek15

CFLAGS=-std=c99 -pedantic -Wall -Wextra -lm

all: prvocisla steg-decode prvocisla-inline steg-decode-inline

error.o: error.c error.h
	gcc $(CFLAGS) -c error.c -o error.o

ppm.o: ppm.c ppm.h eratosthenes.h bit-array.h error.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o	

eratosthenes.o: eratosthenes.c eratosthenes.h bit-array.h error.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

prvocisla.o: prvocisla.c error.h bit-array.h eratosthenes.h
	gcc $(CFLAGS) -c prvocisla.c -o prvocisla.o

steg-decode.o: steg-decode.c bit-array.h error.h eratosthenes.h ppm.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o

prvocisla: prvocisla.o error.o eratosthenes.o
	gcc $(CFLAGS) error.o eratosthenes.o prvocisla.o -o prvocisla

steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	gcc $(CFLAGS) error.o eratosthenes.o ppm.o steg-decode.o -o steg-decode

prvocisla-inline: prvocisla.c error.o eratosthenes.c 
	gcc $(CFLAGS) -DUSE_INLINE error.o eratosthenes.o prvocisla.o -o prvocisla-inline

steg-decode-inline: steg-decode.c ppm.o error.o eratosthenes.c
	gcc $(CFLAGS) -DUSE_INLINE error.o eratosthenes.o ppm.o steg-decode.o -o steg-decode-inline

clean:
	rm *.o