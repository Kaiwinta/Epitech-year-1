/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** my_putstr.c
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
