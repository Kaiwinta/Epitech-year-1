/*
** EPITECH PROJECT, 2023
** my_print_combn
** File description:
** same that the 6 but for n elements
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int  my_loop_number(long nb)
{
    if (nb == 0) {
        return 0;
    }
    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
    }
    if (my_loop_number(nb / 10) == 0) {
        my_putchar(48 + nb % 10);
        my_putchar(44);
        my_putchar(32);
    }
    return 0;
    }
}

int  my_put_nbr(int nb)
{
    long n = nb;

    if (n == 0) {
        my_putchar('0');
    } else {
        my_loop_number(n);
    }
}

int my_pow_10(int n)
{
    int pow_returned = 1;
    for (int i=0;  i< n; i++) {
        pow_returned = pow_returned * 10;
    }
    return pow_returned;
}


int min_number(int n)
{
    int i;
    int nb_actuel = 0;
    
    int  nb_min = 0;
    for (int i = 1; i < n; i++) {
        nb_min = nb_min + (i - 1 ) * my_pow_10(n-1 -i); 
    }
    printf("%d",nb_min);
}

int max_number(int n)
{
    int i = 0;
    int nb_actuel = 0;
    
    int  nb_max = 0;
    for (int i = 0; i < n; i++) {
        nb_max = nb_max + (10-n+i) * my_pow_10(n - i - 1); 
    }
    printf("%d",nb_max);
}

int loop(int nbr,int *max)
{
    if (nbr = 0){
        return 0;
    }
    while (nbr != *max) {
        while (nbr%10 <= 9) {
            my_put_nbr(nbr);
            nbr++;
        }
        nbr++;
        nbr = nbr + (nbr/10)%10;
    }
}

int my_print_combn(int n)
{
    int min = min_number(n);
    int max = max_number(n);

    loop(min,&max);
    return 0;
}

void main(void)
{
    my_print_combn(3);
}
