/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** The main of little ls
*/
#include "include/my.h"

int my_put_in_list(files **list, char *data)
{
    files *temp = malloc(sizeof(files));
    int len = my_strlen(data);
    struct stat buff;

    stat(data, &buff);
    temp = malloc(sizeof(files));
    temp->name = malloc(sizeof(char) * (len + 1));
    my_strcpy(temp->name, data);
    temp->name[len] = '\0';
    temp->time = buff.st_mtime;
    temp->next = *list;
    *list = temp;
    return 0;
}

struct files *one_dir(char *str, flag **flag_list, int *nb_files)
{
    DIR *dir = opendir(str);
    struct stat buff;
    struct dirent *entries;
    struct files *fichier = NULL;

    if (dir == NULL)
        return 0;
    entries = readdir(dir);
    while (entries != NULL) {
        my_put_in_list(&fichier, entries->d_name);
        entries = readdir(dir);
    }
    return fichier;
}

void check_second(char c, flag **temp)
{
    switch (c) {
    case 'a':
        (*temp)->case_a = 1;
        break;
    case 'Q':
        (*temp)->case_qmaj = 1;
        break;
    case 'o':
        (*temp)->case_o = 1;
        break;
    case 'G':
        (*temp)->case_gmaj = 1;
        break;
    case 'd':
        (*temp)->case_d = 1;
        break;
    case 't':
        (*temp)->case_t = 1;
    }
}

int one_flag(char *av, flag **temp)
{
    for (int i = 1; av[i] != '\0'; i++)
        switch (av[i]) {
        case 'l':
            (*temp)->case_l = 1;
            break;
        case 'r':
            (*temp)->case_r = 1;
            break;
        case 'R':
            (*temp)->case_rmaj = 1;
            break;
        default:
            check_second(av[i], temp);
        }
}
