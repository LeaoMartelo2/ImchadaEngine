CC= g++
FLAGS = -lncurses -Wall
LIB_FOLDER = ../engine_lib/
OBJ = obj/


update: ${OBJ}engine_instance.o
	ar rcs ../engine_lib/libImchadaEngine.a $^


${OBJ}engine_instance.o: engine_instance.cpp
	${CC} ${FLAGS} -c $^ -o $@
