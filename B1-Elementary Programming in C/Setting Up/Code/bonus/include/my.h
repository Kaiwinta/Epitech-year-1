/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Contain all the prototypes of all the function exposed by my libmy.a
*/

#ifndef MY_

    #define MY_

    #include <sys/stat.h>
    #include <stdio.h>
    #include <stdlib.h>

int *alloc_memory_int(int);
int my_compute_power_rec(int, int);
int mini_printf(const char *, ...);
int my_compute_power_it(int, int);
int my_compute_square_root(int);
int my_loop_number(long);
int my_isdown(char);
int my_isspace(char);
int my_isup(char);
int m_alnu(char);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strncpy2(char *, char const *, int);
int my_find_prime_sup(int);
int my_getnbr(char *);
int my_is_prime(int);
int my_isneg(int);
int my_put_nbr(int);
int my_putchar(char);
int my_putcharerr(char);
int my_putstr(char const *);
int my_puterror(char const *);
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
int my_isnum(char);
char *my_strdup(char const *);

#endif /* MY_ */
