CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic
DEBUGFLAGS = -DDEBUG

objects = threadKill.o

threadKill: $(objects)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o threadKill $(objects) -lpthread

threadKill.o: kill.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o threadKill.o -c kill.c

.PHONY: clean
clean:
	rm -f threadKill $(objects)
