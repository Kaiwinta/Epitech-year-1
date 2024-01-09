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
    int y = 0;
    int total = my_strlen(dest) + my_strlen(src);
    char *temp = alloc_memory((my_strlen(dest) + my_strlen(src)) + 2);

    for (i; dest[i]; i++)
        temp[i] = dest[i];
    if (dest[i - 1] != '/') {
        temp[i] = '/';
        i++;
        temp[total] = '\0';
    }
    for (y; src[y] != '\0'; y++)
        temp[i + y] = src[y];
    return temp;
}
