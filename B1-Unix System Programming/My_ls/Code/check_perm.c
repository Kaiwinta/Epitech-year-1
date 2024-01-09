/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** check_perm.c
*/

#include "include/my.h"

static void check_sticky(int permissions)
{
    if (permissions & S_ISVTX)
        mini_printf("t");
}

static void perm_oth(struct stat *temp)
{
    if (temp->st_mode & S_IROTH)
        mini_printf("r");
    else
        mini_printf("-");
    if (temp->st_mode & S_IWOTH)
        mini_printf("w");
    else
        mini_printf("-");
    if (temp->st_mode & S_IXOTH && temp->st_mode & S_ISVTX)
        mini_printf("t");
    if (!(temp->st_mode & S_IXOTH) && temp->st_mode & S_ISVTX)
        mini_printf("T");
    if (!(temp->st_mode & S_IXOTH && temp->st_mode & S_ISVTX))
        mini_printf("-");
}

static void perm_grp(struct stat *temp)
{
    if (temp->st_mode & S_IRGRP)
        mini_printf("r");
    else
        mini_printf("-");
    if (temp->st_mode & S_IWGRP)
        mini_printf("w");
    else
        mini_printf("-");
    if (temp->st_mode & S_IXGRP)
        mini_printf("x");
    else
        mini_printf("-");
}

void my_get_perm(struct stat *temp)
{
    if (temp->st_mode & S_IRUSR)
        mini_printf("r");
    else
        mini_printf("-");
    if (temp->st_mode & S_IWUSR)
        mini_printf("w");
    else
        mini_printf("-");
    if (temp->st_mode & S_IXUSR)
        mini_printf("x");
    else
        mini_printf("-");
    perm_grp(temp);
    perm_oth(temp);
}
