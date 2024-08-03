CC= g++
FLAGS = -lncurses -Wall -fPIC
LIB_FOLDER = ../engine_lib/
OBJ = obj/
BINS = ${OBJ}instance.o ${OBJ}constructor.o ${OBJ}logging.o ${OBJ}scene.o


#update: ${BINS}
#	${CC} -o ${LIB_FOLDER}libImchadaEngine.so -fPIC -shared $^

update: ${BINS}
	ar rcs ${LIB_FOLDER}libImchadaEngine.a ${BINS}

${OBJ}instance.o: instance.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}constructor.o: constructor.cpp
	${CC} ${FLAGS} -c $^ -o $@ 

${OBJ}logging.o: logging.cpp
	${CC} ${FLAGS} -c $^ -o $@

${OBJ}scene.o: scene.cpp
	${CC} ${FLAGS} -c $^ -o $@
