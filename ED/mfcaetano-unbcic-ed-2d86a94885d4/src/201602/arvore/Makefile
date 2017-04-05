
CC=gcc

OBJ=arvore.o fila.o
BIN=arvore

all: main 

arvore.o: arvore.h arvore.c
	${CC} -c -g arvore.c

fila.o: fila.h fila.c
	${CC} -c -g fila.c

main: main.c ${OBJ}
	${CC} -o ${BIN} -g main.c ${OBJ}

clean:
	rm -rf ${OBJ} ${BIN}
