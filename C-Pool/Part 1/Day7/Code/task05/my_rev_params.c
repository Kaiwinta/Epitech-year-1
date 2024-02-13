/*
** EPITECH PROJECT, 2023
** my_print_param.c
** File description:
** Display all the parameters of a funciton
*/

void my_putchar5(char c)
{
    write(1, &c, 1);
}

void my_putstr5(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar5(str[i]);
        i++;
    }
}

void my_rev_params(int argc, char **argv)
{
    int i = 0;
    int len = 0;

    while (argv[i]) {
        i++;
        len++;
    }
    for (i = len - 1 ; i >= 0; i--) {
        my_putstr5(argv[i]);
        my_putchar5('\n');
    }
}

int main(int argc, char **argv)
{
    my_rev_params(argc, argv);
    return 0;
}
