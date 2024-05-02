CC= g++
FLAGS = -lncurses -Wall
LIB_FOLDER = ../engine_lib/
OBJ = obj/


update: ${OBJ}engine.o
	ar rcs ../engine_lib/libImchadaEngine.a $^


${OBJ}engine.o: engine.cpp
	${CC} ${FLAGS} -c $^ -o $@
