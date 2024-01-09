/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_loading.c
*/

#include "../include/my.h"

static game_stat *init_loading_game(int wave, my_window_t *screen)
{
    game_stat *temp = malloc(sizeof(game_stat));

    temp->mode = 'l';
    temp->nb_ghost = 2;
    temp->nb_click = 0;
    temp->nb_touch = 0;
    temp->size = 5;
    temp->max_speed = 20 + 2 * wave;
    temp->nb_dead = 0;
    temp->window = screen;
    return temp;
}

static void main_event(sfRenderWindow *window,
    sfEvent *event, my_window_t *screen)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        screen->is_loaded = 1;
    }
}

static void loop_loading(sfRenderWindow *window, sfClock *clock,
    sprite_list *s_list, game_stat *stat)
{
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    sfRenderWindow_clear(window, sfBlack);
    if (seconds > 0.1) {
        move_rec(s_list);
        sfClock_restart(clock);
    }
    while (sfRenderWindow_pollEvent(window, &event))
        main_event(window, &event, stat->window);
    display_bg(window, stat->window);
    display_ghost(window, s_list);
    display_all_text(window, stat->window->load_list, stat->window->font);
    display_all_text(window, stat->window->wave, stat->window->font);
    sfRenderWindow_display(window);
}

static void modify_pos(sprite_list *s_list)
{
    s_list->vect.x = 70;
    s_list->vect.y = 70;
    s_list->next->vect.x = 670;
    s_list->next->vect.y = 370;
}

void loading_screen(sfRenderWindow *window, int wave, my_window_t *screen)
{
    sfClock *clock = sfClock_create();
    sprite_list *s_list = NULL;
    text *t_list = NULL;
    game_stat *stat = init_loading_game(wave, screen);

    for (int i = 0; i < stat->nb_ghost; i++) {
        add_in_list(&s_list, stat);
    }
    modify_pos(s_list);
    update_text_wave(screen, wave);
    while (sfRenderWindow_isOpen(window) && screen->is_loaded == 0) {
        loop_loading(window, clock, s_list, stat);
    }
    screen->is_loaded = 0;
    sfClock_destroy(clock);
    free_all(&s_list, stat);
}
