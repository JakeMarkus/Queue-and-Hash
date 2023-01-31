CFLAGS=-Wall -pedantic -std=c11 -I. -g
VALGRIND=valgrind --leak-check=full

all: test1 test2 test3 test4 test1hash test2hash test3hash

%.o:	%.c
			gcc $(CFLAGS) -c $<

test1:	test1.o queue.o
				gcc $(CFLAGS) test1.o queue.o -o test1

test2:	test2.o queue.o
				gcc $(CFLAGS) test2.o queue.o -o test2

test3:	test3.o queue.o
				gcc $(CFLAGS) test3.o queue.o -o test3

test4:	test4.o queue.o
				gcc $(CFLAGS) test4.o queue.o -o test4

test1hash:	test1hash.o hash.o queue.o
				gcc $(CFLAGS) queue.o test1hash.o hash.o -o test1hash

test2hash: test2hash.o hash.o queue.o
				gcc $(CFLAGS) queue.o test2hash.o hash.o -o test2hash

test3hash: test3hash.o hash.o queue.o
				gcc $(CFLAGS) queue.o test3hash.o hash.o -o test3hash

%.v: %
				$(VALGRIND) $<

clean:
	rm -f *.o test1 test2 test3 test4 test1hash test2hash test3hash
