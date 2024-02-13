/*
** EPITECH PROJECT, 2023
** test_my_strcapitalise.c
** File description:
** testing strcapitalize
*/

#include <criterion/criterion.h>
#include <unistd.h>

Test (my_strcapitalize, Classique_sentence)
{
    char *dest = strdup("124AHDeijahs ELlpsjag iaidha1");
    cr_assert_str_eq(my_strcapitalize(dest), "124ahdeijahs Ellpsjag Iaidha1" ) ;
}

Test (my_strcapitalize, Complexe_sentence)
{
    char *dest = strdup("134A+Edaa -ar -Tyua!?");
    
    cr_assert_str_eq(my_strcapitalize(dest), "134a+Edaa -Ar -Tyua!?" ) ;
}

Test (my_strcapitalize, empty_sentence)
{
    char *dest = strdup("");
    
    cr_assert_str_eq(my_strcapitalize(dest), "" ) ;
}
