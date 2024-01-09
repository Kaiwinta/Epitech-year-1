/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-titouan.pradoura
** File description:
** check_files.c
*/

#include "include/my.h"

int rev_linked_list(files **begin, flag **flag_list, int forced)
{
    files *tmp = *begin;
    files *next = NULL;
    files *prec = NULL;

    if ((*flag_list)->case_r == 0 && !forced)
        return 0;
    if (!tmp)
        return 84;
    while (tmp->next != NULL) {
        next = tmp->next;
        tmp->next = prec;
        prec = tmp;
        tmp = next;
    }
    tmp->next = prec;
    *begin = tmp;
    return 0;
}

void add_in_sorted_time(files **sorted_list, files **temp)
{
    files *buff;

    if (! (*sorted_list) || (*sorted_list)->time <= (*temp)->time) {
        (*temp)->next = (*sorted_list);
        (*sorted_list) = (*temp);
    } else {
        buff = (*sorted_list);
        while (buff->next != NULL &&
            buff->next->time > (*temp)->time) {
            buff = buff->next;
        }
        (*temp)->next = buff->next;
        buff->next = (*temp);
    }
}

void add_in_sorted(files **sorted_list, files **temp)
{
    files *buff;

    if (! (*sorted_list) || ls_cmp((*sorted_list)->name, (*temp)->name) == 1) {
        (*temp)->next = (*sorted_list);
        (*sorted_list) = (*temp);
    } else {
        buff = (*sorted_list);
        while (buff->next != NULL &&
            ls_cmp(buff->next->name, (*temp)->name) == -1) {
            buff = buff->next;
        }
        (*temp)->next = buff->next;
        buff->next = (*temp);
    }
}

int sort_linked_list(files **fichier, flag **flag_list)
{
    files *sorted_list = NULL;
    files *temp = (*fichier);
    files *tempnext;

    if (temp)
        tempnext = temp->next;
    while (temp != NULL) {
        tempnext = temp->next;
        if ((*flag_list)->case_t)
            add_in_sorted_time(&sorted_list, &temp);
        else
            add_in_sorted(&sorted_list, &temp);
        temp = tempnext;
    }
    *fichier = sorted_list;
}

int delete_point(files **fichier, flag **flag_list)
{
    files *temp = (*fichier);
    files *temp_del = NULL;

    if ((*flag_list)->case_a || (*flag_list)->case_d)
        return 0;
    while (temp != NULL && temp->name[0] == '.') {
        (*fichier) = temp->next;
        temp = (*fichier);
    }
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->name[0] == '.') {
            temp_del = temp->next;
            temp->next = temp_del->next;
        } else
            temp = temp->next;
    }
    return 0;
}
