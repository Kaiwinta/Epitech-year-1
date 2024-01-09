/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-titouan.pradoura
** File description:
** common_move.c
*/

#include "../include/my.h"

void go_random_dir(sprite_list *s_list)
{
    int choice = rand() % 4;

    if (choice == 0) {
        s_list->x_vel = -s_list->x_vel;
        s_list->y_vel = -s_list->y_vel;
    }
    if (choice == 1) {
        s_list->x_vel = s_list->x_vel;
        s_list->y_vel = -s_list->y_vel;
    }
    if (choice == 2) {
        s_list->x_vel = -s_list->x_vel;
        s_list->y_vel = s_list->y_vel;
    }
    if (choice == 23) {
        s_list->x_vel = s_list->x_vel;
        s_list->y_vel = s_list->y_vel;
    }
    update_rotation(s_list);
}

void update_vect(sprite_list *s_list)
{
    (s_list)->vect.x += s_list->x_vel / 2 * (s_list->boosted + 1);
    (s_list)->vect.y += s_list->y_vel / 2 * (s_list->boosted + 1);
}

void move_vec(sprite_list *s_list)
{
    while (s_list) {
        update_vect(s_list);
        if (s_list->vect.x > 960) {
            s_list->boosted = 0;
            (s_list->vect.x = -32 * s_list->size_ratio);
        }
        if (s_list->vect.x < -32 * s_list->size_ratio) {
            s_list->boosted = 0;
            s_list->vect.x = 960 + 1;
        }
        if (s_list->vect.y > 540) {
            s_list->boosted = 0;
            s_list->vect.y = -32 * (s_list->size_ratio);
        }
        if (s_list->vect.y < -32 * (s_list->size_ratio)) {
            s_list->boosted = 0;
            s_list->vect.y = 540;
        }
        (s_list) = (s_list)->next;
    }
}

void move_rec(sprite_list *s_list)
{
    while (s_list) {
        (s_list)->rect.left += 32;
        if ((s_list)->rect.left >= 128)
            (s_list)->rect.left = 0;
        (s_list) = (s_list)->next;
    }
}
