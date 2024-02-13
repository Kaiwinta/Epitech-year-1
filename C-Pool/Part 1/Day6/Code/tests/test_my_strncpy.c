/*
** EPITECH PROJECT, 2023
** test_my_strncpy.c
** File description:
** Test the file strncpy.c
*/

# include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_five_characters_in_full_array)
{
    char dest[6] = {1, 2, 3};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_all_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 20);
    cr_assert_str_eq(dest, "HelloWorld");
}

Test(my_strncpy, copy_0_char)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 0);
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_negative_char)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", -56);
    cr_assert_str_eq(dest, "");
}
