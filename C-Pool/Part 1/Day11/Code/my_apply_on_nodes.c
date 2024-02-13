/*
** EPITECH PROJECT, 2023
** my_apply_on_nodes.c
** File description:
** apply a certain function on all nod eof a linked list
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        (*f)(tmp->data);
        tmp = tmp->next;
    }
}
