/*
** EPITECH PROJECT, 2023
** my_str_isprintable.c
** File description:
** return 1 if the str contain only printable characters
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 126 || str[i] < 32) {
            return 0;
        }
        i++;
    }
    return 1;
}
