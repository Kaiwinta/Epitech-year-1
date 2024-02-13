/*
** EPITECH PROJECT, 2023
** my_strcat.h
** File description:
** concatenate one string at the end of the other
*/

#include <string.h>

char *my_strcpy2(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest [i] = src[i];
    return dest;
}

char *my_strcat(char *dst, const char *src)
{
    int len = 0;
    int i = 0;

    while (dst[i] != '\0') {
        i++;
        len++;
    }
    my_strcpy2(dst + len, src);
    return dst;
}
