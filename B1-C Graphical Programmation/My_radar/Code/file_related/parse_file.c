/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** parse_file.c
*/

#include "../include/my.h"

static int check_error(char *line, int *index, int found_one)
{
    if ((line[*index] == '\n' || line[*index] == ' ') && !found_one)
        return -1;
    if (line[*index] < '0' || line[*index] > '9')
        return -1;
    return 0;
}

static int my_get_number(char *line, int *index)
{
    int nb = 0;
    int found_one = 0;

    if (!line[*index])
        return -1;
    while (line[*index]){
        if (line[*index] >= '0' && line[*index] <= '9') {
            found_one = 1;
            nb = nb * 10 + line[*index] - '0';
        }
        if ((line[*index] == '\n' || line[*index] == ' ') && found_one) {
            *index = *index + 1;
            return nb;
        }
        if (check_error(line, index, found_one) == -1)
            return -1;
        *index = *index + 1;
    }
    return nb;
}

static void compute_speed(plane_t *plane, int speed)
{
    float delta_x = plane->dest.x - plane->pos.x;
    float delta_y = plane->dest.y - plane->pos.y;
    float theta = atan2(delta_y, delta_x);

    plane->x_vel = speed * cos(theta);
    plane->y_vel = speed * sin(theta);
    plane->angle = atan2(plane->y_vel, plane->x_vel) * (180 / M_PI);
    sfSprite_setRotation(plane->sprite, plane->angle);
    plane->in_air = 0;
    plane->protected = 0;
    plane->collided = 0;
    plane->reached = 0;
}

static void init_sprite(plane_t *plane)
{
    sfRectangleShape* square = sfRectangleShape_create();
    sfVector2f size = {20, 20};
    static int id = 0;

    id++;
    plane->sprite = sfSprite_create();
    sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(plane->sprite, (plane)->pos);
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOrigin(square, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(square, sfTransparent);
    sfRectangleShape_setOutlineThickness(square, 2);
    sfRectangleShape_setOutlineColor(square, sfBlack);
    sfRectangleShape_setPosition(square, plane->pos);
    plane->id = id;
    plane->square = square;
}

static int read_aircraft(plane_t **plane, char *line)
{
    plane_t *temp = malloc(sizeof(plane_t));
    int text_i = 0;
    int speed;

    temp->pos = (sfVector2f){my_get_number(line, &text_i),
        my_get_number(line, &text_i)};
    temp->dest = (sfVector2f){my_get_number(line, &text_i),
        my_get_number(line, &text_i)};
    speed = my_get_number(line, &text_i);
    temp->delay = my_get_number(line, &text_i);
    if (temp->pos.x < 0 || temp->pos.y < 0 || temp->dest.x < 0 ||
        temp->dest.y < 0 || speed < 50 || temp->delay == -1 || line[text_i]
        || temp->pos.x > 1920 || temp->pos.y > 1080 || temp->dest.x > 1920 ||
        temp->dest.y > 1080 || speed > 160)
        return -1;
    temp->next = (*plane);
    (*plane) = temp;
    init_sprite(temp);
    compute_speed(temp, speed);
    return 0;
}

static void init_circle(tower_t *temp)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, temp->pos);
    sfCircleShape_setRadius(circle, temp->radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    temp->circle = circle;
    sfCircleShape_setOutlineThickness(circle, 1);
    temp->sprite = sfSprite_create();
    sfSprite_setOrigin(temp->sprite, (sfVector2f){20, 20});
    sfSprite_setPosition(temp->sprite, (sfVector2f){(temp)->pos.x
        + temp->radius, (temp)->pos.y + temp->radius});
}

static int read_tower(tower_t **tower, char *line)
{
    sfVector2f pos;
    tower_t *temp = malloc(sizeof(tower_t));
    int radius = 0;
    int index = 0;

    pos.x = my_get_number(line, &index);
    pos.y = my_get_number(line, &index);
    radius = my_get_number(line, &index);
    if (pos.x < 0 || pos.y < 0 || radius < 3 || line[index]
        || radius > 35 || pos.x > 1920 || pos.y > 1080)
        return -1;
    pos.x = pos.x - radius - 20;
    pos.y = pos.y - radius - 20;
    temp->pos = pos;
    temp->radius = (int)(1920 / 100 * radius / 2);
    init_circle(temp);
    temp->next = (*tower);
    (*tower) = temp;
    return 0;
}

static int analyse_line(char *line, plane_t **plane,
    int *is_aircraft, tower_t **tower)
{
    if (line[0] == '\0' && *is_aircraft) {
        *is_aircraft = 0;
        return 0;
    }
    if (line[0] == '\0' && !*is_aircraft) {
        return -1;
    }
    if (*is_aircraft)
        return read_aircraft(plane, line);
    return read_tower(tower, line);
}

int parse_file(char *param)
{
    plane_t *plane = NULL;
    tower_t *tower = NULL;
    char **word = my_str_to_word_array(param);
    int is_aircraft = 1;

    for (int i = 0; word[i]; i++) {
        if (analyse_line(word[i], &plane, &is_aircraft, &tower) == -1) {
            my_putstr_err("The given file dont respect the format\n");
            return 84;
        }
        free(word[i]);
    }
    free(word);
    init_game(plane, tower);
    return 0;
}
