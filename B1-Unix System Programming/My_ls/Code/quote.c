/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** quote.c
*/

#include "include/my.h"

void show_quote(char *path, flag **flag_list)
{
    if ((*flag_list)->case_qmaj)
        mini_printf(" \"%s\"", path);
    else
        mini_printf(" %s", path);
    if ((*flag_list)->case_l || (*flag_list)->case_o )
        mini_printf("\n");
}
