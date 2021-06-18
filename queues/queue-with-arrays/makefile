SRC          = ./src
INCLUDE      = ./include
OBJ          = ./obj
NAME_PROGRAM = queue.exe # must end with .exe
FLAGS        = -lm -pedantic -Wall -std=c99
COMPILER     = gcc   


all: createDirectory libed createFinalProgam

test: clean all run

# all target files
libed: \
	${OBJ}/main.o\
	${OBJ}/queue.o\

createFinalProgam: ${NAME_PROGRAM}

# rule for main file
./obj/main.o: ./src/main.c
	@ echo "Compiling main program... "
	@ ${COMPILER} -c $< -I ${INCLUDE} -o $@ ${FLAGS}

# rule for libed
${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	@ echo "Compiling program $<..."
	@ ${COMPILER} -c $< -I ${INCLUDE} -o $@ ${FLAGS}

# rule for createFinalProgam
%.exe: 
	@ echo "Creating executable..."
	@ ${COMPILER} $< ${OBJ}/*.o -I ${INCLUDE} -o $@

# create a directory for objects
createDirectory: 
	@ echo "Creating directory..."
	@ mkdir ${OBJ}

run: ${NAME_PROGRAM}
	@ ./${NAME_PROGRAM}

valgrind: ${NAME_PROGRAM}
	@ valgrind ./${NAME_PROGRAM}

clean:
	@ echo "Removing files..."
	@ rm -rf ${OBJ} ${NAME_PROGRAM}
