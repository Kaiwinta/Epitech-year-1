/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** my_strcmp.c
*/

#include "../include/shell.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] > s2[i] || s2[i] == '\0') {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    if (s2[i] == '\0') {
        return 0;
    }
    return -1;
}
