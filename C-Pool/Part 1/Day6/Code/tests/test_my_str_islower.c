/*
** EPITECH PROJECT, 2023
** test_my_str_islower.c
** File description:
** test the my_str_islower function
*/
#include <criterion/criterion.h>

Test(my_str_islower, is_lower)
{
    char dest [] = "atsyhqie";
    
    cr_assert_eq(my_str_islower(&dest), 1);
}

Test(my_str_islower, ending_with_numbers)
{
    char dest [] = "aioskaP819";
    
    cr_assert_eq(my_str_islower(&dest), 0);
}

Test(my_str_islower, empty_str)
{
    char dest [] = "";
    
    cr_assert_eq(my_str_islower(&dest), 1);
}

Test(my_str_isalpha, starting_wrong)
{
    char dest [] = "|ahus";
    
    cr_assert_eq(my_str_islower(&dest), 0);
}
