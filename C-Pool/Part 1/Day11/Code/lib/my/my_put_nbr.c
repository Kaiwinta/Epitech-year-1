/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Print a full number
*/

#include "my.h"

int  my_loop_number(long nb)
{
    if (nb == 0) {
        return 0;
    }
    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
    }
    if (my_loop_number(nb / 10) == 0) {
        my_putchar(48 + nb % 10);
        return 0;
    }
}

int  my_put_nbr(int nb)
{
    long n = nb;

    if (n == 0) {
        my_putchar('0');
    } else {
        my_loop_number(n);
    }
}
