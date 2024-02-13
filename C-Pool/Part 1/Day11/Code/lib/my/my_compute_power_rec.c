/*
** EPITECH PROJECT, 2023
** my_compute_power_it.c
** File description:
** power but recursive this time
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 1) {
        return nb;
    }
    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        return my_compute_power_rec(nb, p - 1) * nb;
    }
}
