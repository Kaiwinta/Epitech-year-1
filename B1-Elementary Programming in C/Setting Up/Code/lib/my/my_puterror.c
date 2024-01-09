/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** print a whole str
*/

#include "my.h"

int my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putcharerr(str[i]);
        i++;
    }
    return i;
}
