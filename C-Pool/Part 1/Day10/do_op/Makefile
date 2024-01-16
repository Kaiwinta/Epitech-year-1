##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##

CFILES	=	my_putstr.c	\
		my_putchar.c	\
		my_getnbr.c	\
		my_put_nbr.c	\
		my_strdup.c	\
		task_02.c

OFILES	=	$(CFILES:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OFILES)
	gcc -o $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
