##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##
SHELL := /bin/bash

CFLAGS := -g

CFILES := main.c \
		  flag_game.c \
		  common/common_text_update.c \
		  common/common_function.c \
		  common/common_display.c \
		  common/common_loading.c \
		  common/common_update.c \
		  common/common_event.c \
		  common/common_move.c \
		  common/common_game.c \
		  common/common_boss.c \
		  common/common_free.c \
		  common/common_end.c \
		  wave/mode_extreme.c \
		  wave/mode_normal.c \
		  wave/mode_easy.c \
		  wave/mode_hard.c \
		  boss/extreme_boss.c \
		  boss/normal_boss.c \
		  boss/easy_boss.c \
		  boss/hard_boss.c \
		  lib/my_strcmp.c \
		  lib/my_strdup.c \
		  lib/my_putstr.c \
		  lib/my_strlen.c \

OFILES := $(CFILES:.c=.o)

NAME := my_hunter

CSFML := -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o  $(NAME) $(OFILES) $(CSFML)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
