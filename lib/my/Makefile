##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## ruru !
##

NAME	= libmy.a

SRC	= *.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	 gcc -c $(SRC)
	 ar rc $(NAME) $(OBJ)
	 make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
