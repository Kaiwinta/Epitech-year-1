/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** mode_extreme.c
*/

#include "../include/my.h"

void manage_touched_extreme(sprite_list *s_list, game_stat *stat)
{
    sfVector2f scale;

    if (s_list->size_ratio > stat->size) {
        s_list->boosted += 2;
        go_random_dir(s_list);
        s_list->size_ratio = s_list->size_ratio - 0.5;
        scale = update_scale(s_list);
        s_list->vect.x += 16;
        s_list->vect.y += 16;
        s_list->scale = scale;
    } else if (s_list->size_ratio == stat->size) {
        s_list->size_ratio = 0;
        stat->nb_dead = stat->nb_dead + 1;
        scale = update_scale(s_list);
        s_list->scale = scale;
        update_text_remain(stat);
    }
    sfSprite_setScale(s_list->sprite, (s_list)->scale);
}

static void decrease_boost(sprite_list *s_list)
{
    if (s_list->boosted > 0)
        s_list->boosted = s_list->boosted - 1;
}

static void random_dodge(sprite_list *s_list)
{
    int dir = rand() % 20;

    update_vect(s_list);
    if (dir < 3)
        go_random_dir(s_list);
}

void move_vec_xtreme(sprite_list *s_list)
{
    while (s_list) {
        random_dodge(s_list);
        if (s_list->vect.x > 960 + 32 * (s_list->size_ratio)) {
            decrease_boost(s_list);
            (s_list->vect.x = -32 * s_list->size_ratio);
        }
        if (s_list->vect.x < 0 - 32 * s_list->size_ratio) {
            decrease_boost(s_list);
            (s_list->vect.x = 960 + 32 * s_list->size_ratio);
        }
        if (s_list->vect.y > 540 + 32 * s_list->size_ratio) {
            decrease_boost(s_list);
            (s_list->vect.y = -32 * s_list->size_ratio);
        }
        if (s_list->vect.y < -32 * s_list->size_ratio) {
            decrease_boost(s_list);
            (s_list->vect.y = 540 + 32 * s_list->size_ratio);
        }
        (s_list) = (s_list)->next;
    }
}

static game_stat *init_extreme_game(int wave, my_window_t *screen)
{
    game_stat *temp = malloc(sizeof(game_stat));

    temp->mode = 'x';
    temp->nb_ghost = 9 + 2 * wave;
    temp->nb_click = 0;
    temp->nb_touch = 0;
    temp->size = 1;
    temp->max_speed = 30 + 5 * wave;
    temp->nb_dead = 0;
    temp->window = screen;
    return temp;
}

int extreme(sfRenderWindow *window, int wave, my_window_t *screen)
{
    sfClock *clock = sfClock_create();
    sprite_list *s_list = NULL;
    game_stat *stat = init_extreme_game(wave, screen);

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
        restart(window, 'x', wave, screen);
    } else
        free_all(&s_list, stat);
    return 0;
}
