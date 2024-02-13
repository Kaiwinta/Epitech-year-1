/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** search a special str in an str
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int i_find = 0;

    while (str[i] != '\0') {
        while (str[i + i_find] == to_find[i_find] && to_find[i_find] != '\0') {
            i_find++;
        }
        if (to_find[i_find] == '\0') {
            return &str[i];
        }
        i++;
        i_find = 0;
    }
    return NULL;
}
