/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-titouan.pradoura
** File description:
** movement.c
*/

#include "include/my.h"

void down(player_t *player, char **temp, game_t *stat)
{
    if (temp[player->y + 1] && my_strlen(temp[player->y + 1]) >
        player->x && temp[player->y + 1][player->x] != '#')
        if (temp[player->y + 1][player->x] == 'X' && temp[player->y + 2] &&
        my_strlen(temp[player->y + 2]) > player->x &&
        temp[player->y + 2][player->x] != '#' &&
        temp[player->y + 2][player->x] != 'X') {
            player->y = player->y + 1;
            temp[player->y + 1][player->x] = 'X';
        } else if (temp[player->y + 1][player->x] != 'X')
            player->y = player->y + 1;
}

void go_top(player_t *player, char **temp, game_t *stat)
{
    if (player->y > 0 && my_strlen(temp[player->y - 1]) >
        player->x && temp[player->y - 1][player->x] != '#')
        if (temp[player->y - 1][player->x] == 'X' && player->y - 1 > 0 &&
        my_strlen(temp[player->y - 2]) > player->x &&
        temp[player->y - 2][player->x] != '#' &&
        temp[player->y - 2][player->x] != 'X') {
            player->y = player->y - 1;
            temp[player->y - 1][player->x] = 'X';
        } else if (temp[player->y - 1][player->x] != 'X')
            player->y = player->y - 1;
}

void right(player_t *player, char **temp, game_t *stat)
{
    if (player->x + 1 < my_strlen(temp[player->y]) &&
        temp[player->y][player->x + 1] != '#')
        if (temp[player->y][player->x + 1] == 'X' && player->x + 2 <
        my_strlen(temp[player->y]) && temp[player->y][player->x + 2] != '#'
        && temp[player->y][player->x + 2] != 'X') {
            player->x = player->x + 1;
            temp[player->y][player->x + 1] = 'X';
        } else if (temp[player->y][player->x + 1] != 'X')
            player->x = player->x + 1;
}

void left(player_t *player, char **temp, game_t *stat)
{
    if (player->x > 0 && temp[player->y][player->x - 1] != '#')
        if (temp[player->y][player->x - 1] == 'X' && player->x - 1 > 0 &&
        temp[player->y][player->x - 2] != '#' &&
        temp[player->y][player->x - 2] != 'X') {
            player->x = player->x - 1;
            temp[player->y][player->x - 1] = 'X';
        } else if (temp[player->y][player->x - 1] != 'X')
            player->x = player->x - 1;
}

static void change_to_space(char **map, int y, int x)
{
    if (map[y][x] == 'X' || map[y][x] == 'P') {
        map[y][x] = ' ';
    }
}

void space(char **map, game_t *stat, player_t *player)
{
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            change_to_space(map, y, x);
        }
    }
    for (int s = 0; stat->slot_x[s] != -1; s++)
        map[stat->slot_y[s]][stat->slot_x[s]] = 'O';
    for (int s = 0; stat->box_x[s] != -1; s++)
        map[stat->box_y[s]][stat->box_x[s]] = 'X';
    player->x = stat->p_x;
    player->y = stat->p_y;
}
