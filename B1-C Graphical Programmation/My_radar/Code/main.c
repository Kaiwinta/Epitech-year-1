/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr_err("The programm need only one argument\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        return display_help();
    }
    return open_file(argv[1]);
}
