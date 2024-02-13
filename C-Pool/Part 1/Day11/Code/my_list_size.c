/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

int my_list_size(linked_list_t const *begin)
{
    int count = 0;
    linked_list_t *tmp;

    if (begin == NULL)
        return 0;
    *tmp = *begin;
    while (tmp != NULL) {
        tmp = tmp->next;
        count++;
    }
    return count;
}
