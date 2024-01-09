/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Contain all the prototypes of all the function exposed by my libmy.a
*/

#ifndef MY_

    #define MY_

    #include <sys/stat.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>

typedef struct game_t{
    int nb_x;
    int nb_o;
    int nb_p;
    int nb_line;
    int nb_found;
    int nb_box_found;
    int nb_blocked;
    int p_x;
    int p_y;
    int *box_x;
    int *box_y;
    int *slot_x;
    int *slot_y;
    int len_line_max;
} game_t;

typedef struct player_s{
    int x;
    int y;
    char under_me;
} player_t;

void search_player_and_slot(player_t *player, char **map, game_t *stat);
void down(player_t *player, char **temp, game_t *stat);
void right(player_t *player, char **temp, game_t *stat);
void space(char **map, game_t *stat, player_t *player);
void loop_box(game_t *stat, char **map);
int my_putstr(char const *str);
void left(player_t *player, char **temp, game_t *stat);
void go_top(player_t *player, char **temp, game_t *stat);
void change_under_me(player_t *player, game_t *stat);
int check_end(game_t *stat, char **map);
player_t *init_player(void);
game_t *init_game(void);
int my_soko(char *map);
int my_strlen(char const *);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *str);

#endif /* MY_ */
