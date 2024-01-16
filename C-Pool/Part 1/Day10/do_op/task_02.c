/*
** EPITECH PROJECT, 2023
** task02.c
** File description:
** compute a little operation
*/

static int add(v1, v2)
{
    my_put_nbr(v1 + v2);
    return 0;
}

static int sub(v1, v2)
{
    my_put_nbr(v1 - v2);
    return 0;
}

static int mul(v1, v2)
{
    my_put_nbr( v1 * v2);
    return 0;
}

static int mod(v1, v2)
{
    char *error = my_strdup("Stop: modulo by zero");

    if (v2 != 0) {
        my_put_nbr((v1 % v2));
        return 0;
    }
    my_putstr(error);
    return 84;
}

static int div(v1, v2)
{
    char *error = my_strdup("Stop: division by zero");

    if (v2 != 0) {
        my_put_nbr((v1 / v2));
        return 0;
    }
    my_putstr(error);
    return 84;
}

int  main(int ac, char **av)
{
    int value1;
    int value2;
    char *op[5] = {'+', '-', '/', '%', '*'};
    int (*funct[5])(int, int) = {&add, &sub, &div, &mod, &mul};

    if (ac < 4) {
        return 84;
    }
    value1 = my_getnbr(av[1]);
    value2 = my_getnbr(av[3]);
    for (int y = 0; y < 5; y++) {
        if (av[2][0] == op[y]) {
            return funct[y](value1, value2);
        }
    }
    my_putchar('0');
    return 84;
}
