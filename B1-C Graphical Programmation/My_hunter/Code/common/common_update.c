/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_update.c
*/

#include "../include/my.h"

sfVector2f update_scale(sprite_list *s_list)
{
    sfVector2f scale;

    scale.x = s_list->size_ratio;
    scale.y = s_list->size_ratio;
    return scale;
}

void update_rotation(sprite_list *s_list)
{
    sfTexture_destroy(s_list->texture);
    if (s_list->x_vel < 0) {
        s_list->texture = sfTexture_createFromFile(
            "bin/AllGhost_rev.png", NULL);
    } else {
        s_list->texture = sfTexture_createFromFile(
            "bin/AllGhost.png", NULL);
    }
    sfSprite_setTexture(s_list->sprite, s_list->texture, 0);
}

void update_aim(game_stat *stat, my_window_t *screen)
{
    int nb = stat->nb_touch * 100 / stat->nb_click;

    screen->total_aim = screen->total_aim + nb;
}

void update_mode(text *t_list, char *temp)
{
    free(t_list->src_text);
    t_list->src_text = my_strdup(temp);
    sfText_setString(t_list->str, t_list->src_text);
}
