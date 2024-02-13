/*
** EPITECH PROJECT, 2023
** my_putnbr_base.c
** File description:
** Convert a base 10 number in another base
*/

int my_putnbr_base(int nbr, char const *base)
{
    int reste = nbr;
    
    while (reste >= 0) {
        reste = reste% *base;
        printf("%d",reste / *base);
    }       
}

void main(void)
{
    my_putnbr_base(37,&"8");
}
