CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic

objects = main.o fib.o

main: $(objects)
	$(CC) -o main $(objects)

main.o: main.c fib.h
	$(CC) -c $(CFLAGS) $(CPPFLAGS) main.c

fib.o: fib.c fib.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) fib.c

.PHONY: clean
clean:
	rm -rf $(objects) main