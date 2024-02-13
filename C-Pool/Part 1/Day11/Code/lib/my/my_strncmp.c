/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Compare the first n ascci value of 2 strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int dif = 0;
    int i = 0;
    int ended1 = 1;
    int ended2 = 1;

    for (i; i < n; i++) {
        if (s1[i] == '\0')
            ended1 = 0;
        if (s2[i] == '\0')
            ended2 = 0;
        dif = dif + (s1[i] * ended1 - s2[i] * ended2 );
        if (dif != 0) {
            return dif;
        }
    }
    return dif;
}
