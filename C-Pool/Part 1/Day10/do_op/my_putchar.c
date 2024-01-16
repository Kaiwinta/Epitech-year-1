/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print a char
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}
