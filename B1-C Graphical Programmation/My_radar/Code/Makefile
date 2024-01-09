##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##
SHELL := /bin/bash

CFLAGS := -g

CFILES := main.c \
		  game_related/run.c \
		  game_related/game.c \
		  game_related/event.c \
		  game_related/display.c \
		  game_related/collision.c \
		  game_related/free.c \
		  game_related/text.c \
		  file_related/open_file.c \
		  file_related/parse_file.c \
		  file_related/display_help.c \

OFILES := $(CFILES:.c=.o)

CLIB := lib/my_putstr.c \
		lib/my_strdup.c \
		lib/my_strcmp.c \
		lib/my_strcpy.c \
		lib/my_strlen.c \
		lib/my_putchar.c \
		lib/my_strncpy.c \
		lib/my_put_nbr.c \
		lib/my_putstr_err.c \
		lib/my_str_to_word_array.c \

OLIB := $(CLIB:.c=.o)

CSFML := -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

NAME := my_radar

all: $(NAME)


info: header

define Compile_mess
  ___ __ ____ ____
 / __)  (    (  __)
( (_(  O ) D () _)
 \___)__(____(____) __ __   ____
 / __)  \( \/ |  _ (  |  ) (  __)
( (_(  O ) \/ \) __/)(/ (_/\) _)
 \___)__/\_)(_(__) (__)____(____)

endef
export Compile_mess

.SILENT:
$(NAME): $(OFILES) $(OLIB)
	@echo "$$Compile_mess"
	@gcc -o $(NAME) $(OFILES) $(OLIB) -lm $(CSFML)

clean:
	@rm -f $(OFILES) $(OLIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
