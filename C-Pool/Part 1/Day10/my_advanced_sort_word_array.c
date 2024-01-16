/*
** EPITECH PROJECT, 2023
** my_advanced_sort_word_array.c
** File description:
** Sort the word of the array
*/

#include "my.h"

void insertion_sort(char **tab, int len, int(*cmp)(char const *, char const *))
{
    char *temp;
    int j;

    for (int i = 1; i < len; i++) {
        j = i;
        if (j > 0 && *cmp(tab[j - 1], tab[i]) == 1) {
            my_swap(&tab[i], &tab[j - 1]);
            i = i - 2;
            j = i;
        }
    }
}

int my_advanced_sort_word_array(char **tab,
    int(*cmp)(char const *, char const *))
{
    int len;

    while (tab[len])
        len++;
    if (len >= 1) {
        insertion_sort(tab, len, cmp);
    }
    return 0;
}
