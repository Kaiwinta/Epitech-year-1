/*
** EPITECH PROJECT, 2023
** catv1.c
** File description:
** trying to reproduce the cat command
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int print_files(int fptr, char *filename)
{
    char buff[32000];
    int nbr;

    nbr = read(fptr, buff, 32000);
    if (nbr < 0) {
        write(2, "cat: ", 5);
        write(2, filename, my_strlen(filename));
        write(2, ": Trying to open a dir\n", 23);
        return 84;
    }
    write(1, buff, nbr);
    while (nbr != 0) {
        nbr = read(fptr, buff, 32000);
        write(1, buff, nbr);
    }
    return 0;
}

int basic_cat(void)
{
    char buff[32000];
    int nbr = 1;

    while (nbr != 0 ) {
        nbr = read(0, buff, 32000);
        write(1, buff, nbr);
    }
    return 0;
}

int my_show_files(char *filename)
{
    int fptr;

    fptr = open(filename, O_RDONLY);
    if (fptr < 0) {
        write(2, "cat: ", 5);
        write(2, filename, my_strlen(filename));
        write(2, ": No files or folder found\n", 27);
        return 84;
    }
    return print_files(fptr, filename);
}

int main(int ac, char **av)
{
    int value = 0;

    if (ac == 1) {
        basic_cat();
    }
    for (int i = 1; i < ac; i++) {
        if (my_show_files(av[i]) == 84)
            value = 84;
    }
    return value;
}
