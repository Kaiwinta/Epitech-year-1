/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Contain all the prototypes of all the function exposed by my libmy.a
*/

#ifndef MY_

    #define MY_
int my_compute_power_rec(int, int);
int my_compute_power_it(int, int);
int my_compute_square_root(int);
int my_loop_number(long);
int isdown(char);
int isspace(char);
int isup(char);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char *, char const *);
char *my_strncpy(char *, char const *, int);
int my_find_prime_sup(int);
int my_getnbr(char *);
int my_is_prime(int);
int my_isneg(int);
int my_put_nbr(int);
void my_putchar(char);
void my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
int my_str_isalpha(char *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
int m_alnu(char);
char *my_strncpy2(char *, char const *, int);
int my_show_word_array(char *const *);
#endif /* MY_ */
