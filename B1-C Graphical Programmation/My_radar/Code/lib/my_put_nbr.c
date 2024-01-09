/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** my_put_nbr.c
*/

/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Print a full number
*/

#include "../include/my.h"

int my_loop_number(long long nb, int *count)
{
    if (nb == 0) {
        return 1;
    }
    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
        *count = *count + 1;
    }
    if (my_loop_number(nb / 10, count) == 1) {
        my_putchar(48 + nb % 10);
        *count = *count + 1;
    } else {
        my_putchar(48 + nb % 10);
        *count = *count + 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    } else {
        my_loop_number(nb, &count);
    }
    return count;
}
