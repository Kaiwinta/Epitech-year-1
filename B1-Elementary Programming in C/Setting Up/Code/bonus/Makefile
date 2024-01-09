##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##
SHELL := /bin/bash

CFLAGS := -g
CFILES := main.c \
		  generating.c \
		  display.c \
		  open_files.c \

OFILES := $(CFILES:.c=.o)

NAME := setting_up

all: libcreate $(NAME)

libcreate:
	bash -c "cd lib/my && make re && cd ../.."

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES) -L./lib -lmy

clean:
	bash -c "cd lib/my && make clean"
	rm -f $(OFILES)

fclean: clean
	bash -c "cd lib/my && make fclean"
	rm -f $(NAME)

re: fclean all
	bash -c "cd lib/my && make re && cd ../.."
