##
## EPITECH PROJECT, 2024
## Lib
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC =	src/my_putstr.c \
		src/my_putchar.c \
		src/my_strstr.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_strcmp.c \
		src/alnum.c \
		src/my_realloc.c \
		src/my_memset.c \
		src/my_memcpy.c \
		src/my_strcpy.c \
		src/my_strncpy.c \
		src/my_strncmp.c \
		src/my_strcat.c \
		src/my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

HEADER = my.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp includes/$(HEADER) ../../includes

clean:
	rm -f $(OBJ)
	rm -f ../$(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
