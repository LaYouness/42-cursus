CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = get_next_line.h
BIN = G_N_L
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(BIN)
$(BIN): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(BIN)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(BIN)
	rm -f $(OBJ)
re: clean all