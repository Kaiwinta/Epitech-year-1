/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_function.c
*/

#include "../include/my.h"

sfIntRect init_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = (rand() % 128) / 32 * 32;
    rect.width = 32;
    rect.height = 32;
    return rect;
}

static void init_speed(sprite_list *temp, game_stat *stat)
{
    int MAX_VALUE = stat->max_speed;

    do {
        temp->y_vel = rand() % (2 * MAX_VALUE + 1) - MAX_VALUE;
    } while (temp->y_vel > -3 && temp->y_vel < 3);
    do {
        temp->x_vel = rand() % (2 * MAX_VALUE + 1) - MAX_VALUE;
    } while (temp->x_vel > -3 && temp->x_vel < 3);
}

void init_sprite(sprite_list *temp)
{
    sfSprite_setTexture(temp->sprite, temp->texture, 0);
    sfSprite_setPosition(temp->sprite, (temp)->vect);
    sfSprite_setTextureRect(temp->sprite, (temp)->rect);
    sfSprite_setScale(temp->sprite, (temp)->scale);
}

void add_in_list(sprite_list **s_list, game_stat *stat)
{
    sprite_list *temp = malloc(sizeof(sprite_list));
    sfIntRect rect = init_rect();
    int randscale = rand() % (8 + 1 - stat->size) + stat->size;
    sfVector2f scale = {randscale, randscale};
    sfVector2f vect = {rand() % 960 - 32 * randscale,
        rand() % 540 - 32 * randscale};
    sfTexture *texture = sfTexture_createFromFile("bin/AllGhost.png", NULL);

    temp->sprite = sfSprite_create();
    temp->scale = scale;
    temp->size_ratio = randscale;
    temp->boosted = 0;
    temp->next = (*s_list);
    temp->rect = rect;
    temp->vect = vect;
    temp->texture = texture;
    init_speed(temp, stat);
    update_rotation(temp);
    init_sprite(temp);
    (*s_list) = temp;
}

int free_all(sprite_list **s_list, game_stat *stat)
{
    sprite_list *temp = (*s_list);

    free(stat);
    if (! temp) {
        return 0;
    }
    while ((*s_list) != NULL) {
        temp = (*s_list);
        (*s_list) = (*s_list)->next;
        sfTexture_destroy(temp->texture);
        sfSprite_destroy(temp->sprite);
        free(temp);
    }
}
