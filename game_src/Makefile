PROJECT_NAME = GAME

CC = g++
FLAGS = -Wall -O2 -lncurses -L../engine_lib/ -lImchadaEngine
#remove the need for LD_LIBRARY_PATH
FINAL_FLAGS = -Wall -O2 -lncurses -L../engine_lib/ -lImchadaEngine -Wl,-rpath,../engine_lib/
GAME_SRC = game_src/
GAME_INCLUDE = include/
GAME_OBJ = game_bin/
BINS = main.o example.o

game: ${BINS}
	${CC} $^ -o ${PROJECT_NAME} ${FINAL_FLAGS}

main.o: main.cpp
	${CC} ${FLAGS} -c $^ -o $@

example.o: ${GAME_INCLUDE}example.cpp
	${CC} ${FLAGS} -c $^ -o $@

clear:
	rm *.o ${PROJECT_NAME}

deepclear:
	rm *.o ${PROJECT_NAME} latest.log

#something something
#g++ main.o example.o  -o TEST -lncurses -lImchadaEngine -L ../engine_lib/ -Wl,-rpath,../engine_lib/
