/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** display.c
*/

#include "../include/my.h"

static void display_single_plane(game_t *game, plane_t *planes)
{
    sfSprite_setPosition(planes->sprite, planes->pos);
    if (game->show_sprite)
        sfRenderWindow_drawSprite(game->window, planes->sprite, 0);
    if (game->show_box)
        sfRenderWindow_drawRectangleShape(game->window,
            planes->square, NULL);
}

void display_all_text(text_t *head, sfRenderWindow *window, sfFont *font)
{
    while (head) {
        sfRenderWindow_drawText(window, head->str, NULL);
        head = head->next;
    }
}

static void display_speed_arrow(game_t *game)
{
    if (game->accel <= 0.75)
        sfRenderWindow_drawSprite(game->window, game->arrow->sprite1, 0);
    if (game->accel <= 0.50)
        sfRenderWindow_drawSprite(game->window, game->arrow->sprite2, 0);
    if (game->accel <= 0.25)
        sfRenderWindow_drawSprite(game->window, game->arrow->sprite3, 0);
}

void display_all(game_t *game, plane_t *planes, tower_t *tower)
{
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, 0);
    while (tower) {
        if (game->show_sprite)
            sfRenderWindow_drawSprite(game->window, tower->sprite, 0);
        if (game->show_box)
            sfRenderWindow_drawCircleShape(game->window, tower->circle, 0);
        (tower) = (tower)->next;
    }
    while (planes) {
        if (planes->in_air == 1)
            display_single_plane(game, planes);
        (planes) = (planes)->next;
    }
    display_all_text(game->game_text, game->window, game->font);
    display_speed_arrow(game);
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, 0);
    display_all_text(game->menu_text, game->window, game->font);
}

void display_end(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, 0);
    display_all_text(game->end_text, game->window, game->font);
}
