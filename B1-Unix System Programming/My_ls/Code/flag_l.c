/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** flag_l.c
*/

#include <time.h>
#include "include/my.h"

static char check_type(struct stat *buf)
{
    if (S_ISLNK(buf->st_mode) != 0)
        return 'l';
    if (S_ISREG(buf->st_mode) != 0)
        return '-';
    if (S_ISDIR(buf->st_mode) != 0)
        return 'd';
    if (S_ISCHR(buf->st_mode) != 0)
        return 'c';
    if (S_ISBLK(buf->st_mode) != 0)
        return 'b';
    if (S_ISFIFO(buf->st_mode) != 0)
        return 'p';
    if (S_ISSOCK(buf->st_mode) != 0)
        return 's';
    return '?';
}

static char *cut_in(char *str)
{
    char *temp = alloc_memory(15);

    for (int i = 8; i < 11; i++) {
        temp[i - 8] = str[i];
    }
    for (int i = 4; i < 7; i++) {
        temp[i - 1] = str[i];
    }
    temp[6] = '.';
    for (int i = 10; i < 16; i++)
        temp[i - 3] = str[i];
    return temp;
}

static char *cut_path(char *path, int nb)
{
    char *temp = malloc(sizeof(char) * my_strlen(path));
    int y = 0;

    for (int i = 0; path[i]; i++) {
        if (path[i] == '/')
            nb --;
        if (nb == 0 && path[i] != '/') {
            temp[y] = path[i];
            y++;
        }
    }
    temp[y] = '\0';
    return temp;
}

static void files_name(char *path, flag **flag_list)
{
    int nb = 0;

    for (int i = 0; path[i]; i++) {
        if (path[i] == '/' && path[i + 1] != '\0') {
            nb ++;
        }
    }
    show_quote(cut_path(path, nb), flag_list);
}

void show_size(char type, struct stat *temp)
{
    if (type != 'c' && type != 'b')
        mini_printf("%d %s", temp->st_size, cut_in(ctime(&temp->st_mtime)));
    else
        mini_printf("%d, %d", major(temp->st_rdev), minor(temp->st_rdev));
}

void show_l_files(char *name, flag **flag_list, int is_dir)
{
    struct stat temp;
    struct passwd *pass;
    struct group *grp;
    char type;

    stat(name, &temp);
    type = check_type(&temp);
    mini_printf("%c", type);
    my_get_perm(&temp);
    mini_printf(". %d ", temp.st_nlink);
    pass = getpwuid(temp.st_uid);
    grp = getgrgid(temp.st_gid);
    mini_printf("%s ", pass->pw_name);
    if ((*flag_list)->case_o == 0 && (*flag_list)->case_gmaj == 0)
        mini_printf("%s ", grp->gr_name);
    show_size(type, &temp);
    if (! is_dir)
        show_quote(name, flag_list);
    else
        (files_name(name, flag_list));
}

int case_l(files **fichier, struct flag **flag_list)
{
    int count = 0;

    while (*fichier != NULL) {
        show_l_files((*fichier)->name, flag_list, 0);
        count++;
        (*fichier) = (*fichier)->next;
    }
    return count;
}

int case_ldir(files **fichier, struct flag **flag_list,
    char *path, int nb_files)
{
    int count = 0;
    char *temp;
    struct stat buff;

    temp = my_strcat(path, "");
    if (stat(path, &buff) != -1 && (*flag_list)->case_d == 0)
        if (nb_files > 1 && S_ISDIR(buff.st_mode) == 1)
            mini_printf("%s:\n", temp);
    delete_point(fichier, flag_list);
    mini_printf("total %d\n", loop_number(*fichier, path));
    while (*fichier != NULL) {
        temp = my_strcat(path, (*fichier)->name);
        show_l_files(temp, flag_list, 1);
        free(temp);
        count++;
        (*fichier) = (*fichier)->next;
    }
    return count;
}
