/*
** EPITECH PROJECT, 2023
** concat_params.c
** File description:
** Concatenate all the argument into a string
*/

#include <stdlib.h>

int my_strlen7(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *concat_params(int argc, char **argv)
{
    int len = 0;
    int j = 0;
    int w = 0;
    char *dest;

    for (int i = 0; i < argc; i++) {
        len = len + my_strlen7(argv[i]);
    }
    dest = malloc(sizeof(char) * (len + argc + 1));
    for (int w = 0; w < argc; w++) {
        for (int y = 0; y < my_strlen7(argv[w]); y++) {
            dest[j] = argv[w][y];
            j++;
        }
        dest[j] = '\n';
        j++;
    }
    dest[j - 1] = '\0';
    return dest;
}
