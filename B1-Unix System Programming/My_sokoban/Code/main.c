/*
** EPITECH PROJECT, 2023
** bs_sokoban
** File description:
** Untitled-1
*/

#include "include/my.h"

int display_help(void)
{
    char *temp;
    int fd = 0;

    fd = open("help.txt", O_RDONLY);
    temp = malloc(sizeof(char) * (199));
    read(fd, temp, 199);
    temp[199] = '\0';
    my_putstr(temp);
    free(temp);
    return 0;
}

int flag(char *av)
{
    if (my_strlen(av) == 2 && av[1] == 'h') {
        return display_help();
    }
    return 84;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-')
            return flag(av[1]);
        return my_soko(av[1]);
    } else
        return 84;
}
