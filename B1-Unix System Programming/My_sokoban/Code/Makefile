##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##
SHELL := /bin/bash

CFLAGS := -g

CFILES := main.c \
		  init.c \
		  my_soko.c \
		  loop_box.c \
		  movement.c \
		  check_end.c \
		  search_player.c \
		  lib/my_strlen.c \
		  lib/my_strdup.c \
		  lib/my_strcpy.c \
		  lib/my_putstr.c \
		  lib/my_str_to_word_array.c \

OFILES := $(CFILES:.c=.o)

NAME := my_sokoban

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES) -lncurses

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
