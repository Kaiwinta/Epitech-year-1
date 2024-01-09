/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** open_file.c
*/

#include "../include/my.h"

int good_extension(char *filename)
{
    int len = my_strlen(filename);
    char *extension = my_strdup(".radar");

    for (int i = 0; extension[i]; i++) {
        if (extension[i] != filename[len - my_strlen(extension) + i]) {
            my_putstr_err("The given file is not a '.radar'\n");
            free(extension);
            return -1;
        }
    }
    free(extension);
    return 0;
}

static int check_file_len(char *param)
{
    if (my_strlen(param) > 5) {
        parse_file(param);
        return 0;
    } else {
        my_putstr_err("The given file dont respect the format\n");
        return 84;
    }
}

int open_file(char *filename)
{
    struct stat file;
    char *param;
    int fd = open(filename, O_RDONLY);
    int returned = 0;

    if (stat(filename, &file) != 0 || fd == -1) {
        my_putstr_err("The given file dont exist\n");
        return 84;
    }
    if (good_extension(filename) == -1)
        return 84;
    param = malloc(sizeof(char) * file.st_size);
    read(fd, param, file.st_size);
    returned = check_file_len(param);
    close(fd);
    free(param);
    return returned;
}
