/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print a char
*/

#include <unistd.h>

int my_putcharerr(char c)
{
    write(2, &c, 1);
    return 1;
}
