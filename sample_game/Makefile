CC = g++
FLAGS = -O3 -lncurses -Wall 
SRC = src/
INCLUDE = src/include/

game: main.o
	${CC} ${FLAGS} $^ -o $@

clear:
	rm *.o game

main.o: ${SRC}main.cpp
	${CC} ${FLAGS} $^ -c $@
