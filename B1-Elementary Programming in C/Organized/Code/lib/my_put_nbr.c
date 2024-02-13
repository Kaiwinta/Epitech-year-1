/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Print a full number
*/

#include "../include/shell.h"

int my_loop_number(long nb, int *count)
{
    if (nb == 0) {
        return 0;
    }
    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
        *count = *count + 1;
    }
    if (my_loop_number(nb / 10, count) == 0) {
        my_putchar(48 + nb % 10);
        *count = *count + 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    long n = nb;
    int count = 0;

    if (n == 0) {
        my_putchar('0');
        return 1;
    } else {
        my_loop_number(n, &count);
    }
    return count;
}
