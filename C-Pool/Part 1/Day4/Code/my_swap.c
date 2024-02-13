/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Swaping the content of 2 integer
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
