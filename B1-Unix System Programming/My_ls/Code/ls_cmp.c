/*
** EPITECH PROJECT, 2023
** my_strcomp.c
** File description:
** Compare teh asccci value of 2 string
*/

#include "include/my.h"

char my_mini(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

void check_point(char *str, char *string, int *i, int *y)
{
    char letter1 = my_mini(str[*i]);
    char letter2 = my_mini(string[*y]);

    if (letter1 == '.' || letter1 == '_' || letter1 == '/')
        *i = *y + 1;
    if (letter2 == '.' || letter2 == '_' || letter2 == '/')
        *y = *y + 1;
}

int ls_cmp(char *str, char *string)
{
    int i = 0;
    int y = 0;
    char letter1;
    char letter2;

    while (str[i] != '\0') {
        check_point(str, string, &i, &y);
        letter1 = my_mini(str[i]);
        letter2 = my_mini(string[y]);
        if (letter1 > letter2)
            return 1;
        if (letter1 < letter2)
            return -1;
        i++;
        y++;
    }
    if (string[y] == '\0')
        return 0;
}
