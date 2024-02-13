/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** disp.c
*/

#include "../include/shell.h"

void display_one(linked_list_t *data)
{
    mini_printf("%s n°%d - \"%s\"\n", data->type, data->id, data->name);
}

int display_all(linked_list_t *data)
{
    while (data != NULL) {
        display_one(data);
        data = (data)->next;
    }
}

int disp(void *data, char **args)
{
    int i = 0;
    linked_list_t **link_head = (linked_list_t **)data;

    for (i; args[i]; i++);
    if (i != 0)
        return 84;
    display_all(*link_head);
    return 0;
}
