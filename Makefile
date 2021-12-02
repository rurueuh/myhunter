##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## ruru !
##

NAME = game

SRC	= *.c

OBJ	= $(SRC:.c=.o)

CSFML_FLAG = -lcsfml-system -lcsfml-graphics -lcsfml-window

all: $(NAME)

$(NAME):
	cd lib/my && make re -s
	gcc -g $(SRC) -o $(NAME) -L ./lib/my/ -lmy $(CSFML_FLAG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
