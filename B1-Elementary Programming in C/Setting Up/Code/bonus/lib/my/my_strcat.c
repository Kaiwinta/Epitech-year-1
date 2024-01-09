/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** empty files in order to do a lib
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));

    for (i; dest[i]; i++)
        temp[i] = dest[i];
    for (int y = 0; src[y] != '\0'; y++)
        temp[i + y] = src[y];
    return temp;
}
