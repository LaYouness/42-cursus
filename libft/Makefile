NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = $(wildcard *.c)
BCFILES = $(wildcard *bonus.c)
OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)

all: $(OFILES)
	ar rcs $(NAME) $(OFILES)
bonus: all $(BOFILES)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all