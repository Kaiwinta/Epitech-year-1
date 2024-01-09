/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** my_putstrerr.c
*/

#include "../include/my.h"

void my_putstr_err(const char *str)
{
    write(2, str, my_strlen(str));
}
