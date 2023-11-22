CC = gcc
CFLAGS = -Wall
EXECUTABLE = compilas

# Lista de arquivos fonte
SOURCES = main.c scanner.c

# Lista de arquivos de cabeçalho
HEADERS = scanner.h lib.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: clean
