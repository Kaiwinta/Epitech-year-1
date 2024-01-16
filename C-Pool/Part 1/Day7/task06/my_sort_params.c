/*
** EPITECH PROJECT, 2023
** my_print_param.c
** File description:
** Display all the parameters of a funciton
*/

int my_strcmp12(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] > s2[i] || s2[i] == '\0') {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    if (s2[i] == '\0') {
        return 0;
    }
    return -1;
}

static void my_putchar6(char c)
{
    write(1, &c, 1);
}

static void my_putstr6(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar6(str[i]);
        i++;
    }
}

void swap(char **str1, char **str2)
{
    char *temp;

    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void my_sort_params(int argc, char **argv)
{
    int j = 0;
    int i = 0;

    for (i = 1; i < argc; i++) {
        j = i;
        if (j > 0 && my_strcmp12(argv[i], argv[j - 1]) == -1 ) {
            swap(&argv[i], &argv[j - 1]);
            i = i - 2;
            j = i;
        }
    }
    for (int u = 0; u < argc; u++) {
        my_putstr6(argv[u]);
        my_putchar6('\n');
    }
}

int main(int argc, char **argv)
{
    my_sort_params(argc, argv);
    return 0;
}
