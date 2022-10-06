CC = gcc
CFLAGS = -g
CPPFLAGS = -Wextra -Wall -std=gnu90 -pedantic
DEBUGFLAGS = -DDEBUG

objects = create.o

create: $(objects)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o create $(objects) -lpthread

create.o: createNewPthreads.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o create.o -c createNewPthreads.c

.PHONY: clean
clean:
	rm -f create $(objects)

