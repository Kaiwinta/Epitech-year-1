/*
** EPITECH PROJECT, 2023
** my_show_param_array.c
** File description:
** display all the param
*/

#include "include/my.h"

int my_show_param_array(struct info_param const *par)
{
    int i = 0;
    int y = 0;

    while (par[i].str != 0) {
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        while (par[i].word_array[y]) {
            my_putstr(par[i].word_array[y]);
            my_putchar('\n');
            y++;
        }
        y = 0;
        i++;
    }
    return 0;
}
