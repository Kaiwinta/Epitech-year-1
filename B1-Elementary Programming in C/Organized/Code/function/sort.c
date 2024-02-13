/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** sort.c
*/

#include "../include/shell.h"

static int check_flag(char *flag, int i)
{
    if (my_strcmp(flag, "NAME") == 0)
        return 1;
    if (my_strcmp(flag, "TYPE") == 0)
        return 1;
    if (my_strcmp(flag, "-r") == 0)
        if (i != 0)
            return 1;
        else
            return 0;
    if (my_strcmp(flag, "ID") == 0)
        return 1;
    return 0;
}

static flag_sort_t *init_flag(void)
{
    flag_sort_t *temp = malloc(sizeof(flag_sort_t));

    temp->id = 0;
    temp->name = 0;
    temp->type = 0;
}

static int change_rev(char **args, int i)
{
    if (args[i + 1]) {
        if (my_strcmp(args[i + 1], "-r") == 0 && my_strcmp(args[i], "-r") == 0)
            return -1;
        if (my_strcmp(args[i + 1], "-r") == 0)
            return 1;
    }
    return 0;
}

static int all_sort(linked_list_t **head,
    flag_sort_t *flag, char **args)
{
    int i = 0;
    int rev = 0;

    while (args[i]) {
        rev = change_rev(args, i);
        if (rev == -1)
            return 84;
        sort_by(args[i], rev, head, flag);
        i += rev;
        i++;
    }
}

static int choose_function(char *type, int rev, flag_sort_t *flag_list)
{
    if (my_strcmp(type, "NAME") == 0) {
        flag_list->name = 1;
        return 0;
    }
    if (my_strcmp(type, "TYPE") == 0) {
        flag_list->type = 1;
        return 1;
    }
    if (my_strcmp(type, "ID") == 0 && rev == 0) {
        flag_list->id = 1;
        return 2;
    }
    if (my_strcmp(type, "ID") == 0 && rev == 1) {
        flag_list->id = 1;
        return 3;
    }
}

int sort_by(char *type, int rev, linked_list_t **head, flag_sort_t *flag_list)
{
    // linked_list_t *sorted_list = NULL;
    // linked_list_t *temp = (*head);
    // linked_list_t *tempnext;
    void (*function[])(linked_list_t *, linked_list_t **, int *, flag_sort_t *) =
        {swapping_int};
    int i = 0;

    // if (temp)
    //     tempnext = temp->next;
    i = choose_function(type, rev, flag_list);
    if (i == 2)
        bubble_sort(head, flag_list, function[0]);
    // els
        // function[i](&sorted_list, &temp, rev, flag_list);
    // *head = sorted_list;
}

int sort(void *data, char **args)
{
    int i = 0;
    flag_sort_t *flag = init_flag();
    linked_list_t **link_head = (linked_list_t **)data;

    for (i; args[i]; i++)
        if (check_flag(args[i], i) == 0)
            return 84;
    if (i == 0)
        return 84;
    return all_sort(data, flag, args);
}
