/*
** EPITECH PROJECT, 2023
** mylist.h
** File description:
** The struct of the linked list
*/


#ifndef MYLIST_

    #define MYLIST_
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif /* MYLIST_ */
