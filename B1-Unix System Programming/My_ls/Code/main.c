/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** The main of little ls
*/
#include "include/my.h"


int show_ld(files **fichier, flag **flag_list)
{
    rev_linked_list(fichier, flag_list, 0);
    if ((*flag_list)->case_l)
        return case_l(fichier, flag_list);
    while (*fichier != NULL) {
        if ((*flag_list)->case_qmaj)
            mini_printf("\"%s\"  ", (*fichier)->name);
        else
            mini_printf("%s  ", (*fichier)->name);
        *fichier = (*fichier)->next;
    }
    return 0;
}

static void quote(char *name, flag **flag_list, char bonus)
{
    if ((*flag_list)->case_qmaj)
        mini_printf("\"%s\"", name);
    else
        mini_printf("%s", name);
    if (bonus == 'd')
        mini_printf("\n");
}

int show_linked(files **fichier, int nb_files, flag **flag_list, files **chef)
{
    int count = 0;
    char *str = (*chef)->name;
    struct stat temp;

    if (stat(str, &temp) != -1 && (*flag_list)->case_d == 0)
        if (nb_files > 1 && S_ISDIR(temp.st_mode) == 1)
            quote(str, flag_list, 'd');
    if ((*flag_list)->case_a == 0)
        delete_point(fichier, flag_list);
    rev_linked_list(fichier, flag_list, 0);
    while (*fichier != NULL) {
        quote((*fichier)->name, flag_list, 'n');
        if ((*fichier)->next != NULL)
            my_putstr("  ");
        count++;
        *fichier = (*fichier)->next;
    }
    if (count > 0 && S_ISDIR(temp.st_mode) && ! (*flag_list)->case_d)
        my_putstr("\n");
    return count;
}

int flag_and_show(files **fichier, flag **flag_list,
    int nb_files, int has_prec)
{
    rev_linked_list(fichier, flag_list, 0);
    if ((*flag_list)->case_d)
            return choose_display(fichier, fichier, nb_files, flag_list);
    display_all(fichier, flag_list, nb_files, has_prec);
}

int show_file(files **fichier, flag **flag_list)
{
    delete_point(fichier, flag_list);
    rev_linked_list(fichier, flag_list, 0);
    if ((*flag_list)->case_l)
        return case_l(fichier, flag_list);
    while (*fichier != NULL) {
        show_quote((*fichier)->name, flag_list);
        *fichier = (*fichier)->next;
        if (*fichier)
            my_putstr("  ");
    }
    my_putstr("\n");
}

static void init_flag(flag **our_flag)
{
    (*our_flag)->case_a = 0;
    (*our_flag)->case_t = 0;
    (*our_flag)->case_r = 0;
    (*our_flag)->case_rmaj = 0;
    (*our_flag)->case_l = 0;
    (*our_flag)->case_d = 0;
    (*our_flag)->case_qmaj = 0;
    (*our_flag)->case_gmaj = 0;
    (*our_flag)->case_o = 0;
}

int main(int ac, char **av)
{
    int i = 1;
    int nb_files = 0;
    int returned = 0;
    struct flag *our_flag = malloc(sizeof(struct flag));

    init_flag(&our_flag);
    for (i; i < ac; i++) {
        if (av[i][0] == '-')
            returned += one_flag(av[i], &our_flag);
        else
            nb_files++;
    }
    returned += loop_error(av, &our_flag, &nb_files, ac);
    if (our_flag->case_d == 1)
        returned += loop_dlr(av, &our_flag, &nb_files, ac);
    else
        loop(av, &our_flag, &nb_files, ac);
    free(our_flag);
    return (returned > 0) * 84;
}
