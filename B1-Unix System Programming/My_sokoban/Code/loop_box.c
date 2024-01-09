/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-titouan.pradoura
** File description:
** loop_box.c
*/

#include "include/my.h"

void is_stuck(int y, int x, char **map, game_t *stat)
{
    int stucky = 0;
    int stuckx = 0;

    if (! map[y + 1] || my_strlen(map[y + 1]) <
        x || map[y + 1][x] == '#' || map[y + 1][x] == 'X')
        stucky += 1;
    if (y == 0 || my_strlen(map[y - 1]) <
        x || map[y - 1][x] == '#' || map[y - 1][x] == 'X')
        stucky += 1;
    if (x + 1 >= my_strlen(map[y]) ||
        map[y][x + 1] == '#' || map[y][x + 1] == 'X')
        stuckx += 1;
    if (x == 0 || map[y][x - 1] == '#' || map[y][x - 1] == 'X')
        stuckx += 1;
    if (stuckx > 0 && stucky > 0)
        stat->nb_blocked = stat->nb_blocked + 1;
}

void box_box(char **temp, int y, int x, game_t *stat)
{
    if (temp[y][x] == 'X') {
        is_stuck(y, x, temp, stat);
    }
}

void loop_box(game_t *stat, char **map)
{
    stat->nb_blocked = 0;
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            box_box(map, y, x, stat);
        }
    }
}
