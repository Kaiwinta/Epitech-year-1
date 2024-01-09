/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** run.c
*/

#include "../include/my.h"

void run_end(game_t *game)
{
    sfEvent event;
    static int first = 1;

    if (first == 1) {
        update_text_end(game);
    }
    first = 0;
    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_pollEvent(game->window, &event))
        analyse_events_end(&game, &event);
    display_end(game);
    sfRenderWindow_display(game->window);
}

void run_menu(game_t *game)
{
    sfEvent event;

    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_pollEvent(game->window, &event))
        analyse_events_menu(&game, &event);
    display_menu(game);
    sfRenderWindow_display(game->window);
}

void run_game(game_t *game)
{
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;

    print_framerate(game);
    if (seconds > 0.05 * game->accel) {
        move_vec(&game->head, game->time, &game->tower, game);
        update_timer(game->game_text, game);
        sfClock_restart(game->clock);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_pollEvent(game->window, &event))
        analyse_events(&game, &event);
    display_all(game, game->head, game->tower);
    sfRenderWindow_display(game->window);
}

void print_framerate(game_t *game)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        game->total_time = game->total_time + 1;
        game->total_fps = game->total_fps + fps;
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
}
