CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic

objects = elapsedTime.o

elapsedTime: $(objects)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o elapsedTime $(objects) -lpthread

elapsedTime.o: getElapsed.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o elapsedTime.o -c getElapsed.c

.PHONY: clean
clean:
	rm -f elapsedTime $(objects)