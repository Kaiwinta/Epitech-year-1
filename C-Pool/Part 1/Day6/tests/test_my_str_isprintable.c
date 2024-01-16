/*
** EPITECH PROJECT, 2023
** test_my_str_isprintable.c
** File description:
** Test the printable function
*/

#include <criterion/criterion.h>

Test(my_str_isprintable, printable)
{
    char dest [] = "atsyhqie";
    
    cr_assert_eq(my_str_isprintable(&dest), 1);
}

Test(my_str_isprintable, not_before)
{
    char dest [] = "Æatsyhqie";
    
    cr_assert_eq(my_str_isprintable(&dest), 0);
}

Test(my_str_isprintable, printable2)
{
    char dest [] = " !atsyhqie";
    
    cr_assert_eq(my_str_isprintable(&dest), 1);
}

Test(my_str_isprintable, emptynull)
{
    char dest [2];
    
    dest[1] = '\n';
    cr_assert_eq(my_str_isprintable(&dest), 1);
}

Test(my_str_isprintable, empty)
{
    char dest [2] = "";

    cr_assert_eq(my_str_isprintable(&dest), 1);
}

