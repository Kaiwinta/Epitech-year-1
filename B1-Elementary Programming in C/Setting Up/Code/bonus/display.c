/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-titouan.pradoura
** File description:
** display.c
*/

#include "include/cpe.h"
#include "include/my.h"

void show_result(char *map, int nb_line, max_t *maximum, int size_line)
{
    my_putstr(map);
    free_all(map, maximum);
}

void free_all(char *map, max_t *maximum)
{
    free(maximum);
    free(map);
}
