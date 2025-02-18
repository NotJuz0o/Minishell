##
## EPITECH PROJECT, 2024
## Project
## File description:
## Makefile
##

.PHONY: all clean fclean re lib

SRC =	src/main.c \
		src/concat.c \
		src/parser.c \
		src/executor.c \
		src/init.c \
		src/dynamic_array.c \
		src/builtins/exit.c \
		src/builtins/env.c \
		src/builtins/cd.c \
		src/builtins/setenv.c \
		src/builtins/unsetenv.c \
		src/errors_management.c \
		src/minishell.c

OBJ = $(SRC:.c=.o)

NAME = mysh

CFLAGS = -I./include -Wall -Wextra -g

LIBS = -L./lib -L. -lmy -lhashtable

all: lib $(NAME)

lib:
	$(MAKE) -C lib/my
	$(MAKE) -C lib/hash

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/hash clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/hash fclean

re: fclean all
