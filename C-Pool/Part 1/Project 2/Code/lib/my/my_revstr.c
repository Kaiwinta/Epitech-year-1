/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** reverse the char of an str
*/

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    char temp;

    while (str[len] != '\0') {
        len ++;
    }
    len --;
    while (i <= len / 2) {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
        i++;
    }
    return str;
}
