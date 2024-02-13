/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** return the closest prime number
*/

int my_find_prime_sup(int nb)
{
    int i = nb / 2;

    if (nb <= 1) {
        return 2;
    }
    for (i ; i > 1; i--) {
        if (nb % i == 0) {
            return my_find_prime_sup(nb + 1);
        }
    }
    return nb;
}
