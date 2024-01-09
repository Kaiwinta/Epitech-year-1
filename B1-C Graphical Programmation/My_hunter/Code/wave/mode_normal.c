/*
** EPITECH PROJECT, 2023
** Visual
** File description:
** task1.c
*/

#include "../include/my.h"

void manage_touched_normal(sprite_list *s_list, game_stat *stat)
{
    sfVector2f scale;

    if (s_list->size_ratio > stat->size) {
        s_list->boosted += 1;
        s_list->x_vel = -s_list->x_vel;
        s_list->y_vel = -s_list->y_vel;
        s_list->size_ratio = s_list->size_ratio - 1;
        scale = update_scale(s_list);
        s_list->vect.x += 16;
        s_list->vect.y += 16;
        s_list->scale = scale;
        update_rotation(s_list);
    } else if (s_list->size_ratio == stat->size) {
        s_list->size_ratio = 0;
        stat->nb_dead = stat->nb_dead + 1;
        scale = update_scale(s_list);
        s_list->scale = scale;
        update_text_remain(stat);
    }
    sfSprite_setScale(s_list->sprite, (s_list)->scale);
}

static game_stat *init_normal_game(int wave, my_window_t *screen)
{
    game_stat *temp = malloc(sizeof(game_stat));

    temp->mode = 'n';
    temp->nb_ghost = 7 + 2 * wave;
    temp->nb_click = 0;
    temp->nb_touch = 0;
    temp->size = 2;
    temp->max_speed = 20 + 2 * wave;
    temp->nb_dead = 0;
    temp->window = screen;
    return temp;
}

int normal(sfRenderWindow *window, int wave, my_window_t *screen)
{
    sfClock *clock = sfClock_create();
    sprite_list *s_list = NULL;
    game_stat *stat = init_normal_game(wave, screen);

    update_text_remain(stat);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < stat->nb_ghost; i++) {
        add_in_list(&s_list, stat);
    }
    while (sfRenderWindow_isOpen(window) && stat->nb_dead != stat->nb_ghost) {
        run_game(window, clock, s_list, stat);
    }
    sfClock_destroy(clock);
    if (stat->nb_dead == stat->nb_ghost) {
        update_aim(stat, screen);
        free_all(&s_list, stat);
        restart(window, 'n', wave, screen);
    } else
        free_all(&s_list, stat);
    return 0;
}
