/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** free.c
*/

#include "../include/my.h"

int free_text_list(text_t *t_list)
{
    text_t *temp = t_list;

    if (!temp)
        return 0;
    while (t_list != NULL) {
        temp = (t_list);
        (t_list) = t_list->next;
        free(temp->src_text);
        sfText_destroy(temp->str);
        free(temp);
    }
}

void free_plane_list(plane_t *head)
{
    plane_t *temp;

    while (head) {
        temp = head->next;
        sfSprite_destroy(head->sprite);
        sfRectangleShape_destroy(head->square);
        free(head);
        head = temp;
    }
}

void free_tower_list(tower_t *tower)
{
    tower_t *temp;

    while (tower) {
        temp = tower->next;
        sfCircleShape_destroy(tower->circle);
        sfSprite_destroy(tower->sprite);
        free(tower);
        tower = temp;
    }
}

void free_arrow_sprite(arrow_t *arrow)
{
    sfSprite_destroy(arrow->sprite1);
    sfSprite_destroy(arrow->sprite2);
    sfSprite_destroy(arrow->sprite3);
    free(arrow);
}

void free_game(game_t *game)
{
    if (game->head)
        free_plane_list(game->head);
    free_arrow_sprite(game->arrow);
    free_tower_list(game->tower);
    free_text_list(game->game_text);
    free_text_list(game->menu_text);
    free_text_list(game->end_text);
    sfClock_destroy(game->clock);
    sfTexture_destroy(game->plane_text);
    sfTexture_destroy(game->tow_text);
    sfTexture_destroy(game->flag_text);
    sfTexture_destroy(game->arrow_text);
    sfTexture_destroy(game->bg_text);
    sfSprite_destroy(game->bg_sprite);
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->window);
    free(game);
}
