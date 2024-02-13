/*
** EPITECH PROJECT, 2023
** my_evil_str.c
** File description:
** swap a string 2 letter by 2 lettters
*/

char *my_evil_str(char *str)
{
    int i = 0;
    int y = 0;
    char temp;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (y <= i / 2) {
        temp = str[y];
        str[y] = str[i - y];
        str[i - y] = temp;
        y++;
    }
    return str;
}
