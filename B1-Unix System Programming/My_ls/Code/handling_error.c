/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** handling_error.c
*/

#include "include/my.h"

int is_error(char *name, struct flag **flag_list, int *nb_files)
{
    DIR *dir = opendir(name);
    struct stat buff;
    struct passwd *root_info = getpwuid(0);

    if (dir == NULL) {
        if (stat(name, &buff) == -1) {
            my_puterror("ls: cannot access '");
            my_puterror(name);
            my_puterror("': No such file or directory\n");
            return 84;
        }
        if (my_strncmp("/root", name, 5) == 0)
            return 84;
    }
    closedir(dir);
    return 0;
}

int loop_error(char **av, struct flag **flag_list, int *nb_files, int ac)
{
    int returned = 0;
    int i = 1;

    if (ac == 1)
        return 0;
    while (i < ac) {
        if (*nb_files == 0)
            return 0;
        if (av[i][0] != '-' && *nb_files > 0)
            returned += is_error(av[i], flag_list, nb_files);
        i++;
    }
    return returned;
}
