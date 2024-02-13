/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** return the number contained in a str
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long nb = 0;

    while (str[i] == '-' || str [i] == '+') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i++;
    }
    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i++;
        if (nb * sign > 2147483647 || nb * sign < -2147483648)
            return (0);
    }
    return nb * sign;
}
