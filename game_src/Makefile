PROJECT_NAME = GAME

CC = g++
FLAGS = -Wall -O2 -lncurses -lImchadaEngine -L ../engine_lib/
FINAL_FLAGS = -Wall -O2 -lncurses -lImchadaEngine -L ../engine_lib/ -Wl,-rpath,../engine_lib/
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


#something something
#g++ main.o example.o  -o TEST -lncurses -lImchadaEngine -L ../engine_lib/ -Wl,-rpath,../engine_lib/
