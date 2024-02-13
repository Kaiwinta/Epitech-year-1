/*
** EPITECH PROJECT, 2023
** test_my_revstr.c
** File description:
** test my_revstr.c
*/

#include <criterion/criterion.h>
#include <unistd.h>

Test(count_island, Simple_island_test)
{
    char **dest1 = malloc(6 * sizeof(char *));
    dest1[0]  = strdup("X....\0");
    dest1[1]  = strdup("..X..\0");
    dest1[2]  = strdup("....X\0");
    dest1[3]  = strdup("...XX\0");
    dest1[4]  = strdup(".....\0");

    char **result = malloc(6 * sizeof(char *));
    result[0]  = strdup("0....\0");
    result[1]  = strdup("..1..\0");
    result[2]  = strdup("....2\0");
    result[3]  = strdup("...22\0");
    result[4]  = strdup(".....\0");

    count_island(dest1);
    cr_assert_str_eq(dest1[0], result[0]);
}

Test(count_island, Simple_test_return)
{
    char **dest1 = malloc(6 * sizeof(char *));
    dest1[0]  = strdup("X....\0");
    dest1[1]  = strdup("..X..\0");
    dest1[2]  = strdup("....X\0");
    dest1[3]  = strdup("...XX\0");
    dest1[4]  = strdup(".....\0");

    int nb_island = count_island(dest1);
    cr_assert_eq(nb_island, 3);
}

Test(count_island, null_island)
{
    char **dest1 = malloc(6 * sizeof(char *));
    dest1[0]  = strdup("..X..\0");
    dest1[1]  = strdup("XXX..\0");
    dest1[2]  = strdup("....X\0");
    dest1[3]  = strdup("..XXX\0");
    dest1[4]  = strdup(".....\0");

    char **result = malloc(6 * sizeof(char *));
    result[0]  = strdup("..0..\0");
    result[1]  = strdup("000..\0");
    result[2]  = strdup("....1\0");
    result[3]  = strdup("..111\0");
    result[4]  = strdup(".....\0");

    count_island(dest1);
    cr_assert_str_eq(dest1[0], result[0]);
}
