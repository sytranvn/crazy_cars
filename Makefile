# Makefile for JustForFun Files

# A few variables

CC=g++
LIBS=-lncurses

SRC_DIR=.
EXE_DIR=./bin

EXES = \
    ${EXE_DIR}/crazy_cars

${EXE_DIR}/%: %.o
	${CC} -o $@ $< ${LIBS}

%.o: ${SRC_DIR}/%.c
	${CC} -o $@ -c $<

all:    ${EXES}

clean:
	@rm -f ${EXES}
