/*
** EPITECH PROJECT, 2023
** my_print_revalpha.c
** File description:
** Write the alphabet in reverse order
*/

int my_print_revalpha(void)
{
    int i;

    i = 122;
    while (i >= 97) {
        my_putchar(i);
        i --;
    }
    my_putchar('\n');
    return 0;
}
