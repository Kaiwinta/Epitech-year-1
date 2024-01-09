/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_game.c
*/

#include "../include/my.h"

static void boss_fight(sfRenderWindow *window, char mode, my_window_t *screen)
{
    if (mode == 'e') {
        boss_easy(window, screen);
        end_screen(window, 3, screen);
    }
    if (mode == 'n') {
        boss_normal(window, screen);
        end_screen(window, 3, screen);
    }
    if (mode == 'h') {
        boss_hard(window, screen);
        end_screen(window, 3, screen);
    }
    if (mode == 'x') {
        end_screen(window, 3, screen);
        boss_extreme(window, screen);
    }
}

static void another_wave(sfRenderWindow *window,
    int wave, char mode, my_window_t *screen)
{
    if (mode == 'e')
        easy(window, wave + 1, screen);
    if (mode == 'n')
        normal(window, wave + 1, screen);
    if (mode == 'h')
        hard(window, wave + 1, screen);
    if (mode == 'x')
        extreme(window, wave + 1, screen);
}

void restart(sfRenderWindow *window, char mode, int wave, my_window_t *screen)
{
    loading_screen(window, wave + 1, screen);
    if (wave + 1 == 2) {
        boss_fight(window, mode, screen);
    } else
        another_wave(window, wave, mode, screen);
}

static void display_all(sfRenderWindow *window,
    game_stat *stat, sprite_list *s_list)
{
    display_bg(window, stat->window);
    display_ghost(window, s_list);
    display_all_text(window, stat->window->t_list, stat->window->font);
}

void run_game(sfRenderWindow *window, sfClock *clock,
    sprite_list *s_list, game_stat *stat)
{
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (sfSound_getStatus(stat->window->music_sound) != sfPlaying)
        sfSound_play(stat->window->music_sound);
    if (seconds > 0.1 && stat->mode != 'x')
        move_vec(s_list);
    if (seconds > 0.1 && stat->mode == 'x')
        move_vec_xtreme(s_list);
    if (seconds > 0.1) {
        move_rec(s_list);
        sfClock_restart(clock);
    }
    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_pollEvent(window, &event))
        analyse_events(window, &event, s_list, stat);
    display_all(window, stat, s_list);
    sfRenderWindow_display(window);
}
