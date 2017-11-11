CC=gcc
LDFLAGS=-lncurses
CFLAGS=-Wall

all: ncurses-test

ncurses-test: main.o pico-c.o
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm -rf *.o
	rm -rf ncurses-test
