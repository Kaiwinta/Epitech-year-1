/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_event.c
*/

#include "../include/my.h"

void choose_mode(sprite_list *s_list, game_stat *stat)
{
    if (stat->mode == 'n')
        manage_touched_normal(s_list, stat);
    if (stat->mode == 'e')
        manage_touched_easy(s_list, stat);
    if (stat->mode == 'h')
        manage_touched_hard(s_list, stat);
    if (stat->mode == 'x')
        manage_touched_extreme(s_list, stat);
}

void manage_mouse_click(sfMouseButtonEvent event, sprite_list *s_list,
    game_stat *stat)
{
    int touched = 0;

    sfSound_play(stat->window->shoot_sound);
    stat->nb_click = stat->nb_click + 1;
    while (s_list) {
        if (event.x >= s_list->vect.x && event.x <= s_list->vect.x +
            s_list->rect.width * s_list->size_ratio && event.y >=
            s_list->vect.y && event.y <= s_list->vect.y +
            s_list->rect.height * s_list->size_ratio) {
            choose_mode(s_list, stat);
            touched = 1;
        }
        (s_list) = (s_list)->next;
    }
    if (touched)
        stat->nb_touch = stat->nb_touch + 1;
}

void analyse_events(sfRenderWindow *window, sfEvent *event,
    sprite_list *s_list, game_stat *stat)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseButtonPressed) {
        manage_mouse_click(event->mouseButton, s_list, stat);
        update_text_aim(stat);
    }
}

static void choose_boss_mode(sprite_list *s_list, game_stat *stat)
{
    if (stat->mode == 'e')
        manage_boss_touched_easy(s_list, stat);
    if (stat->mode == 'n')
        manage_boss_touched_normal(s_list, stat);
    if (stat->mode == 'h')
        manage_boss_touched_hard(s_list, stat);
    if (stat->mode == 'x')
        manage_boss_touched_extreme(s_list, stat);
    update_boss_life(stat->window->t_list, s_list);
}

void manage_boss_mouse_click(sfMouseButtonEvent event, sprite_list *s_list,
    game_stat *stat)
{
    int touched = 0;

    sfSound_play(stat->window->shoot_sound);
    stat->nb_click = stat->nb_click + 1;
    if (event.x >= s_list->vect.x && event.x <= s_list->vect.x +
        s_list->rect.width * s_list->size_ratio && event.y >=
        s_list->vect.y && event.y <= s_list->vect.y +
        s_list->rect.height * s_list->size_ratio) {
        choose_boss_mode(s_list, stat);
        touched = 1;
    }
    if (touched)
        stat->nb_touch = stat->nb_touch + 1;
}

void analyse_boss_events(sfRenderWindow *window, sfEvent *event,
    sprite_list *s_list, game_stat *stat)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseButtonPressed) {
        manage_boss_mouse_click(event->mouseButton, s_list, stat);
        update_text_aim(stat);
    }
}
