/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Split a string into words
*/

#include "../include/my.h"

char *my_strncpy2(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char **my_str_to_word_array(char const *str)
{
    int index_tab = 0;
    int len = 0;
    char **text;
    int last_i = 0;
    int index_temp = 0;

    for (len; str[len]; len++);
    text = malloc((len + 1) * (sizeof(char *)));
    for (int i = 0; i <= len; i++){
        if (str[i] && str[i + 1] == '\n' || str[i + 1] ==
            '\0' && str[i] != '\n') {
            text[index_tab] = malloc((i + 2 - last_i) * sizeof(char));
            my_strncpy2(text[index_tab], &str[last_i - 1], i + 1 - last_i++);
            index_tab++;
            last_i = i + 2;
        }
    }
    text[index_tab] = NULL;
    return text;
}
