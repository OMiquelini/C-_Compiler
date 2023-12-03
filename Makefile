CC = gcc
CFLAGS = -Wall -g

all: compilador

compilador: lib.o scanner.o parser.o main.o
	$(CC) $(CFLAGS) $^ -o $@

lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c $< -o $@

scanner.o: scanner.c scanner.h
	$(CC) $(CFLAGS) -c $< -o $@

parser.o: parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

parser.tab.c: parser.y
	bison -d $<

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o compilador parser.tab.c

.PHONY: all clean
