/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-titouan.pradoura
** File description:
** generating.c
*/

#include "include/cpe.h"
#include "include/my.h"

long mini_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i++;
        } else {
            exit(84);
        }
    }
    return nb;
}

int check_pattern(char *pattern)
{
    for (int i = 0; pattern[i]; i++) {
        if (pattern[i] != '.' && pattern[i] != 'o')
            return 84;
    }
    return 0;
}

int generating(char *pattern, char *nb_line)
{
    long nb = mini_getnbr(nb_line);
    int i = 0;
    int y = 1;
    int len = my_strlen(pattern);
    int pattern_i = 0;
    char *map_char = malloc(nb * (nb + 1) + 2);

    if (check_pattern(pattern) > 0 || nb <= 0 || len <= 0)
        return 84;
    for (y; y <= nb * (nb + 1); y++) {
        if ((y) % (nb + 1) == 0)
            map_char[y - 1] = '\n';
        else {
            map_char[y - 1] = pattern[pattern_i % len];
            pattern_i++;
        }
    }
    map_char[y - 1] = '\0';
    loop_line(&i, nb, map_char);
    return 0;
}
