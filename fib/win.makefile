CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic

objects = main.o fib.o

main.exe: $(objects)
	$(CC) -o main $(objects)

main.o: main.c fib.h
	$(CC) -c $(CFLAGS) main.c

fib.o: fib.c fib.h
	$(CC) -c $(CFLAGS) fib.c

.PHONY: clean
clean:
	rm -rf $(objects) main