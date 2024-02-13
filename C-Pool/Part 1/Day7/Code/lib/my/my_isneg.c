/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Display if a number is neg or not.
*/

void my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
