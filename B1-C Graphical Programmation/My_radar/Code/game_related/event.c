/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** event.c
*/

#include "../include/my.h"

void analyse_events(game_t **game, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close((*game)->window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyL) {
            (*game)->show_box = 1 - (*game)->show_box;
        }
        if (event->key.code == sfKeyS) {
            (*game)->show_sprite = 1 - (*game)->show_sprite;
        }
        if (event->key.code == sfKeyUp && (*game)->accel >= 0.5) {
            (*game)->accel = (*game)->accel - 0.25;
        }
        if (event->key.code == sfKeyDown && (*game)->accel <= 0.75) {
            (*game)->accel = (*game)->accel + 0.25;
        }
    }
}

void analyse_events_menu(game_t **game, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close((*game)->window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeySpace) {
            (*game)->menu = 0;
        }
    }
}

void analyse_events_end(game_t **game, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close((*game)->window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeySpace) {
            sfRenderWindow_close((*game)->window);
        }
    }
}
