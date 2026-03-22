CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lm

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

OUT = build/programa
GERADOR = build/gerador
INPUT = data/input.dat

.PHONY: all clean run

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GERADOR): tools/gerar.c
	$(CC) tools/gerar.c -o $(GERADOR) -lm

$(INPUT): $(GERADOR)
	./$(GERADOR)

clean:
	rm -rf build/* data/input.dat

run: clean $(INPUT) all
	./$(OUT)