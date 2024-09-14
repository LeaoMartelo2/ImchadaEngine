CC= g++
FLAGS = -lncurses -Wall -Wextra -fPIC -lfmt
LIB_FOLDER = ../engine_lib/
OBJ = obj/
BINS = ${OBJ}instance.o ${OBJ}constructor.o ${OBJ}scene.o 


update: ${BINS}
	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -shared ${FLAGS} $^

static: ${BINS}
	ar rcs ${LIB_FOLDER}libImchadaEngine.a ${BINS}

clear: 
	rm obj/*.o

${OBJ}instance.o: instance.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}constructor.o: constructor.cpp
	${CC} ${FLAGS} -c $^ -o $@ 

${OBJ}scene.o: scene.cpp
	${CC} ${FLAGS} -c $^ -o $@

