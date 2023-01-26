CFLAGS=-Wall -pedantic -std=c11 -I. -g

%.o: %.c %.h
	gcc $(CFLAGS) -c $<

test1: test1.o queue.o
	gcc $(CFLAGS) test1.o queue.o -o test1
