/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** collision.c
*/

#include "../include/my.h"

static int point_in_circle(float x, float y, sfVector2f center, int radius)
{
    if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
        return 1;
    return 0;
}

static int is_intersecting_circles(sfRectangleShape *r2, sfCircleShape *c1)
{
    sfVector2f pos = sfRectangleShape_getPosition(r2);
    sfVector2f center = sfCircleShape_getPosition(c1);
    int radius = sfCircleShape_getRadius(c1);

    center.x = center.x + radius;
    center.y = center.y + radius;
    if (point_in_circle(pos.x - 10, pos.y - 10, center, radius))
        return 1;
    if (point_in_circle(pos.x + 10, pos.y - 10, center, radius))
        return 1;
    if (point_in_circle(pos.x - 10, pos.y + 10, center, radius))
        return 1;
    if (point_in_circle(pos.x + 10, pos.y + 10, center, radius))
        return 1;
    return 0;
}

void change_to_flag(plane_t **current, game_t *game)
{
    game->arrived = game->arrived + 1;
    sfRectangleShape_setOutlineColor((*current)->square, sfGreen);
    sfSprite_setRotation((*current)->sprite, 0);
    sfSprite_setTexture((*current)->sprite, game->flag_text, 0);
}

void check_in_tower(plane_t *current, tower_t *tower)
{
    if (current->reached != 0)
        return;
    while (tower && !is_intersecting_circles(current->square, tower->circle)) {
        tower = tower->next;
    }
    if (tower == NULL) {
        sfRectangleShape_setOutlineColor(current->square, sfBlack);
        current->protected = 0;
    } else {
        sfRectangleShape_setOutlineColor(current->square, sfRed);
        current->protected = 1;
    }
}

static int collision_air(sfRectangleShape *c1, sfRectangleShape *c2)
{
    sfVector2f pos1 = sfRectangleShape_getPosition(c1);
    sfVector2f pos2 = sfRectangleShape_getPosition(c2);

    if (pos1.x - 10 + 21 >= pos2.x - 10 &&
        pos1.x - 10 <= pos2.x - 10 + 21 &&
        pos1.y - 10 + 21 >= pos2.y - 10 &&
        pos1.y - 10 <= pos2.y - 10 + 21) {
        return 1;
    }
    return 0;
}

int check_air_collision(plane_t **actual)
{
    plane_t *temp = (*actual)->next;
    plane_t *current = (*actual);

    if (current->protected || current->reached != 0)
        return 0;
    while (temp) {
        if (!temp->protected && temp->reached == 0 && temp->in_air
            && temp->id != current->id
            && collision_air(current->square, temp->square)) {
            temp->collided = 1;
            current->collided = 1;
        }
        temp = temp->next;
    }
    return 0;
}
