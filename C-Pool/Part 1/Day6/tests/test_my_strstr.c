/*
** EPITECH PROJECT, 2023
** test_my_strstr.c
** File description:
** testing the function my_strstr.c
*/

#include <criterion/criterion.h>
#include <string.h>

Test(my_strstr, Basic_search_in_list)
{
    char *text = strdup("1234567890");
    char *text2 = strdup("1234567890");
    char *dest = strdup("12345");
    char *dest2 = strdup("12345");

    cr_assert_str_eq(my_strstr(text, dest), strstr(text2, dest2));
}

Test(my_strstr, Basic_search_at_the_end_of_the_list)
{
    char *text = strdup("1234567890");
    char *text2 = strdup("1234567890");
    char *dest = strdup("56");
    char *dest2 = strdup("56");

    cr_assert_str_eq(my_strstr(text, dest), strstr(text2, dest2));
}

Test(my_strstr, Pattern_not_available)
{
    char *text = strdup("1234567890");
    char *text2 = strdup("1234567890");
    char *dest = strdup("A");
    char *dest2 = strdup("A");

    cr_assert_eq(my_strstr(text, dest), strstr(text2, dest2));
}
