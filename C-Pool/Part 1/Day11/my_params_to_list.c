/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** create a linked list of the params
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

int my_put_in_list(linked_list_t **list, void *data)
{
    linked_list_t *temp;

    temp = malloc(sizeof(*temp));
    temp->data = data;
    temp->next = *list;
    *list = temp;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;

    list = NULL;
    for (int i = 0; i < ac; i++) {
        my_put_in_list(&list, av[i]);
    }
    return list;
}
