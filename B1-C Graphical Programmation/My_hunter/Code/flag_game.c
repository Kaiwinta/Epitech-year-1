/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** flag_game.c
*/

#include "include/my.h"

static void choose_gamemode(char type, my_window_t *screen,
    sfRenderWindow *window)
{
    if (type == 'e') {
        add_in_text_list(&(screen->load_list), 380, 200, "Mode: Easy");
        loading_screen(window, 0, screen);
        easy(window, 0, screen);
    }
    if (type == 'n') {
        add_in_text_list(&(screen->load_list), 360, 200, "Mode: Normal");
        loading_screen(window, 0, screen);
        normal(window, 0, screen);
    }
    if (type == 'h') {
        add_in_text_list(&(screen->load_list), 380, 200, "Mode: Hard");
        loading_screen(window, 0, screen);
        hard(window, 0, screen);
    }
    if (type == 'x') {
        add_in_text_list(&(screen->load_list), 350, 200, "Mode: Osu Player");
        loading_screen(window, 0, screen);
        extreme(window, 0, screen);
    }
}

int flag_game(char type)
{
    sfVideoMode mode = {960, 540, 32};
    sfEvent event;
    my_window_t *screen = init_window();
    sfRenderWindow *window;
    text *t_list = init_t_list();

    update_mode(screen->end_list->next, "Press a key to quit");
    window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    sfSound_play(screen->music_sound);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(window, 60);
    choose_gamemode(type, screen, window);
    free_main(t_list, screen);
    sfRenderWindow_destroy(window);
    return 0;
}
