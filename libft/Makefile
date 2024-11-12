CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = $(wildcard *.c)
BCFILES = $(wildcard *bonus.c)
OFILES = $(CFILES:.c=.o)
BOFILES = $(BCFILES:.c=.o)
NAME = libft.a

all: $(OFILES)
	ar rcs $(NAME) $(OFILES)
bonus : all $(BOFILES)
	ar 
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re : fclean all