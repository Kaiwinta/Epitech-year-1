/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

int my_concat_list(linked_list_t **begin, linked_list_t *begin2)
{
    int count = 0;
    linked_list_t *tmp;

    tmp = *begin;
    while (tmp != NULL) {
        tmp = tmp->next;
    }
    tmp->next = begin2;
}
