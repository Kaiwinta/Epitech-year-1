/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** all_loop.c
*/

#include "include/my.h"

int loop_condition(char *str, char mode)
{
    struct stat temp;

    if (stat(str, &temp) == -1)
        return 0;
    if (mode == 'd') {
        return S_ISDIR(temp.st_mode) == 1;
    } else if (mode == 'f') {
        return S_ISDIR(temp.st_mode) == 0;
    }
}

void concat_list(files *dossier, files **fichier)
{
    while ((dossier)->next)
        (dossier) = (dossier)->next;
    (dossier)->next = (*fichier);
}

int little_function(files **fichier, flag **flag_list,
    files **dossier, int *nb_files)
{
    sort_linked_list(fichier, flag_list);
    show_file(fichier, flag_list);
    flag_and_show(dossier, flag_list, *nb_files, 1);
    return 0;
}

static void free_list(files *list)
{
    files *temp = NULL;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp->name);
        free(temp);
    }
}

int loop_dlr(char **av, flag **flag_list, int *nb_files, int ac)
{
    int returned = 0;
    char temp[] = ".";
    files *dossier = NULL;
    struct stat buff;

    if (ac == 1 || *nb_files <= 0)
        returned += my_put_in_list(&dossier, temp);
    for (int i = 1; i < ac; i++)
        if (av[i][0] != '-' && stat(av[i], &buff) != -1)
            returned += my_put_in_list(&dossier, av[i]);
    sort_linked_list(&dossier, flag_list);
    show_ld(&dossier, flag_list);
    if (! (*flag_list)->case_l)
        my_putchar('\n');
    free_list(dossier);
    return returned;
}

void loop(char **av, flag **flag_list, int *nb_files, int ac)
{
    files *dossier = NULL;
    files *fichier = NULL;

    if (ac == 1 || *nb_files <= 0)
        my_put_in_list(&dossier, ".");
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-' && loop_condition(av[i], 'd'))
            my_put_in_list(&dossier, av[i]);
        if (av[i][0] != '-' && loop_condition(av[i], 'f'))
            my_put_in_list(&fichier, av[i]);
        }
    if (dossier)
        sort_linked_list(&dossier, flag_list);
    if (fichier)
        little_function(&fichier, flag_list, &dossier, nb_files);
    else
        flag_and_show(&dossier, flag_list, *nb_files, 0);
    free(dossier);
    free(fichier);
}
