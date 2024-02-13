/*
** EPITECH PROJECT, 2023
** star.c
** File description:
** Print a star based on the number n
*/

static void case_one(void)
{
    char star_one[] = "   *\n*** ***\n *   *\n*** ***\n   *\n";
    int index = 0;

    while (star_one[index] != '\0') {
        my_putchar(star_one[index]);
        index ++;
    }
}

static void top_part(int size)
{
    int i = 0;

    for (int space = 1; space <= 3 * size - 1; space ++) {
        my_putchar(32);
    }
    my_putchar(42);
    my_putchar(10);
    for (i; i < size - 1; i++){
        for (int space = 0; space <= 3 * size - 3 -i; space ++) {
            my_putchar(32);
        }
        my_putchar(42);
        for (int mspace = 1; mspace <= 1 + i * 2; mspace ++) {
            my_putchar(32);
        }
        my_putchar(42);
        my_putchar(10);
    }
}

static void line(int size)
{
    for (int i = 1; i <= 2 * size + 1; i++) {
        my_putchar(42);
    }
    for (int y = 1; y <= 2 * size - 3; y++) {
        my_putchar(32);
    }
    for (int i = 1; i <= 2 * size +1; i++) {
        my_putchar(42);
    }
    my_putchar('\n');
}

static void mid(int size)
{
    for (int y = 0; y < size; y++){
        for (int i = y; i >= 0; i--) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int w = 1; w <= 5 * size - 2 * y - 1 + (size - 4); w++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    }
}

static void mid2(int size)
{
    for (int y = 0; y < size - 1; y++){
        for (int i = 0; i <= size - y - 2; i++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int w = 1; w <= 4 * size + 2 * y - 1; w++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    }
}

static void bot(int size)
{
    int i = 0;

    for (i; i < size - 1; i++){
        for (int space = 1; space <= 2 * size + i; space ++) {
            my_putchar(32);
        }
        my_putchar(42);
        for (int mspace = 1; mspace <= 2 * size - 3 - 2 * i; mspace ++) {
            my_putchar(32);
        }
        my_putchar(42);
        my_putchar(10);
    }
    for (int space = 0; space <= 3 * size - 2; space ++)
        my_putchar(32);
    my_putchar(42);
    my_putchar(10);
}

void star(unsigned int size)
{
    if (size != 0 && size != 1) {
        top_part(size);
        line(size);
        mid(size);
        mid2(size);
        line(size);
        bot(size);
    } else if (size == 1) {
        case_one();
    }
}
