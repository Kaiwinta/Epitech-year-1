/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** display.c
*/

#include "include/my.h"

int choose_display(files **fichier, files **dossier, int nb_files,
    flag **flag_list)
{
    if ((*flag_list)->case_l == 1 || (*flag_list)->case_o)
        case_ldir(dossier, flag_list, (*fichier)->name, nb_files);
    else
        show_linked(dossier, nb_files, flag_list, fichier);
    return 0;
}

void display_all(files **fichier, flag **flag_list, int nb_files, int has_prec)
{
    struct stat temp;
    struct files *dossier = NULL;
    DIR *dir;

    while ((*fichier)) {
        if (has_prec)
            my_putstr("\n");
        dir = opendir((*fichier)->name);
        if (dir != NULL) {
            dossier = one_dir((*fichier)->name, flag_list, &nb_files);
            sort_linked_list(&dossier, flag_list);
            rev_linked_list(&dossier, flag_list, 0);
            choose_display(fichier, &dossier, nb_files, flag_list);
            dossier = NULL;
            has_prec = 1;
        }
        (*fichier) = (*fichier)->next;
    }
    free(dossier);
}

int loop_number(files *fichier, char *path)
{
    struct stat buff;
    char *temp;
    files *fichier_temp = fichier;
    int count = 0;

    while (fichier_temp != NULL) {
        temp = my_strcat(path, fichier_temp->name);
        stat(temp, &buff);
        count += buff.st_size / 1024;
        (fichier_temp) = (fichier_temp)->next;
    }
    return count;
}
