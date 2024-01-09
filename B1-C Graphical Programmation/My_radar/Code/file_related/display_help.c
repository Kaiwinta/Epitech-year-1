/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** display_help.c
*/

#include "../include/my.h"

int display_help(void)
{
    char *temp;
    int fd = 0;
    struct stat buff;

    fd = open("bin/help.txt", O_RDONLY);
    stat("bin/help.txt", &buff);
    temp = malloc(sizeof(char) * (buff.st_size + 1));
    read(fd, temp, buff.st_size);
    temp[buff.st_size] = '\0';
    my_putstr(temp);
    free(temp);
    close(fd);
    return 0;
}
