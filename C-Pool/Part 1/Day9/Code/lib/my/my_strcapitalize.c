/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalize the first letter of each words
*/

int isup(char c)
{
    return (c >= 65 && c <= 90);
}

int isdown(char c)
{
    return (c >= 97 && c <= 122);
}

int isspace(char c)
{
    return (c == ' ' || c == '+' || c == '-');
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new = 1;

    while (str[i] != '\0') {
        if (isup(str[i]) && !new) {
            str[i] = str[i] + 32;
        }
        if (isdown(str[i]) && new) {
            str[i] = str[i] - 32;
        }
        new = 0;
        if (isspace(str[i])) {
            new = 1;
        }
        i++;
    }
    return str;
}
