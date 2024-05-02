PROJECT_NAME = GAME

CC = g++
FLAGS = -Wall -lncurses -L engine_lib -lImchadaEngine
GAME_SRC = game_src/
GAME_INCLUDE = game_src/include/
GAME_OBJ = game_src/game_bin/

game: ${GAME_OBJ}main.o ${GAME_OBJ}example.o
	${CC} ${FLAGS} $^ -o ${PROJECT_NAME}

${GAME_OBJ}main.o: ${GAME_SRC}main.cpp
	${CC} ${FLAGS} -c $^ -o $@

${GAME_OBJ}example.o: ${GAME_INCLUDE}example.cpp
	${CC} ${FLAGS} -c $^ -o $@
