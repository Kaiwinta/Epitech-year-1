/*
** EPITECH PROJECT, 2023
** test_my_revstr.c
** File description:
** test my_revstr.c
*/

#include <criterion/criterion.h>

Test(my_revstr, reverse_odds_number_of_characters)
{
    char dest [] = "12345";

    my_revstr(&dest);
    cr_assert_str_eq(dest, "54321");
}

Test(my_revstr, reverse_even_number_of_characters)
{
    char dest [] = "123456";

    my_revstr(&dest);
    cr_assert_str_eq(dest, "654321");
}

Test(my_revstr, reverse_0_char)
{
    char dest [] = "";

    my_revstr(&dest);
    cr_assert_str_eq(dest, "");
}
