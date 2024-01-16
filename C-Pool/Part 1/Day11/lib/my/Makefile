##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##

SHELL	:=	/bin/bash

CFILES	=	my_putstr.c	\
		my_putchar.c	\
		my_compute_power_rec.c	\
		my_find_prime_sup.c	\
		my_compute_power_it.c	\
		my_compute_square_root.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_put_nbr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_isnum.c	\
		my_strdup.c	\
		my_find_prime_sup.c	\
		my_str_to_word_array.c \

OFILES	=	$(CFILES:.c=.o)

NAME	=	libmy.a

all:	$(NAME) move clean

move:
	bash -c "cp libmy.a ../libmy.a"
	bash -c "cp my.h ../../include/my.h"

$(NAME):		$(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
