/*
** EPITECH PROJECT, 2023
** my_strcomp.c
** File description:
** Compare teh asccci value of 2 string
*/

int my_strcmp(char const *s1, char const *s2)
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
