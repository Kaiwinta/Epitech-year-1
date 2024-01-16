/*
** EPITECH PROJECT, 2023
** my_print_param.c
** File description:
** Display all the parameters of a funciton
*/

void my_putchar2(char c)
{
    write(1, &c, 1);
}

void my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar2(str[i]);
        i++;
    }
}

void my_print_params(int argc, char **argv)
{
    int i = 0;

    while (argv[i]) {
        my_putstr2(argv[i]);
        my_putchar2('\n');
        i++;
    }
}

void main(int argc, char **argv)
{
    my_print_params(argc, argv);
}
