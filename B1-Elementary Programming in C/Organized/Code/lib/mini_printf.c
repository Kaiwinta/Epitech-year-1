/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** A simplified version of the printf
*/

#include <stdarg.h>
#include "../include/shell.h"

static int case_d(va_list ap, char flag)
{
    return my_put_nbr(va_arg(ap, int));
}

static int case_s(va_list ap, char flag)
{
    return my_putstr(va_arg(ap, char *));
}

static int case_c(va_list ap, char flag)
{
    my_putchar(va_arg(ap, int));
    return 1;
}

static int case_pr(va_list ap, char flag)
{
    my_putchar('%');
    return 1;
}

static int case_default(char flag)
{
    my_putchar('%');
    my_putchar(flag);
    return 2;
}

int check_flag(char flag, va_list ap)
{
    char *flag_list = "idsc%";
    int (*function[5])(va_list, char) = {case_d,
        case_d, case_s, case_c, case_pr};

    for (int i = 0; i < 5; i++) {
        if (flag == flag_list[i]) {
            return ((function[i])(ap, flag));
        }
    }
    case_default(flag);
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, format);
    while (format[i]) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            count = count + check_flag(format[i + 1], ap);
            i++;
        } else {
            count ++;
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return count;
}
