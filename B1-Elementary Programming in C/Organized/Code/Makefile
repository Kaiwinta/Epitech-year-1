##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##

SHELL := /bin/bash

CFLAGS := -g

CFILES := main.c \
		  lib/my_strcmp.c \
		  lib/my_putchar.c \
		  lib/mini_printf.c \
		  lib/my_put_nbr.c \
		  lib/my_putstr.c \
		  lib/my_strlen.c \
	      lib/my_strcpy.c \
		  function/check.c \
		  function/add.c \
		  function/del.c \
		  function/sort.c \
		  function/disp.c \
		  function/add_in_sorted.c \

OFILES := $(CFILES:.c=.o)

NAME := organized

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES) -Llib -lshell

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
