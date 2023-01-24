CFLAGS=-Wall -pedantic -std=c11 -I. -g

listcar: list.c
	gcc $(CFLAGS) list.c -o listcar
