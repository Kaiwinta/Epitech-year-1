/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-titouan.pradoura
** File description:
** main.c
*/

#include "include/cpe.h"
#include "include/my.h"
#include <time.h>

int check_param(int ac, char **av)
{
    int returned = 0;
    int fd;
    struct stat buff;

    if (ac == 2)
        if (stat(av[1], &buff) != -1) {
            fd = open(av[1], O_RDONLY);
            returned += open_files(&buff, fd);
            close(fd);
            return returned;
        } else
            return 84;
    if (ac == 3)
        if (stat(av[1], &buff) == -1)
            return generating(av[2], av[1]);
        else
            return 84;
    return 84;
}

int main(int ac, char **av)
{
    int returned = 0;

    returned += check_param(ac, av);
    return (returned > 0) * 84;
}
