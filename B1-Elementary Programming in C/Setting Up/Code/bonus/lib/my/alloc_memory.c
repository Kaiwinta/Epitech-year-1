/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** alloc_memory.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *alloc_memory(unsigned long size)
{
    char *alloc = malloc(sizeof(char) *( size + 1));

    for (int i = 0; i < size; i++)
        alloc[i] = '\0';
    return alloc;
}
