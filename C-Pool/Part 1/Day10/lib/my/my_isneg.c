/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Display if a number is neg or not.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
