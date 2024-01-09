/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-titouan.pradoura
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
    return dest;
}
