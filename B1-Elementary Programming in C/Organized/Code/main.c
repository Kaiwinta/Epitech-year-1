/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** main.c
*/

#include "include/shell.h"

int main(int argc, char **argv)
{
    linked_list_t *list = NULL;

    if (argc != 1)
        return 84;
    return workshop_shell(&list);
}
