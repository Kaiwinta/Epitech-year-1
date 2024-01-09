/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Contain all the prototypes of all the function exposed by my libmy.a
*/

#ifndef MY_

    #define MY_

    #include <sys/stat.h>
    #include <stdlib.h>
    #include <sys/sysmacros.h>
    #include <dirent.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

typedef struct files {
    char *name;
    unsigned long time;
    struct files *next;
}files;

typedef struct flag {
    int case_l;
    int case_t;
    int case_r;
    int case_rmaj;
    int case_a;
    int case_d;
    int case_qmaj;
    int case_gmaj;
    int case_o;
}flag;

void show_quote(char *path, flag **flag_list);
void my_get_perm(struct stat *temp);
int loop_number(files *fichier, char *path);
void loop(char **av, flag **flag_list, int *nb_files, int ac);
int show_file(files **fichier, flag **flag_list);
int show_ld(files **fichier, flag **flag_list);
int case_ldir(files **fichier, struct flag **flag_list,
    char *path, int nb_files);
int choose_display(files **fichier, files **dossier, int nb_files,
    flag **flag_list);
void display_all(files **fichier, flag **flag_list, int nb_files, int);
int loop_dlr(char **av, flag **flag_list, int *nb_files, int ac);
int loop_dir(char **av, flag **flag_list, int *nb_files, int ac);
int case_l(files **fichier, struct flag **flag_list);
int flag_d(char **av, flag **flag_list, int *nb_files, int ac);
int my_put_in_list(files **list, char *data);
int rev_linked_list(files **begin, flag **flag_list, int forced);
struct files *one_dir(char *str, flag **flag_list, int *nb_files);
int ls_cmp(char *str, char *string);
int sort_linked_list(files **fichier, flag **flag_list);
int delete_point(files **fichier, flag **flag_list);
int loop_error(char **av, flag **flag_list, int *nb_files, int ac);
int flag_and_show(files **fichier, flag **flag_list, int nb_files, int);
char *found_name(char *av, int *nb_files);
int show_linked(files **fichier, int nb_files, flag **flag_list, files **chef);
int one_flag(char *av, flag **temp);
int loop_files(char **str, flag **, int *, int);
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
char *alloc_memory(int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
int my_isnum(char);
char *my_strdup(char const *);

#endif /* MY_ */
