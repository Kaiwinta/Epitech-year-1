/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

linked_list_t *my_find_node(linked_list_t *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref) == 0)
            return tmp;
        tmp = tmp->next;
    }
}
