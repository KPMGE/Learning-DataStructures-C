OBJ = ./obj
SRC = ./src
INCLUDE = ./include
CC = gcc
FLAGS = -lm -pedantic -Wall -g
NAME_PROGRAM = dictionary.exe

all: create_directory libed create_executable

libed: \
	$(OBJ)/keyval.o \
	$(OBJ)/dictionary.o \
	$(OBJ)/utils.o \
	$(OBJ)/main.o \

$(OBJ)/main.o: $(SRC)/main.c
	@ echo "\033[1;32m"
	@ echo "Compiling src/main.c ..."
	@ $(CC) -c $< -o $@ $(FLAGS)
	@ echo "\033[0m"

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@ echo "\033[1;32m"
	@ echo "Compiling $< ..."
	@ $(CC) -c $< -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

create_directory: 
	@ echo "\033[1;32m"
	@ echo "Creating obj directory..."
	@ mkdir $(OBJ)
	@ echo "\033[0m"

create_executable: 
	@ echo "\033[1;32m"
	@ echo "Creating executable..."
	@ $(CC) -o $(NAME_PROGRAM) $(OBJ)/*.o 
	@ echo "\033[0m"

run: 
	@ echo "\033[1;32m"
	@ echo "Runnin program ..."
	@ echo "\033[0m"
	@ ./$(NAME_PROGRAM)

valgrind:
	@ valgrind ./$(NAME_PROGRAM)

test: clean all clear run

clean: 
	@ echo "\033[1;35m"
	@ echo "Removing temporary files ..."
	@ rm -rf $(OBJ) $(NAME_PROGRAM)
	@ echo "\033[0m"
