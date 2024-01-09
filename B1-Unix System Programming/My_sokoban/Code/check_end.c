/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-titouan.pradoura
** File description:
** check_end.c
*/

#include "include/my.h"

static int check_all_box(game_t *stat, char **map)
{
    for (int i = 0; stat->slot_y[i] != -1; i++)
        if (map[stat->slot_y[i]][stat->slot_x[i]] != 'X') {
            return 2;
        }
    return 1;
}

int check_end(game_t *stat, char **map)
{
    if (stat->nb_blocked == stat->nb_x) {
        return check_all_box(stat, map);
    }
    for (int i = 0; stat->slot_y[i] != -1; i++) {
        if (map[stat->slot_y[i]][stat->slot_x[i]] != 'X')
            return 0;
    }
    return 1;
}

void change_under_me(player_t *player, game_t *stat)
{
    int changed = 0;

    for (int i = 0; stat->slot_y[i] != -1; i++)
        if (player->x == stat->slot_x[i] && player->y == stat->slot_y[i]) {
            changed = 1;
            player->under_me = 'O';
        }
    if (changed == 0)
        player->under_me = ' ';
}
