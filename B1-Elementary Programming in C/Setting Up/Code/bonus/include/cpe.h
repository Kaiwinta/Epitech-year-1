/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-titouan.pradoura
** File description:
** cpe.h
*/

#ifndef CPE

    #define CPE

    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct max_t {
    int x;
    int y;
    int value;
} max_t;

int open_files(struct stat *buff, int fd);
int generating(char *, char *);
int generating_rect(char *pattern, char *nb_line, char *size_line);
void loop_line(int *i, int nb_line, char *char_map);
void show_result(char *map, int nb_line, max_t *maximum, int size_line);
void free_all(char *map, max_t *maximum);

#endif /* CPE */
