/*
** EPITECH PROJECT, 2023
** test_main.c
** File description:
** test the main function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void redirect_all_stdout(void)
{
    cr_redirectstdout();
    cr_redirectstderr();
}

int my_show_files(char *filename);

Test(my_show_files, no_such_files, .init=redirect_all_stdout)
{
    int result =my_show_files("catv1");
    cr_assert_eq(result, 84);
}
