CC = g++
FLAGS = -O3 -lncurses -Wall 
SRC = src/
INCLUDE = src/include/

ENGINE = engine/

#game specific code


# add your own headers/parts of the engine on the 
game: main.o example.o
	${CC} ${FLAGS} $^ -o $@

main.o: ${SRC}main.cpp
	${CC} ${FLAGS} $^ -c $@

example.o: ${INCLUDE}example.cpp
	${CC} ${FLAGS} $^ -c $@


# engine general code



