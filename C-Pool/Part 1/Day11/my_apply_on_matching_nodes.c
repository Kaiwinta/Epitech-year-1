/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

int my_apply_on_matching_nodes(linked_list_t *begin,
    int (*f)(), void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref) == 0)
            (*f)(tmp->data);
        tmp = tmp->next;
    }
}
