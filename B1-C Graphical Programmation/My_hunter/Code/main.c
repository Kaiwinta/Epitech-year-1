/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** main.c
*/

#include "include/my.h"

static void mouse_click_main(sfMouseButtonEvent event,
    sfRenderWindow *window, my_window_t *screen)
{
    if (event.x >= 400 && event.x <= 543 && event.y >= 280 && event.y < 315) {
        update_mode(screen->load_list, "Mode: Easy");
        loading_screen(window, 0, screen);
        easy(window, 0, screen);
    }
    if (event.x >= 400 && event.x <= 543 && event.y >= 320 && event.y < 355) {
        update_mode(screen->load_list, "Mode: Normal");
        loading_screen(window, 0, screen);
        normal(window, 0, screen);
    }
    if (event.x >= 400 && event.x <= 543 && event.y >= 360 && event.y < 395) {
        update_mode(screen->load_list, "Mode: Hard");
        loading_screen(window, 0, screen);
        hard(window, 0, screen);
    }
    if (event.x >= 400 && event.x <= 543 && event.y >= 400 && event.y < 435) {
        update_mode(screen->load_list, "Mode: Osu Player");
        loading_screen(window, 0, screen);
        extreme(window, 0, screen);
    }
}

static void main_event(sfRenderWindow *window,
    sfEvent *event, my_window_t *screen)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtMouseButtonPressed) {
        mouse_click_main(event->mouseButton, window, screen);
    }
}

void add_in_text_list(text **t_list, int x, int y, char *word)
{
    sfText *obj_text = sfText_create();
    text *temp = malloc(sizeof(text));

    temp->x = x;
    temp->y = y;
    temp->src_text = my_strdup(word);
    sfText_setString(obj_text, word);
    sfText_setCharacterSize(obj_text, 30);
    sfText_setPosition(obj_text, (sfVector2f){x, y});
    sfText_setOutlineThickness(obj_text, 1);
    sfText_setOutlineColor(obj_text, sfWhite);
    sfText_setFillColor(obj_text, sfBlack);
    temp->str = obj_text;
    temp->next = (*t_list);
    (*t_list) = temp;
}

text *init_t_list(void)
{
    text *t_list = NULL;

    add_in_text_list(&t_list, 360, 100, "GhoSt HuNTeR");
    add_in_text_list(&t_list, 400, 230, "DifFiculTy :");
    add_in_text_list(&t_list, 400, 280, "-EaSy");
    add_in_text_list(&t_list, 400, 320, "-NorMAl"),
    add_in_text_list(&t_list, 400, 360, "-HaRd");
    add_in_text_list(&t_list, 400, 400, "-OsU PlAYeR");
    return t_list;
}

static void init_text(my_window_t *temp)
{
    text *t_list = NULL;
    text *load_list = NULL;
    text *wave = NULL;
    text *end_list = NULL;

    add_in_text_list(&t_list, 10, 60, "Wave Aim: 000");
    add_in_text_list(&t_list, 10, 10, "Ghost left: 00");
    add_in_text_list(&load_list, 200, 400, "Press a key to start the Wave");
    add_in_text_list(&load_list, 380, 200, "Mode: Easy");
    add_in_text_list(&wave, 400, 100, "Wave 1/2");
    add_in_text_list(&end_list, 400, 100, "");
    add_in_text_list(&end_list, 200, 400,
        "Press a key to go back to the menu");
    add_in_text_list(&end_list, 200, 200, "Your aim for this try was 000");
    temp->end_list = end_list;
    temp->t_list = t_list;
    temp->load_list = load_list;
    temp->wave = wave;
}

static void init_sound(my_window_t *temp)
{
    temp->shoot_sound = sfSound_create();
    temp->dead_sound = sfSound_create();
    temp->music_sound = sfSound_create();
    temp->heal_sound = sfSound_create();
    temp->dead_buffer = sfSoundBuffer_createFromFile("bin/pop.ogg");
    sfSound_setBuffer(temp->dead_sound, temp->dead_buffer);
    sfSound_setVolume(temp->dead_sound, 40);
    temp->shoot_buffer = sfSoundBuffer_createFromFile("bin/shoot.ogg");
    sfSound_setBuffer(temp->shoot_sound, temp->shoot_buffer);
    sfSound_setVolume(temp->shoot_sound, 100);
    temp->music_buffer = sfSoundBuffer_createFromFile("bin/ghost.ogg");
    sfSound_setBuffer(temp->music_sound, temp->music_buffer);
    sfSound_setVolume(temp->music_sound, 40);
    temp->heal_buffer = sfSoundBuffer_createFromFile("bin/heal.ogg");
    sfSound_setBuffer(temp->heal_sound, temp->heal_buffer);
    sfSound_setVolume(temp->heal_sound, 100);
}

my_window_t *init_window(void)
{
    my_window_t *temp = malloc(sizeof(my_window_t));
    sfTexture *texture = sfTexture_createFromFile("bin/mansion.jpeg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfFont *font = sfFont_createFromFile("bin/HelpMe.ttf");

    temp->bg_text = texture;
    temp->total_aim = 0;
    temp->is_loaded = 0;
    temp->font = font;
    init_text(temp);
    init_sound(temp);
    sfSprite_setTexture(sprite, temp->bg_text, 0);
    temp->bg_sprite = sprite;
    return temp;
}

void game(void)
{
    sfVideoMode mode = {960, 540, 32};
    sfEvent event;
    my_window_t *screen = init_window();
    sfRenderWindow *window;
    text *t_list = init_t_list();

    window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    sfSound_play(screen->music_sound);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            main_event(window, &event, screen);
        sfRenderWindow_clear(window, sfBlack);
        display_bg(window, screen);
        display_all_text(window, t_list, screen->font);
        sfRenderWindow_display(window);
    }
    free_main(t_list, screen);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        game();
        return 0;
    }
    if (ac > 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return display_help();
    if (my_strcmp(av[1], "-n") == 0)
        return flag_game('n');
    if (my_strcmp(av[1], "-s") == 0)
        return flag_game('h');
    if (my_strcmp(av[1], "-e") == 0)
        return flag_game('e');
    if (my_strcmp(av[1], "-x") == 0)
        return flag_game('x');
    my_putstr("Wrong flag: ");
    my_putstr(av[1]);
    my_putstr("\nTry with '-h' for help\n");
    return 84;
}
