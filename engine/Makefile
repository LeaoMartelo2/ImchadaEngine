CC= g++
FLAGS = -lncurses -Wall -fPIC
LIB_FOLDER = ../engine_lib/
OBJ = obj/
BINS = ${OBJ}engine_state.o ${OBJ}arguments.o ${OBJ}constructor.o ${OBJ}logging.o


#update: ${BINS}
#	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -fPIC -shared $^

update: ${BINS}
	ar rcs ${LIB_FOLDER}libImchadaEngine.a ${BINS}

${OBJ}engine_state.o: engine_state.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}arguments.o: arguments.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}constructor.o: constructor.cpp
	${CC} ${FLAGS} -c $^ -o $@ 

${OBJ}logging.o: logging.cpp
	${CC} ${FLAGS} -c $^ -o $@
