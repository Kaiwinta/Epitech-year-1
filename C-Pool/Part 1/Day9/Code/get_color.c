/*
** EPITECH PROJECT, 2023
** get_color.c
** File description:
** return the color as an int
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = red;

    color = color << 8;
    color = color + green;
    color = color << 8;
    color = color + blue;
    return color;
}
