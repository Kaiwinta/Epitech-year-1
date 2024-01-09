/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_text_update.c
*/

#include "../include/my.h"

static void update_text_to_boss(text *t_list)
{
    char *temp = my_strdup("Boss life: 00");

    free(t_list->src_text);
    t_list->src_text = temp;
    sfText_setString(t_list->str, t_list->src_text);
}

static void reset_text(text *t_list)
{
    char *temp2 = my_strdup("Ghost left: 00");

    free(t_list->src_text);
    t_list->src_text = temp2;
    sfText_setString(t_list->str, t_list->src_text);
}

void update_text_aim(game_stat *stat)
{
    int len = my_strlen(stat->window->t_list->next->src_text);

    if (stat->nb_click == 0) {
        stat->window->t_list->next->src_text[len - 1] = '0';
        stat->window->t_list->next->src_text[len - 2] = '0';
        stat->window->t_list->next->src_text[len - 3] = '0';
    } else {
        stat->window->t_list->next->src_text[len - 1] =
            ((stat->nb_touch * 100) / stat->nb_click) % 10 + 48;
        stat->window->t_list->next->src_text[len - 2] =
            ((stat->nb_touch * 100) / stat->nb_click) % 100 / 10 + 48;
        stat->window->t_list->next->src_text[len - 3] =
            ((stat->nb_touch * 100) / stat->nb_click) / 100 + 48;
    }
    sfText_setString(stat->window->t_list->next->str,
        stat->window->t_list->next->src_text);
}

void update_text_remain(game_stat *stat)
{
    int len = my_strlen(stat->window->t_list->src_text);

    stat->window->t_list->src_text[len - 1] =
        (stat->nb_ghost - stat->nb_dead) % 10 + 48;
    stat->window->t_list->src_text[len - 2] =
        (stat->nb_ghost - stat->nb_dead) / 10 + 48;
    sfText_setString(stat->window->t_list->str,
        stat->window->t_list->src_text);
}

void update_text_wave(my_window_t *window, int wave)
{
    int len = my_strlen(window->wave->src_text);

    if (wave + 1 == 3) {
        free(window->wave->src_text);
        window->wave->src_text = my_strdup("Boss Wave");
        sfText_setPosition(window->wave->str, (sfVector2f){375, 100});
        update_text_to_boss(window->t_list);
    } else {
        if (window->wave->src_text[0] == 'B') {
            free(window->wave->src_text);
            window->wave->src_text = my_strdup("Wave 1/2");
            sfText_setPosition(window->wave->str, (sfVector2f){400, 100});
            len = my_strlen(window->wave->src_text);
            window->wave->src_text[len - 3] = wave + 49;
            reset_text(window->t_list);
        } else
            window->wave->src_text[len - 3] = wave + 49;
    }
    sfText_setString(window->wave->str, window->wave->src_text);
}

void update_boss_life(text *t_list, sprite_list *s_list)
{
    int len = my_strlen(t_list->src_text);

    t_list->src_text[len - 1] = s_list->size_ratio % 10 + 48;
    t_list->src_text[len - 2] = s_list->size_ratio / 10 + 48;
    sfText_setString(t_list->str, t_list->src_text);
}

void update_all_text(game_stat *stat)
{
    update_text_aim(stat);
    update_text_remain(stat);
}
