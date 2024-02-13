/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** concatenate n char into dest
*/

#include <string.h>

char *my_strcpy3(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (i == n) {
        dest[i] = '\0';
    }
    return dest;
}

char *my_strncat(char *dst, const char *src, int n)
{
    int len = 0;
    int i = 0;

    while (dst[i] != '\0') {
        i++;
        len++;
    }
    my_strcpy3(dst + len, src, n);
    return dst;
}
