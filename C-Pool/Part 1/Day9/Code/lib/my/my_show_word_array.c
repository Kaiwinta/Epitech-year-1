/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** display the content of an array
*/

#include <stdlib.h>

void my_putchar12(char c)
{
    write(1, &c, 1);
}

void my_putstr12(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar12(str[i]);
        i++;
    }
}

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr12(tab[i]);
        my_putchar12('\n');
        i++;
    }
}
