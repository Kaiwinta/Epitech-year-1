/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copy n char from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
            return dest;
        }
        i++;
    }
    if (src[i] == '\0')
        dest[i] = '\0';
    return dest;
}
