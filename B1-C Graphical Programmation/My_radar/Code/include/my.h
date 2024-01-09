/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>

#ifndef MY_H
    #define MY_H

typedef struct plane_s {
    float y_vel;
    float x_vel;
    float angle;
    int delay;
    int id;
    int in_air;
    int protected;
    int collided;
    int reached;
    sfRectangleShape *square;
    sfVector2f dest;
    sfSprite *sprite;
    sfVector2f pos;
    struct plane_s *next;
} plane_t;

typedef struct tower_s {
    sfVector2f pos;
    int radius;
    sfCircleShape *circle;
    sfSprite *sprite;
    struct tower_s *next;
} tower_t;

typedef struct arrow_s {
    sfSprite *sprite1;
    sfSprite *sprite2;
    sfSprite *sprite3;
} arrow_t;

typedef struct text_s {
    sfText *str;
    char *src_text;
    int x;
    int y;
    struct text_s *next;
} text_t;

typedef struct game_s {
    int show_box;
    int show_sprite;
    float accel;
    int time;
    int total_time;
    int total_fps;
    int menu;
    int explosed;
    int arrived;
    int total;
    sfTexture *bg_text;
    sfTexture *flag_text;
    sfTexture *tow_text;
    sfTexture *plane_text;
    sfTexture *arrow_text;
    sfSprite *bg_sprite;
    sfFont *font;
    sfRenderWindow *window;
    sfClock *clock;
    text_t *game_text;
    text_t *menu_text;
    text_t *end_text;
    arrow_t *arrow;
    plane_t *head;
    tower_t *tower;
} game_t;

/*Lib*/
int my_put_nbr(int nb);
int my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strdup(char const *src);
void my_putstr_err(const char *str);
char **my_str_to_word_array(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);

/*Run*/
void run_end(game_t *game);
void run_game(game_t *game);
void run_menu(game_t *game);

/*events*/
void analyse_events(game_t **game, sfEvent *event);
void analyse_events_end(game_t **game, sfEvent *event);
void analyse_events_menu(game_t **game, sfEvent *event);

/*display*/
void display_end(game_t *game);
void display_menu(game_t *game);
void display_all(game_t *game, plane_t *planes, tower_t *tower);

/*In game update*/
void move_vec(plane_t **planes, int time, tower_t **tower, game_t *game);
void check_in_tower(plane_t *current, tower_t *tower);
int check_air_collision(plane_t **current);
void change_to_flag(plane_t **current, game_t *game);
void update_timer(text_t *text, game_t *game);
void update_text_end(game_t *game);
void print_framerate(game_t *game);

/*game start and end*/
int init_game(plane_t *planes, tower_t *tower);
void free_game(game_t *game);
int set_all_font(text_t **t_list, sfFont *font);
int free_text_list(text_t *t_list);
void add_in_text_list(text_t **t_list, int x, int y, char *word);

/*file related*/
int parse_file(char *param);
int open_file(char *filename);
int display_help(void);

#endif /* MY_H */
