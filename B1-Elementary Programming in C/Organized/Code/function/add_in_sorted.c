/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** add_in_sorted.c
*/

#include "../include/shell.h"

// void add_in_sorted_name(linked_list_t **sorted_list, linked_list_t **temp,
//     int rev)
// {
//     linked_list_t *buff;

//     if (!(*sorted_list) || my_strcmp((*sorted_list)->name,
//         (*temp)->name) == 1 - (2 * rev)) {
//         (*temp)->next = (*sorted_list);
//         (*sorted_list) = (*temp);
//     } else {
//         buff = (*sorted_list);
//         while (buff->next != NULL &&
//             my_strcmp(buff->next->name, (*temp)->name) == -1 + (2 * rev)) {
//             buff = buff->next;
//         }
//         (*temp)->next = buff->next;
//         buff->next = (*temp);
//     }
// }

// void add_in_sorted_type(linked_list_t **sorted_list, linked_list_t **temp,
//     int rev, flag_sort_t *flag_list)
// {
//     linked_list_t *buff;

//     if (!(*sorted_list) || my_strcmp((*sorted_list)->type,
//         (*temp)->type) == 1 - (2 * rev)) {
//         (*temp)->next = (*sorted_list);
//         (*sorted_list) = (*temp);
//     } else {
//         buff = (*sorted_list);
//         while (buff->next != NULL &&
//             my_strcmp(buff->next->type, (*temp)->type) == -1 + (2 * rev)) {
//             buff = buff->next;
//         }
//         (*temp)->next = buff->next;
//         buff->next = (*temp);
//     }
// }

// void add_in_sorted_id_rev(linked_list_t **sorted_list, linked_list_t **temp,
//     int rev)
// {
//     linked_list_t *buff;

//     if (!(*sorted_list) || (*sorted_list)->id < (*temp)->id) {
//         (*temp)->next = (*sorted_list);
//         (*sorted_list) = (*temp);
//     } else {
//         buff = (*sorted_list);
//         while (buff->next != NULL &&
//             buff->next->id > (*temp)->id) {
//             buff = buff->next;
//         }
//         (*temp)->next = buff->next;
//         buff->next = (*temp);
//     }
// }

linked_list_t* swap(linked_list_t* ptr1, linked_list_t* ptr2)
{
    linked_list_t* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubble_sort(linked_list_t **head, flag_sort_t *flag_list, void(*function)(linked_list_t *, linked_list_t **, int *))
{
    linked_list_t **actual;
    linked_list_t *temp;
    int swapped;

    while (1) {
        actual = head;
        swapped = 0;
        while (*actual && (*actual)->next) {
            temp = *actual;
            function(temp, actual, &swapped);
            actual = &(*actual)->next;
        }
        if (swapped == 0)
            break;
    }
}
