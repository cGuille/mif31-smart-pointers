CC=g++
BIN=bin
EXEC=main
LDFLAGS=-g -Wall -ansi -pedantic -std=c++0x
CCFLAGS=-c ${LDFLAGS}

all: ${EXEC}

main: ${BIN}/main.o ${BIN}/ref-counter.o
	${CC} ${LDFLAGS} $^ -o $@

${BIN}/main.o: main.cpp smart-pointer.hpp
	${CC} ${CCFLAGS} $< -o $@

${BIN}/ref-counter.o: ref-counter.cpp
	${CC} ${CCFLAGS} $< -o $@

clean:
	\rm -f ${BIN}/*.o ${EXEC}

veryclean: clean
	\rm -f ${BIN}/*.out

docu: doc/Doxyfile
	doxygen doc/Doxyfile
