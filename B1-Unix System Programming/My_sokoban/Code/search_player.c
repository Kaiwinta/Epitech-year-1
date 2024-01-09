/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-titouan.pradoura
** File description:
** search_player.c
*/

#include "include/my.h"

void is_player(char temp, int y, int x, player_t *player)
{
    if (temp == 'P') {
        player->x = x;
        player->y = y;
    }
}

void is_slot(char temp, int y, int x, game_t *stat)
{
    if (temp == 'O') {
        stat->slot_x[stat->nb_found] = x;
        stat->slot_y[stat->nb_found] = y;
        stat->nb_found = stat->nb_found + 1;
    }
}

void is_box(char temp, int y, int x, game_t *stat)
{
    if (temp == 'X') {
        stat->box_x[stat->nb_box_found] = x;
        stat->box_y[stat->nb_box_found] = y;
        stat->nb_box_found = stat->nb_box_found + 1;
    }
}

static void change_max(int *max, int y)
{
    if (y > *max)
        *max = *max + 1;
}

void search_player_and_slot(player_t *player, char **map, game_t *stat)
{
    int max = 0;

    for (int i = 0; map[i]; i++) {
        for (int y = 0; map[i][y]; y++) {
            change_max(&max, y);
            is_slot(map[i][y], i, y, stat);
            is_box(map[i][y], i, y, stat);
            is_player(map[i][y], i, y, player);
        }
    }
    stat->p_x = player->x;
    stat->p_y = player->y;
    stat->len_line_max = max + 1;
    stat->box_x[stat->nb_box_found] = -1;
    stat->box_y[stat->nb_box_found] = -1;
    stat->slot_x[stat->nb_found] = -1;
    stat->slot_y[stat->nb_found] = -1;
}
