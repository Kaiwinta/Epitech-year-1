/*
** EPITECH PROJECT, 2023
** my_print_digits
** File description:
** Write all the digits on the same line
*/

int my_print_digits(void)
{
    int i;

    i = 48;
    while (i <= 57) {
        my_putchar(i);
        i ++;
    }
    my_putchar('\n');
    return 0;
}
