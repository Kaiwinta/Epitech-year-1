/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** del.c
*/

#include "../include/shell.h"

static void change(linked_list_t **tmp, linked_list_t **tmpnext)
{
    if (*tmp != NULL)
        *tmp = (*tmp)->next;
    if (*tmp != NULL)
        *tmpnext = (*tmp)->next;
    else
        *tmpnext = NULL;
}

static int check_temp(linked_list_t **tmp, linked_list_t **tmpnext,
    linked_list_t **begin, int id_ref)
{
    if ((*tmp)->id == id_ref) {
        mini_printf("%s n°%d - \"%s\" deleted.\n",
            (*tmp)->type, (*tmp)->id, (*tmp)->name);
        if ((*tmp)->next)
            *begin = *tmpnext;
        else
            *begin = NULL;
        free(*tmp);
        return 1;
    }
    return 0;
}

int my_delete_nodes(linked_list_t **begin, int id_ref)
{
    linked_list_t *tmp = *begin;
    linked_list_t *tmpnext;
    int deleted = 0;

    if (*begin == NULL)
        return 0;
    tmpnext = tmp->next;
    deleted += check_temp(&tmp, &tmpnext, begin, id_ref);
    while (tmpnext != NULL) {
        if (tmpnext->id == id_ref) {
            mini_printf("%s n°%d - \"%s\" deleted.\n",
                tmpnext->type, tmpnext->id, tmpnext->name);
            tmp->next = tmpnext->next;
            free(tmpnext);
            deleted += 1;
        }
        change(&tmp, &tmpnext);
    }
    return deleted;
}

int get_nbr(char *temp)
{
    int i = 0;

    for (int y = 0; temp[y] != '\0'; y++) {
        if (temp[y] < 48 || temp[y] > 57)
            return -1;
        i *= 10;
        i += temp[y] - 48;
    }
    return i;
}

int del(void *data, char **args)
{
    int i = 0;
    int id = 0;
    linked_list_t **link_head = (linked_list_t **)data;

    for (i; args[i]; i++);
    if (i == 0)
        return 84;
    for (int y = 0; args[y]; y++) {
        id = get_nbr(args[y]);
        if (id == -1)
            return 84;
    }
    for (int y = 0; args[y]; y++) {
        id = get_nbr(args[y]);
        if (id == -1 || my_delete_nodes(link_head, id) == 0)
            return 84;
    }
    return 0;
}
