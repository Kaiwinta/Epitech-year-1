/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** check.c
*/

#include "../include/shell.h"

int check_for_id(flag_sort_t *flag_list, linked_list_t *head,
    linked_list_t *temp)
{
    if (flag_list->name == 1 && my_strcmp(head->name, temp->name) != 0)
        return 0;
    if (flag_list->type == 1 && my_strcmp(head->type, temp->type) != 0)
        return 0;
    return 1;
}

void swapping_int(linked_list_t *temp, linked_list_t **actual, int *swapped, flag_sort_t *flag_list)
{
    if (temp->id > temp->next->id && check_for_id(flag_list, temp, temp->next)) {
        *actual = swap(temp, temp->next);
        *swapped = 1;
    }
}

int check_for_name(flag_sort_t *flag_list, linked_list_t *head,
    linked_list_t *temp)
{
    if (flag_list->id == 1 && head->id != temp->id)
        return 0;
    if (flag_list->type == 1 && my_strcmp(head->type, temp->type) != 0)
        return 0;
    return 1;
}

int check_for_type(flag_sort_t *flag_list, linked_list_t *head,
    linked_list_t *temp)
{
    if (flag_list->id == 1 && head->id != temp->id)
        return 0;
    if (flag_list->name == 1 && my_strcmp(head->name, temp->name) != 0)
        return 0;
    return 1;
}
