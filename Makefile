# Makefile para compilar o projeto

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall

# Nome do executável
TARGET = compilas

# Lista de arquivos-fonte
SRCS = scanner.c parser.c main.c

# Lista de arquivos de cabeçalho
HEADERS = lib.h scanner.h parser.h

# Objetos gerados a partir dos arquivos-fonte
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos-fonte em objetos
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
