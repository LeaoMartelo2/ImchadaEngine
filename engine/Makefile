CC= g++
FLAGS = -lncurses -Wall -fPIC
LIB_FOLDER = ../engine_lib/
OBJ = obj/
BINS = ${OBJ}instance.o ${OBJ}constructor.o ${OBJ}scene.o ${OBJ}game_map.o


update: ${BINS}
	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -shared $^

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

${OBJ}game_map.o: game_map.cpp
	${CC} ${FLAGS} -c $^ -o $@
