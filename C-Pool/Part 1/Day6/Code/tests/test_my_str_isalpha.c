/*
** EPITECH PROJECT, 2023
** test_my_str_isalpha.c
** File description:
** test my_str_is_alpha
*/

#include <criterion/criterion.h>

Test(my_str_isalpha, starting_with_numbers)
{
    char dest [] = "12345AEOP";
    
    cr_assert_eq(my_str_isalpha(&dest), 0);
}

Test(my_str_isalpha, ending_with_numbers)
{
    char dest [] = "AaspsEOP819";
    
    cr_assert_eq(my_str_isalpha(&dest), 0);
}

Test(my_str_isalpha, empty_strr)
{
    char dest [] = "";
    
    cr_assert_eq(my_str_isalpha(&dest), 1);
}

Test(my_str_isalpha, all_alpha)
{
    char dest [] = "azopskkqZAEOP";
    
    cr_assert_eq(my_str_isalpha(&dest), 1);
}

Test(my_str_isalpha, weird_one_1)
{
    char dest [] = ",aspsEOP819";
    
    cr_assert_eq(my_str_isalpha(&dest), 0);
}

Test(my_str_isalpha, weird_one_2)
{
    char dest [] = "|aspsEOP819";
    
    cr_assert_eq(my_str_isalpha(&dest), 0);
}

Test(my_str_isalpha, weird_one_3)
{
    char dest [] = "_aspsEOP819";
    
    cr_assert_eq(my_str_isalpha(&dest), 0);
}
