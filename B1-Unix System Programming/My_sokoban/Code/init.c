/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-titouan.pradoura
** File description:
** init.c
*/

#include "include/my.h"

player_t *init_player(void)
{
    player_t *temp = malloc(sizeof(player_t));

    temp->x = 0;
    temp->y = 0;
    temp->under_me = ' ';
    return temp;
}

game_t *init_game()
{
    game_t *stat = malloc(sizeof(game_t));

    stat->nb_o = 0;
    stat->nb_x = 0;
    stat->nb_p = 0;
    stat->p_x = 0;
    stat->p_y = 0;
    stat->nb_line = 0;
    stat->nb_box_found = 0;
    stat->nb_found = 0;
    stat->nb_blocked = 0;
    stat->len_line_max = 0;
    return stat;
}
