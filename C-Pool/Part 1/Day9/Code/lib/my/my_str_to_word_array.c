/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Split a string into words
*/

#include <unistd.h>

int m_alnu(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) {
        return 1;
    } else if (c >= 97 && c <= 122) {
        return 1;
    } else {
        return 0;
    }
}

char *my_strncpy2(char *dest, char const *src, int n)
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

char **my_str_to_word_array(char const *str)
{
    int index_tab = 0;
    int len = 0;
    char **text;
    int last_i = 0;
    int index_temp = 0;

    for (len; str[len]; len++);
    text = malloc((len + 1) * (sizeof(char *)));
    for (int i = 0; i <= len; i++){
        if ((m_alnu(str[i]) && ! m_alnu(str[i + 1])) ||
        (m_alnu(str[i]) && str[i + 1] == '\0')) {
            text[index_tab] = malloc((i - last_i + 1) * sizeof(char));
            my_strncpy2(text[index_tab++], &str[last_i - 1], i + 1 - last_i++);
            last_i = i + 2;
        }
        if ((! m_alnu(str[i]) && ! m_alnu(str[i + 1])))
            last_i = i + 2;
    }
    text[index_tab] = NULL;
    return text;
}
