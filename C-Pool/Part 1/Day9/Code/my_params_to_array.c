/*
** EPITECH PROJECT, 2023
** my_param_to_array.c
** File description:
** Return an array of structure and return the adress of the first cell
*/

#include <stdlib.h>
#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param temp;
    struct info_param *array = malloc(sizeof(struct info_param ) * (ac + 1));

    for (int i = 0; i <= ac - 1; i++) {
        temp.str = av[i];
        temp.copy = my_strdup(av[i]);
        temp.length = my_strlen(av[i]);
        temp.word_array = my_str_to_word_array(av[i]);
        array[i] = temp;
    }
    array[ac].str = 0;
    return array;
}
