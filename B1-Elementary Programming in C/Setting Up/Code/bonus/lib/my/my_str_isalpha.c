/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** return 1 if the whole str is alpha
*/

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 122 || str[i] > 90 && str [i] < 97) {
            return 0;
        }
        i++;
    }
    return 1;
}
