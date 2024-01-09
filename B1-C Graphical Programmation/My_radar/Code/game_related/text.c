/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** text.c
*/

#include "../include/my.h"

void add_in_text_list(text_t **t_list, int x, int y, char *word)
{
    sfText *obj_text = sfText_create();
    text_t *temp = malloc(sizeof(text_t));

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

void update_timer(text_t *text, game_t *game)
{
    static float second = 0;
    int changed = 0;

    second += 0.05;
    game->time = (int)second;
    if (text->src_text[0] != game->time / 100 + 48) {
        text->src_text[0] = game->time / 100 + 48;
        changed = 1;
    }
    if (text->src_text[1] != game->time % 100 / 10 + 48) {
        text->src_text[1] = game->time % 100 / 10 + 48;
        changed = 1;
    }
    if (text->src_text[2] != game->time % 10 + 48) {
        text->src_text[2] = game->time % 10 + 48;
        changed = 1;
    }
    if (changed)
        sfText_setString(text->str, text->src_text);
}

int set_all_font(text_t **t_list, sfFont *font)
{
    text_t *temp = *t_list;

    while (temp) {
        sfText_setFont(temp->str, font);
        temp = temp->next;
    }
}

static void update_one_end_text(text_t **text, int value)
{
    if (value / 1000 != 0)
        (*text)->src_text[0] = value / 1000 + 48;
    else
        (*text)->src_text[0] = ' ';
    if (value % 1000 / 100 != 0 || value / 1000 != 0)
        (*text)->src_text[1] = value % 1000 / 100 + 48;
    else
        (*text)->src_text[1] = ' ';
    if (value % 100 / 10 != 0 || value % 1000 / 100 != 0 || value / 1000 != 0)
        (*text)->src_text[2] = value % 100 / 10 + 48;
    else
        (*text)->src_text[2] = '0';
    if (value % 10 != 0 || value % 100 / 10 != 0 || value % 1000 / 100 != 0 ||
        value / 1000 != 0)
        (*text)->src_text[4] = value % 10 + 48;
    else
        (*text)->src_text[4] = '0';
    sfText_setString((*text)->str, (*text)->src_text);
}

static void update_fps_end_text(text_t **text, int value)
{
    if (value / 1000 != 0)
        (*text)->src_text[0] = value / 1000 + 48;
    else
        (*text)->src_text[0] = ' ';
    if (value % 1000 / 100 != 0 || value / 1000 != 0)
        (*text)->src_text[1] = value % 1000 / 100 + 48;
    else
        (*text)->src_text[1] = ' ';
    if (value % 100 / 10 != 0 || value % 1000 / 100 != 0 || value / 1000 != 0)
        (*text)->src_text[2] = value % 100 / 10 + 48;
    else
        (*text)->src_text[2] = '0';
    if (value % 10 != 0 || value % 100 / 10 != 0 || value % 1000 / 100 != 0 ||
        value / 1000 != 0)
        (*text)->src_text[3] = value % 10 + 48;
    else
        (*text)->src_text[3] = '0';
    sfText_setString((*text)->str, (*text)->src_text);
}

void update_text_end(game_t *game)
{
    int crashed = (int)(10 * (float)game->explosed * 100 / (float)game->total);
    int landed = 100 * 10 - crashed;
    int average = game->total_fps / game->total_time;

    update_one_end_text(&game->end_text->next, landed);
    update_one_end_text(&game->end_text->next->next, crashed);
    update_fps_end_text(&game->end_text, average);
    sfText_setString(game->end_text->str, game->end_text->src_text);
}
