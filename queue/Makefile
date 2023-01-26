CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: test1 test3 test4

%.o: %.c %.h
	gcc $(CFLAGS) -c $<

test1: test1.o queue.o
	gcc $(CFLAGS) test1.o queue.o -o test1

test3: test3.o queue.o
	gcc $(CFLAGS) test3.o queue.o -o test3

test4: test4.o queue.o
	gcc $(CFLAGS) test4.o queue.o -o test4
