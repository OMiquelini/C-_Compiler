CC = gcc
CFLAGS = -Wall
EXECUTABLE = compilas

# Lista de arquivos fonte
SOURCES = main.c scanner.c lib.c

# Lista de arquivos de cabeçalho
HEADERS = scanner.h lib.h

# Lista de arquivos objeto gerados a partir dos arquivos fonte
OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regra de compilação para cada arquivo objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: clean
