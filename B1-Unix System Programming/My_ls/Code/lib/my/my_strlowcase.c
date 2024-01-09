/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Put every letter in uppercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    char *temp = str;

    while (temp[i] != '\0') {
        if (temp[i] >= 65 && temp[i] <= 90) {
            temp[i] = temp[i] + 32;
        }
        i++;
    }
    return temp;
}
