/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** mode_hard.c
*/

#include "../include/my.h"

void manage_touched_hard(sprite_list *s_list, game_stat *stat)
{
    sfVector2f scale;

    if (s_list->size_ratio > stat->size) {
        s_list->boosted = 1;
        s_list->boosted += 2;
        go_random_dir(s_list);
        s_list->size_ratio = s_list->size_ratio - 0.5;
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

static game_stat *init_hard_game(int wave, my_window_t *screen)
{
    game_stat *temp = malloc(sizeof(game_stat));

    temp->mode = 'h';
    temp->nb_ghost = 8 + 2 * wave;
    temp->nb_click = 0;
    temp->nb_touch = 0;
    temp->size = 1;
    temp->max_speed = 30 + 2 * wave;
    temp->nb_dead = 0;
    temp->window = screen;
    return temp;
}

int hard(sfRenderWindow *window, int wave, my_window_t *screen)
{
    sfClock *clock = sfClock_create();
    sprite_list *s_list = NULL;
    game_stat *stat = init_hard_game(wave, screen);

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
        restart(window, 'h', wave, screen);
    } else
        free_all(&s_list, stat);
    return 0;
}
