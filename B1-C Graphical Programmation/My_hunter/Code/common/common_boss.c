/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_boss.c
*/

#include "../include/my.h"

static void init_boss_speed(sprite_list *temp, game_stat *stat)
{
    int MAX_VALUE = stat->max_speed;

    do {
        temp->y_vel = rand() % (2 * MAX_VALUE + 1) - MAX_VALUE;
    } while (temp->y_vel > -5 && temp->y_vel < 5);
    do {
        temp->x_vel = rand() % (2 * MAX_VALUE + 1) - MAX_VALUE;
    } while (temp->x_vel > -5 && temp->x_vel < 5);
}

static int decrease_boost(sprite_list *s_list, game_stat *stat)
{
    if (s_list->boosted > 1)
        s_list->boosted = s_list->boosted - 2;
    if (s_list->size_ratio < 10) {
        sfSound_play(stat->window->heal_sound);
        s_list->size_ratio = s_list->size_ratio + 1;
        s_list->scale = update_scale(s_list);
        sfSprite_setScale(s_list->sprite, (s_list)->scale);
        update_boss_life(stat->window->t_list, s_list);
    }
    return 1;
}

static void random_dodge(sprite_list *s_list)
{
    int dir = rand() % 20;

    update_vect(s_list);
    if (dir < 1)
        go_random_dir(s_list);
}

void move_vec_boss(sprite_list *s_list, game_stat *stat)
{
    while (s_list) {
        random_dodge(s_list);
        if (s_list->vect.x > 960 + 32 * (s_list->size_ratio)) {
            decrease_boost(s_list, stat);
            (s_list->vect.x = -32 * s_list->size_ratio);
        }
        if (s_list->vect.x < 0 - 32 * s_list->size_ratio) {
            decrease_boost(s_list, stat);
            (s_list->vect.x = 960 + 32 * s_list->size_ratio);
        }
        if (s_list->vect.y > 540 + 32 * s_list->size_ratio) {
            decrease_boost(s_list, stat);
            (s_list->vect.y = -32 * s_list->size_ratio);
        }
        if (s_list->vect.y < -32 * s_list->size_ratio) {
            decrease_boost(s_list, stat);
            (s_list->vect.y = 540 + 32 * s_list->size_ratio);
        }
        (s_list) = (s_list)->next;
    }
}

void add_boss(sprite_list **s_list, game_stat *stat)
{
    sprite_list *temp = malloc(sizeof(sprite_list));
    sfIntRect rect = init_rect();
    int randscale = 10;
    sfVector2f scale = {randscale, randscale};
    sfVector2f vect = {960 / 2, 540 / 2};
    sfTexture *texture = sfTexture_createFromFile("bin/AllGhost.png", NULL);

    temp->sprite = sfSprite_create();
    temp->scale = scale;
    temp->size_ratio = randscale;
    temp->boosted = 0;
    temp->next = (*s_list);
    temp->rect = rect;
    temp->vect = vect;
    temp->texture = texture;
    init_boss_speed(temp, stat);
    update_rotation(temp);
    init_sprite(temp);
    (*s_list) = temp;
}

void run_boss_game(sfRenderWindow *window, sfClock *clock,
    sprite_list *s_list, game_stat *stat)
{
    sfEvent event;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        move_vec_boss(s_list, stat);
        move_rec(s_list);
        sfClock_restart(clock);
    }
    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_pollEvent(window, &event))
        analyse_boss_events(window, &event, s_list, stat);
    display_bg(window, stat->window);
    display_ghost(window, s_list);
    display_all_text(window, stat->window->t_list, stat->window->font);
    sfRenderWindow_display(window);
}
