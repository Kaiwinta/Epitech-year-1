/*
** EPITECH PROJECT, 2023
** count_island.c
** File description:
** count the number of differents island
*/

int change_island(char **world, int nb_island, int tempy, int tempx)
{
    world[tempy][tempx] = nb_island + 48;
    return 0;
}

void verif(char **world, int *nb_island, int tempy, int tempx)
{
    if (tempx >= 1)
        if (world[tempy][tempx - 1] == 'X'){
            change_island(world, nb_island, tempy, tempx - 1);
            verif(world, nb_island, tempy, tempx - 1);
        }
    if (world[tempy + 1])
        if (world[tempy + 1][tempx] == 'X'){
            change_island(world, nb_island, tempy + 1, tempx);
            verif(world, nb_island, tempy + 1, tempx);
        }
    if (world[tempy][tempx + 1] != '\0')
        if (world[tempy][tempx + 1] == 'X'){
            change_island(world, nb_island, tempy, tempx + 1);
            verif(world, nb_island, tempy, tempx + 1);
        }
    if (tempy >= 1)
        if (world[tempy - 1][tempx] == 'X'){
            change_island(world, nb_island, tempy - 1, tempx);
            verif(world, nb_island, tempy - 1, tempx);
        }
}

int loop_line(char **world, int nb_island, int *y, int *x)
{
    int returned = 0;
    int tempx;
    int tempy;

    while (world[*y][*x] != '\0') {
        tempy = *y;
        tempx = *x;
        if (world[*y][*x] == 'X') {
            change_island(world, nb_island, tempy, tempx);
            verif(world, nb_island, tempy, tempx);
            nb_island++;
            returned ++;
        }
        *x = *x + 1;
    }
    return returned;
}

int count_island(char **world)
{
    int nb_island = 0;
    int x = 0;
    int y = 0;

    while (world[y]) {
        nb_island = nb_island + loop_line(world, nb_island, &y, &x);
        y++;
        x = 0;
    }
    return nb_island;
}
