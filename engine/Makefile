CC= g++
FLAGS = -lncurses -Wall -fPIC
LIB_FOLDER = ../engine_lib/
OBJ = obj/


update: ${OBJ}engine_state.o ${OBJ}arguments.o ${OBJ}constructor.o ${OBJ}logging.o
	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -fPIC -shared $^


${OBJ}engine_state.o: engine_state.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}arguments.o: arguments.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}constructor.o: constructor.cpp
	${CC} ${FLAGS} -c $^ -o $@ 

${OBJ}logging.o: logging.cpp
	${CC} ${FLAGS} -c $^ -o $@
