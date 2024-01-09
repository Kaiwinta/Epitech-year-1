/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** easy_boss.c
*/

#include "../include/my.h"

void manage_boss_touched_easy(sprite_list *s_list, game_stat *stat)
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
    } else if (s_list->size_ratio <= stat->size){
        s_list->size_ratio = 0;
        stat->nb_dead = stat->nb_dead + 1;
        scale = update_scale(s_list);
        s_list->scale = scale;
        sfSound_play(stat->window->dead_sound);
    }
    sfSprite_setScale(s_list->sprite, (s_list)->scale);
}

static game_stat *init_boss_easy_game(my_window_t *screen)
{
    game_stat *temp = malloc(sizeof(game_stat));

    temp->mode = 'e';
    temp->nb_ghost = 1;
    temp->nb_click = 0;
    temp->nb_touch = 0;
    temp->size = 1;
    temp->max_speed = 20;
    temp->nb_dead = 0;
    temp->window = screen;
    return temp;
}

int boss_easy(sfRenderWindow *window, my_window_t *screen)
{
    sfClock *clock = sfClock_create();
    sprite_list *s_list = NULL;
    sprite_list *health = NULL;
    game_stat *stat = init_boss_easy_game(screen);

    srand((unsigned int)time(NULL));
    add_boss(&s_list, stat);
    update_text_aim(stat);
    update_boss_life(stat->window->t_list, s_list);
    while (sfRenderWindow_isOpen(window) && stat->nb_dead != stat->nb_ghost) {
        run_boss_game(window, clock, s_list, stat);
    }
    update_aim(stat, screen);
    sfClock_destroy(clock);
    free_all(&s_list, stat);
    return 0;
}
