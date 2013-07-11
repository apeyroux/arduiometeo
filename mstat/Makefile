CC=gcc
CFLAGS=-g -Wall -I.
DEPS = mstat.h mstat.c main.c
OBJ = mstat.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mstat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
