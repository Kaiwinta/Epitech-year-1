/*
** EPITECH PROJECT, 2023
** my_print_comb
** File description:
** Display all the different number composed by Three differents digits
*/

#include <unistd.h>

void show_number(int a, int b, int c)
{
    my_putchar(48 + a);
    my_putchar(48 + b);
    my_putchar(48 + c);
    if (a != 7 || b != 8 || c != 9) {
        my_putchar(44);
        my_putchar(32);
    }
}

void loop_c(int a, int b, int c)
{
    c = b + 1;
    while (c <= 9) {
        show_number(a, b, c);
        c++;
    }
}

int my_print_comb(void)
{
    int a = 0;
    int b = 1;
    int c = 2;

    while (a <= 7) {
        while (b <= 9) {
            loop_c(a, b, c);
            b ++;
        }
        a ++;
        b = a + 1;
        c = a + 2;
    }
    return 0;
}
