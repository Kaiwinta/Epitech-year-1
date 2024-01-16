/*
** EPITECH PROJECT, 2023
** my_print_comb2.c
** File description:
** Same but for 2 pairs of numbers
*/

void show_number2(v1, v2)
{
    my_putchar(v1 / 10 + 48);
    my_putchar(v1 % 10 + 48);
    my_putchar(32);
    my_putchar(v2 / 10 + 48);
    my_putchar(v2 % 10 + 48);
    if (v1 != 98) {
    my_putchar(44);
    my_putchar(32);
    }
}

int my_print_comb2(void)
{
    int v1 = 00;
    int v2 = 01;

    while (v1 != 100) {
        for (v2 = v1 +1; v2 < 100; v2++) {
            show_number2(v1, v2);
        }
        v1 ++;
    }
    return 0;
}
