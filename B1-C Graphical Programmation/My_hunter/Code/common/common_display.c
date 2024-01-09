/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_display.c
*/

#include "../include/my.h"

void display_ghost(sfRenderWindow *window, sprite_list *s_list)
{
    while (s_list) {
        sfSprite_setPosition(s_list->sprite, (s_list)->vect);
        sfSprite_setTextureRect(s_list->sprite, (s_list)->rect);
        sfRenderWindow_drawSprite(window, s_list->sprite, 0);
        (s_list) = (s_list)->next;
    }
}

void display_bg(sfRenderWindow *window, my_window_t *screen)
{
    sfRenderWindow_drawSprite(window, screen->bg_sprite, 0);
}

int display_help(void)
{
    char *temp;
    int fd = 0;

    fd = open("help.txt", O_RDONLY);
    temp = malloc(sizeof(char) * (1507));
    read(fd, temp, 1507);
    temp[1507] = '\0';
    my_putstr(temp);
    return 0;
}

void display_all_text(sfRenderWindow *window,
    text *t_list, sfFont *font)
{
    while (t_list) {
        sfText_setFont(t_list->str, font);
        sfRenderWindow_drawText(window, t_list->str, NULL);
        t_list = t_list->next;
    }
}
