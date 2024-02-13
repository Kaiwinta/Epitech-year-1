/*
** EPITECH PROJECT, 2023
** Test the strncmp function
** File description:
** test_my_strncmp.c
*/

#include <criterion/criterion.h>
#include <string.h>

Test(my_strncmp, Test_classic)
{
    char dest [] = "12345";
    char *s2 = strdup("1AVVAS");

    cr_assert_eq(my_strncmp(&dest, s2, 3), strncmp(&dest, s2, 3));
}

Test(my_strncmp, Test_negative)
{
    char dest [] = "ABC";
    char *s2 = strdup("abc");

    cr_assert_eq(my_strncmp (&dest, s2, 3), strncmp (&dest, s2, 3));
}

Test(my_strncmp, Test_out_range_both)
{
    char dest [] = "ABC";
    char *s2 = strdup("ABA");

    cr_assert_eq(my_strncmp (&dest, s2, 5), strncmp (&dest, s2, 5));
}

Test(my_strncmp, Test_range_1)
{
    char dest [] = "ABARRS";
    char *s2 = strdup("aBC");

    cr_assert_eq(my_strncmp (&dest, s2,14), strncmp (&dest, s2, 14));
}

Test(my_strncmp, Test_null_size)
{
    char dest [] = "12345";
    char *s2 = strdup("1AVVAS");

    cr_assert_eq(my_strncmp(&dest, s2, 0), strncmp(&dest, s2, 0));
}

Test(my_strncmp, Test_end1)
{
    char dest [] = "1";
    char *s2 = strdup("12");

    cr_assert_eq(my_strncmp(&dest, s2, 2), strncmp(&dest, s2, 2));
}

Test(my_strncmp, Test_end2)
{
    char dest [] = "12";
    char *s2 = strdup("1");

    cr_assert_eq(my_strncmp(&dest, s2, 2), strncmp(&dest, s2, 2));
}
