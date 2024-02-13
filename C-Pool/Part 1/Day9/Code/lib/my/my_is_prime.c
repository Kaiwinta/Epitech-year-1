/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** Return the smallest prime number greater than or equal to the number given
*/

int my_is_prime(int nb)
{
    int i = nb / 2;

    if (nb <= 1) {
        return 0;
    }
    for (i ; i > 1; i--){
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
