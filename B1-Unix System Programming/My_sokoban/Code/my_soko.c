/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-titouan.pradoura
** File description:
** my_soko.c
*/

#include "include/my.h"

static void free_all(char **map)
{
    int i = 0;

    while (map[i]) {
        free(map[i]);
        i++;
    }
    free(map);
}

static void move_p(char **temp, player_t *player)
{
    temp[player->y][player->x] = 'P';
}

static void check_key(player_t *player, int *key, char **temp, game_t *stat)
{
    *key = getch();
    temp[player->y][player->x] = player->under_me;
    if (*key == 32)
        space(temp, stat, player);
    if (*key == KEY_LEFT)
        left(player, temp, stat);
    if (*key == KEY_RIGHT)
        right(player, temp, stat);
    if (*key == KEY_UP)
        go_top(player, temp, stat);
    if (*key == KEY_DOWN)
        down(player, temp, stat);
    change_under_me(player, stat);
    move_p(temp, player);
}

static void display_game(char **temp, game_t *stat)
{
    int i = 0;
    char *text = "Please resize";

    clear();
    if (stat->nb_line > LINES || stat->len_line_max > COLS) {
        mvprintw(LINES / 2, COLS / 2 - my_strlen(text) / 2, text);
        refresh();
    } else {
        while (temp[i]) {
            mvprintw(i, 0, temp[i]);
            i++;
        }
    }
}

static void check_char(char temp, game_t *stat)
{
    switch (temp) {
        case 'X':
            stat->nb_x += 1;
            break;
        case 'O':
            stat->nb_o += 1;
            break;
        case 'P':
            stat->nb_p += 1;
            break;
        case '\n':
            stat->nb_line += 1;
            break;
        case '#':
        case ' ':
            break;
        default:
            exit(84);
    }
}

void check_game(int fd, game_t *game_stat)
{
    if (game_stat->nb_o != game_stat->nb_x) {
        close(fd);
        exit(84);
    }
    if (game_stat->nb_p != 1) {
        close(fd);
        exit(84);
    }
}

static void is_ended(int *ended, char **map, game_t *stat)
{
    if (*ended != 0) {
        display_game(map, stat);
        refresh();
        usleep(500000);
    }
}

int game(char **map, game_t *stat)
{
    WINDOW *win;
    player_t *player = init_player();
    int key = 0;
    int ended = 0;

    search_player_and_slot(player, map, stat);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    display_game(map, stat);
    while (ended == 0) {
        check_key(player, &key, map, stat);
        loop_box(stat, map);
        display_game(map, stat);
        ended += check_end(stat, map);
    }
    is_ended(&ended, map, stat);
    free_all(map);
    endwin();
    return ended - 1;
}

int open_files(int fd, game_t *game_stat, struct stat *buff)
{
    char *char_map = malloc(sizeof(char) * (buff->st_size + 1));
    int nb_line;
    char **map;

    if (fd == -1)
        exit(84);
    for (int k = 0; k < buff->st_size; k++)
        char_map[k] = '\0';
    if (read(fd, char_map, buff->st_size) == 0)
        exit(84);
    char_map[buff->st_size] = '\0';
    for (int i = 0; char_map[i]; i++)
        check_char(char_map[i], game_stat);
    check_game(fd, game_stat);
    game_stat->slot_x = malloc(sizeof(int) * (game_stat->nb_x + 1));
    game_stat->slot_y = malloc(sizeof(int) * (game_stat->nb_x + 1));
    game_stat->box_x = malloc(sizeof(int) * (game_stat->nb_x + 1));
    game_stat->box_y = malloc(sizeof(int) * (game_stat->nb_x + 1));
    map = my_str_to_word_array(char_map);
    return game(map, game_stat);
}

int my_soko(char *map)
{
    game_t *game_stat = init_game();
    struct stat buff;
    int returned = 0;
    int fd;

    if (stat(map, &buff) != -1) {
        fd = open(map, O_RDONLY);
        returned = open_files(fd, game_stat, &buff);
        close(fd);
    } else
        return 84;
    return returned;
}
