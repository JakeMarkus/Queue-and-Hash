CFLAGS=-Wall -pedantic -std=c11 -I. -g

queueComp: queue.c
	gcc $(CFLAGS) queue.c -o queueComp

%.o: %.c %.h
	gcc $(CFLAGS) -c $<
