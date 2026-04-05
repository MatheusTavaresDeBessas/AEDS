CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lm

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

OUT = build/programa

# usar gerar.c
#
# GERADOR = build/gerador
# INPUT = data/input.dat

.PHONY: all clean run

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#compilação do gerar.c
#
# $(GERADOR): tools/gerar.c
# 	$(CC) tools/gerar.c -o $(GERADOR) -lm
#
# $(INPUT): $(GERADOR)
# 	./$(GERADOR)

clean:
	rm -rf build/*
#	rm -rf build/* data/input.dat
#clean acima deve ser usado junto com o gerar.c

#run com gerador
#run: clean $(INPUT) all)

run: clean all
	./$(OUT)