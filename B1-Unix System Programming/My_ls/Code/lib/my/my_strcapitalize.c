/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalize the first letter of each words
*/

int my_isup(char c)
{
    return (c >= 65 && c <= 90);
}

int my_isdown(char c)
{
    return (c >= 97 && c <= 122);
}

int my_isspace(char c)
{
    return (c == ' ' || c == '+' || c == '-');
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new = 1;

    while (str[i] != '\0') {
        if (my_isup(str[i]) && !new) {
            str[i] = str[i] + 32;
        }
        if (my_isdown(str[i]) && new) {
            str[i] = str[i] - 32;
        }
        new = 0;
        if (my_isspace(str[i])) {
            new = 1;
        }
        i++;
    }
    return str;
}
