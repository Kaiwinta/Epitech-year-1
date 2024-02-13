/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** add.c
*/

#include "../include/shell.h"

int my_put_in_list(linked_list_t **head, char *type, char *name, int id)
{
    linked_list_t *temp = malloc(sizeof(linked_list_t));

    temp->type = malloc(sizeof(char) * (my_strlen(type) + 1));
    temp->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    my_strcpy(temp->type, type);
    my_strcpy(temp->name, name);
    temp->name[my_strlen(name)] = '\0';
    temp->type[my_strlen(type)] = '\0';
    temp->next = *head;
    temp->id = id;
    *head = temp;
    mini_printf("%s n°%d - \"%s\" added.\n", temp->type, temp->id, temp->name);
    return 0;
}

int can_add(char *type)
{
    int returned = 0;

    if (my_strcmp(type, "WIRE") == 0)
        returned += 1;
    if (my_strcmp(type, "ACTUATOR") == 0)
        returned += 1;
    if (my_strcmp(type, "DEVICE") == 0)
        returned += 1;
    if (my_strcmp(type, "SENSOR") == 0)
        returned += 1;
    if (my_strcmp(type, "PROCESSOR") == 0)
        returned += 1;
    return returned;
}

int add(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;
    static int id = 0;
    int i = 0;

    for (i; args[i]; i += 2) {
        if (!args[i + 1])
            return 84;
        if (!can_add(args[i]))
            return 84;
    }
    if (i == 0)
        return 84;
    for (int i = 0; args[i]; i += 2) {
        my_put_in_list(head, args[i], args[i + 1], id);
        id++;
    }
    return 0;
}
