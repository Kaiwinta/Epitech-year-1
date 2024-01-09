/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** game.c
*/

#include "../include/my.h"

static void delete_single_aircraft(plane_t *current,
    plane_t *prev, plane_t **planes)
{
    plane_t *temp = current->next;

    if (prev == NULL)
        (*planes) = temp;
    else
        prev->next = temp;
    sfRectangleShape_destroy(current->square);
    sfSprite_destroy(current->sprite);
    free(current);
}

static int destination_reached(plane_t *current)
{
    return (current->pos.x >= current->dest.x - 10 &&
            current->pos.x <= current->dest.x + 10 &&
            current->pos.y >= current->dest.y - 10 &&
            current->pos.y <= current->dest.y + 10);
}

static void move_single_plane(plane_t **current, plane_t *prev,
    plane_t **planes, game_t *game)
{
    if ((*current)->collided) {
        game->explosed = game->explosed + 1;
        delete_single_aircraft(*current, prev, planes);
        (*current) = NULL;
        return;
    }
    if ((*current)->reached == 0 && !destination_reached((*current))) {
        ((*current))->pos.x += (*current)->x_vel / 20;
        ((*current))->pos.y += (*current)->y_vel / 20;
        sfRectangleShape_setPosition((*current)->square, (*current)->pos);
    } else {
        if ((*current)->reached == 0) {
            change_to_flag(current, game);
            (*current)->reached = 1;
        }
        if ((*current)->reached >= 3) {
            delete_single_aircraft((*current), prev, planes);
            (*current) = NULL;
        }
    }
}

static void check_in_air(plane_t **planes, int time)
{
    static int old_time = 0;
    plane_t *current = (*planes);

    if (old_time == time && old_time != 0)
        return;
    old_time = time;
    while (current) {
        if (current->in_air == 0 && current->delay <= time)
            current->in_air = 1;
        if (current->reached != 0)
            current->reached += 1;
        current = current->next;
    }
}

void move_vec(plane_t **planes, int time, tower_t **tower, game_t *game)
{
    plane_t *prev = NULL;
    plane_t *current = (*planes);
    plane_t *next = NULL;

    check_in_air(planes, time);
    while (current) {
        next = current->next;
        if (current->in_air) {
            check_in_tower(current, *tower);
            check_air_collision(&current);
            move_single_plane(&current, prev, planes, game);
        }
        if (current)
            prev = current;
        if (prev)
            current = prev->next;
        else
            current = next;
    }
}

static void init_text(game_t *temp)
{
    temp->menu = 1;
    temp->game_text = NULL;
    temp->end_text = NULL;
    temp->menu_text = NULL;
    add_in_text_list(&temp->game_text, 1750, 20, "Timer : ");
    add_in_text_list(&temp->game_text, 1830, 20, "000");
    add_in_text_list(&temp->menu_text, 910, 200, "My Radar");
    add_in_text_list(&temp->menu_text, 850, 500, "Press <space> to start");
    add_in_text_list(&temp->end_text, 860, 200, "End of the Simulation");
    add_in_text_list(&temp->end_text, 830, 400, "Planes Crashed:");
    add_in_text_list(&temp->end_text, 830, 500, "Planes Landed:");
    add_in_text_list(&temp->end_text, 830, 600, "Average FPS:");
    add_in_text_list(&temp->end_text, 850, 750, "Press <space> to quit");
    add_in_text_list(&temp->end_text, 1050, 400, "000.0%");
    add_in_text_list(&temp->end_text, 1050, 500, "000.0%");
    add_in_text_list(&temp->end_text, 1050, 600, "0000 FPS");
    set_all_font(&temp->game_text, temp->font);
    set_all_font(&temp->end_text, temp->font);
    set_all_font(&temp->menu_text, temp->font);
}

static void set_all_texture(plane_t *head, tower_t *tower, game_t *game)
{
    sfFont *font = sfFont_createFromFile("bin/Oswald.ttf");

    game->bg_text = sfTexture_createFromFile("bin/map.jpg", NULL);
    game->flag_text = sfTexture_createFromFile("bin/flag.png", NULL);
    game->tow_text = sfTexture_createFromFile("bin/tower.png", NULL);
    game->plane_text = sfTexture_createFromFile("bin/plane.png", NULL);
    game->bg_sprite = sfSprite_create();
    while (head) {
        sfSprite_setTexture(head->sprite, game->plane_text, 0);
        head = head->next;
    }
    while (tower) {
        sfSprite_setTexture(tower->sprite, game->tow_text, 0);
        tower = tower->next;
    }
    game->font = font;
    game->show_box = 1;
    game->show_sprite = 1;
    game->accel = 1;
    game->total = game->head->id;
}

static void set_arrow(game_t *game)
{
    arrow_t *temp = malloc(sizeof(arrow_t));

    game->arrow_text = sfTexture_createFromFile("bin/arrow.png", NULL);
    temp->sprite1 = sfSprite_create();
    sfSprite_setTexture(temp->sprite1, game->arrow_text, 0);
    sfSprite_setPosition(temp->sprite1, (sfVector2f){20, 20});
    temp->sprite2 = sfSprite_create();
    sfSprite_setTexture(temp->sprite2, game->arrow_text, 0);
    sfSprite_setPosition(temp->sprite2, (sfVector2f){45, 20});
    temp->sprite3 = sfSprite_create();
    sfSprite_setTexture(temp->sprite3, game->arrow_text, 0);
    sfSprite_setPosition(temp->sprite3, (sfVector2f){70, 20});
    game->arrow = temp;
}

static game_t *init_gamestat(sfVideoMode mode, plane_t *planes, tower_t *tower)
{
    game_t *temp = malloc(sizeof(game_t));
    sfClock *clock = sfClock_create();

    temp->window = sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
    sfRenderWindow_setPosition(temp->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(temp->window, 145);
    temp->time = 0;
    temp->total_time = 0;
    temp->explosed = 0;
    temp->arrived = 0;
    temp->total_fps = 0;
    temp->clock = clock;
    temp->tower = tower;
    temp->head = planes;
    set_arrow(temp);
    set_all_texture(temp->head, temp->tower, temp);
    sfSprite_setTexture(temp->bg_sprite, temp->bg_text, 0);
    init_text(temp);
    return temp;
}

int init_game(plane_t *planes, tower_t *tower)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = init_gamestat(mode, planes, tower);

    while (sfRenderWindow_isOpen(game->window) && game->menu == 1)
        run_menu(game);
    while (sfRenderWindow_isOpen(game->window) && game->head)
        run_game(game);
    while (sfRenderWindow_isOpen(game->window))
        run_end(game);
    free_game(game);
    return 0;
}
