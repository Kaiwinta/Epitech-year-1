/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-titouan.pradoura
** File description:
** open_files.c
*/

#include "include/cpe.h"
#include "include/my.h"
#include "time.h"

static int get_line_len(int i, char *char_map)
{
    int count = 0;

    for (i; char_map[i] && char_map[i] != '\n' && char_map[i] != '\0'; i++) {
        count++;
    }
    return count;
}

static int choose_minimum(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b < a && b <= c)
        return b;
    if (c < a && c < b)
        return c;
}

static int getting_number(int *map, int x, int line_len)
{
    int value = 1;

    if (x % (line_len + 1) == 0 || x / (line_len + 1) == 0)
        value = 1;
    else {
        value = 1 + choose_minimum(map[x - 1], map[x - line_len - 1],
            map[x - (line_len + 2)]);
    }
    return value;
}

static int choose_number(char temp, int x, int *map, int line_len)
{
    if (temp == '\n')
        return -1;
    if (temp == '\0')
        return -2;
    if (temp == 'o')
        return 0;
    if (temp == '.')
        return getting_number(map, x, line_len);
    exit(84);
}

static max_t *init_max(void)
{
    max_t *maximum = malloc(sizeof(max_t));

    maximum->value = 0;
    maximum->x = -1;
    maximum->y = -1;
    return maximum;
}

void change_max(max_t *maximum, int nb, int x)
{
    if (maximum->value < nb) {
        maximum->value = nb;
        maximum->x = x;
    }
}

void change_char_max(max_t *maximum, char *map, int size_line, int nb_line)
{
    for (int i = maximum->x; i > maximum->x - maximum->value; i--)
        for (int y = 0; y < maximum->value; y++)
            map[i - (size_line + 1) * y] = 'x';
}

void loop_line(int *i, int nb_line, char *char_map)
{
    max_t *maximum = init_max();
    int icopy = *i;
    int count = 0;
    int x = 0;
    int size_line = get_line_len(*i, char_map);
    int *map = alloc_memory_int((nb_line * (size_line + 1) - 1));

    while (char_map[x]) {
        check_ended(map, x, maximum, char_map);
        map[x] = choose_number(char_map[icopy], x, map, size_line);
        icopy++;
        change_max(maximum, map[x], x);
        x = (icopy - *i);
    }
    if (char_map[x - 1] != '\n')
        char_map[x] = '\n';
    free(map);
    change_char_max(maximum, char_map, size_line, nb_line);
    show_result(char_map, nb_line, maximum, size_line);
}

static int get_number_from_first_line(int fd, int *i)
{
    char buff[1];
    int nb = 0;
    int result = read(fd, buff, 1);

    while (result > 0){
        if (buff[0] >= '0' && buff[0] <= '9') {
            nb = nb * 10;
            nb = nb + buff[0] - 48;
        }
        if (buff[0] == '\n')
            return nb;
        if (buff[0] < '0' || buff[0] > '9' && buff[0] != '\n')
            return -1;
        result = read(fd, buff, 1);
    }
    *i = *i + 1;
    return nb;
}

int open_files(struct stat *buff, int fd)
{
    char *char_map = malloc(sizeof(char) * (buff->st_size + 1));
    int i = 0;
    int nb_line;

    if (fd == -1)
        exit(84);
    nb_line = get_number_from_first_line(fd, &i);
    for (int k = 0; k < buff->st_size; k++)
        char_map[k] = '\0';
    if (read(fd, char_map, buff->st_size - i) == 0)
        return 84;
    char_map[buff->st_size] = '\0';
    if (nb_line <= 0)
        return 84;
    loop_line(&i, nb_line, char_map);
    return 0;
}
