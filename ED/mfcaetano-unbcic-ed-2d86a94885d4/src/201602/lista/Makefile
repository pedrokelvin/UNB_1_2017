
CC=gcc

OBJ=lista.o
BIN=lista

all: main

lista.o: lista.h lista.c
	${CC} -c -g lista.c

main: main.c ${OBJ}
	${CC} -o ${BIN} -g main.c lista.o

clean: ${OBJ} ${BIN}
	rm -rf ${OBJ} ${BIN}
