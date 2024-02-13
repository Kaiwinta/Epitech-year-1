/*
** EPITECH PROJECT, 2023
** my_delte_nodes.c
** File description:
** Delete and element of a linked list
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

int *my_delete_nodes(linked_list_t *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;
    linked_list_t *tmpnext;

    tmp = begin;
    tmpnext = tmp->next;
    while (tmpnext != NULL) {
        if ((*cmp)(tmpnext->data, data_ref) == 0) {
            tmp->next = tmpnext->next;
            free(tmpnext);
        }
        tmp = tmp->next;
        tmpnext = tmp->next;
    }
    return 0;
}
