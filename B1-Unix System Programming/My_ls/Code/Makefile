##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile all the code
##
SHELL := /bin/bash

CFILES := main.c \
		  struct_use.c \
		  handling_error.c \
		  sorting.c \
		  ls_cmp.c \
		  display.c \
		  all_loop.c \
		  flag_l.c \
		  check_perm.c \
		  quote.c

OFILES := $(CFILES:.c=.o)

NAME := my_ls

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
