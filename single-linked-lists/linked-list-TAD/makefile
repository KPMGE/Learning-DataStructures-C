SRC          = ./src
INCLUDE      = ./include
OBJ          = ./obj
NAME_PROGRAM = stack.exe # must end with .exe
FLAGS        = -lm -pedantic -Wall -std=c99
COMPILER     = gcc   


all: createDirectory libed createFinalProgam

test: clean all run

# all target files
libed: \
	${OBJ}/main.o\
	${OBJ}/stack.o\

createFinalProgam: ${NAME_PROGRAM}

# rule for main file
./obj/main.o: ./src/main.c
	@ echo "\033[1;32m"
	@ echo "Compiling main program... "
	@ ${COMPILER} -c $< -I ${INCLUDE} -o $@ ${FLAGS}
	@ echo "\033[0m"

# rule for libed
${OBJ}/%.o: ${SRC}/%.c ${INCLUDE}/%.h
	@ echo "\033[1;32m"
	@ echo "Compiling program $<..."
	@ ${COMPILER} -c $< -I ${INCLUDE} -o $@ ${FLAGS}
	@ echo "\033[0m"

# rule for createFinalProgam
%.exe: 
	@ echo "\033[1;32m"
	@ echo "Creating executable..."
	@ ${COMPILER} $< ${OBJ}/*.o -I ${INCLUDE} -o $@
	@ echo "\033[0m"

# create a directory for objects
createDirectory: 
	@ echo "\033[1;32m"
	@ echo "Creating directory..."
	@ mkdir ${OBJ}
	@ echo "\033[0m"

run: ${NAME_PROGRAM}
	@ ./${NAME_PROGRAM}

valgrind: ${NAME_PROGRAM}
	@ valgrind ./${NAME_PROGRAM}

clean:
	@ echo "\033[1;35m"
	@ echo "Removing files..."
	@ rm -rf ${OBJ} ${NAME_PROGRAM}
	@ echo "\033[0m"

