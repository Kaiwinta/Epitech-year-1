/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** swap
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
