CC= g++
FLAGS = -lncurses -Wall
LIB_FOLDER = ../engine_lib/
OBJ = obj/


update: ${OBJ}engine_state.o ${OBJ}arguments.o ${OBJ}constructor.o
	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -fpic -shared $^


${OBJ}engine_state.o: engine_state.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}arguments.o: arguments.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}constructor.o: constructor.cpp
	${CC} ${FLAGS} -c $^ -o $@ 
