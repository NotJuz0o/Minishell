##
## EPITECH PROJECT, 2024
## Lib
## File description:
## Makefile
##

.PHONY: all clean fclean re unit_tests tests_run coverage

SRC = 	src/my_putchar.c \
		src/my_strlen.c \
		src/my_strcmp.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_putnbr.c \
		src/my_compute_power_rec.c \
		src/hash.c \
		src/handle_table.c \
		src/ht_delete.c \
		src/create.c

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

HEADER = secured.h

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
