/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** strlowcase
*/

#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 65 || str[i] <= 90)
            str[i] = str[i] + 32;
    return str;
}
