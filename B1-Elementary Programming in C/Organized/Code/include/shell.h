/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SHELL_H
    #define SHELL_H

typedef struct linked_list_s {
    char *type;
    char *name;
    int id;
    struct linked_list_s *next;
} linked_list_t;

typedef struct flag_sort_s {
    int type;
    int name;
    int id;
} flag_sort_t;

int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int add(void *head, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);
int workshop_shell(void *data);
void swapping_int(linked_list_t *temp, linked_list_t **actual, int *swapped, flag_sort_t *flag_list);
void add_in_sorted_id(linked_list_t **sorted_list, linked_list_t **temp,
    int rev, flag_sort_t *flag_list);
void add_in_sorted_id_rev(linked_list_t **sorted_list, linked_list_t **temp,
    int rev);
void add_in_sorted_name(linked_list_t **sorted_list, linked_list_t **temp,
    int rev);
void add_in_sorted_type(linked_list_t **sorted_list, linked_list_t **temp,
    int rev, flag_sort_t *flag_list);

#endif /* SHELL_H */
