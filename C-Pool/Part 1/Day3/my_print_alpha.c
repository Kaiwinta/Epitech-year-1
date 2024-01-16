/*
** EPITECH PROJECT, 2023
** my_print_alpha.c
** File description:
** DAy 03 task01
*/

int my_print_alpha(void)
{
    int i;

    i = 97;
    while (i <= 122) {
        my_putchar(i);
        i ++;
    }
    my_putchar('\n');
    return 0;
}
