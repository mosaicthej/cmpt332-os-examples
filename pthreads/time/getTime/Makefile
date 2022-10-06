CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic

objects = time.o

time: $(objects)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o time $(objects) -lpthread

time.o: getTime.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o time.o -c getTime.c

.PHONY: clean
clean:
	rm -f time $(objects)