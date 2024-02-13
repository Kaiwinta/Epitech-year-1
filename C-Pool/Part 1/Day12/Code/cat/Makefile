##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##

SHELL	:=	/bin/bash

CFILES	=	my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		catv1.c

OBJ	= 	$(CFILES:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME): 	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
