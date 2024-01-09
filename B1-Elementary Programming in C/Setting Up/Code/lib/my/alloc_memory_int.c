/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** alloc_memory.c
*/

#include <stdlib.h>

int *alloc_memory_int(unsigned long size)
{
    int *nb = malloc(sizeof(int) * (size + 1));

    for (int i = 0; i <= size; i++)
        nb[i] = -1;
    return nb;
}
