/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    linked_list_t *next = NULL;
    linked_list_t *prec;

    if (!tmp)
        return;
    while (tmp->next != NULL) {
        next = tmp->next;
        tmp->next = next;
        prec = tmp;
        tmp = next;
    }
}
