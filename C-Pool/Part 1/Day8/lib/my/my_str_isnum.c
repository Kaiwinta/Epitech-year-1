/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** Return 1 if the whole str is composed by number
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57) {
            return 0;
        }
        i++;
    }
    return 1;
}
