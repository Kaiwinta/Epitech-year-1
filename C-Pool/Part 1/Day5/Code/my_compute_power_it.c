/*
** EPITECH PROJECT, 2023
** my_compute_power_it.c
** File description:
** power a number nb to the power of p
*/

int my_compute_power_it(int nb, int p)
{
    int save = nb;

    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    while (p > 1){
        nb = nb * save;
        p --;
    }
    return nb;
}
