##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-secured-titouan.pradoura
## File description:
## Makefile
##
.SILENT:

SHELL := /bin/bash

CFILES := ht_dump.c \
		  hash.c \
		  new_hashtable.c \
		  delete_hashtable.c \
		  ht_insert.c \
		  ht_delete.c \
		  ht_search.c \
		  lib/my_strlen.c \
		  lib/my_strdup.c \
		  lib/mini_printf.c \
		  lib/my_putchar.c \
		  lib/my_putstr.c \
		  lib/my_put_nbr.c \


CTESTFILES:= tests/test_hash.c \
			 tests/test_new_hashtable.c \
			 tests/test_delete_hashtable.c \
			 tests/test_mini_printf.c \
			 tests/test_ht_insert.c \
			 tests/test_ht_delete.c \
			 tests/test_ht_search.c \
			 tests/test_ht_dump.c \

OFILES := $(CFILES:.c=.o)

NAME := libhashtable.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

compile:
	bash -c "make re"
	bash -c "gcc -g *.c lib/*.c"
	bash -c "./a.out"

unit_tests:	re
	gcc -o unit_test $(CTESTFILES) $(CFILES) --coverage -lcriterion

tests_run: unit_tests
	./unit_test

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	rm unit_test*
