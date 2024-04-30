CC = g++
FLAGS = -O3 -lncurses - Wall
SRC = src/
INCLUDE = src/include 

all: main.o 
	${CC} ${FLAGS} $^ -o $@


clear:
	rm *.o all

main.o: ${SCR}main.cpp 
	${CC} ${FLAGS} $^ -o $@

