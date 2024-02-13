/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
