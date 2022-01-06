NAME_PROGRAM   = queue-linked-list
MAIN_FILE_NAME = main
SRC            = ./src
INCLUDE        = ./include
OBJ            = ./obj
BIN            = ./bin
FLAGS          = -lm -pedantic -Wall 
COMPILER       = gcc   

C_FILES        = $(wildcard $(SRC)/*.c)
OBJ_PATH_FILES = $(patsubst $(SRC)%,$(OBJ)%,$(C_FILES))
OBJ_FILES      = $(patsubst %.c,%.o,$(OBJ_PATH_FILES))

all: clean create_dir $(OBJ_FILES) create_final_progam

create_final_progam: $(BIN)/$(NAME_PROGRAM)

# rule for main file
$(OBJ)/$(MAIN_FILE_NAME).o: $(SRC)/$(MAIN_FILE_NAME).c
	@ echo "\033[1;32m"
	@ echo "Compiling main program... "
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# rule for all o files
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@ echo "\033[1;32m"
	@ echo "Compiling program $<..."
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# rule for create_final_progam
$(BIN)/%: 
	@ echo "\033[1;32m"
	@ echo "Creating executable..."
	@ $(COMPILER) $< $(OBJ)/*.o -I $(INCLUDE) -o $@
	@ echo "\033[0m"

# create all needed directories
create_dir: 
	@ echo "\033[1;32m"
	@ echo "Creating $(OBJ) directory...\n"
	@ mkdir $(OBJ)
	@ echo "Creating $(BIN) directory..."
	@ mkdir $(BIN)
	@ echo "\033[0m"

# rule to run the final program
run: 
	@ echo "\033[1;32m"
	@ echo "Running $(BIN)/$(NAME_PROGRAM)"
	@ ./$(BIN)/$(NAME_PROGRAM)
	@ echo "\033[0m"

valgrind: 
	@ echo "\033[1;32m"
	@ echo "Running valgrind on $(BIN)/$(NAME_PROGRAM)"
	@ echo "\033[0m"
	@ valgrind ./$(BIN)/$(NAME_PROGRAM)

clean:
	@ echo "\033[1;35m"
	@ echo "Removing temporary files..."
	@ rm -rf $(OBJ) $(NAME_PROGRAM) $(BIN)
	@ echo "\033[0m"
