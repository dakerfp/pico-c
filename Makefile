CC=gcc
LDFLAGS=-lncurses
CFLAGS=-Wall


all: ncurses-test

ncurses-test: main.c pico-c.c
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)
	
