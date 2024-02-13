/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** return the square root of a number if its an int
*/

int my_compute_square_root(int nb)
{
    int i = nb;

    if (nb <= 0) {
        return 0;
    } else if (nb == 1) {
        return 1;
    }
    for (i ; i > 1; i--) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
